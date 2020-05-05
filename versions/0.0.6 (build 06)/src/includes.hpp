/* Import */
    // Limits
    #include <limits.h>

    // Locale
    #include <locale.h>

    // Memory Allocator
    #include <malloc.h>

    // Mathematics
    #include <math.h>

    // Standard ...
    #if defined(STDC_HEADERS)
        # include <stddef.h> // Standard Definition
        # include <stdlib.h> // Standard Library
    #else
        #if defined(HAVE_STDDEF_H)
            #include <stddef.h> // Standard Definition
        #endif

        #if defined(HAVE_STDLIB_H)
            #include <stdlib.h> // Standard Library
        #elif defined(HAVE_MALLOC_H)
            #include <malloc.h> // Memory Allocator
        #endif
    #endif

    // Standard Boolean
    #include <stdbool.h>

    // Unicode Characters
    /* #include <uchar.h> */

    // UNIX Standard
    #include <unistd.h>

    // Wide Characters
    #ifdef HAVE_WCHAR_H
        #include <wchar.h>
    #endif
