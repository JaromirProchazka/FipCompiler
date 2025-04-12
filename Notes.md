# Commands

# Compile cecko1 - 5

in file main\CMakeLists.txt comment or uncomment wanted cecko targets

```
# in root

```

cmake -DCMAKE_BUILD_TYPE=Debug . && cmake --build . && ./stud-main/cecko3 ../test/testdecl-elementary.c

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
