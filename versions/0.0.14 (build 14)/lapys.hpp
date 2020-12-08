/* ...
    --- WARN ---
        #Lapys: Unsupported compilers:
            - ARM MSVC v19.0 (WINE)
            - MSP430 gcc 4.5.3
            - RISC-V rv32gc clang
            - RISC-V rv64gc clang
            - WebAssembly clang
            - x86-64 gcc 4.1.2
*/
#ifndef __LAPYS__
  /* Import > Platforms */
  #include "platforms/linux"
  #include "platforms/windows"

  /* Definition > Main */
  #if platform__is_windows
  # define __MAIN__ int wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int const)
  #else
  # define __MAIN__ int main(int const, char const* const[])
  #endif

  /* Definition */
  #define __LAPYS__

  /* Import */
  // : Environments
  #include "environments/c"
  #include "environments/cpp"
  #include "environments/posix"

  // : Shims
  #include "shims/polyfills.hpp"
  #include "shims/type-traits.hpp"

  // : Features
  #include "features/exceptions.hpp"

  // : Mathematics
  #include "mathematics/constants.hpp"
  #include "mathematics/constants.cpp"

  #include "mathematics/functions.hpp"
  #include "mathematics/functions.cpp"

  // : Primitives
  #include "primitives/boolean.hpp"
  #include "primitives/character.hpp"
  #include "primitives/decimal.hpp"
  #include "primitives/function.hpp"
  #include "primitives/integer.hpp"
  #include "primitives/member.hpp"
  #include "primitives/number.hpp"
  #include "primitives/pointer.hpp"
  #include "primitives/string.hpp"
#endif
