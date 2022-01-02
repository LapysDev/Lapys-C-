/* ... */
namespace Lapys {
  /* Definition > ... */
  #if CPP_VERSION < 2017uL
    #if CPP_VERSION < 2011uL
      union byte {
        private:
          unsigned char value : CHAR_BIT;

        public:
          inline byte() throw() : value() {}
          inline byte(unsigned char const value) throw() : value(value) {}

          // ...
          inline operator unsigned char() const throw() {
            return this -> value;
          }
      };
    #else
      enum byte : unsigned char {};
    #endif

    constfunc(true) inline byte operator +(byte const byte) noexcept { return static_cast<Lapys::byte>(+static_cast<unsigned char>(byte)); }
    constfunc(true) inline byte operator !(byte const byte) noexcept { return static_cast<Lapys::byte>(!static_cast<unsigned char>(byte)); }
    constfunc(true) inline byte operator ~(byte const byte) noexcept { return static_cast<Lapys::byte>(~static_cast<unsigned char>(byte)); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, byte>::type operator &(byte const byte, type const integer) noexcept { return static_cast<Lapys::byte>(static_cast<unsigned char>(byte) & integer); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, type>::type operator &(type const integer, byte const byte) noexcept { return static_cast<Lapys::byte>(integer & static_cast<unsigned char>(byte)); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, byte>::type operator |(byte const byte, type const integer) noexcept { return static_cast<Lapys::byte>(static_cast<unsigned char>(byte) | integer); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, type>::type operator |(type const integer, byte const byte) noexcept { return static_cast<Lapys::byte>(integer | static_cast<unsigned char>(byte)); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, byte>::type operator ^(byte const byte, type const integer) noexcept { return static_cast<Lapys::byte>(static_cast<unsigned char>(byte) ^ integer); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, type>::type operator ^(type const integer, byte const byte) noexcept { return static_cast<Lapys::byte>(integer ^ static_cast<unsigned char>(byte)); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, byte>::type operator <<(byte const base, type const shift) noexcept { return static_cast<byte>(static_cast<unsigned char>(base) << shift); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, type>::type operator <<(type const base, byte const shift) noexcept { return static_cast<byte>(base << static_cast<unsigned char>(shift)); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, byte>::type operator >>(byte const base, type const shift) noexcept { return static_cast<byte>(static_cast<unsigned char>(base) >> shift); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, type>::type operator >>(type const base, byte const shift) noexcept { return static_cast<byte>(base >> static_cast<unsigned char>(shift)); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, bool>::type operator ==(byte const byte, type const integer) noexcept { return static_cast<unsigned char>(byte) == integer; }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, bool>::type operator ==(type const integer, byte const byte) noexcept { return integer == static_cast<unsigned char>(byte); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, bool>::type operator !=(byte const byte, type const integer) noexcept { return static_cast<unsigned char>(byte) != integer; }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, bool>::type operator !=(type const integer, byte const byte) noexcept { return integer != static_cast<unsigned char>(byte); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, bool>::type operator < (byte const byte, type const integer) noexcept { return static_cast<unsigned char>(byte) < integer; }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, bool>::type operator < (type const integer, byte const byte) noexcept { return integer < static_cast<unsigned char>(byte); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, bool>::type operator > (byte const byte, type const integer) noexcept { return static_cast<unsigned char>(byte) > integer; }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, bool>::type operator > (type const integer, byte const byte) noexcept { return integer > static_cast<unsigned char>(byte); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, bool>::type operator <=(byte const byte, type const integer) noexcept { return static_cast<unsigned char>(byte) <= integer; }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, bool>::type operator <=(type const integer, byte const byte) noexcept { return integer <= static_cast<unsigned char>(byte); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, bool>::type operator >=(byte const byte, type const integer) noexcept { return static_cast<unsigned char>(byte) >= integer; }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, bool>::type operator >=(type const integer, byte const byte) noexcept { return integer >= static_cast<unsigned char>(byte); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, byte&>::type operator &=(byte& byte, type const integer) noexcept { return (byte    = byte & integer); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, type&>::type operator &=(type& integer, byte const byte) noexcept { return (integer = integer & byte); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, byte&>::type operator |=(byte& byte, type const integer) noexcept { return (byte    = byte | integer); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, type&>::type operator |=(type& integer, byte const byte) noexcept { return (integer = integer | byte); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, byte&>::type operator ^=(byte& byte, type const integer) noexcept { return (byte    = byte ^ integer); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, type&>::type operator ^=(type& integer, byte const byte) noexcept { return (integer = integer ^ byte); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, byte&>::type operator <<=(byte& base, type const shift) noexcept { return (base = base << shift); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, type&>::type operator <<=(type& base, byte const shift) noexcept { return (base = base << shift); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, byte&>::type operator >>=(byte& base, type const shift) noexcept { return (base = base >> shift); }
    template <typename type> constfunc(true) inline typename conditional<is_integral<type>::value, type&>::type operator >>=(type& base, byte const shift) noexcept { return (base = base >> shift); }
  #else
    typedef std::byte byte;
  #endif

  /* Function > ... */
  #if CPP_VERSION < 2011uL
    template <typename type>
    type& forward(type&       object) throw() {
      return object;
    }

    template <typename type>
    type const& forward(type const& object) throw() {
      return object;
    }
  #else
    template <typename type>
    constexpr type&& forward(typename Traits::remove_reference<type>::type& object) noexcept {
      return static_cast<type&&>(object);
    }

    template <typename type>
    constexpr type&& forward(typename Traits::remove_reference<type>::type&& object) noexcept {
      return static_cast<type&&>(object);
    }
  #endif

  // ...
  #if CPP_VERSION < 2011uL
    template <typename type>
    type instanceof() throw();
  #else
    template <typename type>
    constexpr type&& instanceof() noexcept;
  #endif

  // ...
  #if defined(__cpp_lib_launder) || (CPP_COMPILER == CPP__MSVC__COMPILER && defined(_HAS_LAUNDER)) || CPP_VERSION >= 2017uL
    using std::launder;
  #else
    template <typename type>
    inline type* launder(type* pointer) noexcept {
      #if CPP_COMPILER == CPP__CLANG__COMPILER || (CPP_COMPILER == CPP__GCC__COMPILER && defined(__has_builtin))
      # if __has_builtin(__builtin_launder)
        return __builtin_launder(pointer);
      # else
        return pointer;
      # endif
      #elif CPP_COMPILER == CPP__GCC__COMPILER
        // ->> Force compiler to assume `pointer` was modified because it is used as an input & output.
        __asm__("" : "+r"(pointer));
        return pointer;
      #elif CPP_COMPILER == CPP__MSVC__COMPILER && CPP_VENDOR == CPP__MICROSOFT_WINDOWS__VENDOR && defined(_ReadWriteBarrier)
        // ->> Prevent memory access re-ordering (relies on MSVC not having optimizations for `const` data members)
        _ReadWriteBarrier();
        return pointer;
      #else
        return pointer;
      #endif
    }
  #endif
}
