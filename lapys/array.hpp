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
  };

  // : [Dynamic Array]
  template <typename base, class allocator>
  class Array<base, DYNAMIC, allocator> {
    private:
      struct lookup {
        unsigned char const reallocate;
      };

      // ...
      union { base *begin, *value; };
      base *end;
      std::size_t capacity;

      allocator<base> allocator;

    public:
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

  /* Main */
  int main() {
    std::printf("[lenient]: %4.5s" "\r\n", has_reallocate<lenient_allocator>::value ? "true" : "false");
    std::printf("[strict] : %4.5s" "\r\n", has_reallocate<strict_allocator >::value ? "true" : "false");
  }
}

