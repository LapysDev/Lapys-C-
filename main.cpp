/* Import */
#include "lapys.hpp"

/* ... */
using namespace Lapys;

// ...
struct integer final {
  unsigned const value;

  // ...
  constexpr inline integer() noexcept : value() {}
  constexpr inline integer(unsigned const value) noexcept : value(value) {}

  // constexpr friend inline bool operator ==(integer const integerA, integer const integerB) noexcept { return integerA.value == integerB.value; }
  // constexpr friend inline integer operator <<(integer const integerA, integer const integerB) noexcept { return integerA.value << integerB.value; }
  // constexpr friend inline integer operator >>(integer const integerA, integer const integerB) noexcept { return integerA.value >> integerB.value; }
};

/* Main */
template struct Lapys::Traits::widthof<integer>;
int main() {
  std::printf("[]: %u" "\r\n", maxof<integer>::value.value);
  // std::printf("[integer]     : %lu" "\r\n", static_cast<unsigned long>(widthof<integer>           ::value));
  // std::printf("[integer, ...]: %lu" "\r\n", static_cast<unsigned long>(widthof<integer, integer{}>::value));
  // std::printf("[integer, 0]  : %lu" "\r\n", static_cast<unsigned long>(widthof<integer, 0u>       ::value));
  // std::printf("[integer, 255]: %lu" "\r\n", static_cast<unsigned long>(widthof<integer, 255u>     ::value));

  // std::printf("widthof  [unsigned, ...]: %lu" "\r\n", static_cast<unsigned long>(widthof<unsigned>     ::value));
  // std::printf("widthof  [unsigned, 0u] : %lu" "\r\n", static_cast<unsigned long>(widthof<unsigned, 0u> ::value));
  // std::printf("widthof  [unsigned, 1u] : %lu" "\r\n", static_cast<unsigned long>(widthof<unsigned, 1u> ::value));
  // std::printf("widthof  [unsigned, 55u]: %lu" "\r\n", static_cast<unsigned long>(widthof<unsigned, 55u>::value));
  // std::printf("widthof  [bit<31u>, ...]: %lu" "\r\n", static_cast<unsigned long>(widthof<bit<31u> >    ::value));
  // std::printf("widthof  [byte, ...]    : %lu" "\r\n", static_cast<unsigned long>(widthof<Lapys::byte>  ::value));
}
// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
