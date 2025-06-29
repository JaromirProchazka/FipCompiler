#!/bin/bash

set -euo pipefail

# Configuration
TEST_REPETITIONS=1000 # 700 default
BASE_DIR="./compiled_programs_data"
RESULTS_FILE="$BASE_DIR/benchmark_results.csv"
TEMP_FILE="$BASE_DIR/temp.csv"

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
        # hyperfine \
        #     --warmup 3 \
        #     --runs "$TEST_REPETITIONS" \
        #     --export-csv "$TEMP_FILE" \
        #     "$normal_exe" \
        #     "$fip_exe"
        touch "$TEMP_FILE"

        # Capture CPU times from both executables
        total_fetch_normal=0
        total_algo_normal=0
        total_algo_sqrt_normal=0
        total_fetch_fip=0
        total_algo_fip=0
        total_algo_sqrt_fip=0

        avrg_fetch_normal=0
        avrg_algo_normal=0
        stddev_normal=0
        avrg_fetch_fip=0
        avrg_algo_fip=0
        stddev_fip=0
        for i in $(seq 1 $TEST_REPETITIONS); do
            # Run normal_exe and extract its elapsed time
            # out=$($normal_exe 2>&1)
            # t=$(printf "%s\n" "$out" | awk '/Elapsed CPU time:/ {print $NF}')
            # times="$times $t"

            # Run fip_exe and extract its elapsed time
            # out=$($fip_exe 2>&1)
            # t=$(printf "%s\n" "$out" | awk '/Elapsed CPU time:/ {print $NF}')
            # times="$times $t"

            # run normal_exe and capture both timings
            mapfile -t normal_times < <( "$normal_exe" \
                | grep "Elapsed CPU time:" \
                | awk '{print $4}' )
            # run fip_exe and capture both timings
            mapfile -t fip_times < <( "$fip_exe" \
                | grep "Elapsed CPU time:" \
                | awk '{print $4}' )

            if [[ ${#normal_times[@]} -ne 2 || ${#fip_times[@]} -ne 2 ]]; then
                echo "ERROR: expected 2 timings, got ${#normal_times[@]} and ${#fip_times[@]}"
                exit 1
            fi


            total_fetch_normal=$(awk -v nt="${normal_times[0]}" -v t="$total_fetch_normal" \
                'BEGIN { printf("%.7f", nt + t ) }')
            total_algo_normal=$(awk -v nt="${normal_times[1]}" -v t="$total_algo_normal" \
                'BEGIN { printf("%.7f", nt + t ) }')
            total_algo_sqrt_normal=$(awk -v nt="${normal_times[1]}" -v t="$total_algo_sqrt_normal" \
                'BEGIN { printf("%.7f", (nt * nt) + t ) }')

            total_fetch_fip=$(awk -v nt="${fip_times[0]}" -v t="$total_fetch_fip" \
                'BEGIN { printf("%.7f", nt + t ) }')
            total_algo_fip=$(awk -v nt="${fip_times[1]}" -v t="$total_algo_fip" \
                'BEGIN { printf("%.7f", nt + t ) }')
            total_algo_sqrt_fip=$(awk -v nt="${fip_times[1]}" -v t="$total_algo_sqrt_fip" \
                'BEGIN { printf("%.7f", (nt * nt) + t ) }')
        done

        avrg_fetch_normal=$(awk -v t="$total_fetch_normal" -v c="$TEST_REPETITIONS" \
                'BEGIN { printf("%.7f", t / c ) }')
        echo "avrg_fetch_normal{$avrg_fetch_normal} = total_fetch_normal{$total_fetch_normal} / TEST_REPETITIONS{$TEST_REPETITIONS}"

        avrg_algo_normal=$(awk -v t="$total_algo_normal" -v c="$TEST_REPETITIONS" \
                'BEGIN { printf("%.7f", t / c ) }')
        echo "avrg_algo_normal{$avrg_algo_normal} = total_algo_normal{$total_algo_normal} / TEST_REPETITIONS{$TEST_REPETITIONS}"

        stddev_normal=$(awk -v es="${total_algo_sqrt_normal}" -v e="$avrg_algo_normal" -v c="$TEST_REPETITIONS" \
            'BEGIN { printf("%.7f", sqrt( (es/c) - (e*e) ) ) }')  # sqrt( E[X^2] - E[X]^2 )
        echo "stddev_normal{$stddev_normal} = sqrt( (total_algo_sqrt_normal{$total_algo_sqrt_normal}/TEST_REPETITIONS{$TEST_REPETITIONS}) - avrg_algo_normal^2{$avrg_algo_normal^2} ) -- sqrt( E[X^2] - E[X]^2 )"


        avrg_fetch_fip=$(awk -v t="$total_fetch_fip" -v c="$TEST_REPETITIONS" \
                'BEGIN { printf("%.7f", t / c ) }')
        echo "avrg_fetch_fip{$avrg_fetch_fip} = total_fetch_fip{$total_fetch_fip} / TEST_REPETITIONS{$TEST_REPETITIONS}"

        avrg_algo_fip=$(awk -v t="$total_algo_fip" -v c="$TEST_REPETITIONS" \
                'BEGIN { printf("%.7f", t / c ) }')
        echo "avrg_algo_fip{$avrg_algo_fip} = total_algo_fip{$total_algo_fip} / TEST_REPETITIONS{$TEST_REPETITIONS}"

        stddev_fip=$(awk -v es="${total_algo_sqrt_fip}" -v e="$avrg_algo_fip" -v c="$TEST_REPETITIONS" \
            'BEGIN { printf("%.7f", sqrt( (es/c) - (e*e) ) ) }')  # sqrt( E[X^2] - E[X]^2 )
        echo "stddev_fip{$stddev_fip} = sqrt( (total_algo_sqrt_fip{$total_algo_sqrt_fip}/TEST_REPETITIONS{$TEST_REPETITIONS}) - avrg_algo_fip^2{$avrg_algo_fip^2} ) -- sqrt( E[X^2] - E[X]^2 )"
        

        # avrg_fetch_normal, avrg_algo_normal, stddev_normal, normal_exe
        # avrg_fetch_fip,    avrg_algo_fip,    stddev_fip,    fip_exe
        # TEMP_FILE, RESULTS_FILE
        awk -v f="$avrg_fetch_normal" \
            -v c="${base_name}_normal" \
            -v m="$avrg_algo_normal" \
            -v s="$stddev_normal" \
        'BEGIN {
            FS=OFS=","
            print "command","fetch_time","mean","stddev"
            print c, f, m, s
            exit
        }' > "$TEMP_FILE"

        awk -v f="$avrg_fetch_fip" \
            -v c="${base_name}_fip" \
            -v m="$avrg_algo_fip" \
            -v s="$stddev_fip" \
        'BEGIN {
            FS=OFS=","
            print c, f, m, s
            exit
        }' >> "$TEMP_FILE"


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