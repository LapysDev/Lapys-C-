/* Import > C++ Standard Library */
#if CPP_VERSION >= 2011uL
# include <type_traits> // Type Traits
#endif
#if CPP_VERSION >= 2020uL
# include <compare> // Compare
#endif

/* Namespace ->> All traits should be `struct final`, everything else a `union` */
namespace Lapys {
  /* Function > ... */
  #ifdef __cpp_rvalue_references // ->> Preserve object type when forwarding from wrapper functions
    template <typename type> constfunc(true) mustinline type&& forward(type&  object) noexcept { return static_cast<type&&>(object); }
    template <typename type> constfunc(true) mustinline type&& forward(type&& object) noexcept { return static_cast<type&&>(object); }
  #else
    template <typename type> constfunc(true) mustinline type&                forward(type&                object) noexcept { return object; }
    template <typename type> constfunc(true) mustinline type const&          forward(type const&          object) noexcept { return object; }
    template <typename type> constfunc(true) mustinline type const volatile& forward(type const volatile& object) noexcept { return object; }
    template <typename type> constfunc(true) mustinline type volatile&       forward(type volatile&       object) noexcept { return object; }
  #endif

  template <typename type> // ->> No reference-qualifications, just plain type deduction
  constfunc(true) inline type instanceof() noexcept;

  /* ALias > ... */
  #ifdef __cpp_lib_byte // ->> Must alias to a type blessed by the standard
    typedef std::byte byte;
  #else
    typedef unsigned char byte;
  #endif

  /* ... */
  namespace Traits {}
  using namespace Traits;
}

namespace Lapys {
  /* Definition > ... */
  template <std::size_t>
  struct bit; // ->> Just because; User-specified type similar to `byte` for bitwise storage

  /* Namespace > Enumeration > ... */
  namespace Traits {
    // ... ->> For configurable function code paths or generic data structures
    intenum(unsigned char, control_parameter) {
      DYNAMIC     = 0x0000u,
      HEAP        = 0x0000u,

      AUTOMATIC   = 0x0001u,
      BUFFERED    = 0x0002u,
      CLEARED     = 0x0004u,
      EXECUTABLE  = 0x0008u,
      MAXIMUM     = 0xF000u,
      NON_DYNAMIC = 0x0010u,
      STACK       = 0x0020u,
      VIEWABLE    = 0x0040u
    };
  }

  /* Namespace > Definition > ... */
  namespace Traits {
    #ifdef __cpp_variadic_templates
      template <bool, bool...> struct boolean_and;
      template <bool, bool...> struct boolean_or;
    #else
      template <bool, bool = true, bool = true, bool = true, bool = true, bool = true, bool = true, bool = true> struct boolean_and;
      template <bool, bool = true, bool = true, bool = true, bool = true, bool = true, bool = true, bool = true> struct boolean_or;
    #endif

    struct overloaded; // ->> Callable construct for explicit function overloading
  }
}

namespace Lapys {
  namespace Traits {
    #ifdef __cpp_variadic_templates
      template <typename... types>
      overloaded overload(types&&... functions) noexcept {}
    #else
      template <typename type1>                                                                                                                 overloaded overload(type1 nodecay function1)                                                                                                                                                                                noexcept {}
      template <typename type1, typename type2>                                                                                                 overloaded overload(type1 nodecay function1, type2 nodecay function2)                                                                                                                                                       noexcept {}
      template <typename type1, typename type2, typename type3>                                                                                 overloaded overload(type1 nodecay function1, type2 nodecay function2, type3 nodecay function3)                                                                                                                              noexcept {}
      template <typename type1, typename type2, typename type3, typename type4>                                                                 overloaded overload(type1 nodecay function1, type2 nodecay function2, type3 nodecay function3, type4 nodecay function4)                                                                                                     noexcept {}
      template <typename type1, typename type2, typename type3, typename type4, typename type5>                                                 overloaded overload(type1 nodecay function1, type2 nodecay function2, type3 nodecay function3, type4 nodecay function4, type5 nodecay function5)                                                                            noexcept {}
      template <typename type1, typename type2, typename type3, typename type4, typename type5, typename type6>                                 overloaded overload(type1 nodecay function1, type2 nodecay function2, type3 nodecay function3, type4 nodecay function4, type5 nodecay function5, type6 nodecay function6)                                                   noexcept {}
      template <typename type1, typename type2, typename type3, typename type4, typename type5, typename type6, typename type7>                 overloaded overload(type1 nodecay function1, type2 nodecay function2, type3 nodecay function3, type4 nodecay function4, type5 nodecay function5, type6 nodecay function6, type7 nodecay function7)                          noexcept {}
      template <typename type1, typename type2, typename type3, typename type4, typename type5, typename type6, typename type7, typename type8> overloaded overload(type1 nodecay function1, type2 nodecay function2, type3 nodecay function3, type4 nodecay function4, type5 nodecay function5, type6 nodecay function6, type7 nodecay function7, type8 nodecay function8) noexcept {}
    #endif
  }
}
