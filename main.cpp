/* Import */
#define LAPYS_HOSTED       true
#define LAPYS_PREPROCESSOR true
#include <cstdio>
#include "lapys.hpp"

/* ... */
using namespace Lapys;

#define codegen(argument) [argument]//void function<argument>(subapply(subcodegen, default, apply_comma, arity(argument)));
# define subcodegen(argument) int argument_ ## argument

// del main.i && cls && clang++ -E -P -std=c++98 -Wall -Werror -Wextra main.cpp -o main.i
// del main.i && cls && g++ -E -P -std=c++98 -Wall -Werror -Wextra main.cpp -o main.i
// del main.i && cls && cl /P /std:c++14 /W4 main.cpp
// del main.i && cls && icl -P -std=c++14 -Wall -Werror -w3 main.cpp -o main.i
// apply(codegen, default, default, 1, 2, 3)

/* Main */
int main(int, char*[]) /* noexcept */ {
  std::puts(apply(default, default, default));
  std::puts(apply(default, default, apply_comma));
  std::puts(apply(default, default, default, A));
  std::puts(apply(default, default, apply_comma, A));
  std::puts(apply(default, default, default, A, B));
  std::puts(apply(default, default, apply_comma, A, B));
  std::puts(apply(default, default, default, A, B, C));
  std::puts(apply(default, default, apply_comma, A, B, C));
  std::printf("%1.13s", "Hello, World!");
}
// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
