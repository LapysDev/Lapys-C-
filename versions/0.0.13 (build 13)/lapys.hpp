/* Logic */
#ifndef LAPYS_H_
    /* Definition > (Lapys, ...) */
    #  define LAPYS_H_

    #  if environment__is_windows
    #     define __MAIN__ int wWinMain(HINSTANCE, HINSTANCE, LPWSTR commandLineArgumentString, int const)
    #  else
    #     define __MAIN__ int main(int const commandLineArgumentCount, char* const commandLineArguments[])
    #  endif

    /* Import > ... */
        // [Polyfills]
        #  include "shims/polyfills.hpp"

        // [Environments]
        #  include "environments/c" // C Standard Library
        #  include "environments/cpp" // C++ Standard Library
        #  include "environments/posix" // POSIX Standard Library

        // [Platforms]
        #  include "platforms/linux" // Linux
        #  include "platforms/windows" // Microsoft Windows

        // [Mathematics]
        #  include "mathematics/constants.hpp"
        #  include "mathematics/functions.hpp"

        // [Primitives]
        #  include "primitives/fraction.hpp"
        #  include "primitives/integer.hpp"
        #  include "primitives/member.hpp"
        #  include "primitives/number.hpp"
        #  include "primitives/pointer.hpp"
        #  include "primitives/string.hpp"

    /* Namespace > Lapys */
    namespace Lapys {
        /* [Features] Import > ... */
            // [...]
            #  include "features/definitions.hpp" // NOTE (Lapys) -> Define all features.

            // [Interface]
                /* [...] */ #  include "features/exceptions.hpp" // ... --- NOTE (Lapys) -> Interface for safely fault-terminating the (current) application.
                /* [Memory] */ #  include "features/memory.hpp" // Memory

                // [Data]
                #  include "features/variable.hpp" // Variable
                #  include "features/array.hpp" // Array
                #     include "features/big-number.hpp" // : Big Number
                #  include "features/function.hpp" // Function
                #  include "features/object.hpp" // Object
                #  include "features/stream.hpp" // Stream
                #  include "features/string.hpp" // String

                // [Native]
                #  include "features/system.hpp" // System
                #  include "features/interface.hpp" // Interface
                #     include "features/console.hpp" // : Console
                #     include "features/window.hpp" // : Window
                #  include "features/entries.hpp" // Entries
                #  include "features/process.hpp" // Process

                // [Devices]
                #  include "features/device.hpp" // Device
                #     include "features/camera.hpp" // : Camera
                #     include "features/gamepad.hpp" // : Gamepad
                #     include "features/keyboard.hpp" // : Keyboard
                #     include "features/printer.hpp" // : Printer
                #     include "features/speaker.hpp" // : Speaker

                /* [Graphics] */ #  include "features/graphics.hpp" // Graphics

            // [Implementation] ...
            #  include "features/exceptions.cpp"

            #  include "features/memory.cpp"
            #  include "features/variable.cpp"
            #  include "features/array.cpp"
            #  include "features/big-number.cpp"
            #  include "features/function.cpp"
            #  include "features/object.cpp"
            #  include "features/stream.cpp"
            #  include "features/string.cpp"
            #  include "features/system.cpp"
            #  include "features/interface.cpp"
            #  include "features/console.cpp"
            #  include "features/window.cpp"
            #  include "features/entries.cpp"
            #  include "features/process.cpp"
            #  include "features/device.cpp"
            #  include "features/camera.cpp"
            #  include "features/gamepad.cpp"
            #  include "features/keyboard.cpp"
            #  include "features/printer.cpp"
            #  include "features/speaker.cpp"
            #  include "features/graphics.cpp"

        /* Main */
        void Main(Process::Arguments const[]);

        /* Phase */
        void Initiate(void);
        void Reset(void);
        void Update(void);
        void Terminate(void);
    }

    /* Main */
    __MAIN__ { using Process::Signal;
        /* ... --- NOTE (Lapys) -> Set everything up before invoking the custom entry point. */
        Process::setCurrentProcessSignalHandler(Signal::INTERRUPT, Exception::terminate);
        Process::setCurrentProcessTerminateHandler(Process::currentProcessTerminateHandler);

        /* ... */
        Lapys::Main((Process::Arguments const*) Process::getCurrentProcessArguments());

        // Return --- NOTE (Lapys) -> `MSG::wParam` does not get returned in Microsoft Windows platforms.
        return EXIT_SUCCESS;
    }
#endif
