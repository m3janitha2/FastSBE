# sbe-v1 example schema

Extends the FIX SBE v1.0 example schema:
https://github.com/FIXTradingCommunity/fix-simple-binary-encoding/tree/master/v1-0-STANDARD

`NewOrderSingle` here is fixed-size (no repeating groups or variable-length
data), exercised by the `sbe_v1_encode_decode` round-trip test.
