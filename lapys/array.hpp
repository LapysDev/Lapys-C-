/* ... */
namespace Lapys {
  template <typename base, std::size_t = DYNAMIC, class = Memory::HeapAllocator<base> >
  class Array;
}

namespace Lapys {
  // : [Static Array]
  template <typename base, std::size_t length, class>
  class Array {
    public:
      base value[length];

    private:
      base *end;

    // ...
    public:
      constfunc(true) Array() noexcept :
        value(), end()
      {}

      template <std::size_t capacity>
      Array(typename conditional<capacity <= length, base>::type const volatile (&)[capacity]) noexcept :
        value(), end()
      {}

      template <std::size_t capacity>
      Array(typename conditional<(capacity > length), base>::type const volatile (&)[capacity]) noexcept :
        value(), end()
      {}
  };

  // : [Dynamic Array]
  template <typename base, class allocator_t>
  class Array<base, DYNAMIC, allocator_t> {
    protected:
      union { base *begin, *value; };

    private:
      base *end;
      std::size_t capacity;

      allocator_t allocator;

    // ...
    public:
      constfunc(true) Array() noexcept {}

      template <std::size_t capacity>
      Array(base const volatile (&)[capacity]) noexcept {}
  };

  /* ... */
  // struct lookup { unsigned char const reallocate; };
  // template <class object> struct member_name_lookup : public object, public lookup {};

  // template <class object, typename = typename std::integral_constant<std::size_t, 0u>::value_type, bool derivable = false == (std::is_final<object>::value || std::is_union<object>::value)> union has_reallocate { static bool const value = false == derivable; };
  // template <class object> union has_reallocate<object, typename std::integral_constant<std::size_t, sizeof(member_name_lookup<object>::reallocate)>::value_type, false> { static bool const value = false; };
  // template <class object> union has_reallocate<object, typeof(sizeof(&object::reallocate)), true> { static bool const value = true; };

  // ...
  // struct lenient_allocator {};
  // struct strict_allocator { void reallocate() {} };

  // /* Main */
  // int main() {
  //   std::printf("[lenient]: %4.5s" "\r\n", has_reallocate<lenient_allocator>::value ? "true" : "false");
  //   std::printf("[strict] : %4.5s" "\r\n", has_reallocate<strict_allocator >::value ? "true" : "false");
  // }
}

