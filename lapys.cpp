/* Import */
#include <cstdio>
#include <iostream>
#include "lapys.hpp" // Lapys

enum Enumeration { ANY = 1337 };
int function(void) { return 0x45; }
class Object {};
struct String {
    String(char const[], ...) {}
    inline int operator +(void) const { return 42; }
};

void Lapys::Main(... /* ArgumentList const */) {
    std::boolalpha(std::cout);

    Lapys::Utility::shadow<int> const integer = 0x44;
    Lapys::Utility::shadow<int> const integers[2] = {1, 2};
    Lapys::Utility::shadow<String> string = "..."; {
        // would not work if `int const` was shadowed, instead
        std::cout << "[int]: " << ++integer << std::endl;
        std::cout << "[int]: " << integer++ << std::endl;

        // test for shadowed operator overloads
        std::cout << "[int + int]: " << integers[0] + 2 << std::endl;
        std::cout << "[int + int]: " << 1 + integers[1] << std::endl;
        std::cout << "[int + int]: " << integers[0] + integers[1] << std::endl;
        std::cout << "[String]: " << +string << std::endl;

        // test for incompatible operator overloads...
        new Lapys::Utility::shadow<Object>();
    }

    std::printf("%18s", "[PROGRAM EXECUTED]");
}
