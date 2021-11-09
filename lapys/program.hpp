/* ... */
namespace Lapys {
  class CommandLineArguments;
}

namespace Lapys {
  class CommandLineArguments final : public Array<String<char> > {
    public:
      constfunc(true) CommandLineArguments(char const* const[], std::size_t const) noexcept {}
  };
}
