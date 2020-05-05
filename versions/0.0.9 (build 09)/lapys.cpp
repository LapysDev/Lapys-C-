/* Import */
#include <iostream>
#include "src/ldk.hpp"
#include "src/lapys.hpp"

/* Main */
int main(void) {
    // [Begin] Print
    std::cout.write("[PROGRAM INITIATED]", 19u); std::endl(std::cout);

    std::cout << "    [boolean (sizeof)]: \t\t" << sizeof(LapysDevelopmentKit::Types::boolean) << " \tbyte(s)" << std::endl;
    std::cout << "    [character (sizeof)]: \t\t" << sizeof(LapysDevelopmentKit::Types::character) << " \tbyte(s)" << std::endl;
    std::cout << "    [fraction (sizeof)]: \t\t" << sizeof(LapysDevelopmentKit::Types::fraction) << " \tbyte(s)" << std::endl;
    std::cout << "    [integer (sizeof)]: \t\t" << sizeof(LapysDevelopmentKit::Types::integer) << " \tbyte(s)" << std::endl;
    std::cout << "    [null_pointer (sizeof)]: \t\t" << sizeof(LapysDevelopmentKit::Types::null_pointer) << " \tbyte(s)" << std::endl;
    std::cout << "    [number (sizeof)]: \t\t\t" << sizeof(LapysDevelopmentKit::Types::number) << " \tbyte(s)" << std::endl;
    std::cout << "    [object (sizeof)]: \t\t\t" << sizeof(LapysDevelopmentKit::Types::object) << " \tbyte(s)" << std::endl;
    std::cout << "    [pointer (sizeof)]: \t\t" << sizeof(LapysDevelopmentKit::Types::pointer) << " \tbyte(s)" << std::endl;
    std::cout << "    [primitive (sizeof)]: \t\t" << sizeof(LapysDevelopmentKit::Types::primitive) << " \tbyte(s)" << std::endl;
    std::cout << "    [raw_pointer (sizeof)]: \t\t" << sizeof(LapysDevelopmentKit::Types::raw_pointer) << " \tbyte(s)" << std::endl;
    std::cout << "    [shared_smart_pointer (sizeof)]: \t" << sizeof(LapysDevelopmentKit::Types::shared_smart_pointer) << " \tbyte(s)" << std::endl;
    std::cout << "    [size (sizeof)]: \t\t\t" << sizeof(LapysDevelopmentKit::Types::size) << " \tbyte(s)" << std::endl;
    std::cout << "    [string (sizeof)]: \t\t\t" << sizeof(LapysDevelopmentKit::Types::string) << " \tbyte(s)" << std::endl;
    std::cout << "    [unique_smart_pointer (sizeof)]: \t" << sizeof(LapysDevelopmentKit::Types::unique_smart_pointer) << " \tbyte(s)" << std::endl;
    std::cout.put('\n');

    // [End] Print
    std::cout.write("[PROGRAM TERMINATED]\0", 21u); std::flush(std::cout);

    // Return
    return 0;
}

// void Lapys::Main(String arguments) {
//     // [Begin] Print
//     console.log("[PROGRAM INITIATED]");

//     // [End] Print
//     console.log("[PROGRAM TERMINATED]");
// }
