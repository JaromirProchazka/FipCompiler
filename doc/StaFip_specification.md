# Code example

```ffip
// List definition
type list {
    Nil;
    Cons(int val, type list next);
}

// List reversal functions
type list freverse [type list xs];

fip type list freverse_acc [type list xs, type list acc]
    = match! xs -> type list {
        | Nil           -> acc
        | Cons(x, xx)   -> freverse_acc(xx, Cons(x, acc))
}

type list freverse [type list xs] = freverse_acc(xs, Nil)


// Util functions
type list make_list [] = Cons(1, Cons(2, Cons(3, Nil )))

int finish [type Tagged x] = 0


// Main function
int main [int argc, char** argv] =
    finish( freverse( make_list() ))
```

This code uses FIP to sort a simple list in place.

# Declarations

## Functions

As in most functional languages, a program is a set of functions. A function
here is an object that takes a number of arguments and contains a single expression
to which the arguments are substituted. Because of that, a function definition
is structured in this way: ’return_type IDF [ argument_list ] = expression’ where
an argument_list is ’argument_type IDF’ separated by commas.

If a function must be declared without a body for example in case, when
two functions call each other, a C style notation is used: ’return_type IDF [
argument_list ];’. The body can be declared later in code using this notation:
’return_type IDF [ argument_list ] = expression’.

In the definition of the function, it can also be declared with a fip keyword
in its list of specifiers. This is similar to the Koka notation and it denotes the
function as fully in place.

When starting a StaFip program, the compiler looks for a main function in this
format: ’int main [int argc, char** argv] = expression’. The evaluated value of
the expression of type int is the exit code of the program.

## Enum types

Custom type declarations are also supported. The StaFip types work like,
for example, Rust’s enums. A parent type is defined, and under it a number of
child types with a data field. In StaFip, the types are declared with a parent
’type parent_type_idf { child_type_declaration_list }’ with a list of child-type
declarations below it in curly brackets. A child type is declared as ’child_type_idf
( data_fields_list );’. If the child type has no field, the parentheses are not
included, and it is declared as such ’child_type_idf;’. For reasons described in the
implementation section, a parent type can have only one child type under it, with
no data fields. An example of an enum-type declaration and instantiation can be
seen here:

```ffip
type list {
    Nil ;
    Cons ( int val , type list next ) ;
}
// Instantiation : Cons ( 1 , Cons (2 , Nil ) )
// results in list : '1 -> 2 -> Nil '
```

The parent type can be understood as an abstract type with the child types
inheriting from it. The parent type itself can not be instantiated. Only the child
types can be constructed if they are given all their data field values. However, the
child types can be easily cast to their parent type and the other way around. As
seen in the list type example, the second field of the Cons child type is the parent
type and can thus be either another Cons or a Nil. A parent type must have at least one child type. This way, it is ensured that the field of parent type always
holds an instance of some instantiated child type.

There is also an implicitly declared object type like this: ’type object { Tagged
; }’. This type is special in the sense that any other type can be cast to it and
it can be cast to any other type. Note that these casts are implicit, and there
is no way to explicitly cast. This is especially useful in cases when we need to
implement a generic type, a type that can take as a field in different cases a
differently typed value. This is arguably less safe, but for our testing purposes, it
is enough. However, this works only with other declared enum types. Data types
like int can not be cast to the object type.

# Expressions

## Literals and Data types

StaFip supports int, string, \_Bool, and char literals. The int is a 32-bit long
signed int value, char is an 8-bit long value, and string literals are pointers to an
array of chars. \_Bool is a 1-bit long value where the literal of 1 represents true
value, and a value of 0 represents a false value. C-style pointers are also present
and any object can be referenced to using ’&’ sign and dereferenced using ’\*’ sign.

## Arithmetics

Arithmetics are a similar to C arithmetics. For numerical type, StaFip sup-
ports addition(+), subtraction(-), multiplication(\*), division(/) and modulo(%).
Boolean algebra is also supported with the greater(>), lesser(<), greater or
equil(>=), lesser or equil(<=), equil(==), not equil(!=) and negation(!).

## Match expressions

Match expression is a syntactic structure that, given an expression, creates
branching in the program based on the expression’s actual (child) type. In
the FIP context, it is also used to provide reuse tokens to the context, since
once the type is matched, its size in memory is known. The syntax of match
expresion is ’match matched_expression ->expressions_return_type { paterns_list
}’ with either non-destructive BMATCH (match) or destructive match! version. A
pattern has this form ’| child_type_idf( new_variables_list )->result_expression
’. The new_variables_list is a list of identifiers separated by commas. If a
new variable has the same name as some other argument above it, the name is
overloaded and covered in this context. Each pattern has its context, so variable
names can be shared between patterns without overloading. The field values of
the matched expression are copied to the new variables. The result_expression
can use the new variables from new_variables_list, and given that the pattern
matches the type of the given matched expression, this expression is the result of
the match expression. The code bellow shows an example of match expression use.
The matched expression can be any expression. However, if no pattern fits the
resulting type of matched expression, the behavior is undefined.

```ffip
match! x1 -> type T1 {                // reusables: x1[3]
    | Ta(a, b, c) -> match! x2 -> T1 {// reusables: x1[3], x2[2]
        | Tb(d, e)  -> Taa( Tbb(a, b), c, d ) // reusables: emty
        // ...                        // reusables: x1[3], x2[2]
    }                                 // reusables: x1[3]
    // ...
}
```

Match expressions are also present in Koka and other languages. The limitation
of the StaFip’s match is that the matched expression must be of an Enum type.

So numbers, strings, and so on can not be pattern-matched. And also that the
pattern must have as variables only identifiers, not other patterns. So pattern
like ’| Sublist(a, Sublist(b, xs1))->...’ is not possible, and what must be done is
nesting the match expressions like this ’| Sublist(a, ss)-> match ->type list { |
Sublist(b, xs1)->... }’ which can lead to duplications in code. But for our testing
purposes, this is fine because for non-enum types, we use the if-else expressions.

## If-Else expressions

Another option for branching in the program is the if-else expression with
this syntax ’if (cond_expression)then_expression ; else else_expression ; ’. The
expression in the cond_expression must be convertible to a boolean.
Enum types are also Boolean convertible. If-expression given an expression
of the enum type as condition enters the then_expression if the expression is an
instance of the child type with some data inside it, like for example Cons(5, Nil),
the result of the if-else expression is the then_expression. Else if the expression is
an instance of a type with no data inside it, like Nil, the else_expression is the
result.

```ffip
// part of the quick sort algorithm implementation
if (_elem(p) <= _elem(x))
    if (_elem(p) <= _elem(y))
        Pair(Nil_elem, Cons_elem(x, Cons_elem(y, Nil_elem)));
    else
        Pair(Cons_elem(y, Nil_elem), Cons_elem(x, Nil_elem));
else
    if (_elem(p) <= _elem(y))
        Pair(Cons_elem(x, Nil_elem), Cons_elem(y, Nil_elem));
    else
        Pair(Cons_elem(x, Cons_elem(y, Nil_elem)), Nil_elem);
```

The if-else expressions can also be nested. This nesting is interpreted similarly
to that in the C language. When evaluating the nested if-else expressions, the
StaFip compiler traverses the structure until it reaches the deepest if expression
that itself has no other nested if/if-else expressions. The next closest else expression
is interpreted as belonging to this if expression. This if-else expression is interpreted
as the inner expression of the if-else expression above it in the nesting, and this
process is repeated.
The limitation of the If-else expression in StaFip is that its result type must be
an Enum type. So, for example, this code is invalid in StaFip ’if (cond)1; else 2;’
since 1 and 2 are of data type, not enum type.
