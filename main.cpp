/* Import */
#include "lapys.hpp"

/* ... */
using namespace Lapys;

/* Main */
int main() {
  std::printf("[]: %4.5s" "\r\n", can_construct<int, int>::value ? "true" : "false");
  std::printf("[]: %4.5s" "\r\n", can_construct<int, int, int>::value ? "true" : "false");
  // std::printf("%u", static_cast<unsigned>(widthof<bit<42u> >::value));
}
// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
