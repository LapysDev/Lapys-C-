/* Import */
#include <cstdio>
#include <iostream>
#include "lapys.hpp" // Lapys

// ...
enum Enumeration { ANY = 1337 };
int function(void) { return 0x45; }
union Object { public: int identity; inline Object(void) : identity(420) {} };
struct String {
    String(char const[] = NULL, ...) {}

    inline char const* operator =(char const[]) const { return "\"Hello, World!\""; }
    inline char const* operator =(String const&) const { return "\"Lorem ipsum\""; }

    inline int operator +(void) { return 420; }
    inline int operator +(void) const { return 42; }
};

/* Main */
class Immutable { public: Lapys::Utility::property<Immutable, String const> name; inline Immutable(...) : name() {} };
class Modifiable { public: Lapys::Utility::property<Modifiable, String> name; inline Modifiable(...) : name() {} };

void Lapys::Main(... /* ArgumentList const */) {
    std::boolalpha(std::cout);

    // ...
    std::cout << "[...]: " << +(Immutable("Lapys").name) << std::endl;
    std::cout << "[...]: " << +(Modifiable("Lapys").name) << std::endl;

    std::printf("%18s", "[PROGRAM EXECUTED]");
}
