/* Import */
#include <iostream>
#include "lapys.hpp" // Lapys

class Object {};
int main(void) /* ... Lapys::Main(ArgumentList const); */ {
    Lapys::property<Object, int> dummy = 0x3C;
    Lapys::property<Object, int> number = dummy;

    // dummy = 0;
    // number = dummy;

    {}                 std::cout << "[...]: " << number << std::endl;
    { number += 011; } std::cout << "[...]: " << number << std::endl;

    std::printf("%18s", "[PROGRAM EXECUTED]");
}
