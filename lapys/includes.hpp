/* ... */
#ifndef LAPYS
# define LAPYS
  /* Namespace */
  namespace Lapys {}

  /* Import > ... */
  // : [C++ Standard Library]
  #include <algorithm> // Algorithm
  #include <cfloat>    // C Float
  #include <climits>   // C Limits
  #include <cstddef>   // C Standard Definition
  #include <cstdio>    // C Standard Input/ Output
  #include <cstdlib>   // C Standard Library
  #include <cstring>   // C String
  #include <memory>    // Memory
  #include <new>       // New

  // : [C Standard Library]
  #include <errno.h>   // Error No.
  #include <stdbool.h> // Standard Booleans
  #include <stdint.h>  // Standard Integers
  #include <wchar.h>   // Wide Characters

  // : [...]
  #include "extensions.h" // Extensions
  #include "macros.h"     // Macros
  #include "traits.hpp"   // Traits

  // : [UNIX]
  #if CPP_VENDOR & CPP__UNIX__VENDOR
  # include <stdlib.h>
  # include <sys/mman.h>
  #endif

  // : [Windows]
  #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
  # include <windows.h>
  # include <winnt.h>
  #   include <memoryapi.h>
  #endif

  // : [...]
  #include "mathematics.hpp" // Mathematics
  #include "memory.hpp"      // Memory
#endif
