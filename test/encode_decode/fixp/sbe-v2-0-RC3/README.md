# sbe-v2-0-RC3 example schema

Extends the FIX SBE v2.0-RC3 example schema:
https://github.com/FIXTradingCommunity/fix-simple-binary-encoding/tree/master/v2-0-RC3

`NewOrderSingle` here adds repeating groups and variable-length data, exercised
by the `encode_decode` round-trip plus the `composite_*` and `message_*` field
tests.
