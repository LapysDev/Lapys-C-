/* Import */
#include "lapys.hpp" // Lapys
#include <cstdio>

/* ... Lapys::Main(ArgumentList const); */
int main(void) {
    enum Enumeration { ZERO = 0 };
    class Object final {};

    constexpr Lapys::shadow<Enumeration> enumeration = ZERO;
    constexpr Lapys::shadow<Object> object; static_cast<void>(object);
    constexpr Lapys::shadow<unsigned> variable = 1337u;

    std::printf("[...]: %i" "\r\n", +enumeration);
    std::printf("[...]: %u" "\r\n", +variable);
    std::printf("%18s", "[PROGRAM EXECUTED]");
}
