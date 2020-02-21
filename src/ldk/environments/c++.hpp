/* Import --- NOTE (Lapys) -> Platform-independent imports. */
#include <float.h> // Floating-Point
#include <locale.h> // Locale
#include <math.h> // Mathematics
#ifdef STDC_HEADERS // Standard ...
#  include <stddef.h> // Standard Definition
#  include <stdlib.h> // Standard Library
#else
#  ifdef HAVE_STDDEF_H // Standard Definition
#  include <stddef.h>
#  endif

#  ifdef HAVE_STDLIB_H // Standard Library
#      include <stdlib.h>
#  else
#      ifdef HAVE_MALLOC_H // Memory Allocator
#          include <malloc.h>
#      endif
#  endif
#endif
#include <stdbool.h> // Standard Boolean
#include <string.h> // String
#ifndef HAVE_WCHAR_H // Wide Characters
#  include <wchar.h>
#endif

/* Logic --- NOTE (Lapys) -> Platform-dependent imports. */
#ifdef __ANDROID__ // Android
#elif defined(__APPLE__ ) && defined(__MACH__) // Apple Macintosh
#elif defined(__gnu_linux__) || defined(linux) || defined(__linux) || defined(__linux__) // Linux
#elif defined(__TOS_WIN__) || defined(_WIN16) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN32_WCE) || defined(_WIN64) || defined(__WINDOWS__) // Microsoft Windows
#  include <stdarg.h> // Standard Arguments
#  include <windef.h> // Windows Definitions
#  include <wincon.h> // Windows Conventions
#  include <winbase.h> // Windows Base
#  if !(defined(NOGDI) || defined(_WINGDI_H)) // Windows GDI (Graphics Device Interface)
#      include <wingdi.h>
#  endif
#  include <winuser.h> // Windows User
#  include <winnls.h> // Windows NLS
#  include <winver.h> // Windows Versioning
#  include <winnetwk.h> // Windows Networking
#  include <winreg.h> // Windows Registering
#  include <winsvc.h> // Windows Services
#endif
