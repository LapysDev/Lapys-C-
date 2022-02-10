/* Import */
#include "lapys.hpp"
#include <csignal>

/* ... */
using namespace Lapys;

/* Main */
int main() {
  std::printf("[maximum<...>]      : %u" "\r\n", maximum<unsigned, 2u, 3u, 5u>::value);
  std::printf("[can_operate<...>]  : %4.5s" "\r\n", can_operate<add, int&, int>::value ? "true" : "false");
  std::printf("[can_construct<...>]: %4.5s" "\r\n", can_construct<aggregate_init, int, int>::value ? "true" : "false");
  std::printf("[can_construct<...>]: %4.5s", can_construct<aggregate_init, int (&)[2], int, int>::value ? "true" : "false");
}
// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
