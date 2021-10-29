/* ... */
namespace Lapys {
  /* Class */
  template <typename, std::size_t> class Array;
  class CommandLineArguments { public: CommandLineArguments(...) {} };
  template <typename = char, std::size_t = LAPYS_BUILTIN_MAX> class String;

  /* Main */
  noinline void Main(CommandLineArguments const&);
}
