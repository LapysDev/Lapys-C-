/* ... */
namespace Lapys {
  namespace Memory {
    template <typename>              class HeapAllocator;
    template <typename, std::size_t> class StackAllocator;

    // ...
    static byte STACK_BUFFER[32u * 1024u] = {};
    static byte *STACK_POINTER = STACK_BUFFER;

    // ...
    void* allocateHeap(std::size_t const) exceptspec(true);
    void* allocateHeap(std::size_t const, std::size_t const) exceptspec(true);

    void* allocateStack(std::size_t const) exceptspec(true);
    void* allocateStack(std::size_t const, std::size_t const) exceptspec(true);

    inline void* reallocateHeap(void* const, std::size_t const) exceptspec(false);
    void* reallocateHeap(void* const, std::size_t const, std::size_t const) exceptspec(false);
    template <typename type> constfunc(true) inline type* reallocateHeap(type* const, std::size_t const, std::size_t const = alignmentof(type)) exceptspec(false);

    inline void* reallocateStack(void* const, std::size_t const) exceptspec(false);
    void* reallocateStack(void* const, std::size_t const, std::size_t const) exceptspec(false);
    template <typename type> constfunc(true) inline type* reallocateStack(type* const, std::size_t const, std::size_t const = alignmentof(type)) exceptspec(false);

    void releaseHeap(void* const) exceptspec(false);
    template <typename type> constfunc(false) inline void releaseHeap(type* const) exceptspec(false);

    void releaseStack(void* const) exceptspec(false);
    template <typename type> constfunc(false) inline void releaseStack(type* const) exceptspec(false);
  }
}

namespace Lapys {
  namespace Memory {
    /* Class > ... */
    template <typename base>
    class HeapAllocator final {
      private:
        template <typename type>
        inline typename conditional<false == is_void<type>::value, type*>::type allocate(std::size_t const count) exceptspec(true) {
          #if CPP_VERSION < 2017uL
            return static_cast<type*>(::operator new[](count * sizeof(type), std::nothrow));
          #else
            return static_cast<type*>(::operator new[](count * sizeof(type), static_cast<std::align_val_t>(alignmentof(type)), std::nothrow));
          #endif
        }

        template <typename type>
        inline typename conditional<false != is_void<type>::value, type*>::type allocate(std::size_t const size) exceptspec(true) {
          return static_cast<type*>(allocateHeap(size));
        }

        template <typename type>
        inline typename conditional<false == is_void<type>::value, void>::type release(type* const pointer) exceptspec(false) {
          #if CPP_VERSION < 2017uL
            ::operator delete[](pointer, std::nothrow);
          #else
            ::operator delete[](pointer, static_cast<std::align_val_t>(alignmentof(type)), std::nothrow);
          #endif
        }

        template <typename type>
        inline typename conditional<false != is_void<type>::value, void>::type release(type* const pointer) exceptspec(false) {
          releaseHeap(pointer);
        }

      public:
        inline base* allocate(std::size_t const argument) exceptspec(true) {
          return this -> allocate<base>(argument);
        }

        inline void release(base* const pointer) exceptspec(false) {
          this -> release(pointer);
        }
    };

    template <typename base, std::size_t size>
    class StackAllocator final {
      private:
        byte buffer[size];

      public:
        constfunc(false) base* allocate(std::size_t const count) exceptspec(true) {}
        constfunc(false) void release(base* const pointer) exceptspec(false) {}
    };

    /* Function > ... */
    void* allocateHeap(std::size_t const size) exceptspec(true) {
      return allocateHeap(size, LAPYS_BUILTIN_MAX_ALIGNMENT);
    }

    void* allocateHeap(std::size_t const size, std::size_t const alignment) exceptspec(true) {
      #if CPP_VERSION < 2017uL
        static_cast<void>(alignment);
        return std::malloc(size);
      #else
        return ::operator new(size, static_cast<std::align_val_t>(alignment), std::nothrow);
      #endif
    }

    // ...
    void* allocateStack(std::size_t const size) exceptspec(true) {
      return allocateStack(size, LAPYS_BUILTIN_MAX_ALIGNMENT);
    }

    void* allocateStack(std::size_t const size, std::size_t const alignment) exceptspec(true) {
      typedef std::size_t header_t;

      byte *data = NULL;
      byte *head = STACK_POINTER;

      // ...
      head += sizeof(header_t);
      while (0u != (head - STACK_BUFFER) % alignment) {
        if (head == STACK_BUFFER + (sizeof(STACK_BUFFER) / sizeof(*STACK_BUFFER)))
        return NULL;

        ++head;
      }

      data = head;
      head += size;
      while (0u != (head - STACK_BUFFER) % alignmentof(header_t)) {
        if (head == STACK_BUFFER + (sizeof(STACK_BUFFER) / sizeof(*STACK_BUFFER)))
        return NULL;

        ++head;
      }

      // ...
      new (STACK_POINTER) header_t((head - sizeof(header_t)) - STACK_POINTER);
      STACK_POINTER = head;

      // ...
      return data;
    }

    // ...
    void* reallocateHeap(void* const pointer, std::size_t const size) exceptspec(false) {
      return reallocateHeap(pointer, size, LAPYS_BUILTIN_MAX_ALIGNMENT);
    }

    void* reallocateHeap(void* const pointer, std::size_t const size, std::size_t const alignment) exceptspec(false) {
      #if CPP_VERSION < 2017uL
        static_cast<void>(alignment);
        return std::realloc(pointer, size);
      #else
        releaseHeap(pointer);
        return allocateHeap(size, alignment);
      #endif
    }

    template <typename type>
    constfunc(true) type* reallocateHeap(type* const pointer, std::size_t const size, std::size_t const alignment) exceptspec(false) {
      return reallocateHeap(static_cast<void*>(const_cast<typename remove_qualifiers<type>::type*>(pointer)), size, alignment);
    }

    // ...
    void* reallocateStack(void* const pointer, std::size_t const size) exceptspec(false) {
      return reallocateStack(pointer, size, LAPYS_BUILTIN_MAX_ALIGNMENT);
    }

    void* reallocateStack(void* const pointer, std::size_t const size, std::size_t const alignment) exceptspec(false) {
      releaseStack(pointer);
      return allocateStack(size, alignment);
    }

    template <typename type>
    constfunc(true) type* reallocateStack(type* const pointer, std::size_t const size, std::size_t const alignment) exceptspec(false) {
      return reallocateStack(static_cast<void*>(const_cast<typename remove_qualifiers<type>::type*>(pointer)), size, alignment);
    }

    // ...
    void releaseHeap(void* const pointer) exceptspec(false) {
      #if CPP_VERSION < 2017uL
        std::free(pointer);
      #else
        ::operator delete(pointer);
      #endif
    }

    template <typename type>
    constfunc(false) void releaseHeap(type* const pointer) exceptspec(false) {
      releaseHeap(static_cast<void*>(const_cast<typename remove_qualifiers<type>::type*>(pointer)));
    }

    // ...
    void releaseStack(void* const pointer) exceptspec(false) {
      typedef std::size_t header_t;

      byte *head;

      for (byte *iterator = STACK_BUFFER; ; ) {
        header_t *header = launder(reinterpret_cast<header_t*>(iterator));
        std::size_t capacity = *reinterpret_cast<std::size_t*>(header);

        // ...
        head = iterator;
        iterator += capacity + sizeof(header_t);

        if (iterator > pointer) {
          header = launder(reinterpret_cast<header_t*>(head));
          capacity = *reinterpret_cast<std::size_t*>(header);

          STACK_POINTER -= capacity + sizeof(header_t);
          break;
        }
      }
    }

    template <typename type>
    constfunc(false) void releaseStack(type* const pointer) exceptspec(false) {
      releaseStack(static_cast<void*>(const_cast<typename remove_qualifiers<type>::type*>(pointer)));
    }
  }
}
