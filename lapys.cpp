/* Import */
#include "lapys.hpp" // Lapys
#include <iostream>

/* ... Lapys::Main(ArgumentList const); */
int main(void) {
    class Object final { public:
        Lapys::property<Object, char const*> name;
        Lapys::property<Object, char const*> subname;
    } object = {"Lapys", "Gyrnet"};

    {} std::cout << "[...]: " << object.name << std::endl;
    {} std::cout << "[...]: " << +object.name << std::endl;
    {} std::cout << "[...]: " << (object.name + 1) << std::endl;
    {} std::cout << "[...]: " << (1 + object.name) << std::endl;
    { ++object.name; } std::cout << "[...]: " << object.name << std::endl;
    { object.name = "Jyrsper"; } std::cout << "[...]: " << object.name << std::endl;
    { object.name = object.subname; } std::cout << "[...]: " << object.name << std::endl;

    std::printf("%18s", "[PROGRAM EXECUTED]");
}
