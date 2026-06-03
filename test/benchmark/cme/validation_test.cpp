#include <MDIncrementalRefreshBook46Data.h>
#include <fastsbe_benchmark.h>
#include <sbetool_benchmark.h>

// Round-trips the same data through each codec independently (encode then
// decode, with display) to confirm both produce a usable message.
int main()
{
    MDIncrementalRefreshBook46Data data{5, 5};

    char buffer1[4096]{};
    fastsbe::encode_MDIncrementalRefreshBook46_from_struct(buffer1, data, true);
    fastsbe::decode_MDIncrementalRefreshBook46(buffer1, true);

    char buffer2[4096]{};
    sbetool::encode_MDIncrementalRefreshBook46_from_struct(buffer2, sizeof(buffer2), data, true);
    sbetool::decode_MDIncrementalRefreshBook46(buffer2, sizeof(buffer2), true);
}
