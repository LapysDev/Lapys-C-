// ...
#ifndef LAPYS
    /* Definition */
    #define LAPYS

    /* Import */
    #include "definitions.hpp" // Definitions
    #include "includes.hpp" // Includes

    /* Namespace */
        /* ... */
        namespace Lapys {} namespace Macintosh {} namespace Windows {}

        /* Macintosh */
        /* Windows [32-Bit] */
        #include "architecture/macintosh.hpp"
        #include "architecture/windows.hpp"

        /* Lapys */
        namespace Lapys {
            /* Namespace > Lapys Development Kit */
            #include "ldk.hpp"

            /* [Global] Utilization */
            using Lapys::DevelopmentKit::Types::objects; // NOTE (Lapys) -> Registry of all custom object types.

            /* Phase > (Initiate, Terminate) */
            inline void Initiate() {}
            void Terminate() { objects.free(); }

            /* Main */
            int Main(...);
        }

    /* Utilization */
    using namespace Lapys::DevelopmentKit::Constants;
    using namespace Lapys::DevelopmentKit::Types;

    /* Main */
    BOOL WINAPI DllMain(HINSTANCE DLLHandlerInstance, DWORD forwardingReason, LPVOID reserved) { Lapys::Initiate(); const int programStatus = Lapys::Main(3u, forwardingReason, DLLHandlerInstance, reserved); Lapys::Terminate(); return programStatus; }
    int main(int argumentCount, char* argumentVector[]) { Lapys::Initiate(); const int programStatus = Lapys::Main(argumentCount, argumentVector); Lapys::Terminate(); return programStatus; }
    int wmain(int argumentCount, wchar_t* argumentVector[]) { Lapys::Initiate(); const int programStatus = Lapys::Main(argumentCount, argumentVector); Lapys::Terminate(); return programStatus; }
    int WINAPI WinMain(HINSTANCE handlerInstance, HINSTANCE previousHandlerInstance, LPSTR programInitiationCommandLine, int windowAppearance) { Lapys::Initiate(); const int programStatus = Lapys::Main(4u, programInitiationCommandLine, handlerInstance, previousHandlerInstance, windowAppearance); Lapys::Terminate(); return programStatus; }
#endif
