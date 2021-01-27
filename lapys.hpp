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

    #include "shim" // Shim

    // : C/ C++ Standard Library; ...
    #if __CPP__VERSION__ > 1997uL || __CPP__VERSION__ < 2020uL
    #   include <stdbool.h> // Standard Boolean
    #else
    #   include <cstdbool> // C Standard Boolean
    #endif
    #if __CPP__VERSION__ > 1997uL
    #   include <type_traits> // Type Traits
    #endif

    #include "utility" // Utility

    /* Main */
    namespace Lapys { void Main(...); }
    __MAIN__ except(false) { Lapys::Main(); return EXIT_SUCCESS; }

    /* Deletion > ... --- NOTE (Lapys) -> Matches the order of definitions. */
    #undef __MAIN__
    #undef __WINDOWS__MAIN__
    #undef __WINDOWS_DLL__MAIN__

    #undef except__selector
    #undef except__selector_delay
    #undef except__state_anticipated
    #undef except__state_unexpected
    #undef except__state_unknown
    #undef except__tokenizer
    #undef except__tokenizer_delay
    #undef except__value_false
    #undef except__value_true
    #undef constable
    #undef constexpr
    #undef except
    #undef final
    #undef inline
    #undef is_except
    #undef nodecay
    #undef override
    #undef super
    #if false == __COMPILER_IS__ICC__
    #  undef typeof
    #endif

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
Set the Floating-Point Environment on initiation

template <typename type>
struct is_complete {
  constexpr inline static bool disambiguate(...) except(false) { return false; }
  template <typename subtype> constexpr inline static typeof(sizeof(subtype)) disambiguate(subtype* const) except(false) { return true; }

  constexpr static bool const value = disambiguate(static_cast<type*>(NULL));
};

inline bool isBigEndian(void) except(false) {
    constexpr unsigned int value = 1u;
    return 0u == *reinterpret_cast<unsigned char const*>(value);
}

inline bool isLittleEndian(void) except(false) {
    constexpr unsigned int value = 1u;
    return 0u != *reinterpret_cast<unsigned char const*>(value);
}
*/
