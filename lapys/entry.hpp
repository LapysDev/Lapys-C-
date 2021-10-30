/* ... */
namespace Lapys {
  // Main
  noinline void Main(CommandLineArguments const&);
}

/* Main */
int main(int const count, char* const arguments[])
  #if CPP_COMPILER != CPP__ICC__COMPILER
    noexcept
  #endif
{
  Lapys::Main(Lapys::CommandLineArguments(arguments, count));
  return EXIT_SUCCESS;
}
