/* Import */
#include "lapys.hpp"

/* ... */
using namespace Lapys;

/* Main */
int main() {
  // std::printf("%u" "\r\n", static_cast<unsigned>(widthof<bit<42u> >  ::value));
  std::printf("%u" "\r\n", static_cast<unsigned>(widthof<Lapys::byte>::value));
}
// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
