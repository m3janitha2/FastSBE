#!/usr/bin/env bash
#
# Build and run every FastSBE test with g++ against the prebuilt gtest/benchmark
# libraries under build/_deps. Use this where cmake is unavailable; the
# canonical flow is still:
#
#     cmake -S . -B build && cmake --build build && ctest --test-dir build
#
# Exits non-zero if any test fails.
set -u

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
GEN=("python3" "$ROOT/FastSBE/FastSBE.py")

GTINC="$ROOT/build/_deps/googletest-src/googletest/include"
GTEST="$ROOT/build/lib/libgtest.a"
GTEST_MAIN="$ROOT/build/lib/libgtest_main.a"
GBINC="$ROOT/build/_deps/googlebenchmark-src/include"
BMLIB="$ROOT/build/_deps/googlebenchmark-build/src/libbenchmark.a"

if [ ! -f "$GTEST" ]; then
    echo "error: prebuilt gtest not found at $GTEST" >&2
    echo "       run 'cmake -S . -B build' once to fetch gtest/benchmark." >&2
    exit 1
fi

CXX=(g++ -std=c++17 -O2 -pthread)
BIN="$(mktemp -d)"

# -v / --verbose: stream each test's stdout (gtest details + message dumps);
# default is quiet (only PASS/FAIL per test).
VERBOSE=0
case "${1:-}" in -v|--verbose) VERBOSE=1 ;; esac
UTIL="-I$ROOT/test/utility"
pass=0
fail=0
ok()  { echo "  PASS  $1"; pass=$((pass + 1)); }
bad() { echo "  FAIL  $1"; fail=$((fail + 1)); }

# build_and_run <name> <output> <compile args...>
build_and_run() {
    local name="$1" out="$2"; shift 2
    if ! "${CXX[@]}" "$@" -o "$out" 2>"$out.err"; then
        bad "$name"; sed 's/^/      /' "$out.err" | head -5; return
    fi
    local rc
    if [ "$VERBOSE" -eq 1 ]; then
        echo "  ----- $name output -----"
        "$out"; rc=$?
    else
        "$out" >/dev/null 2>&1; rc=$?
    fi
    if [ "$rc" -eq 0 ]; then ok "$name"; else bad "$name"; fi
}

echo "== generating codecs =="
"${GEN[@]}" /tmp/_v1.log  "$ROOT/test/endcode_decode/sbe-v1/example-schema.xml"       "$ROOT/test/endcode_decode/sbe-v1/generated"       "test::sbe" >/dev/null 2>&1
"${GEN[@]}" /tmp/_v2.log  "$ROOT/test/endcode_decode/sbe-v2-0-RC3/example-schema.xml" "$ROOT/test/endcode_decode/sbe-v2-0-RC3/generated" "sbetool"   >/dev/null 2>&1
"${GEN[@]}" /tmp/_cme.log "$ROOT/test/endcode_decode/cme_v13/cme-mdp3-v13.xml"        "$ROOT/test/endcode_decode/cme_v13/generated"      "cme"       >/dev/null 2>&1
"${GEN[@]}" /tmp/_fx.log  "$ROOT/test/benchmark/fixp/example-schema-sbe-v1.xml"       "$ROOT/test/benchmark/fixp/fastsbe"                "fastsbe"   >/dev/null 2>&1
"${GEN[@]}" /tmp/_cb.log  "$ROOT/test/benchmark/cme/cme-mdp3-v13.xml"                 "$ROOT/test/benchmark/cme/fastsbe"                 "fastsbe"   >/dev/null 2>&1

echo "== sbe-v2 (encode/decode round-trip) =="
V2="$ROOT/test/endcode_decode/sbe-v2-0-RC3"
V2INC="-I$V2 $UTIL -I$ROOT/test/endcode_decode/common -I$V2/generated -I$GTINC"
for src in "$V2"/encode_decode.cpp "$V2"/composite/*.cpp "$V2"/message/*.cpp; do
    n=$(basename "$src" .cpp)
    build_and_run "$n" "$BIN/$n" $V2INC "$src" "$GTEST" "$GTEST_MAIN"
done

echo "== sbe-v1 (decode) =="
V1="$ROOT/test/endcode_decode/sbe-v1"
build_and_run "decode_sbe_v1" "$BIN/decode_sbe_v1" "-I$V1" "-I$V1/generated" "$V1/decode_sbe_v1.cpp"

echo "== cme_v13 (encode/decode round-trip) =="
CV="$ROOT/test/endcode_decode/cme_v13"
build_and_run "cme_v13_encode_decode" "$BIN/cme_v13_encode_decode" "-I$CV" "-I$CV/generated" $UTIL "-I$GTINC" "$CV/encode_decode.cpp" "$GTEST"

echo "== benchmark validations (FastSbe vs SbeTool round-trip) =="
FX="$ROOT/test/benchmark/fixp"
build_and_run "fixp_validation" "$BIN/fixp_validation" "-I$FX" $UTIL "-I$GBINC" "$FX/validation_test.cpp" "$BMLIB"
CB="$ROOT/test/benchmark/cme"
build_and_run "cme_validation" "$BIN/cme_validation" "-I$CB" $UTIL "-I$GBINC" "$CB/validation_test.cpp" "$BMLIB"

echo ""
echo "== $pass passed, $fail failed =="
[ "$fail" -eq 0 ]
