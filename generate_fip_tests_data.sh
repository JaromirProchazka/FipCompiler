#!/bin/bash

echo "============ [generate_fip_tests_data] Started Generation ============"

# Exit immediately if initial build steps fail
set -e

# Build the compiler
cmake -DCMAKE_BUILD_TYPE=Debug . && cmake --build .

# Compile utils library
clang++ -c -fPIE compiled_programs_data/lib/ck_utils.cpp -o compiled_programs_data/lib/ck_utils.o

# Disable immediate exit for the loop processing
set +e

# Process each .ffip file in the test directory
for ffip_file in ./test/*.ffip; do
    # Get filename without path and extension
    base=$(basename "$ffip_file" .ffip)
    
    echo "[generate_fip_tests_data] Processing $base.ffip..."

    # Initialize error flag for this file
    error_occurred=0

    # Make dir for the generation results
    mkdir -p ./compiled_programs_data/${base}/

    echo "[generate_fip_tests_data] Folder ./compiled_programs_data/$base/ for results made"
    
    # Compile to LLVM IR
    ./stud-main/cecko5 -a "./compiled_programs_data/${base}/${base}.txt" \
        -o "./compiled_programs_data/${base}/${base}.ll" \
        "./test/${base}.ffip" || {
        echo "[generate_fip_tests_data] Error: Compilation to LLVM IR failed for $base"
        error_occurred=1
    }
    
    # Generate assembly from LLVM IR
    if [ $error_occurred -eq 0 ]; then
        llc -opaque-pointers -o "compiled_programs_data/${base}/${base}.s" \
            "compiled_programs_data/${base}/${base}.ll" || {
            echo "[generate_fip_tests_data] Error: Assembly generation failed for $base"
            error_occurred=1
        }
    fi
    
    # Compile to object file
    if [ $error_occurred -eq 0 ]; then
        clang -c -fPIE "compiled_programs_data/${base}/${base}.s" \
            -o "compiled_programs_data/${base}/${base}.o" || {
            echo "[generate_fip_tests_data] Error: Object file creation failed for $base"
            error_occurred=1
        }
    fi
    
    # Link executable
    if [ $error_occurred -eq 0 ]; then
        clang -no-pie -o "compiled_programs_data/${base}/${base}" \
            "compiled_programs_data/${base}/${base}.o" \
            "compiled_programs_data/lib/ck_utils.o" -lstdc++ || {
            echo "[generate_fip_tests_data] Error: Linking failed for $base"
            error_occurred=1
        }
    fi

    # Cleanup intermediate files for this test case
    rm -f compiled_programs_data/${base}/${base}.s compiled_programs_data/${base}/${base}.ll "compiled_programs_data/${base}/${base}.o"

    echo "[generate_fip_tests_data] compiled_programs_data/$base/ successful"

done

echo "================= [generate_fip_tests_data] ALL DONE ================="