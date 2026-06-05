#!/usr/bin/env bash
#
# One-command build + test for FastSBE via the project's CMake/CTest setup.
# CMake is a hard project requirement; this script is just a convenience wrapper
# so a full build + test (+ optional benchmarks) is a single command.
#
#   build_and_test.sh        configure, build, and run all tests (ctest)
#   build_and_test.sh -v     ... with verbose, per-test output
#   build_and_test.sh -b     ... and run the benchmark suites after the tests
#
# Flags compose (e.g. -v -b). Exits non-zero if configure, build, or any test fails.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD="$ROOT/build"
BUILD_TYPE="${BUILD_TYPE:-Release}"

VERBOSE=0
BENCH=0
for arg in "$@"; do
    case "$arg" in
        -v|--verbose) VERBOSE=1 ;;
        -b|--bench)   BENCH=1 ;;
        *) echo "usage: $(basename "$0") [-v|--verbose] [-b|--bench]" >&2; exit 2 ;;
    esac
done

if ! command -v cmake >/dev/null 2>&1; then
    echo "error: cmake is required but was not found on PATH" >&2
    exit 1
fi

echo "== configure =="
cmake -S "$ROOT" -B "$BUILD" -DCMAKE_BUILD_TYPE="$BUILD_TYPE"

echo "== build =="
cmake --build "$BUILD" --config "$BUILD_TYPE" -j

echo "== test =="
if [ "$VERBOSE" -eq 1 ]; then
    ( cd "$BUILD" && ctest -C "$BUILD_TYPE" -V )
else
    ( cd "$BUILD" && ctest -C "$BUILD_TYPE" --output-on-failure )
fi

# -b/--bench: timing suites (not pass/fail) run after the tests, one per schema.
if [ "$BENCH" -eq 1 ]; then
    echo "== benchmarks (FastSbe vs SbeTool) =="
    "$BUILD/test/benchmark/fixp/fixp_benchmark_test"
    "$BUILD/test/benchmark/cme/cme_benchmark_test"
fi
