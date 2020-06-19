/* Pragma */
#pragma once
#ifndef LAPYS_H
/* Definition > ... */
#  define LAPYS_H

/* Import */
// [Shim]
#  include "shims/polyfills.hpp" // ...

// [Libraries]
#  include "libraries/c/includes.h" // C Standard Library
#  include "libraries/c++/includes.hpp" // C++ Standard Library

// [Environment]
#  include "environments/linux/includes.h" // Linux
#  include "environments/windows/includes.h" // Microsoft Windows

// [Features]
    // [Types]
    #include "features/primitive/types.hpp" // Primitives
    #include "features/primitive/functions.hpp"

    #include "features/base/types.hpp" // Base
    #include "features/base/functions.hpp"

    // [Devices]
    #include "features/devices/devices.hpp"
    #include "features/devices/camera/camera.hpp" // Camera
    #include "features/devices/gamepad/gamepad.hpp" // Game Pad
    #include "features/devices/joystick/joystick.hpp" // Joystick
    #include "features/devices/keyboard/keyboard.hpp" // Keyboard
    #include "features/devices/microphone/microphone.hpp" // Microphone
    #include "features/devices/mouse/mouse.hpp" // Mouse
    #include "features/devices/router/router.hpp" // Router
    #include "features/devices/screen/screen.hpp" // Screen
    #include "features/devices/speaker/speaker.hpp" // Speaker

    // [Mathematics]
    #include "features/mathematics/constants.hpp"
    #include "features/mathematics/functions.hpp"

    // [Global]
    #include "features/global/constants.hpp" // Constants
    #include "features/global/functions.hpp" // Functions

// [...]
#  include "lapys.cpp"
#endif
