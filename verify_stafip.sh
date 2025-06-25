#!/usr/bin/env bash
set -euo pipefail

TEST_DIR="./test"
TEST_FILES="${TEST_DIR}/*.ffip"
TMP_DIR="${TEST_DIR}/_tmp_outputs"

mkdir -p "$TMP_DIR"

pass=0
fail=0

banchmarks_utils/compile_stafip_scripts_in.sh "$TEST_FILES" "$TEST_DIR"

for ffip in "$TEST_DIR"/*.ffip; do
  [ -f "$ffip" ] || continue
  name="$(basename "${ffip%.ffip}")"

  gold="${ffip}.gold"
  exe="${TEST_DIR}/${name}/${name}"
  tmp="${TMP_DIR}/${name}.out"

  echo -n "Testing ${name} ... "

  if [ ! -f "$gold" ]; then
    echo "⚠️  Missing gold file (${gold}) — skipping"
    continue
  fi

  if [ ! -x "$exe" ]; then
    echo "⚠️  Missing or non-executable target (${exe}) — skipping"
    continue
  fi

  if "$exe" > "$tmp" 2>&1; then
    if diff -u -b -a "$gold" "$tmp"; then
      echo "✅ PASS"
      pass=$(($pass+1))
    else
      echo "❌ FAIL — output differs"
      fail=$(($fail+1))
    fi
  else
    echo "❌ FAIL — program exited with error"
    fail=$(($fail+1))
  fi
done

echo
echo "Summary: $pass passed, $fail failed."

# Clean-up

rm -rf "$TMP_DIR"

for ffip in "$TEST_DIR"/*.ffip; do
  name="$(basename "${ffip%.ffip}")"
  dir="${TEST_DIR}/${name}"
  if [ -d "$dir" ]; then
    rm -rf "$dir"
  fi
done

echo "========== DONE =========="

exit $(( fail > 0 ? 1 : 0 ))
