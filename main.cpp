/* Import */
#define LAPYS_PREPROCESSOR true
#include <cstdio>
#include "lapys.hpp"

/* ... */
using namespace Lapys;

/* Main */
int main(int, char*[]) /* noexcept */ {
  #define stringify(source) #source
  std::puts(apply(stringify, default, default, this, _, is, _, single, _, identifier, break));
}
// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
