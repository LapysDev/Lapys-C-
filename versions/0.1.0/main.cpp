/* Import */
#include "lapys.hpp"

using namespace Lapys;

/* Main */
void Lapys::Main(CommandLineArguments const& arguments) {
  std::printf("[]: %lu %lu" "\r\n", static_cast<unsigned long>(sizeof(arguments)), static_cast<unsigned long>(sizeof(void*) + sizeof(void*) + sizeof(std::size_t*) + sizeof(Memory::HeapAllocator<char>)));
  static_cast<void>(arguments);
}
