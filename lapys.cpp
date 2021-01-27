/* Import */
#include <cstdio>
#include <iostream>
#include "lapys.hpp" // Lapys

class Object {
    private:
        struct Integer { Integer(...) {} int operator +(void) { return 0x45; } };
        struct NonInteger {};

    public:
        Lapys::Utility::accessor<Object, NonInteger> index;
        inline Object(...) : index() {}
};

/* Main */
void Lapys::Main(... /* ArgumentList const */) {
    std::boolalpha(std::cout);
    std::cout << "[]: " << +Object().index << std::endl;
    std::printf("%18s", "[PROGRAM EXECUTED]");
}
