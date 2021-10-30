/* ... */
namespace Lapys {
  // Command-Line Arguments
  class CommandLineArguments final : public Array<String<char> > {
    public:
      constfunc CommandLineArguments(char const* const[], std::size_t const) noexcept {}
  };
}
