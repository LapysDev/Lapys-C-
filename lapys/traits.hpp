#ifndef LAPYS_MODULE_TRAITS
# define LAPYS_MODULE_TRAITS
  /* Import */
  // : [C++ Standard Library]
  #if CPP_VERSION >= 2011uL
  # include <type_traits> // Type Traits
  #endif
  #if CPP_VERSION >= 2020uL
  # include <compare> // Compare
  #endif

  // : [...]
  #include "extensions.hpp"

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

  // #if CPP_COMPILER != CPP_GCC_COMPILER
  //   __COUNTER__
  //   function([]() {}) always generates a new template instantiate
  //   template <auto = []{}> for C++20 and beyond
  // #else
  // # include <stdint.h>

  //   double_t, float_t
  //   __SIZE_TYPE__
  //   __PTRDIFF_TYPE__
  //   __WCHAR_TYPE__
  //   __WINT_TYPE__
  //   __INTMAX_TYPE__
  //   __UINTMAX_TYPE__
  //   __SIG_ATOMIC_TYPE__
  //   __INT8_TYPE__
  //   __INT16_TYPE__
  //   __INT32_TYPE__
  //   __INT64_TYPE__
  //   __UINT8_TYPE__
  //   __UINT16_TYPE__
  //   __UINT32_TYPE__
  //   __UINT64_TYPE__
  //   __INT_LEAST8_TYPE__
  //   __INT_LEAST16_TYPE__
  //   __INT_LEAST32_TYPE__
  //   __INT_LEAST64_TYPE__
  //   __UINT_LEAST8_TYPE__
  //   __UINT_LEAST16_TYPE__
  //   __UINT_LEAST32_TYPE__
  //   __UINT_LEAST64_TYPE__
  //   __INT_FAST8_TYPE__
  //   __INT_FAST16_TYPE__
  //   __INT_FAST32_TYPE__
  //   __INT_FAST64_TYPE__
  //   __UINT_FAST8_TYPE__
  //   __UINT_FAST16_TYPE__
  //   __UINT_FAST32_TYPE__
  //   __UINT_FAST64_TYPE__
  //   __INTPTR_TYPE__
  //   __UINTPTR_TYPE__

  //   __SCHAR_WIDTH__
  //   __SHRT_WIDTH__
  //   __INT_WIDTH__
  //   __LONG_WIDTH__
  //   __LONG_LONG_WIDTH__
  //   __PTRDIFF_WIDTH__
  //   __SIG_ATOMIC_WIDTH__
  //   __SIZE_WIDTH__
  //   __WCHAR_WIDTH__
  //   __WINT_WIDTH__
  //   __INT_LEAST8_WIDTH__
  //   __INT_LEAST16_WIDTH__
  //   __INT_LEAST32_WIDTH__
  //   __INT_LEAST64_WIDTH__
  //   __INT_FAST8_WIDTH__
  //   __INT_FAST16_WIDTH__
  //   __INT_FAST32_WIDTH__
  //   __INT_FAST64_WIDTH__
  //   __INTPTR_WIDTH__
  //   __INTMAX_WIDTH__
  // #endif
#endif
