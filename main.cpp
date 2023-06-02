/* Import */
#define LAPYS_HOSTED             true
#define LAPYS_PREPROCESSOR       true
#define LAPYS_PREPROCESSOR_GUARD false

#include <cstdio>
#include "lapys.hpp"

/* ... */
using namespace Lapys;

/* Main */
int main(int, char*[]) /* noexcept */ {
  instanceof<typename collection<int (&)[3], int (&)[2], int (&)[1]>::concatenate<collection<int (*)[3], int (*)[2], int (*)[1]> >::type>() * 2;
  std::printf("%1.13s", "Hello, World!");
  return 0x00; // --> EXIT_SUCCESS
}

// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
