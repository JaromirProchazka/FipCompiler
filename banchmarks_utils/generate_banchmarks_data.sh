#!/bin/bash

# Configuration
TEST_REPETITIONS=250
BASE_DIR="./compiled_programs_data"
RESULTS_FILE="$BASE_DIR/benchmark_results.csv"
TEMP_FILE="temp.csv"

# Clean previous results
rm -f "$RESULTS_FILE" "$TEMP_FILE"

# Find all program pairs
find "$BASE_DIR" -type d -name "*_normal" -print0 | while IFS= read -r -d $'\0' normal_dir; do
    # Extract base name from directory
    base_name=$(basename "$normal_dir" "_normal")
    
    # Skip basic_* programs
    if [[ "$base_name" == basic_* ]]; then
        echo "[generate_banchmarks_data] Skipping basic_* program: $base_name"
        continue
    fi

    # Construct paths
    fip_dir="${normal_dir%_normal}_fip"
    normal_exe="$normal_dir/${base_name}_normal"
    fip_exe="$fip_dir/${base_name}_fip"

    # Verify both executables exist
    if [[ -x "$normal_exe" && -x "$fip_exe" ]]; then
        echo "[generate_banchmarks_data] Benchmarking pair:"
        echo "[generate_banchmarks_data]   Normal: $normal_exe"
        echo "[generate_banchmarks_data]   FIP:    $fip_exe"

        # Run benchmarks
        hyperfine \
            --warmup 3 \
            --runs "$TEST_REPETITIONS" \
            --export-csv "$TEMP_FILE" \
            "$normal_exe" \
            "$fip_exe"

        # Aggregate results
        if [[ ! -f "$RESULTS_FILE" ]]; then
            cp "$TEMP_FILE" "$RESULTS_FILE"
        else
            tail -n +2 "$TEMP_FILE" >> "$RESULTS_FILE"
        fi
    else
        echo "[generate_banchmarks_data] Skipping incomplete pair for $base_name"
    fi
done

# Final cleanup and reporting
rm -f "$TEMP_FILE"
echo -e "\n[generate_banchmarks_data] Benchmarking complete. Results saved to: $RESULTS_FILE"

if [[ ! -f "$RESULTS_FILE" ]]; then
    echo "[generate_banchmarks_data]    Error: No valid executable pairs found!"
    echo "[generate_banchmarks_data]        Check that:"
    echo "[generate_banchmarks_data]        1. Directory structure matches ../compiled_programs_data/<program_name>_{normal,fip}/"
    echo "[generate_banchmarks_data]        2. Executables are named <program_name>_{normal,fip} inside their directories"
    exit 1
fi

# Generate graphs
echo -e "\n[generate_banchmarks_data] Generating comparison graphs..."
python3 ./banchmarks_utils/generate_graphs.py "$RESULTS_FILE"

echo "================ [generate_banchmarks_data] ALL DONE ================="