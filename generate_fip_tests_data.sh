#!/bin/bash

echo "============ [generate_fip_tests_data] Started Generation ============"

# Exit immediately if initial build steps fail
set -e

# Parse command line flags
replace_flag=0
basics_flag=0
benchmarks_flag=0
do_tests=1
results_destination="compiled_programs_data"

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
        --benchmarks)
            benchmarks_flag=1
            shift
            ;;
        --no-test)
            do_tests=0
            shift
            ;;
        *)
            echo "[generate_fip_tests_data] Unknown option: $1"
            echo "[generate_fip_tests_data] Usage: $0 [--replace] [--basics] [--no-test] [--benchmarks]"
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

if [ $basics_flag -eq 1 ]; then
    file_pattern="./bench/basic_*.ffip"
    echo "Processing only basic test files..."
elif [ $benchmarks_flag -eq 1 ]; then
    shopt -s extglob
    file_pattern='./bench/!(basic_*)*_@(fip|normal).ffip'
    echo "Processing only benchmarked test files..."
else
    file_pattern="./bench/*.ffip"
    echo "Processing all benchmark files..."
fi

# Process each .ffip file in the bench directory
banchmarks_utils/compile_stafip_scripts_in.sh "$file_pattern" "${results_destination}"

# Generate data for benchmarks
if [ $do_tests -eq 1 ]; then
    if [ $basics_flag -eq 0 ]; then
        echo "====== [generate_fip_tests_data] Generate data for benchmarks ========"
        ./banchmarks_utils/generate_banchmarks_data.sh
        echo "============= [generate_fip_tests_data] BANCHMARKS DONE =============="
    fi
else
    echo "[generate_fip_tests_data] Benchmarks are disabled"
fi

echo "================= [generate_fip_tests_data] ALL DONE ================="