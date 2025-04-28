#!/bin/bash

echo "============ [generate_fip_tests_data] Started Generation ============"

# Exit immediately if initial build steps fail
set -e

# Parse command line flags
replace_flag=0
basics_flag=0
do_tests=1

while [[ $# -gt 0 ]]; do
    case "$1" in
        --replace)
            replace_flag=1
            shift
            ;;
        --basics)
            basics_flag=1
            shift
            ;;
        --no-test)
            do_tests=0
            shift
            ;;
        *)
            echo "[generate_fip_tests_data] Unknown option: $1"
            echo "[generate_fip_tests_data] Usage: $0 [--replace] [--basics]"
            exit 1
            ;;
    esac
done

# Handle --replace flag
if [ $replace_flag -eq 1 ]; then
    echo "[generate_fip_tests_data] Cleaning compiled_programs_data (preserving .lib)..."
    if [ -d "compiled_programs_data" ]; then
        # Remove everything except .lib folder and its contents
        find compiled_programs_data/ -mindepth 1 -not -path 'compiled_programs_data/.lib*' -exec rm -rf {} +
    fi
fi

# Build the compiler
cmake -DCMAKE_BUILD_TYPE=Debug . && cmake --build .

# Compile utils library
clang++ -c -fPIE compiled_programs_data/.lib/ck_utils.cpp -o compiled_programs_data/.lib/ck_utils.o

# Disable immediate exit for the loop processing
set +e

# Determine file pattern based on --basics flag
if [ $basics_flag -eq 1 ]; then
    file_pattern="./test/basic_*.ffip"
    echo "Processing only basic test files..."
else
    file_pattern="./test/*.ffip"
    echo "Processing all test files..."
fi

# Process each .ffip file in the test directory
for ffip_file in $file_pattern; do
    # Get filename without path and extension
    base=$(basename "$ffip_file" .ffip)
    
    echo "[generate_fip_tests_data] Processing $base.ffip..."

    # Initialize error flag for this file
    error_occurred=0

    # Make dir for the generation results
    mkdir -p ./compiled_programs_data/${base}/

    echo "[generate_fip_tests_data] Folder ./compiled_programs_data/$base/ for results made"
    
    # compile the test file to LLVM IR code and data files (text of LLVM IR and a IR binary)
    ./stud-main/cecko5 -a "./compiled_programs_data/${base}/${base}.txt" \
        -o "./compiled_programs_data/${base}/${base}.ll" \
        "./test/${base}.ffip" || {
        echo "[generate_fip_tests_data] Error: Compilation to LLVM IR failed for $base"
        error_occurred=1
    }
    
    # generate .s IR code file from the compiled .ll IR code file
    if [ $error_occurred -eq 0 ]; then
        llc -opaque-pointers -o "compiled_programs_data/${base}/${base}.s" \
            "compiled_programs_data/${base}/${base}.ll" || {
            echo "[generate_fip_tests_data] Error: Assembly generation failed for $base"
            error_occurred=1
        }
    fi
    
    # create object file for the IR code
    if [ $error_occurred -eq 0 ]; then
        clang -c -fPIE "compiled_programs_data/${base}/${base}.s" \
            -o "compiled_programs_data/${base}/${base}.o" || {
            echo "[generate_fip_tests_data] Error: Object file creation failed for $base"
            error_occurred=1
        }
    fi
    
    # compile test file for test linked with the util file
    if [ $error_occurred -eq 0 ]; then
        clang -no-pie -o "compiled_programs_data/${base}/${base}" \
            "compiled_programs_data/${base}/${base}.o" \
            "compiled_programs_data/.lib/ck_utils.o" -lstdc++ || {
            echo "[generate_fip_tests_data] Error: Linking failed for $base"
            error_occurred=1
        }
    fi

    # Cleanup intermediate files for this test case
    rm -f compiled_programs_data/${base}/${base}.s compiled_programs_data/${base}/${base}.ll "compiled_programs_data/${base}/${base}.o"

    if [ $error_occurred -eq 1 ]; then
        echo "Removing failed test directory: compiled_programs_data/${base}/"
        rm -rf "compiled_programs_data/${base}/"
    fi

    echo "[generate_fip_tests_data] compiled_programs_data/$base/ successful"

done

# Generate data for benchmarks
if [ $do_tests -eq 1 ]; then
    echo "====== [generate_fip_tests_data] Generate data for benchmarks ========"
    ./banchmarks_utils/generate_banchmarks_data.sh
    echo "============= [generate_fip_tests_data] BANCHMARKS DONE =============="
else

    echo "[generate_fip_tests_data] Benchmarks are disabled"
fi

echo "================= [generate_fip_tests_data] ALL DONE ================="