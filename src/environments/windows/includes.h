/* Import */
    // [...]
    #if defined(__NT__) || defined(__TOS_WIN__) || defined(_WIN16) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN32_WCE) || defined(_WIN64) || defined(__WINDOWS__) // Microsoft Windows
        #define IS_WINDOWS_ENVIRONMENT true
        #define WIN32_LEAN_AND_MEAN

        #include <stdarg.h> // Standard Arguments
        #include <windef.h> // Windows Definitions
        #include <wincon.h> // Windows Conventions
        #include <winbase.h> // Windows Base
        #if !(defined(NOGDI) || defined(_WINGDI_H)) // Windows GDI (Graphics Device Interface)
        #    include <wingdi.h>
        #endif
        #include <winuser.h> // Windows User
        #include <winnls.h> // Windows NLS
        #include <winver.h> // Windows Versioning
        #include <winnetwk.h> // Windows Networking
        #include <winreg.h> // Windows Registering
        #include <winsvc.h> // Windows Services
    #else
        #define IS_WINDOWS_ENVIRONMENT false
    #endif
