# Commands

# Generate compilation files

for test file basic_if.ffip:

```
# build the compiler
cmake -DCMAKE_BUILD_TYPE=Debug . && cmake --build .

# compile the test file to LLVM IR code and data files (text of LLVM IR and a IR binary)
./stud-main/cecko5 -a "./compiled_programs_data/basic_if.txt" -o "././compiled_programs_data/basic_if.ll" ./test/basic_if.ffip

# generate .s IR code file from the compiled .ll IR code file
llc -opaque-pointers -o compiled_programs_data/basic_if.s compiled_programs_data/basic_if.ll

# clang -o compiled_programs_data/basic_if compiled_programs_data/basic_if.s

# create object file for the IR code
clang -c -fPIE compiled_programs_data/basic_if.s -o compiled_programs_data/basic_if.o

# compiling utils library with ckrt_malloc, ckrt_printf...
clang++ -c -fPIE compiled_programs_data/ck_utils.cpp -o compiled_programs_data/ck_utils.o

# compile test file for test linked with the util file
clang -no-pie -o compiled_programs_data/basic_if compiled_programs_data/basic_if.o compiled_programs_data/ck_utils.o -lstdc++

# run the compiled test file
./compiled_programs_data/basic_if
```

# Compile cecko1 - 5

in file main\CMakeLists.txt comment or uncomment wanted cecko targets

```
# in root

```

cmake -DCMAKE_BUILD_TYPE=Debug . && cmake --build . && ./stud-main/cecko5 ./test/quick_sort.ffip

# change tests

```
# in the project root folder
cd build/
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
./stud-main/cecko3 ../test/testdecl-elementary.c
cd ..
```

## Config

```
# in the project root folder
cd build/
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

## Build

```
# in the project root folder
cd build/
make
```

## Running

```
# in the project root folder
build/stud-main/cecko1 ./test/test1.c
```

or alternatively

```
# in the project root folder
cd build/
./stud-main/cecko1 ../test/test1.c
```

# BISON LOG

```bison log
cat build/stud-sol/caparser.y.output
```
