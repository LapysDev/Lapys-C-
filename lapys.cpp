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
    std::printf("%18s", "[PROGRAM EXECUTED]");
}
