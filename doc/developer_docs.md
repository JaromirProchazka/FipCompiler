The StaFip compiler is implemented using Flex for lexical analysis and Bison for semantic analysis. It is a single traversal, meaning that it is implemented in such a way that the input source code text is traversed only once before generating the final assembly code. The final code is generated using the LLVM library and C++ in the form of LLVM Intermediate Representation (IR), which is then compiled using \textit{Clang} compiler to a final executable file.

The project does not use the LLVM library directly, but a framework by Bednárek, D., Yaghob, Cecko Skeleton \cite{CeckoFramework24}. This framework abstracts the LLVM library and provides other useful features like handling contexts and lookup tables for functions and variables.

# Declarations

## Enum types

Enum types declaration in StaFip can be simply represented and is similar to
C structs. When using the type as an argument, for instance in ’type list xs’,
this type actually translates to ’struct list \*xs’. The first field of any non-null
type is implicitly an int tag with a unique type identifier number. On each new
instantiable type declaration, a tag is chosen for it as the least not yet taken
positive integer. Also for this type, a constructor ’_const_<type*name>’ and a reuser
’\_reuse*<type_name>’ are defined. One of these implicitly defined function is called in case of instantiation like this:
Cons(1, Nil).

Both of these functions take the explicitly declared field values of the type and
use a pointer to the heap block of the enum type size to set the tag value and fields.
Finally, they both return this pointer. The difference between these functions is
how they obtain the heap pointer. While the constructor simply memory allocates
for the required type-sized block, the reuser takes as an additional first argument
a pointer to already allocated memory and initializes the type instance there.
This is different for child types that with no explicit fields like the ’Nil’ enum
type in the example. These types are represented as a NULL pointer. For this
reason, there can be only one child of such a type. Since in our implementation,
multiple empty enum child types would be indistinguishable at runtime.
An interesting problem while making this testing compiler was in the empty
enum type representation. At first, these types were represented simply as memory
allocated blocks with only the tag field. However, this later in FIP algorithms
testing posed a problem since at least the algorithms shown in the [1] paper didn’t
account for reusing these empty types. There simply were not enough reuse tokens
for them. And so to make our implementation truly fully in place, these types
could not be implemented as memory allocated blocks. This shows how FIP
can be implementation sensitive, and it might not be easy to migrate algorithm
implementations from one FIP language to another. This functionality is implemented
in the [casem::TaggedTypeDecl](@ref casem::TaggedTypeDecl). The child types can be
initialized using the [casem::declare_child_ttype()](@ref casem::declare_child_ttype())
method. A vector of the resulting cecko::CKStructTypeSafeObs is than passed to the
[TaggedTypeDecl::finish_parent_ttype()](@ref casem::TaggedTypeDecl::finish_parent_ttype())
method creating the parrent type with the child types being under it.

Another interesting consequence of FIP is the uniform field size. Since each
field is one element in a reuse token. Therefore, we must for some types that they
actually need. Let’s illustrate that these two types: ’Nums(int x, int y);’, and
’Ptrs(type Nums n1, type Nums n2);’. Since int has a size of 4 bytes and type Nums
has two of them, it takes up 8 bytes. The Ptrs type holds two 8-byte pointers
and thus takes up 16 bytes. But the Nums type should actually be reusable for
the Ptrs type. But, implemented naively, Nums does not hold enough space for it.
For this reason, we need to pad the Nums type so that any type with 2 fields can
reuse it. In the StaFip implementation, for any type allocation, we allocate the
number_of_field \* ptr_size bytes since in the StaFip implementation, no field can
take up more space than pointer size.

# Expressions

## Literals, Data types and Arithmetics

For literals, variables, and other data type instances, StaFip compiler uses
the [InstructionWrapper](@ref casem::InstructionWrapper) class. The whole API that this
class provides is constant. Most operations simply create a new instance of
InstructionWrapper without changing the old one. Writing a compiler with a
language without garbage collection is quite cumbersome, and in our context,
the better performance possible with C++ does not matter since the speed of
the generated code is the important requirement, not the compilation speed. For
these reasons, StaFip implementation mainly stores instances of these structures
on the stack and uses copy constructors when necessary. If needed, C++ smart
pointers are used to handle memory management.

The instruction wrapper can be initialized dirrectaly using its constructor or
more conviniently one of the builder functions:

- [init_instruction_from_name()](@ref casem::init_instruction_from_name()) for making variables wrappers
- [init_instruction_function_call()](@ref casem::init_instruction_function_call()) for wrapping the results of a funcion call
- [init_instruction_const()](@ref casem::init_instruction_const()) for creating literals
- [init_instruction_malloca()](@ref casem::init_instruction_malloca()) for heap allocations, the wrapper than referes to the adress to the heap

It provides the arithmetical operators that may generate load instructions of
the values of the data based on their type and generates the arithmetical operation
instruction using the LLVM library. These functions, in general, also implicitly try
to cast given values to their expected types for that operation. If this cast fails, a
proper error message is generated and logged, and an invalid InstructionWrapper
is past instead.

This class also implements operations for enum types, like field parsing, gener-
ating an operation for checking if a given enum type has a certain field, and also
loads, stores, and debugging prints instructions generation.

## Match Expressions

Match expressions create branching in the code. Of course,
the StaFip compiler does not generate C but the LLVM IR code. However, the
LLVM IR is a bit hard to understand even for such a small example, and so we
provide a C equivalent code. The actual IR representation can be found in the
StaFip project repository. The state of the match expression compilation is
stored in the [casem::MatchWrapper](@ref casem::MatchWrapper) class. This class
also wrapp more specific classes for keeping the match compilation state like
[MatchBinderChackerData](@ref casem::MatchBinderChackerData) class for the
pattern variables and the [MatchBinderListHeadData](@ref casem::MatchBinderListHeadData)
for wrapping the pattern list.

First, the result variable is declared, which will at the end of the evaluation
hold the value of the match expression. In the StaFip compiler, it is represented
with the mentioned [InstructionWrapper](@ref casem::InstructionWrapper) class and is sent up the syntax tree as a
result of the match_expression non-terminal in the grammar.
As mentioned in the language section, any pattern matching an empty type
without any explicit fields (like the Nil type) must be the first pattern of the match
patterns. This is because before dereferencing the
matched expression and checking its tag, it must be determined that the matched
expression is not NULL. So for a match with an empty type in the first pattern,
we generate a branch with the condition that the matched expression is NULL.
The positive outcome will jump to the block handling the empty-type pattern
expression. The evaluated expression here is stored in the result location.

In the negative outcome of the branch, the program jumps to a block where
the tag checks start. There a chain of branchings for each Enum type with a
pattern is generated. If the tag of the matched expression matches the Enum
type tag, the corresponding evaluated expression is stored in the result value, and
the checks continue. This chain is equivalent to a sequence of if-statements, each
checking the tag and, on success, storing its corresponding evaluated expression
to the result location.
Finally, the result location is interpreted as the evaluated match expression
and used further in the code.
If the match is destructive, as in the example, the FIP mode is started in the
compiler, and the match provides its matched expression as a reuse token. The
subsequent expressions in patterns are evaluated with reusers, which may use the
matched expression instead of constructors that allocate to the heap. This FIP mechanism is described in detail later.
In case of nested match expressions (or even if-else expressions), a new context
block is entered so that multiple result locations can coexist and be referenced
separately.

While developing the StaFip compiler match expression, the match had to
be modified to accommodate the types represented with NULL pointers problem
mentioned in the Enum types subchapter.
Another interesting problem that arose with the match expression implemen-
tation was the unintended entering of multiple patterns. In a non-FIP context,
any matched expression will result in entering only one of the patterns, given that
each pattern matches a unique type. And so, although a bit less performant, the
tag checks can be implemented with a sequence of if blocks instead of a sequence
of if/else if blocks. This is because the matched expression must have some
concrete tag that will not change, and given that each pattern checks for a different
type, at most one will check for the tag present in the matched expression.
But when introducing FIP to a functional language, this assumption fails
because the matched expression can be reused for instance of a different type. If
any subsequent pattern then checks for this new type, it will be unexpectedly
entered, and the result location will be overwritten. This is a problem, and it was
actually encountered in some benchmarked algorithms. The good news is that
this problem can be easily solved in the benchmarked algorithms by rearranging
the patterns to a different order, such that the subsequent patterns do not check
for type the matched expression could have been reused for. Although this is
unpleasant for writing in StaFip, it is enough for our testing purposes.

## If-Else expressions

The if-else expression is implemented in a similar way to the match expression.
At the start of its evaluation, a result variable is declared and then passed forward
as the value of the if-else expression. Unlike in a match expression, however, the
result type isn’t known at the start of the expression, and so we declare the result
location with the object type. This is the reason why the result type of these
expressions must be an enum type, since other data types can not be cast to it.
After the result type declaration, a conditional jump is made based on the value
of the boolean convertible condition expression. Both the if.then and if.else blocks generated store to the result location and then jump to if.end block where
the code continues.

The If-Else expressions compilation state is kept in the [IfExpressionData](@ref casem::IfExpressionData).

## FIP mechanism implementation

The FIP context is handled through a global state of type [casem::FipState](@ref casem::FipState).
Functions ’[casem::FipState::enter_fip_mode()](@ref casem::FipState::enter_fip_mode())’ and
’[casem::FipState::exit_fip_mode()](@ref casem::FipState::exit_fip_mode())’ handle statically at compilation time if the program is in the
FIP mode or not. They are implemented with a counter, which is incremented
on entry and decremented on exit function. If it is zero, we are not in the FIP
mode; otherwise, we are. This information can be retrieved using ’[casem::FipState::is_in_fip_mode()](@ref casem::FipState::is_in_fip_mode())’
function. The enter function is called at the start of any
expression that uses FIP, like a destructive match expression or a body entry of
an FIP function, and the exit function is called when its evaluation is done. The [casem::FipState](@ref casem::FipState) statically keeps track of the reuse expressions in the
program at compile time. Inside this class is a context stack of type ’std::vector<
std::set<[ReuseInstruction](@ref casem::ReuseInstruction), [ReuseInstructionComparator](@ref casem::ReuseInstructionComparator)>>’.
The std::vector<> implements the stacks of contexts. The context is represented as a set std::set<
ReuseInstruction, ReuseInstructionComparator> with wrapped InstructionWrappers
representing the reusable heap blocks ordered by the number of their reuse tokens.
As mentioned, a new context block is entered, for example, on a match or
an if-else expression. When a new context block is entered, if the program is in
FIP mode, a new std::set<[ReuseInstruction](@ref casem::ReuseInstruction),
[ReuseInstructionComparator](@ref casem::ReuseInstructionComparator)> context
instance is appended to the stack. This new context is a copy of the one before it
because the new context has access to all reuse tokens from the context above it.
When leaving the context block, this instance is again popped from the stack.
Functions ’[casem::FipState::emplace_reusable(Args &...args)](@ref casem::FipState::emplace_reusable())’ and ’[casem::FipState
::insert_reusable(ReuseInstruction &inst)](@ref casem::FipState
::insert_reusable())’ are used for adding new reusable to-
kens to the current context at the top of the stack.

Using this mechanism, we statically collect and keep track of reuse tokens
throughout the program. when evaluating an expression with type initializations
in FIP mode, the StaFip compiler uses the ’[casem::FipState::reuse(std::size_t
required_size)](@ref casem::FipState::reuse())’ to retrieve the reuse token (reusable expression) of a certain size
from the current context stored at the top of the FipState stack. If there is a
token of given size available, the function removes it from the context and instead
of the constructor generates a reuser function with this expression in the first
argument. Notice that runtime does in no way decide the reusing, everything is decided at
compile time.

If a reusable token of suitable size is not available, two things can happen.
The StaFip compiler provides a static variable ’ENFORCE_FIP’ which is by default
true. If it is true, then the lack of available tokens results in a compilation error.
If it is false, then a constructor with allocation is generated instead without an
error. This is a weaker implementation of the FIP, but it can be more practical.
The Koka implementation also allows this construction on no-reuse tokens of the
required size.
