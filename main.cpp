/* Import */
#include "lapys.hpp"

using namespace Lapys;

/* Main */
void Lapys::Main(CommandLineArguments const&) {
  enum { count = 10u };
  Lapys::byte *allocations[count] = {};
  Memory::StackAllocator<Lapys::byte, 32u * 1024u> allocator = Memory::StackAllocator<Lapys::byte, 32u * 1024u>();

  // ...
  for (unsigned char index = 0u; count != index; ++index) {
    allocations[index] = allocator.allocate(64u);
    std::printf("[allocate(64) {%u}]: %li" "\r\n", index, static_cast<long>(allocations[index] - allocator.sus()));
  }

  allocator.release(allocations[2]); std::puts("[release {2}]");
  allocator.release(allocations[4]); std::puts("[release {4}]");
  allocator.release(allocations[5]); std::puts("[release {5}]");
  allocator.release(allocations[7]); std::puts("[release {7}]");

  for (unsigned char counter = 3u; counter; --counter)
  std::printf("[allocate(64)]: %li" "\r\n", static_cast<long>(allocator.allocate(64u) - allocator.sus()));

  for (unsigned char size = 16u; size; size /= 2u)
  for (unsigned char counter = 3u; counter; --counter)
  std::printf("[allocate(%u)]: %li" "\r\n", size, static_cast<long>(allocator.allocate(size) - allocator.sus()));

  std::printf("[allocate(1)]: %li", static_cast<long>(allocator.allocate(1u) - allocator.sus()));
}
