/* Import */
#include "lapys.hpp"
#include <csignal>

/* ... */
using namespace Lapys;

/* Main */
int main() {
  struct program { static void stop(int const) { std::puts("\r\n" "segfaulted..."); std::exit(EXIT_SUCCESS); } };
  std::signal(SIGSEGV, &program::stop);

  // // ...
  // unsigned count;
  // unsigned *integers;

  // std::puts("[allocating]");
  // count = 3u; integers = Memory::allocateHeap(Lapys::ZERO, count * sizeof(unsigned));
  // std::printf("[allocated]: %p" "\r\n", static_cast<void*>(integers));
  // if (NULL != integers) {
  //   for (unsigned *integer = integers + count; integer-- != integers; )
  //   std::printf("  " "[... #%u]: %u" "\r\n", static_cast<unsigned>(integer - integers), *new (integer) unsigned(integer - integers));
  // }

  // std::puts("[re-allocating]");
  // count = 7u; integers = Memory::reallocateHeap(Lapys::ZERO, integers, count * sizeof(unsigned));
  // std::printf("[re-allocated]: %p" "\r\n", static_cast<void*>(integers));
  // if (NULL != integers) {
  //   std::printf("%s", "  " "[...]: ");
  //     for (Lapys::byte *byte = static_cast<Lapys::byte*>(static_cast<void*>(integers + count)); byte-- != static_cast<Lapys::byte*>(static_cast<void*>(integers + 2)); )
  //     std::printf("0x%c%c ", "0123456789ABCDEF"[+(*byte >> 4u) % 16u], "0123456789ABCDEF"[+*byte % 16u]);
  //   std::puts("");

  //   for (unsigned *integer = integers + count; integer-- != integers + 2; )
  //   std::printf("  " "[... #%u]: %u" "\r\n", static_cast<unsigned>(integer - integers), *new (integer) unsigned(integer - integers));

  //   for (unsigned *integer = integers + 3; integer-- != integers; )
  //   std::printf("  " "[... #%u]: %u" "\r\n", static_cast<unsigned>(integer - integers), *Lapys::launder(integer));
  // }

  // std::puts("[releasing]");
  // std::printf("[released]: %s" "\r\n", Memory::releaseHeap(integers) ? "true" : "false");
}
// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
