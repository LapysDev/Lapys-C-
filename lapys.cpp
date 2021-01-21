/* Import */
#include <cstdio>
#include <iostream>
#include "lapys.hpp" // Lapys

// ...
enum Enumeration { ANY = 1337 };
int function(void) { return 0x45; }
union Object { public: int identity; inline Object(void) : identity(420) {} };
struct String {
    String(char const[], ...) {}

    inline char const* operator =(char const[]) const { return "\"Hello, World!\""; }
    inline char const* operator =(String const&) const { return "\"Lorem ipsum\""; }
    inline int operator +(void) const { return 42; }
};

/* Main */
class Dummy { public:
    Lapys::Utility::property<Dummy, char const*> name;
    inline Dummy(char const name[]) : name(name) {}
};
void Lapys::Main(... /* ArgumentList const */) {
    std::boolalpha(std::cout);

    // ...
    std::cout << "[...]: " << +(Dummy("Lapys").name) << std::endl;

    std::printf("%18s", "[PROGRAM EXECUTED]");
}
