/* ... */
namespace Lapys {
  // : [Static Array]
  template <typename base, std::size_t length = 0u>
  class Array {};

  // : [Dynamic Array]
  template <typename base>
  class Array<base, 0u> {};
}
