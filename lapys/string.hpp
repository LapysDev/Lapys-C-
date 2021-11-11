/* ... */
namespace Lapys {
  template <typename base = char, std::size_t = LAPYS_BUILTIN_MAX_SIZE, class = Memory::HeapAllocator<base> >
  class String;
}

namespace Lapys {
  namespace {
    // : [Short-String Optimized]
    template <typename base, std::size_t size, class allocator_t>
    class CharacterArray : private Array<base, size, allocator_t> {
      protected:
        base *value;
        bool fixed;

        // ...
        constfunc(true) inline CharacterArray(dummy_t const) noexcept {}

        // ...
        constfunc(true) inline base*& getDynamicBuffer() const noexcept        { return const_cast<base*&>(this -> CharacterArray<base, size, allocator_t>::value); }
        constfunc(true) inline base (&getFixedBuffer  () const noexcept)[size] { return const_cast<base (&)[size]>(this -> Array<base, size, allocator_t>::value); }

        constfunc(true) inline bool isFixed() const noexcept { return this -> fixed; }
    };

    // : [...]
    template <typename base, class allocator_t>
    class CharacterArray<base, DYNAMIC, allocator_t> : private Array<base, DYNAMIC, allocator_t> {
      protected:
        constfunc(true) inline CharacterArray(dummy_t const) noexcept {}

        // ...
        constfunc(true) inline base*&       getDynamicBuffer() const noexcept { return const_cast<base*&>(this -> value); }
        constfunc(true) inline base* const& getFixedBuffer  () const noexcept { return static_cast<base* const&>(NULL); }

        constfunc(true) inline bool isFixed() const noexcept { return false; }
    };
  }

  template <typename base, std::size_t size, class allocator_t>
  class String : private CharacterArray<base, size, allocator_t> {
    public:
      template <std::size_t capacity>
      constfunc(true) String(typename conditional<capacity <= size, base>::type const volatile (&)[capacity]) noexcept :
        CharacterArray<base, size, allocator_t>(dummy_t())
      {}

      template <std::size_t capacity>
      String(typename conditional<(capacity > size), base>::type const volatile (&)[capacity]) noexcept :
        CharacterArray<base, size, allocator_t>(dummy_t())
      {}

      template <typename type>
      String(type const) noexcept :
        CharacterArray<base, size, allocator_t>(typename conditional<is_pointer<type>::value, dummy_t>::type())
      {}
  };
}
