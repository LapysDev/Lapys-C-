/* ... */
#ifndef __LAPYS__
    /* Definition > ... */
    #define __LAPYS__

    /* Pragmatic > ... */
    // #pragma once
    //
    // #pragma STDC CX_LIMITED_RANGE OFF
    // #pragma STDC FENV_ACCESS ON
    // #pragma STDC FP_CONTRACT ON

    /* Namespace */
    namespace Lapys {}

    /* Import */
    // : C++ Standard Library; ...
    #include <climits> // C Limits
    #include <cstddef> // C Standard Definitions
    #include <cstdlib> // C Standard Library

    #include "polyfills" // Polyfills

    // : C/ C++ Standard Library; ...
    #if __CPP__VERSION__ < 2020uL
    #   include <cstdbool> // C Standard Boolean
    #else
    #   include <stdbool.h> // Standard Boolean
    #endif

    #if __CPP__VERSION__ > 1997uL
    #   include <type_traits> // Type Traits
    #endif

    #include "structure" // Structure

    /* Deletion > ... --- NOTE (Lapys) -> Matches the order of definitions. */
    #undef __MAIN__
    #undef __WINDOWS__MAIN__
    #undef __WINDOWS_DLL__MAIN__

    #if __CPP__VERSION__ < 2011uL
    #  undef except__selector
    #  undef except__selector_delay
    #  undef except__state_anticipated
    #  undef except__state_unexpected
    #  undef except__state_unknown
    #  undef except__tokenizer
    #  undef except__tokenizer_delay
    #  undef except__value_false
    #  undef except__value_true

    #  undef constexpr
    #  undef final
    #  undef inline
    #  undef override
    #endif
    #undef constable
    #undef except
    #undef is_except
    #undef super
    #undef specific

    #undef __PLATFORM_IS__APPLE_MACINTOSH__
    #undef __PLATFORM_IS__LINUX__
    #undef __PLATFORM_IS__MICROSOFT_WINDOWS__
    #undef __PLATFORM_IS__POSIX__
    #undef __PLATFORM_IS__UNIX__

    #undef __COMPILER_IS__ARM__
    #undef __COMPILER_IS__CLANG__
    #undef __COMPILER_IS__GNU__
    #undef __COMPILER_IS__ICC__
    #undef __COMPILER_IS__MSVC__

    #undef __C__VERSION__
    #undef __CPP__VERSION__
    #undef __CPP_COMMAND_LINE_INTERFACE__VERSION__
    #undef __CPP_EMBEDDED__VERSION__
    #undef __ENVIRONMENT_IS__C__
    #undef __ENVIRONMENT_IS__CPP__
    #undef __ENVIRONMENT_IS__CPP_COMMAND_LINE_INTERFACE__
    #undef __ENVIRONMENT_IS__CPP_EMBEDDED__
#endif

/*
Set the Floating-Point Environment on initiate

template <typename type>
struct is_complete {
  constexpr static bool test(...) noexcept { return false; }
  template <typename subtype> constexpr static decltype(sizeof(subtype)) test(subtype* const) noexcept { return true; }

  constexpr static bool const value = test((type*) 0);
};

inline bool isBigEndian(void) noexcept {
    constexpr unsigned int value = 1u;
    return 0u == *reinterpret_cast<unsigned char const*>(value);
}

inline bool isLittleEndian(void) noexcept {
    constexpr unsigned int value = 1u;
    return 0u == *reinterpret_cast<unsigned char const*>(value);
}
*/
