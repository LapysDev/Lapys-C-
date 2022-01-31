/* Import > ... */
#include "includes.hpp"

/* ... */
namespace Lapys {
  /* Namespace */
  namespace Memory {
    /* Function > ... */
    allocated_t allocateHeap(std::size_t const size) noexcept {
      return Memory::allocateHeap(size, Math::minimum(Math::bit_ceil(size), static_cast<std::size_t>(LAPYS_MAX_BUILTIN_ALIGNMENT)));
    }

    allocated_t allocateHeap(std::size_t const size, std::size_t const alignment) noexcept {
      return Memory::allocateHeap(static_cast<control_parameter>(static_cast<unsigned>(Traits::DUMMY)), size, alignment);
    }

    allocated_t allocateHeap(control_parameter const control, std::size_t const size) noexcept {
      return Memory::allocateHeap(control, size, Math::minimum(Math::bit_ceil(size), static_cast<std::size_t>(LAPYS_MAX_BUILTIN_ALIGNMENT)));
    }

    allocated_t allocateHeap(control_parameter const control, std::size_t const size, std::size_t const alignment) noexcept {
      void *allocation = NULL;

      // ...
      #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
        if (control & Traits::EXECUTABLE) {
          allocation = ::VirtualAllocEx(::GetCurrentProcess(), static_cast<LPVOID>(NULL), alignment + size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
          if (NULL != allocation) return Memory::align(allocation, alignment, size);
          // 1 + new (allocation) allocation_parameter(MICROSOFT_WINDOWS);
        }

        else {
          static HANDLE heap = NULL;

          // ...
          if (NULL == heap) heap = ::GetProcessHeap();
          if (NULL == heap) heap = ::HeapCreate(0x0u, 0u, 0u);

          if (NULL != heap) allocation = ::HeapAlloc(heap, control & Traits::ZERO ? HEAP_ZERO_MEMORY : 0x0u, size + (alignment * (MEMORY_ALLOCATION_ALIGNMENT != alignment)));
          if (NULL != allocation) return MEMORY_ALLOCATION_ALIGNMENT == alignment ? allocation : Memory::align(allocation, alignment, size);

          allocation = ::VirtualAllocEx(::GetCurrentProcess(), static_cast<LPVOID>(NULL), alignment + size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
          if (NULL != allocation) return Memory::align(allocation, alignment, size);
        }
      #endif

      #if CPP_VENDOR & CPP__UNIX__VENDOR
        if (control & Traits::EXECUTABLE) {
          allocation = ::mmap(NULL, alignment + size, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0L);
          if (NULL != allocation) return Memory::align(allocation, alignment, size);
        }

        else {
          if (0u != alignment && 0u == (alignment & (alignment - 1u)) && 0u == alignment % size) allocation = ::aligned_alloc(alignment, size);
          if (NULL != allocation) { if (control & Traits::ZERO) { ::explicit_bzero(allocation, size); } return allocation; }

          allocation = ::mmap(NULL, alignment + size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0L);
          if (NULL != allocation) return Memory::align(allocation, alignment, size);
        }
      #endif

      if (control & Traits::EXECUTABLE)
      return NULL;

      #if CPP_VERSION >= 2017uL
        allocation = ::operator new(size, static_cast<std::align_val_t>(alignment), std::nothrow);
        if (nullptr != allocation) { if (control & Traits::ZERO) { std::fill(static_cast<byte*>(allocation), static_cast<byte*>(allocation) + size, static_cast<byte>(0x0)); } return allocation; }
      #endif

      if (control & Traits::ZERO) {
        allocation = std::calloc(size + (alignment * (LAPYS_MAX_BUILTIN_ALIGNMENT != alignment)), sizeof(byte));
        if (NULL != allocation) return LAPYS_MAX_BUILTIN_ALIGNMENT == alignment ? allocation : Memory::align(allocation, alignment, size);
      }

      allocation = ::operator new(alignment + size, std::nothrow);
      if (NULL != allocation) { if (control & Traits::ZERO) { std::fill(static_cast<byte*>(allocation), static_cast<byte*>(allocation) + size, static_cast<byte>(0x0)); } return Memory::align(allocation, alignment, size); }

      allocation = std::malloc(size + (alignment * (LAPYS_MAX_BUILTIN_ALIGNMENT != alignment)));
      if (NULL != allocation) { if (control & Traits::ZERO) { std::memset(allocation, 0x0, size); } return LAPYS_MAX_BUILTIN_ALIGNMENT == alignment ? allocation : Memory::align(allocation, alignment, size); }

      // ...
      return allocation;
    }
  }
}
