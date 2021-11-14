/* ... */
namespace Lapys {
  template <typename base = char, std::size_t = LAPYS_BUILTIN_MAX_SIZE, class = Memory::HeapAllocator<base> >
  class String;
}

namespace Lapys {
  template <typename, std::size_t, class>
  class String {};
}
