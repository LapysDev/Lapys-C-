/* ... */
namespace Lapys {
  namespace Memory {
    namespace {
      class Allocation final {
        private:
          void* const value;

        public:
          constfunc explicit inline Allocation(void* const allocation) noexcept :
            value(allocation)
          {}

          template <typename type>
          constfunc inline operator type*() const rvalued noexcept {
            return static_cast<type*>(this -> value);
          }
      };

      byte STACK_BUFFER[4096] = {};
      byte *STACK_POINTER = STACK_BUFFER;
    }

    // ...
    Allocation allocateHeap (std::size_t const) noexcept;
    Allocation allocateStack(std::size_t const) noexcept;
    Allocation reallocateHeap (void* const,       std::size_t const) exceptspec(false);
    Allocation reallocateHeap (void const* const, std::size_t const) exceptspec(false);
    Allocation reallocateStack(void* const,       std::size_t const) exceptspec(false);
    Allocation reallocateStack(void const* const, std::size_t const) exceptspec(false);
    void releaseHeap (void* const)       exceptspec(false);
    void releaseHeap (void const* const) exceptspec(false);
    void releaseStack(void* const)       exceptspec(false);
    void releaseStack(void const* const) exceptspec(false);
  }
}

namespace Lapys {
  namespace Memory {
    /* Function > ... */
    Allocation allocateHeap(std::size_t const size) noexcept {
      return Allocation(std::malloc(size));
    }

    Allocation allocateStack(std::size_t const size) noexcept {
      byte *const allocation = STACK_POINTER + sizeof(std::size_t);

      // ...
      if (size + sizeof(std::size_t) + (STACK_POINTER - STACK_BUFFER) > sizeof(STACK_BUFFER) * sizeof(byte))
      return Allocation(static_cast<void*>(NULL));

      new (STACK_POINTER) std::size_t(size);
      STACK_POINTER += size + sizeof(std::size_t);

      // ...
      return Allocation(allocation);
    }

    Allocation reallocateHeap(void* const pointer, std::size_t const size) exceptspec(false) {
      return Allocation(std::realloc(pointer, size));
    }

    Allocation reallocateHeap(void const* const pointer, std::size_t const size) exceptspec(false) {
      return Allocation(reallocateHeap(const_cast<void*>(pointer), size));
    }

    Allocation reallocateStack(void* const pointer, std::size_t const size) exceptspec(false) {
      std::size_t *const capacity = launder(reinterpret_cast<std::size_t*>(static_cast<byte*>(pointer) - sizeof(std::size_t)));

      STACK_POINTER += static_cast<typename Traits::sign<std::size_t>::type>(size) - static_cast<typename Traits::sign<std::size_t>::type>(*capacity);
      *capacity = size;

      return Allocation(pointer);
    }

    Allocation reallocateStack(void const* const pointer, std::size_t const size) exceptspec(false) {
      return Allocation(reallocateStack(const_cast<void*>(pointer), size));
    }

    void releaseHeap(void* const pointer) exceptspec(false) {
      std::free(pointer);
    }

    void releaseHeap(void const* const pointer) exceptspec(false) {
      releaseHeap(const_cast<void*>(pointer));
    }

    void releaseStack(void* const pointer) exceptspec(false) {
      std::size_t *const capacity = launder(reinterpret_cast<std::size_t*>(static_cast<byte*>(pointer) - sizeof(std::size_t)));

      STACK_POINTER -= *capacity;
      *capacity = 0u;
    }

    void releaseStack(void const* const pointer) exceptspec(false) {
      releaseStack(const_cast<void*>(pointer));
    }
  }
}
