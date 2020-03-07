/* Import */
    // [C Standard Library]
    #include <float.h> // Floating-Point
    #include <math.h> // Mathematics
    #include <stdbool.h> // Standard Boolean
    #include <stdio.h> // Standard Input-Output
    #include <string.h> // String

    #ifdef STDC_HEADERS // Standard ...
    #  include <stddef.h> // Standard Definition
    #  include <stdlib.h> // Standard Library
    #else
    #  ifdef HAVE_STDDEF_H // Standard Definition
    #     include <stddef.h>
    #  endif

    #  ifdef HAVE_STDLIB_H // Standard Library
    #      include <stdlib.h>
    #  else
    #      ifdef HAVE_MALLOC_H // Main Memory Allocation Point
    #          include <malloc.h>
    #      endif
    #  endif
    #endif

    // [...]
    #include <conio.h> // Console Input-Output
    #include <dirent.h> // Directory Entries
    #include <wchar.h> // Wide Characters
