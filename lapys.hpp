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
    // : C++ Standard Library
    #include <climits> // C Limits
    #include <cstddef> // C Standard Definitions
    #include <cstdlib> // C Standard Library

    // : ...
    #include "polyfills" // Polyfills
    #include "structure" // Structure

    // : C Standard Library
    #include <stdbool.h> // Standard Boolean

    /* Deletion > ... */
    #undef __MAIN__
    #undef __WINDOWS__MAIN__
    #undef __WINDOWS_DLL__MAIN__

    #if __ENVIRONMENT_IS__CPP__
    #   undef is_noexcept
    #   undef super

    #   if __CPP__VERSION__ < 2003uL
    #       undef constable
    #       undef noexcept
    #       undef specific
    #   elif __CPP__VERSION__ < 2011uL
    #       undef constable
    #       undef noexcept
    #       undef specific
    #   endif

    #   if __CPP__VERSION__ < 2011uL
    #       undef constexpr
    #       undef final
    #       undef inline
    #       undef override
    #   endif
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
