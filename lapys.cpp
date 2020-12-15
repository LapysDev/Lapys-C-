/* Import */
#include "lapys.hpp" // Lapys
#include <cstdio>

/* ... Lapys::Main(ArgumentList const); */
int main(void) {
    enum Enumeration { ENUM_VALUE = 420 };
    class Object final {};

    constexpr Lapys::shadow<Enumeration> enumeration = ENUM_VALUE;
    constexpr Lapys::shadow<unsigned> integer = 1330u;
    constexpr Lapys::shadow<Object> object; static_cast<void>(object);

    std::printf("[...]: %i" "\r\n", +enumeration);
    std::printf("[...]: %u" "\r\n", integer + 7u);
    std::printf("[...]: %u" "\r\n", integer += 12u);

    std::printf("%18s", "[PROGRAM EXECUTED]");
}
