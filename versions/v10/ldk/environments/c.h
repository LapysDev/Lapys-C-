/* Import */
#include <float.h> // Floating-Point
#include <locale.h> // Locale
#include <math.h> // Mathematics

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

#include <stdbool.h> // Standard Boolean
#include <string.h> // String

#ifndef HAVE_WCHAR_H // Wide Characters
#  include <wchar.h>
#endif
