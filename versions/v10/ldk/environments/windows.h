/* [Microsoft Windows] ... */
#if defined(__TOS_WIN__) || defined(_WIN16) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN32_WCE) || defined(_WIN64) || defined(__WINDOWS__) // Microsoft Windows
    /* Definition > ... */
    #undef ldk__detected_platform
    #define ldk__detected_platform ldk_platform__windows

    /* Import */
    #include <stdarg.h> // Standard Arguments
    #include <windef.h> // Windows Definitions
    #include <wincon.h> // Windows Conventions
    #include <winbase.h> // Windows Base
    #if !(defined(NOGDI) || defined(_WINGDI_H)) // Windows GDI (Graphics Device Interface)
    #  include <wingdi.h>
    #endif
    #include <winuser.h> // Windows User
    #include <winnls.h> // Windows NLS
    #include <winver.h> // Windows Versioning
    #include <winnetwk.h> // Windows Networking
    #include <winreg.h> // Windows Registering
    #include <winsvc.h> // Windows Services

    // #  include "windows/commctrl.h" // Common Controls
    // #  include "windows/ftsiface.h" // ...
    // #  include "windows/olectl.h" // Object-Linking & Embedding Controls
    // #  include "windows/penwin.h" // Pen for Windows
    // #  include "windows/prsht.h" // Prop Sheet
    // #  include "windows/richedit.h" // Rich Edit
    // #  include "windows/smx.h" // Server Manager Extensions
    // #  include "windows/shellapi.h" // Shell API
    // #  include "windows/shlobj.h" // Shell Object
    // #  include "windows/vfw.h" // Video for Windows
    // #  include "windows/wfext.h" // Windows File Extensions
#endif
