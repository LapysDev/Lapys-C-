/* Namespace */
namespace Lapys {
  /* Namespace */
  namespace Memory {
    /* Class > ... */
    struct allocated_t final {
      private:
        void const volatile *const value;

      public:
        template <typename type> constfunc(true) inline allocated_t(type* const pointer) noexcept : value init(pointer) {}
        template <typename type> noignore constfunc(true) inline operator type*() const volatile rref noexcept { return static_cast<type*>(const_cast<void*>(this -> value)); }
    };

    // ...
    #if CPP_VERSION < 2011uL
      enum allocation_parameter
    #else
      enum allocation_parameter : typename uint_minimum_t::type
    #endif
    {
      C_STANDARD,
      CPP_STANDARD,
      MICROSOFT_WINDOWS__HEAP,
      MICROSOFT_WINDOWS__VIRTUAL,
      UNIX
    };

    // ...
    struct allocation_information final {
      private:
        static typename uint_minimum_t::type const ALLOCATION_PARAMETER_WIDTH = 3u;
        typename uint_least_t<(sizeof(allocation_parameter) > sizeof(std::size_t) ? sizeof(allocation_parameter) : sizeof(std::size_t))>::type const value;

      public:
        constfunc(true) inline allocation_information(allocation_parameter const parameter) noexcept :
          value(static_cast<std::size_t>(parameter) & ALLOCATION_PARAMETER_WIDTH)
        {}

        constfunc(true) inline allocation_information(allocation_parameter const parameter, std::size_t const size) noexcept : value(
          (static_cast<std::size_t>(parameter) & ALLOCATION_PARAMETER_WIDTH) |
          ((Memory::MICROSOFT_WINDOWS__VIRTUAL == parameter || Memory::UNIX == parameter) && size == ((size << ALLOCATION_PARAMETER_WIDTH) >> ALLOCATION_PARAMETER_WIDTH) ? size << ALLOCATION_PARAMETER_WIDTH : 0u)
        ) {}

        // ...
        constfunc(true) inline allocation_parameter getParameter() const lref noexcept { return static_cast<allocation_parameter>(this -> value & ALLOCATION_PARAMETER_WIDTH); }
        constfunc(true) inline std::size_t          getSize()      const lref noexcept { return this -> value << ALLOCATION_PARAMETER_WIDTH; }
    };

    /* Function > ... */
    template <typename type> noignore inline type* align(type* const, std::size_t const, std::size_t const) noexcept;
    template <typename typeA, typename typeB> noignore inline typeA* align(typeA*, std::size_t const, std::size_t, typeB* const) noexcept;

    noignore allocated_t allocateHeap(std::size_t const) noexcept;
    noignore allocated_t allocateHeap(std::size_t const, std::size_t const) noexcept;
    noignore allocated_t allocateHeap(control_parameter const, std::size_t const) noexcept;
    noignore allocated_t allocateHeap(control_parameter const, std::size_t const, std::size_t const) noexcept;

    #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
      noignore inline HANDLE getHeap() noexcept {
        static HANDLE heap = NULL;

        // ...
        if (NULL == heap) heap = ::GetProcessHeap();
        if (NULL == heap) heap = ::HeapCreate(0x0u, 0u, 0u);

        return heap;
      }
    #endif

    template <typename type> bool releaseHeap(type* const) noexcept;
    template <typename type> inline bool releaseHeap(type* const, std::size_t const) noexcept;

    // Allocator<byte, Traits::HEAP>::allocate(Traits::EXECUTABLE | Traits::ZERO, size);
    // Allocator<byte, Traits::HEAP>::reallocate(pointer, size)
    // Allocator<byte, Traits::HEAP>::release(pointer, size)
 }
}

/* Import > ... */
#include "memory.tpp"
