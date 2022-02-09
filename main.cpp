/* Import */
#include "lapys.hpp"
#include <csignal>

/* ... */
using namespace Lapys;

/* Main */
int main() {
  std::printf("[...]: %u", Lapys::maximum<unsigned, 2u, 3u, 5u>::value);
}
// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
