# FastSBE

A command-line Python code generator that produces optimized C++ codecs for [Simple Binary Encoding (SBE)](https://github.com/FIXTradingCommunity/fix-simple-binary-encoding) messages from XML schema definitions.

## Why FastSBE?

Built for low-latency systems:

- **Decode is a view, not a parse.** Generated codecs are packed (`#pragma pack(1)`) with fields in wire order, so the struct layout *is* the SBE wire layout. Decoding is a `reinterpret_cast` over your buffer — nothing is constructed or copied.
- **Reads are single member loads.** Getters return the member directly: no allocation, no copy, no length or offset arithmetic at access time. Fixed-width sizes are compile-time `sizeof`; strings and variable-length data are returned as views into the buffer.
- **O(1) random access to repeating-group entries.** Entry `i` is reached as `base + i * block_length` — one multiply, no iteration over predecessors.
- **No runtime machinery.** Header-only, no virtual calls, `constexpr`/`noexcept` throughout. A whole message — header, fixed block, and groups — is one contiguous, heap-free object you can stack-allocate.
- **Encode mirrors decode.** Setters write straight into the buffer and groups are sized in place; there is no separate serialization pass.
- **Faster than the reference `sbe-tool`** — up to ~11× on decode and ~1.1-3.2× on encode (see [Performance](#performance)).

## Limitations

- **Little-endian hosts only.** Fields are read as native packed members with no byte-swapping, so the host byte order must match the wire (true on x86 and little-endian ARM).
- **No variable-length fields inside repeating groups.** Constant-stride entry indexing (`base + i * block_length`) assumes fixed-size entries; a nested group or variable-length field inside an entry would break it.

## Performance

Measured against the reference `sbe-tool`, same machine and message (lower is better). Reproduce locally with `./build_and_test.sh -b`, or see the Benchmark step of the [CMake workflow](.github/workflows/cmake.yml)

| Message | Operation | FastSBE | sbe-tool | Speedup |
| --- | --- | ---: | ---: | ---: |
| `NewOrderSingle` (flat) | decode | 13.0 ns | 49.2 ns | ~3.8× |
| `NewOrderSingle` (flat) | encode | 44.2 ns | 49.4 ns | ~1.1× |
| `MDIncrementalRefreshBook46` (repeating groups) | decode | 12.3 ns | 134 ns | ~10.9× |
| `MDIncrementalRefreshBook46` (repeating groups) | encode | 54.4 ns | 174 ns | ~3.2× |

Decoding gains most from the zero-copy view, and the gap widens with message complexity: a book message with repeating groups decodes ~11× faster than `sbe-tool`.

### Raw benchmark output (GitHub Actions, Linux runner)

```text
2026-06-12T10:28:01+00:00
Running ./test/benchmark/fixp/fixp_benchmark_test
Run on (4 X 3243.94 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x2)
  L1 Instruction 32 KiB (x2)
  L2 Unified 512 KiB (x2)
  L3 Unified 32768 KiB (x1)
Load Average: 0.93, 0.40, 0.15
----------------------------------------------------------------------------------------------
Benchmark                                                    Time             CPU   Iterations
----------------------------------------------------------------------------------------------
FastSBEFixture/BM_Decode_NewOrderSingle                   13.0 ns         13.0 ns     55062861
SbeToolFixture/BM_Decode_NewOrderSingle                   49.2 ns         49.2 ns     14037009
FastSBEFixture/BM_Encode_NewOrderSingle_from_struct       44.2 ns         44.2 ns     15828041
SbeToolFixture/BM_Encode_NewOrderSingle_from_struct       49.4 ns         49.4 ns     14274530
2026-06-12T10:28:06+00:00
Running ./test/benchmark/cme/cme_benchmark_test
Run on (4 X 2445.43 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x2)
  L1 Instruction 32 KiB (x2)
  L2 Unified 512 KiB (x2)
  L3 Unified 32768 KiB (x1)
Load Average: 0.93, 0.41, 0.16
----------------------------------------------------------------------------------------------------------
Benchmark                                                                Time             CPU   Iterations
----------------------------------------------------------------------------------------------------------
FastSBEFixture/BM_Decode_MDIncrementalRefreshBook46                   12.3 ns         12.3 ns     56808631
SbeToolFixture/BM_Decode_MDIncrementalRefreshBook46                    134 ns          134 ns      5208728
FastSBEFixture/BM_Encode_MDIncrementalRefreshBook46_from_struct       54.4 ns         54.4 ns     12670551
SbeToolFixture/BM_Encode_MDIncrementalRefreshBook46_from_struct        174 ns          174 ns      4016341
```
