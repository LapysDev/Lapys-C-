#ifndef LAPYS_MODULE_TRAITS
# define LAPYS_MODULE_TRAITS
  /* Guard > ... */
  #ifdef Traits
  # error Lapys C++: Awkward. Unexpected `Traits` macro definition
  #endif

  #ifdef widthof
  # error Lapys C++: Unexpected `widthof` macro definition
  #endif

  /* Import */
  // : [...]
  #include "extensions.hpp"

  // : [C/ C++ Standard Library]
  #include <climits>  // C Limits
  #include <stdint.h> // Standard Integer
  #if CPP_VERSION >= 2011uL
  # include <type_traits> // Type Traits
  #endif

  #if defined(__cpp_impl_three_way_comparison) && defined(__cpp_lib_three_way_comparison) // --> 201907L
  # include <compare> // Compare
  #endif

  /* Namespace ->> All concepts/ metafunctions/ traits should be `struct ... final`, everything else a `union ...` */
  namespace Lapys {
    /* Class > Bit ->> Distinct (unsigned) type similar to `byte` for bitwise storage */
    template <std::size_t>
    struct bit;

    /* Function */
    // Instance Of ->> Plain & simple type deduction with no reference-qualifications
    template <typename type>
    constfunc(true) type (instanceof)() noexcept;

    // Pass ->> Prevent redundant copying (and preserve type qualifications) when forwarding parameters between functions
    #ifdef __cpp_rvalue_references // --> 200610L
      template <typename type> constfunc(true) mustinline type&  (pass)(type&  object) noexcept { return static_cast<type&&>(object); }
      template <typename type> constfunc(true) mustinline type&& (pass)(type&& object) noexcept { return static_cast<type&&>(object); }
    #else
      template <typename type> constfunc(true) mustinline type&                (pass)(type&                object) noexcept { return object; }
      template <typename type> constfunc(true) mustinline type const&          (pass)(type const&          object) noexcept { return object; }
      template <typename type> constfunc(true) mustinline type const volatile& (pass)(type const volatile& object) noexcept { return object; }
      template <typename type> constfunc(true) mustinline type volatile&       (pass)(type volatile&       object) noexcept { return object; }
    #endif

    // Width Of ->> Queries bit width of expression (object)
    #define widthof(expression) (sizeof(::Lapys::widthof(expression)) / sizeof(unsigned char))

    template <std::size_t width> constfunc(true) mustinline unsigned char /* --> byte */ (&(widthof)(bit<width> const)   noexcept)[width];
    template <typename    type>  constfunc(true) mustinline unsigned char /* --> byte */ (&(widthof)(type       nodecay) noexcept)[CHAR_BIT * sizeof(type)];

    /* Alias */
    // Byte ->> Aliases to an (unsigned) byte type blessed by the standard (as specified in the C++ language definition)
    #ifndef __cpp_lib_byte // --> 201603L
      typedef unsigned char byte;
    #else
      typedef std::byte byte;

      // ... ->> Make `Lapys::byte` types operationally consistent; cannot override standard-defined operator overloads
      constfunc(true) mustinline std::byte (operator +)(std::byte const byte) noexcept { return byte; }
      constfunc(true) mustinline std::byte (operator -)(std::byte const byte) noexcept { return static_cast<std::byte>(-std::to_integer<unsigned char>(byte)); }
      constfunc(true) mustinline bool      (operator !)(std::byte const byte) noexcept { return !std::to_integer<unsigned char>(byte); }

      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          +=  instanceof<type nodecay>())                    (operator += )(std::byte&          byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char&>()          +=  instanceof<type nodecay>()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          +=  instanceof<type nodecay>()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          +=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() +=  instanceof<type nodecay>())                    (operator += )(std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() +=  instanceof<type nodecay>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() +=  instanceof<type nodecay>()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() +=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          -=  instanceof<type nodecay>())                    (operator -= )(std::byte&          byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char&>()          -=  instanceof<type nodecay>()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          -=  instanceof<type nodecay>()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          -=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() -=  instanceof<type nodecay>())                    (operator -= )(std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() -=  instanceof<type nodecay>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() -=  instanceof<type nodecay>()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() -=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          *=  instanceof<type nodecay>())                    (operator *= )(std::byte&          byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char&>()          *=  instanceof<type nodecay>()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          *=  instanceof<type nodecay>()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          *=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() *=  instanceof<type nodecay>())                    (operator *= )(std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() *=  instanceof<type nodecay>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() *=  instanceof<type nodecay>()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() *=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          /=  instanceof<type nodecay>())                    (operator /= )(std::byte&          byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char&>()          /=  instanceof<type nodecay>()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          /=  instanceof<type nodecay>()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          /=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() /=  instanceof<type nodecay>())                    (operator /= )(std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() /=  instanceof<type nodecay>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() /=  instanceof<type nodecay>()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() /=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          %=  instanceof<type nodecay>())                    (operator %= )(std::byte&          byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char&>()          %=  instanceof<type nodecay>()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          %=  instanceof<type nodecay>()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          %=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() %=  instanceof<type nodecay>())                    (operator %= )(std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() %=  instanceof<type nodecay>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() %=  instanceof<type nodecay>()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() %=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() &=  instanceof<type nodecay>())                    (operator &= )(std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() &=  instanceof<type nodecay>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() &=  instanceof<type nodecay>()) evaluation = (value &=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() &=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() |=  instanceof<type nodecay>())                    (operator |= )(std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() |=  instanceof<type nodecay>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() |=  instanceof<type nodecay>()) evaluation = (value |=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() |=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type nodecay>())                    (operator ^= )(std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() ^=  instanceof<type nodecay>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type nodecay>()) evaluation = (value ^=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() <<= instanceof<type nodecay>())                    (operator <<=)(std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() <<= instanceof<type nodecay>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() <<= instanceof<type nodecay>()) evaluation = (value <<= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() <<= instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() >>= instanceof<type nodecay>())                    (operator >>=)(std::byte volatile& byte, type nodecay object) exceptspec(exceptof(instanceof<unsigned char volatile&>() >>= instanceof<type nodecay>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() >>= instanceof<type nodecay>()) evaluation = (value >>= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() >>= instanceof<type nodecay>())>(evaluation); }
      template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) == instanceof<type nodecay>())) (operator == )(std::byte const     byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) == instanceof<type nodecay>())) { return std::to_integer<unsigned char>(byte) == pass<type>(object); }
      template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) != instanceof<type nodecay>())) (operator != )(std::byte const     byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) != instanceof<type nodecay>())) { return std::to_integer<unsigned char>(byte) != pass<type>(object); }
      template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) <  instanceof<type nodecay>())) (operator <  )(std::byte const     byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <  instanceof<type nodecay>())) { return std::to_integer<unsigned char>(byte) <  pass<type>(object); }
      template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) >  instanceof<type nodecay>())) (operator >  )(std::byte const     byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) >  instanceof<type nodecay>())) { return std::to_integer<unsigned char>(byte) >  pass<type>(object); }
      template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) <= instanceof<type nodecay>())) (operator <= )(std::byte const     byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <= instanceof<type nodecay>())) { return std::to_integer<unsigned char>(byte) <= pass<type>(object); }
      template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) >= instanceof<type nodecay>())) (operator >= )(std::byte const     byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) >= instanceof<type nodecay>())) { return std::to_integer<unsigned char>(byte) >= pass<type>(object); }

      #if defined(__cpp_impl_three_way_comparison) || defined(__cpp_lib_three_way_comparison) // --> 201907L
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type nodecay>())) (operator <=>)(std::byte const byte, type nodecay object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type nodecay>())) { return std::to_integer<unsigned char>(byte) <=> pass<type>(object); }
      #endif

      #if CPP_VERSION < 2011uL // ->> A preview of the cost of over-compensating for not having perfect-forwarding syntax; not abstracted with convenience macros such as `apply(...)` due to possibly unreliable preprocessor speeds
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          +=  instanceof<type&>               ())                    (operator += )(std::byte&          byte, type&                object) exceptspec(exceptof(instanceof<unsigned char&>()          +=  instanceof<type&>               ()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          +=  instanceof<type&>               ()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          +=  instanceof<type&>               ())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          +=  instanceof<type       volatile&>())                    (operator += )(std::byte&          byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          +=  instanceof<type       volatile&>()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          +=  instanceof<type       volatile&>()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          +=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          +=  instanceof<type const volatile&>())                    (operator += )(std::byte&          byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          +=  instanceof<type const volatile&>()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          +=  instanceof<type const volatile&>()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          +=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() +=  instanceof<type&>               ())                    (operator += )(std::byte volatile& byte, type&                object) exceptspec(exceptof(instanceof<unsigned char volatile&>() +=  instanceof<type&>               ()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() +=  instanceof<type&>               ()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() +=  instanceof<type&>               ())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() +=  instanceof<type       volatile&>())                    (operator += )(std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() +=  instanceof<type       volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() +=  instanceof<type       volatile&>()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() +=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() +=  instanceof<type const volatile&>())                    (operator += )(std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() +=  instanceof<type const volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() +=  instanceof<type const volatile&>()) evaluation = (value +=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() +=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          -=  instanceof<type&>               ())                    (operator -= )(std::byte&          byte, type&                object) exceptspec(exceptof(instanceof<unsigned char&>()          -=  instanceof<type&>               ()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          -=  instanceof<type&>               ()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          -=  instanceof<type&>               ())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          -=  instanceof<type       volatile&>())                    (operator -= )(std::byte&          byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          -=  instanceof<type       volatile&>()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          -=  instanceof<type       volatile&>()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          -=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          -=  instanceof<type const volatile&>())                    (operator -= )(std::byte&          byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          -=  instanceof<type const volatile&>()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          -=  instanceof<type const volatile&>()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          -=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() -=  instanceof<type&>               ())                    (operator -= )(std::byte volatile& byte, type&                object) exceptspec(exceptof(instanceof<unsigned char volatile&>() -=  instanceof<type&>               ()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() -=  instanceof<type&>               ()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() -=  instanceof<type&>               ())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() -=  instanceof<type       volatile&>())                    (operator -= )(std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() -=  instanceof<type       volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() -=  instanceof<type       volatile&>()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() -=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() -=  instanceof<type const volatile&>())                    (operator -= )(std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() -=  instanceof<type const volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() -=  instanceof<type const volatile&>()) evaluation = (value -=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() -=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          *=  instanceof<type&>               ())                    (operator *= )(std::byte&          byte, type&                object) exceptspec(exceptof(instanceof<unsigned char&>()          *=  instanceof<type&>               ()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          *=  instanceof<type&>               ()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          *=  instanceof<type&>               ())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          *=  instanceof<type       volatile&>())                    (operator *= )(std::byte&          byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          *=  instanceof<type       volatile&>()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          *=  instanceof<type       volatile&>()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          *=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          *=  instanceof<type const volatile&>())                    (operator *= )(std::byte&          byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          *=  instanceof<type const volatile&>()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          *=  instanceof<type const volatile&>()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          *=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() *=  instanceof<type&>               ())                    (operator *= )(std::byte volatile& byte, type&                object) exceptspec(exceptof(instanceof<unsigned char volatile&>() *=  instanceof<type&>               ()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() *=  instanceof<type&>               ()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() *=  instanceof<type&>               ())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() *=  instanceof<type       volatile&>())                    (operator *= )(std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() *=  instanceof<type       volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() *=  instanceof<type       volatile&>()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() *=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() *=  instanceof<type const volatile&>())                    (operator *= )(std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() *=  instanceof<type const volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() *=  instanceof<type const volatile&>()) evaluation = (value *=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() *=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          /=  instanceof<type&>               ())                    (operator /= )(std::byte&          byte, type&                object) exceptspec(exceptof(instanceof<unsigned char&>()          /=  instanceof<type&>               ()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          /=  instanceof<type&>               ()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          /=  instanceof<type&>               ())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          /=  instanceof<type       volatile&>())                    (operator /= )(std::byte&          byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          /=  instanceof<type       volatile&>()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          /=  instanceof<type       volatile&>()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          /=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          /=  instanceof<type const volatile&>())                    (operator /= )(std::byte&          byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          /=  instanceof<type const volatile&>()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          /=  instanceof<type const volatile&>()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          /=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() /=  instanceof<type&>               ())                    (operator /= )(std::byte volatile& byte, type&                object) exceptspec(exceptof(instanceof<unsigned char volatile&>() /=  instanceof<type&>               ()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() /=  instanceof<type&>               ()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() /=  instanceof<type&>               ())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() /=  instanceof<type       volatile&>())                    (operator /= )(std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() /=  instanceof<type       volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() /=  instanceof<type       volatile&>()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() /=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() /=  instanceof<type const volatile&>())                    (operator /= )(std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() /=  instanceof<type const volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() /=  instanceof<type const volatile&>()) evaluation = (value /=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() /=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          %=  instanceof<type&>               ())                    (operator %= )(std::byte&          byte, type&                object) exceptspec(exceptof(instanceof<unsigned char&>()          %=  instanceof<type&>               ()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          %=  instanceof<type&>               ()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          %=  instanceof<type&>               ())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          %=  instanceof<type       volatile&>())                    (operator %= )(std::byte&          byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          %=  instanceof<type       volatile&>()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          %=  instanceof<type       volatile&>()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          %=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char&>()          %=  instanceof<type const volatile&>())                    (operator %= )(std::byte&          byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char&>()          %=  instanceof<type const volatile&>()))                  { unsigned char          value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char&>()          %=  instanceof<type const volatile&>()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char&>()          %=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() %=  instanceof<type&>               ())                    (operator %= )(std::byte volatile& byte, type&                object) exceptspec(exceptof(instanceof<unsigned char volatile&>() %=  instanceof<type&>               ()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() %=  instanceof<type&>               ()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() %=  instanceof<type&>               ())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() %=  instanceof<type       volatile&>())                    (operator %= )(std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() %=  instanceof<type       volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() %=  instanceof<type       volatile&>()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() %=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() %=  instanceof<type const volatile&>())                    (operator %= )(std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() %=  instanceof<type const volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() %=  instanceof<type const volatile&>()) evaluation = (value %=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() %=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() &=  instanceof<type&>               ())                    (operator &= )(std::byte volatile& byte, type&                object) exceptspec(exceptof(instanceof<unsigned char volatile&>() &=  instanceof<type&>               ()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() &=  instanceof<type&>               ()) evaluation = (value &=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() &=  instanceof<type&>               ())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() &=  instanceof<type       volatile&>())                    (operator &= )(std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() &=  instanceof<type       volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() &=  instanceof<type       volatile&>()) evaluation = (value &=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() &=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() &=  instanceof<type const volatile&>())                    (operator &= )(std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() &=  instanceof<type const volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() &=  instanceof<type const volatile&>()) evaluation = (value &=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() &=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() |=  instanceof<type&>               ())                    (operator |= )(std::byte volatile& byte, type&                object) exceptspec(exceptof(instanceof<unsigned char volatile&>() |=  instanceof<type&>               ()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() |=  instanceof<type&>               ()) evaluation = (value |=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() |=  instanceof<type&>               ())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() |=  instanceof<type       volatile&>())                    (operator |= )(std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() |=  instanceof<type       volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() |=  instanceof<type       volatile&>()) evaluation = (value |=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() |=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() |=  instanceof<type const volatile&>())                    (operator |= )(std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() |=  instanceof<type const volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() |=  instanceof<type const volatile&>()) evaluation = (value |=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() |=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type&>               ())                    (operator ^= )(std::byte volatile& byte, type&                object) exceptspec(exceptof(instanceof<unsigned char volatile&>() ^=  instanceof<type&>               ()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type&>               ()) evaluation = (value ^=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type&>               ())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type       volatile&>())                    (operator ^= )(std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() ^=  instanceof<type       volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type       volatile&>()) evaluation = (value ^=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type const volatile&>())                    (operator ^= )(std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() ^=  instanceof<type const volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type const volatile&>()) evaluation = (value ^=  pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() ^=  instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() <<= instanceof<type&>               ())                    (operator <<=)(std::byte volatile& byte, type&                object) exceptspec(exceptof(instanceof<unsigned char volatile&>() <<= instanceof<type&>               ()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() <<= instanceof<type&>               ()) evaluation = (value <<= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() <<= instanceof<type&>               ())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() <<= instanceof<type       volatile&>())                    (operator <<=)(std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() <<= instanceof<type       volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() <<= instanceof<type       volatile&>()) evaluation = (value <<= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() <<= instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() <<= instanceof<type const volatile&>())                    (operator <<=)(std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() <<= instanceof<type const volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() <<= instanceof<type const volatile&>()) evaluation = (value <<= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() <<= instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() >>= instanceof<type&>               ())                    (operator >>=)(std::byte volatile& byte, type&                object) exceptspec(exceptof(instanceof<unsigned char volatile&>() >>= instanceof<type&>               ()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() >>= instanceof<type&>               ()) evaluation = (value >>= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() >>= instanceof<type&>               ())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() >>= instanceof<type       volatile&>())                    (operator >>=)(std::byte volatile& byte, type       volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() >>= instanceof<type       volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() >>= instanceof<type       volatile&>()) evaluation = (value >>= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() >>= instanceof<type       volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof(instanceof<unsigned char volatile&>() >>= instanceof<type const volatile&>())                    (operator >>=)(std::byte volatile& byte, type const volatile& object) exceptspec(exceptof(instanceof<unsigned char volatile&>() >>= instanceof<type const volatile&>()))                  { unsigned char volatile value = std::to_integer<unsigned char>(byte); typeof(instanceof<unsigned char volatile&>() >>= instanceof<type const volatile&>()) evaluation = (value >>= pass<type>(object)); byte = static_cast<std::byte>(value); return static_cast<typeof(instanceof<unsigned char volatile&>() >>= instanceof<type const volatile&>())>(evaluation); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) == instanceof<type&>               ())) (operator == )(std::byte const     byte, type&                object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) == instanceof<type&>               ())) { return std::to_integer<unsigned char>(byte) == pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) == instanceof<type       volatile&>())) (operator == )(std::byte const     byte, type       volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) == instanceof<type       volatile&>())) { return std::to_integer<unsigned char>(byte) == pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) == instanceof<type const volatile&>())) (operator == )(std::byte const     byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) == instanceof<type const volatile&>())) { return std::to_integer<unsigned char>(byte) == pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) != instanceof<type&>               ())) (operator != )(std::byte const     byte, type&                object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) != instanceof<type&>               ())) { return std::to_integer<unsigned char>(byte) != pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) != instanceof<type       volatile&>())) (operator != )(std::byte const     byte, type       volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) != instanceof<type       volatile&>())) { return std::to_integer<unsigned char>(byte) != pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) != instanceof<type const volatile&>())) (operator != )(std::byte const     byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) != instanceof<type const volatile&>())) { return std::to_integer<unsigned char>(byte) != pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) <  instanceof<type&>               ())) (operator <  )(std::byte const     byte, type&                object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <  instanceof<type&>               ())) { return std::to_integer<unsigned char>(byte) <  pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) <  instanceof<type       volatile&>())) (operator <  )(std::byte const     byte, type       volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <  instanceof<type       volatile&>())) { return std::to_integer<unsigned char>(byte) <  pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) <  instanceof<type const volatile&>())) (operator <  )(std::byte const     byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <  instanceof<type const volatile&>())) { return std::to_integer<unsigned char>(byte) <  pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) >  instanceof<type&>               ())) (operator >  )(std::byte const     byte, type&                object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) >  instanceof<type&>               ())) { return std::to_integer<unsigned char>(byte) >  pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) >  instanceof<type       volatile&>())) (operator >  )(std::byte const     byte, type       volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) >  instanceof<type       volatile&>())) { return std::to_integer<unsigned char>(byte) >  pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) >  instanceof<type const volatile&>())) (operator >  )(std::byte const     byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) >  instanceof<type const volatile&>())) { return std::to_integer<unsigned char>(byte) >  pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) <= instanceof<type&>               ())) (operator <= )(std::byte const     byte, type&                object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <= instanceof<type&>               ())) { return std::to_integer<unsigned char>(byte) <= pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) <= instanceof<type       volatile&>())) (operator <= )(std::byte const     byte, type       volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <= instanceof<type       volatile&>())) { return std::to_integer<unsigned char>(byte) <= pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) <= instanceof<type const volatile&>())) (operator <= )(std::byte const     byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <= instanceof<type const volatile&>())) { return std::to_integer<unsigned char>(byte) <= pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) >= instanceof<type&>               ())) (operator >= )(std::byte const     byte, type&                object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) >= instanceof<type&>               ())) { return std::to_integer<unsigned char>(byte) >= pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) >= instanceof<type       volatile&>())) (operator >= )(std::byte const     byte, type       volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) >= instanceof<type       volatile&>())) { return std::to_integer<unsigned char>(byte) >= pass<type>(object); }
        template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) >= instanceof<type const volatile&>())) (operator >= )(std::byte const     byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) >= instanceof<type const volatile&>())) { return std::to_integer<unsigned char>(byte) >= pass<type>(object); }

        #if defined(__cpp_impl_three_way_comparison) || defined(__cpp_lib_three_way_comparison) // --> 201907L
          template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type&>               ())) (operator <=>)(std::byte const byte, type&                object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type&>               ())) { return std::to_integer<unsigned char>(byte) <=> pass<type>(object); }
          template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type       volatile&>())) (operator <=>)(std::byte const byte, type       volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type       volatile&>())) { return std::to_integer<unsigned char>(byte) <=> pass<type>(object); }
          template <typename type> constfunc(false) mustinline typeof((std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type const volatile&>())) (operator <=>)(std::byte const byte, type const volatile& object) exceptspec(exceptof(std::to_integer<unsigned char>(instanceof<std::byte>()) <=> instanceof<type const volatile&>())) { return std::to_integer<unsigned char>(byte) <=> pass<type>(object); }
        #endif
      #endif
    #endif

    // ...
    typedef unsigned long uintmax_template_t;

    /* Trait */
    // Null ->> Specialization type denoting an "empty set of values"; See `void` type
    union null;

    // SFINAE Pointer ->> Specialization-only type
    #if CPP_VERSION < 2011uL
      #define sfinaeptr sfinaeptr
      enum sfinaeptr_t /* : unsigned char */ { sfinaeptr /* = 0x00hhu */ };
    #else
      #define sfinaeptr nullptr
      typedef std::nullptr_t sfinaeptr_t;
    #endif

    /* Namespace */
    namespace Traits {
      /* Alias > Boolean (False, True) */
      typedef bool nodecayparam(boolean_false)[false + 1u];
      typedef bool nodecayparam(boolean_true) [true  + 1u];

      /* Trait > ... ->> Not all traits are neatly declarable without their definition */
      struct defer;
      struct enumtypeinfo;
      struct opinfo;

      template <typename>                               struct alias;
      template <typename, bool = false>                 struct classinfo;
      template <bool, typename = null, typename = null> struct conditional;
      template <typename base, base, bool>              struct constant;
      template <typename>                               struct enuminfo;
      template <std::size_t>                            struct float_fast_t;
      template <std::size_t>                            struct float_fast_width_t;
      template <std::size_t>                            struct float_least_t;
      template <std::size_t>                            struct float_least_width_t;
      template <std::size_t>                            struct float_t;
      template <std::size_t>                            struct float_width_t;
      template <std::size_t>                            struct int_fast_t;
      template <std::size_t>                            struct int_fast_width_t;
      template <std::size_t>                            struct int_least_t;
      template <std::size_t>                            struct int_least_width_t;
      template <std::size_t>                            struct int_t;
      template <std::size_t>                            struct int_width_t;
      template <typename>                               struct is_class;
      template <typename>                               struct is_enum;
      template <typename>                               struct is_final;
      template <typename, bool = false>                 struct is_integer;
      template <typename>                               struct is_null;
      template <typename, typename>                     struct is_same;
      template <typename>                               struct is_signed;
      template <typename>                               struct is_similar;
      template <typename>                               struct is_union;
      template <typename>                               struct is_unsigned;
      template <typename>                               struct maxof;
      template <typename>                               struct minof;
      template <typename>                               struct nilof;
      template <typename>                               struct remove_const;
      template <typename>                               struct remove_const_volatile;
      template <typename>                               struct remove_volatile;
      template <typename>                               struct signedof;
      template <std::size_t>                            struct uint_fast_t;
      template <std::size_t>                            struct uint_fast_width_t;
      template <std::size_t>                            struct uint_least_t;
      template <std::size_t>                            struct uint_least_width_t;
      template <std::size_t>                            struct uint_t;
      template <std::size_t>                            struct uint_width_t;
      template <typename>                               struct unsignedof;

      #ifdef __cpp_variadic_templates // --> 200704L
        template <bool, bool...> struct boolean_and;
        template <bool, bool...> struct boolean_or;
      #else
        template <bool, bool = true, bool = true, bool = true, bool = true, bool = true, bool = true, bool = true> struct boolean_and;
        template <bool, bool = true, bool = true, bool = true, bool = true, bool = true, bool = true, bool = true> struct boolean_or;
      #endif
    }

    /* ... */
    using namespace Traits;
  }

  namespace Lapys {
    /* Namespace */
    namespace Traits {
      /* Trait */
      // ... ->> Aliases specified type (plain and simple)
      template <typename base>
      struct alias final {
        typedef base type;
      };

      // ... ->> Class type diagnostics
      template <typename base, bool fallback>
      struct classinfo final {
        private:
          // ... ->> Evaluates if type is a union type
          template <typename subbase, bool subfallback = false>
          struct unionof final {
            private:
              template <typename type>
              constfunc(false) static boolean_true valueof(sfinaeptr_t const, byte type::* const = NULL) noexcept;

              template <typename>
              constfunc(false) static boolean_false valueof(...) noexcept;

            public:
              static bool const value =
                #if CPP_VERSION >= 2011uL
                  std::is_union<subbase>::value or
                #elif CPP_COMPILER == CPP_CIRCLE_COMPILER || CPP_COMPILER == CPP_CLANG_COMPILER || CPP_COMPILER == CPP_GNUC_COMPILER || CPP_COMPILER == CPP_INTEL_COMPILER || CPP_COMPILER == CPP_LLVM_COMPILER || CPP_COMPILER == CPP_NVCC_COMPILER
                # ifdef __has_builtin // --> `__is_union(...)` may still exist otherwise
                #   if __has_builtin(__is_union)
                      __is_union(subbase) or
                #   endif
                # endif
                #elif CPP_COMPILER == CPP_MSVC_COMPILER
                  __is_union(subbase) or
                #endif
              sizeof(boolean_true) == sizeof(valueof<subbase>(sfinaeptr)) or
              subfallback;
          };

          // ... ->> Evaluates if type is a class or union type
          template <typename subbase>
          struct valueof final {
            static bool const value =
              #if CPP_VERSION >= 2011uL
                std::is_class<subbase>::value or
              #elif CPP_COMPILER == CPP_MSVC_COMPILER
                __is_class(subbase) or
              #elif CPP_COMPILER == CPP_CIRCLE_COMPILER || CPP_COMPILER == CPP_CLANG_COMPILER || CPP_COMPILER == CPP_GNUC_COMPILER || CPP_COMPILER == CPP_INTEL_COMPILER || CPP_COMPILER == CPP_LLVM_COMPILER || CPP_COMPILER == CPP_NVCC_COMPILER
              # ifdef __has_builtin // --> `__is_class(...)` may still exist otherwise
              #   if __has_builtin(__is_class)
                    __is_class(subbase) or
              #   endif
              # endif
              #endif
            unionof<subbase, fallback>::value;
          };

          // ... ->> Evaluates if class type is specified `final`; Union types always evaluate falsy
          template <typename subbase, bool = valueof<subbase>::value>
          struct finalof final {
            static bool const value = false;
          };

          template <typename subbase>
          struct finalof<subbase, true> final {
            static bool const value =
              #if CPP_VERSION >= 2014uL
                std::is_final<subbase>::value and
              #elif CPP_VERSION >= 2011uL
              # if CPP_COMPILER == CPP_CIRCLE_COMPILER || CPP_COMPILER == CPP_CLANG_COMPILER || CPP_COMPILER == CPP_GNUC_COMPILER || CPP_COMPILER == CPP_INTEL_COMPILER || CPP_COMPILER == CPP_LLVM_COMPILER || CPP_COMPILER == CPP_NVCC_COMPILER
              #   ifdef __has_builtin // --> `__is_final(...)` may still exist otherwise
              #     if __has_builtin(__is_final)
                      __is_final(subbase) and
              #     endif
              #   endif
              # elif CPP_COMPILER == CPP_MSVC_COMPILER
                  __is_sealed(subbase) and
              # endif
              #endif
            false;
          };

        public:
          static bool const derivable = not finalof<base>::value and not unionof<base>::value;
          static bool const value     = valueof<base>::value;
          static bool const variant   = unionof<base>::value;
      };

      // ... ->> Aliases dependent type based on (boolean) condition
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

      // ... ->> Evaluates if type is (based on) an integer type
      template <typename base, bool enumerable>
      struct is_integer final {
        static bool const value = conditional<enumerable, constant<bool, false, true>, is_enum<base> >::type::value;
      };

      template <bool enumerable>
      struct is_integer<bool, enumerable> final {
        static bool const value = true;
      };

      template <bool enumerable>
      struct is_integer<char, enumerable> final {
        static bool const value = true;
      };

      template <bool enumerable>
      struct is_integer<int, enumerable> final {
        static bool const value = true;
      };

      template <bool enumerable>
      struct is_integer<long, enumerable> final {
        static bool const value = true;
      };

      template <bool enumerable>
      struct is_integer<short, enumerable> final {
        static bool const value = true;
      };

      template <bool enumerable>
      struct is_integer<signed char, enumerable> final {
        static bool const value = true;
      };

      template <bool enumerable>
      struct is_integer<unsigned char, enumerable> final {
        static bool const value = true;
      };

      template <bool enumerable>
      struct is_integer<unsigned int, enumerable> final {
        static bool const value = true;
      };

      template <bool enumerable>
      struct is_integer<unsigned long, enumerable> final {
        static bool const value = true;
      };

      template <bool enumerable>
      struct is_integer<unsigned short, enumerable> final {
        static bool const value = true;
      };

      template <bool enumerable>
      struct is_integer<wchar_t, enumerable> final {
        static bool const value = true;
      };

      #if CPP_VERSION >= 2011uL
        template <bool enumerable>
        struct is_integer<long long, enumerable> final {
          static bool const value = true;
        };

        template <bool enumerable>
        struct is_integer<unsigned long long, enumerable> final {
          static bool const value = true;
        };
      #endif

      #ifdef __cpp_char8_t // --> 201811L
        template <bool enumerable>
        struct is_integer<char8_t /* --> unsigned char */, enumerable> final {
          static bool const value = true;
        };
      #endif

      #ifdef __cpp_lib_byte // --> 201603L
        template <bool enumerable>
        struct is_integer<std::byte /* --> unsigned char */, enumerable> final {
          static bool const value = true;
        };
      #endif

      #ifdef __cpp_unicode_characters // --> 200704L
        template <bool enumerable>
        struct is_integer<char16_t /* --> std::uint_least16_t */, enumerable> final {
          static bool const value = true;
        };

        template <bool enumerable>
        struct is_integer<char32_t /* --> std::uint_least32_t */, enumerable> final {
          static bool const value = true;
        };
      #endif

      #ifdef int128_t
        template <bool enumerable>
        struct is_integer<int128_t, enumerable> final {
          static bool const value = true;
        };
      #endif

      #ifdef uint128_t
        template <bool enumerable>
        struct is_integer<uint128_t, enumerable> final {
          static bool const value = true;
        };
      #endif

      template <std::size_t width>
      struct is_integer<bit<width>, false> final {
        static bool const value = true;
      };

      template <typename base, bool enumerable>
      struct is_integer<base const, enumerable> final {
        static bool const value = is_integer<base, enumerable>::value;
      };

      template <typename base, bool enumerable>
      struct is_integer<base const volatile, enumerable> final {
        static bool const value = is_integer<base, enumerable>::value;
      };

      template <typename base, bool enumerable>
      struct is_integer<base volatile, enumerable> final {
        static bool const value = is_integer<base, enumerable>::value;
      };

      // ... ->> Constant of specified type preferably instantiated at compile-time
      #ifdef __cpp_constexpr // --> 200704L
        template <typename base, base constantValue, bool = false>
        struct constant final {
          constexpr static base value = constantValue;
        };
      #else
        template <typename base, base constantValue, bool = is_integer<base>::value>
        struct constant final {
          static base const value = constantValue;
        };

        template <typename base, base constantValue>
        struct constant<base, constantValue, false> final {
          static base const value;
        };
          template <typename base, base value>
          base const constant<base, value, false>::value = value;
      #endif

      // ... ->> Dummy type for overarching evaluation eg: `sizeof defer::type<T>` instead of `sizeof T` for incomplete type `T`
      struct defer final {
        template <typename base, base>
        struct constant final {};

        // ...
        template <typename>
        struct type final {};
      };

      // ... ->> Type signedness
      template <typename>
      struct is_signed final {
        static bool const value = false;
      };

      template <>
      struct is_signed<signed char> final {
        static bool const value = true;
      };

      template <>
      struct is_signed<signed int> final {
        static bool const value = true;
      };

      template <>
      struct is_signed<signed long> final {
        static bool const value = true;
      };

      template <>
      struct is_signed<signed short> final {
        static bool const value = true;
      };

      #if CHAR_MIN - 0
        template <>
        struct is_signed<char> final {
          static bool const value = true;
        };
      #endif

      #if CPP_VERSION >= 2011uL
        template <>
        struct is_signed<signed long long> final {
          static bool const value = true;
        };
      #endif

      #ifdef int128_t
        template <>
        struct is_signed<int128_t> final {
          static bool const value = true;
        };
      #endif

      // ... ->> Enumeration type diagnostics
      struct enumtypeinfo final {
        template <typename>
        friend struct enuminfo;

        private:
          typedef unsigned char      metadata_t;
          typedef bool               signedness_t;
          typedef uintmax_template_t size_t;

          /* ... */
          static unsigned char const METADATA_WIDTH   = 3u;
          static unsigned char const SIGNEDNESS_WIDTH = 1u;
          static unsigned char const SIZE_WIDTH       = (CHAR_BIT * sizeof(size_t)) - (METADATA_WIDTH + SIGNEDNESS_WIDTH);

          /* ... */
          template <typename, sfinaeptr_t = sfinaeptr> struct metadataof                  final { static metadata_t const value = 0u; };
          template <sfinaeptr_t sfinae>                struct metadataof<bool,    sfinae> final { static metadata_t const value = 1u; };
          template <sfinaeptr_t sfinae>                struct metadataof<char,    sfinae> final { static metadata_t const value = 2u; };
          template <sfinaeptr_t sfinae>                struct metadataof<wchar_t, sfinae> final { static metadata_t const value = 1u; };
          #ifdef __cpp_char8_t // --> 201811L
            template <sfinaeptr_t sfinae> struct metadataof<char8_t, sfinae> final { static metadata_t const value = 3u; };
          #endif
          #ifdef __cpp_lib_byte // --> 201603L
            template <sfinaeptr_t sfinae> struct metadataof<std::byte, sfinae> final { static metadata_t const value = 4u; };
          #endif
          #ifdef __cpp_unicode_characters // --> 200704L
            template <sfinaeptr_t sfinae> struct metadataof<char16_t, sfinae> final { static metadata_t const value = 1u; };
            template <sfinaeptr_t sfinae> struct metadataof<char32_t, sfinae> final { static metadata_t const value = 1u; };
          #endif

          // ...
          template <std::size_t base>
          struct decode final {
            private:
              static metadata_t   const metadata   = (base >> 0u)                                  & ((((1u << (METADATA_WIDTH   - 1u)) - 1u) << 1u) + 1u);
              static signedness_t const signedness = (base >> METADATA_WIDTH)                      & ((((1u << (SIGNEDNESS_WIDTH - 1u)) - 1u) << 1u) + 1u);
              static size_t       const size       = (base >> (METADATA_WIDTH + SIGNEDNESS_WIDTH)) & ((((1u << (SIZE_WIDTH       - 1u)) - 1u) << 1u) + 1u);

            public:
              typedef
                typename conditional<metadata == metadataof<bool>   ::value && size == sizeof(bool),    bool,
                typename conditional<metadata == metadataof<char>   ::value && size == sizeof(char),    char,
                typename conditional<metadata == metadataof<wchar_t>::value && size == sizeof(wchar_t), wchar_t,

                typename conditional<
                #ifdef __cpp_char8_t // --> 201811L
                  metadata == metadataof<char8_t>::value && size == sizeof(char8_t), char8_t,
                #else
                  false, null,
                #endif

                typename conditional<
                #ifdef __cpp_lib_byte // --> 201603L
                  metadata == metadataof<std::byte>::value && size == sizeof(std::byte), std::byte,
                #else
                  false, null,
                #endif

                typename conditional<
                #ifdef __cpp_unicode_characters // --> 200704L
                  metadata == metadataof<char16_t>::value && size == sizeof(char16_t), char16_t,
                #else
                  false, null,
                #endif

                typename conditional<
                #ifdef __cpp_unicode_characters // --> 200704L
                  metadata == metadataof<char32_t>::value && size == sizeof(char32_t), char32_t,
                #else
                  false, null,
                #endif

                  typename conditional<signedness, typename int_t<size>::type, typename uint_t<size>::type>::type
                >::type>::type>::type>::type>::type>::type>::type
              type;
          };

          // ...
          template <typename base, metadata_t metadata = 0u>
          struct encode final {
            private:
              typedef constant<bool, 0u == (sizeof(base) >> SIZE_WIDTH)> enum_underlying_type_unrepresentable;
              static_assert(enum_underlying_type_unrepresentable::value, "Expected enumeration underlying type to be of smaller size");

            public:
              static std::size_t const value = (
                ((0u != metadata ? metadata : metadataof<base>::value & ((((1u << (METADATA_WIDTH   - 1u)) - 1u) << 1u) + 1u)) << 0u)             |
                ((static_cast<unsigned char>(is_signed<base>::value)  & ((((1u << (SIGNEDNESS_WIDTH - 1u)) - 1u) << 1u) + 1u)) << METADATA_WIDTH) |
                ((sizeof(base)                                        & ((((1u << (SIZE_WIDTH       - 1u)) - 1u) << 1u) + 1u)) << (METADATA_WIDTH + SIGNEDNESS_WIDTH))
              );
          };

          /* ... ->> Disambiguate underlying type of enumeration via overload resolution */
          constfunc(true) static byte (&(typeof)(bool           const) noexcept)[enumtypeinfo::encode<bool>          ::value];
          constfunc(true) static byte (&(typeof)(char           const) noexcept)[enumtypeinfo::encode<char>          ::value];
          constfunc(true) static byte (&(typeof)(int            const) noexcept)[enumtypeinfo::encode<int>           ::value];
          constfunc(true) static byte (&(typeof)(long           const) noexcept)[enumtypeinfo::encode<long>          ::value];
          constfunc(true) static byte (&(typeof)(short          const) noexcept)[enumtypeinfo::encode<short>         ::value];
          constfunc(true) static byte (&(typeof)(signed char    const) noexcept)[enumtypeinfo::encode<signed char>   ::value];
          constfunc(true) static byte (&(typeof)(unsigned       const) noexcept)[enumtypeinfo::encode<unsigned>      ::value];
          constfunc(true) static byte (&(typeof)(unsigned char  const) noexcept)[enumtypeinfo::encode<unsigned char> ::value];
          constfunc(true) static byte (&(typeof)(unsigned long  const) noexcept)[enumtypeinfo::encode<unsigned long> ::value];
          constfunc(true) static byte (&(typeof)(unsigned short const) noexcept)[enumtypeinfo::encode<unsigned short>::value];
          constfunc(true) static byte (&(typeof)(wchar_t        const) noexcept)[enumtypeinfo::encode<wchar_t>       ::value];
          #if CPP_VERSION >= 2011uL
            constfunc(true) static byte (&(typeof)(long long          const) noexcept)[enumtypeinfo::encode<long long>         ::value];
            constfunc(true) static byte (&(typeof)(unsigned long long const) noexcept)[enumtypeinfo::encode<unsigned long long>::value];
          #endif
          #ifdef __cpp_char8_t // --> 201811L
            constfunc(true) static byte (&(typeof)(char8_t const) noexcept)[enumtypeinfo::encode<char8_t>::value];
          #endif
          #ifdef __cpp_lib_byte // --> 201603L
            constfunc(true) static byte (&(typeof)(std::byte const) noexcept)[enumtypeinfo::encode<std::byte>::value];
          #endif
          #ifdef __cpp_unicode_characters // --> 200704L
            constfunc(true) static byte (&(typeof)(char16_t const) noexcept)[enumtypeinfo::encode<char16_t>::value];
            constfunc(true) static byte (&(typeof)(char32_t const) noexcept)[enumtypeinfo::encode<char32_t>::value];
          #endif
          #ifdef int128_t
            constfunc(true) static byte (&(typeof)(int128_t const) noexcept)[enumtypeinfo::encode<int128_t>::value];
          #endif
          #ifdef uint128_t
            constfunc(true) static byte (&(typeof)(uint128_t const) noexcept)[enumtypeinfo::encode<uint128_t>::value];
          #endif
          constfunc(true) static byte (&(typeof)(...) noexcept)[enumtypeinfo::encode<uintmax_t>::value + 1u];
      };

      template <typename base>
      struct enuminfo final {
        typedef typename enumtypeinfo::template decode<sizeof((enumtypeinfo::typeof)(instanceof<base>())) / sizeof(byte)>::type type;
        static bool const value =
          #if CPP_VERSION >= 2011uL
            std::is_enum<base>::value or
          #elif CPP_COMPILER == CPP_MSVC_COMPILER
            __is_enum(base) or
          #elif CPP_COMPILER == CPP_CIRCLE_COMPILER || CPP_COMPILER == CPP_CLANG_COMPILER || CPP_COMPILER == CPP_GNUC_COMPILER || CPP_COMPILER == CPP_INTEL_COMPILER || CPP_COMPILER == CPP_LLVM_COMPILER || CPP_COMPILER == CPP_NVCC_COMPILER
          # ifdef __has_builtin // --> `__is_enum(...)` may still exist otherwise
          #   if __has_builtin(__is_enum)
                __is_enum(base) or
          #   endif
          # endif
          #endif
        not (classinfo<base>::value or is_integer<base, true>::value);
      };

      // ... ->> Fastest floating-point type with at least specified size
      template <std::size_t size>
      struct float_fast_t final {
        typedef typename float_fast_width_t<CHAR_BIT * size>::type type;
      };

      // ... ->> Fastest floating-point type with at least specified bit width
      template <std::size_t width>
      struct float_fast_width_t final {
        typedef typename conditional<
          width <= widthof(double()), double, // ->> Assume a `double` is the "fastest" type
          typename float_least_width_t<width>::type
        >::type type;
      };

      // ... ->> Smallest floating-point type with at least specified size
      template <std::size_t size>
      struct float_least_t final {
        typedef typename float_least_width_t<CHAR_BIT * size>::type type;
      };

      // ... ->> Smallest floating-point type with at least specified bit width
      template <std::size_t width>
      struct float_least_width_t final {
        typedef
          typename conditional<width <= widthof(static_cast<float>      (0.0)), float,
          typename conditional<width <= widthof(static_cast<double>     (0.0)), double,
          typename conditional<width <= widthof(static_cast<long double>(0.0)), long double,
          #ifndef float16_t
            void
          #else
            typename conditional<width <= widthof(static_cast<float16_t>(0.0)), float16_t,
            #ifndef float32_t
              void
            #else
              typename conditional<width <= widthof(static_cast<float32_t>(0.0)), float32_t,
              #ifndef float64_t
                void
              #else
                typename conditional<width <= widthof(static_cast<float64_t>(0.0)), float64_t,
                #ifndef float128_t
                  void
                #else
                  typename conditional<width <= widthof(static_cast<float128_t>(0.0)), float128_t, void>::type
                #endif
                >::type
              #endif
              >::type
            #endif
            >::type
          #endif
          >::type>::type>::type
        type;
      };

      // ... ->> Floating-point type of exact specified size
      template <std::size_t size>
      struct float_t final {
        typedef typename float_width_t<CHAR_BIT * size>::type type;
      };

      // ... ->> Floating-point type of exact specified bit width
      template <std::size_t width>
      struct float_width_t final {
        private:
          template <typename base, bool = is_same<base, void>::value>
          struct valueof final {
            typedef typename conditional<width == widthof(static_cast<base>(0.0)), base, void>::type type;
          };

          template <typename base>
          struct valueof<base, true> final {
            typedef base type;
          };

        public:
          typedef typename valueof<typename float_least_width_t<width>::type>::type type;
      };

      // ... ->> Fastest signed integer type with at least specified size
      template <std::size_t size>
      struct int_fast_t final {
        typedef typename int_fast_width_t<CHAR_BIT * size>::type type;
      };

      // ... ->> Fastest signed integer type with at least specified bit width
      template <std::size_t width>
      struct int_fast_width_t final {
        typedef typename signedof<typename uint_fast_width_t<width>::type>::type type;
      };

      // ... ->> Smallest signed integer type with at least specified size
      template <std::size_t size>
      struct int_least_t final {
        typedef typename int_least_width_t<CHAR_BIT * size>::type type;
      };

      // ... ->> Smallest signed integer type with at least specified bit width
      template <std::size_t width>
      struct int_least_width_t final {
        typedef typename signedof<typename uint_least_width_t<width>::type>::type type;
      };

      // ... ->> Signed integer type of exact specified size
      template <std::size_t size>
      struct int_t final {
        typedef typename int_width_t<CHAR_BIT * size>::type type;
      };

      // ... ->> Signed integer type of exact specified bit width
      template <std::size_t width>
      struct int_width_t final {
        typedef typename signedof<typename uint_width_t<width>::type>::type type;
      };

      // ... ->> Evaluates if type is a class or union type
      template <typename base>
      struct is_class final {
        static bool const value = classinfo<base>::value;
      };

      // ... ->> Evaluates if type is an enumeration type
      template <typename base>
      struct is_enum final {
        static bool const value = enuminfo<base>::value;
      };

      // ... ->> Evaluates if type is a class or union type
      template <typename base>
      struct is_final final {
        static bool const value = not is_class<base>::value or not classinfo<base>::derivable;
      };

      // ...
      template <typename>
      struct is_null final {
        static bool const value = false;
      };

      template <>
      struct is_null<null> final {
        static bool const value = true;
      };

      template <>
      struct is_null<null const> final {
        static bool const value = true;
      };

      template <>
      struct is_null<null const volatile> final {
        static bool const value = true;
      };

      template <>
      struct is_null<null volatile> final {
        static bool const value = true;
      };

      // ... ->> Type equality
      template <typename, typename>
      struct is_same final {
        static bool const value = false;
      };

      template <typename base>
      struct is_same<base, base> final {
        static bool const value = true;
      };

      // ... ->> Type (expression) similarity
      template <typename base>
      struct is_similar final {
        template <typename type>
        constfunc(true) static typename conditional<is_same<base const volatile, type const volatile>::value, boolean_true, boolean_false>::type (value)(type nodecay) noexcept;
      };

      template <typename base>
      struct is_similar<base&> final {
        template <typename type> constfunc(true) static typename conditional<is_same<base, type>               ::value, boolean_true, boolean_false>::type (value)(type&)                noexcept;
        template <typename type> constfunc(true) static typename conditional<is_same<base, type const>         ::value, boolean_true, boolean_false>::type (value)(type const&)          noexcept;
        template <typename type> constfunc(true) static typename conditional<is_same<base, type const volatile>::value, boolean_true, boolean_false>::type (value)(type const volatile&) noexcept;
        template <typename type> constfunc(true) static typename conditional<is_same<base, type       volatile>::value, boolean_true, boolean_false>::type (value)(type       volatile&) noexcept;
      };

      #ifdef __cpp_rvalue_references // --> 200610L
        template <typename base>
        struct is_similar<base&&> final {
          constfunc(true)                          static typename conditional<is_same<base, typename remove_const_volatile<base>::type>               ::value, boolean_true, boolean_false>::type (value)(typename remove_const_volatile<base>::type&&)                noexcept;
          constfunc(true)                          static typename conditional<is_same<base, typename remove_const_volatile<base>::type const>         ::value, boolean_true, boolean_false>::type (value)(typename remove_const_volatile<base>::type const&&)          noexcept;
          constfunc(true)                          static typename conditional<is_same<base, typename remove_const_volatile<base>::type const volatile>::value, boolean_true, boolean_false>::type (value)(typename remove_const_volatile<base>::type const volatile&&) noexcept;
          constfunc(true)                          static typename conditional<is_same<base, typename remove_const_volatile<base>::type       volatile>::value, boolean_true, boolean_false>::type (value)(typename remove_const_volatile<base>::type       volatile&&) noexcept;
          template <typename type> constfunc(true) static boolean_false                                                                                                                            (value)(type const volatile&)                                        noexcept;
        };
      #endif

      // ... ->> Evaluates if type is a union type
      template <typename base>
      struct is_union final {
        static bool const value = classinfo<base>::value and classinfo<base>::variant;
      };

      // ... ->> Type un-signedness
      template <typename>
      struct is_unsigned final {
        static bool const value = false;
      };

      template <>
      struct is_unsigned<unsigned char> final {
        static bool const value = true;
      };

      template <>
      struct is_unsigned<unsigned int> final {
        static bool const value = true;
      };

      template <>
      struct is_unsigned<unsigned long> final {
        static bool const value = true;
      };

      template <>
      struct is_unsigned<unsigned short> final {
        static bool const value = true;
      };

      #if CHAR_MIN - 0
      #else
        template <>
        struct is_unsigned<char> final {
          static bool const value = true;
        };
      #endif

      #if CPP_VERSION >= 2011uL
        template <>
        struct is_unsigned<unsigned long long> final {
          static bool const value = true;
        };
      #endif

      #ifdef uint128_t
        template <>
        struct is_unsigned<uint128_t> final {
          static bool const value = true;
        };
      #endif

      // ... ->> Type topmost const-qualifier removal
      template <typename base>
      struct remove_const final {
        typedef base type;
      };

      template <typename base>
      struct remove_const<base const> final {
        typedef base type;
      };

      // ... ->> Type topmost cv-qualifier removal
      template <typename base>
      struct remove_const_volatile final {
        typedef base type;
      };

      template <typename base>
      struct remove_const_volatile<base const> final {
        typedef base type;
      };

      template <typename base>
      struct remove_const_volatile<base const volatile> final {
        typedef base type;
      };

      template <typename base>
      struct remove_const_volatile<base volatile> final {
        typedef base type;
      };

      // ... ->> Type topmost volatile-qualifier removal
      template <typename base>
      struct remove_volatile final {
        typedef base type;
      };

      template <typename base>
      struct remove_volatile<base volatile> final {
        typedef base type;
      };

      // ... ->> Sign integer type
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

      // ... ->> Fastest unsigned integer type with at least specified size
      template <std::size_t size>
      struct uint_fast_t final {
        typedef typename uint_fast_width_t<CHAR_BIT * size>::type type;
      };

      // ... ->> Fastest unsigned integer type with at least specified bit width
      template <std::size_t width>
      struct uint_fast_width_t final {
        typedef
          typename conditional<width <= widthof(static_cast<uint_fast8_t> (0u)), uint_fast8_t,
          typename conditional<width <= widthof(static_cast<uint_fast16_t>(0u)), uint_fast16_t,
          typename conditional<width <= widthof(static_cast<uint_fast32_t>(0u)), uint_fast32_t,
          typename conditional<width <= widthof(static_cast<uint_fast64_t>(0u)), uint_fast64_t,
          typename conditional<width <= widthof(static_cast<unsigned>     (0u)), unsigned,
          #ifndef uint128_t
            void
          #else
            typename conditional<width <= widthof(static_cast<uint128_t>(0u)), uint128_t, void>::type
          #endif
          >::type>::type>::type>::type>::type
        type;
      };

      // ... ->> Smallest unsigned integer type with at least specified size
      template <std::size_t size>
      struct uint_least_t final {
        typedef typename uint_least_width_t<CHAR_BIT * size>::type type;
      };

      // ... ->> Smallest unsigned integer type with at least specified bit width
      template <std::size_t width>
      struct uint_least_width_t final {
        typedef
          typename conditional<width <= widthof(static_cast<unsigned char> (0u)), unsigned char,
          typename conditional<width <= widthof(static_cast<unsigned short>(0u)), unsigned short,
          typename conditional<width <= widthof(static_cast<unsigned int>  (0u)), unsigned int,
          typename conditional<width <= widthof(static_cast<unsigned long> (0u)), unsigned long,
          #if CPP_VERSION < 2011uL
            void
          #else
            typename conditional<width <= widthof(static_cast<unsigned long long>(0u)), unsigned long long,
            #ifndef uint128_t
              void
            #else
              typename conditional<width <= widthof(static_cast<uint128_t>(0u)), uint128_t, void>::type
            #endif
            >::type
          #endif
          >::type>::type>::type>::type
        type;
      };

      // ... ->> Unsigned integer type of exact specified size
      template <std::size_t size>
      struct uint_t final {
        typedef typename uint_width_t<CHAR_BIT * size>::type type;
      };

      // ... ->> Unsigned integer type of exact specified bit width
      template <std::size_t width>
      struct uint_width_t final {
        private:
          template <typename base, bool = is_same<base, void>::value>
          struct valueof final {
            typedef typename conditional<width == widthof(static_cast<base>(0u)), base, void>::type type;
          };

          template <typename base>
          struct valueof<base, true> final {
            typedef base type;
          };

        public:
          typedef typename valueof<typename uint_least_width_t<width>::type>::type type;
      };

      // ... ->> Unsign integer type
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
    }

    namespace Traits {
      // ... ->> Operation diagnostics
      struct opinfo final {
        struct membered final {};

        // ...
        struct nonmembered final {};

        // ...
        struct nonoverloaded final {};

        // ... ->> Dis-junction of `member` and `nonmember` traits
        struct overloaded final {};
      };

      // ...
      template <typename>
      struct maxof {};

      // ...
      template <typename>
      struct minof final {};

      // ...
      template <typename>
      struct nilof final {};

      /* Alias > ... */
      typedef float_fast_width_t <8u>  ::type                                 float_fast8_t;
      typedef float_fast_width_t <16u> ::type                                 float_fast16_t;
      typedef float_fast_width_t <32u> ::type                                 float_fast32_t;
      typedef float_fast_width_t <64u> ::type                                 float_fast64_t;
      typedef float_fast_width_t <128u>::type                                 float_fast128_t;
      typedef float_least_width_t<8u>  ::type                                 float_least8_t;
      typedef float_least_width_t<16u> ::type                                 float_least16_t;
      typedef float_least_width_t<32u> ::type                                 float_least32_t;
      typedef float_least_width_t<64u> ::type                                 float_least64_t;
      typedef float_least_width_t<128u>::type                                 float_least128_t;
      typedef float_least_width_t<widthof(static_cast<void*>(nullptr))>::type floatptr_t;

      #ifdef float16_t
        typedef conditional<sizeof(float) <= sizeof(float16_t), float, float16_t>::type floatmin_t;
      #else
        typedef float_width_t<16u>::type float16_t;
        typedef float                    floatmin_t;
      #endif

      #ifndef float32_t
        typedef float_width_t<32u>::type float32_t;
      #endif

      #ifndef float64_t
        typedef float_width_t<64u>::type float64_t;
      #endif

      #ifndef float128_t
        typedef float_width_t<128u>::type float128_t;
      #endif

      typedef
        conditional<not is_same<float_least128_t, void>::value, float_least128_t,
        conditional<not is_same<float_least64_t,  void>::value, float_least64_t,
        conditional<not is_same<float_least32_t,  void>::value, float_least32_t,
        conditional<not is_same<float_least16_t,  void>::value, float_least16_t,
        conditional<not is_same<float_least8_t,   void>::value, float_least8_t,
          void
        >::type>::type>::type>::type>::type
      floatmax_t;

      // ...
      typedef uint_fast8_t                                                   uint_fast8_t;
      typedef uint_fast16_t                                                  uint_fast16_t;
      typedef uint_fast32_t                                                  uint_fast32_t;
      typedef uint_fast64_t                                                  uint_fast64_t;
      typedef uint_fast_width_t <128u>::type                                 uint_fast128_t;
      typedef uint_least_width_t<8u>  ::type                                 uint_least8_t;
      typedef uint_least_width_t<16u> ::type                                 uint_least16_t;
      typedef uint_least_width_t<32u> ::type                                 uint_least32_t;
      typedef uint_least_width_t<64u> ::type                                 uint_least64_t;
      typedef uint_least_width_t<128u>::type                                 uint_least128_t;
      typedef uint_width_t      <8u>  ::type                                 uint8_t;
      typedef uint_width_t      <16u> ::type                                 uint16_t;
      typedef uint_width_t      <32u> ::type                                 uint32_t;
      typedef uint_width_t      <64u> ::type                                 uint64_t;
      typedef unsigned char                                                  uintmin_t;
      typedef uint_least_width_t<widthof(static_cast<void*>(nullptr))>::type uintptr_t;

      #ifndef uint128_t
        typedef uint_width_t<128u>::type uint128_t;
      #endif

      typedef
        conditional<not is_same<uint_least128_t, void>::value, uint_least128_t,
        conditional<not is_same<uint_least64_t,  void>::value, uint_least64_t,
        conditional<not is_same<uint_least32_t,  void>::value, uint_least32_t,
        conditional<not is_same<uint_least16_t,  void>::value, uint_least16_t,
        conditional<not is_same<uint_least8_t,   void>::value, uint_least8_t,
          void
        >::type>::type>::type>::type>::type
      uintmax_t;

      // ...
      typedef signedof<uint_fast8_t>   ::type int_fast8_t;
      typedef signedof<uint_fast16_t>  ::type int_fast16_t;
      typedef signedof<uint_fast32_t>  ::type int_fast32_t;
      typedef signedof<uint_fast64_t>  ::type int_fast64_t;
      typedef signedof<uint_fast128_t> ::type int_fast128_t;
      typedef signedof<uint_least8_t>  ::type int_least8_t;
      typedef signedof<uint_least16_t> ::type int_least16_t;
      typedef signedof<uint_least32_t> ::type int_least32_t;
      typedef signedof<uint_least64_t> ::type int_least64_t;
      typedef signedof<uint_least128_t>::type int_least128_t;
      typedef signedof<uint8_t>        ::type int8_t;
      typedef signedof<uint16_t>       ::type int16_t;
      typedef signedof<uint32_t>       ::type int32_t;
      typedef signedof<uint64_t>       ::type int64_t;
      typedef signedof<uintmax_t>      ::type intmax_t;
      typedef signedof<uintmin_t>      ::type intmin_t;
      typedef signedof<uintptr_t>      ::type intptr_t;

      #ifndef int128_t
        typedef signedof<uint128_t>::type int128_t;
      #endif

      /* Class > Bit */
      template <std::size_t width>
      struct bit final {
        private:
          typename uint_least_width_t<width>::type value : width;

        public:
      };

      template <>
      struct bit<0u> final {
        constfunc(true) bit(uintmin_t const) noexcept discard;

        /* ... --- TODO (Lapys) */
        // template <typename type> constfunc(true) bit         & operator =(type nodecay)         & noexcept discard { typedef constant<bool, 0u == sizeof(defer::template type<type>)> invalid_assignment; static_assert(invalid_assignment::value, "Assignment of empty type `bit<0zu>`"); return *this; }
        // template <typename type> constfunc(true) bit volatile& operator =(type nodecay) volatile& noexcept discard { typedef constant<bool, 0u == sizeof(defer::template type<type>)> invalid_assignment; static_assert(invalid_assignment::value, "Assignment of empty type `bit<0zu>`"); return *this; }
        // template <typename type> constfunc(true) friend bit         & operator  +=(bit&,          type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit volatile& operator  +=(bit volatile&, type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit         & operator  -=(bit&,          type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit volatile& operator  -=(bit volatile&, type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit         & operator  *=(bit&,          type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit volatile& operator  *=(bit volatile&, type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit         & operator  /=(bit&,          type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit volatile& operator  /=(bit volatile&, type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit         & operator  %=(bit&,          type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit volatile& operator  %=(bit volatile&, type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit         & operator  &=(bit&,          type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit volatile& operator  &=(bit volatile&, type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit         & operator  |=(bit&,          type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit volatile& operator  |=(bit volatile&, type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit         & operator  ^=(bit&,          type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit volatile& operator  ^=(bit volatile&, type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit         & operator <<=(bit&,          type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit volatile& operator <<=(bit volatile&, type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit         & operator >>=(bit&,          type nodecay) noexcept discard;
        // template <typename type> constfunc(true) friend bit volatile& operator >>=(bit volatile&, type nodecay) noexcept discard;

        constfunc(true) operator uintmin_t() const noexcept discard;
      };
    }

  //   namespace Traits {
  //     // ... ->> For configurable function code paths (eg: `Memory::allocate(...)`, ...) or generic data structures (eg: `Array`, ...)
  //     intenum(uint_least16_t, control_parameter) {
  //       DYNAMIC     = 0x0000u,
  //       HEAP        = 0x0000u,

  //       AUTOMATIC   = 0x0001u,
  //       BUFFERED    = 0x0002u,
  //       CLEARED     = 0x0004u,
  //       EXECUTABLE  = 0x0008u,
  //       MAXIMUM     = 0xF000u,
  //       NON_DYNAMIC = 0x0010u,
  //       STACK       = 0x0020u,
  //       VIEWABLE    = 0x0040u
  //     };
  //   }

  //   /* Definition */
  //   // ...
  //   #define as as_operator
  //   # define as_operator(object) as(object)

  //   /* Function */
  //   // As ->> Permissibly converts between types; amalgam of `reinterpret_cast`, `static_cast`, and `std::bit_cast<>`
  //   template <typename typeA, typename typeB>
  //   constfunc(true) typename conditional<opinfo::template cast<typeB nodecay, typeA>::value && not (is_array<typeA>::value || is_function<typeA>::value || is_void<typeA>::value), typeA>::type as(typeB nodecay object) noexcept {
  //     return (typeA) pass<typeB>(object);
  //   }

  //   template <typename typeA, typename typeB>
  //   constfunc(true) typename conditional<not opinfo::template cast<typeB nodecay, typeA>::value && not (is_array<typeA>::value || is_function<typeA>::value || is_void<typeA>::value), typeA>::type as(typeB nodecay object) noexcept {
  //     return (typeA&) object;
  //   }

  //   template <typename typeA, typename typeB> // ->> Conversion to bounded array type yields a temporary array reference
  //   constfunc(true) typename conditional<is_bound_array<typeA>::value && not (
  //     is_integer<typename subbaseof<typeA>::type>::value &&
  //     (is_integer<typeB>::value || (is_bound_array<typeB>::value && is_integer<typename subbaseof<typeB>::type>::value))
  //   ), typeA rlref>::type as(
  //     typeB nodecay object,
  //     typeA &       array = Array<typename baseof<typeA>::type, lengthof<typeA>::value>().valueOf()
  //   ) noexcept; // ->> Construction of `array` from `reinterpret_cast`

  //   template <typename typeA, typename typeB> // ->> Conversion to bounded byte array type yields a temporary array reference
  //   constfunc(true) typename conditional<is_bound_array<typeA>::value && (
  //     is_byte<typename subbaseof<typeA>::type>::value &&
  //     not (is_integer<typeB>::value || (is_bound_array<typeB>::value && is_integer<typename subbaseof<typeB>::type>::value))
  //   ), typeA rlref>::type as(
  //     typeB nodecay object,
  //     typeA &       array = Array<typename baseof<typeA>::type, lengthof<typeA>::value>().valueOf()
  //   ) noexcept; // --> std::memcpy(...)

  //   template <typename typeA, typename typeB> // ->> Conversion to bounded integer-base array type from integer-base object yields a temporary array reference
  //   constfunc(true) typename conditional<is_bound_array<typeA>::value && (
  //     is_integer<typename subbaseof<typeA>::type>::value &&
  //     (is_integer<typeB>::value || (is_bound_array<typeB>::value && is_integer<typename subbaseof<typeB>::type>::value))
  //   ), typeA rlref>::type as(
  //     typeB nodecay object,
  //     typeA &       array = Array<typename baseof<typeA>::type, lengthof<typeA>::value>().valueOf()
  //   ) noexcept; // ->> Manual endian-cognizant bit twiddling

  //   template <typename typeA, typename typeB> // ->> Conversion to unbounded array type yields a temporary array reference
  //   constfunc(true) typename conditional<is_unbound_array<typeA>::value && (
  //     is_complete<typeB>::value
  //   ), typeA rlref>::type as(
  //     typeB nodecay                  object,
  //     typename baseof<typeA>::type (&array)[(sizeof(typeB) / sizeof(typename subbaseof<typeA>::type)) + (0u != sizeof(typeB) % sizeof(typename subbaseof<typeA>::type))] = Array<typename baseof<typeA>::type, (sizeof(typeB) / sizeof(typename subbaseof<typeA>::type)) + (0u != sizeof(typeB) % sizeof(typename subbaseof<typeA>::type))>().valueOf()
  //   ) noexcept {
  //     return static_cast<typeA rlref>(as<typename baseof<typeA>::type[(sizeof(typeB) / sizeof(typename subbaseof<typeA>::type)) + (0u != sizeof(typeB) % sizeof(typename subbaseof<typeA>::type))]>(object, array));
  //   }

  //   template <typename typeA, typename typeB> // ->> Conversion to unbounded array type from incomplete object yields a temporary array reference
  //   constfunc(true) typename conditional<is_unbound_array<typeA>::value && (
  //     not is_complete<typeB>::value &&
  //   ), typeA rlref>::type as(typeB nodecay) noexcept {
  //     typedef constant<bool, 0u == sizeof(typename subbaseof<typeA>::type)> invalid_cast;
  //     static_assert(invalid_cast::value, "Unable to `cast(...)` from an incomplete object to an unbounded array");

  //     return instanceof<typeA>();
  //   }

  //   template <typename typeA, typename typeB> // ->> Conversion to function type from function pointer/ reference yields a wrapper function reference
  //   constfunc(true) typename conditional<is_function<typeA>::value && (
  //     is_function<typename subbaseof<typeB>::type>::value
  //   ), typeA rlref>::type as(typeB nodecay object) noexcept {
  //     return Function<typeA>(object).valueOf();
  //   }

  //   template <typename typeA, typename typeB> // ->> Conversion to function type from non-function object yields a non-executable function reference
  //   constfunc(true) typename conditional<is_function<typeA>::value && (
  //     not is_function<typename subbaseof<typeB>::type>::value &&
  //     false != is_complete<typeB>::value && false != (is_bound_array<typeB>::value && is_byte<typename baseof<typeB>::type>::value)
  //   ), typeA rlref>::type as(typeB nodecay object) noexcept {
  //     return Function<typeA>(as<char[sizeof(typeB)]>(object)).valueOf();
  //   }

  //   template <typename typeA, typename typeB>
  //   constfunc(true) typename conditional<is_function<typeA>::value && (
  //     not is_function<typename subbaseof<typeB>::type>::value &&
  //     false != is_complete<typeB>::value && false == (is_bound_array<typeB>::value && is_byte<typename baseof<typeB>::type>::value)
  //   ), typeA rlref>::type as(typeB nodecay object) noexcept {
  //     return as<typeA>(as<unsigned char[sizeof(typeB)]>(object));
  //   }

  //   template <typename typeA, typename typeB> // ->> Conversion to function type from incomplete non-function object yields a non-defined (or mostly ill-formed) function reference
  //   constfunc(true) typename conditional<is_function<typeA>::value && (
  //     not is_function<typename subbaseof<typeB>::type>::value &&
  //     false == is_complete<typeB>::value && false == (is_bound_array<typeB>::value && is_byte<typename baseof<typeB>::type>::value)
  //   ), typeA rlref>::type as(typeB nodecay) noexcept {
  //     return Function<typeA>(nullptr).valueOf();
  //   }

  //   template <typename typeA, typename typeB> // ->> Conversion to void type does nothing; unfortunately not constant evaluable with stricter `constexpr`
  //   constfunc(false) typename conditional<is_void<typeA>::value, void>::type>::type as(typeB nodecay) noexcept {}
  }

  // Current Goals
  // • Ensure `apply(…)` macro works as intended
  // • Ensure `CPP_ENDIAN` works validly with `as` (does it need `std::memcpy(...)`?)
  // • Provide declarations for traits used here (such as `opinfo::cast<>`)
  //
  // Design Goals
  // • Auto-diagnose memory allocations with `__FILE__` and `__LINE__` (and optionally `__COUNTER__`) via macros
  // • Beware of `SIZE_MAX` (or such) for bounded ranges, such as the ones for memory allocators
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
  //   ⚬ image parsing, (APNG, AVIF, GIF, JPEG, PNG, SVG, WEBP)
  //   ⚬ internationalization/ locale,
  //   ⚬ math.,
  //   ⚬ memory management, (fixed-size allocations are sorted in buckets, not generalized; `Memory::allocate(…)` evaluates to `class MemoryBuffer` which decays to a pointer — there´s also `Memory::instantiate<>(…)`; `Memory::allocate(…)` may also allocate from "memory-mapped" files)
  //       Page align for bigger allocation blocks,
  //       C++ `std::aligned_alloc(…)`,
  //       MSVC `_aligned_malloc(…)` (used with `_aligned_free(…)` instead), and
  //       POSIX `posix_memalign(…)`
  //       WinAPI `VirtualAlloc2(…)`
  //
  //       `std::align(…)`, or otherwise manually align for `alignof T < alignof max_align_t`
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
