/* Import */
#include "lapys.hpp"

/* ... */
using namespace Lapys;

/* Main */
int main() {
  std::printf("int(int)     : %4.5s" "\r\n", can_construct<int, int>     ::value ? "true" : "false");
  std::printf("int(int, int): %4.5s" "\r\n", can_construct<int, int, int>::value ? "true" : "false");
  std::printf("int + int          : %4.5s" "\r\n", can_operate<add, int, int>           ::value ? "true" : "false");
  std::printf("++int              : %4.5s" "\r\n", can_operate<pre_increment, int>      ::value ? "true" : "false");
  std::printf("void (&)(int) (int): %4.5s" "\r\n", can_operate<call, void (&)(int), int>::value ? "true" : "false");
  std::printf("void (int)    (int): %4.5s" "\r\n", can_operate<call, void (int),    int>::value ? "true" : "false");
  // std::printf("%u", static_cast<unsigned>(widthof<bit<42u> >::value));
}
// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
