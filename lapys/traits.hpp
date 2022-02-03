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

  /* Namespace */
  namespace Lapys {
    /* Function > ... */
    template <typename type>
    constfunc(true) inline type instanceof() noexcept;

    // ... --- CITE (Lapys) -> https://github.com/facebook/folly/blob/main/folly/lang/Launder.h
    #if defined(__cpp_lib_launder) || (CPP_COMPILER == CPP__MSVC__COMPILER && defined(_HAS_LAUNDER)) || CPP_VERSION >= 2017uL
      using std::launder;
    #else
      template <typename type>
      noignore inline type* launder(type* pointer) noexcept {
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

    /* Class > ... */
    #if CPP_VERSION < 2011uL
      union alignmentas(sizeof(unsigned char)) byte {
        private:
          unsigned char value;

        public:
          typedef unsigned char type;

          // ...
          constfunc(true) inline byte() noexcept : value() {}
          constfunc(true) inline byte(unsigned char const value) noexcept : value(value) {}

          constfunc(true) operator unsigned char() const volatile noexcept { return this -> value; }
      };
    #elif CPP_VERSION < 2017uL
      enum class byte : unsigned char {};
    #else
      typedef std::byte byte;
    #endif

    #if CPP_VERSION < 2017uL
      constfunc(true) inline byte operator ~(byte const byte) noexcept { return Lapys::byte(~static_cast<unsigned char>(byte)); }

      constfunc(true) inline byte operator &(byte const byteA, byte const byteB) noexcept { return Lapys::byte(static_cast<unsigned char>(byteA) & static_cast<unsigned char>(byteB)); }
      template <typename type> constfunc(true) inline byte operator &(byte const byte, type const& object) noexcept { return Lapys::byte(static_cast<unsigned char>(byte) & static_cast<unsigned char>(object)); }
      template <typename type> constfunc(true) inline byte operator &(type const& object, byte const byte) noexcept { return Lapys::byte(static_cast<unsigned char>(object) & static_cast<unsigned char>(byte)); }

      constfunc(true) inline byte operator |(byte const byteA, byte const byteB) noexcept { return Lapys::byte(static_cast<unsigned char>(byteA) | static_cast<unsigned char>(byteB)); }
      template <typename type> constfunc(true) inline byte operator |(byte const byte, type const& object) noexcept { return Lapys::byte(static_cast<unsigned char>(byte) | static_cast<unsigned char>(object)); }
      template <typename type> constfunc(true) inline byte operator |(type const& object, byte const byte) noexcept { return Lapys::byte(static_cast<unsigned char>(object) | static_cast<unsigned char>(byte)); }

      constfunc(true) inline byte operator ^(byte const byteA, byte const byteB) noexcept { return Lapys::byte(static_cast<unsigned char>(byteA) ^ static_cast<unsigned char>(byteB)); }
      template <typename type> constfunc(true) inline byte operator ^(byte const byte, type const& object) noexcept { return Lapys::byte(static_cast<unsigned char>(byte) ^ static_cast<unsigned char>(object)); }
      template <typename type> constfunc(true) inline byte operator ^(type const& object, byte const byte) noexcept { return Lapys::byte(static_cast<unsigned char>(object) ^ static_cast<unsigned char>(byte)); }

      constfunc(true) inline byte operator <<(byte const byteA, byte const byteB) noexcept { return Lapys::byte(static_cast<unsigned char>(byteA) << static_cast<unsigned char>(byteB)); }
      template <typename type> constfunc(true) inline byte operator <<(byte const byte, type const& object) noexcept { return Lapys::byte(static_cast<unsigned char>(byte) << static_cast<unsigned char>(object)); }
      template <typename type> constfunc(true) inline byte operator <<(type const& object, byte const byte) noexcept { return Lapys::byte(static_cast<unsigned char>(object) << static_cast<unsigned char>(byte)); }

      constfunc(true) inline byte operator >>(byte const byteA, byte const byteB) noexcept { return Lapys::byte(static_cast<unsigned char>(byteA) >> static_cast<unsigned char>(byteB)); }
      template <typename type> constfunc(true) inline byte operator >>(byte const byte, type const& object) noexcept { return Lapys::byte(static_cast<unsigned char>(byte) >> static_cast<unsigned char>(object)); }
      template <typename type> constfunc(true) inline byte operator >>(type const& object, byte const byte) noexcept { return Lapys::byte(static_cast<unsigned char>(object) >> static_cast<unsigned char>(byte)); }

      template <typename type> constfunc(true) inline byte&          operator &=(byte&          byte, type const& object) noexcept { return (byte = static_cast<unsigned char>(byte) & object); }
      template <typename type> constfunc(true) inline byte volatile& operator &=(byte volatile& byte, type const& object) noexcept { return (byte = static_cast<unsigned char>(byte) & object); }

      template <typename type> constfunc(true) inline byte&          operator |=(byte&          byte, type const& object) noexcept { return (byte = static_cast<unsigned char>(byte) | object); }
      template <typename type> constfunc(true) inline byte volatile& operator |=(byte volatile& byte, type const& object) noexcept { return (byte = static_cast<unsigned char>(byte) | object); }

      template <typename type> constfunc(true) inline byte&          operator ^=(byte&          byte, type const& object) noexcept { return (byte = static_cast<unsigned char>(byte) ^ object); }
      template <typename type> constfunc(true) inline byte volatile& operator ^=(byte volatile& byte, type const& object) noexcept { return (byte = static_cast<unsigned char>(byte) ^ object); }

      template <typename type> constfunc(true) inline byte&          operator <<=(byte&          byte, type const& object) noexcept { return (byte = static_cast<unsigned char>(byte) << object); }
      template <typename type> constfunc(true) inline byte volatile& operator <<=(byte volatile& byte, type const& object) noexcept { return (byte = static_cast<unsigned char>(byte) << object); }

      template <typename type> constfunc(true) inline byte&          operator >>=(byte&          byte, type const& object) noexcept { return (byte = static_cast<unsigned char>(byte) >> object); }
      template <typename type> constfunc(true) inline byte volatile& operator >>=(byte volatile& byte, type const& object) noexcept { return (byte = static_cast<unsigned char>(byte) >> object); }
    #endif

    /* ... */
    namespace Traits {
      // ... ->> For configurable function code paths or generic data structures
      enum control_parameter {
        BUFFERED   = 0x0002u,
        DYNAMIC    = 0x0000u,
        EXECUTABLE = 0x0004u,
        HEAP       = 0x0008u,
        MAXIMUM    = 0xF000u,
        STATIC     = 0x0010u,
        STACK      = 0x0020u,
        VIEWABLE   = 0x0040u,
        ZERO       = 0x0000u  // --> 0
      };
        constfunc(true) inline control_parameter operator &(control_parameter const controlParameterA, control_parameter const controlParameterB) noexcept { return static_cast<control_parameter>(static_cast<unsigned char>(controlParameterA) & static_cast<unsigned char>(controlParameterB)); }
        constfunc(true) inline control_parameter operator |(control_parameter const controlParameterA, control_parameter const controlParameterB) noexcept { return static_cast<control_parameter>(static_cast<unsigned char>(controlParameterA) | static_cast<unsigned char>(controlParameterB)); }

      // ... ->> For convenient template specialization
      enum dummy_parameter {
        DUMMY = 0xFFFFu
      };

      // ...
      enum initialization {
        aggregate_init,
        copy_init,
        default_init,
        direct_init,
        move_init,
        reference_init,
        zero_init
      };

      // ...
      union null {
        constfunc(true) null(...) noexcept {}

        template <typename type>
        constfunc(true) inline operator type() const noexcept {
          return instanceof<type>();
        }
      };

      // ...
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

    namespace Traits {
      struct int_maximum_t;
      struct int_minimum_t;
      struct uint_maximum_t;
      struct uint_minimum_t;

      template <typename>                                                                                          struct alias;
      template <typename>                                                                                          struct assess_bound;
      template <typename>                                                                                          struct assess_const;
      template <typename>                                                                                          struct assess_function;
      template <typename>                                                                                          struct assess_pointer;
      template <typename>                                                                                          struct assess_reference;
      template <typename>                                                                                          struct assess_volatile;
      template <enum initialization control, typename, apply(typename = null apply_empty, comma, LAPYS_MAX_ARITY)> struct can_initialize;
      template <enum operation control, apply(typename = null apply_empty, comma, LAPYS_MAX_ARITY)>                struct can_operate;
      template <bool, typename = null, typename = null>                                                            struct conditional;
      template <typename base, base>                                                                               struct constant;
      template <apply(typename = null apply_empty, comma, LAPYS_MAX_ARITY)>                                        struct constructor;
      template <template <typename> class, typename>                                                               struct defer;
      template <typename>                                                                                          struct generator;
      template <std::size_t>                                                                                       struct int_least_t;
      template <std::size_t>                                                                                       struct int_least_width_t;
      template <typename>                                                                                          struct int_next_t;
      template <typename>                                                                                          struct int_previous_t;
      template <std::size_t>                                                                                       struct int_t;
      template <std::size_t>                                                                                       struct int_width_t;
      template <typename>                                                                                          struct is_arithmetic;
      template <typename>                                                                                          struct is_bound;
      template <typename>                                                                                          struct is_character;
      template <class>                                                                                             struct is_class;
      template <typename>                                                                                          struct is_const;
      template <typename>                                                                                          struct is_enum;
      template <class>                                                                                             struct is_empty;
      template <class>                                                                                             struct is_final;
      template <typename>                                                                                          struct is_floating_point;
      template <typename>                                                                                          struct is_function;
      template <typename>                                                                                          struct is_integral;
      template <typename>                                                                                          struct is_lvalue_reference;
      template <typename>                                                                                          struct is_noexcept;
      template <typename>                                                                                          struct is_pointer;
      template <typename>                                                                                          struct is_reference;
      template <typename>                                                                                          struct is_rvalue_reference;
      template <typename, typename>                                                                                struct is_same;
      template <typename>                                                                                          struct is_scalar;
      template <typename>                                                                                          struct is_scoped_enum;
      template <class>                                                                                             struct is_union;
      template <typename>                                                                                          struct is_unscoped_enum;
      template <typename>                                                                                          struct is_void;
      template <typename>                                                                                          struct is_volatile;
      template <typename>                                                                                          struct maxof;
      template <typename>                                                                                          struct nilof;
      template <typename>                                                                                          struct minof;
      template <typename, class, class>                                                                            struct property;
      template <typename>                                                                                          struct remove_bound;
      template <typename>                                                                                          struct remove_const;
      template <typename>                                                                                          struct remove_lvalue_reference;
      template <typename>                                                                                          struct remove_pointer;
      template <typename>                                                                                          struct remove_qualifiers;
      template <typename>                                                                                          struct remove_reference;
      template <typename>                                                                                          struct remove_rvalue_reference;
      template <typename>                                                                                          struct remove_volatile;
      template <typename>                                                                                          struct sign;
      template <bool, class, class>                                                                                struct ternary;
      template <std::size_t>                                                                                       struct uint_least_t;
      template <std::size_t>                                                                                       struct uint_least_width_t;
      template <typename>                                                                                          struct uint_next_t;
      template <typename>                                                                                          struct uint_previous_t;
      template <std::size_t>                                                                                       struct uint_t;
      template <std::size_t>                                                                                       struct uint_width_t;
      template <typename>                                                                                          struct unsign;
    }

    using namespace Traits;
  }

  namespace Lapys {
    // : [Core]
    namespace Traits {
      template <typename base>
      struct alias final {
        typedef base type;
      };

      // ...
      template <> struct conditional<false> final {};
      template <> struct conditional<true>  final {};

      template <typename base> struct conditional<false, base> final {};
      template <typename base> struct conditional<true,  base> final { typedef base type; };

      template <typename baseA, typename baseB> struct conditional<false, baseA, baseB> final { typedef baseB type; };
      template <typename baseA, typename baseB> struct conditional<true,  baseA, baseB> final { typedef baseA type; };

      // ...
      template <typename base, base argument>
      struct constant final {
        constvar static base const value varinit(argument);
      };

      // ...
      #define constructor(count)                                                                                       \
        template <reapply(typename constructor_template_argument, comma, count)>                                       \
        struct constructor<reapply(constructor_template_argument, comma, count)> final {                               \
          template <reapply(constructor_construct_template_parameter, comma, count)>                                   \
          struct apply final {                                                                                         \
            template <typename type>                                                                                   \
            struct call final {                                                                                        \
              constvar static type const value = type(reapply(constructor_construct_template_argument, comma, count)); \
            };                                                                                                         \
          };                                                                                                           \
        };
      # define constructor_template_argument(count) type ## count
      #   define constructor_construct_template_argument(count)  value ## count
      #   define constructor_construct_template_parameter(count) type  ## count value ## count

      template <>
      struct constructor<> final {
        template <typename = null>
        struct apply final {
          template <typename type>
          struct call final {
            #ifdef __cpp_aggregate_paren_init
              constvar static type const value {};
            #else
              constvar static type const value = type();
            #endif
          };
        };
      };

      template <apply(typename constructor_template_argument, comma, LAPYS_MAX_ARITY)>
      struct constructor final {
        template <apply(constructor_construct_template_parameter, comma, LAPYS_MAX_ARITY)>
        struct apply final {
          template <typename type>
          struct call final {
            #ifdef __cpp_aggregate_paren_init
              constvar static type const value {apply(constructor_construct_template_argument, comma, LAPYS_MAX_ARITY)};
            #else
              constvar static type const value = type(apply(constructor_construct_template_argument, comma, LAPYS_MAX_ARITY));
            #endif
          };
        };
      };

      apply(constructor, empty, previous(LAPYS_MAX_ARITY))

      #undef constructor
      # undef constructor_template_argument
      #   undef constructor_construct_template_argument
      #   undef constructor_construct_template_parameter

      // ...
      template <template <typename> class trait, typename parameter>
      struct defer final {
        typedef trait<parameter> type;
      };

      // ...
      template <typename base>
      struct generator final {
        template <base current, base end, base step>
        struct sequence_sentinel final {
          private:
            template <typename type, type, type, bool>
            struct valueof;

            template <typename type, type subcurrent, type subend>
            struct valueof<type, subcurrent, subend, false> final {
              friend struct sequence_sentinel<current, end, step>;
              private: static bool const value = static_cast<bool>(subcurrent < subend) || static_cast<bool>(subcurrent == subend);
            };

            template <typename type, type subcurrent, type subend>
            struct valueof<type, subcurrent, subend, true> final {
              friend struct sequence_sentinel<current, end, step>;
              private: static bool const value = subcurrent <= subend;
            };

          public:
            static bool const value = valueof<base, current, end, can_operate<equals_lesser, base, base>::value || false == (can_operate<equals, base, base>::value && can_operate<lesser, base, base>::value)>::value;
        };
      };

      // ...
      template <std::size_t size>
      struct int_least_t final {
        private:
          template <dummy_parameter, class, bool>
          struct valueof final {
            friend struct int_least_t<size>;
            private: typedef void type;
          };

          template <dummy_parameter dummy, class int_trait_t>
          struct valueof<dummy, int_trait_t, false> final {
            friend struct int_least_t<size>;
            private: typedef typename conditional<size <= sizeof(typename int_trait_t::type), typename int_trait_t::type, typename valueof<dummy, int_next_t<typename int_trait_t::type>, int_next_t<typename int_trait_t::type>::end>::type>::type type;
          };

        public:
          typedef typename valueof<DUMMY, int_minimum_t, false>::type type;
      };

      // ...
      template <std::size_t width>
      struct int_least_width_t final {
        private:
          template <dummy_parameter, class, bool>
          struct valueof {
            friend struct int_least_width_t<width>;
            private: typedef void type;
          };

          template <dummy_parameter dummy, class int_trait_t>
          struct valueof<dummy, int_trait_t, false> final {
            friend struct int_least_width_t<width>;
            private: typedef typename conditional<width <= CHAR_BIT * sizeof(typename int_trait_t::type), typename int_trait_t::type, typename valueof<dummy, int_next_t<typename int_trait_t::type>, int_next_t<typename int_trait_t::type>::end>::type>::type type;
          };

        public:
          typedef typename valueof<DUMMY, int_minimum_t, false>::type type;
      };

      #if defined(INT8_C)
        template <> struct int_least_width_t<8u> final { typedef int_least8_t type; };
      #endif
      #if defined(INT16_C)
        template <> struct int_least_width_t<16u> final { typedef int_least16_t type; };
      #endif
      #if defined(INT32_C)
        template <> struct int_least_width_t<32u> final { typedef int_least32_t type; };
      #endif
      #if defined(INT64_C)
        template <> struct int_least_width_t<64u> final { typedef int_least64_t type; };
      #endif

      // ...
      #if CPP_VERSION >= 2011uL || defined(LLONG_MAX)
        struct int_maximum_t final { typedef signed long long type; };
      #else
        struct int_maximum_t final { typedef signed long type; };
      #endif

      // ...
      struct int_minimum_t final {
        typedef signed char type;
      };

      // ...
      template <typename>
      struct int_next_t;

      template <> struct int_next_t<signed char>  final { typedef signed short type; static bool const end = false; };
      template <> struct int_next_t<signed short> final { typedef signed int   type; static bool const end = false; };
      template <> struct int_next_t<signed int>   final { typedef signed long  type; static bool const end = false; };

      #if CPP_VERSION >= 2011uL || defined(LLONG_MAX)
        template <> struct int_next_t<signed long>      final { typedef signed long long type; static bool const end = false; };
        template <> struct int_next_t<signed long long> final {                                static bool const end = true;  };
      #else
        template <> struct int_next_t<signed long> final { static bool const end = true; };
      #endif

      // ...
      template <typename>
      struct int_previous_t;

      template <> struct int_previous_t<signed char>  final {                            static bool const end = true;  };
      template <> struct int_previous_t<signed short> final { typedef signed char  type; static bool const end = false; };
      template <> struct int_previous_t<signed int>   final { typedef signed short type; static bool const end = false; };
      template <> struct int_previous_t<signed long>  final { typedef signed int   type; static bool const end = false; };

      #if CPP_VERSION >= 2011uL || defined(LLONG_MAX)
        template <> struct int_previous_t<signed long long> final { typedef signed long type; static bool const end = false; };
      #endif

      // ...
      template <std::size_t width>
      struct int_width_t final {
        private:
          template <dummy_parameter, class, bool>
          struct valueof {
            friend struct int_width_t<width>;
            private: typedef void type;
          };

          template <dummy_parameter dummy, class int_trait_t>
          struct valueof<dummy, int_trait_t, false> final {
            friend struct int_least_width_t<width>;
            private: typedef typename conditional<width == CHAR_BIT * sizeof(typename int_trait_t::type), typename int_trait_t::type, typename valueof<dummy, int_next_t<typename int_trait_t::type>, int_next_t<typename int_trait_t::type>::end>::type>::type type;
          };

        public:
          typedef typename valueof<DUMMY, int_minimum_t, false>::type type;
      };

      #if CHAR_BIT == 8
        template <> struct int_width_t<8u>  final { typedef int8_t  type; };
        template <> struct int_width_t<16u> final { typedef int16_t type; };
        template <> struct int_width_t<32u> final { typedef int32_t type; };
        template <> struct int_width_t<64u> final { typedef int64_t type; };
      #endif

      #if CPP_COMPILER == CPP__CLANG__COMPILER
        template <> struct int_width_t<128u> final { typedef __int128_t type; };
      #elif CPP_COMPILER == CPP__GCC__COMPILER
      # ifdef __SIZEOF_INT128__
      #   pragma GCC diagnostic push
      #   pragma GCC diagnostic ignored "-Wpedantic"
          template <> struct int_width_t<128u> final { typedef __int128 type; };
      #   pragma GCC diagnostic pop
      # endif
      #elif CPP_COMPILER == CPP__ICC__COMPILER
      # ifdef __SSE2__
          template <> struct int_width_t<128u> final { typedef __i128 type; };
      # endif
      #endif

      // ...
      template <std::size_t size>
      struct int_t final {
        private:
          template <dummy_parameter, class, bool>
          struct valueof final {
            friend struct int_t<size>;
            private: typedef void type;
          };

          template <dummy_parameter dummy, class int_trait_t>
          struct valueof<dummy, int_trait_t, false> final {
            friend struct int_t<size>;
            private: typedef typename conditional<size == sizeof(typename int_trait_t::type), typename int_trait_t::type, typename valueof<dummy, int_next_t<typename int_trait_t::type>, int_next_t<typename int_trait_t::type>::end>::type>::type type;
          };

        public:
          typedef typename valueof<DUMMY, int_minimum_t, false>::type type;
      };

      template <> struct int_t<sizeof(signed char)> final { typedef signed char type; };
      #if SHRT_MAX != SCHAR_MAX
        template <> struct int_t<sizeof(signed short)> final { typedef signed short type; };
      #endif
      #if INT_MAX != SCHAR_MAX && INT_MAX != SHRT_MAX
        template <> struct int_t<sizeof(signed int)> final { typedef signed int type; };
      #endif
      #if LONG_MAX != SCHAR_MAX && LONG_MAX != SHRT_MAX && LONG_MAX != INT_MAX
        template <> struct int_t<sizeof(signed long)> final { typedef signed long type; };
      #endif
      #if CPP_VERSION >= 2011uL || defined(LLONG_MAX)
      # if LLONG_MAX != SCHAR_MAX && LLONG_MAX != SHRT_MAX && LLONG_MAX != INT_MAX && LLONG_MAX != LONG_MAX
          template <> struct int_t<sizeof(signed long long)> final { typedef signed long long type; };
      # endif
      #endif

      // ...
      template <std::size_t size>
      struct uint_least_t final {
        private:
          template <dummy_parameter, class, bool>
          struct valueof final {
            friend struct uint_least_t<size>;
            private: typedef void type;
          };

          template <dummy_parameter dummy, class uint_trait_t>
          struct valueof<dummy, uint_trait_t, false> final {
            friend struct uint_least_t<size>;
            private: typedef typename conditional<size <= sizeof(typename uint_trait_t::type), typename uint_trait_t::type, typename valueof<dummy, uint_next_t<typename uint_trait_t::type>, uint_next_t<typename uint_trait_t::type>::end>::type>::type type;
          };

        public:
          typedef typename valueof<DUMMY, uint_minimum_t, false>::type type;
      };

      // ...
      template <std::size_t width>
      struct uint_least_width_t final {
        private:
          template <dummy_parameter, class, bool>
          struct valueof {
            friend struct uint_least_width_t<width>;
            private: typedef void type;
          };

          template <dummy_parameter dummy, class uint_trait_t>
          struct valueof<dummy, uint_trait_t, false> final {
            friend struct uint_least_width_t<width>;
            private: typedef typename conditional<width <= CHAR_BIT * sizeof(typename uint_trait_t::type), typename uint_trait_t::type, typename valueof<dummy, uint_next_t<typename uint_trait_t::type>, uint_next_t<typename uint_trait_t::type>::end>::type>::type type;
          };

        public:
          typedef typename valueof<DUMMY, uint_minimum_t, false>::type type;
      };

      #if defined(INT8_C)
        template <> struct uint_least_width_t<8u> final { typedef uint_least8_t type; };
      #endif
      #if defined(INT16_C)
        template <> struct uint_least_width_t<16u> final { typedef uint_least16_t type; };
      #endif
      #if defined(INT32_C)
        template <> struct uint_least_width_t<32u> final { typedef uint_least32_t type; };
      #endif
      #if defined(INT64_C)
        template <> struct uint_least_width_t<64u> final { typedef uint_least64_t type; };
      #endif

      // ...
      #if CPP_VERSION >= 2011uL || defined(ULLONG_MAX)
        struct uint_maximum_t final { typedef unsigned long long type; };
      #else
        struct uint_maximum_t final { typedef unsigned long type; };
      #endif

      // ...
      struct uint_minimum_t final {
        typedef unsigned char type;
      };

      // ...
      template <typename>
      struct uint_next_t;

      template <> struct uint_next_t<unsigned char>  final { typedef unsigned short type; static bool const end = false; };
      template <> struct uint_next_t<unsigned short> final { typedef unsigned int   type; static bool const end = false; };
      template <> struct uint_next_t<unsigned int>   final { typedef unsigned long  type; static bool const end = false; };

      #if CPP_VERSION >= 2011uL || defined(ULLONG_MAX)
        template <> struct uint_next_t<unsigned long>      final { typedef unsigned long long type; static bool const end = false; };
        template <> struct uint_next_t<unsigned long long> final {                                  static bool const end = true;  };
      #else
        template <> struct uint_next_t<unsigned long> final { static bool const end = true; };
      #endif

      // ...
      template <typename>
      struct uint_previous_t;

      template <> struct uint_previous_t<unsigned char>  final {                              static bool const end = true;  };
      template <> struct uint_previous_t<unsigned short> final { typedef unsigned char  type; static bool const end = false; };
      template <> struct uint_previous_t<unsigned int>   final { typedef unsigned short type; static bool const end = false; };
      template <> struct uint_previous_t<unsigned long>  final { typedef unsigned int   type; static bool const end = false; };

      #if CPP_VERSION >= 2011uL || defined(ULLONG_MAX)
        template <> struct uint_previous_t<unsigned long long> final { typedef unsigned long type; static bool const end = false; };
      #endif

      // ...
      template <std::size_t width>
      struct uint_width_t final {
        private:
          template <dummy_parameter, class, bool>
          struct valueof {
            friend struct uint_width_t<width>;
            private: typedef void type;
          };

          template <dummy_parameter dummy, class uint_trait_t>
          struct valueof<dummy, uint_trait_t, false> final {
            friend struct uint_least_width_t<width>;
            private: typedef typename conditional<width == CHAR_BIT * sizeof(typename uint_trait_t::type), typename uint_trait_t::type, typename valueof<dummy, uint_next_t<typename uint_trait_t::type>, uint_next_t<typename uint_trait_t::type>::end>::type>::type type;
          };

        public:
          typedef typename valueof<DUMMY, uint_minimum_t, false>::type type;
      };

      #if CHAR_BIT == 8
        template <> struct uint_width_t<8u>  final { typedef uint8_t  type; };
        template <> struct uint_width_t<16u> final { typedef uint16_t type; };
        template <> struct uint_width_t<32u> final { typedef uint32_t type; };
        template <> struct uint_width_t<64u> final { typedef uint64_t type; };
      #endif

      #if CPP_COMPILER == CPP__CLANG__COMPILER
        template <> struct uint_width_t<128u> final { typedef __uint128_t type; };
      #elif CPP_COMPILER == CPP__GCC__COMPILER
      # ifdef __SIZEOF_INT128__
      #   pragma GCC diagnostic push
      #   pragma GCC diagnostic ignored "-Wpedantic"
          template <> struct uint_width_t<128u> final { typedef unsigned __int128 type; };
      #   pragma GCC diagnostic pop
      # endif
      #elif CPP_COMPILER == CPP__ICC__COMPILER
      # ifdef __SSE2__
          template <> struct uint_width_t<128u> final { typedef __u128 type; };
      # endif
      #endif

      // ...
      template <std::size_t size>
      struct uint_t final {
        private:
          template <dummy_parameter, class, bool>
          struct valueof final {
            friend struct uint_t<size>;
            private: typedef void type;
          };

          template <dummy_parameter dummy, class uint_trait_t>
          struct valueof<dummy, uint_trait_t, false> final {
            friend struct uint_t<size>;
            private: typedef typename conditional<size == sizeof(typename uint_trait_t::type), typename uint_trait_t::type, typename valueof<dummy, uint_next_t<typename uint_trait_t::type>, uint_next_t<typename uint_trait_t::type>::end>::type>::type type;
          };

        public:
          typedef typename valueof<DUMMY, uint_minimum_t, false>::type type;
      };

      template <> struct uint_t<sizeof(unsigned char)> final { typedef unsigned char type; };
      #if USHRT_MAX != UCHAR_MAX
        template <> struct uint_t<sizeof(unsigned short)> final { typedef unsigned short type; };
      #endif
      #if UINT_MAX != UCHAR_MAX && UINT_MAX != USHRT_MAX
        template <> struct uint_t<sizeof(unsigned int)> final { typedef unsigned int type; };
      #endif
      #if ULONG_MAX != UCHAR_MAX && ULONG_MAX != USHRT_MAX && ULONG_MAX != UINT_MAX
        template <> struct uint_t<sizeof(unsigned long)> final { typedef unsigned long type; };
      #endif
      #if CPP_VERSION >= 2011uL || defined(ULLONG_MAX)
      # if ULLONG_MAX != UCHAR_MAX && ULLONG_MAX != USHRT_MAX && ULLONG_MAX != UINT_MAX && ULLONG_MAX != ULONG_MAX
          template <> struct uint_t<sizeof(unsigned long long)> final { typedef unsigned long long type; };
      # endif
      #endif
    }

    namespace Traits {
      template <typename base>
      struct maxof final {
        constvar static base const value varinit((((typename conditional<(sizeof(typename uint_least_t<sizeof(base)>::type) > sizeof(unsigned)), typename conditional<(sizeof(typename uint_least_t<sizeof(base)>::type) > sizeof(typename uint_maximum_t::type)), typename uint_maximum_t::type, typename uint_least_t<sizeof(base)>::type>::type, unsigned>::type(1u) << ((CHAR_BIT * sizeof(base)) - 1u)) - 1u) << 1u) + 1u);
      };

      template <> struct maxof<char>           final { static char           const value = static_cast<char>(CHAR_MAX);            };
      template <> struct maxof<int>            final { static int            const value = INT_MAX;                                };
      template <> struct maxof<long>           final { static long           const value = LONG_MAX;                               };
      template <> struct maxof<short>          final { static short          const value = static_cast<short>(SHRT_MAX);           };
      template <> struct maxof<signed char>    final { static signed char    const value = static_cast<signed char>(SCHAR_MAX);    };
      template <> struct maxof<unsigned char>  final { static unsigned char  const value = static_cast<unsigned char>(UCHAR_MAX);  };
      template <> struct maxof<unsigned int>   final { static unsigned int   const value = UINT_MAX;                               };
      template <> struct maxof<unsigned long>  final { static unsigned long  const value = ULONG_MAX;                              };
      template <> struct maxof<unsigned short> final { static unsigned short const value = static_cast<unsigned short>(USHRT_MAX); };
      #if CPP_VERSION >= 2011uL
        template <> struct maxof<char16_t>    final { constexpr static char16_t    value = static_cast<char16_t>(UINT_LEAST16_MAX); };
        template <> struct maxof<char32_t>    final { constexpr static char32_t    value = static_cast<char32_t>(UINT_LEAST32_MAX); };
        template <> struct maxof<double>      final { constexpr static double      value = DBL_MAX;                                 };
        template <> struct maxof<float>       final { constexpr static float       value = FLT_MAX;                                 };
        template <> struct maxof<long double> final { constexpr static long double value = LDBL_MAX;                                };
        template <> struct maxof<wchar_t>     final { constexpr static wchar_t     value = WCHAR_MAX;                               };
      #endif
      #if CPP_VERSION >= 2011uL || defined(LLONG_MAX)
        template <> struct maxof<long long>          final { static long long const value = LLONG_MAX; };
      #endif
      #if CPP_VERSION >= 2011uL || defined(ULLONG_MAX)
        template <> struct maxof<unsigned long long> final { static unsigned long long const value = ULLONG_MAX; };
      #endif
      #if CPP_VERSION >= 2020uL
        template <> struct maxof<char8_t> final { constexpr static char8_t value = static_cast<char8_t>(UINT_LEAST8_MAX); };
      #endif

      // ...
      template <typename base>
      struct minof final {
        constvar static base const value varinit((static_cast<typename conditional<(sizeof(unsigned) > sizeof(typename uint_minimum_t::type)), unsigned, typename uint_minimum_t::type>::type>(0u)));
      };

      template <> struct minof<char>           final { static char           const value = '\0';      };
      template <> struct minof<int>            final { static int            const value = INT_MIN;   };
      template <> struct minof<long>           final { static long           const value = LONG_MIN;  };
      template <> struct minof<short>          final { static short          const value = SHRT_MIN;  };
      template <> struct minof<signed char>    final { static signed char    const value = SCHAR_MIN; };
      template <> struct minof<unsigned char>  final { static unsigned char  const value = 0u;        };
      template <> struct minof<unsigned int>   final { static unsigned int   const value = 0u;        };
      template <> struct minof<unsigned long>  final { static unsigned long  const value = 0uL;       };
      template <> struct minof<unsigned short> final { static unsigned short const value = 0u;        };
      template <> struct minof<wchar_t>        final { static wchar_t        const value = L'\0';     };
      #if CPP_VERSION >= 2011uL
        template <> struct minof<char16_t>           final { constexpr static char16_t           value = u'\0';     };
        template <> struct minof<char32_t>           final { constexpr static char32_t           value = U'\0';     };
        template <> struct minof<double>             final { constexpr static double             value = -DBL_MAX;  };
        template <> struct minof<float>              final { constexpr static float              value = -FLT_MAX;  };
        template <> struct minof<long double>        final { constexpr static long double        value = -LDBL_MAX; };
      #endif
      #if CPP_VERSION >= 2011uL || defined(LLONG_MAX)
        template <> struct minof<long long> final { static long long const value = LLONG_MIN; };
      #endif
      #if CPP_VERSION >= 2011uL || defined(ULLONG_MAX)
        template <> struct minof<unsigned long long> final { static unsigned long long const value = 0u; };
      #endif
      #if CPP_VERSION >= 2020uL
        template <> struct minof<char8_t> final { constexpr static char8_t value = u8'\0'; };
      #endif

      // ...
      #ifdef __cpp_nontype_template_args
        template <typename base>
        struct nilof final {
          private:
            template <dummy_parameter, bool>
            struct valueof;

            template <dummy_parameter dummy>
            struct valueof<dummy, false> final {
              friend struct nilof<base>;
              private:
                #ifdef __cpp_aggregate_paren_init
                  constvar static base const value {};
                #else
                  constvar static base const value = base();
                #endif
            };

            template <dummy_parameter dummy>
            struct valueof<dummy, true> final {
              friend struct nilof<base>;
              private: constvar static base const value varinit(0);
            };

          public:
            constvar static base const value varinit((valueof<DUMMY, (
              can_initialize<default_init, base>::value && false == can_initialize<zero_init, base>::value ? false :
              can_initialize<zero_init, base>::value                                                       ? true  :
              true
            )>::value));
        };
      #else
        template <typename base>
        struct nilof final {
          constvar static base const value varinit(0);
        };
      #endif
    }

    // : [Utility]
    namespace Traits {
      #define can_aggregate(count)                                                                                                                                                                       \
        template <typename base, reapply(typename can_aggregate_initialize_template_argument, comma, count)>                                                                                             \
        struct can_initialize<aggregate_init, base, reapply(can_aggregate_initialize_template_argument, comma, count)> final {                                                                           \
          private:                                                                                                                                                                                       \
            template <dummy_parameter, typename, reapply(typename can_aggregate_valueof_template_argument, comma, count), class = alias<null> >                                                 \
            struct valueof final {                                                                                                                                                                       \
              friend struct can_initialize;                                                                                                                                                              \
              private: static bool const value = false;                                                                                                                                                  \
            };                                                                                                                                                                                           \
                                                                                                                                                                                                         \
            template <dummy_parameter dummy, typename subbase, reapply(typename can_aggregate_valueof_template_argument, comma, count)>                                                         \
            struct valueof<dummy, subbase, reapply(can_aggregate_valueof_template_argument, comma, count), alias<typeof(null(subbase(reapply(can_aggregate_valueof_argument, comma, count))))> > final { \
              friend struct can_initialize;                                                                                                                                                              \
              private: static bool const value = true;                                                                                                                                                   \
            };                                                                                                                                                                                           \
                                                                                                                                                                                                         \
          public:                                                                                                                                                                                        \
            static bool const value = valueof<DUMMY, base, reapply(can_aggregate_initialize_template_argument, comma, count)>::value;                                                                    \
        };
      # define can_aggregate_initialize_template_argument(count) type ## count
      # define can_aggregate_valueof_argument(count)          instanceof<subtype ## count>()
      # define can_aggregate_valueof_template_argument(count) subtype ## count

      apply(can_aggregate, empty, LAPYS_MAX_ARITY)

      template <typename base>
      struct can_initialize<copy_init, base> final {
        #ifdef __cpp_rvalue_references
          static bool const value = can_initialize<aggregate_init, base, base>::value;
        #else
          static bool const value = can_initialize<aggregate_init, base, base const&>::value;
        #endif
      };

      template <typename base>
      struct can_initialize<default_init, base> final {
        private:
          template <dummy_parameter, typename, class = alias<null> >
          struct valueof final {
            friend struct can_initialize<default_init, base>;
            private: static bool const value = false;
          };

          template <dummy_parameter dummy, typename subbase>
          struct valueof<dummy, subbase, alias<typeof(null(subbase()))> > final {
            friend struct can_initialize<default_init, base>;
            private: static bool const value = true;
          };

        public:
          static bool const value = valueof<DUMMY, base>::value;
      };

      template <typename base, typename type>
      struct can_initialize<direct_init, base, type> final {
        static bool const value = can_initialize<aggregate_init, base, type>::value;
      };

      template <typename base>
      struct can_initialize<move_init, base> final {
        #ifdef __cpp_rvalue_references
          static bool const value = can_initialize<aggregate_init, base, base&&>::value;
        #else
          static bool const value = can_initialize<aggregate_init, base, base>::value;
        #endif
      };

      template <typename base>
      struct can_initialize<reference_init, base> final {
        static bool const value = is_reference<base>::value;
      };

      template <typename base, typename type>
      struct can_initialize<zero_init, base, type> final {
        private:
          template <dummy_parameter, typename, class = alias<null> >
          struct valueof final {
            friend struct can_initialize<zero_init, base>;
            private: static bool const value = false;
          };

          template <dummy_parameter dummy, class subbase>
          struct valueof<dummy, subbase, alias<typeof(null(subbase(0)))> > final {
            friend struct can_initialize<zero_init, base>;
            private: static bool const value = true;
          };

        public:
          static bool const value = valueof<DUMMY, base>::value;
      };

      #undef can_aggregate
      # undef can_aggregate_initialize_template_argument
      # undef can_aggregate_valueof_argument
      # undef can_aggregate_valueof_template_argument

      // ...
      #define can_call_template_argument(count) type ## count
      #define can_nop_template_parameter(count) typename
      # define can_nop_valueof_template_parameter(count) class = alias<null>
      #define can_operate_template_parameter(count) typename

      template <>
      struct can_operate<Traits::nop> final {
        template <enum operation control, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)>
        friend struct can_operate;

        private:
          template <dummy_parameter, enum operation control, apply(can_nop_valueof_template_parameter, comma, LAPYS_MAX_ARITY), class = alias<null> >
          struct valueof final {
            template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate;
            private: static bool const value = false;
          };

          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::add,                typeA, typeB, alias<typeof(null(  instanceof<typeA>()   + instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename type>                  struct valueof<dummy, Traits::address,            type,         alias<typeof(null( &instanceof<type> ()                        ))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::assign,             typeA, typeB, alias<typeof(null(  instanceof<typeA>()   = instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::assign_add,         typeA, typeB, alias<typeof(null(  instanceof<typeA>()  += instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::assign_bitwise_and, typeA, typeB, alias<typeof(null(  instanceof<typeA>()  &= instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::assign_bitwise_or,  typeA, typeB, alias<typeof(null(  instanceof<typeA>()  |= instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::assign_bitwise_xor, typeA, typeB, alias<typeof(null(  instanceof<typeA>()  ^= instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::assign_divide,      typeA, typeB, alias<typeof(null(  instanceof<typeA>()  /= instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::assign_left_shift,  typeA, typeB, alias<typeof(null(  instanceof<typeA>() <<= instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::assign_modulo,      typeA, typeB, alias<typeof(null(  instanceof<typeA>()  %= instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::assign_multiply,    typeA, typeB, alias<typeof(null(  instanceof<typeA>()  *= instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::assign_right_shift, typeA, typeB, alias<typeof(null(  instanceof<typeA>() >>= instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::assign_subtract,    typeA, typeB, alias<typeof(null(  instanceof<typeA>()  -= instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::bitwise_and,        typeA, typeB, alias<typeof(null(  instanceof<typeA>()   & instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::bitwise_or,         typeA, typeB, alias<typeof(null(  instanceof<typeA>()   | instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::bitwise_xor,        typeA, typeB, alias<typeof(null(  instanceof<typeA>()   ^ instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::boolean_and,        typeA, typeB, alias<typeof(null(  instanceof<typeA>()  && instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::boolean_or,         typeA, typeB, alias<typeof(null(  instanceof<typeA>()  || instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename type>                  struct valueof<dummy, Traits::call,               type,         alias<typeof(null(  instanceof<type> ()()                      ))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::cast,               typeA, typeB, alias<typeof(null(  static_cast<typeB>(instanceof<typeA>())    ))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::comma,              typeA, typeB, alias<typeof(null(  instanceof<typeA>()   , instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename type>                  struct valueof<dummy, Traits::complement,         type,         alias<typeof(null( ~instanceof<type> ()                        ))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename type>                  struct valueof<dummy, Traits::dereference,        type,         alias<typeof(null( *instanceof<type> ()                        ))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::divide,             typeA, typeB, alias<typeof(null(  instanceof<typeA>()   / instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::equals,             typeA, typeB, alias<typeof(null(  instanceof<typeA>()  == instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::equals_greater,     typeA, typeB, alias<typeof(null(  instanceof<typeA>()  >= instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::equals_lesser,      typeA, typeB, alias<typeof(null(  instanceof<typeA>()  <= instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::greater,            typeA, typeB, alias<typeof(null(  instanceof<typeA>()   > instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::left_shift,         typeA, typeB, alias<typeof(null(  instanceof<typeA>()  << instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::lesser,             typeA, typeB, alias<typeof(null(  instanceof<typeA>()   < instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename type>                  struct valueof<dummy, Traits::minus,              type,         alias<typeof(null( -instanceof<type> ()                        ))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::modulo,             typeA, typeB, alias<typeof(null(  instanceof<typeA>()   % instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::multiply,           typeA, typeB, alias<typeof(null(  instanceof<typeA>()   * instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename type>                  struct valueof<dummy, Traits::negate,             type,         alias<typeof(null( !instanceof<type> ()                        ))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename type>                  struct valueof<dummy, Traits::post_decrement,     type,         alias<typeof(null(  instanceof<type> ()--                      ))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename type>                  struct valueof<dummy, Traits::post_increment,     type,         alias<typeof(null(  instanceof<type> ()++                      ))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename type>                  struct valueof<dummy, Traits::plus,               type,         alias<typeof(null( +instanceof<type> ()                        ))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename type>                  struct valueof<dummy, Traits::pre_decrement,      type,         alias<typeof(null(--instanceof<type> ()                        ))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename type>                  struct valueof<dummy, Traits::pre_increment,      type,         alias<typeof(null(++instanceof<type> ()                        ))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::right_shift,        typeA, typeB, alias<typeof(null(  instanceof<typeA>()  >> instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::subscript,          typeA, typeB, alias<typeof(null(  instanceof<typeA>()[instanceof<typeB>()]   ))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::subtract,           typeA, typeB, alias<typeof(null(  instanceof<typeA>()   - instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };
          template <dummy_parameter dummy, typename typeA, typename typeB> struct valueof<dummy, Traits::unequals,           typeA, typeB, alias<typeof(null(  instanceof<typeA>()  != instanceof<typeB>()))> > final { template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate; private: static bool const value = true; };

          #define can_call_valueof(count)                                                                                                                                                                         \
            template <dummy_parameter dummy, typename type, reapply(typename can_call_valueof_template_argument, comma, count)>                                                                          \
            struct valueof<dummy, Traits::call, type, reapply(can_call_valueof_template_argument, comma, count), alias<typeof(null(instanceof<type>(reapply(can_call_valueof_argument, comma, count))))> > final { \
              template <enum operation subcontrol, reapply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate;                                                                        \
              private: static bool const value = true;                                                                                                                                                            \
            };
          # define can_call_valueof_argument(count)          instanceof<type ## count>()
          # define can_call_valueof_template_argument(count) type ## count

          apply(can_call_valueof, empty, previous(LAPYS_MAX_ARITY))

          #undef can_call_valueof
          # undef can_call_valueof_argument
          # undef can_call_valueof_template_argument

          #ifdef __cpp_impl_three_way_comparison
            template <dummy_parameter dummy, typename typeA, typename typeB>
            struct valueof<dummy, Traits::compare, typeA, typeB, alias<typeof(null(instanceof<typeA>() <=> instanceof<typeB>()))> > final {
              template <enum operation subcontrol, apply(can_nop_template_parameter, comma, LAPYS_MAX_ARITY)> friend struct can_operate;
              private: static bool const value = true;
            };
          #endif

        public:
          static bool const value = true;
      };

      template <typename typeA, typename typeB> struct can_operate<Traits::add,                typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::add,                typeA, typeB>::value; };
      template <typename typeA>                 struct can_operate<Traits::address,            typeA>        final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::address,            typeA>       ::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::assign,             typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::assign,             typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::assign_add,         typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::assign_add,         typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::assign_bitwise_and, typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::assign_bitwise_and, typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::assign_bitwise_or,  typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::assign_bitwise_or,  typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::assign_bitwise_xor, typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::assign_bitwise_xor, typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::assign_divide,      typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::assign_divide,      typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::assign_left_shift,  typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::assign_left_shift,  typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::assign_modulo,      typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::assign_modulo,      typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::assign_multiply,    typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::assign_multiply,    typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::assign_right_shift, typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::assign_right_shift, typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::assign_subtract,    typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::assign_subtract,    typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::bitwise_and,        typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::bitwise_and,        typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::bitwise_or,         typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::bitwise_or,         typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::bitwise_xor,        typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::bitwise_xor,        typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::boolean_and,        typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::boolean_and,        typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::boolean_or,         typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::boolean_or,         typeA, typeB>::value; };
      template <typename typeA>                 struct can_operate<Traits::call,               typeA>        final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::call,               typeA>       ::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::cast,               typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::cast,               typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::comma,              typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::comma,              typeA, typeB>::value; };
      template <typename typeA>                 struct can_operate<Traits::complement,         typeA>        final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::complement,         typeA>       ::value; };
      template <typename typeA>                 struct can_operate<Traits::dereference,        typeA>        final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::dereference,        typeA>       ::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::divide,             typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::divide,             typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::equals,             typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::equals,             typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::equals_greater,     typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::equals_greater,     typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::equals_lesser,      typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::equals_lesser,      typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::greater,            typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::greater,            typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::left_shift,         typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::left_shift,         typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::lesser,             typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::lesser,             typeA, typeB>::value; };
      template <typename typeA>                 struct can_operate<Traits::minus,              typeA>        final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::minus,              typeA>       ::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::modulo,             typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::modulo,             typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::multiply,           typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::multiply,           typeA, typeB>::value; };
      template <typename typeA>                 struct can_operate<Traits::negate,             typeA>        final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::negate,             typeA>       ::value; };
      template <typename typeA>                 struct can_operate<Traits::plus,               typeA>        final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::plus,               typeA>       ::value; };
      template <typename typeA>                 struct can_operate<Traits::post_decrement,     typeA>        final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::post_decrement,     typeA>       ::value; };
      template <typename typeA>                 struct can_operate<Traits::post_increment,     typeA>        final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::post_increment,     typeA>       ::value; };
      template <typename typeA>                 struct can_operate<Traits::pre_decrement,      typeA>        final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::pre_decrement,      typeA>       ::value; };
      template <typename typeA>                 struct can_operate<Traits::pre_increment,      typeA>        final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::pre_increment,      typeA>       ::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::right_shift,        typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::right_shift,        typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::subscript,          typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::subscript,          typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::subtract,           typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::subtract,           typeA, typeB>::value; };
      template <typename typeA, typename typeB> struct can_operate<Traits::unequals,           typeA, typeB> final { static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::unequals,           typeA, typeB>::value; };

      #define can_call(count)                                                                                                                                      \
        template <typename type, reapply(typename can_call_template_argument, comma, count)>                                                                       \
        struct can_operate<Traits::call, type, reapply(can_call_template_argument, comma, count)> final {                                                           \
          static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::call, type, reapply(can_call_template_argument, comma, count)>::value; \
        };
      apply(can_call, empty, previous(LAPYS_MAX_ARITY))
      #undef can_call

      #ifdef __cpp_impl_three_way_comparison
        template <typename typeA, typename typeB>
        struct can_operate<Traits::compare, typeA, typeB> final {
          static bool const value = can_operate<Traits::nop>::template valueof<DUMMY, Traits::compare, typeA, typeB>::value;
        };
      #endif

      // ... ->> accumulate, collection, index_collection, index_sequence, integer_collection, integer_sequence, maximum, minimum, sequence, total
      #ifdef __cpp_variadic_templates
        template <enum operation control, typename base, base...>
        struct accumulate {};
          template <typename base, base... values>
          struct maximum : public accumulate<Traits::equals_greater, base, values...> {
            private:
              template <base subvalue, base...>
              struct valueof final {
                friend struct maximum<base, values...>;
                private: constvar static base const value varinit(subvalue);
              };

              template <base subvalueA, base subvalueB, base... subvalues>
              struct valueof<subvalueA, subvalueB, subvalues...> final {
                friend struct maximum<base, values...>;
                private: constvar static base const value varinit((valueof<(subvalueB > subvalueA ? subvalueB : subvalueA), subvalues...>::value));
              };

            public:
              constvar static base const value varinit(valueof<values...>::value);
          };

          // ...
          template <typename base, base... values>
          struct minimum : public accumulate<Traits::equals_lesser, base, values...> {
            private:
              template <base subvalue, base...>
              struct valueof final {
                friend struct minimum<base, values...>;
                private: constvar static base const value varinit(subvalue);
              };

              template <base subvalueA, base subvalueB, base... subvalues>
              struct valueof<subvalueA, subvalueB, subvalues...> final {
                friend struct minimum<base, values...>;
                private: constvar static base const value varinit((valueof<(subvalueB < subvalueA ? subvalueB : subvalueA), subvalues...>::value));
              };

            public:
              constvar static base const value varinit(valueof<values...>::value);
          };

          // ...
          template <typename base, base... values>
          struct total : public accumulate<Traits::add, base, values...> {
            private:
              template <base subvalue, base...>
              struct valueof final {
                friend struct total<base, values...>;
                private: constvar static base const value varinit(subvalue);
              };

              template <base subvalueA, base subvalueB, base... subvalues>
              struct valueof<subvalueA, subvalueB, subvalues...> final {
                friend struct total<base, values...>;
                private: constvar static base const value varinit((valueof<subvalueA + subvalueB, subvalues...>::value));
              };

            public:
              constvar static base const value varinit(valueof<values...>::value);
          };

        // ...
        template <typename base, base...>
        struct collection {};
          template <typename base, base... integers>
          struct integer_collection : public collection<typename conditional<is_integral<base>::value, base>::type, integers...> {};
            template <std::size_t... indexes>
            struct index_collection : public integer_collection<std::size_t, indexes...> {};

        // ...
        template <typename base, base start, base end, base step = conditional<is_scalar<base>::value || can_initialize<direct_init, base, unsigned>::value, defer<constructor<unsigned>::template apply<1u>::template call, base>, defer<constructor<>::template apply<>::template call, base> >::type::type::value, template <base, base, base> class sentinel = generator<base>::template sequence_sentinel>
        struct sequence {
          private:
            template <std::size_t, base, class>
            struct generate;

            template <std::size_t depth, base current, base... values>
            struct generate<depth, current, collection<base, values...> > : public generate<
              (depth - 1u) * sentinel<current + step, end, step>::value,
              current + step,
              collection<base, values..., current>
            > {};

            template <base current, base... values>
            struct generate<0u, current, collection<base, values...> > {
              constvar static base const recent varinit(current);
              typedef collection<base, values...> type;
            };

            // ...
            template <base current, class, class, bool>
            struct valueof;

            template <base current, base... values, base... next>
            struct valueof<current, collection<base, values...>, collection<base, next...>, true> final {
              friend struct sequence<base, start, end, step, sentinel>;
              private:
                typedef typename valueof<
                  generate<LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH, current, collection<base> >::recent,
                  collection<base, values..., next...>,
                  typename generate<LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH, current, collection<base> >::type,
                  sentinel<generate<LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH, current, collection<base> >::recent, end, step>::value
                >::type type;
            };

            template <base current, base... values, base... next>
            struct valueof<current, collection<base, values...>, collection<base, next...>, false> final {
              friend struct sequence<base, start, end, step, sentinel>;
              private: typedef collection<base, values..., next...> type;
            };

          public:
            typedef typename valueof<start, collection<base>, collection<base>, sentinel<start, end, step>::value>::type type;
        };
          template <typename base, base start, base end, base step = 1, template <base, base, base> class sentinel = generator<base>::template sequence_sentinel>
          struct integer_sequence : public sequence<typename conditional<is_integral<base>::value, base>::type, start, end, step, sentinel> {};
            template <std::size_t start, std::size_t end, std::size_t step = 1u, template <std::size_t, std::size_t, std::size_t> class sentinel = generator<std::size_t>::template sequence_sentinel>
            struct index_sequence : public integer_sequence<std::size_t, start, end, step, sentinel> {};
      #else
        #define countof(accumulate_trait)                                                                                                                                   \
          template <std::size_t count, std::size_t index, base, apply(base template_subargument, comma, previous(LAPYS_END_ARITY))>                                         \
          struct countof final {                                                                                                                                            \
            friend struct accumulate_trait;                                                                                                                                 \
            private: static std::size_t const value = countof<index, index + 1u, apply(template_subargument, comma, previous(LAPYS_END_ARITY)), nilof<base>::value>::value; \
          };                                                                                                                                                                \
                                                                                                                                                                            \
          template <std::size_t count, std::size_t index, apply(base template_subargument, comma, previous(LAPYS_END_ARITY))>                                               \
          struct countof<count, index, nilof<base>::value, apply(template_subargument, comma, previous(LAPYS_END_ARITY))> final {                                           \
            friend struct accumulate_trait;                                                                                                                                 \
            private: static std::size_t const value = countof<count, index + 1u, apply(template_subargument, comma, previous(LAPYS_END_ARITY)), nilof<base>::value>::value; \
          };                                                                                                                                                                \
                                                                                                                                                                            \
          template <std::size_t count, apply(base template_subargument, comma, LAPYS_END_ARITY)>                                                                            \
          struct countof<count, LAPYS_END_ARITY, apply(template_subargument, comma, LAPYS_END_ARITY)> final {                                                               \
            friend struct accumulate_trait;                                                                                                                                 \
            private: static std::size_t const value = count;                                                                                                                \
          };                                                                                                                                                                \
                                                                                                                                                                            \
          template <std::size_t count, apply(base template_subargument, comma, previous(LAPYS_END_ARITY))>                                                                  \
          struct countof<count, LAPYS_END_ARITY, nilof<base>::value, apply(template_subargument, comma, previous(LAPYS_END_ARITY))> final {                                 \
            friend struct accumulate_trait;                                                                                                                                 \
            private: static std::size_t const value = count;                                                                                                                \
          };
        #define index_collection_template_parameter(count) std::size_t value ## count = 0u
        #define template_argument(count)  value ## count
        #define template_parameter(count) value ## count = nilof<base>::value
        # define template_subargument(count) subvalue ## count

        template <enum operation control, typename base, apply(base template_parameter, comma, LAPYS_END_ARITY)>
        struct accumulate {};
          template <typename base, apply(base template_parameter, comma, LAPYS_END_ARITY)>
          struct maximum : public accumulate<Traits::equals_greater, base, apply(template_argument, comma, LAPYS_END_ARITY)> {
            private:
              countof(maximum)

              // ...
              template <std::size_t count, base subvalueA, base subvalueB, apply(base template_subargument, comma, previous(previous(LAPYS_END_ARITY)))>
              struct valueof final {
                friend struct maximum<base, apply(template_argument, comma, LAPYS_END_ARITY)>;
                private: constvar static base const value varinit((valueof<count - 1u, (subvalueB > subvalueA ? subvalueB : subvalueA), apply(template_subargument, comma, previous(previous(LAPYS_END_ARITY))), nilof<base>::value>::value));
              };

              template <base subvalue, apply(base template_subargument, comma, previous(LAPYS_END_ARITY))>
              struct valueof<0u, subvalue, apply(template_subargument, comma, previous(LAPYS_END_ARITY))> final {
                friend struct maximum<base, apply(template_argument, comma, LAPYS_END_ARITY)>;
                private: constvar static base const value varinit(subvalue);
              };

            public:
              constvar static base const value varinit((valueof<countof<0u, 0u, apply(template_argument, comma, LAPYS_END_ARITY)>::value, apply(template_argument, comma, LAPYS_END_ARITY)>::value));
          };

          // ...
          template <typename base, apply(base template_parameter, comma, LAPYS_END_ARITY)>
          struct minimum : public accumulate<Traits::equals_lesser, base, apply(template_argument, comma, LAPYS_END_ARITY)> {
            private:
              countof(minimum)

              // ...
              template <std::size_t count, base subvalueA, base subvalueB, apply(base template_subargument, comma, previous(previous(LAPYS_END_ARITY)))>
              struct valueof final {
                friend struct minimum<base, apply(template_argument, comma, LAPYS_END_ARITY)>;
                private: constvar static base const value varinit((valueof<count - 1u, (subvalueB < subvalueA ? subvalueB : subvalueA), apply(template_subargument, comma, previous(previous(LAPYS_END_ARITY))), nilof<base>::value>::value));
              };

              template <base subvalue, apply(base template_subargument, comma, previous(LAPYS_END_ARITY))>
              struct valueof<0u, subvalue, apply(template_subargument, comma, previous(LAPYS_END_ARITY))> final {
                friend struct minimum<base, apply(template_argument, comma, LAPYS_END_ARITY)>;
                private: constvar static base const value varinit(subvalue);
              };

            public:
              constvar static base const value varinit((valueof<countof<0u, 0u, apply(template_argument, comma, LAPYS_END_ARITY)>::value, apply(template_argument, comma, LAPYS_END_ARITY)>::value));
          };

          // ...
          template <typename base, apply(base template_parameter, comma, LAPYS_END_ARITY)>
          struct total : public accumulate<Traits::add, base, apply(template_argument, comma, LAPYS_END_ARITY)> {
            private:
              countof(total)

              template <std::size_t count, base subvalueA, base subvalueB, apply(base template_subargument, comma, previous(previous(LAPYS_END_ARITY)))>
              struct valueof final {
                friend struct total<base, apply(template_argument, comma, LAPYS_END_ARITY)>;
                private: constvar static base const value varinit((valueof<count - 1u, subvalueA + subvalueB, apply(template_subargument, comma, previous(previous(LAPYS_END_ARITY))), nilof<base>::value>::value));
              };

              template <base subvalue, apply(base template_subargument, comma, previous(LAPYS_END_ARITY))>
              struct valueof<0u, subvalue, apply(template_subargument, comma, previous(LAPYS_END_ARITY))> final {
                friend struct total<base, apply(template_argument, comma, LAPYS_END_ARITY)>;
                private: constvar static base const value varinit(subvalue);
              };

            public:
              constvar static base const value varinit((valueof<countof<0u, 0u, apply(template_argument, comma, LAPYS_END_ARITY)>::value, apply(template_argument, comma, LAPYS_END_ARITY)>::value));
          };

        // ...
        template <typename base, apply(base = nilof<base>::value apply_empty, comma, LAPYS_END_ARITY), apply(base = nilof<base>::value apply_empty, comma, LAPYS_MAX_ARITY)>
        struct collection {};
          template <typename base, apply(base template_parameter, comma, LAPYS_END_ARITY)>
          struct integer_collection : public collection<typename conditional<is_integral<base>::value, base>::type, apply(template_argument, comma, LAPYS_END_ARITY)> {};
            template <apply(index_collection_template_parameter, comma, LAPYS_END_ARITY)>
            struct index_collection : public integer_collection<std::size_t, apply(template_argument, comma, LAPYS_END_ARITY)> {};

        // ...
        template <typename base, base start, base end, base step = conditional<is_scalar<base>::value || can_initialize<direct_init, base, unsigned>::value, defer<constructor<unsigned>::template apply<1u>::template call, base>, defer<constructor<>::template apply<>::template call, base> >::type::type::value, template <base, base, base> class sentinel = generator<base>::template sequence_sentinel>
        struct sequence {
          private:
            template <std::size_t, base, class>
            struct generate;

            #define sequence_generate(count)                                                                                                    \
              template <std::size_t depth, base current, reapply(base sequence_generate_template_argument, comma, count)>                       \
              struct generate<depth, current, collection<base, reapply(sequence_generate_template_argument, comma, count)> > : public generate< \
                (depth - 1u) * sentinel<current + step, end, step>::value,                                                                      \
                current + step,                                                                                                                 \
                collection<base, reapply(sequence_generate_template_argument, comma, count), current>                                           \
              > {};                                                                                                                             \
                                                                                                                                                \
              template <base current, reapply(base sequence_generate_template_argument, comma, count)>                                          \
              struct generate<0u, current, collection<base, reapply(sequence_generate_template_argument, comma, count)> > {                     \
                constvar static base const recent varinit(current);                                                                             \
                typedef collection<base, reapply(sequence_generate_template_argument, comma, count)> type;                                      \
              };
            # define sequence_generate_template_argument(count) value ## count

            template <std::size_t depth, base current>
            struct generate<depth, current, collection<base> > : public generate<
              (depth - 1u) * sentinel<current + step, end, step>::value,
              current + step,
              collection<base, current>
            > {};

            template <base current>
            struct generate<0u, current, collection<base> > {
              constvar static base const recent varinit(current);
              typedef collection<base> type;
            };

            apply(sequence_generate, empty, previous(LAPYS_MAX_ARITY))

            template <base current, apply(base sequence_generate_template_argument, comma, LAPYS_MAX_ARITY)>
            struct generate<0u, current, collection<base, apply(sequence_generate_template_argument, comma, LAPYS_MAX_ARITY)> > {
              constvar static base const recent varinit(current);
              typedef collection<base, apply(sequence_generate_template_argument, comma, LAPYS_MAX_ARITY)> type;
            };

            #undef sequence_generate
            # undef sequence_generate_template_argument

            // ...
            template <base current, class, class, bool>
            struct valueof;

            #define sequence_valueof(count)                                                                                                                                                                          \
              template <base current, reapply(base sequence_valueof_template_argument, comma, count), reapply(base sequence_valueof_next_argument, comma, LAPYS_MAX_ARITY)>                                          \
              struct valueof<current, collection<base, reapply(sequence_valueof_template_argument, comma, count)>, collection<base, reapply(sequence_valueof_next_argument, comma, LAPYS_MAX_ARITY)>, true> final {  \
                friend struct sequence<base, start, end, step, sentinel>;                                                                                                                                            \
                private:                                                                                                                                                                                             \
                  typedef typename valueof<                                                                                                                                                                          \
                    generate<(LAPYS_MAX_ARITY < LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH ? LAPYS_MAX_ARITY : LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH), current, collection<base> >::recent,                             \
                    collection<base, reapply(sequence_valueof_template_argument, comma, count), reapply(sequence_valueof_next_argument, comma, LAPYS_MAX_ARITY)>,                                                    \
                    typename generate<(LAPYS_MAX_ARITY < LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH ? LAPYS_MAX_ARITY : LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH), current, collection<base> >::type,                      \
                    sentinel<generate<(LAPYS_MAX_ARITY < LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH ? LAPYS_MAX_ARITY : LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH), current, collection<base> >::recent, end, step>::value  \
                  >::type type;                                                                                                                                                                                      \
              };                                                                                                                                                                                                     \
                                                                                                                                                                                                                     \
              template <base current, reapply(base sequence_valueof_template_argument, comma, count), reapply(base sequence_valueof_next_argument, comma, LAPYS_MAX_ARITY)>                                          \
              struct valueof<current, collection<base, reapply(sequence_valueof_template_argument, comma, count)>, collection<base, reapply(sequence_valueof_next_argument, comma, LAPYS_MAX_ARITY)>, false> final { \
                friend struct sequence<base, start, end, step, sentinel>;                                                                                                                                            \
                private: typedef collection<base, reapply(sequence_valueof_template_argument, comma, count), reapply(sequence_valueof_next_argument, comma, LAPYS_MAX_ARITY)> type;                                  \
              };
            # define sequence_valueof_next_argument(count)     next  ## count
            # define sequence_valueof_template_argument(count) value ## count

            template <base current, apply(base sequence_valueof_next_argument, comma, LAPYS_MAX_ARITY)>
            struct valueof<current, collection<base>, collection<base, apply(sequence_valueof_next_argument, comma, LAPYS_MAX_ARITY)>, true> final {
              friend struct sequence<base, start, end, step, sentinel>;
              private:
                typedef typename valueof<
                  generate<(LAPYS_MAX_ARITY < LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH ? LAPYS_MAX_ARITY : LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH), current, collection<base> >::recent,
                  collection<base, apply(sequence_valueof_next_argument, comma, LAPYS_MAX_ARITY)>,
                  typename generate<(LAPYS_MAX_ARITY < LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH ? LAPYS_MAX_ARITY : LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH), current, collection<base> >::type,
                  sentinel<generate<(LAPYS_MAX_ARITY < LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH ? LAPYS_MAX_ARITY : LAPYS_MAX_TEMPLATE_INSTANTIATION_DEPTH), current, collection<base> >::recent, end, step>::value
                >::type type;
            };

            template <base current, apply(base sequence_valueof_next_argument, comma, LAPYS_MAX_ARITY)>
            struct valueof<current, collection<base>, collection<base, apply(sequence_valueof_next_argument, comma, LAPYS_MAX_ARITY)>, false> final {
              friend struct sequence<base, start, end, step, sentinel>;
              private: typedef collection<base, apply(sequence_valueof_next_argument, comma, LAPYS_MAX_ARITY)> type;
            };

            apply(sequence_valueof, empty, LAPYS_END_ARITY)

            #undef sequence_valueof
            # undef sequence_valueof_next_argument
            # undef sequence_valueof_template_argument

          public:
            typedef typename valueof<start, collection<base>, collection<base>, sentinel<start, end, step>::value>::type type;
        };
          template <typename base, base start, base end, base step = 1, template <base, base, base> class sentinel = generator<base>::template sequence_sentinel>
          struct integer_sequence : public sequence<typename conditional<is_integral<base>::value, base>::type, start, end, step, sentinel> {};
            template <std::size_t start, std::size_t end, std::size_t step = 1u, template <std::size_t, std::size_t, std::size_t> class sentinel = generator<std::size_t>::template sequence_sentinel>
            struct index_sequence : public integer_sequence<std::size_t, start, end, step, sentinel> {};

        #undef countof
        #undef index_collection_template_parameter
        #undef template_argument
        #undef template_parameter
        # undef template_subargument
      #endif

      #undef can_call_template_argument
      #undef can_nop_template_parameter
      # undef can_nop_valueof_template_parameter
      #undef can_operate_template_parameter
    }

    namespace Traits {
      template <typename type>                       struct assess_bound                  final { typedef type base; static bool const bounded = false; static std::size_t const length = 0u;       };
      template <typename type>                       struct assess_bound<type []>         final { typedef type base; static bool const bounded = false; static std::size_t const length = 0u;       };
      template <typename type, std::size_t capacity> struct assess_bound<type [capacity]> final { typedef type base; static bool const bounded = true;  static std::size_t const length = capacity; };

      // ...
      template <typename base> struct assess_const             final { typedef base type; };
      template <typename base> struct assess_const<base const> final { typedef base type; };

      // ...
      template <typename type>
      struct assess_function final {
        typedef type base;

        static std::size_t const arity        = 0u;
        static bool        const constness    = false;
        static bool        const except       = false;
        static bool        const lvalue       = false;
        static bool        const member       = false;
        static bool        const rvalue       = false;
        static bool        const variadic     = false;
        static bool        const volatileness = false;
      };

      #if CPP_VERSION < 2011uL
        #define assess_function(count)                                                                                                                                                                                                                                                                                                                                                                                                                         \
          template <typename type, reapply(typename assess_function_template_parameter, comma, count)>               struct assess_function<type (reapply(assess_function_template_parameter, comma, count))>                                final { typedef type base; static std::size_t const arity = count; static bool const constness = false, except = true, lvalue = false, member = false, rvalue = false, variadic = false, volatileness = false; }; \
          template <typename type, reapply(typename assess_function_template_parameter, comma, count)>               struct assess_function<type (reapply(assess_function_template_parameter, comma, count), ...)>                           final { typedef type base; static std::size_t const arity = count; static bool const constness = false, except = true, lvalue = false, member = false, rvalue = false, variadic = true,  volatileness = false; }; \
          template <typename type, reapply(typename assess_function_template_parameter, comma, count)>               struct assess_function<type (*)(reapply(assess_function_template_parameter, comma, count))>                             final { typedef type base; static std::size_t const arity = count; static bool const constness = false, except = true, lvalue = false, member = false, rvalue = false, variadic = false, volatileness = false; }; \
          template <typename type, reapply(typename assess_function_template_parameter, comma, count)>               struct assess_function<type (*)(reapply(assess_function_template_parameter, comma, count), ...)>                        final { typedef type base; static std::size_t const arity = count; static bool const constness = false, except = true, lvalue = false, member = false, rvalue = false, variadic = true,  volatileness = false; }; \
          template <typename type, class object, reapply(typename assess_function_template_parameter, comma, count)> struct assess_function<type (object::*)(reapply(assess_function_template_parameter, comma, count))>                     final { typedef type base; static std::size_t const arity = count; static bool const constness = false, except = true, lvalue = true,  member = true,  rvalue = false, variadic = false, volatileness = false; }; \
          template <typename type, class object, reapply(typename assess_function_template_parameter, comma, count)> struct assess_function<type (object::*)(reapply(assess_function_template_parameter, comma, count)) const>               final { typedef type base; static std::size_t const arity = count; static bool const constness = true,  except = true, lvalue = true,  member = true,  rvalue = false, variadic = false, volatileness = false; }; \
          template <typename type, class object, reapply(typename assess_function_template_parameter, comma, count)> struct assess_function<type (object::*)(reapply(assess_function_template_parameter, comma, count)) volatile>            final { typedef type base; static std::size_t const arity = count; static bool const constness = false, except = true, lvalue = true,  member = true,  rvalue = false, variadic = false, volatileness = true;  }; \
          template <typename type, class object, reapply(typename assess_function_template_parameter, comma, count)> struct assess_function<type (object::*)(reapply(assess_function_template_parameter, comma, count)) const volatile>      final { typedef type base; static std::size_t const arity = count; static bool const constness = true,  except = true, lvalue = true,  member = true,  rvalue = false, variadic = false, volatileness = true;  }; \
          template <typename type, class object, reapply(typename assess_function_template_parameter, comma, count)> struct assess_function<type (object::*)(reapply(assess_function_template_parameter, comma, count), ...)>                final { typedef type base; static std::size_t const arity = count; static bool const constness = false, except = true, lvalue = true,  member = true,  rvalue = false, variadic = true,  volatileness = false; }; \
          template <typename type, class object, reapply(typename assess_function_template_parameter, comma, count)> struct assess_function<type (object::*)(reapply(assess_function_template_parameter, comma, count), ...) const>          final { typedef type base; static std::size_t const arity = count; static bool const constness = true,  except = true, lvalue = true,  member = true,  rvalue = false, variadic = true,  volatileness = false; }; \
          template <typename type, class object, reapply(typename assess_function_template_parameter, comma, count)> struct assess_function<type (object::*)(reapply(assess_function_template_parameter, comma, count), ...) volatile>       final { typedef type base; static std::size_t const arity = count; static bool const constness = false, except = true, lvalue = true,  member = true,  rvalue = false, variadic = true,  volatileness = true;  }; \
          template <typename type, class object, reapply(typename assess_function_template_parameter, comma, count)> struct assess_function<type (object::*)(reapply(assess_function_template_parameter, comma, count), ...) const volatile> final { typedef type base; static std::size_t const arity = count; static bool const constness = true,  except = true, lvalue = true,  member = true,  rvalue = false, variadic = true,  volatileness = true;  };
        # define assess_function_template_parameter(count) type ## count

        template <typename type>               struct assess_function<type ()>                              final { typedef type base; static std::size_t const arity = 0u; static bool const constness = false, except = true, lvalue = false, member = false, rvalue = false, variadic = false, volatileness = false; };
        template <typename type>               struct assess_function<type (...)>                           final { typedef type base; static std::size_t const arity = 0u; static bool const constness = false, except = true, lvalue = false, member = false, rvalue = false, variadic = true,  volatileness = false; };
        template <typename type>               struct assess_function<type (*)()>                           final { typedef type base; static std::size_t const arity = 0u; static bool const constness = false, except = true, lvalue = false, member = false, rvalue = false, variadic = false, volatileness = false; };
        template <typename type>               struct assess_function<type (*)(...)>                        final { typedef type base; static std::size_t const arity = 0u; static bool const constness = false, except = true, lvalue = false, member = false, rvalue = false, variadic = true,  volatileness = false; };
        template <typename type, class object> struct assess_function<type (object::*)()>                   final { typedef type base; static std::size_t const arity = 0u; static bool const constness = false, except = true, lvalue = true,  member = true,  rvalue = false, variadic = false, volatileness = false; };
        template <typename type, class object> struct assess_function<type (object::*)() const>             final { typedef type base; static std::size_t const arity = 0u; static bool const constness = true,  except = true, lvalue = true,  member = true,  rvalue = false, variadic = false, volatileness = false; };
        template <typename type, class object> struct assess_function<type (object::*)() volatile>          final { typedef type base; static std::size_t const arity = 0u; static bool const constness = false, except = true, lvalue = true,  member = true,  rvalue = false, variadic = false, volatileness = true;  };
        template <typename type, class object> struct assess_function<type (object::*)() const volatile>    final { typedef type base; static std::size_t const arity = 0u; static bool const constness = true,  except = true, lvalue = true,  member = true,  rvalue = false, variadic = false, volatileness = true;  };
        template <typename type, class object> struct assess_function<type (object::*)(...)>                final { typedef type base; static std::size_t const arity = 0u; static bool const constness = false, except = true, lvalue = true,  member = true,  rvalue = false, variadic = true,  volatileness = false; };
        template <typename type, class object> struct assess_function<type (object::*)(...) const>          final { typedef type base; static std::size_t const arity = 0u; static bool const constness = true,  except = true, lvalue = true,  member = true,  rvalue = false, variadic = true,  volatileness = false; };
        template <typename type, class object> struct assess_function<type (object::*)(...) volatile>       final { typedef type base; static std::size_t const arity = 0u; static bool const constness = false, except = true, lvalue = true,  member = true,  rvalue = false, variadic = true,  volatileness = true;  };
        template <typename type, class object> struct assess_function<type (object::*)(...) const volatile> final { typedef type base; static std::size_t const arity = 0u; static bool const constness = true,  except = true, lvalue = true,  member = true,  rvalue = false, variadic = true,  volatileness = true;  };
        apply(assess_function, empty, LAPYS_MAX_ARITY)

        #undef assess_function
        # undef assess_function_template_parameter
      #else
        template <typename type, typename... types> struct assess_function<type (types...)>                       final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = true, lvalue = false, member = false, rvalue = false, variadic = false, volatileness = false; };
        template <typename type, typename... types> struct assess_function<type (types...) &>                     final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = true, lvalue = true,  member = true,  rvalue = false, variadic = false, volatileness = false; };
        template <typename type, typename... types> struct assess_function<type (types...) &&>                    final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = true, lvalue = false, member = true,  rvalue = true,  variadic = false, volatileness = false; };
        template <typename type, typename... types> struct assess_function<type (types...) const&>                final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = true,  except = true, lvalue = true,  member = true,  rvalue = false, variadic = false, volatileness = false; };
        template <typename type, typename... types> struct assess_function<type (types...) const&&>               final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = true,  except = true, lvalue = false, member = true,  rvalue = true,  variadic = false, volatileness = false; };
        template <typename type, typename... types> struct assess_function<type (types...) const volatile&>       final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = true,  except = true, lvalue = true,  member = true,  rvalue = false, variadic = false, volatileness = true;  };
        template <typename type, typename... types> struct assess_function<type (types...) const volatile&&>      final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = true,  except = true, lvalue = false, member = true,  rvalue = true,  variadic = false, volatileness = true;  };
        template <typename type, typename... types> struct assess_function<type (types...) volatile&>             final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = true, lvalue = true,  member = true,  rvalue = false, variadic = false, volatileness = false; };
        template <typename type, typename... types> struct assess_function<type (types...) volatile&&>            final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = true, lvalue = false, member = true,  rvalue = true,  variadic = false, volatileness = false; };
        template <typename type, typename... types> struct assess_function<type (types..., ...)>                  final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = true, lvalue = false, member = false, rvalue = false, variadic = true,  volatileness = false; };
        template <typename type, typename... types> struct assess_function<type (types..., ...) &>                final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = true, lvalue = true,  member = true,  rvalue = false, variadic = true,  volatileness = false; };
        template <typename type, typename... types> struct assess_function<type (types..., ...) &&>               final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = true, lvalue = false, member = true,  rvalue = true,  variadic = true,  volatileness = false; };
        template <typename type, typename... types> struct assess_function<type (types..., ...) const&>           final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = true,  except = true, lvalue = true,  member = true,  rvalue = false, variadic = true,  volatileness = false; };
        template <typename type, typename... types> struct assess_function<type (types..., ...) const&&>          final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = true,  except = true, lvalue = false, member = true,  rvalue = true,  variadic = true,  volatileness = false; };
        template <typename type, typename... types> struct assess_function<type (types..., ...) const volatile&>  final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = true,  except = true, lvalue = true,  member = true,  rvalue = false, variadic = true,  volatileness = true;  };
        template <typename type, typename... types> struct assess_function<type (types..., ...) const volatile&&> final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = true,  except = true, lvalue = false, member = true,  rvalue = true,  variadic = true,  volatileness = true;  };
        template <typename type, typename... types> struct assess_function<type (types..., ...) volatile&>        final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = true, lvalue = true,  member = true,  rvalue = false, variadic = true,  volatileness = false; };
        template <typename type, typename... types> struct assess_function<type (types..., ...) volatile&&>       final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = true, lvalue = false, member = true,  rvalue = true,  variadic = true,  volatileness = false; };
        #if CPP_VERSION >= 2017uL
          template <typename type, typename... types> struct assess_function<type (types...) noexcept>                       final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = false, lvalue = false, member = false, rvalue = false, variadic = false, volatileness = false; };
          template <typename type, typename... types> struct assess_function<type (types...) & noexcept>                     final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = false, lvalue = true,  member = true,  rvalue = false, variadic = false, volatileness = false; };
          template <typename type, typename... types> struct assess_function<type (types...) && noexcept>                    final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = false, lvalue = false, member = true,  rvalue = true,  variadic = false, volatileness = false; };
          template <typename type, typename... types> struct assess_function<type (types...) const& noexcept>                final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = true,  except = false, lvalue = true,  member = true,  rvalue = false, variadic = false, volatileness = false; };
          template <typename type, typename... types> struct assess_function<type (types...) const&& noexcept>               final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = true,  except = false, lvalue = false, member = true,  rvalue = true,  variadic = false, volatileness = false; };
          template <typename type, typename... types> struct assess_function<type (types...) const volatile& noexcept>       final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = true,  except = false, lvalue = true,  member = true,  rvalue = false, variadic = false, volatileness = true;  };
          template <typename type, typename... types> struct assess_function<type (types...) const volatile&& noexcept>      final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = true,  except = false, lvalue = false, member = true,  rvalue = true,  variadic = false, volatileness = true;  };
          template <typename type, typename... types> struct assess_function<type (types...) volatile& noexcept>             final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = false, lvalue = true,  member = true,  rvalue = false, variadic = false, volatileness = false; };
          template <typename type, typename... types> struct assess_function<type (types...) volatile&& noexcept>            final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = false, lvalue = false, member = true,  rvalue = true,  variadic = false, volatileness = false; };
          template <typename type, typename... types> struct assess_function<type (types..., ...) noexcept>                  final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = false, lvalue = false, member = false, rvalue = false, variadic = true,  volatileness = false; };
          template <typename type, typename... types> struct assess_function<type (types..., ...) & noexcept>                final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = false, lvalue = true,  member = true,  rvalue = false, variadic = true,  volatileness = false; };
          template <typename type, typename... types> struct assess_function<type (types..., ...) && noexcept>               final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = false, lvalue = false, member = true,  rvalue = true,  variadic = true,  volatileness = false; };
          template <typename type, typename... types> struct assess_function<type (types..., ...) const& noexcept>           final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = true,  except = false, lvalue = true,  member = true,  rvalue = false, variadic = true,  volatileness = false; };
          template <typename type, typename... types> struct assess_function<type (types..., ...) const&& noexcept>          final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = true,  except = false, lvalue = false, member = true,  rvalue = true,  variadic = true,  volatileness = false; };
          template <typename type, typename... types> struct assess_function<type (types..., ...) const volatile& noexcept>  final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = true,  except = false, lvalue = true,  member = true,  rvalue = false, variadic = true,  volatileness = true;  };
          template <typename type, typename... types> struct assess_function<type (types..., ...) const volatile&& noexcept> final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = true,  except = false, lvalue = false, member = true,  rvalue = true,  variadic = true,  volatileness = true;  };
          template <typename type, typename... types> struct assess_function<type (types..., ...) volatile& noexcept>        final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = false, lvalue = true,  member = true,  rvalue = false, variadic = true,  volatileness = false; };
          template <typename type, typename... types> struct assess_function<type (types..., ...) volatile&& noexcept>       final { typedef type base; static std::size_t const arity = sizeof...(types); static bool const constness = false, except = false, lvalue = false, member = true,  rvalue = true,  variadic = true,  volatileness = false; };
        #endif
      #endif

      // ...
      template <typename type> struct assess_pointer                               final { typedef type base; static bool const membered = false; };
      template <typename type> struct assess_pointer<type*>                        final { typedef type base; static bool const membered = false; };
      template <typename type> struct assess_pointer<type* const>                  final { typedef type base; static bool const membered = false; };
      template <typename type> struct assess_pointer<type* const volatile>         final { typedef type base; static bool const membered = false; };
      template <typename type> struct assess_pointer<type* volatile>               final { typedef type base; static bool const membered = false; };
      template <class object, typename type> struct assess_pointer<type object::*> final { typedef type base; static bool const membered = true;  };

      // ...
      template <typename type> struct assess_reference        final { typedef type base; static bool const lvalue = false, rvalue = false; };
      template <typename type> struct assess_reference<type&> final { typedef type base; static bool const lvalue = true,  rvalue = false; };
      #if CPP_VERSION >= 2011uL
        template <typename type> struct assess_reference<type&&> final { typedef type base; static bool const lvalue = false, rvalue = true; };
      #endif

      // ...
      template <typename type> struct assess_volatile                final { typedef type base; };
      template <typename type> struct assess_volatile<type volatile> final { typedef type base; };

      // ...
      template <typename base>
      struct is_arithmetic final {
        static bool const value = (
          is_floating_point<base>::value ||
          is_integral      <base>::value
        );
      };

      // ...
      template <typename base>
      struct is_bound final {
        static bool const value = false == is_same<base, typename assess_bound<base>::base>::value;
      };

      // ...
      template <typename base>
      struct is_character final {
        static bool const value = (
          is_same<char,    typename remove_qualifiers<base>::type>::value ||
          is_same<wchar_t, typename remove_qualifiers<base>::type>::value ||
          #if CPP_VERSION >= 2011uL
            is_same<char16_t, typename remove_qualifiers<base>::type>::value ||
            is_same<char32_t, typename remove_qualifiers<base>::type>::value ||
          #endif
          #if CPP_VERSION >= 2020uL
            is_same<char8_t, typename remove_qualifiers<base>::type>::value ||
          #endif
          false
        );
      };

      // ...
      template <class base>
      struct is_class final {
        private:
          template <class, typename = std::size_t>
          struct valueof final {
            friend struct is_class<base>;
            private: static bool const value = false;
          };

          template <class type>
          struct valueof<type, typeof(sizeof(null type::*))> final {
            friend struct is_class<base>;
            private: static bool const value = true;
          };

        public:
          static bool const value = valueof<base>::value;
      };

      // ...
      template <typename base>
      struct is_const final {
        static bool const value = false == is_same<base, typename assess_const<base>::base>::value;
      };

      // ...
      template <class base>
      struct is_empty final {
        #if CPP_VERSION < 2011uL
          #if CPP_COMPILER == CPP__CLANG__COMPILER
          # if __has_builtin(__is_empty)
            static bool const value = __is_empty(base);
          # else
            static bool const value = false;
          # endif
          #elif CPP_COMPILER == CPP__GCC__COMPILER || CPP_COMPILER == CPP__ICC__COMPILER || CPP_COMPILER == CPP__MSVC__COMPILER
            static bool const value = __is_empty(base);
          #else
            static bool const value = false;
          #endif
        #else
          static bool const value = std::is_empty<base>::value;
        #endif
      };

      // ...
      template <typename base>
      struct is_enum final {
        #if CPP_VERSION < 2011uL
          #if CPP_COMPILER == CPP__CLANG__COMPILER
          # if __has_builtin(__is_enum)
            static bool const value = __is_enum(base);
          # else
            static bool const value = false;
          # endif
          #elif CPP_COMPILER == CPP__GCC__COMPILER || CPP_COMPILER == CPP__MSVC__COMPILER
            static bool const value = __is_enum(base);
          #elif CPP_COMPILER == CPP__ICC__COMPILER
          # ifdef __is_enum
            static bool const value = __is_enum(base);
          # else
            static bool const value = false;
          # endif
          #else
            static bool const value = false;
          #endif
        #else
          static bool const value = std::is_enum<base>::value;
        #endif
      };

      // ...
      template <class base>
      struct is_final final {
        #if CPP_VERSION < 2014uL
          #if CPP_COMPILER == CPP__CLANG__COMPILER
          # if __has_builtin(__is_final)
            static bool const value = __is_final(base);
          # else
            static bool const value = true;
          # endif
          #elif CPP_COMPILER == CPP__GCC__COMPILER || CPP_COMPILER == CPP__ICC__COMPILER
          # ifdef __is_final
            static bool const value = __is_final(base);
          # else
            static bool const value = true;
          #endif
          #elif CPP_COMPILER == CPP__MSVC__COMPILER
            static bool const value = __is_sealed(base);
          #else
            static bool const value = true;
          #endif
        #else
          static bool const value = std::is_final<base>::value;
        #endif
      };

      // ...
      template <typename base>
      struct is_floating_point final {
        static bool const value = (
          is_same<double,      typename remove_qualifiers<base>::type>::value ||
          is_same<float,       typename remove_qualifiers<base>::type>::value ||
          is_same<long double, typename remove_qualifiers<base>::type>::value
        );
      };

      // ...
      template <typename base>
      struct is_function final {
        static bool const value = false == is_same<base, typename assess_function<base>::base>::value;
      };

      // ...
      template <typename base>
      struct is_integral final {
        static bool const value = (
          is_same<int,            typename remove_qualifiers<base>::type>::value ||
          is_same<long,           typename remove_qualifiers<base>::type>::value ||
          is_same<short,          typename remove_qualifiers<base>::type>::value ||
          is_same<signed char,    typename remove_qualifiers<base>::type>::value ||
          is_same<unsigned char,  typename remove_qualifiers<base>::type>::value ||
          is_same<unsigned int,   typename remove_qualifiers<base>::type>::value ||
          is_same<unsigned long,  typename remove_qualifiers<base>::type>::value ||
          is_same<unsigned short, typename remove_qualifiers<base>::type>::value ||
          #if CPP_VERSION >= 2011uL || defined(LLONG_MAX)
            is_same<long long, typename remove_qualifiers<base>::type>::value ||
          #endif
          #if CPP_VERSION >= 2011uL || defined(ULLONG_MAX)
            is_same<unsigned long long, typename remove_qualifiers<base>::type>::value ||
          #endif
          false
        );
      };

      // ...
      template <typename base>
      struct is_lvalue_reference final {
        static bool const value = assess_reference<base>::lvalue;
      };

      // ...
      template <typename base>
      struct is_noexcept final {
        static bool const value = false == assess_function<base>::except;
      };

      // ...
      template <typename base>
      struct is_pointer final {
        static bool const value = false == is_same<base, typename assess_pointer<base>::base>::value;
      };

      // ...
      template <typename base>
      struct is_reference final {
        static bool const value = (
          is_lvalue_reference<base>::value ||
          is_rvalue_reference<base>::value
        );
      };

      // ...
      template <typename base>
      struct is_rvalue_reference final {
        static bool const value = assess_reference<base>::rvalue;
      };

      // ...
      template <typename, typename>
      struct is_same final {
        static bool const value = false;
      };

      template <typename base>
      struct is_same<base, base> final {
        static bool const value = true;
      };

      // ...
      template <typename base>
      struct is_scalar final {
        private:
          template <typename, bool>
          struct valueof;

          template <typename type>
          struct valueof<type, false> final {
            friend struct is_scalar<base>;
            private: static bool const value = (
              is_character     <type>::value ||
              is_enum          <type>::value ||
              is_floating_point<type>::value ||
              is_integral      <type>::value ||
              is_pointer       <type>::value
            );
          };

          template <typename type>
          struct valueof<type, true> final {
            friend struct is_scalar<base>;
            private: static bool const value = valueof<typename assess_bound<typename assess_reference<type>::base>::base, false>::value;
          };

        public:
          static bool const value = valueof<base, is_bound<base>::value || is_reference<base>::value>::value;
      };

      // ...
      template <class base>
      struct is_union final {
        #if CPP_VERSION < 2011uL
          #if CPP_COMPILER == CPP__CLANG__COMPILER
          # if __has_builtin(__is_union)
            static bool const value = __is_union(base);
          # else
            static bool const value = true;
          # endif
          #elif CPP_COMPILER == CPP__GCC__COMPILER || CPP_COMPILER == CPP__MSVC__COMPILER
            static bool const value = __is_union(base);
          #else
            static bool const value = true;
          #endif
        #else
          static bool const value = std::is_union<base>::value;
        #endif
      };

      // ...
      template <typename base>
      struct is_unscoped_enum final {
        private:
          noinline constfunc(true) static byte (&disambiguate(int const) noexcept)[true  + 1u];
          noinline constfunc(true) static byte (&disambiguate(...)       noexcept)[false + 1u];

        public:
          static bool const value = false == (
            is_arithmetic<base>::value ||
            is_bound     <base>::value ||
            is_function  <base>::value ||
            is_pointer   <base>::value ||
            is_reference <base>::value
          ) && sizeof(byte[true + 1u]) == sizeof(disambiguate(*static_cast<base*>(NULL)));
      };

      // ...
      template <typename base>
      struct is_scoped_enum final {
        static bool const value = is_enum<base>::value && false == is_unscoped_enum<base>::value;
      };

      // ...
      template <typename base>
      struct is_void final {
        static bool const value = is_same<void, typename remove_qualifiers<base>::type>::value;
      };

      // ...
      template <typename base>
      struct is_volatile final {
        static bool const value = false == is_same<base, typename assess_volatile<base>::base>::value;
      };

      // ...
      template <typename base>
      struct remove_bound final {
        typedef typename assess_bound<base>::type type;
      };

      // ...
      template <typename base>
      struct remove_const final {
        typedef typename assess_const<base>::type type;
      };

      // ...
      template <typename base>
      struct remove_lvalue_reference final {
        typedef typename conditional<is_lvalue_reference<base>::value, typename assess_reference<base>::base, base>::type type;
      };

      // ...
      template <typename base>
      struct remove_pointer final {
        typedef typename assess_pointer<base>::base type;
      };

      // ...
      template <typename base>
      struct remove_qualifiers final {
        typedef typename remove_const<typename remove_volatile<base>::type>::type type;
      };

      // ...
      template <typename base>
      struct remove_reference final {
        typedef typename assess_reference<base>::base type;
      };

      // ...
      template <typename base>
      struct remove_rvalue_reference final {
        typedef typename conditional<is_rvalue_reference<base>::value, typename assess_reference<base>::base, base>::type type;
      };

      // ...
      template <typename base>
      struct remove_volatile final {
        typedef typename assess_volatile<base>::base type;
      };

      // ...
      template <typename base> struct sign                 final { typedef base         type; };
      template <>              struct sign<unsigned char>  final { typedef signed char  type; };
      template <>              struct sign<unsigned int>   final { typedef signed int   type; };
      template <>              struct sign<unsigned long>  final { typedef signed long  type; };
      template <>              struct sign<unsigned short> final { typedef signed short type; };
      #if CPP_VERSION >= 2011uL || defined(ULLONG_MAX)
        template <> struct sign<unsigned long long> final { typedef signed long long type; };
      #endif

      // ...
      template <typename typeA, typeA valueA, typename typeB, typeB valueB>
      struct ternary<false, constant<typeA, valueA>, constant<typeB, valueB> > final {
        constvar static typeB const value varinit(valueB);
      };

      template <typename typeA, typeA valueA, typename typeB, typeB valueB>
      struct ternary<true, constant<typeA, valueA>, constant<typeB, valueB> > final {
        constvar static typeA const value varinit(valueA);
      };

      // ...
      template <typename base> struct unsign               final { typedef base           type; };
      template <>              struct unsign<signed char>  final { typedef unsigned char  type; };
      template <>              struct unsign<signed int>   final { typedef unsigned int   type; };
      template <>              struct unsign<signed long>  final { typedef unsigned long  type; };
      template <>              struct unsign<signed short> final { typedef unsigned short type; };
      #if CPP_VERSION >= 2011uL || defined(LLONG_MAX)
        template <> struct unsign<signed long long> final { typedef unsigned long long type; };
      #endif
    }
  }

  /* ... */
  #if CPP_VERSION > 2011uL
    constenum(static std::size_t, LAPYS_MAX_BUILTIN_ALIGNMENT, alignmentof(std::max_align_t));
  #else
    constenum(static std::size_t, LAPYS_MAX_BUILTIN_ALIGNMENT, (
      Lapys::Traits::maximum<std::size_t,
        alignmentof(long double),
        alignmentof(uintmax_t),
        alignmentof(wchar_t),
        alignmentof(Lapys::byte*),
        alignmentof(Lapys::byte (*)(...)),
        alignmentof(Lapys::byte Lapys::Traits::null::*),
        alignmentof(Lapys::byte (Lapys::Traits::null::*)(...))
      >::value
    ));
  #endif

  constenum(static std::size_t, LAPYS_MAX_BUILTIN_SIZE, (
    Lapys::Traits::maximum<std::size_t,
      sizeof(long double),
      sizeof(uintmax_t),
      sizeof(wchar_t),
      sizeof(Lapys::byte*),
      sizeof(Lapys::byte (*)(...)),
      sizeof(Lapys::byte Lapys::Traits::null::*),
      sizeof(Lapys::byte (Lapys::Traits::null::*)(...))
    >::value
  ));
#if   CPP_COMPILER == CPP__CLANG__COMPILER
# pragma clang diagnostic pop
#elif CPP_COMPILER == CPP__GCC__COMPILER
# pragma GCC diagnostic pop
#endif
