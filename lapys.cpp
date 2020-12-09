/* Import */
#include "lapys.hpp" // Lapys
#include <cstdio>

/* ... Lapys::Main(ArgumentList const); */
enum BaseEnumeration {};
class BaseObject {};
enum class BaseScopedEnumeration {};
enum Enumeration : char {};
class Object final {};
enum class ScopedEnumeration : char {};
union Union final {};

namespace Utility = Lapys::Utility;

int main(void) {
    std::printf("[...]: %s" "\r\n", Utility::is_enum<int>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Utility::is_enum<Enumeration>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Utility::is_enum<Object>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Utility::is_enum<Union>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Utility::is_enum<ScopedEnumeration>::value ? "true" : "false");
    std::printf("%18s", "[PROGRAM EXECUTED]");
}
