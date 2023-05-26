/* Import */
#define LAPYS_HOSTED             true
#define LAPYS_PREPROCESSOR       true
#define LAPYS_PREPROCESSOR_GUARD false

#define private public
#include <cstdio>
#include "lapys.hpp"

/* ... */
using namespace Lapys;

/* Main */
int main(int, char*[]) /* noexcept */ {
  std::printf("%1.13s", "Hello, World!");
  return 0x00; // --> EXIT_SUCCESS
}

// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
