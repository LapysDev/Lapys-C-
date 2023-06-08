/* Import */
#define LAPYS_HOSTED             true
#define LAPYS_PREPROCESSOR       true
#define LAPYS_PREPROCESSOR_GUARD false

#include <cstdio>
#include "lapys.hpp"

/* ... */
using namespace Lapys;

/* Main */
template <typename cumulation, typename base, std::size_t>
struct cumulate {
  typedef cumulation (*bruh)[sizeof(*instanceof<base>())];
};

template <typename, std::size_t>
struct map {
  typedef void type;
};

// ...
int main(int, char*[]) /* noexcept */ {
  // instanceof<collection<int (*)[1], int (*)[2], int (*)[3]>::build<trait>::type>() * 2;
  std::printf("%1.13s", "Hello, World!");
  return 0x00; // --> EXIT_SUCCESS
}

// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
