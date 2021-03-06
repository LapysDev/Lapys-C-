/* Import --- WARN (Lapys) -> Imported in order. */
/* #include <windows.h> --- ERROR (Lapys) -> Includes conflicting declaration of `boolean` type. */

#include <stdarg.h> // Standard Arguments
#include <windef.h> // Windows Definitions
#include <wincon.h> // Windows Conventions
#include <winbase.h> // Windows Base
#if !(defined(NOGDI) || defined(_WINGDI_H))
#include <wingdi.h> // Windows GDI (Graphics Device Interface)
#endif
#include <winuser.h> // Windows User
#include <winnls.h> // Windows NLS
#include <winver.h> // Windows Versioning
#include <winnetwk.h> // Windows Networking
#include <winreg.h> // Windows Registering
#include <winsvc.h> // Windows Services

/* Namespace > Windows */
namespace Windows {}
