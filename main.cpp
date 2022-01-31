/* Import */
#include "lapys.hpp"

/* ... */
using namespace Lapys;

/* Main */
int main() {
  std::printf("Hello, %p" "\r\n", static_cast<void*>(Memory::allocateHeap(69u)));
  std::printf("Maximum of 2, 3: %u" "\r\n", Math::maximum(2u, 3u));
  std::printf("Maximum of 2, 3, 5: %u", Math::maximum({2u, 3u, 5u}));
}
// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
