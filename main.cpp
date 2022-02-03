/* Import */
#include "lapys.hpp"
#include <csignal>

/* ... */
using namespace Lapys;

/* Main */
int main() {
  struct program { static void stop(int const) { std::puts("\r\n" "segfaulted..."); std::exit(EXIT_SUCCESS); } };
  std::signal(SIGSEGV, &program::stop);

  // ...
  unsigned *const integer = Memory::allocateHeap(sizeof(unsigned));

  std::printf("[allocated]: %u (%p)" "\r\n", *new (integer) unsigned(42u), static_cast<void*>(integer));
  Memory::releaseHeap(integer);
  std::puts("[released]");
}
// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
