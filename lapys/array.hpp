/* ... */
namespace Lapys {
  template <typename base, std::size_t = DYNAMIC, class = Memory::HeapAllocator<base> >
  class Array;
}

namespace Lapys {
  namespace {
    template <typename = void, class = void_t, bool = false, bool = false>
    class ArrayLayout {};
      template <typename base, class allocator_t, bool emptiness>
      class ArrayLayout<base, allocator_t, emptiness, false> {
        template <typename, std::size_t, class>
        friend class Array;

        private:
          union { base *begin, *value; };
          base *end;
          std::size_t capacity;
          allocator_t allocator;
      };

      template <typename base, class allocator_t, bool emptiness>
      class ArrayLayout<base, allocator_t, emptiness, true> {
        template <typename, std::size_t, class>
        friend class Array;

        private:
          union { base *begin, *value; };
          base *end;
          std::size_t capacity;
          nouniqueaddr allocator_t allocator;
      };
        template <typename base, class allocator_t, bool compactness> class ArrayLayout<base, allocator_t, true, compactness> : private ArrayLayout<base, allocator_t, true, true> {};
        template <typename base, typename type, bool compactness> class ArrayLayout<base, Memory::HeapAllocator<type>, false, compactness> : private ArrayLayout<base, Memory::HeapAllocator<base>, true, true> {};
        template <typename base, typename type, bool compactness> class ArrayLayout<base, Memory::HeapAllocator<type>, true,  compactness> : private ArrayLayout<base, Memory::HeapAllocator<base>, true, true> {};

    template <typename array_t = void_t>
    class ArrayLength {
      friend class array_t;

      private:
        array_t const *const array;

        constfunc(true) inline ArrayLength(array_t const* const array) noexcept :
          array(array)
        {}

      public:
        constfunc(true) std::size_t const* operator &() const noexcept discard;
        constfunc(true) inline operator std::size_t() const noexcept = 0;
    };
      template <>
      class ArrayLength<void_t> {
        private:
          constfunc(true) inline ArrayLength(void const* const) noexcept {}
      };
  }

  // : [Dynamic Array]
  template <typename base, class allocator_t>
  class Array<base, DYNAMIC, allocator_t> : private ArrayLayout<base, typename remove_qualifiers<allocator_t>::type, is_empty<allocator_t>::value> {
    public:
      class Length final : ArrayLength<Array> {
        constfunc(true) inline Length(Array const* const array) noexcept : ArrayLength<Array>::ArrayLength(array) {}
        constfunc(true) inline operator std::size_t() const noexcept { return array -> end - array -> begin; }
      } length;
  };

  // : [View Array]
  template <typename base, class allocator_t>
  class Array<base, VIEW, allocator_t> : private ArrayLayout<> {
    private:
      base *value;

    public:
      nouniqueaddr class Length final : ArrayLength<> {
        constfunc(true) inline Length(Array const* const array) noexcept : ArrayLength<>::ArrayLength(array) {}
        constfunc(true) inline operator std::size_t() const noexcept discard;
      } length;
  };

  berries.length

  // : [Static Array]
  template <typename base, std::size_t length, class>
  class Array : private ArrayLayout<> {
    private:
      union {
        base begin[length];
        base value[length];
      };
      base *end;

    public:
      class Length final : ArrayLength<Array> {
        constfunc(true) inline Length(Array const* const array) noexcept : ArrayLength<Array>::ArrayLength(array) {}
        constfunc(true) inline operator std::size_t() const noexcept { return array -> end - array -> begin; }
      } length;
  };
}
