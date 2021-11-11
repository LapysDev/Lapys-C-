/* Constant > ... */
namespace Lapys {
  enum { DYNAMIC = 0u };
}

enum {
  LAPYS_BUILTIN_MAX_ALIGNMENT =
  #if CPP_VERSION > 2011uL
    alignmentof(std::max_align_t)
  #else
    Lapys::Traits::maximum<std::size_t,
      alignmentof(char),
      alignmentof(double),
      alignmentof(float),
      alignmentof(int),
      alignmentof(long),
      alignmentof(long double),
      alignmentof(short),
      alignmentof(signed char),
      alignmentof(unsigned char),
      alignmentof(unsigned int),
      alignmentof(unsigned long),
      alignmentof(unsigned short),
      alignmentof(wchar_t),
      #if CPP_VERSION >= 2011uL
        alignmentof(char16_t),
        alignmentof(char32_t),
        alignmentof(double),
        alignmentof(float),
        alignmentof(long double),
        alignmentof(long long),
        alignmentof(unsigned long long),
      #endif
      #if CPP_VERSION >= 2020uL
        alignmentof(char8_t),
      #endif
      alignmentof(void*)
    >::value
  #endif
};

enum {
  LAPYS_BUILTIN_MAX_SIZE = Lapys::Traits::maximum<std::size_t,
    sizeof(char),
    sizeof(double),
    sizeof(float),
    sizeof(int),
    sizeof(long),
    sizeof(long double),
    sizeof(short),
    sizeof(signed char),
    sizeof(unsigned char),
    sizeof(unsigned int),
    sizeof(unsigned long),
    sizeof(unsigned short),
    sizeof(wchar_t),
    #if CPP_VERSION >= 2011uL
      sizeof(char16_t),
      sizeof(char32_t),
      sizeof(double),
      sizeof(float),
      sizeof(long double),
      sizeof(long long),
      sizeof(unsigned long long),
    #endif
    #if CPP_VERSION >= 2020uL
      sizeof(char8_t),
    #endif
    sizeof(void*)
  >::value
};

#ifndef LAPYS_MAX_TEMPLATE_INSTANTIATION
# define LAPYS_MAX_TEMPLATE_INSTANTIATION static_cast<unsigned char>(LAPYS_MAX_ARITY)
#endif
