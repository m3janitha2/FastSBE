#include <cstdlib>
#include <iostream>
#include <ctime>

#include <benchmark/benchmark.h>

#include <MDIncrementalRefreshBook46Data.h>
#include <fastsbe_benchmark.h>
#include <sbetool_benchmark.h>

// Data is built once per fixture; SetUp() encodes a buffer so the decode
// benchmark has something to read. Each benchmark loop body contains only the
// encode or decode call - no data generation is measured.

class FastSBEFixture : public benchmark::Fixture
{
public:
    void SetUp(const ::benchmark::State &state)
    {
        fastsbe::encode_MDIncrementalRefreshBook46_from_struct(buffer_, data, false);
    }

    char buffer_[4096]{};
    MDIncrementalRefreshBook46Data data{10, 10};
};

class SbeToolFixture : public benchmark::Fixture
{
public:
    void SetUp(const ::benchmark::State &state)
    {
        sbetool::encode_MDIncrementalRefreshBook46_from_struct(buffer_, sizeof(buffer_), data, false);
    }

    char buffer_[4096]{};
    MDIncrementalRefreshBook46Data data{10, 10};
};

BENCHMARK_F(FastSBEFixture, BM_Decode_MDIncrementalRefreshBook46)(benchmark::State &st)
{
    for (auto _ : st)
    {
        fastsbe::decode_MDIncrementalRefreshBook46(buffer_, false);
    }
}

BENCHMARK_F(SbeToolFixture, BM_Decode_MDIncrementalRefreshBook46)(benchmark::State &st)
{
    for (auto _ : st)
    {
        sbetool::decode_MDIncrementalRefreshBook46(buffer_, sizeof(buffer_), false);
    }
}

BENCHMARK_F(FastSBEFixture, BM_Encode_MDIncrementalRefreshBook46_from_struct)(benchmark::State &st)
{
    for (auto _ : st)
    {
        fastsbe::encode_MDIncrementalRefreshBook46_from_struct(buffer_, data, false);
    }
}

BENCHMARK_F(SbeToolFixture, BM_Encode_MDIncrementalRefreshBook46_from_struct)(benchmark::State &st)
{
    for (auto _ : st)
    {
        sbetool::encode_MDIncrementalRefreshBook46_from_struct(buffer_, sizeof(buffer_), data, false);
    }
}

BENCHMARK_MAIN();
