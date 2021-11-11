/* ... */
namespace Lapys {
  class CommandLineArguments;
}

namespace Lapys {
  class CommandLineArguments final : public Array<String<char>, DYNAMIC> {
    private:
    public:
      constfunc(true) CommandLineArguments(char const* const /*arguments*/[], std::size_t const /*count*/) noexcept {}
  };
}
