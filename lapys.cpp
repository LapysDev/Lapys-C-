/* Import */
#include "lapys.hpp" // Lapys
#include <cstdio>

/* ... Lapys::Main(ArgumentList const); */
class Primitive {};
class Object : Primitive {};

int main(void) {
    std::printf("[Object, Object]: %s" "\r\n", Lapys::is_base<Object, Object>::value ? "true" : "false");
    std::printf("[Object, Primitive]: %s" "\r\n", Lapys::is_base<Object, Primitive>::value ? "true" : "false");
    std::printf("[Primitive, Object]: %s" "\r\n", Lapys::is_base<Primitive, Object>::value ? "true" : "false");
    std::printf("[Primitive, Primitive]: %s" "\r\n", Lapys::is_base<Primitive, Primitive>::value ? "true" : "false");
    std::printf("%18s", "[PROGRAM EXECUTED]");
}
