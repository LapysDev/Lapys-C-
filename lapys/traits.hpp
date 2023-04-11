#ifndef LAPYS_MODULE_TRAITS
# define LAPYS_MODULE_TRAITS
  /* Guard > ... */
  #define byte       byte
  #define instanceof instanceof
  #define pass       pass
  #define Traits     Traits

  #ifdef as
  # error Lapys C++: Unexpected `as` macro definition
  #endif

  #ifdef byte
  # error Lapys C++: Unexpected `byte` macro definition
  #endif

  #ifdef conditional
  # error Lapys C++: Unexpected `conditional` macro definition
  #endif

  #ifdef instanceof
  # error Lapys C++: Unexpected `instanceof` macro definition
  #endif

  #ifdef Traits
  # error Lapys C++: Awkward. Unexpected `Traits` macro definition
  #endif

  /* Import */
  // : [...]
  #include "extensions.hpp"

  // : [C++ Standard Library]
  #include <climits> // C Limits
  #if CPP_VERSION >= 2011uL
  # include <type_traits> // Type Traits
  #endif

  #if defined(__cpp_impl_three_way_comparison) && defined(__cpp_lib_three_way_comparison)
  # include <compare> // Compare
  #endif

  /* Namespace ->> All concepts/ metafunctions/ traits should be `struct final`, everything else a `union` */
  namespace Lapys {
    /* Function */
    // Instance Of ->> No reference-qualifications, just plain/ simple type deduction
    template <typename type>
    constfunc(true) type (instanceof)() noexcept;

    // Pass ->> Prevent redundant copying (and preserve type qualifications) when forwarding parameters between functions
    #ifdef __cpp_rvalue_references
      template <typename type> constfunc(true) mustinline type&& (pass)(type&  object) noexcept { return static_cast<type&&>(object); }
      template <typename type> constfunc(true) mustinline type&& (pass)(type&& object) noexcept { return static_cast<type&&>(object); }
    #else
      template <typename type> constfunc(true) mustinline type&                (pass)(type&                object) noexcept { return object; }
      template <typename type> constfunc(true) mustinline type const&          (pass)(type const&          object) noexcept { return object; }
      template <typename type> constfunc(true) mustinline type const volatile& (pass)(type const volatile& object) noexcept { return object; }
      template <typename type> constfunc(true) mustinline type volatile&       (pass)(type volatile&       object) noexcept { return object; }
    #endif

    /* ALias */
    // ... ->> Aliases to an (unsigned) byte type blessed by the standard
    #ifndef __cpp_lib_byte
      typedef unsigned char byte;
    #else
      typedef std::byte byte;

      // ... ->> Make `Lapys::byte` types operationally consistent; cannot override standard-defined operator overloads
      constfunc(true) mustinline std::byte operator +(std::byte const byte) noexcept { return byte; }
      constfunc(true) mustinline std::byte operator -(std::byte const byte) noexcept { return static_cast<std::byte>(-std::to_integer<unsigned char>(byte)); }
      constfunc(true) mustinline std::byte operator !(std::byte const byte) noexcept { return static_cast<std::byte>(!std::to_integer<unsigned char>(byte)); }

      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          +=  instanceof<type nodecay>())                    operator += (std::byte&          byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char&>()          +=  instanceof<type nodecay>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          +=  instanceof<type nodecay>()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          +=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() +=  instanceof<type nodecay>())                    operator += (std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() +=  instanceof<type nodecay>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() +=  instanceof<type nodecay>()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() +=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          -=  instanceof<type nodecay>())                    operator -= (std::byte&          byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char&>()          -=  instanceof<type nodecay>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          -=  instanceof<type nodecay>()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          -=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() -=  instanceof<type nodecay>())                    operator -= (std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() -=  instanceof<type nodecay>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() -=  instanceof<type nodecay>()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() -=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          *=  instanceof<type nodecay>())                    operator *= (std::byte&          byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char&>()          *=  instanceof<type nodecay>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          *=  instanceof<type nodecay>()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          *=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() *=  instanceof<type nodecay>())                    operator *= (std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() *=  instanceof<type nodecay>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() *=  instanceof<type nodecay>()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() *=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          /=  instanceof<type nodecay>())                    operator /= (std::byte&          byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char&>()          /=  instanceof<type nodecay>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          /=  instanceof<type nodecay>()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          /=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() /=  instanceof<type nodecay>())                    operator /= (std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() /=  instanceof<type nodecay>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() /=  instanceof<type nodecay>()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() /=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          %=  instanceof<type nodecay>())                    operator %= (std::byte&          byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char&>()          %=  instanceof<type nodecay>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          %=  instanceof<type nodecay>()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          %=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() %=  instanceof<type nodecay>())                    operator %= (std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() %=  instanceof<type nodecay>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() %=  instanceof<type nodecay>()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() %=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() &=  instanceof<type nodecay>())                    operator &= (std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() &=  instanceof<type nodecay>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() &=  instanceof<type nodecay>()) evaluation = (value &=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() &=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() |=  instanceof<type nodecay>())                    operator |= (std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() |=  instanceof<type nodecay>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() |=  instanceof<type nodecay>()) evaluation = (value |=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() |=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type nodecay>())                    operator ^= (std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() ^=  instanceof<type nodecay>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type nodecay>()) evaluation = (value ^=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() <<= instanceof<type nodecay>())                    operator <<=(std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() <<= instanceof<type nodecay>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() <<= instanceof<type nodecay>()) evaluation = (value <<= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() <<= instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() >>= instanceof<type nodecay>())                    operator >>=(std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() >>= instanceof<type nodecay>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() >>= instanceof<type nodecay>()) evaluation = (value >>= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() >>= instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) == instanceof<type nodecay>())) operator == (std::byte const     byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) == instanceof<type nodecay>()))) { return std::to_integer<unsigned char>(byte) == pass<type>(object); }
      template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) != instanceof<type nodecay>())) operator != (std::byte const     byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) != instanceof<type nodecay>()))) { return std::to_integer<unsigned char>(byte) != pass<type>(object); }
      template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) <  instanceof<type nodecay>())) operator <  (std::byte const     byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) <  instanceof<type nodecay>()))) { return std::to_integer<unsigned char>(byte) <  pass<type>(object); }
      template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) >  instanceof<type nodecay>())) operator >  (std::byte const     byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) >  instanceof<type nodecay>()))) { return std::to_integer<unsigned char>(byte) >  pass<type>(object); }
      template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) <= instanceof<type nodecay>())) operator <= (std::byte const     byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) <= instanceof<type nodecay>()))) { return std::to_integer<unsigned char>(byte) <= pass<type>(object); }
      template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) >= instanceof<type nodecay>())) operator >= (std::byte const     byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) >= instanceof<type nodecay>()))) { return std::to_integer<unsigned char>(byte) >= pass<type>(object); }

      #if defined(__cpp_impl_three_way_comparison) || defined(__cpp_lib_three_way_comparison)
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type nodecay>()) operator <=>(std::byte const byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type nodecay>())) { return std::to_integer<unsigned char>(byte) <=> pass<type>(object); }
      #endif

      #if CPP_VERSION < 2011uL // ->> A preview of the cost of over-compensating for not having perfect-forwarding syntax; not abstracted with convenience macros such as `apply(...)` due to possibly unreliable preprocessor speeds
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          +=  instanceof<type               &>())                    operator += (std::byte&          byte, type               & object) exceptspec(exceptof(instanceof<unsigned char&>()          +=  instanceof<type               &>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          +=  instanceof<type               &>()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          +=  instanceof<type               &>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          +=  instanceof<type       volatile&>())                    operator += (std::byte&          byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          +=  instanceof<type       volatile&>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          +=  instanceof<type       volatile&>()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          +=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          +=  instanceof<type const volatile&>())                    operator += (std::byte&          byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          +=  instanceof<type const volatile&>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          +=  instanceof<type const volatile&>()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          +=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() +=  instanceof<type               &>())                    operator += (std::byte volatile& byte, type               & object) exceptspec(exceptof(instanceof<unsigned char volatile&>() +=  instanceof<type               &>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() +=  instanceof<type               &>()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() +=  instanceof<type               &>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() +=  instanceof<type       volatile&>())                    operator += (std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() +=  instanceof<type       volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() +=  instanceof<type       volatile&>()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() +=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() +=  instanceof<type const volatile&>())                    operator += (std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() +=  instanceof<type const volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() +=  instanceof<type const volatile&>()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() +=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          -=  instanceof<type               &>())                    operator -= (std::byte&          byte, type               & object) exceptspec(exceptof(instanceof<unsigned char&>()          -=  instanceof<type               &>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          -=  instanceof<type               &>()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          -=  instanceof<type               &>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          -=  instanceof<type       volatile&>())                    operator -= (std::byte&          byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          -=  instanceof<type       volatile&>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          -=  instanceof<type       volatile&>()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          -=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          -=  instanceof<type const volatile&>())                    operator -= (std::byte&          byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          -=  instanceof<type const volatile&>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          -=  instanceof<type const volatile&>()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          -=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() -=  instanceof<type               &>())                    operator -= (std::byte volatile& byte, type               & object) exceptspec(exceptof(instanceof<unsigned char volatile&>() -=  instanceof<type               &>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() -=  instanceof<type               &>()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() -=  instanceof<type               &>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() -=  instanceof<type       volatile&>())                    operator -= (std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() -=  instanceof<type       volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() -=  instanceof<type       volatile&>()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() -=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() -=  instanceof<type const volatile&>())                    operator -= (std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() -=  instanceof<type const volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() -=  instanceof<type const volatile&>()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() -=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          *=  instanceof<type               &>())                    operator *= (std::byte&          byte, type               & object) exceptspec(exceptof(instanceof<unsigned char&>()          *=  instanceof<type               &>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          *=  instanceof<type               &>()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          *=  instanceof<type               &>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          *=  instanceof<type       volatile&>())                    operator *= (std::byte&          byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          *=  instanceof<type       volatile&>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          *=  instanceof<type       volatile&>()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          *=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          *=  instanceof<type const volatile&>())                    operator *= (std::byte&          byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          *=  instanceof<type const volatile&>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          *=  instanceof<type const volatile&>()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          *=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() *=  instanceof<type               &>())                    operator *= (std::byte volatile& byte, type               & object) exceptspec(exceptof(instanceof<unsigned char volatile&>() *=  instanceof<type               &>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() *=  instanceof<type               &>()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() *=  instanceof<type               &>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() *=  instanceof<type       volatile&>())                    operator *= (std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() *=  instanceof<type       volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() *=  instanceof<type       volatile&>()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() *=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() *=  instanceof<type const volatile&>())                    operator *= (std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() *=  instanceof<type const volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() *=  instanceof<type const volatile&>()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() *=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          /=  instanceof<type               &>())                    operator /= (std::byte&          byte, type               & object) exceptspec(exceptof(instanceof<unsigned char&>()          /=  instanceof<type               &>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          /=  instanceof<type               &>()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          /=  instanceof<type               &>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          /=  instanceof<type       volatile&>())                    operator /= (std::byte&          byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          /=  instanceof<type       volatile&>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          /=  instanceof<type       volatile&>()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          /=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          /=  instanceof<type const volatile&>())                    operator /= (std::byte&          byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          /=  instanceof<type const volatile&>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          /=  instanceof<type const volatile&>()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          /=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() /=  instanceof<type               &>())                    operator /= (std::byte volatile& byte, type               & object) exceptspec(exceptof(instanceof<unsigned char volatile&>() /=  instanceof<type               &>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() /=  instanceof<type               &>()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() /=  instanceof<type               &>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() /=  instanceof<type       volatile&>())                    operator /= (std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() /=  instanceof<type       volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() /=  instanceof<type       volatile&>()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() /=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() /=  instanceof<type const volatile&>())                    operator /= (std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() /=  instanceof<type const volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() /=  instanceof<type const volatile&>()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() /=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          %=  instanceof<type               &>())                    operator %= (std::byte&          byte, type               & object) exceptspec(exceptof(instanceof<unsigned char&>()          %=  instanceof<type               &>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          %=  instanceof<type               &>()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          %=  instanceof<type               &>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          %=  instanceof<type       volatile&>())                    operator %= (std::byte&          byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          %=  instanceof<type       volatile&>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          %=  instanceof<type       volatile&>()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          %=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          %=  instanceof<type const volatile&>())                    operator %= (std::byte&          byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          %=  instanceof<type const volatile&>()))                    { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          %=  instanceof<type const volatile&>()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          %=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() %=  instanceof<type               &>())                    operator %= (std::byte volatile& byte, type               & object) exceptspec(exceptof(instanceof<unsigned char volatile&>() %=  instanceof<type               &>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() %=  instanceof<type               &>()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() %=  instanceof<type               &>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() %=  instanceof<type       volatile&>())                    operator %= (std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() %=  instanceof<type       volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() %=  instanceof<type       volatile&>()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() %=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() %=  instanceof<type const volatile&>())                    operator %= (std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() %=  instanceof<type const volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() %=  instanceof<type const volatile&>()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() %=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() &=  instanceof<type               &>())                    operator &= (std::byte volatile& byte, type               & object) exceptspec(exceptof(instanceof<unsigned char volatile&>() &=  instanceof<type               &>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() &=  instanceof<type               &>()) evaluation = (value &=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() &=  instanceof<type               &>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() &=  instanceof<type       volatile&>())                    operator &= (std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() &=  instanceof<type       volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() &=  instanceof<type       volatile&>()) evaluation = (value &=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() &=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() &=  instanceof<type const volatile&>())                    operator &= (std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() &=  instanceof<type const volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() &=  instanceof<type const volatile&>()) evaluation = (value &=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() &=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() |=  instanceof<type               &>())                    operator |= (std::byte volatile& byte, type               & object) exceptspec(exceptof(instanceof<unsigned char volatile&>() |=  instanceof<type               &>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() |=  instanceof<type               &>()) evaluation = (value |=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() |=  instanceof<type               &>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() |=  instanceof<type       volatile&>())                    operator |= (std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() |=  instanceof<type       volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() |=  instanceof<type       volatile&>()) evaluation = (value |=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() |=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() |=  instanceof<type const volatile&>())                    operator |= (std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() |=  instanceof<type const volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() |=  instanceof<type const volatile&>()) evaluation = (value |=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() |=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type               &>())                    operator ^= (std::byte volatile& byte, type               & object) exceptspec(exceptof(instanceof<unsigned char volatile&>() ^=  instanceof<type               &>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type               &>()) evaluation = (value ^=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type               &>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type       volatile&>())                    operator ^= (std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() ^=  instanceof<type       volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type       volatile&>()) evaluation = (value ^=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type const volatile&>())                    operator ^= (std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() ^=  instanceof<type const volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type const volatile&>()) evaluation = (value ^=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() <<= instanceof<type               &>())                    operator <<=(std::byte volatile& byte, type               & object) exceptspec(exceptof(instanceof<unsigned char volatile&>() <<= instanceof<type               &>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() <<= instanceof<type               &>()) evaluation = (value <<= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() <<= instanceof<type               &>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() <<= instanceof<type       volatile&>())                    operator <<=(std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() <<= instanceof<type       volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() <<= instanceof<type       volatile&>()) evaluation = (value <<= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() <<= instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() <<= instanceof<type const volatile&>())                    operator <<=(std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() <<= instanceof<type const volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() <<= instanceof<type const volatile&>()) evaluation = (value <<= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() <<= instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() >>= instanceof<type               &>())                    operator >>=(std::byte volatile& byte, type               & object) exceptspec(exceptof(instanceof<unsigned char volatile&>() >>= instanceof<type               &>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() >>= instanceof<type               &>()) evaluation = (value >>= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() >>= instanceof<type               &>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() >>= instanceof<type       volatile&>())                    operator >>=(std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() >>= instanceof<type       volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() >>= instanceof<type       volatile&>()) evaluation = (value >>= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() >>= instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() >>= instanceof<type const volatile&>())                    operator >>=(std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() >>= instanceof<type const volatile&>()))                    { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() >>= instanceof<type const volatile&>()) evaluation = (value >>= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() >>= instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) == instanceof<type               &>())) operator == (std::byte const     byte, type               & object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) == instanceof<type               &>()))) { return std::to_integer<unsigned char>(byte) == pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) == instanceof<type       volatile&>())) operator == (std::byte const     byte, type       volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) == instanceof<type       volatile&>()))) { return std::to_integer<unsigned char>(byte) == pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) == instanceof<type const volatile&>())) operator == (std::byte const     byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) == instanceof<type const volatile&>()))) { return std::to_integer<unsigned char>(byte) == pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) != instanceof<type               &>())) operator != (std::byte const     byte, type               & object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) != instanceof<type               &>()))) { return std::to_integer<unsigned char>(byte) != pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) != instanceof<type       volatile&>())) operator != (std::byte const     byte, type       volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) != instanceof<type       volatile&>()))) { return std::to_integer<unsigned char>(byte) != pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) != instanceof<type const volatile&>())) operator != (std::byte const     byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) != instanceof<type const volatile&>()))) { return std::to_integer<unsigned char>(byte) != pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) <  instanceof<type               &>())) operator <  (std::byte const     byte, type               & object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) <  instanceof<type               &>()))) { return std::to_integer<unsigned char>(byte) <  pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) <  instanceof<type       volatile&>())) operator <  (std::byte const     byte, type       volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) <  instanceof<type       volatile&>()))) { return std::to_integer<unsigned char>(byte) <  pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) <  instanceof<type const volatile&>())) operator <  (std::byte const     byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) <  instanceof<type const volatile&>()))) { return std::to_integer<unsigned char>(byte) <  pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) >  instanceof<type               &>())) operator >  (std::byte const     byte, type               & object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) >  instanceof<type               &>()))) { return std::to_integer<unsigned char>(byte) >  pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) >  instanceof<type       volatile&>())) operator >  (std::byte const     byte, type       volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) >  instanceof<type       volatile&>()))) { return std::to_integer<unsigned char>(byte) >  pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) >  instanceof<type const volatile&>())) operator >  (std::byte const     byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) >  instanceof<type const volatile&>()))) { return std::to_integer<unsigned char>(byte) >  pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) <= instanceof<type               &>())) operator <= (std::byte const     byte, type               & object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) <= instanceof<type               &>()))) { return std::to_integer<unsigned char>(byte) <= pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) <= instanceof<type       volatile&>())) operator <= (std::byte const     byte, type       volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) <= instanceof<type       volatile&>()))) { return std::to_integer<unsigned char>(byte) <= pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) <= instanceof<type const volatile&>())) operator <= (std::byte const     byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) <= instanceof<type const volatile&>()))) { return std::to_integer<unsigned char>(byte) <= pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) >= instanceof<type               &>())) operator >= (std::byte const     byte, type               & object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) >= instanceof<type               &>()))) { return std::to_integer<unsigned char>(byte) >= pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) >= instanceof<type       volatile&>())) operator >= (std::byte const     byte, type       volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) >= instanceof<type       volatile&>()))) { return std::to_integer<unsigned char>(byte) >= pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>((instanceof<std::byte>()) >= instanceof<type const volatile&>())) operator >= (std::byte const     byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>((instanceof<std::byte>()) >= instanceof<type const volatile&>()))) { return std::to_integer<unsigned char>(byte) >= pass<type>(object); }

        #if defined(__cpp_impl_three_way_comparison) || defined(__cpp_lib_three_way_comparison)
          template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type               &>()) operator <=>(std::byte const byte, type               & object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type               &>())) { return std::to_integer<unsigned char>(byte) <=> object; }
          template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type       volatile&>()) operator <=>(std::byte const byte, type       volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type       volatile&>())) { return std::to_integer<unsigned char>(byte) <=> object; }
          template <typename type> constfunc(false) mustinline typeof(std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type const volatile&>()) operator <=>(std::byte const byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type const volatile&>())) { return std::to_integer<unsigned char>(byte) <=> object; }
        #endif
      #endif
    #endif

    /* ... */
    namespace Traits {
      /* Alias > ... */
      typedef bool nodecayparam(boolean_false)[false + 1u];
      typedef bool nodecayparam(boolean_true) [true  + 1u];
    }

    using namespace Traits;
  }

  namespace Lapys {
    /* Class */
    // ... ->> Specialization type denoting an empty set of values; See `void` type
    union null;

    /* Namespace > Definition */
    namespace Traits {
      // ... ->> Fundamental conditional/ SFINAE type
      template <bool, typename = null, typename = null>
      struct conditional;

      template <typename baseA, typename baseB>
      struct conditional<false, baseA, baseB> final {
        typedef baseB type;
      };

      template <typename base>
      struct conditional<false, base, null> final {};

      template <typename base>
      struct conditional<false, base, null const> final {};

      template <typename base>
      struct conditional<false, base, null const volatile> final {};

      template <typename base>
      struct conditional<false, base, null volatile> final {};

      template <typename baseA, typename baseB>
      struct conditional<true, baseA, baseB> final {
        typedef baseA type;
      };

      template <typename base>
      struct conditional<true, null, base> final {};

      template <typename base>
      struct conditional<true, null const, base> final {};

      template <typename base>
      struct conditional<true, null const volatile, base> final {};

      template <typename base>
      struct conditional<true, null volatile, base> final {};

      // ... ->> Type equality
      template <typename, typename>
      struct is_same final {
        static bool const value = false;
      };

      template <typename base>
      struct is_same<base, base> final {
        static bool const value = true;
      };
    }

    /* Class */
    // ... ->> Sign integral type
    template <typename base>
    struct signedof final {
      typedef base type;
    };

    template <>
    struct signedof<unsigned char> final {
      typedef signed char type;
    };

    template <>
    struct signedof<unsigned int> final {
      typedef signed int type;
    };

    template <>
    struct signedof<unsigned long> final {
      typedef signed long type;
    };

    #if CPP_VERSION >= 2011uL
      template <>
      struct signedof<unsigned long long> final {
        typedef signed long long type;
      };
    #endif

    #ifdef uint128_t
      template <>
      struct signedof<uint128_t> final {
        #ifdef int128_t
          typedef int128_t type;
        #else
          typedef void type;
        #endif
      };
    #endif

    // ... ->> Unsign integral type
    template <typename base>
    struct unsignedof final {
      typedef base type;
    };

    template <>
    struct unsignedof<signed char> final {
      typedef unsigned char type;
    };

    template <>
    struct unsignedof<signed int> final {
      typedef unsigned int type;
    };

    template <>
    struct unsignedof<signed long> final {
      typedef unsigned long type;
    };

    #if CPP_VERSION >= 2011uL
      template <>
      struct unsignedof<signed long long> final {
        typedef unsigned long long type;
      };
    #endif

    #ifdef int128_t
      template <>
      struct unsignedof<int128_t> final {
        #ifdef uint128_t
          typedef uint128_t type;
        #else
          typedef void type;
        #endif
      };
    #endif

    // ... ->> Collection of fixed-width arithmetic types (some of which may be `void` to denote their unavailability) ->> `double_t` and `float_t` (from `<math.h>`) and other such types may not necessarily feature
    template <std::size_t width>
    struct float_fast_width_t final {
      typedef typename conditional<
        width <= widthof(double()), double, // ->> Assume a `double` is the "fastest"
        typename float_least_width_t<width>::type
      >::type type;
    };

    template <std::size_t width>
    struct float_least_width_t final {
      typedef
        typename conditional<width <= widthof(float      ()), float,
        typename conditional<width <= widthof(double     ()), double,
        typename conditional<width <= widthof(long double()), long double,
        #ifndef float16_t
          void
        #else
          typename conditional<width <= widthof(float16_t()), float16_t,
          #ifndef float32_t
            void
          #else
            typename conditional<width <= widthof(float32_t()), float32_t,
            #ifndef float64_t
              void
            #else
              typename conditional<width <= widthof(float64_t()), float64_t,
              #ifndef float128_t
                void
              #else
                typename conditional<width <= widthof(float128_t()), float128_t, void>::type
              #endif
              >::type
            #endif
            >::type
          #endif
          >::type
        #endif
        >::type>::type>::type>::type
      type;
    };

    template <std::size_t width>
    struct float_width_t final {
      private:
        template <typename decimal, bool = is_same<decimal, void>::value>
        struct valueof final {
          typedef typename conditional<width == widthof(decimal()), decimal, void>::type type;
        };

        template <typename decimal>
        struct valueof<decimal, true> final {
          typedef decimal type;
        };

      public:
        typedef typename valueof<typename float_least_width_t<width>::type>::type type;
    };

    template <std::size_t width>
    struct uint_fast_width_t final {
      typedef
        typename conditional<width <= widthof(unsigned          ()), unsigned, // ->> Assume an `unsigned` word is the "fastest"
        typename conditional<width <= widthof(std::uint_fast8_t ()), std::uint_fast8_t,
        typename conditional<width <= widthof(std::uint_fast16_t()), std::uint_fast16_t,
        typename conditional<width <= widthof(std::uint_fast32_t()), std::uint_fast32_t,
        typename conditional<width <= widthof(std::uint_fast64_t()), std::uint_fast64_t,
        #ifndef uint128_t
          void
        #else
          typename conditional<width <= widthof(uint128_t()), uint128_t, void>::type
        #endif
        >::type>::type>::type>::type>::type
      type;
    };

    template <std::size_t width>
    struct uint_least_width_t final {
      typedef
        typename conditional<width <= widthof(unsigned char ()), unsigned char,
        typename conditional<width <= widthof(unsigned short()), unsigned short,
        typename conditional<width <= widthof(unsigned int  ()), unsigned int,
        typename conditional<width <= widthof(unsigned long ()), unsigned long,
        #if CPP_VERSION < 2011uL
          void
        #else
          typename conditional<width <= widthof(unsigned long long()), unsigned long long,
          #ifndef uint128_t
            void
          #else
            typename conditional<width <= widthof(uint128_t()), uint128_t, void>::type
          #endif
          >::type
        #endif
        >::type>::type>::type>::type
      type;
    };

    template <std::size_t width>
    struct uint_width_t final {
      private:
        template <typename uint, bool = is_same<uint, void>::value>
        struct valueof final {
          typedef typename conditional<width == widthof(uint()), uint, void>::type type;
        };

        template <typename uint>
        struct valueof<uint, true> final {
          typedef uint type;
        };

      public:
        typedef typename valueof<typename uint_least_width_t<width>::type>::type type;
    };

    typedef typename float_fast_width_t<8u>   ::type                   float_fast8_t;
    typedef typename float_fast_width_t<16u>  ::type                   float_fast16_t;
    typedef typename float_fast_width_t<32u>  ::type                   float_fast32_t;
    typedef typename float_fast_width_t<128u> ::type                   float_fast128_t;
    typedef typename float_least_width_t<8u>  ::type                   float_least8_t;
    typedef typename float_least_width_t<16u> ::type                   float_least16_t;
    typedef typename float_least_width_t<32u> ::type                   float_least32_t;
    typedef typename float_least_width_t<128u>::type                   float_least128_t;
    typedef std::uint_fast8_t                                          uint_fast8_t;
    typedef std::uint_fast16_t                                         uint_fast16_t;
    typedef std::uint_fast32_t                                         uint_fast32_t;
    typedef std::uint_fast64_t                                         uint_fast64_t;
    typedef typename uint_fast_width_t <128u> ::type                   uint_fast128_t;
    typedef typename uint_least_width_t<8u>   ::type                   uint_least8_t;
    typedef typename uint_least_width_t<16u>  ::type                   uint_least16_t;
    typedef typename uint_least_width_t<32u>  ::type                   uint_least32_t;
    typedef typename uint_least_width_t<64u>  ::type                   uint_least64_t;
    typedef typename uint_least_width_t<128u> ::type                   uint_least128_t;
    typedef typename uint_width_t      <8u>   ::type                   uint8_t;
    typedef typename uint_width_t      <16u>  ::type                   uint16_t;
    typedef typename uint_width_t      <32u>  ::type                   uint32_t;
    typedef typename uint_width_t      <64u>  ::type                   uint64_t;
    typedef unsigned char                                              uintmin_t;
    typedef typename uint_least_width_t<widthof(void*(nullptr))>::type uintptr_t;
    typedef
      typename conditional<not is_same<uint_least128_t, void>::value, uint_least128_t,
      typename conditional<not is_same<uint_least64_t,  void>::value, uint_least64_t,
      typename conditional<not is_same<uint_least32_t,  void>::value, uint_least32_t,
      typename conditional<not is_same<uint_least16_t,  void>::value, uint_least16_t,
      typename conditional<not is_same<uint_least8_t,   void>::value, uint_least8_t,
        void
      >::type>::type>::type>::type>::type
    uintmax_t;

    #ifdef float16_t
      typedef void float16_t;
    #else
      typedef typename float_width_t<16u>::type float16_t;
    #endif

    #ifdef float32_t
      typedef void float32_t;
    #else
      typedef typename float_width_t<32u>::type float32_t;
    #endif

    #ifdef float64_t
      typedef void float64_t;
    #else
      typedef typename float_width_t<64u>::type float64_t;
    #endif

    #ifdef float128_t
      typedef void float128_t;
    #else
      typedef typename float_width_t<128u>::type float128_t;
    #endif

    #ifdef uint128_t
      typedef void uint128_t;
    #else
      typedef typename uint_width_t<128u>::type uint128_t;
    #endif

    typedef typename signedof<uint_fast8_t>   ::type int_fast8_t;
    typedef typename signedof<uint_fast16_t>  ::type int_fast16_t;
    typedef typename signedof<uint_fast32_t>  ::type int_fast32_t;
    typedef typename signedof<uint_fast64_t>  ::type int_fast64_t;
    typedef typename signedof<uint_fast128_t> ::type int_fast128_t;
    typedef typename signedof<uint_least8_t>  ::type int_least8_t;
    typedef typename signedof<uint_least16_t> ::type int_least16_t;
    typedef typename signedof<uint_least32_t> ::type int_least32_t;
    typedef typename signedof<uint_least64_t> ::type int_least64_t;
    typedef typename signedof<uint_least128_t>::type int_least128_t;
    typedef typename signedof<uint8_t>        ::type int8_t;
    typedef typename signedof<uint16_t>       ::type int16_t;
    typedef typename signedof<uint32_t>       ::type int32_t;
    typedef typename signedof<uint64_t>       ::type int64_t;
    typedef typename signedof<uint128_t>      ::type int128_t;
    typedef typename signedof<uintmax_t>      ::type intmax_t;
    typedef typename signedof<uintmin_t>      ::type intmin_t;
    typedef typename signedof<uintptr_t>      ::type intptr_t;

    // ... ->> User-specified "unsigned" type similar to `byte` for bitwise storage
    template <std::size_t>
    struct bit;

    /* Namespace > Enumeration ->> For configurable function code paths or generic data structures */
    namespace Traits {
      intenum(uint_least16_t, control_parameter) {
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

    /* Namespace > Definition */
    namespace Traits {
      // ...
      #ifdef __cpp_variadic_templates
        template <bool, bool...> struct boolean_and;
        template <bool, bool...> struct boolean_or;
      #else
        template <bool, bool = true, bool = true, bool = true, bool = true, bool = true, bool = true, bool = true> struct boolean_and;
        template <bool, bool = true, bool = true, bool = true, bool = true, bool = true, bool = true, bool = true> struct boolean_or;
      #endif

      // ...
      template <typename base, base>
      struct constant;

      // ...
      template <typename>
      struct maxof;

      // ...
      template <typename>
      struct minof;

      // ...
      template <typename>
      struct nilof;
    }

    /* Definition */
    // ...
    #define as as_operator
    # define as_operator(object) as(object)

    // ...
    #define widthof widthof_operator
    # define widthof_operator(object) sizeof(widthof(object)) / sizeof(uintmin_t)

    /* Function */
    // As ->> Permissibly converts between types; amalgam of `reinterpret_cast`, `static_cast`, and `std::bit_cast<>`
    template <typename typeA, typename typeB>
    constfunc(true) typename conditional<opinfo::template cast<typeB nodecay, typeA>::valid && not (is_array<typeA>::value || is_function<typeA>::value || is_void<typeA>::value), typeA>::type as(typeB nodecay object) noexcept {
      return (typeA) pass<typeB>(object);
    }

    template <typename typeA, typename typeB>
    constfunc(true) typename conditional<not opinfo::template cast<typeB nodecay, typeA>::valid && not (is_array<typeA>::value || is_function<typeA>::value || is_void<typeA>::value), typeA>::type as(typeB nodecay object) noexcept {
      return (typeA&) object;
    }

    template <typename typeA, typename typeB> // ->> Conversion to bounded array type yields a temporary array reference
    constfunc(true) typename conditional<is_bound_array<typeA>::value && not (
      is_integral<typename subbaseof<typeA>::type>::value &&
      (is_integral<typeB>::value || (is_bound_array<typeB>::value && is_integral<typename subbaseof<typeB>::type>::value))
    ), typeA rlref>::type as(
      typeB nodecay object,
      typeA &       array = Array<typename baseof<typeA>::type, lengthof<typeA>::value>().valueOf()
    ) noexcept; // ->> Construction of `array` from `reinterpret_cast`

    template <typename typeA, typename typeB> // ->> Conversion to bounded byte array type yields a temporary array reference
    constfunc(true) typename conditional<is_bound_array<typeA>::value && (
      is_byte<typename subbaseof<typeA>::type>::value &&
      not (is_integral<typeB>::value || (is_bound_array<typeB>::value && is_integral<typename subbaseof<typeB>::type>::value))
    ), typeA rlref>::type as(
      typeB nodecay object,
      typeA &       array = Array<typename baseof<typeA>::type, lengthof<typeA>::value>().valueOf()
    ) noexcept; // --> std::memcpy(...)

    template <typename typeA, typename typeB> // ->> Conversion to bounded integral-base array type from integral-base object yields a temporary array reference
    constfunc(true) typename conditional<is_bound_array<typeA>::value && (
      is_integral<typename subbaseof<typeA>::type>::value &&
      (is_integral<typeB>::value || (is_bound_array<typeB>::value && is_integral<typename subbaseof<typeB>::type>::value))
    ), typeA rlref>::type as(
      typeB nodecay object,
      typeA &       array = Array<typename baseof<typeA>::type, lengthof<typeA>::value>().valueOf()
    ) noexcept; // ->> Manual endian-cognizant bit twiddling

    template <typename typeA, typename typeB> // ->> Conversion to unbounded array type yields a temporary array reference
    constfunc(true) typename conditional<is_unbound_array<typeA>::value && (
      is_complete<typeB>::value
    ), typeA rlref>::type as(
      typeB nodecay                  object,
      typename baseof<typeA>::type (&array)[(sizeof(typeB) / sizeof(typename subbaseof<typeA>::type)) + (0u != sizeof(typeB) % sizeof(typename subbaseof<typeA>::type))] = Array<typename baseof<typeA>::type, (sizeof(typeB) / sizeof(typename subbaseof<typeA>::type)) + (0u != sizeof(typeB) % sizeof(typename subbaseof<typeA>::type))>().valueOf()
    ) noexcept {
      return static_cast<typeA rlref>(as<typename baseof<typeA>::type[(sizeof(typeB) / sizeof(typename subbaseof<typeA>::type)) + (0u != sizeof(typeB) % sizeof(typename subbaseof<typeA>::type))]>(object, array));
    }

    template <typename typeA, typename typeB> // ->> Conversion to unbounded array type from incomplete object yields a temporary array reference
    constfunc(true) typename conditional<is_unbound_array<typeA>::value && (
      not is_complete<typeB>::value &&
    ), typeA rlref>::type as(typeB nodecay) noexcept {
      typedef constant<bool, 0u == sizeof(typename subbaseof<typeA>::type)> invalid_cast;
      static_assert(invalid_cast::value, "Unable to `cast(...)` from an incomplete object to an unbounded array");

      return instanceof<typeA>();
    }

    template <typename typeA, typename typeB> // ->> Conversion to function type from function pointer/ reference yields a wrapper function reference
    constfunc(true) typename conditional<is_function<typeA>::value && (
      is_function<typename subbaseof<typeB>::type>::value
    ), typeA rlref>::type as(typeB nodecay object) noexcept {
      return Function<typeA>(object).valueOf();
    }

    template <typename typeA, typename typeB> // ->> Conversion to function type from non-function object yields a non-executable function reference
    constfunc(true) typename conditional<is_function<typeA>::value && (
      not is_function<typename subbaseof<typeB>::type>::value &&
      false != is_complete<typeB>::value && false != (is_bound_array<typeB>::value && is_byte<typename baseof<typeB>::type>::value)
    ), typeA rlref>::type as(typeB nodecay object) noexcept {
      return Function<typeA>(as<char[sizeof(typeB)]>(object)).valueOf();
    }

    template <typename typeA, typename typeB>
    constfunc(true) typename conditional<is_function<typeA>::value && (
      not is_function<typename subbaseof<typeB>::type>::value &&
      false != is_complete<typeB>::value && false == (is_bound_array<typeB>::value && is_byte<typename baseof<typeB>::type>::value)
    ), typeA rlref>::type as(typeB nodecay object) noexcept {
      return as<typeA>(as<unsigned char[sizeof(typeB)]>(object));
    }

    template <typename typeA, typename typeB> // ->> Conversion to function type from incomplete non-function object yields a non-defined (or mostly ill-formed) function reference
    constfunc(true) typename conditional<is_function<typeA>::value && (
      not is_function<typename subbaseof<typeB>::type>::value &&
      false == is_complete<typeB>::value && false == (is_bound_array<typeB>::value && is_byte<typename baseof<typeB>::type>::value)
    ), typeA rlref>::type as(typeB nodecay) noexcept {
      return Function<typeA>(nullptr).valueOf();
    }

    template <typename typeA, typename typeB> // ->> Conversion to void type does nothing; unfortunately not constant evaluable with stricter `constexpr`
    constfunc(false) typename conditional<is_void<typeA>::value, void>::type>::type as(typeB nodecay) noexcept {}

    // Width Of ->> Queries bit width of object (or type); usable only in unevaluated contexts
    template <std::size_t width>
    constfunc(true) uintmin_t const (&(widthof)(bit<width> const volatile&) noexcept)[width];

    template <typename type>
    constfunc(true) typename conditional<is_complete<type>::value, uintmin_t>::type const (&(widthof)(type const volatile&) noexcept)[CHAR_BIT * sizeof(type)];

    template <typename type>
    constfunc(true) typename conditional<not is_complete<type>::value, uintmin_t>::type const (&(widthof)(type const volatile&) noexcept)[
      #if CPP_VERSION < 2020uL
        1
      #endif
    ] {
      typedef constant<bool, 0u == sizeof(typename subbaseof<type>::type)> invalid_widthof;
      static_assert(invalid_widthof::value, "Invalid application of `widthof(...)` to incomplete type");

      return instanceof<uintmin_t const (&)[
        #if CPP_VERSION < 2020uL
          1
        #endif
      ]>();
    }
  }

  // Current Goals
  // • Ensure `apply(…)` macro works as intended
  // • Ensure `CPP_ENDIAN` works validly with `as` (does it need `std::memcpy(...)`?)
  // • Provide declarations for traits used here (such as `opinfo::cast<>`)
  //
  // Design Goals
  // • Auto-diagnose memory allocations with `__FILE__` and `__LINE__` (and optionally `__COUNTER__`) via macros
  // • Beware of `SIZE_MAX` (or such) for bounded ranges, such as the ones for memory allocators
  // • GCC defines the `<stdint.h>` macros `__INT16_TYPE__`, `__INT32_TYPE__`, `__INT64_TYPE__`, `__INT8_TYPE__`, `__INTPTR_TYPE__`, `__UINT16_TYPE__`, `__UINT32_TYPE__`, `__UINT64_TYPE__`, `__UINT8_TYPE__`, and `__UINTPTR_TYPE__` for optional standard type aliases
  // • Overload literal operators (since C++11) for string methods (`"…"indexOf(…)`, `L"…"hash`, …) and custom string types (`"…"s`, …)
  // • Overload literal operators for unit measurements (`0cm`, `0px`, …)
  // • Prefer `__STDCPP_BFLOAT16_T__`, `__STDCPP_FLOAT16_T__`, `__STDCPP_FLOAT32_T__`, `__STDCPP_FLOAT64_T__`, and `__STDCPP_FLOAT128_T__` (since C++23 from `<stdfloat>`) for fixed-size floating-point arithmetic
  // • Prefer `double_t` and `float_t` (since C++11 from `<cmath>`) for floating-point arithmetic
  // • Prefer `UI::createWindow().append(UI::createButton(), UI::createText())` over `Window{}.append(Button{}, Text{})`
  // • Prefer factory functions & methods over stateful constructors & member functions eg: `System::createFile(…)` evaluates to `class File*` or `NULL`
  // • Standard
  //   ⚬ arbitrary-precision,
  //   ⚬ array, (first member is the actual array, explicitly convertible to pointers, implicitly convertible to arrays)
  //   ⚬ audio,
  //   ⚬ data structure, (linked list, map, set, …)
  //   ⚬ dynamic function, (`Function<…>(nullptr)` creates undefined function; `Function<…>("…")` creates instructions; `Memory::instantiate<Function<…> >("…")` creates callable functions; explicit `Function<…>(…)` takes any callable and wraps 'em)
  //   ⚬ geolocation,
  //   ⚬ 2D/ 3D graphics rendering, (software rendering MUST be guaranteed to be available)
  //   ⚬ events, (keyboard, pointer, touch, vibration, …)
  //   ⚬ font parsing,
  //   ⚬ hardware diagnostics, (battery, gamepad, graphics card, keyboard, stylus, USB, …)
  //   ⚬ HTML parsing,
  //   ⚬ image parsing,
  //   ⚬ internationalization/ locale,
  //   ⚬ math.,
  //   ⚬ memory management, (fixed-size allocations are sorted in buckets, not generalized; `Memory::allocate(…)` evaluates to `class MemoryBuffer` which decays to a pointer — there´s also `Memory::instantiate<>(…)`; `Memory::allocate(…)` may also allocate from "memory-mapped" files)
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
