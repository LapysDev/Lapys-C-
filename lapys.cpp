/* Import */
#include <cstdio>
#include <iostream>
#include "lapys.hpp" // Lapys

enum Enumeration { ANY = 1337 };
int function(void) { return 0x45; }
union Object { public: int identity; inline Object(void) : identity(420) {} };
struct String {
    String(char const[], ...) {}

    inline char const* operator =(char const[]) const { return "\"Hello, World!\""; }
    inline char const* operator =(String const&) const { return "\"Lorem ipsum\""; }
    inline int operator +(void) const { return 42; }
};

class Element {
    public:
    property<Element, char const[], &accessor, &mutator> innerText = "...";
};

void Lapys::Main(... /* ArgumentList const */) {
    std::boolalpha(std::cout);

    Lapys::Utility::shadow<int [3]> const array(1, 2, 3);
    Lapys::Utility::shadow<Enumeration> const enumeration = ANY;
    Lapys::Utility::shadow<int> const integer = 0x44;
    Lapys::Utility::shadow<Object> const object = Object();
    int Object::* const member = &Object::identity;
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

        std::cout << "[s-int [3]]: {" << array[0] << ", " << array[1] << ", " << array[2] << "}" << std::endl;
        std::cout << "[s-int [3]]: {" << *array << ", " << *(array + 1) << ", " << *(array + 2) << "}" << std::endl;

        std::cout << "[s-Enumeration]: " << enumeration << std::endl;

        std::cout << "[s-Object]: " << static_cast<Object&>(object).identity << std::endl;
        std::cout << "[s-Object]: " << static_cast<Object&>(object).*member << std::endl;
        std::cout << "[s-Object*]: " << pointer -> identity << std::endl;
        std::cout << "[s-Object*]: " << pointer ->* member << std::endl;
        std::cout << "[s-Object*]: " << (*pointer).identity << std::endl;
        std::cout << "[s-Object*]: " << (*pointer).*member << std::endl;

        std::cout << "[s-String]: " << +string << std::endl;
        std::cout << "[s-String]: " << string.operator +() << std::endl;
        std::cout << "[String]: " << (stronk = "???") << std::endl;
        std::cout << "[s-String]: " << (string = "???") << std::endl;
    }

    std::printf("%18s", "[PROGRAM EXECUTED]");
}
