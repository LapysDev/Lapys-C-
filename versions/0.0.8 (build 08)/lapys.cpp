/* Import */
#include <iostream>
#include "src/ldk.hpp"
#include "src/lapys.hpp"

/* Main */
int main(void) {
    // [Begin] Print
    std::cout.write("[PROGRAM INITIATED]", 19u); std::endl(std::cout);

    std::cout << "[boolean (sizeof)]: " << sizeof(LapysDevelopmentKit::Types::boolean) << std::endl;
    std::cout << "[character (sizeof)]: " << sizeof(LapysDevelopmentKit::Types::character) << std::endl;
    std::cout << "[fraction (sizeof)]: " << sizeof(LapysDevelopmentKit::Types::fraction) << std::endl;
    std::cout << "[integer (sizeof)]: " << sizeof(LapysDevelopmentKit::Types::integer) << std::endl;
    std::cout << "[null_pointer (sizeof)]: " << sizeof(LapysDevelopmentKit::Types::null_pointer) << std::endl;
    std::cout << "[number (sizeof)]: " << sizeof(LapysDevelopmentKit::Types::number) << std::endl;
    std::cout << "[object (sizeof)]: " << sizeof(LapysDevelopmentKit::Types::object) << std::endl;
    std::cout << "[pointer (sizeof)]: " << sizeof(LapysDevelopmentKit::Types::pointer) << std::endl;
    std::cout << "[primitive (sizeof)]: " << sizeof(LapysDevelopmentKit::Types::primitive) << std::endl;
    std::cout << "[shared_pointer (sizeof)]: " << sizeof(LapysDevelopmentKit::Types::shared_pointer) << std::endl;
    std::cout << "[size (sizeof)]: " << sizeof(LapysDevelopmentKit::Types::size) << std::endl;
    std::cout << "[string (sizeof)]: " << sizeof(LapysDevelopmentKit::Types::string) << std::endl;
    std::cout << "[unique_pointer (sizeof)]: " << sizeof(LapysDevelopmentKit::Types::unique_pointer) << std::endl;

    // [End] Print
    std::cout.write("[PROGRAM TERMINATED]\0", 21u);

    // Return
    return 0;
}

// void Lapys::Main(String arguments) {
//     // [Begin] Print
//     console.log("[PROGRAM INITIATED]");

//     // [End] Print
//     console.log("[PROGRAM TERMINATED]");
// }
