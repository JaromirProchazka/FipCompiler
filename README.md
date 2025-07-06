# StaFip Compiler

A small testing compiler of a functional language StaFip. It
implement the Fully In Place calculus (FIP) and is meant to test
this calculus in space with no garbage collection.

## Example

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

## Requirements

This project is meant for linux ubuntu environment and the CMake building this project needs to be instructed where to find the LLVM (15.0.0) directory. Use command `cmake -DLLVM_DIR=<llvm-install-folder>/lib/cmake/llvm <...other-arguments...>` to do so.

- CMake
- BISON 3.4
- FLEX 2.6.4
- LLVM 15.0.0
- Doxygen 1.10.0
- bash
- clang 15.0.0
  - llc 15.0.0
  - clang 15.0.0
  - clang++ 15.0.0
  - (installation command: `sudo apt install -y llvm-15 clang-15 clang-tools-15`)

## Build and Run

For the build and testing alown, use this command:

```sh
cmake . && cmake --build .
```

You can then run any script with `.ffip` file extension with this command:

```sh
# runs script and print its compiled IR and run result on the stdout
./stud-main/cecko5 <script>

# also runs the script but puts the IR to ./DebugLog.txt
./stud-main/cecko5 -a ./DebugLog.txt <script>
```

## Tests

The StaFip compiler is tested throw a set of testing StaFip scripts. These scripts
also include the benchmarked algorithms, both the FIP and non-FIP versions on some
none-trivial data.

These testing scritps are present in the `test` folder. For each there is also a
corresponding `.gold` file with the expected results.

Use this command to build and run tests:

```sh
verify_stafip.sh
```

## Run Benchmarks

To build and run benchmarks, use this default command:

```sh
./generate_fip_tests_data.sh --replace
```

For generating Benchmarks, we have generate_fip_tests_data.sh script.
It takes all files from the `./bench/` folder and generates result in the
`./compiled_programs_data/` folder.

In the `./bench/` folder, files which names strart with "basic\_" substring
are meant as benchmark files and are not included in the benchmarks results. For
other files, it is expeceted that they have a fip and non-fip version. The
Fip version should should fit patern "<name>\_fip.ffip" and the non-fip
version fits pattern "<name>\_normal.ffip".

After Benchmarks are generated, for each script there is folder of its name
with compiled executable and the generated IR instructions. Than
`./compiled_programs_data/benchmark_results.csv` with benchmark results in
CSV file. This data is then visualized in the
`./compiled_programs_data/benchmark_results_comparison.png` file. The FIP
and non-FIP versions of the scripts are compared in the generated graphs and
a speedup ratio is calculated.

The script `generate_fip_tests_data.sh` can be configured with these flags:

- `--replace`: first cleans up the `./compiled_programs_data/` folder
- `--basics`: only compiles the test files with fiting pattern "basic\_\*" and doesn't run benchmarks
- `--no-test`: doesn't generate benchmark results
- `--benchmarks`: only compiles the benchmarked test files with fiting pattern "./bench/!(basic**)**@(fip|normal).ffip" and runs benchmarks

## Documentation

Documentation can be found in the `doc` folder. There the documentaiton is split
to:

- `developer_docs.md` documenting from the high level the `casem` library which abstracts the LLVM interface and provides specific data types for the StaFip language.
- `StaFip_stdlib_docs` documents the implicitely defined function and types of the StaFip language
- The `StaFip_specification.md` which describe the language its self, its semantics and syntax
- and finaly the doxygen documentation of the `casem` library to which the `developer_docs.md` often links

the doxymentation can be generated using the command bellow (from project root) and than accessed by opening the index.html file in the resulting `doc/html/` folder.

```sh
cd ./doc/
doxygen ./doxyfile
# than open the doc/html/index.html
```

## Thesis

### reference

This compiler builds on ideas presented in:

- _Anton Lorenzen, Daan Leijen; Swierstra, Wouter. F P 2: Fully in-Place Functional Programming. Proceedings of the ACM on Programming Languages. 2023, vol. 7, no. 198, pp. 275–304._
