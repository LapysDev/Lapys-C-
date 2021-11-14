/* ... */
namespace Lapys {
  class CommandLineArguments;
}

namespace Lapys {
  class CommandLineArguments final : Array<char const* const, VIEW> {
    private:
      std::size_t length;

    public:
      constfunc(true) CommandLineArguments(char const* const arguments[], std::size_t const count) noexcept :
        Array<char const* const, VIEW>(arguments), length(count)
      {}
  };
}
