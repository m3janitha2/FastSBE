#pragma once

#include <iostream>

// Shared test helper: dump a decoded/encoded SBE message between the markers
// gtest uses, so message bodies are easy to spot in test output. Lives in
// test/utility (already on every benchmark + encode_decode target's include
// path) so the fastsbe and sbetool benchmark headers can share ONE definition
// instead of each defining its own global template (which clashed when a single
// translation unit included both, forcing the sbetool copies to be renamed
// print_message2).
template <typename Msg>
inline void print_message(Msg &msg)
{
    std::cout << "[ MESSAGE  ]" << std::endl;
    std::cout << msg << std::endl;
    std::cout << "[----------]" << std::endl;
}
