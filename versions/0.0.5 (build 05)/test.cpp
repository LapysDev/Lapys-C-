/* Import */
#include <iostream> // Input-Output Stream
#include "lapys.hpp" // Lapys

/* Main */
const int Lapys::Main(...) {
    // ...
    std::cout << "[PROGRAM EXECUTED]\n" << std::endl;

    // std::cout << "sizeof(Array): " << sizeof(Array) << std::endl;
    // std::cout << "sizeof(Boolean): " << sizeof(Boolean) << std::endl;
    // std::cout << "sizeof(Function): " << sizeof(Function) << std::endl;
    // std::cout << "sizeof(Number): " << sizeof(Number) << std::endl;
    // std::cout << "sizeof(Object): " << sizeof(Object) << std::endl;
    // std::cout << "sizeof(String): " << sizeof(String) << std::endl;
    // std::cout << "sizeof(Symbol): " << sizeof(Symbol);

    std::cout << "[NUMBER -> STRING]: " << LDKF::numberToString(1.4232) << std::endl;
    std::cout << "[NUMBER -> STRING]: " << LDKF::numberToString(-21.4232) << std::endl;
    std::cout << "[NUMBER -> STRING]: " << LDKF::numberToString(123.25) << std::endl;
    std::cout << "[NUMBER -> STRING]: " << LDKF::numberToString(-4321.25) << std::endl;
    // BigNumber number;

    // std::cout << number.toString() << std::endl;

    // Return
    return 0;
}
