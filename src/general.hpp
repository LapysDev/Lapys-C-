/* Pragma */
#pragma once

/* Import */
#include "libraries/c/includes.h" // C Standard Library
#include "libraries/c++/includes.hpp" // C++ Standard Library

#include "environments/linux/includes.h" // Linux
#include "environments/windows/includes.h" // Windows

#include "shims/polyfills.hpp" // ... --- NOTE (Lapys) -> Shiv required differences between alternative implementations and versions of C++.

/* Class > ... */
struct array;
struct boolean;
struct character;
struct integral;
struct null_pointer;
struct number;
struct pointer;
struct primitive;
struct rational;
struct raw_pointer;
struct string;
struct wide;

/* Definition */
    // Array ...
    // Number ...
    // Pointer ...
    struct pointer__allocate_heap_memory;
    template <typename type> void pointer__free_heap_memory(type* const) noexcept;
    template <typename type> void pointer__source_copy_memory(type* const, type* const, size_t const) noexcept;
    template <typename type> void pointer__source_move_memory(type* const, type* const, size_t const) noexcept;

    // String ...
    size_t string__length(char* const) noexcept;
    size_t string__length(char const* const) noexcept;
    size_t string__length(char8_t* const) noexcept;
    size_t string__length(char8_t const* const) noexcept;
    size_t string__length(char16_t* const) noexcept;
    size_t string__length(char16_t const* const) noexcept;
    size_t string__length(char32_t* const) noexcept;
    size_t string__length(char32_t const* const) noexcept;
    size_t string__length(signed char* const) noexcept;
    size_t string__length(signed char const* const) noexcept;
    size_t string__length(unsigned char* const) noexcept;
    size_t string__length(unsigned char const* const) noexcept;
    size_t string__length(wchar_t* const) noexcept;
    size_t string__length(wchar_t const* const) noexcept;

/* Import */
#include "general.cpp" // NOTE (Lapys) -> Define all data interfaces.
#include "shims/primitives.cpp" // NOTE (Lapys) -> Modified self-managed atomic types.
#include "shims/types.cpp" // NOTE (Lapys) -> Modified type interfaces.

#include "shims/definitions.hpp" // NOTE (Lapys) -> Atomic/ minimal development code features and re-definitions.
#include "shims/constants.hpp" // NOTE (Lapys) -> Global utility constants and objects.

/* Main */
void Main(Arguments const);

#if IS_LINUX_ENVIRONMENT
int main(int const /*argumentCount*/, char* const /*argumentVector*/[]) {
    // Return
    return EXIT_SUCCESS;
}

#elif IS_WINDOWS_ENVIRONMENT // CHECKPOINT (Lapys) -> Get the directory of the executing script and de-allocate each argument string.
int WinMain(HINSTANCE const /*instanceHandle*/, HINSTANCE const /*previousInstanceHandle*/, LPSTR const /*programInitiationCommandLineArguments*/, int const/*windowAppearance*/) {
    // Return
    return EXIT_SUCCESS;
}

#else
int main(void) {
    // Return
    return EXIT_SUCCESS;
}

#endif
