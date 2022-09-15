/* Import */
#define LAPYS_PREPROCESSOR true
#include <cstdio>
#include "lapys.hpp"

/* ... */
using namespace Lapys;

/* Main */
int main(int, char*[]) /* noexcept */ {
  char const literal[] = "Hello, World!";
  char const dummy[] = "Lorem ipsum";
  // choose(false, A, B);
  // choose(3u, A, B, C, D);
  std::puts(apply(default, default, default, A));
  std::puts(apply(default, default, apply_comma, A));
  std::puts(apply(default, default, default, A, B));
  std::puts(apply(default, default, apply_group_begin, A, B));
  std::printf("%1.13s", "Hello, World!");
  // #define subapply(function, condition, separator, ...) apply__begin empty()(function, condition, separator, __VA_ARGS__)
  // #define function(count) [subapply(stringify, default, default, arity(count))]
  // std::puts(apply(function, default, default, arity(3u)));
}
// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
