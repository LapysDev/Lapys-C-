/* Import */
#include <cstdio>
#include <iostream>
#include "lapys.hpp" // Lapys

enum Enumeration { ANY = 1337 };
int function(void) { return 0x45; }
class Object {};
class String { public: String(char const[], ...) {} };

void Lapys::Main(... /* ArgumentList const */) {
    std::boolalpha(std::cout);

    Lapys::Utility::shadow<int> const integer = 0x44; {
        // would not work if `int const` was shadowed, instead
        std::cout << "[int]: " << ++integer << std::endl;
        std::cout << "[int]: " << integer++ << std::endl;

        // test for incompatible operator overloads...
        new Lapys::Utility::shadow<Object>();
        new Lapys::Utility::shadow<String>("...");
    }

    std::printf("%18s", "[PROGRAM EXECUTED]");
}
