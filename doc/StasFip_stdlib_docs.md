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
