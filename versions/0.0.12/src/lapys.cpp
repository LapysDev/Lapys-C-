/* Pragma */
#pragma once
#ifndef LAPYS_CPP
/* Definition > ... */
#  define LAPYS_CPP

/* Import */
// [Types]
#  include "features/primitive/types.cpp" // Primitives
#  include "features/primitive/functions.cpp"

#  include "features/base/types.cpp" // Base
#  include "features/base/functions.cpp"

// [Devices]
#include "features/devices/devices.cpp"
#include "features/devices/camera/camera.cpp" // Camera
#include "features/devices/gamepad/gamepad.cpp" // Game Pad
#include "features/devices/joystick/joystick.cpp" // Joystick
#include "features/devices/keyboard/keyboard.cpp" // Keyboard
#include "features/devices/microphone/microphone.cpp" // Microphone
#include "features/devices/mouse/mouse.cpp" // Mouse
#include "features/devices/router/router.cpp" // Router
#include "features/devices/screen/screen.cpp" // Screen
#include "features/devices/speaker/speaker.cpp" // Speaker

// [Mathematics]
#include "features/mathematics/functions.cpp"

// [Global]
#include "features/global/functions.cpp" // Functions
#endif
