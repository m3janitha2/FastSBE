# FastSBE

A command-line Python code generator that produces optimized C++ codecs for [Simple Binary Encoding (SBE)](https://github.com/FIXTradingCommunity/fix-simple-binary-encoding) messages from XML schema definitions.

## Why FastSBE?

Built for low-latency systems:

- **Decode is a view, not a parse.** Generated codecs are packed (`#pragma pack(1)`) with fields in wire order, so the struct layout *is* the SBE wire layout. Decoding is a `reinterpret_cast` over your buffer — nothing is constructed or copied.
- **Reads are single member loads.** Getters return the member directly: no allocation, no copy, no length or offset arithmetic at access time. Fixed-width sizes are compile-time `sizeof`; strings and variable-length data are returned as views into the buffer.
- **O(1) random access to repeating-group entries.** Entry `i` is reached as `base + i * block_length` — one multiply, no iteration over predecessors.
- **No runtime machinery.** Header-only, no virtual calls, `constexpr`/`noexcept` throughout. A whole message — header, fixed block, and groups — is one contiguous, heap-free object you can stack-allocate.
- **Encode mirrors decode.** Setters write straight into the buffer and groups are sized in place; there is no separate serialization pass.
- **Faster than the reference `sbe-tool`** — up to ~9× on decode and ~1.3-2.6× on encode (see [Performance](#performance)).

## Limitations

- **Little-endian hosts only.** Fields are read as native packed members with no byte-swapping, so the host byte order must match the wire (true on x86 and little-endian ARM).
- **No variable-length fields inside repeating groups.** Constant-stride entry indexing (`base + i * block_length`) assumes fixed-size entries; a nested group or variable-length field inside an entry would break it.

## Performance

Measured by the benchmark suite (`build_and_test.sh -b`) against the reference `sbe-tool`, same machine and message (lower is better):

| Message | Operation | FastSBE | sbe-tool | Speedup |
| --- | --- | ---: | ---: | ---: |
| `NewOrderSingle` (flat) | decode | 14.2 ns | 44.4 ns | ~3.1× |
| `NewOrderSingle` (flat) | encode | 31.8 ns | 40.8 ns | ~1.3× |
| `MDIncrementalRefreshBook46` (repeating groups) | decode | 14.4 ns | 131 ns | ~9.1× |
| `MDIncrementalRefreshBook46` (repeating groups) | encode | 60.7 ns | 158 ns | ~2.6× |

Decoding gains most from the zero-copy view, and the gap widens with message complexity: a book message with repeating groups decodes ~9× faster than `sbe-tool`.
