/* Import > ... */
#include "includes.hpp"

/* ... */
namespace Lapys {
  /* Namespace */
  namespace Memory {
    /* Function > ... */
    Allocation allocateHeap(std::size_t const size) noexcept {
      return Memory::allocateHeap(size, Math::minimum(Math::bit_ceil(size), static_cast<std::size_t>(LAPYS_MAX_BUILTIN_ALIGNMENT)));
    }

    Allocation allocateHeap(std::size_t const size, std::size_t const alignment) noexcept {
      return Memory::allocateHeap(static_cast<control_parameter>(static_cast<unsigned>(Traits::DUMMY)), size, alignment);
    }

    Allocation allocateHeap(control_parameter const control, std::size_t const size) noexcept {
      return Memory::allocateHeap(control, size, Math::minimum(Math::bit_ceil(size), static_cast<std::size_t>(LAPYS_MAX_BUILTIN_ALIGNMENT)));
    }

    Allocation allocateHeap(control_parameter const control, std::size_t size, std::size_t alignment) noexcept {
      if (0u == size) return static_cast<void*>(NULL);
      else size += alignmentof(Allocation) + sizeof(Allocation);

      while (0u != alignment % alignmentof(Allocation))
      ++alignment;

      for (std::size_t width = 0u; alignment >> width; ++width) {
        if (width > (CHAR_BIT * sizeof(std::size_t)) - Allocation::KIND_WIDTH)
        return static_cast<void*>(NULL);
      }

      // ...
      void *allocation = NULL;
      Allocation::kind kind = static_cast<Allocation::kind>(0x0u);

      do {
        #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
          if (control & Traits::EXECUTABLE) {
            allocation = ::VirtualAllocEx(::GetCurrentProcess(), static_cast<LPVOID>(NULL), size + alignment, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
            if (NULL != allocation) { kind = Allocation::MICROSOFT_WINDOWS__VIRTUAL; size += alignment; break; }
          }

          else {
            HANDLE const heap = Memory::getHeap();

            // ...
            if (NULL != heap) allocation = ::HeapAlloc(heap, control & Traits::ZERO ? HEAP_ZERO_MEMORY : 0x0u, size + (alignment * (MEMORY_ALLOCATION_ALIGNMENT != alignment)));
            if (NULL != allocation) { kind = Allocation::MICROSOFT_WINDOWS__HEAP; size += alignment * (MEMORY_ALLOCATION_ALIGNMENT != alignment); break; }

            allocation = ::VirtualAllocEx(::GetCurrentProcess(), static_cast<LPVOID>(NULL), size + alignment, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
            if (NULL != allocation) { kind = Allocation::MICROSOFT_WINDOWS__VIRTUAL; size += alignment; break; }
          }
        #endif

        // ...
        #if CPP_VENDOR & CPP__UNIX__VENDOR
          if (false == (control & Traits::EXECUTABLE)) {
            allocation = ::aligned_alloc(alignmentof(Allocation), size + (alignment * (alignmentof(Allocation) != alignment)));
            if (NULL != allocation) { kind = Allocation::UNIX__ALIGNED; size += alignment * (alignmentof(Allocation) != alignment); if (control & Traits::ZERO) { std::memset(allocation, 0x0, size); } break; }
          }

          allocation = ::mmap(NULL, size + alignment, PROT_READ | PROT_WRITE | (control & Traits::EXECUTABLE ? PROT_EXEC : 0x0), MAP_ANONYMOUS | MAP_PRIVATE, -1, 0L);
          if (NULL != allocation) { kind = Allocation::UNIX__MAPPED; size += alignment; break; }
        #endif

        // ...
        if (control & Traits::EXECUTABLE)
        return static_cast<void*>(NULL);

        // ...
        #if CPP_VERSION >= 2017uL
          allocation = std::aligned_alloc(alignmentof(Allocation), size + (alignment * (alignmentof(Allocation) != alignment)));
          if (NULL != allocation) { kind = Allocation::C_STANDARD; size += alignment * (alignmentof(Allocation) != alignment); if (control & Traits::ZERO) { std::memset(allocation, 0x0, size); } break; }
        #endif

        if (control & Traits::ZERO) {
          allocation = std::calloc(size + (alignment * (LAPYS_MAX_BUILTIN_ALIGNMENT != alignment)), sizeof(byte));
          if (NULL != allocation) { kind = Allocation::C_STANDARD; size += alignment * (LAPYS_MAX_BUILTIN_ALIGNMENT != alignment); break; }
        }

        allocation = std::malloc(size + (alignment * (LAPYS_MAX_BUILTIN_ALIGNMENT != alignment)));
        if (NULL != allocation) { kind = Allocation::C_STANDARD; size += alignment * (LAPYS_MAX_BUILTIN_ALIGNMENT != alignment); if (control & Traits::ZERO) { std::memset(allocation, 0x0, size); } break; }

        // ...
        #if CPP_VERSION >= 2017uL
          allocation = ::operator new(size + (alignment * (alignmentof(Allocation) != alignment)), static_cast<std::align_val_t>(alignmentof(Allocation)), std::nothrow);
          if (NULL != allocation) { kind = Allocation::CPP_STANDARD; size += alignment * (alignmentof(Allocation) != alignment); if (control & Traits::ZERO) { std::fill(static_cast<byte*>(allocation), static_cast<byte*>(allocation) + size, static_cast<byte>(0x0u)); } break; }
        #endif

        #ifdef __STDCPP_DEFAULT_NEW_ALIGNMENT__
          allocation = ::operator new(size + (alignment * (__STDCPP_DEFAULT_NEW_ALIGNMENT__ != alignment)), std::nothrow);
          if (NULL != allocation) { kind = Allocation::CPP_STANDARD; size += alignment * (__STDCPP_DEFAULT_NEW_ALIGNMENT__ != alignment); if (control & Traits::ZERO) { std::fill(static_cast<byte*>(allocation), static_cast<byte*>(allocation) + size, static_cast<byte>(0x0u)); } break; }
        #else
          allocation = ::operator new(size + alignment, std::nothrow);
          if (NULL != allocation) { kind = Allocation::CPP_STANDARD; size += alignment; if (control & Traits::ZERO) { std::fill(static_cast<byte*>(allocation), static_cast<byte*>(allocation) + size, static_cast<byte>(0x0u)); } break; }
        #endif
      } while (false);

      if (NULL == allocation)
      return static_cast<void*>(NULL);

      // ...
      void *const address = Memory::align(static_cast<byte*>(allocation) + sizeof(Allocation), alignment, size - sizeof(Allocation), allocation);

      size -= static_cast<byte*>(address) - static_cast<byte*>(allocation);
      for (byte *information = static_cast<byte*>(address) - sizeof(Allocation); ; --information) {
        if (allocation == information) {
          new (allocation) Allocation(kind, size);
          return address;
        }

        if (0u == static_cast<std::size_t>(static_cast<byte*>(address) - information) % alignmentof(Allocation)) {
          if (information < static_cast<byte*>(allocation) + sizeof(Allocation)) {
            new (information) Allocation(Allocation::KIND_INCOMPLETE_REFERENCE, information - static_cast<byte*>(allocation));
          }

          else {
            new (allocation)  Allocation(kind, size);
            new (information) Allocation(Allocation::KIND_COMPLETE_REFERENCE, information - static_cast<byte*>(allocation));
          }

          return address;
        }
      }
    }
  }
}
