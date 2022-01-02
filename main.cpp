/* Import */
#include "lapys.hpp"

/* ... */
using namespace Lapys;

/* Main */
int main() {
  std::printf("[int,        int       ]: %4.5s" "\r\n", Lapys::can_operate<Lapys::assign_add, int,        int>       ::value ? "true" : "false");
  std::printf("[int,        int&      ]: %4.5s" "\r\n", Lapys::can_operate<Lapys::assign_add, int,        int&>      ::value ? "true" : "false");
  std::printf("[int,        int const&]: %4.5s" "\r\n", Lapys::can_operate<Lapys::assign_add, int,        int const&>::value ? "true" : "false");
  std::printf("[int,        int&&     ]: %4.5s" "\r\n", Lapys::can_operate<Lapys::assign_add, int,        int&&>     ::value ? "true" : "false");
  std::puts("");

  std::printf("[int&,       int       ]: %4.5s" "\r\n", Lapys::can_operate<Lapys::assign_add, int&,       int>       ::value ? "true" : "false");
  std::printf("[int&,       int&      ]: %4.5s" "\r\n", Lapys::can_operate<Lapys::assign_add, int&,       int&>      ::value ? "true" : "false");
  std::printf("[int&,       int const&]: %4.5s" "\r\n", Lapys::can_operate<Lapys::assign_add, int&,       int const&>::value ? "true" : "false");
  std::printf("[int&,       int&&     ]: %4.5s" "\r\n", Lapys::can_operate<Lapys::assign_add, int&,       int&&>     ::value ? "true" : "false");
  std::puts("");

  std::printf("[int const&, int       ]: %4.5s" "\r\n", Lapys::can_operate<Lapys::assign_add, int const&, int>       ::value ? "true" : "false");
  std::printf("[int const&, int&      ]: %4.5s" "\r\n", Lapys::can_operate<Lapys::assign_add, int const&, int&>      ::value ? "true" : "false");
  std::printf("[int const&, int const&]: %4.5s" "\r\n", Lapys::can_operate<Lapys::assign_add, int const&, int const&>::value ? "true" : "false");
  std::printf("[int const&, int&&     ]: %4.5s" "\r\n", Lapys::can_operate<Lapys::assign_add, int const&, int&&>     ::value ? "true" : "false");
  std::puts("");

  std::printf("[int&&,      int       ]: %4.5s" "\r\n", Lapys::can_operate<Lapys::assign_add, int&&,      int>       ::value ? "true" : "false");
  std::printf("[int&&,      int&      ]: %4.5s" "\r\n", Lapys::can_operate<Lapys::assign_add, int&&,      int&>      ::value ? "true" : "false");
  std::printf("[int&&,      int const&]: %4.5s" "\r\n", Lapys::can_operate<Lapys::assign_add, int&&,      int const&>::value ? "true" : "false");
  std::printf("[int&&,      int&&     ]: %4.5s" "\r\n", Lapys::can_operate<Lapys::assign_add, int&&,      int&&>     ::value ? "true" : "false");
  std::puts("");
}
// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }

/* ... */
// #define apply(function, count) stall(apply_parse(function, count))
// # define apply_parse(function, count) concatenate(apply_, count) empty() (function)
// # define apply_1(function) function(1)
// # define apply_2(function) function(1) function(2)
// # define apply_3(function) function(1) function(2) function(3)
// #define concatenate(argumentA, argumentB) argumentA ## argumentB
// #define empty()
// #define stringify(argument) #argument
// #define subapply apply_parse empty()

// #define stall(...) stall_12(__VA_ARGS__)
// # define stall_1(...)  __VA_ARGS__
// # define stall_2(...)  stall_1(__VA_ARGS__)
// # define stall_3(...)  stall_2(__VA_ARGS__)
// # define stall_4(...)  stall_3(__VA_ARGS__)
// # define stall_5(...)  stall_4(__VA_ARGS__)
// # define stall_6(...)  stall_5(__VA_ARGS__)
// # define stall_7(...)  stall_6(__VA_ARGS__)
// # define stall_8(...)  stall_7(__VA_ARGS__)
// # define stall_9(...)  stall_8(__VA_ARGS__)
// # define stall_10(...) stall_9(__VA_ARGS__)
// # define stall_11(...) stall_10(__VA_ARGS__)
// # define stall_12(...) stall_11(__VA_ARGS__)

// // ...
// #include <cstdio>
// #define make_pattern(count) subapply(stringify, count)

// int main() {
//   std::puts(apply(stringify, 3));
//   std::puts(apply(make_pattern, 3));
// }
