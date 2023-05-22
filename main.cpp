/* Import */
#define LAPYS_HOSTED       true
#define LAPYS_PREPROCESSOR true
#include <cstdio>
#include "lapys.hpp"

/* ... */
using namespace Lapys;

// #define codegen(argument) [argument]//void function<argument>(subapply(subcodegen, default, apply_comma, arity(argument)));
// # define subcodegen(argument) int argument_ ## argument

// del main.i && cls && clang++ -E -P -std=c++98 -Wall -Werror -Wextra main.cpp -o main.i
// del main.i && cls && g++ -E -P -std=c++98 -Wall -Werror -Wextra main.cpp -o main.i
// del main.i && cls && cl /P /std:c++14 /W4 main.cpp
// del main.i && cls && icl -P -std=c++14 -Wall -Werror -w3 main.cpp -o main.i

/* Main */
int main(int, char*[]) /* noexcept */ {
  #define f(x) [x]
  #define g(x) subapply(f, default, apply_subtract, x, y, z)

  std::puts(apply(f, default, default));
  std::puts(apply(f, default, apply_add));
  std::puts(apply(f, default, default,   A));
  std::puts(apply(f, default, apply_add, A));
  std::puts(apply(f, default, default,   A, B));
  std::puts(apply(f, default, apply_add, A, B));
  std::puts(apply(f, default, default,   A, B, C));
  std::puts(apply(f, default, apply_add, A, B, C));
  BRUH
  std::puts(apply(g, default, default));
  std::puts(apply(g, default, apply_add));
  std::puts(apply(g, default, default,   A));
  std::puts(apply(g, default, apply_add, A));
  std::puts(apply(g, default, default,   A, B));
  std::puts(apply(g, default, apply_add, A, B));
  std::puts(apply(g, default, default,   A, B, C));
  std::puts(apply(g, default, apply_add, A, B, C));
  std::printf("%1.13s", "Hello, World!");
}
// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
