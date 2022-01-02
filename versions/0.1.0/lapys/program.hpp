/* ... */
namespace Lapys {
  class CommandLineArguments;
}

namespace Lapys {
  class CommandLineArguments final {
    private:
      Array<char const* const, VIEW> value;
      std::size_t length;

    public:
      constfunc(true) CommandLineArguments(char const* const arguments[], std::size_t const count) noexcept :
        value(arguments), length(count)
      {}
  };
}
