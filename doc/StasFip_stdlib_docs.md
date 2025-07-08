# StaFip library functions

StaFip also implements a set of predefined functions often encapsulating some
sideeffect like for example printing to standart output. These functions are then in
the implementation of algoritms used for debugging and monitoring the runtime
of the StaFip using scripts.

## Object type

The StaFip standard library includes a deffinition of an Object type with a
child type Tagged. This type is provided for porposes of polymorphism. Every
other defined enum type is implicitelly substitutable into a parameter of type
object (or type Tagged). There is an implicite cast from any type to type object
and from it to any type. The implicite definition of this enum type is visualized here:

```ffip
type object {
    Tagged;
}
```

## Pair, Tuple3 and Tuple4 types

```
Pair ( type object first, type object second ) ;
Tuple3 ( type object first, type object second, type object third ) ;
Tuple4 ( type object first, type object second, type object third, type object forth ) ;
```

These types are only meant for returning multiple instances from a function to
a caller without a need for reuse tokens in case of the FIP functions. Regarding
the implementation, at the start of a StaFip script, a field in memory is allocated
for each of these types. When constructing these types later in a script, they
simply reuse their corresponding field. This can, in general, result in overwriting
of still-used data. But since these types are in the testing scripts, only used in
cases of returning from a function (and unboxing of the returned instance by the
caller), and since each script is only single-threaded, these fields are overwritten
only when no other function is using them. An example of Tupple4 type is shown
in Figure bellow.

This implementation is not ideal for the production-ready implementation of
StaFip, since in a multi-threaded environment, this implementation might create
race conditions. A better implementation would entail storing instances of these
types on the stack and copying them to the caller.

```
fip type Tuple3 buncons [ type bseq bs ]
    = match ! bs -> type Tuple3 {
        | BSeq (s , b ) ->
            match uncons (s , b ) -> type Tuple3 {
                | Tuple4 (x , u3 , s_ , b_ ) -> Tuple3 (x , u3 , BSeq (s_ , b_ ) )
            }
    }
```

This is an example use of Tuple4 library type. Notes that although the buncons
function is FIP and there is only one reuse token of size 2 (from bs parameter), the
Tuple4 type is constructed and returned since it does not need any reuse tokens.

## Boolean ( int value ) ;

The Boolean type is an implicitly defined enum type used for returning a
Boolean type instance from a function to the caller. As the Tuple type, it uses a
statically allocated heap field which is reused at each construction of type Boolean
type. This type is defined because the match expression must return an enum type
instance, and in some instances, we want a function to return a _Bool. For this
purpose, we make the function return through a match expression an instance of
type Boolean.

## int printf [char * format, ...]

This function is implemented basically the same way as in the C language. It
is a variadic function that takes a string with a number (or none) of substrings
in format ’\%c’ where c is some char or sequence of chars identifying type, and a
number of arguments. The string representations of the arguments are in order
attempted to be substituted by the pattern where the ’\%c’ type must match the
type of the argument. Also the number of argumets must match number of the
’\%c’ patters in the string. More detailed explanation can be found in the C++
reference documentation [6].

## T log [T e, char *msg = ""]

This function as another function for printing runtime values to standart
output. Hoever unlike the printf which returns the object, object e it was given
to it as an argument.

The T type can either match to type Object or any other primitive type like an
int or a string. If the given type is a string, it also prints its address in memory.
After that, a the \lstinline|msg| string argument is printed.
In code bellow is an example of list printing implementation using the \lstinline|log| method.

```ffip
type list {
    Nil;
    Cons(int val, type list next);
}

type list second [int x, type list xx] = xx

int travers_list [type list xs] = match xs -> int {
    | Nil               -> printf("Nil\n")
    | Cons(x, xx)       -> travers_list( second( log(x, "-> "), xx ))
}

type list log_list [type list xs] = second( travers_list(xs), xs)
```

After that, a the msg string argument is printed. In Fugure 2.10 is an example of
list printing implementation using the log method.

## T time [T e]

This function is used for benchmarking and measuring the CPU time of a
given part of code. The parameter here is irrelevant, it is simply forwarded to the
caller. The resulting printed text contains the measured time in seconds and the
ammount of memory bytes allocated so far in the programs runtime. On its first
callstarts a clock and on its second call prints the clock value to the stdout and
resets the clock so that this can be repeated again. The object ’e’ given to it is
simplyforwarded to the caller. This clock function is implemented using C code
bellow.

```cpp
static clock_t clock_start = 0;

void ckrt_measure_cpu_time(void)
{
    if (clock_start == 0)
    {
        clock_start = clock();
    }
    else
    {
        clock_t end = clock();
        double elapsed_sec = (double)(end - clock_start)
            / CLOCKS_PER_SEC;
        printf("Now already malloced in total %uB\n",
            (unsigned int)already_allocated);
        printf("Elapsed CPU time: %.6f\n", elapsed_sec);
        clock_start = 0;
    }
}
```

The function can be used to measure the time a function ’int A [int a]’ takes
to finish like this: ’time(A(time(5)))’. The first call to of time on the last parameter
5 of A starts the clock and right after that the fucntion ’A’ is entered. Then when
fucntion A finishes, and its result is given to the second time call, the clock is
stopped by the time function and the measured time is printed to standard output.
