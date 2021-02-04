/* Import */
#include <cstdio>
#include <iostream>
#include "lapys.hpp" // Lapys

class Object {
    private:
        struct Integer { Integer(...) {} int operator +(void) { return 0x45; } };
        struct NonInteger {};

    public:
        struct sus : public Lapys::Utility::accessor<Object, int> { template <typename type> sus(type argument) : Lapys::Utility::accessor<Object, int>(argument) {} } index;

        inline Object(int index = 1, ...) : index(index) {}
        int getIndex(void) const { return +(this -> index); }
};

/* Main */
void Lapys::Main(... /* ArgumentList const */) {
    std::boolalpha(std::cout);

    std::cout << "[...]: " << Lapys::Utility::is_const_operation<int, Lapys::Utility::operation::post_add, int>::value << std::endl;
    std::cout << "[accessor<int> + int]          : " << Object().index + 1 << std::endl;
    std::cout << "[int + accessor<int>]          : " << 1 + Object().index << std::endl;
    std::cout << "[accessor<int> + accessor<int>]: " << Object().index + Object().index << std::endl;

    std::printf("%18s", "[PROGRAM EXECUTED]");
}
