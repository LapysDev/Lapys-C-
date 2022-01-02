/* ... */
namespace Lapys {
  template <typename base, std::size_t = DYNAMIC, class = Memory::HeapAllocator<base> >
  class Array;
    template <typename base = void, class allocator_t = void_t, bool compactness = false>
    class ArrayLayout {
      template <typename, std::size_t, class>
      friend class Array;

      private:
        union { base *begin, *value; };
        base *end;
        std::size_t capacity;
        allocator_t const allocator;

        // ...
        constfunc(true) inline ArrayLayout(base const begin[], base const end[], std::size_t const capacity, allocator_t const& allocator) noexcept :
          begin(begin), end(end), capacity(capacity), allocator(allocator)
        {}
    };

    template <typename base, class allocator_t>
    class ArrayLayout<base, allocator_t, true> {
      template <typename, std::size_t, class>
      friend class Array;

      private:
        union { base *begin, *value; };
        base *end;
        std::size_t capacity;
        nouniqueaddr allocator_t const allocator;

        constfunc(true) inline ArrayLayout(base const begin[], base const end[], std::size_t const capacity, allocator_t const& allocator) noexcept :
          begin(begin), end(end), capacity(capacity), allocator(allocator)
        {}
    };

    template <>
    class ArrayLayout<void, void_t, false> {
      template <typename, std::size_t, class>
      friend class Array;
    };
}

namespace Lapys {
  /* Class > ... */
  // : [Dynamic Array]
  template <typename base, class allocator_t>
  class Array<base, DYNAMIC, allocator_t> final : private ArrayLayout<base, allocator_t, is_empty<allocator_t>::value || Memory::Traits::is_heap_allocator<allocator_t>::value> {
    public:
      class Length final {
        friend class Array;

        private:
          Array const *const array;
          constfunc(true) inline Length(Array const* const array) noexcept : array(array) {}

        public:
          constfunc(true) std::size_t const* operator &() const noexcept discard;
          constfunc(true) inline operator std::size_t() const noexcept { return array -> end - array -> begin; }
      } const length;

      // ...
      constfunc(true) Array() exceptspec(exceptof(allocator_t())) :
        ArrayLayout<base, allocator_t, is_empty<allocator_t>::value || Memory::Traits::is_heap_allocator<allocator_t>::value>::ArrayLayout(NULL, NULL, 0u, allocator_t()),
        length(this)
      {}

      template <typename type, std::size_t length>
      Array(typename conditional<is_same<base, typename remove_qualifiers<type>::type>::value, type>::type (&array)[length]) exceptspec(exceptof(allocator_t()) && exceptof(instanceof<allocator_t>().allocate(instanceof<std::size_t>()))) :
        ArrayLayout<base, allocator_t, is_empty<allocator_t>::value || Memory::Traits::is_heap_allocator<allocator_t>::value>::ArrayLayout(NULL, NULL, length * sizeof(base), allocator_t()),
        length(this)
      {
        this -> begin = this -> allocator.allocate(this -> capacity);
        this -> end   = this -> begin + this -> capacity;

        for (type *iterator = array; iterator != array + length; ++iterator)
        new (const_cast<typename remove_qualifiers<base>::type*>(this -> begin++)) base(*iterator);

        this -> begin -= length;
      }

      template <typename type>
      Array(typename conditional<is_same<base, typename remove_qualifiers<type>::type>::value, type>::type array[], std::size_t const length) exceptspec(exceptof(allocator_t()) && exceptof(instanceof<allocator_t>().allocate(instanceof<std::size_t>()))) :
        ArrayLayout<base, allocator_t, is_empty<allocator_t>::value || Memory::Traits::is_heap_allocator<allocator_t>::value>::ArrayLayout(NULL, NULL, length * sizeof(base), allocator_t()),
        length(this)
      {
        this -> begin = this -> allocator.allocate(this -> capacity);
        this -> end   = this -> begin + this -> capacity;

        for (type *iterator = array, *const end = array + length; iterator != end; ++iterator)
        new (const_cast<typename remove_qualifiers<base>::type*>(this -> begin++)) base(*iterator);

        this -> begin -= length;
      }
  };

  // : [View Array]
  template <typename base, class allocator_t>
  class Array<base, VIEW, allocator_t> final : private ArrayLayout<> {
    private:
      base *value;

    public:
      class Length final {
        friend class Array;

        private:
          constfunc(true) inline Length(Array const* const) noexcept {}

        public:
          constfunc(true) std::size_t const* operator &() const noexcept discard;
          constfunc(true) operator std::size_t() const noexcept discard;
      };

      #ifdef __cpp_constexpr
        nouniqueaddr constexpr Length const length = Length(NULL);
      #else
        nouniqueaddr Length const length;
      #endif

      // ...
      constfunc(true) Array() noexcept :
        ArrayLayout<>::ArrayLayout(),
        value(NULL), length(this)
      {}

      constfunc(true) Array(base const volatile array[], std::size_t const = 0u) noexcept :
        ArrayLayout<>::ArrayLayout(),
        value(array), length(this)
      {}
  };

  // : [Static Array]
  template <typename base, std::size_t capacity, class>
  class Array final : private ArrayLayout<> {
    private:
      union {
        base begin[capacity];
        base value[capacity];
      };
      base *end;

    public:
      class Length final {
        friend class Array;

        private:
          Array const *const array;
          constfunc(true) inline Length(Array const* const array) noexcept : array(array) {}

        public:
          constfunc(true) std::size_t const* operator &() const noexcept discard;
          constfunc(true) inline operator std::size_t() const noexcept { return array -> end - array -> begin; }
      } const length;

      // ...
      constfunc(true) Array() noexcept :
        ArrayLayout<>::ArrayLayout(),
        begin(), end(this -> begin), length(this)
      {}

      #if defined(__cpp_aggregate_paren_init) && defined(__cpp_delegating_constructors) && defined(__cpp_variadic_templates)
        template <std::size_t length>
        constexpr Array(typename conditional<(capacity >= length), base>::type const volatile (&array)[length]) noexcept :
          ArrayLayout<>::ArrayLayout(),
          begin{}, end{this -> begin + length}, length{this}
        {}
      #else
        template <typename type, std::size_t length>
        Array(typename conditional<(capacity >= length) && is_same<base, typename remove_qualifiers<type>::type>::value, type>::type (&array)[length]) noexcept :
          ArrayLayout<>::ArrayLayout(),
          begin(), end(this -> begin + length), length(this)
        {
          typename remove_qualifiers<base>::type *value = const_cast<typename remove_qualifiers<base>::type*>(this -> begin);

          for (type *iterator = array; iterator != array + length; ++iterator)
          *(value++) = *iterator;
        }
      #endif
  };
}
