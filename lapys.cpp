/* Import */
#include "lapys.hpp" // Lapys
#include <cstdio>

/* ... Lapys::Main(ArgumentList const); */
class Object final {};
namespace Utility = Lapys::Utility;

int main(void) {
    std::printf("[...]: %s" "\r\n", Utility::is_same<int, typename Utility::base_of<int [3]>::type>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Utility::is_same<int, typename Utility::base_of<void, char>::type>::value ? "true" : "false");
    std::printf("%18s", "[PROGRAM EXECUTED]");
}
