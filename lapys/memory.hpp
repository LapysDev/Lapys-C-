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
        template <typename type> constfunc(true) inline operator type*() const volatile rref noexcept { return static_cast<type*>(const_cast<void*>(this -> value)); }
    };

    enum allocation_parameter {
      C_STANDARD,
      CPP_STANDARD,
      MICROSOFT_WINDOWS,
      UNIX
    };

    /* Function > ... */
    template <typename type> inline type* align(type* const, std::size_t const, std::size_t const) noexcept;
    template <typename type> inline type* align(type*, std::size_t const, std::size_t, type* const) noexcept;

    noignore allocated_t allocateHeap(std::size_t const) noexcept;
    noignore allocated_t allocateHeap(std::size_t const, std::size_t const) noexcept;
    noignore allocated_t allocateHeap(control_parameter const, std::size_t const) noexcept;
    noignore allocated_t allocateHeap(control_parameter const, std::size_t const, std::size_t const) noexcept;

    template <typename type> void releaseHeap(type* const) noexcept;

    // Allocator<byte, Traits::HEAP>::allocate(Traits::EXECUTABLE | Traits::ZERO, size);
    // Allocator<byte, Traits::HEAP>::reallocate(pointer, size)
    // Allocator<byte, Traits::HEAP>::release(pointer, size)
 }
}

/* Import > ... */
#include "memory.tpp"
