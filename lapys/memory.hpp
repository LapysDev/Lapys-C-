/* Namespace */
namespace Lapys {
  /* Namespace */
  namespace Memory {
    /* ... */
    template <class> struct assess_allocator;
    template <class> struct is_allocator;

    /* Class > ... */
    class Allocation;
    template <typename, std::size_t = static_cast<std::size_t>(Traits::HEAP)> class Allocator;

    /* Function > ... */
    template <typename type> noignore inline type* align(type* const, std::size_t const, std::size_t const) noexcept;
    template <typename typeA, typename typeB> noignore inline typeA* align(typeA*, std::size_t const, std::size_t const, typeB* const) noexcept;

    // ...
    noignore Allocation allocateHeap(std::size_t const) noexcept;
    noignore Allocation allocateHeap(std::size_t const, std::size_t const) noexcept;
    noignore Allocation allocateHeap(control_parameter const, std::size_t const) noexcept;
    noignore Allocation allocateHeap(control_parameter const, std::size_t, std::size_t) noexcept;

    // ...
    #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
      noignore inline HANDLE getHeap() noexcept {
        static HANDLE heap = NULL;

        // ...
        if (NULL == heap) heap = ::GetProcessHeap();
        if (NULL == heap) heap = ::HeapCreate(0x0u, 0u, 0u);

        return heap;
      }
    #endif

    // ...
    template <typename type> noignore inline Allocation reallocateHeap(type* const, std::size_t const) noexcept;
    template <typename type> noignore Allocation reallocateHeap(control_parameter const, type* const, std::size_t const) noexcept;

    // ...
    template <typename type> bool releaseHeap(type* const) noexcept;
    template <typename type> bool releaseHeap(type* const, std::size_t const) noexcept;
  }

  namespace Memory {
    template <class type>                          struct assess_allocator                             final { typedef type base; };
    template <typename type, std::size_t capacity> struct assess_allocator<Allocator<type, capacity> > final { typedef type base; };

    template <class base>
    struct is_allocator final {
      static bool const value = false == is_same<base, typename assess_allocator<base>::base>::value;
    };

    /* Class > ... */
    class Allocation final {
      friend Allocation allocateHeap(control_parameter const, std::size_t, std::size_t) noexcept;
      template <typename type> friend Allocation reallocateHeap(control_parameter const, type* const, std::size_t const) noexcept;
      template <typename type> friend bool releaseHeap(type* const) noexcept;
      template <typename type> friend bool releaseHeap(type* const, std::size_t const) noexcept;

      private:
        #if CPP_VERSION < 2011uL
          static enum kind
        #else
          static enum kind : typename uint_minimum_t::type
        #endif
        {
          C_STANDARD = 0x3u,
          CPP_STANDARD,
          MICROSOFT_WINDOWS__HEAP,
          MICROSOFT_WINDOWS__VIRTUAL,
          UNIX__ALIGNED,
          UNIX__MAPPED
        } const KIND_COMPLETE_REFERENCE = static_cast<Allocation::kind>(0x1u), KIND_INCOMPLETE_REFERENCE = static_cast<Allocation::kind>(0x2u);
        static typename uint_minimum_t::type const KIND_WIDTH = 4u;

        union value {
          friend class Allocation;

          private:
            void *const address;
            typename uint_least_t<(sizeof(kind) > sizeof(std::size_t) ? (sizeof(kind) > sizeof(typename uint_maximum_t::type) ? sizeof(kind) : sizeof(typename uint_maximum_t::type)) : sizeof(std::size_t))>::type const metadata;

            // ...
            constfunc(true) inline value(void* const address) noexcept : address init(address) {}

            constfunc(true) inline value(std::size_t const offset) noexcept : metadata init(offset << Allocation::KIND_WIDTH) {}
            constfunc(true) inline value(Allocation::kind const kind, std::size_t const size) noexcept : metadata init((static_cast<std::size_t>(kind) & ~(~0u << Allocation::KIND_WIDTH)) | (0u != size && size == ((size << Allocation::KIND_WIDTH) >> Allocation::KIND_WIDTH) ? size << Allocation::KIND_WIDTH : 0u)) {}
        } const value;

        // ...
        constfunc(true) inline Allocation(std::size_t const offset) noexcept : value init(offset) {}
        template <typename type> constfunc(true) inline Allocation(type* const pointer) noexcept : value init(bit_cast<void*>(pointer)) {}
        constfunc(true) inline Allocation(Allocation::kind const kind, std::size_t const size = 0u) noexcept : value(kind, size) {}

        // ...
        noignore constfunc(true) inline Allocation::kind getKind  () const lref noexcept { return static_cast<Allocation::kind>(this -> value.metadata & ~(~0u << Allocation::KIND_WIDTH)); }
        noignore constfunc(true) inline std::size_t      getOffset() const lref noexcept { return this -> value.metadata >> Allocation::KIND_WIDTH; }
        noignore constfunc(true) inline std::size_t      getSize  () const lref noexcept { return this -> value.metadata >> Allocation::KIND_WIDTH; }

        template <typename type>
        noignore inline static Allocation const* inspectHeap(type* const address) noexcept {
          for (byte *information = bit_cast<byte*>(address) - sizeof(Allocation); ; --information)
          if (0u == static_cast<std::size_t>(bit_cast<byte*>(address) - information) % alignmentof(Allocation)) {
            Allocation const *const metadata = launder(bit_cast<Allocation const*>(information));
            return Allocation::KIND_COMPLETE_REFERENCE == metadata -> getKind() ? launder(bit_cast<Allocation const*>(information - (metadata -> getOffset()))) : metadata;
          }

          return NULL;
        }

      public:
        template <typename type>
        noignore constfunc(true) inline operator type*() const rref noexcept {
          return static_cast<type*>(this -> value.address);
        }
    };

    // ...
    template <>
    class Allocator<null, 0u> final {
      public:
        template <class allocator> struct can_allocate;
        template <class allocator> struct can_deallocate;
        template <class allocator> struct can_reallocate;
        template <class allocator, bool> struct can_release;

        // ...
        template <class allocator> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_allocate<allocator>::value && false == is_pointer<typeof(allocator::allocate(instanceof<std::size_t>()))>::value, void*>::type allocate(std::size_t const size) const volatile noexcept { return const_cast<void*>(static_cast<void const volatile*>(allocator::allocate(static_cast<std::size_t>(size)))); }
        template <class allocator> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_allocate<allocator>::value && false != is_pointer<typeof(allocator::allocate(instanceof<std::size_t>()))>::value, typeof(allocator::allocate(instanceof<std::size_t>()))>::type allocate(std::size_t const size) const volatile noexcept { return allocator::allocate(static_cast<std::size_t>(size)); }
        template <class allocator> constfunc(true) inline typename conditional<false != is_allocator<allocator>::value, typename assess_allocator<allocator>::base*>::type allocate(std::size_t const size) const volatile noexcept { return allocator::allocate(size); }
        template <class allocator> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value, typeof(Allocator<null>::allocate<allocator>(instanceof<std::size_t>()))>::type allocate(control_parameter const, std::size_t const size) const volatile noexcept { return Allocator<null>::allocate<allocator>(size); }
        template <class allocator> constfunc(true) inline typename conditional<false != is_allocator<allocator>::value, typename assess_allocator<allocator>::base*>::type allocate(control_parameter const control, std::size_t const size) const volatile noexcept { return allocator::allocate(control, size); }

        template <class allocator, typename type> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_reallocate<allocator>::value && false == is_pointer<typeof(allocator::reallocate(instanceof<type*>(), instanceof<std::size_t>()))>::value, type*>::type reallocate(type* const address, std::size_t const resize) const volatile noexcept { return static_cast<void>(allocator::reallocate(static_cast<type*>(address), static_cast<std::size_t>(resize))), address; }
        template <class allocator, typename type> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_reallocate<allocator>::value && false != is_pointer<typeof(allocator::reallocate(instanceof<type*>(), instanceof<std::size_t>()))>::value, typeof(allocator::reallocate(instanceof<type*>(), instanceof<std::size_t>()))>::type reallocate(type* const address, std::size_t const resize) const volatile noexcept { return allocator::reallocate(static_cast<type*>(address), static_cast<std::size_t>(resize)); }
        template <class allocator, typename type> constfunc(true) inline typename conditional<false != is_allocator<allocator>::value, typename assess_allocator<allocator>::base*>::type allocate(type* const address, std::size_t const resize) const volatile noexcept { return allocator::reallocate(address, resize); }
        template <class allocator, typename type> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value, typeof(Allocator<null>::reallocate<allocator>(instanceof<type*>(), instanceof<std::size_t>()))>::type allocate(control_parameter const, type* const address, std::size_t const resize) const volatile noexcept { return Allocator<null>::reallocate<allocator>(address, resize); }
        template <class allocator, typename type> constfunc(true) inline typename conditional<false != is_allocator<allocator>::value, typename assess_allocator<allocator>::base*>::type allocate(control_parameter const control, type* const address, std::size_t const resize) const volatile noexcept { return allocator::reallocate(control, address, resize); }

        template <class allocator, typename type> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_release<allocator, false>::value && false == is_void<typeof(allocator::release(instanceof<type*>()))>::value, bool>::type release(type* const address) const volatile noexcept { return static_cast<bool>(allocator::release(static_cast<type*>(address))); }
        template <class allocator, typename type> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_release<allocator, false>::value && false != is_void<typeof(allocator::release(instanceof<type*>()))>::value, bool>::type release(type* const address) const volatile noexcept { return static_cast<void>(allocator::release(static_cast<type*>(address))), true; }
        template <class allocator, typename type> constfunc(true) inline typename conditional<false != is_allocator<allocator>::value, bool>::type release(type* const address) const volatile noexcept { return allocator::release(address); }
        template <class allocator, typename type> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_release<allocator, true>::value && false == is_void<typeof(allocator::release(instanceof<type*>()))>::value, bool>::type release(type* const address, std::size_t const size) const volatile noexcept { return static_cast<bool>(allocator::release(static_cast<type*>(address)), static_cast<std::size_t>(size)); }
        template <class allocator, typename type> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_release<allocator, true>::value && false != is_void<typeof(allocator::release(instanceof<type*>()))>::value, bool>::type release(type* const address, std::size_t const size) const volatile noexcept { return static_cast<void>(allocator::release(static_cast<type*>(address)), static_cast<std::size_t>(size)), true; }
        template <class allocator, typename type> constfunc(true) inline typename conditional<false != is_allocator<allocator>::value, bool>::type release(type* const address, std::size_t const size) const volatile noexcept { return allocator::release(address, size); }
    };

    template <std::size_t capacity>
    class Allocator<null, capacity> final {
      public:
    };

    template <typename base, std::size_t capacity>
    class Allocator final {
      public:
        // alignmentof(typeof((instanceof<typename conditional<is_void<base>::value, byte, base>::type>())))
        constfunc(true) inline typename conditional<is_void<base>::value, Allocation, base*>::type allocate(std::size_t const size) const volatile noexcept { return Allocator::allocate(static_cast<control_parameter>(static_cast<unsigned>(Traits::DUMMY)), size); }
        constfunc(true) typename conditional<is_void<base>::value, Allocation, base*>::type allocate(control_parameter const, std::size_t const) const volatile noexcept;

        constfunc(true) inline typename conditional<is_void<base>::value, Allocation, base*>::type reallocate(base* const address, std::size_t const resize) const volatile noexcept { return Allocator::allocate(static_cast<control_parameter>(static_cast<unsigned>(Traits::DUMMY)), address, resize); }
        constfunc(true) typename conditional<is_void<base>::value, Allocation, base*>::type reallocate(control_parameter const, base* const, std::size_t const) const volatile noexcept;

        constfunc(true) bool release(base* const) const volatile noexcept;
        constfunc(true) inline bool release(base* const, std::size_t const) const volatile noexcept;
    };

    template <typename base>
    class Allocator<base, Traits::HEAP> final {
      public:
        noignore inline typename conditional<is_void<base>::value, Allocation, base*>::type allocate(std::size_t const size) const volatile noexcept { return Memory::allocateHeap(size, alignmentof(typeof((instanceof<typename conditional<is_void<base>::value, byte, base>::type>())))); }
        noignore typename conditional<is_void<base>::value, Allocation, base*>::type allocate(control_parameter const control, std::size_t const size) const volatile noexcept { return Memory::allocateHeap(control, size, alignmentof(typeof((instanceof<typename conditional<is_void<base>::value, byte, base>::type>())))); }

        noignore inline typename conditional<is_void<base>::value, Allocation, base*>::type reallocate(base* const address, std::size_t const resize) const volatile noexcept { return Memory::reallocateHeap(address, resize); }
        noignore typename conditional<is_void<base>::value, Allocation, base*>::type reallocate(control_parameter const control, base* const address, std::size_t const resize) const volatile noexcept { return Memory::reallocateHeap(control, address, resize); }

        inline bool release(base* const address) const volatile noexcept { return Memory::releaseHeap(address); }
        bool release(base* const address, std::size_t const size) const volatile noexcept { return Memory::releaseHeap(address, size); }
    };
  }
}

/* Import > ... */
#include "memory.tpp"
