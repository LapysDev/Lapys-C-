/* Import */
#include "lapys.hpp" // Lapys
#include <cstdio>

/* ... Lapys::Main(ArgumentList const); */
class Object final {};
int main(void) {
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (...)>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (...)&>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (...)&&>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (...) const>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (...) const&>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (...) const&&>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (...) const volatile>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (...) const volatile&>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (...) const volatile&&>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (...) volatile>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (...) volatile&>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (...) volatile&&>::value ? "true" : "false");

    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (&)(...)>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (*)(...)>::value ? "true" : "false");

    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (Object::**)(...)>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (Object::**)(...)&>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (Object::**)(...)&&>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (Object::**)(...) const>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (Object::**)(...) const&>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (Object::**)(...) const&&>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (Object::**)(...) const volatile>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (Object::**)(...) const volatile&>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (Object::**)(...) const volatile&&>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (Object::**)(...) volatile>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (Object::**)(...) volatile&>::value ? "true" : "false");
    std::printf("[...]: %s" "\r\n", Lapys::is_variadic<int (Object::**)(...) volatile&&>::value ? "true" : "false");

    std::printf("[{*}]: %s" "\r\n", Lapys::is_same<
        int (...),
        typename Lapys::remove_pointer<
        typename Lapys::remove_qualifiers<
        typename Lapys::remove_specifications<
            int (Object::**)(...) const
        >::type
        >::type
        >::type
    >::value ? "true" : "false");

    std::printf("%18s", "[PROGRAM EXECUTED]");
}
