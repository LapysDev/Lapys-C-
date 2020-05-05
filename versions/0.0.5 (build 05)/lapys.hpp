/* Import */
#include <fcntl.h> // Functional
#include <math.h> // Mathematics
#include <stdlib.h> // Standard Library
#include <unistd.h> // UNIX Standard
#include <windows.h> // Windows

// ...
#ifndef LAPYS
    /* Namespace */
        /* ... */
        namespace Lapys {} namespace Macintosh {} namespace Windows {}

        /* Macintosh */
        namespace Macintosh {}

        /* Windows [32-Bit] */
        namespace Windows {}

        /* Lapys */
        namespace Lapys {
            /* Namespace */
                /* Development Kit */
                namespace DevelopmentKit {
                    namespace Functions {}
                    namespace Mathematics {}
                    inline namespace Types {}
                }
                    /* Shorthand */
                    namespace LDK = Lapys::DevelopmentKit;
                    namespace LDKF = Lapys::DevelopmentKit::Functions;
                    namespace LDKM = Lapys::DevelopmentKit::Mathematics;
                    namespace LDKT = Lapys::DevelopmentKit::Types;

                namespace DevelopmentKit {
                    /* Import */
                    #include "Development Kit/Functions.hpp"
                    #include "Development Kit/Mathematics.hpp"
                    #include "Development Kit/Types.hpp"
                }
                    /* Utilization */
                    using namespace Lapys::DevelopmentKit::Types;

                /* Processes */
                namespace Processes {
                    /* Global > Program Initiated */
                    Boolean ProgramInitiated = false;
                }

            /* Function > Main */
            const int Main(...);
        }
            /* Shorthand */
            namespace LDK = Lapys::DevelopmentKit;
            namespace LDKF = Lapys::DevelopmentKit::Functions;
            namespace LDKM = Lapys::DevelopmentKit::Mathematics;
            namespace LDKT = Lapys::DevelopmentKit::Types;

    /* Main */
    BOOL WINAPI DllMain(HINSTANCE DLLHandlerInstance, DWORD forwardingReason, LPVOID reserved) { if (Lapys::Processes::ProgramInitiated) return 0; else { Lapys::Processes::ProgramInitiated = true; return Lapys::Main(3u, forwardingReason, DLLHandlerInstance, reserved); } }
    int main(int argumentCount, char* argumentVector[]) { if (Lapys::Processes::ProgramInitiated) return 0; else { Lapys::Processes::ProgramInitiated = true; return Lapys::Main(argumentCount, argumentVector); } }
    int wmain(int argumentCount, wchar_t* argumentVector[]) { if (Lapys::Processes::ProgramInitiated) return 0; else { Lapys::Processes::ProgramInitiated = true; return Lapys::Main(argumentCount, argumentVector); } }
    int WINAPI WinMain(HINSTANCE handlerInstance, HINSTANCE previousHandlerInstance, LPSTR programInitiationCommandLine, int windowAppearance) { if (Lapys::Processes::ProgramInitiated) return 0; else { Lapys::Processes::ProgramInitiated = true; return Lapys::Main(4u, programInitiationCommandLine, handlerInstance, previousHandlerInstance, windowAppearance); } }

    /* Definition > ... */
    #define LAPYS
#endif
