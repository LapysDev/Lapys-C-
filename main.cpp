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
  // typedef cumulation (*bruh)[sizeof(*instanceof<base>())];
};

template <typename, std::size_t>
struct map {
  typedef void type;
};

// ...
int main(int, char*[]) /* noexcept */ {
  // sizeof(new (std::nothrow) int[(map<void, 0u>())]);
  std::puts(opinfo::nonoverloaded::has<opinfo::new_array_placement, std::nothrow_t, int, std::size_t>::value ? "true" : "false");
  // instanceof<collection<int (*)[1], int (*)[2], int (*)[3]>::build<cumulate>::type>() * 2;
  std::printf("%1.13s", "Hello, World!");
  return 0x00; // --> EXIT_SUCCESS
}

// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
