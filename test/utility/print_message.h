#pragma once

#include <iostream>

// Print a message between markers so it stands out in test output.
template <typename Msg>
inline void print_message(Msg &msg)
{
    std::cout << "[ MESSAGE  ]" << std::endl;
    std::cout << msg << std::endl;
    std::cout << "[----------]" << std::endl;
}
