/* Import */
#include <cstdio>
#include <iostream>
#include "lapys.hpp" // Lapys

class Object {
    friend void Lapys::Main(...);
    private:
        struct NonInteger {};
        struct Integer {
            Integer(...) {}

            int operator +(void) { return 0x45; }
            operator int(void) const { return 1337; }
        };

    public:
        Lapys::Utility::accessor<Object, Integer> index;

        inline Object(Integer index = 1, ...) : index(index) {}
        Integer getIndex(void) const { return +(this -> index); }
};

/* Main */
void Lapys::Main(... /* ArgumentList const */) {
    std::boolalpha(std::cout);

    std::cout << "[Integer + Integer]: " << (
        Lapys::Utility::is_const_operation<Object::Integer, Lapys::Utility::operation::pre_add, Object::Integer>::value ? "const" :
        Lapys::Utility::is_mutable_operation<Object::Integer, Lapys::Utility::operation::pre_add, Object::Integer>::value ? "mutable" :
        "..."
    ) << std::endl;

    std::endl(std::cout);
    std::cout << "[accessor<Integer> + Integer]          : " << Object().getIndex() + 1 << std::endl;
    std::cout << "[Integer + accessor<Integer>]          : " << 1 + Object().getIndex() << std::endl;
    std::cout << "[accessor<Integer> + accessor<Integer>]: " << Object().getIndex() + Object().getIndex() << std::endl;

    std::printf("%18s", "[PROGRAM EXECUTED]");
}
