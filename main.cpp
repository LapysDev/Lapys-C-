/* Import */
#define LAPYS_PREPROCESSOR true
#include <cstdio>
#include "lapys.hpp"

/* ... */
using namespace Lapys;

#define codegen(argument) void function<argument>(apply(subcodegen, default, apply_comma, arity(argument)));
# define subcodegen(argument) int argument_ ## argument

apply(codegen, default, default, arity(3u))

/* Main */
int main(int, char*[]) /* noexcept */ {
  // std::puts(apply(default, default, default));
  // std::puts(apply(default, default, default, A));
  // std::puts(apply(default, default, apply_comma, A));
  // std::puts(apply(default, default, default, A, B));
  // std::puts(apply(default, default, apply_comma, A, B));
  std::printf("%1.13s", "Hello, World!");
}
// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
