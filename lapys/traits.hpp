#ifndef LAPYS_MODULE_TRAITS
# define LAPYS_MODULE_TRAITS
  /* Import */
  // : [...]
  #include "extensions.hpp"

  // : [C++ Standard Library]
  #if CPP_VERSION >= 2011uL
  # include <type_traits> // Type Traits
  #endif

  #if defined(__cpp_impl_three_way_comparison) && defined(__cpp_lib_three_way_comparison)
  # if __cpp_impl_three_way_comparison >= 201907L && __cpp_lib_three_way_comparison >= 201907L
  #   include <compare> // Compare
  # endif
  #endif

  /* Namespace ->> All traits should be `struct final`, everything else a `union` */
  namespace Lapys {
    /* Function > ... */
    template <typename type> // ->> No reference-qualifications, just plain type deduction
    constfunc(true) type instanceof() noexcept;

    #ifdef __cpp_rvalue_references // ->> Prevent redundant copying when forwarding from wrapper functions
      template <typename type> constfunc(true) mustinline type&& (pass)(type&  object) noexcept { return static_cast<type&&>(object); }
      template <typename type> constfunc(true) mustinline type&& (pass)(type&& object) noexcept { return static_cast<type&&>(object); }
    #else
      template <typename type> constfunc(true) mustinline type&                (pass)(type&                object) noexcept { return object; }
      template <typename type> constfunc(true) mustinline type const&          (pass)(type const&          object) noexcept { return object; }
      template <typename type> constfunc(true) mustinline type const volatile& (pass)(type const volatile& object) noexcept { return object; }
      template <typename type> constfunc(true) mustinline type volatile&       (pass)(type volatile&       object) noexcept { return object; }
    #endif

    /* ALias > ... */
    #ifdef __cpp_lib_byte // ->> Must alias to a byte type blessed by the standard
      typedef std::byte byte;

      /* ... ->> cannot override standard-defined operator overloads */
      constfunc(true) mustinline std::byte operator +(std::byte const byte) noexcept { return byte; }
      constfunc(true) mustinline std::byte operator -(std::byte const byte) noexcept { return static_cast<std::byte>(-std::to_integer<unsigned char>(byte)); }
      constfunc(true) mustinline std::byte operator !(std::byte const byte) noexcept { return static_cast<std::byte>(!std::to_integer<unsigned char>(byte)); }

      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          +=  instanceof<type nodecay>()) operator += (std::byte&          byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char&>()          +=  instanceof<type nodecay>())) { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          +=  instanceof<type nodecay>()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          +=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() +=  instanceof<type nodecay>()) operator += (std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() +=  instanceof<type nodecay>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() +=  instanceof<type nodecay>()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() +=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          -=  instanceof<type nodecay>()) operator -= (std::byte&          byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char&>()          -=  instanceof<type nodecay>())) { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          -=  instanceof<type nodecay>()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          -=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() -=  instanceof<type nodecay>()) operator -= (std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() -=  instanceof<type nodecay>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() -=  instanceof<type nodecay>()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() -=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          *=  instanceof<type nodecay>()) operator *= (std::byte&          byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char&>()          *=  instanceof<type nodecay>())) { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          *=  instanceof<type nodecay>()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          *=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() *=  instanceof<type nodecay>()) operator *= (std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() *=  instanceof<type nodecay>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() *=  instanceof<type nodecay>()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() *=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          /=  instanceof<type nodecay>()) operator /= (std::byte&          byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char&>()          /=  instanceof<type nodecay>())) { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          /=  instanceof<type nodecay>()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          /=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() /=  instanceof<type nodecay>()) operator /= (std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() /=  instanceof<type nodecay>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() /=  instanceof<type nodecay>()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() /=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          %=  instanceof<type nodecay>()) operator %= (std::byte&          byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char&>()          %=  instanceof<type nodecay>())) { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          %=  instanceof<type nodecay>()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          %=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() %=  instanceof<type nodecay>()) operator %= (std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() %=  instanceof<type nodecay>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() %=  instanceof<type nodecay>()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() %=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() &=  instanceof<type nodecay>()) operator &= (std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() &=  instanceof<type nodecay>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() &=  instanceof<type nodecay>()) evaluation = (value &=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() &=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() |=  instanceof<type nodecay>()) operator |= (std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() |=  instanceof<type nodecay>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() |=  instanceof<type nodecay>()) evaluation = (value |=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() |=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type nodecay>()) operator ^= (std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() ^=  instanceof<type nodecay>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type nodecay>()) evaluation = (value ^=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() <<= instanceof<type nodecay>()) operator <<=(std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() <<= instanceof<type nodecay>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() <<= instanceof<type nodecay>()) evaluation = (value <<= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() <<= instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() >>= instanceof<type nodecay>()) operator >>=(std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() >>= instanceof<type nodecay>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() >>= instanceof<type nodecay>()) evaluation = (value >>= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() >>= instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) == instanceof<type nodecay>()) operator ==(std::byte const byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) == instanceof<type nodecay>())) { return std::to_integer<unsigned char>(byte) == pass<type>(object); }
      template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) != instanceof<type nodecay>()) operator !=(std::byte const byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) != instanceof<type nodecay>())) { return std::to_integer<unsigned char>(byte) != pass<type>(object); }
      template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) <  instanceof<type nodecay>()) operator < (std::byte const byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <  instanceof<type nodecay>())) { return std::to_integer<unsigned char>(byte) <  pass<type>(object); }
      template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) >  instanceof<type nodecay>()) operator > (std::byte const byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) >  instanceof<type nodecay>())) { return std::to_integer<unsigned char>(byte) >  pass<type>(object); }
      template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) <= instanceof<type nodecay>()) operator <=(std::byte const byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <= instanceof<type nodecay>())) { return std::to_integer<unsigned char>(byte) <= pass<type>(object); }
      template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) >= instanceof<type nodecay>()) operator >=(std::byte const byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) >= instanceof<type nodecay>())) { return std::to_integer<unsigned char>(byte) >= pass<type>(object); }

      #if defined(__cpp_impl_three_way_comparison) || defined(__cpp_lib_three_way_comparison)
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type nodecay>()) operator <=>(std::byte const byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type nodecay>())) { return std::to_integer<unsigned char>(byte) <=> pass<type>(object); }
      #endif

      #if CPP_VERSION < 2011uL
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          +=  instanceof<type const volatile&>()) operator += (std::byte&          byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          +=  instanceof<type const volatile&>())) { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          +=  instanceof<type const volatile&>()) evaluation = (value +=  object); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          +=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() +=  instanceof<type const volatile&>()) operator += (std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() +=  instanceof<type const volatile&>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() +=  instanceof<type const volatile&>()) evaluation = (value +=  object); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() +=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          -=  instanceof<type const volatile&>()) operator -= (std::byte&          byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          -=  instanceof<type const volatile&>())) { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          -=  instanceof<type const volatile&>()) evaluation = (value -=  object); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          -=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() -=  instanceof<type const volatile&>()) operator -= (std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() -=  instanceof<type const volatile&>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() -=  instanceof<type const volatile&>()) evaluation = (value -=  object); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() -=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          *=  instanceof<type const volatile&>()) operator *= (std::byte&          byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          *=  instanceof<type const volatile&>())) { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          *=  instanceof<type const volatile&>()) evaluation = (value *=  object); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          *=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() *=  instanceof<type const volatile&>()) operator *= (std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() *=  instanceof<type const volatile&>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() *=  instanceof<type const volatile&>()) evaluation = (value *=  object); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() *=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          /=  instanceof<type const volatile&>()) operator /= (std::byte&          byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          /=  instanceof<type const volatile&>())) { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          /=  instanceof<type const volatile&>()) evaluation = (value /=  object); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          /=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() /=  instanceof<type const volatile&>()) operator /= (std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() /=  instanceof<type const volatile&>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() /=  instanceof<type const volatile&>()) evaluation = (value /=  object); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() /=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          %=  instanceof<type const volatile&>()) operator %= (std::byte&          byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          %=  instanceof<type const volatile&>())) { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          %=  instanceof<type const volatile&>()) evaluation = (value %=  object); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          %=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() %=  instanceof<type const volatile&>()) operator %= (std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() %=  instanceof<type const volatile&>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() %=  instanceof<type const volatile&>()) evaluation = (value %=  object); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() %=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() &=  instanceof<type const volatile&>()) operator &= (std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() &=  instanceof<type const volatile&>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() &=  instanceof<type const volatile&>()) evaluation = (value &=  object); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() &=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() |=  instanceof<type const volatile&>()) operator |= (std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() |=  instanceof<type const volatile&>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() |=  instanceof<type const volatile&>()) evaluation = (value |=  object); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() |=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type const volatile&>()) operator ^= (std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() ^=  instanceof<type const volatile&>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type const volatile&>()) evaluation = (value ^=  object); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() <<= instanceof<type const volatile&>()) operator <<=(std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() <<= instanceof<type const volatile&>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() <<= instanceof<type const volatile&>()) evaluation = (value <<= object); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() <<= instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() >>= instanceof<type const volatile&>()) operator >>=(std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() >>= instanceof<type const volatile&>())) { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() >>= instanceof<type const volatile&>()) evaluation = (value >>= object); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() >>= instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) == instanceof<type const volatile&>()) operator ==(std::byte const byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) == instanceof<type const volatile&>())) { return std::to_integer<unsigned char>(byte) == object; }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) != instanceof<type const volatile&>()) operator !=(std::byte const byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) != instanceof<type const volatile&>())) { return std::to_integer<unsigned char>(byte) != object; }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) <  instanceof<type const volatile&>()) operator < (std::byte const byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <  instanceof<type const volatile&>())) { return std::to_integer<unsigned char>(byte) <  object; }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) >  instanceof<type const volatile&>()) operator > (std::byte const byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) >  instanceof<type const volatile&>())) { return std::to_integer<unsigned char>(byte) >  object; }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) <= instanceof<type const volatile&>()) operator <=(std::byte const byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <= instanceof<type const volatile&>())) { return std::to_integer<unsigned char>(byte) <= object; }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) >= instanceof<type const volatile&>()) operator >=(std::byte const byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) >= instanceof<type const volatile&>())) { return std::to_integer<unsigned char>(byte) >= object; }

        #if defined(__cpp_impl_three_way_comparison) || defined(__cpp_lib_three_way_comparison)
          template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type const volatile&>()) operator <=>(std::byte const byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type const volatile&>())) { return std::to_integer<unsigned char>(byte) <=> object; }
        #endif
      #endif
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

    /* Namespace > Enumeration ->> For configurable function code paths or generic data structures */
    namespace Traits {
      intenum(unsigned short, control_parameter) {
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
    }
  }

  // Current Goals
  // • Assert design of Extensions module (`extensions.h`)
  // • Ensure `apply(…)` macro works as intended
  //
  // Design Goals
  // • Auto-diagnose memory allocations with `__FILE__` and `__LINE__` (and optionally `__COUNTER__`) via macros
  // • Beware of `SIZE_MAX` (or such) for bounded ranges, such as the ones for memory allocators
  // • Consider GCC `<stdint.h>` macros `__INT_FAST16_WIDTH__`, `__INT_FAST32_WIDTH__`, `__INT_FAST64_WIDTH__`, `__INT_FAST8_WIDTH__`, `__INT_LEAST16_WIDTH__`, `__INT_LEAST32_WIDTH__`, `__INT_LEAST64_WIDTH__`, `__INT_LEAST8_WIDTH__`, `__INT_WIDTH__`, `__INTMAX_WIDTH__`, `__INTPTR_WIDTH__`, `__LONG_LONG_WIDTH__`, `__LONG_WIDTH__`, `__PTRDIFF_WIDTH__`, `__SCHAR_WIDTH__`, `__SHRT_WIDTH__`, `__SIG_ATOMIC_WIDTH__`, `__SIZE_WIDTH__`, `__WCHAR_WIDTH__`, and `__WINT_WIDTH__`
  // • GCC defines the `<stdint.h>` macros `__INT16_TYPE__`, `__INT32_TYPE__`, `__INT64_TYPE__`, `__INT8_TYPE__`, `__INTPTR_TYPE__`, `__UINT16_TYPE__`, `__UINT32_TYPE__`, `__UINT64_TYPE__`, `__UINT8_TYPE__`, and `__UINTPTR_TYPE__` for optional standard type aliases
  // • Overload literal operators (since C++11) for string methods (`"…"indexOf(…)`, `L"…"hash`, …) and custom string types (`"…"s`, …)
  // • Overload literal operators for unit measurements (`0cm`, `0px`, …)
  // • Prefer `__STDCPP_BFLOAT16_T__`, `__STDCPP_FLOAT16_T__`, `__STDCPP_FLOAT32_T__`, `__STDCPP_FLOAT64_T__`, and `__STDCPP_FLOAT128_T__` (since C++23 from `<stdfloat>`) for fixed-size floating-point arithmetic
  // • Prefer `double_t` and `float_t` (since C++11 from `<cmath>`) for floating-point arithmetic
  // • Prefer `UI::createWindow().append(UI::createButton(), UI::createText())` over `Window{}.append(Button{}, Text{})`
  // • Prefer factory functions & methods over stateful constructors & member functions eg: `System::createFile(…)` evaluates to `class File*` or `NULL`
  // • Standard
  //   ⚬ arbitrary-precision,
  //   ⚬ array,
  //   ⚬ audio,
  //   ⚬ data structure, (linked list, map, set, …)
  //   ⚬ geolocation,
  //   ⚬ 2D/ 3D graphics rendering, (software rendering MUST be guaranteed to be available)
  //   ⚬ events, (keyboard, pointer, touch, vibration, …)
  //   ⚬ font parsing,
  //   ⚬ hardware diagnostics, (battery, gamepad, graphics card, keyboard, stylus, USB, …)
  //   ⚬ HTML parsing,
  //   ⚬ image parsing,
  //   ⚬ internationalization/ locale,
  //   ⚬ math.,
  //   ⚬ memory management, (fixed-size allocations are sorted in buckets, not generalized; `Memory::allocate(…)` evaluates to `class MemoryBuffer` which decays to a pointer — there´s also `Memory::instantiate<>(…)`)
  //   ⚬ multi-threading, (background workers and spawning threads)
  //   ⚬ networking, (TCP/IP, UDP, …)
  //   ⚬ parallelization, (OpenMP or SIMD support?)
  //   ⚬ program-specific features,
  //   ⚬ QR,
  //   ⚬ string, (codepoints, SSO, ropes, UTF-8 default, …)
  //   ⚬ system diagnostics/ query, (clipboard, filesystem, screen, …)
  //   ⚬ tuple,
  //   ⚬ URL/ path,
  //   ⚬ user-interface,
  //   ⚬ variant, and
  //   ⚬ video
  //   APIs
  // • Use `template <auto = []{}>` (since C++20 or `function([]{})` since C++11) for stateful template metaprogramming otherwise use `__COUNTER__` aliased via macros
#endif
