/* Import */
#include <cstdio>
#include <iostream>
#include "lapys.hpp" // Lapys

enum Enumeration { ANY = 1337 };
int function(void) { return 0x45; }
class Object { public: int value; inline Object(void) : value(420) {} };
struct String {
    String(char const[], ...) {}

    inline char const* operator =(char const[]) const { return "\"Hello, World!\""; }
    inline char const* operator =(String const&) const { return "\"Lorem ipsum\""; }
    inline int operator +(void) const { return 42; }
};

void Lapys::Main(... /* ArgumentList const */) {
    std::boolalpha(std::cout);

    Lapys::Utility::shadow<Enumeration> const enumeration = ANY;
    Lapys::Utility::shadow<int> const integer = 0x44;
    Lapys::Utility::shadow<Object> const object = Object();
    int Object::* const member = &Object::value;
    Lapys::Utility::shadow<Object*> const pointer = new Object;
    Lapys::Utility::shadow<String> const string = "...";
    String stronk = "***"; {
        // would not work if `int const` was shadowed, instead
        std::cout << "[s-int (++)]: " << ++integer << std::endl;
        std::cout << "[s-int (++ int)]: " << integer++ << std::endl;
        std::cout << "[s-int (= int)]: " << (integer = 420) << std::endl;
        std::cout << "[s-int (= s-long)]: " << (integer = Lapys::Utility::shadow<long>(420)) << std::endl;
        std::cout << "[s-int (= s-int)]: " << (integer = Lapys::Utility::shadow<int>(420)) << std::endl;
        std::cout << "[s-int (+= int)]: " << (integer += 420) << std::endl;

        // test for shadowed operator overloads
        std::cout << "[s-int + int]: " << integer + 1 << std::endl;
        std::cout << "[int + s-int]: " << 1 + integer << std::endl;
        std::cout << "[s-int + s-int]: " << integer + integer << std::endl;

        std::cout << "[s-Enumeration]: " << enumeration << std::endl;

        std::cout << "[s-Object*]: " << pointer -> value << std::endl;
        std::cout << "[s-Object*]: " << pointer ->* member << std::endl;

        std::cout << "[s-String]: " << +string << std::endl;
        std::cout << "[s-String]: " << string.operator +() << std::endl;
        std::cout << "[String]: " << (stronk = "???") << std::endl;
        std::cout << "[s-String]: " << (string = "???") << std::endl;

        // ...
        static_cast<void>(object);
    }

    std::printf("%18s", "[PROGRAM EXECUTED]");
}
