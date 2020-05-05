/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Import */
    #include <locale.h> // Locale
    #include <math.h> // Mathematics
    #if defined(STDC_HEADERS) // Standard ...
        #include <stddef.h> // Standard Definition
        #include <stdlib.h> // Standard Library
    #else
        #if defined(HAVE_STDDEF_H) // Standard Definition
        #include <stddef.h>
        #endif

        #if defined(HAVE_STDLIB_H) // Standard Library
            #include <stdlib.h>
        #elif defined(HAVE_MALLOC_H) // Memory Allocator
            #include <malloc.h>
        #endif
    #endif
    #include <stdbool.h> // Standard Boolean
    // #include <uchar.h> // Unicode Characters
    #ifndef HAVE_WCHAR_H // Wide Characters
        #include <wchar.h>
    #endif
#endif
