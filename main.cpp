/* Import */
#include "lapys.hpp"
#include <csignal>

/* ... */
using namespace Lapys;

/* Main */
int main() {
  struct program { static void stop(int const) { std::puts("\r\n" "segfaulted..."); std::exit(EXIT_SUCCESS); } };
  std::signal(SIGSEGV, &program::stop);

  // ...
  unsigned count;
  unsigned *integers;

  count = 3u; integers = Memory::allocateHeap(count * sizeof(unsigned));
  std::printf("[allocated]: %p" "\r\n", static_cast<void*>(integers));
  if (NULL != integers) {
    for (unsigned *integer = integers + count; integer-- != integers; )
    std::printf("  " "[... #%u]: %u" "\r\n", static_cast<unsigned>(integer - integers), *new (integer) unsigned(integer - integers));
  }

  count = 7u; integers = Memory::reallocateHeap(integers, count * sizeof(unsigned));
  std::printf("[re-allocated]: %p" "\r\n", static_cast<void*>(integers));
  if (NULL != integers) {
    for (unsigned *integer = integers + count; integer-- != integers + 2; )
    std::printf("  " "[... #%u]: %u" "\r\n", static_cast<unsigned>(integer - integers), *new (integer) unsigned(integer - integers));

    for (unsigned *integer = integers + 3; integer-- != integers; )
    std::printf("  " "[... #%u]: %u" "\r\n", static_cast<unsigned>(integer - integers), *Lapys::launder(integer));
  }

  Memory::releaseHeap(integers);
  std::puts("[released]");
}
// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
