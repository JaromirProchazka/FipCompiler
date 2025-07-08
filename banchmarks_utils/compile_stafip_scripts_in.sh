#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <file_pattern> <destination_directory>"
    exit 1
fi

shopt -s extglob

# Expand pattern into actual files
files=( $file_pattern )

file_pattern="$1"
destination_dir="$2"

shopt -s extglob
files=( $file_pattern )

# Build the compiler
cmake . && cmake --build . || {
    echo "[compile_stafip_scripts] Error: Failed to build the compiler"
    exit 1
}

# Compile utils library
mkdir -p "${destination_dir}/.lib"
clang++-15 -c -fPIE compiled_programs_data/.lib/ck_utils.cpp -o "${destination_dir}/.lib/ck_utils.o" || {
    echo "[compile_stafip_scripts] Error: Failed to compile utils library"
    exit 1
}

set +e

for ffip_file in "${files[@]}"; do
    base=$(basename "$ffip_file" .ffip)

    echo "[compile_stafip_scripts] Processing $base.ffip..."

    error_occurred=0

    mkdir -p "${destination_dir}/${base}/"

    echo "[compile_stafip_scripts] Folder ${destination_dir}/${base}/ for results made"

    # Compile the test file to LLVM IR code and data files
    (./stud-main/cecko5 -a "${destination_dir}/${base}/${base}.txt" \
        -o "${destination_dir}/${base}/${base}.ll" \
        "$ffip_file" || {
        echo "[compile_stafip_scripts] Error: Compilation to LLVM IR failed for $base"
        error_occurred=1
    }) | grep "error"

    # Generate .s IR code file
    if [ $error_occurred -eq 0 ]; then
        llc-15 -o "${destination_dir}/${base}/${base}.s" \
            "${destination_dir}/${base}/${base}.ll" || {
            echo "[compile_stafip_scripts] Error: Assembly generation failed for $base"
            error_occurred=1
        }
    fi

    # Create object file
    if [ $error_occurred -eq 0 ]; then
        clang-15 -c -fPIE "${destination_dir}/${base}/${base}.s" \
            -o "${destination_dir}/${base}/${base}.o" || {
            echo "[compile_stafip_scripts] Error: Object file creation failed for $base"
            error_occurred=1
        }
    fi

    # Compile final executable linked with util file
    if [ $error_occurred -eq 0 ]; then
        clang-15 -no-pie -o "${destination_dir}/${base}/${base}" \
            "${destination_dir}/${base}/${base}.o" \
            "${destination_dir}/.lib/ck_utils.o" -lstdc++ || {
            echo "[compile_stafip_scripts] Error: Linking failed for $base"
            error_occurred=1
        }
    fi

    # Cleanup
    rm -f "${destination_dir}/${base}/${base}.s" "${destination_dir}/${base}/${base}.ll" "${destination_dir}/${base}/${base}.o"

    if [ $error_occurred -eq 1 ]; then
        echo "[compile_stafip_scripts] Removing failed test directory: ${destination_dir}/${base}/"
        rm -rf "${destination_dir}/${base}/"
    else
        echo "[compile_stafip_scripts] ${destination_dir}/${base}/ successful"
    fi

done