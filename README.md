# FastSBE

A command-line Python code generator that produces optimized C++ codecs for [Simple Binary Encoding (SBE)](https://github.com/FIXTradingCommunity/fix-simple-binary-encoding) messages from XML schema definitions.

## Why FastSBE?

Built for low-latency systems:

- **Decode is a view, not a parse.** Generated codecs are packed (`#pragma pack(1)`) with fields in wire order, so the struct layout *is* the SBE wire layout. Decoding is a `reinterpret_cast` over your buffer — nothing is constructed or copied.
- **Reads are single member loads.** Getters return the member directly: no allocation, no copy, no length or offset arithmetic at access time. Fixed-width sizes are compile-time `sizeof`; strings and variable-length data are returned as views into the buffer.
- **O(1) random access to repeating-group entries.** Entry `i` is reached as `base + i * block_length` — one multiply, no iteration over predecessors.
- **No runtime machinery.** Header-only, no virtual calls, `constexpr`/`noexcept` throughout. A whole message — header, fixed block, and groups — is one contiguous, heap-free object you can stack-allocate.
- **Encode mirrors decode.** Setters write straight into the buffer and groups are sized in place; there is no separate serialization pass.
- **Faster than the reference `sbe-tool`** on both encode and decode — see [Performance](#performance).

## Limitations

- **Little-endian hosts only.** Fields are read as native packed members with no byte-swapping, so the host byte order must match the wire (true on x86 and little-endian ARM).
- **No variable-length fields inside repeating groups.** Constant-stride entry indexing (`base + i * block_length`) assumes fixed-size entries; a nested group or variable-length field inside an entry would break it.

## Performance

Figures below come from the GitHub Actions CMake workflow.

```console
2022-11-03T00:51:53+00:00
Running ./benchmark_test
Run on (2 X 2394.45 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x2)
  L1 Instruction 32 KiB (x2)
  L2 Unified 256 KiB (x2)
  L3 Unified 30720 KiB (x1)
Load Average: 1.22, 0.76, 0.31
----------------------------------------------------------------------------------------------
Benchmark                                                    Time             CPU   Iterations
----------------------------------------------------------------------------------------------
FastSBEFixture/BM_Decode_NewOrderSingle                   23.4 ns         23.4 ns     30990496
SbeToolFixture/BM_Decode_NewOrderSingle                   85.3 ns         85.3 ns      8025875
FastSBEFixture/BM_Encode_NewOrderSingle_from_struct       43.9 ns         43.9 ns     15479654
SbeToolFixture/BM_Encode_NewOrderSingle_from_struct        122 ns          121 ns      5462472
```
