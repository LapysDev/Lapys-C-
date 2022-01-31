/* Import */
#include "lapys.hpp"

/* ... */
using namespace Lapys;

/* Main */
int main() {
  unsigned *const integer = Memory::allocateHeap(sizeof(unsigned));

  std::printf("[allocated]: %u" "\r\n", *integer);
  Memory::releaseHeap(integer);
  std::puts("[released]");
}
// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
