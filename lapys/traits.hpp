#if CPP_COMPILER == CPP__CLANG__COMPILER
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wlong-long"
#elif CPP_COMPILER == CPP__GCC__COMPILER
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wlong-long"
#endif
  /* Import > C++ Standard Library */
  #if CPP_VERSION >= 2011uL
  # include <type_traits> // Type Traits
  #endif
  #if CPP_VERSION >= 2020uL
  # include <compare> // Compare
  #endif

  /* Namespace ->> All traits should be `struct final`, everything else a `union` */
  namespace Lapys {
    /* Function > Forward */
    #ifdef __cpp_rvalue_references
      template <typename type> constfunc(true) inline type&& forward(type&  object) noexcept { return static_cast<type&&>(object); }
      template <typename type> constfunc(true) inline type&& forward(type&& object) noexcept { return static_cast<type&&>(object); }
    #else
      template <typename type> constfunc(true) inline type&                forward(type&                object) noexcept { return static_cast<type&>               (object); }
      template <typename type> constfunc(true) inline type const&          forward(type const&          object) noexcept { return static_cast<type const&>         (object); }
      template <typename type> constfunc(true) inline type const volatile& forward(type const volatile& object) noexcept { return static_cast<type const volatile&>(object); }
      template <typename type> constfunc(true) inline type volatile&       forward(type volatile&       object) noexcept { return static_cast<type volatile&>      (object); }
    #endif

    /* Class > Byte */
    #if CPP_VERSION < 2011uL
      union alignmentas(sizeof(unsigned char)) byte {
        private:
          unsigned char value;

        public:
          constfunc(true) inline byte() noexcept : value() {}
          constfunc(true) inline byte(unsigned char const value) noexcept : value(value) {}

          constfunc(true) inline operator unsigned char() const volatile noexcept { return this -> value; }
      };
    #else
      enum class byte : unsigned char {};
    #endif
      // ... ->> Accessible conversion to integral scalar type; makes aliasing `std::byte` infeasible.
      constfunc(true) inline unsigned char operator +(byte const byte) noexcept { return static_cast<unsigned char>(byte); }

      // ...
      constfunc(true) inline byte operator ~(byte const byte) noexcept { return Lapys::byte(~static_cast<unsigned char>(byte)); }

      constfunc(true) inline byte operator &(byte const byteA, byte const byteB) noexcept { return byte(static_cast<unsigned char>(byteA) & static_cast<unsigned char>(byteB)); }
      template <typename type> constfunc(true) inline byte operator &(byte const byte, type nodecay object) noexcept { return Lapys::byte(static_cast<unsigned char>(byte) & static_cast<unsigned char>(static_cast<type nodecay>(object))); }
      template <typename type> constfunc(true) inline byte operator &(type nodecay object, byte const byte) noexcept { return Lapys::byte(static_cast<unsigned char>(static_cast<type nodecay>(object)) & static_cast<unsigned char>(byte)); }

      constfunc(true) inline byte operator |(byte const byteA, byte const byteB) noexcept { return byte(static_cast<unsigned char>(byteA) | static_cast<unsigned char>(byteB)); }
      template <typename type> constfunc(true) inline byte operator |(byte const byte, type nodecay object) noexcept { return Lapys::byte(static_cast<unsigned char>(byte) | static_cast<unsigned char>(static_cast<type nodecay>(object))); }
      template <typename type> constfunc(true) inline byte operator |(type nodecay object, byte const byte) noexcept { return Lapys::byte(static_cast<unsigned char>(static_cast<type nodecay>(object)) | static_cast<unsigned char>(byte)); }

      constfunc(true) inline byte operator ^(byte const byteA, byte const byteB) noexcept { return byte(static_cast<unsigned char>(byteA) ^ static_cast<unsigned char>(byteB)); }
      template <typename type> constfunc(true) inline byte operator ^(byte const byte, type nodecay object) noexcept { return Lapys::byte(static_cast<unsigned char>(byte) ^ static_cast<unsigned char>(static_cast<type nodecay>(object))); }
      template <typename type> constfunc(true) inline byte operator ^(type nodecay object, byte const byte) noexcept { return Lapys::byte(static_cast<unsigned char>(static_cast<type nodecay>(object)) ^ static_cast<unsigned char>(byte)); }

      constfunc(true) inline byte operator <<(byte const byteA, byte const byteB) noexcept { return byte(static_cast<unsigned char>(byteA) << static_cast<unsigned char>(byteB)); }
      template <typename type> constfunc(true) inline byte operator <<(byte const byte, type nodecay object) noexcept { return Lapys::byte(static_cast<unsigned char>(byte) << static_cast<unsigned char>(static_cast<type nodecay>(object))); }
      template <typename type> constfunc(true) inline byte operator <<(type nodecay object, byte const byte) noexcept { return Lapys::byte(static_cast<unsigned char>(static_cast<type nodecay>(object)) << static_cast<unsigned char>(byte)); }

      constfunc(true) inline byte operator >>(byte const byteA, byte const byteB) noexcept { return byte(static_cast<unsigned char>(byteA) >> static_cast<unsigned char>(byteB)); }
      template <typename type> constfunc(true) inline byte operator >>(byte const byte, type nodecay object) noexcept { return Lapys::byte(static_cast<unsigned char>(byte) >> static_cast<unsigned char>(static_cast<type nodecay>(object))); }
      template <typename type> constfunc(true) inline byte operator >>(type nodecay object, byte const byte) noexcept { return Lapys::byte(static_cast<unsigned char>(static_cast<type nodecay>(object)) >> static_cast<unsigned char>(byte)); }

      template <typename type> constfunc(true) inline byte&          operator &=(byte&          byte, type nodecay object) noexcept { return (byte = Lapys::byte(static_cast<unsigned char>(byte) & static_cast<type nodecay>(object))), byte; }
      template <typename type> constfunc(true) inline byte volatile& operator &=(byte volatile& byte, type nodecay object) noexcept { return (byte = Lapys::byte(static_cast<unsigned char>(byte) & static_cast<type nodecay>(object))), byte; }

      template <typename type> constfunc(true) inline byte&          operator |=(byte&          byte, type nodecay object) noexcept { return (byte = Lapys::byte(static_cast<unsigned char>(byte) | static_cast<type nodecay>(object))), byte; }
      template <typename type> constfunc(true) inline byte volatile& operator |=(byte volatile& byte, type nodecay object) noexcept { return (byte = Lapys::byte(static_cast<unsigned char>(byte) | static_cast<type nodecay>(object))), byte; }

      template <typename type> constfunc(true) inline byte&          operator ^=(byte&          byte, type nodecay object) noexcept { return (byte = Lapys::byte(static_cast<unsigned char>(byte) ^ static_cast<type nodecay>(object))), byte; }
      template <typename type> constfunc(true) inline byte volatile& operator ^=(byte volatile& byte, type nodecay object) noexcept { return (byte = Lapys::byte(static_cast<unsigned char>(byte) ^ static_cast<type nodecay>(object))), byte; }

      template <typename type> constfunc(true) inline byte&          operator <<=(byte&          byte, type nodecay object) noexcept { return (byte = Lapys::byte(static_cast<unsigned char>(byte) << static_cast<type nodecay>(object))), byte; }
      template <typename type> constfunc(true) inline byte volatile& operator <<=(byte volatile& byte, type nodecay object) noexcept { return (byte = Lapys::byte(static_cast<unsigned char>(byte) << static_cast<type nodecay>(object))), byte; }

      template <typename type> constfunc(true) inline byte&          operator >>=(byte&          byte, type nodecay object) noexcept { return (byte = Lapys::byte(static_cast<unsigned char>(byte) >> static_cast<type nodecay>(object))), byte; }
      template <typename type> constfunc(true) inline byte volatile& operator >>=(byte volatile& byte, type nodecay object) noexcept { return (byte = Lapys::byte(static_cast<unsigned char>(byte) >> static_cast<type nodecay>(object))), byte; }

    /* Definition > ... */
    template <std::size_t>
    struct bit;

    template <typename type>
    constfunc(true) inline type instanceof() noexcept;

    /* Namespace; Alias */
    namespace Traits {}
    using namespace Traits;
  }

  namespace Lapys {
    /* Namespace > Enumeration */
    namespace Traits {
      // ... ->> For configurable function code paths or generic data structures
      enum control_parameter {
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
        constfunc(true) inline control_parameter operator &(control_parameter const controlParameterA, control_parameter const controlParameterB) noexcept { return static_cast<control_parameter>(static_cast<unsigned>(controlParameterA) & static_cast<unsigned>(controlParameterB)); }
        constfunc(true) inline control_parameter operator |(control_parameter const controlParameterA, control_parameter const controlParameterB) noexcept { return static_cast<control_parameter>(static_cast<unsigned>(controlParameterA) | static_cast<unsigned>(controlParameterB)); }

      // ... ->> For compile-time conditional explicit type conversion --> bit_cast<...>
      enum conversion {
        addressable_cast = 0x1u,
        bitwise_cast,
        direct_cast,
        functional_cast,
        pointer_cast,
        scalar_cast,
        void_cast
      };

      // ... ->> For convenient inner-class partial template specialization --> template trait<enum dummy_parameter DUMMY>;
      enum dummy_parameter {
        DUMMY = 0x0000u
      };

      // ... ->> For SFINAE checks --> alias<null>
      union null {
        constfunc(true) null(...) noexcept {}

        template <typename type>
        constfunc(true) inline operator type() const noexcept {
          return instanceof<type>();
        }
      };

      // ... --> can_operate<enum operation, ...>
      enum operation {
        nop,

        assign,
        add,         assign_add,
        divide,      assign_divide,
        left_shift,  assign_left_shift,
        modulo,      assign_modulo,
        multiply,    assign_multiply,
        right_shift, assign_right_shift,
        subtract,    assign_subtract,

        bitwise_and, assign_bitwise_and,
        bitwise_or,  assign_bitwise_or,
        bitwise_xor, assign_bitwise_xor,

        boolean_and,
        boolean_or,

        equals,
        greater, equals_greater,
        lesser,  equals_lesser,
        compare,
        unequals,

        member_access,
        member_pointer_access,

        post_decrement,
        post_increment,
        pre_decrement,
        pre_increment,

        address,
        call,
        cast,
        comma,
        complement,
        dereference,
        negate,
        minus,
        plus,
        subscript
      };
    }

    /* Namespace > Definition --- NOTE (Lapys) -> Required to later define the `widthof<T, ...>` trait */
    namespace Traits {
      struct int_big_t;
      struct int_byte_t;
      struct int_maximum_t;
      struct int_minimum_t;
      struct int_null_t;
      struct int_pointer_t;
      struct uint_big_t;
      struct uint_byte_t;
      struct uint_maximum_t;
      struct uint_minimum_t;
      struct uint_null_t;
      struct uint_pointer_t;

      template <typename>                               struct assess_const;
      template <typename>                               struct assess_volatile;
      template <bool, typename = null, typename = null> struct conditional;
      template <std::size_t, class = int_minimum_t>     struct int_least_t;
      template <std::size_t, class = int_minimum_t>     struct int_least_width_t;
      template <typename>                               struct int_next_t;
      template <typename>                               struct int_previous_t;
      template <std::size_t, class = int_minimum_t>     struct int_t;
      template <std::size_t, class = int_minimum_t>     struct int_width_t;
      template <typename>                               struct is_bit;
      template <typename, typename>                     struct is_same;
      template <typename>                               struct remove_const;
      template <typename>                               struct remove_qualifiers;
      template <typename>                               struct remove_volatile;
      template <std::size_t, class = uint_minimum_t>    struct uint_least_t;
      template <std::size_t, class = uint_minimum_t>    struct uint_least_width_t;
      template <typename>                               struct uint_next_t;
      template <typename>                               struct uint_previous_t;
      template <std::size_t, class = uint_minimum_t>    struct uint_t;
      template <std::size_t, class = uint_minimum_t>    struct uint_width_t;
    }

    /* Namespace > Trait */
    namespace Traits {
      template <typename type> struct assess_const             final { typedef type base; };
      template <typename type> struct assess_const<type const> final { typedef type base; };

      // ...
      template <typename type> struct assess_volatile                final { typedef type base; };
      template <typename type> struct assess_volatile<type volatile> final { typedef type base; };

      // ...
      template <> struct conditional<false> final {};
      template <> struct conditional<true>  final {};

      template <typename base> struct conditional<false, base> final {};
      template <typename base> struct conditional<true,  base> final { typedef base type; };

      template <typename baseA, typename baseB> struct conditional<false, baseA, baseB> final { typedef baseB type; };
      template <typename baseA, typename baseB> struct conditional<true,  baseA, baseB> final { typedef baseA type; };

      // ...
      struct int_big_t final {
        #ifdef int128_t
          typedef typename conditional<(sizeof(int128_t) > sizeof(intmax_t)), int128_t, intmax_t>::type type;
        #else
          typedef intmax_t type;
        #endif
      };

      // ...
      struct int_byte_t final {
        typedef signed char type;
      };

      // ...
      #if CPP_VERSION >= 2011uL || defined(ULLONG_MAX)
        struct int_maximum_t final { typedef signed long long type; };
      #else
        struct int_maximum_t final { typedef signed long type; };
      #endif

      // ...
      struct int_minimum_t final {
        typedef typename int_byte_t::type type;
      };

      // ...
      struct int_null_t final {
        typedef void type;
      };

      // ...
      template <std::size_t size> struct int_least_t<size, int_minimum_t>                             final { typedef typename conditional<size <= sizeof(typename int_minimum_t::type), typename int_minimum_t::type, typename int_least_t<size, int_next_t<typename int_minimum_t::type> >::type>::type type; };
      template <std::size_t size> struct int_least_t<size, int_next_t<typename int_maximum_t::type> > final { typedef typename int_least_width_t<CHAR_BIT * size>::type type; };
      template <std::size_t size, typename base> struct int_least_t<size, int_next_t<base> >          final { typedef typename conditional<size <= sizeof(typename int_next_t<base>::type), typename int_next_t<base>::type, typename int_least_t<size, int_next_t<typename int_next_t<base>::type> >::type>::type type; };

      // ...
      template <std::size_t width>
      struct int_least_width_t<width, int_minimum_t> final {
        private: typedef typename conditional<width <= CHAR_BIT * sizeof(typename int_minimum_t::type), typename int_minimum_t::type, typename int_least_width_t<width, int_next_t<typename int_minimum_t::type> >::type>::type int_scalar_t;
        public: typedef
          typename conditional<width <= CHAR_BIT, typename int_byte_t::type,
          typename conditional<width <= 8u,  int_least8_t,
          typename conditional<width <= 16u, int_least16_t,
          typename conditional<width <= 32u, int_least32_t,
          typename conditional<width <= 64u, int_least64_t,
            #ifdef int128_t
              typename conditional<(width <= 128u), int128_t, int_scalar_t>::type
            #else
              int_scalar_t
            #endif
          >::type>::type>::type>::type>::type
        type;
      };

      template <std::size_t width> struct int_least_width_t<width, int_next_t<typename int_maximum_t::type> > final { typedef typename int_null_t::type type; };
      template <std::size_t width, typename base> struct int_least_width_t<width, int_next_t<base> >          final { typedef typename conditional<width <= CHAR_BIT * sizeof(typename int_next_t<base>::type), typename int_next_t<base>::type, typename int_least_width_t<width, int_next_t<typename int_next_t<base>::type> >::type>::type type; };

      // ...
      template <> struct int_next_t<signed char>  final { typedef signed short type; };
      template <> struct int_next_t<signed short> final { typedef signed int   type; };
      template <> struct int_next_t<signed int>   final { typedef signed long  type; };

      #if CPP_VERSION >= 2011uL || defined(LLONG_MAX)
        template <> struct int_next_t<signed long>      final { typedef signed long long type; };
        template <> struct int_next_t<signed long long> final {};
      #else
        template <> struct int_next_t<signed long> final {};
      #endif

      // ...
      struct int_pointer_t final {
        #if defined(PRIdPTR) || defined(PRIiPTR) || defined(INTPTR_MAX) || defined(INTPTR_MIN) || defined(SCNdPTR) || defined(SCNiPTR)
          typedef intptr_t type;
        #else
          typedef typename conditional<(sizeof(void*) > sizeof(typename int_maximum_t::type)), typename int_big_t::type, typename int_maximum_t::type>::type type;
        #endif
      };

      // ...
      template <> struct int_previous_t<signed char>  final {};
      template <> struct int_previous_t<signed short> final { typedef signed char  type; };
      template <> struct int_previous_t<signed int>   final { typedef signed short type; };
      template <> struct int_previous_t<signed long>  final { typedef signed int   type; };

      #if CPP_VERSION >= 2011uL || defined(ULLONG_MAX)
        template <> struct int_previous_t<signed long long> final { typedef signed long type; };
      #endif

      // ...
      template <std::size_t size> struct int_t<size, int_minimum_t>                             final { typedef typename conditional<size == sizeof(typename int_minimum_t::type), typename int_minimum_t::type, typename int_t<size, int_next_t<typename int_minimum_t::type> >::type>::type type; };
      template <std::size_t size> struct int_t<size, int_next_t<typename int_maximum_t::type> > final { typedef typename int_null_t::type type; };
      template <std::size_t size, typename base> struct int_t<size, int_next_t<base> >          final { typedef typename conditional<size == sizeof(typename int_next_t<base>::type), typename int_next_t<base>::type, typename int_t<size, int_next_t<typename int_next_t<base>::type> >::type>::type type; };

      template <> struct int_t<1u> final { typedef typename int_byte_t::type type; };

      // ...
      template <std::size_t width> struct int_width_t<width, int_minimum_t>                             final { typedef typename conditional<width == CHAR_BIT * sizeof(typename int_minimum_t::type), typename int_minimum_t::type, typename int_width_t<width, int_next_t<typename int_minimum_t::type> >::type>::type type; };
      template <std::size_t width> struct int_width_t<width, int_next_t<typename int_maximum_t::type> > final { typedef typename int_null_t::type type; };
      template <std::size_t width, typename base> struct int_width_t<width, int_next_t<base> >          final { typedef typename conditional<width == CHAR_BIT * sizeof(typename int_next_t<base>::type), typename int_next_t<base>::type, typename int_width_t<width, int_next_t<typename int_next_t<base>::type> >::type>::type type; };

      template <> struct int_width_t<CHAR_BIT> final { typedef typename int_byte_t::type type; };

      #if CHAR_BIT != 8 && (defined(INT8_MAX) || defined(INT8_MIN))
        template <> struct int_width_t<8u> final { typedef int8_t type; };
      #endif

      #if CHAR_BIT != 16 && (defined(INT16_MAX) || defined(INT16_MIN))
        template <> struct int_width_t<16u> final { typedef int16_t type; };
      #endif

      #if CHAR_BIT != 32 && (defined(INT32_MAX) || defined(INT32_MIN))
        template <> struct int_width_t<32u> final { typedef int32_t type; };
      #endif

      #if CHAR_BIT != 64 && (defined(INT64_MAX) || defined(INT64_MIN))
        template <> struct int_width_t<64u> final { typedef int64_t type; };
      #endif

      #if CHAR_BIT != 128 && defined(int128_t)
        template <> struct int_width_t<128u> final { typedef int128_t type; };
      #endif

      // ...
      template <typename base>
      struct is_bit final {
        private:
          template <dummy_parameter, typename>
          struct valueof {
            friend struct is_bit<base>;
            private: static bool const value = false;
          };

          template <dummy_parameter dummy, std::size_t width>
          struct valueof<dummy, bit<width> > {
            friend struct is_bit<base>;
            private: static bool const value = true;
          };

        public:
          static bool const value = valueof<DUMMY, typename remove_qualifiers<base>::type>::value;
      };

      // ...
      template <typename, typename> struct is_same             final { static bool const value = false; };
      template <typename base>      struct is_same<base, base> final { static bool const value = true;  };

      // ...
      template <typename base>
      struct remove_const final {
        typedef typename assess_const<base>::base type;
      };

      // ...
      template <typename base>
      struct remove_qualifiers final {
        typedef typename remove_const<typename remove_volatile<base>::type>::type type;
      };

      // ...
      template <typename base>
      struct remove_volatile final {
        typedef typename assess_volatile<base>::base type;
      };

      // ...
      struct uint_big_t final {
        #ifdef uint128_t
          typedef typename conditional<(sizeof(uint128_t) > sizeof(uintmax_t)), uint128_t, uintmax_t>::type type;
        #else
          typedef uintmax_t type;
        #endif
      };

      // ...
      struct uint_byte_t final {
        typedef unsigned char type;
      };

      // ...
      #if CPP_VERSION >= 2011uL || defined(ULLONG_MAX)
        struct uint_maximum_t final { typedef unsigned long long type; };
      #else
        struct uint_maximum_t final { typedef unsigned long type; };
      #endif

      // ...
      struct uint_minimum_t final {
        typedef typename uint_byte_t::type type;
      };

      // ...
      struct uint_null_t final {
        typedef void type;
      };

      // ...
      template <std::size_t size> struct uint_least_t<size, uint_minimum_t>                              final { typedef typename conditional<size <= sizeof(typename uint_minimum_t::type), typename uint_minimum_t::type, typename uint_least_t<size, uint_next_t<typename uint_minimum_t::type> >::type>::type type; };
      template <std::size_t size> struct uint_least_t<size, uint_next_t<typename uint_maximum_t::type> > final { typedef typename uint_least_width_t<CHAR_BIT * size>::type type; };
      template <std::size_t size, typename base> struct uint_least_t<size, uint_next_t<base> >           final { typedef typename conditional<size <= sizeof(typename uint_next_t<base>::type), typename uint_next_t<base>::type, typename uint_least_t<size, uint_next_t<typename uint_next_t<base>::type> >::type>::type type; };

      // ...
      template <std::size_t width>
      struct uint_least_width_t<width, uint_minimum_t> final {
        private: typedef typename conditional<width <= CHAR_BIT * sizeof(typename uint_minimum_t::type), typename uint_minimum_t::type, typename uint_least_width_t<width, uint_next_t<typename uint_minimum_t::type> >::type>::type uint_scalar_t;
        public: typedef
          typename conditional<width <= CHAR_BIT, typename uint_byte_t::type,
          typename conditional<width <= 8u,  uint_least8_t,
          typename conditional<width <= 16u, uint_least16_t,
          typename conditional<width <= 32u, uint_least32_t,
          typename conditional<width <= 64u, uint_least64_t,
            #ifdef uint128_t
              typename conditional<(width <= 128u), uint128_t, uint_scalar_t>::type
            #else
              uint_scalar_t
            #endif
          >::type>::type>::type>::type>::type
        type;
      };

      template <std::size_t width> struct uint_least_width_t<width, uint_next_t<typename uint_maximum_t::type> > final { typedef typename uint_null_t::type type; };
      template <std::size_t width, typename base> struct uint_least_width_t<width, uint_next_t<base> >           final { typedef typename conditional<width <= CHAR_BIT * sizeof(typename uint_next_t<base>::type), typename uint_next_t<base>::type, typename uint_least_width_t<width, uint_next_t<typename uint_next_t<base>::type> >::type>::type type; };

      // ...
      template <> struct uint_next_t<unsigned char>  final { typedef unsigned short type; };
      template <> struct uint_next_t<unsigned short> final { typedef unsigned int   type; };
      template <> struct uint_next_t<unsigned int>   final { typedef unsigned long  type; };

      #if CPP_VERSION >= 2011uL || defined(LLONG_MAX)
        template <> struct uint_next_t<unsigned long>      final { typedef unsigned long long type; };
        template <> struct uint_next_t<unsigned long long> final {};
      #else
        template <> struct uint_next_t<unsigned long> final {};
      #endif

      // ...
      struct uint_pointer_t final {
        #if defined(PRIoPTR) || defined(PRIuPTR) || defined(PRIxPTR) || defined(PRIXPTR) || defined(SCNoPTR) || defined(SCNuPTR) || defined(SCNxPTR) || defined(UINTPTR_MAX)
          typedef uintptr_t type;
        #else
          typedef typename conditional<(sizeof(void*) > sizeof(typename uint_maximum_t::type)), typename uint_big_t::type, typename uint_maximum_t::type>::type type;
        #endif
      };

      // ...
      template <> struct uint_previous_t<unsigned char>  final {};
      template <> struct uint_previous_t<unsigned short> final { typedef unsigned char  type; };
      template <> struct uint_previous_t<unsigned int>   final { typedef unsigned short type; };
      template <> struct uint_previous_t<unsigned long>  final { typedef unsigned int   type; };

      #if CPP_VERSION >= 2011uL || defined(ULLONG_MAX)
        template <> struct uint_previous_t<unsigned long long> final { typedef unsigned long type; };
      #endif

      // ...
      template <std::size_t size> struct uint_t<size, uint_minimum_t>                              final { typedef typename conditional<size == sizeof(typename uint_minimum_t::type), typename uint_minimum_t::type, typename uint_t<size, uint_next_t<typename uint_minimum_t::type> >::type>::type type; };
      template <std::size_t size> struct uint_t<size, uint_next_t<typename uint_maximum_t::type> > final { typedef typename uint_null_t::type type; };
      template <std::size_t size, typename base> struct uint_t<size, uint_next_t<base> >           final { typedef typename conditional<size == sizeof(typename uint_next_t<base>::type), typename uint_next_t<base>::type, typename uint_t<size, uint_next_t<typename uint_next_t<base>::type> >::type>::type type; };

      template <> struct uint_t<1u> final { typedef typename uint_byte_t::type type; };

      // ...
      template <std::size_t width> struct uint_width_t<width, uint_minimum_t>                              final { typedef typename conditional<width == CHAR_BIT * sizeof(typename uint_minimum_t::type), typename uint_minimum_t::type, typename uint_width_t<width, uint_next_t<typename uint_minimum_t::type> >::type>::type type; };
      template <std::size_t width> struct uint_width_t<width, uint_next_t<typename uint_maximum_t::type> > final { typedef typename uint_null_t::type type; };
      template <std::size_t width, typename base> struct uint_width_t<width, uint_next_t<base> >           final { typedef typename conditional<width == CHAR_BIT * sizeof(typename uint_next_t<base>::type), typename uint_next_t<base>::type, typename uint_width_t<width, uint_next_t<typename uint_next_t<base>::type> >::type>::type type; };

      template <> struct uint_width_t<CHAR_BIT> final { typedef typename uint_byte_t::type type; };

      #if CHAR_BIT != 8 && defined(UINT8_MAX)
        template <> struct uint_width_t<8u> final { typedef uint8_t type; };
      #endif

      #if CHAR_BIT != 16 && defined(UINT16_MAX)
        template <> struct uint_width_t<16u> final { typedef uint16_t type; };
      #endif

      #if CHAR_BIT != 32 && defined(UINT32_MAX)
        template <> struct uint_width_t<32u> final { typedef uint32_t type; };
      #endif

      #if CHAR_BIT != 64 && defined(UINT64_MAX)
        template <> struct uint_width_t<64u> final { typedef uint64_t type; };
      #endif

      #if CHAR_BIT != 128 && defined(uint128_t)
        template <> struct uint_width_t<128u> final { typedef uint128_t type; };
      #endif
    }

    /* Class > Bit ->> Preferably `unsigned` */
    template <std::size_t width>
    struct bit final {
      typename uint_least_width_t<width>::type value : width;

      // ...
      constfunc(true) inline bit() noexcept : value() {}
      constfunc(true) inline bit(bit const& bit) noexcept : value(bit.value) {}
      constfunc(true) inline bit(typename uint_least_width_t<width>::type const value) noexcept : value(value) {}

      // ...
      constfunc(true) friend inline typename uint_least_width_t<width>::type operator +(bit const bit) noexcept { return bit.operator typename uint_least_width_t<width>::type(); }
      constfunc(true) friend inline bit operator ~(bit const bit) noexcept { return Lapys::bit<width>(~bit.value); }

      constfunc(true) friend inline bit operator &(bit const bitA, bit const bitB) noexcept { return Lapys::bit<width>(bitA.value & bitB.value); }
      template <typename type> constfunc(true) friend inline bit operator &(bit const bit, type const& object) noexcept { return Lapys::bit<width>(bit.value & object); }
      template <typename type> constfunc(true) friend inline bit operator &(type const& object, bit const bit) noexcept { return Lapys::bit<width>(object & bit.value); }

      constfunc(true) friend inline bit operator |(bit const bitA, bit const bitB) noexcept { return Lapys::bit<width>(bitA.value | bitB.value); }
      template <typename type> constfunc(true) friend inline bit operator |(bit const bit, type const& object) noexcept { return Lapys::bit<width>(bit.value | object); }
      template <typename type> constfunc(true) friend inline bit operator |(type const& object, bit const bit) noexcept { return Lapys::bit<width>(object | bit.value); }

      constfunc(true) friend inline bit operator ^(bit const bitA, bit const bitB) noexcept { return Lapys::bit<width>(bitA.value ^ bitB.value); }
      template <typename type> constfunc(true) friend inline bit operator ^(bit const bit, type const& object) noexcept { return Lapys::bit<width>(bit.value ^ object); }
      template <typename type> constfunc(true) friend inline bit operator ^(type const& object, bit const bit) noexcept { return Lapys::bit<width>(object ^ bit.value); }

      constfunc(true) friend inline bit operator <<(bit const bitA, bit const bitB) noexcept { return Lapys::bit<width>(bitA.value << bitB.value); }
      template <typename type> constfunc(true) friend inline bit operator <<(bit const bit, type const& object) noexcept { return Lapys::bit<width>(bit.value << object); }
      template <typename type> constfunc(true) friend inline bit operator <<(type const& object, bit const bit) noexcept { return Lapys::bit<width>(object << bit.value); }

      constfunc(true) friend inline bit operator >>(bit const bitA, bit const bitB) noexcept { return Lapys::bit<width>(bitA.value >> bitB.value); }
      template <typename type> constfunc(true) friend inline bit operator >>(bit const bit, type const& object) noexcept { return Lapys::bit<width>(bit.value >> object); }
      template <typename type> constfunc(true) friend inline bit operator >>(type const& object, bit const bit) noexcept { return Lapys::bit<width>(object >> bit.value); }

      template <typename type> constfunc(true) friend inline bit&          operator &=(bit&          bit, type const& object) noexcept { return (bit.value &= object), bit; }
      template <typename type> constfunc(true) friend inline bit volatile& operator &=(bit volatile& bit, type const& object) noexcept { return (bit.value &= object), bit; }

      template <typename type> constfunc(true) friend inline bit&          operator |=(bit&          bit, type const& object) noexcept { return (bit.value |= object), bit; }
      template <typename type> constfunc(true) friend inline bit volatile& operator |=(bit volatile& bit, type const& object) noexcept { return (bit.value |= object), bit; }

      template <typename type> constfunc(true) friend inline bit&          operator ^=(bit&          bit, type const& object) noexcept { return (bit.value ^= object), bit; }
      template <typename type> constfunc(true) friend inline bit volatile& operator ^=(bit volatile& bit, type const& object) noexcept { return (bit.value ^= object), bit; }

      template <typename type> constfunc(true) friend inline bit&          operator <<=(bit&          bit, type const& object) noexcept { return (bit.value <<= object), bit; }
      template <typename type> constfunc(true) friend inline bit volatile& operator <<=(bit volatile& bit, type const& object) noexcept { return (bit.value <<= object), bit; }

      template <typename type> constfunc(true) friend inline bit&          operator >>=(bit&          bit, type const& object) noexcept { return (bit.value >>= object), bit; }
      template <typename type> constfunc(true) friend inline bit volatile& operator >>=(bit volatile& bit, type const& object) noexcept { return (bit.value >>= object), bit; }

      #if (CPP_VERSION < 2011uL)
        constfunc(true) inline operator typename uint_least_width_t<width>::type() const volatile noexcept { return this -> value; }
      #else
        constfunc(true) explicit inline operator typename uint_least_width_t<width>::type() const volatile noexcept { return this -> value; }
      #endif
    };
  }

  namespace Lapys {
    /* Namespace > Definition */
    namespace Traits {
      template <typename>                            struct alias;
      template <typename>                            struct assess_bound;
      template <typename>                            struct assess_pointer;
      template <typename>                            struct assess_reference;
      template <typename>                            struct can_destruct;
      template <typename base, base>                 struct constant; // ->> `struct construct<...>` supports `defer`ence
      template <template <typename> class, typename> struct defer;
      template <typename>                            struct generator;
      template <typename>                            struct is_arithmetic;
      template <typename>                            struct is_bound;
      template <typename>                            struct is_byte;
      template <typename>                            struct is_character;
      template <class>                               struct is_class;
      template <typename>                            struct is_const;
      template <typename>                            struct is_enum;
      template <class>                               struct is_empty;
      template <class>                               struct is_final;
      template <typename>                            struct is_floating_point;
      template <typename>                            struct is_functional;
      template <typename>                            struct is_integral;
      template <typename>                            struct is_lvalue_reference;
      template <typename>                            struct is_pointer;
      template <typename>                            struct is_reference;
      template <typename>                            struct is_rvalue_reference;
      template <typename>                            struct is_scalar;
      template <typename>                            struct is_scoped_enum;
      template <class>                               struct is_union;
      template <typename>                            struct is_unscoped_enum;
      template <typename>                            struct is_void;
      template <typename>                            struct is_volatile;
      template <typename>                            struct maxof;
      template <typename>                            struct nilof;
      template <typename>                            struct minof;
      template <typename, class, class>              struct property;
      template <typename>                            struct remove_bound;
      template <typename>                            struct remove_lvalue_reference;
      template <typename>                            struct remove_pointer;
      template <typename>                            struct remove_reference;
      template <typename>                            struct remove_rvalue_reference;
      template <typename>                            struct sign;
      template <typename>                            struct unsign;

      #define widthof_t typename conditional<is_bit<base>::value, typeof(+instanceof<bit<CHAR_BIT * sizeof(base)> >()), typename conditional<(CPP_VERSION < 2011uL), typename conditional<is_same<byte, typename remove_qualifiers<base>::type>::value, typeof(+instanceof<byte>()), base>::type, base>::type>::type
        template <typename base, widthof_t integer = maxof<widthof_t>::value>
        struct widthof;
      #undef widthof_t

      #ifdef __cpp_variadic_templates
        template <enum initialization control, typename, typename...> struct can_construct;
        template <enum operation      control, typename...>           struct can_operate;
        template <typename...>                                        struct construct; // ->> `struct constant<...>` does not support `defer`ence
      #else
        template <enum initialization control, typename, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null> struct can_construct;
        template <enum operation      control, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null>           struct can_operate;
        template <typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null, typename = null>                                        struct construct; // ->> `struct constant<...>` does not support `defer`ence
      #endif
    }

    /* Namespace > Trait */
    namespace Traits {}
  }
#if CPP_COMPILER == CPP__CLANG__COMPILER
# pragma clang diagnostic pop
#elif CPP_COMPILER == CPP__GCC__COMPILER
# pragma GCC diagnostic pop
#endif
