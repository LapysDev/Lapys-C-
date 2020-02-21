/**
    @author: Lapys Dev Team
    @description: Lapys C++ is a general-purpose C++ library for personal project use.
    @version: 0.0.7
    @url: https://www.github.com/LapysDev/LapysCPP

    --- NOTE ---
        #Lapys:
            - Supported environment standards:
                -- ISO/IEC 14882:1998 (C++98) (1998 - 2003) - current...
            - Over its years of development, the library is still a bare-bones version of what it could be (and code could definitely be re-factored).

    --- RULES ---
        #Lapys:
            - All functions, modules, statements and variables must be lexicographically ordered (if possible).
            - Default parameters are disallowed.
            - Global-scope functions must be prefixed with `::` when referenced.

    --- WARN ---
        #Lapys:
            - Functions can only be minified if they perform at optimal absolutism.
            - Some functions will be heavily overloaded (duplicated) due to C/ C++ lacking a multiple type-specific shorthand for function overloads.

    --- RULES ---
        #Lapys:
            - Syntactic Rules:
                -- Byte Sizes
                    --- 4-Bits: 15
                    --- 8-Bits: 255 // char
                    --- 16-Bits: 32767 // int, short
                    --- 32-Bits: 65535 // unsigned int, unsigned long
                    --- 64-Bits: 4294967295 // unsigned long long
                    --- 128-Bits: 18446744073709551615

                -- Function Pointers
                    --- `int (*functionPointer)()`
                    --- `int (*functionPointer)(int)`
                    --- `int (*functionPointer)(int, int)`
                    --- `int (*functionPointer)(...)`

                -- Manipulators
                    --- `std::ostream& (*manipulator)(std::ostream&)`

                -- Non-Overloadable Operators
                    --- `::`
                    --- `.*`
                    --- `.`
                    --- `?:`

                -- Numbers
                    --- `char`
                    --- `char16_t`
                    --- `char32_t`
                    --- `double`
                    --- `float`
                    --- `int`
                    --- `long`
                    --- `long double`
                    --- `long long`
                    --- `short`
                    --- `signed char`
                    --- `unsigned char`
                    --- `unsigned int`
                    --- `unsigned long`
                    --- `unsigned long long`
                    --- `unsigned short`
                    --- `wchar_t`

                -- Overloadable Operators
                    --- `+`
                    --- `-`
                    --- `*`
                    --- `/`
                    --- `%`
                    --- `^`
                    --- `&`
                    --- `|`
                    --- `~`
                    --- `!`
                    --- `,`
                    --- `=`
                    --- `<`
                    --- `>`
                    --- `<=`
                    --- `>=`
                    --- `++`
                    --- `--`
                    --- `<<`
                    --- `>>`
                    --- `==`
                    --- `!=`
                    --- `&&`
                    --- `||`
                    --- `+=`
                    --- `-=`
                    --- `/=`
                    --- `%=`
                    --- `^=`
                    --- `&=`
                    --- `|=`
                    --- `*=`
                    --- `<<=`
                    --- `>>=`
                    --- `[]`
                    --- `()`
                    --- `->`
                    --- `->*`
                    --- `new`
                    --- `new[]`
                    --- `delete`
                    --- `delete[]`

                -- Strings
                    --- `char`, `char*`, `const char*`, `char[]`, `const char[]`
                    --- `char16_t`, `char16_t*`, `const char16_t*`, `char16_t[]`, `const char16_t[]`
                    --- `char32_t`, `char32_t*`, `const char32_t*`, `char32_t[]`, `const char32_t[]`
                    --- `wchar_t`, `wchar_t*`, `const wchar_t*`, `wchar_t[]`, `const wchar_t[]`
                    --- `std::string`
                    --- `std::u16string`
                    --- `std::u32string`
                    --- `std::wstring`
*/
#pragma once
#ifndef LAPYS_H
    // Definition > Lapys Header
    #define LAPYS_H

    /* Import --- REDACT */
    #include <iostream> // Input Output-Stream
    #include <math.h> // Mathematics
    #include <stdlib.h> // Standard Library
    #include <unistd.h> // Unix Standard --- WARN (Lapys) -> Not standard to the C standard library.

    /* Polyfills */
        // [bool]
        #if !(defined __cplusplus)
            typedef enum {false, true} bool;
        #endif

        // Infinity
        #ifndef INFINITY
            #define INFINITY HUGE_VAL;
        #endif

    /* Shorthands */
    typedef std::int8_t int8_t;
    typedef std::int16_t int16_t;
    typedef std::int32_t int32_t;
    typedef std::int64_t int64_t;
    typedef std::int_fast8_t int_fast8_t;
    typedef std::int_fast16_t int_fast16_t;
    typedef std::int_fast32_t int_fast32_t;
    typedef std::int_fast64_t int_fast64_t;
    typedef std::int_least8_t int_least8_t;
    typedef std::int_least16_t int_least16_t;
    typedef std::int_least32_t int_least32_t;
    typedef std::int_least64_t int_least64_t;
    typedef std::intmax_t intmax_t;
    typedef std::intptr_t intptr_t;
    typedef long double ldouble;
    typedef long long llong;
    typedef std::nullptr_t nullptr_t;
    typedef signed char schar;
    typedef std::size_t size_t;
    typedef std::string string;
    typedef std::u16string u16string;
    typedef std::u32string u32string;
    typedef unsigned char uchar;
    typedef unsigned int uint;
    typedef std::uint8_t uint8_t;
    typedef std::uint16_t uint16_t;
    typedef std::uint32_t uint32_t;
    typedef std::uint64_t uint64_t;
    typedef std::uint_fast8_t uint_fast8_t;
    typedef std::uint_fast16_t uint_fast16_t;
    typedef std::uint_fast32_t uint_fast32_t;
    typedef std::uint_fast64_t uint_fast64_t;
    typedef std::uint_least8_t uint_least8_t;
    typedef std::uint_least16_t uint_least16_t;
    typedef std::uint_least32_t uint_least32_t;
    typedef std::uint_least64_t uint_least64_t;
    typedef std::uintmax_t uintmax_t;
    typedef std::uintptr_t uintptr_t;
    typedef unsigned long ulong;
    typedef unsigned long long ullong;
    typedef unsigned short ushort;
    typedef std::wstring wstring;

    /* Global */
        // (...)
        constexpr static const char
        *AUTHOR = "Lapys",
        *DESCRIPTION = "Lapys C++ is a general-purpose C++ library for personal project use.",
        *URL = "https://www.github.com/LapysDev/LapysCPP",
        *VERSION = "0.0.7";

        // Strict --- WARN (Lapys) -> Change the state of a function's actions.
        static bool STRICT = false;

    /* Namespace */
        // Lapys Development Kit --- NOTE (Lapys) -> Integration of the Lapys Development Kit into C/ C++.
        namespace LapysDevelopmentKit {
            /* Namespace */
                // (...) --- NOTE (Lapys) -> Pre-define all namespaces with their shorthands.
                inline namespace Constants {} namespace LDKC = LapysDevelopmentKit::Constants;
                inline namespace Data {} namespace LDKD = LapysDevelopmentKit::Data;
                inline namespace Environment {} namespace LDKE = LapysDevelopmentKit::Environment;
                inline namespace Functions {} namespace LDKF = LapysDevelopmentKit::Functions;
                inline namespace Information {} namespace LDKI = LapysDevelopmentKit::Information;
                inline namespace Mathematics {} namespace LDKM = LapysDevelopmentKit::Mathematics;
                inline namespace Objects {} namespace LDKO = LapysDevelopmentKit::Objects;

                // Constants --- REDACT
                inline namespace Constants {
                    inline namespace Default {
                        const void* pointer = ((void*) 0);
                        const int value = (int) pointer;
                    }

                    inline namespace Number {
                        constexpr const double Infinity = INFINITY;
                        constexpr const float NaN = NAN;
                    }

                    inline namespace String {
                        constexpr const char
                            alphabets[52] {'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z'},
                            binary[2] {'0', '1'},
                            digits[10] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'},
                            hexadecimal[22] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F'},
                            lowercaseAlphabets[26] {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
                            octal[8] {'0', '1', '2', '3', '4', '5', '6', '7'},
                            uppercaseAlphabets[26] {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
                            variableCharacters[64] {'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '_', '$'},
                            variableCharacters[64] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z', '_', '$'};
                    }
                }
                    /* Utilization */
                    using LDKC::Number::Infinity;
                    using LDKC::Number::NaN;

                // Functions --- NOTE (Lapys) -> Numeric comparison functions for the `LapysDevelopmentKit::Mathematics` namespace. --- MINIFY
                inline namespace Functions {
                    constexpr inline static const bool numberIsNaN(double number) { return std::isnan(number); } constexpr inline static const bool numberIsNaN(float number) { return std::isnan(number); } constexpr inline static const bool numberIsNaN(int number) { return std::isnan(number); } constexpr inline static const bool numberIsNaN(long number) { return std::isnan(number); } constexpr inline static const bool numberIsNaN(long double number) { return std::isnan(number); } constexpr inline static const bool numberIsNaN(long long number) { return std::isnan(number); } constexpr inline static const bool numberIsNaN(short number) { return std::isnan(number); } constexpr inline static const bool numberIsNaN(unsigned int number) { return std::isnan(number); } constexpr inline static const bool numberIsNaN(unsigned long number) { return std::isnan(number); } constexpr inline static const bool numberIsNaN(unsigned long long number) { return std::isnan(number); } constexpr inline static const bool numberIsNaN(unsigned short number) { return std::isnan(number); }
                    constexpr inline static const bool numberIsNegative(double number) { return number < 0; } constexpr inline static const bool numberIsNegative(float number) { return number < 0; } constexpr inline static const bool numberIsNegative(int number) { return number < 0; } constexpr inline static const bool numberIsNegative(long number) { return number < 0; } constexpr inline static const bool numberIsNegative(long double number) { return number < 0; } constexpr inline static const bool numberIsNegative(long long number) { return number < 0; } constexpr inline static const bool numberIsNegative(short number) { return number < 0; } constexpr inline static const bool numberIsNegative(unsigned int number) { return number < 0; } constexpr inline static const bool numberIsNegative(unsigned long number) { return number < 0; } constexpr inline static const bool numberIsNegative(unsigned long long number) { return number < 0; } constexpr inline static const bool numberIsNegative(unsigned short number) { return number < 0; }
                    constexpr inline static const bool numberIsPositiveZero(double number) { return !number; } constexpr inline static const bool numberIsPositiveZero(float number) { return !number; } constexpr inline static const bool numberIsPositiveZero(int number) { return !number; } constexpr inline static const bool numberIsPositiveZero(long number) { return !number; } constexpr inline static const bool numberIsPositiveZero(long double number) { return !number; } constexpr inline static const bool numberIsPositiveZero(long long number) { return !number; } constexpr inline static const bool numberIsPositiveZero(short number) { return !number; } constexpr inline static const bool numberIsPositiveZero(unsigned int number) { return !number; } constexpr inline static const bool numberIsPositiveZero(unsigned long number) { return !number; } constexpr inline static const bool numberIsPositiveZero(unsigned long long number) { return !number; } constexpr inline static const bool numberIsPositiveZero(unsigned short number) { return !number; }
                    constexpr inline static const bool numberIsPositive(double number) { return LDKF::numberIsPositiveZero(number) ^ number > 0; } constexpr inline static const bool numberIsPositive(float number) { return LDKF::numberIsPositiveZero(number) ^ number > 0; } constexpr inline static const bool numberIsPositive(int number) { return LDKF::numberIsPositiveZero(number) ^ number > 0; } constexpr inline static const bool numberIsPositive(long number) { return LDKF::numberIsPositiveZero(number) ^ number > 0; } constexpr inline static const bool numberIsPositive(long double number) { return LDKF::numberIsPositiveZero(number) ^ number > 0; } constexpr inline static const bool numberIsPositive(long long number) { return LDKF::numberIsPositiveZero(number) ^ number > 0; } constexpr inline static const bool numberIsPositive(short number) { return LDKF::numberIsPositiveZero(number) ^ number > 0; } constexpr inline static const bool numberIsPositive(unsigned int number) { return LDKF::numberIsPositiveZero(number) ^ number > 0; } constexpr inline static const bool numberIsPositive(unsigned long number) { return LDKF::numberIsPositiveZero(number) ^ number > 0; } constexpr inline static const bool numberIsPositive(unsigned long long number) { return LDKF::numberIsPositiveZero(number) ^ number > 0; } constexpr inline static const bool numberIsPositive(unsigned short number) { return LDKF::numberIsPositiveZero(number) ^ number > 0; }
                }

                /* Mathematics
                        --- MINIFY ---
                        --- WARN ---
                            #Lapys: Define the `LapysDevelopmentKit::Mathematics::abs` function only for the
                                `LapysDevelopmentKit::Functions::toCharacterString(long double)` function.
                */
                inline namespace Mathematics { constexpr inline double abs(double number) { return LDKF::numberIsNegative(number) ? -number : number; } constexpr inline float abs(float number) { return LDKF::numberIsNegative(number) ? -number : number; } constexpr inline int abs(int number) { return LDKF::numberIsNegative(number) ? -number : number; } constexpr inline long abs(long number) { return LDKF::numberIsNegative(number) ? -number : number; } constexpr inline long double abs(long double number) { return LDKF::numberIsNegative(number) ? -number : number; } constexpr inline long long abs(long long number) { return LDKF::numberIsNegative(number) ? -number : number; } constexpr inline short abs(short number) { return LDKF::numberIsNegative(number) ? -number : number; } constexpr inline unsigned int abs(unsigned int number) { return number; } constexpr inline unsigned long abs(unsigned long number) { return number; } constexpr inline unsigned long long abs(unsigned long long number) { return number; } constexpr inline unsigned short abs(unsigned short number) { return number; } }

                // Functions --- NOTE (Lapys) -> Declare only proprietary functions for the `LapysDevelopmentKit::Objects` module.
                inline namespace Functions {
                    /* Function */
                        // Array > Length
                        template <typename type> constexpr inline static std::size_t arrayLength(type (&)[0]) { return 0; }
                        template <std::size_t length, typename type> constexpr inline static std::size_t arrayLength(type (&)[length]) { return length; }

                        // Character > Is Digit
                        constexpr inline bool characterIsDigit(char character) { std::size_t iterator = LDKF::arrayLength(LDKC::String::digits); while (iterator) if (character == *(LDKC::String::digits + (iterator -= 1))) return true; return false; }

                        // Character String
                            // Length --- MINIFY
                            constexpr inline std::size_t characterStringLength(char characterString[]) { if (NULL == characterString) return 0; else { std::size_t length = 0; while (*(characterString + length) != '\0') length += 1; return length; } }

                            // Is Empty
                            constexpr bool characterStringIsEmpty(char characterString[]) { return !LDKF::characterStringLength(characterString); }

                            // Clone --- MINIFY
                            constexpr char* characterStringClone(char characterString[]) { std::size_t iterator = LDKF::characterStringLength(characterString); char* characterStringClone = (char*) std::malloc(iterator + 1); *(characterStringClone + iterator) = '\0'; while (iterator) { iterator -= 1; *(characterStringClone + iterator) = *(characterString + iterator); } return characterStringClone; }
                            constexpr static char* characterStringClone(const char characterString[]) { return LDKF::characterStringClone((char*) characterString); }

                        // Number > (Characteristics, Mantissa) Length --- MINIFY
                        constexpr inline static unsigned char numberCharacteristicsLength(int number) { unsigned char length = 0; while (number) { length += 1; number /= 10; } return length; } constexpr inline static unsigned char numberCharacteristicsLength(long number) { unsigned char length = 0; while (number) { length += 1; number /= 10; } return length; } constexpr inline static unsigned char numberCharacteristicsLength(long long number) { unsigned char length = 0; while (number) { length += 1; number /= 10; } return length; } constexpr static unsigned char numberCharacteristicsLength(double number) { return LDKF::numberCharacteristicsLength((long) number); } constexpr static unsigned char numberCharacteristicsLength(float number) { return LDKF::numberCharacteristicsLength((int) number); } constexpr static unsigned char numberCharacteristicsLength(long double number) { return LDKF::numberCharacteristicsLength((long long) number); } constexpr inline static unsigned char numberCharacteristicsLength(unsigned int number) { unsigned char length = 0; while (number) { length += 1; number /= 10; } return length; } constexpr inline static unsigned char numberCharacteristicsLength(unsigned long number) { unsigned char length = 0; while (number) { length += 1; number /= 10; } return length; } constexpr inline static unsigned char numberCharacteristicsLength(unsigned long long number) { unsigned char length = 0; while (number) { length += 1; number /= 10; } return length; } constexpr inline static unsigned char numberCharacteristicsLength(unsigned short number) { unsigned char length = 0; while (number) { length += 1; number /= 10; } return length; } constexpr inline static unsigned char numberCharacteristicsLength(short number) { unsigned char length = 0; while (number) { length += 1; number /= 10; } return length; }
                        constexpr inline static unsigned char numberMantissaLength(double number) { bool isSafe = false; const bool isSigned = LDKF::numberIsNegative(number); long long integer = number; unsigned char length = 0;  if (number != integer)  while ((isSafe = isSigned ? integer > -0x7FFFFFFFFFFFFFFF : integer < 0x8000000000000000) && (isSigned ? number < integer : number > integer) && (isSigned ? LDKF::numberIsNegative(integer) : LDKF::numberIsPositive(integer))) { number *= 10; integer = number; length += 1; } return length + isSafe; } constexpr inline static unsigned char numberMantissaLength(float number) { bool isSafe = false; const bool isSigned = LDKF::numberIsNegative(number); long long integer = number; unsigned char length = 0;  if (number != integer)  while ((isSafe = isSigned ? integer > -0x7FFFFFFFFFFFFFFF : integer < 0x8000000000000000) && (isSigned ? number < integer : number > integer) && (isSigned ? LDKF::numberIsNegative(integer) : LDKF::numberIsPositive(integer))) { number *= 10; integer = number; length += 1; } return length + isSafe; } constexpr static unsigned char numberMantissaLength(int number) { return LDKF::numberMantissaLength((float) number); } constexpr static unsigned char numberMantissaLength(long number) { return LDKF::numberMantissaLength((double) number); } constexpr inline static unsigned char numberMantissaLength(long double number) { bool isSafe = false; const bool isSigned = LDKF::numberIsNegative(number); long long integer = number; unsigned char length = 0;  if (number != integer)  while ((isSafe = isSigned ? integer > -0x7FFFFFFFFFFFFFFF : integer < 0x8000000000000000) && (isSigned ? number < integer : number > integer) && (isSigned ? LDKF::numberIsNegative(integer) : LDKF::numberIsPositive(integer))) { number *= 10; integer = number; length += 1; } return length + isSafe; } constexpr static unsigned char numberMantissaLength(long long number) { return LDKF::numberMantissaLength((long double) number); } constexpr static unsigned char numberMantissaLength(unsigned int number) { return LDKF::numberMantissaLength((float) number); } constexpr static unsigned char numberMantissaLength(unsigned long number) { return LDKF::numberMantissaLength((double) number); } constexpr static unsigned char numberMantissaLength(unsigned long long number) { return LDKF::numberMantissaLength((long double) number); } constexpr static unsigned char numberMantissaLength(unsigned short number) { return LDKF::numberMantissaLength((float) number); } constexpr static unsigned char numberMantissaLength(short number) { return LDKF::numberMantissaLength((float) number); }

                        // (Signed, UTF-32, Wide) Character String > Length --- MINIFY
                        constexpr inline std::size_t signedCharacterStringLength(signed char signedCharacterString[]) { if (NULL == signedCharacterString) return 0; std::size_t length = 0; while (*(signedCharacterString + length) != '\0') length += 1; return length; }
                        constexpr inline std::size_t utf32CharacterStringLength(char32_t utf32CharacterString[]) { if (NULL == utf32CharacterString) return 0; std::size_t length = 0; while (*(utf32CharacterString + length) != U'\0') length += 1; return length; }
                        constexpr inline std::size_t wideCharacterStringLength(wchar_t wideCharacterString[]) { if (NULL == wideCharacterString) return 0; std::size_t length = 0; while (*(wideCharacterString + length) != L'\0') length += 1; return length; }

                        // To Character
                        constexpr inline char toCharacter(char arg) { return arg; }
                        constexpr inline char toCharacter(wchar_t arg) { return (char) arg; }
                        constexpr inline char toCharacter(char16_t arg) { return LDKF::toCharacter((wchar_t) arg); }
                        constexpr inline char toCharacter(char32_t arg) { return LDKF::toCharacter((wchar_t) arg); }
                        constexpr inline char toCharacter(signed char arg) { return arg; }
                        constexpr inline char toCharacter(unsigned char arg) { return arg; }

                        // To Wide Character String --- MINIFY --- NOTE (Lapys) -> Convert each UTF-32 character to a wider format rather than statically cast the Argument string.
                        constexpr inline wchar_t* toWideCharacterString(char32_t arg[]) { std::size_t iterator = LDKF::utf32CharacterStringLength(arg); wchar_t* string = (wchar_t*) std::malloc(iterator * sizeof(wchar_t)); while (iterator) { iterator -= 1; *(string + iterator) = (wchar_t) *(arg + iterator); } return string; }

                        // To Character String --- MINIFY --- WARN (Lapys) -> Always allocates heap memory for its return value.
                        constexpr inline char* toCharacterString(const bool arg) { return LDKF::characterStringClone((char*) (arg ? "true" : "false")); }
                        constexpr inline char* toCharacterString(const char arg) { bool isNullTerminationCharacter = arg == '\0'; char* characterString = (char*) std::malloc(1 + !isNullTerminationCharacter); *characterString = arg; isNullTerminationCharacter || (*(characterString + 1) = '\0'); return characterString; }
                        constexpr inline char* toCharacterString(char arg[]) { return LDKF::characterStringClone(NULL == arg ? (char*) "null" : arg); }
                        constexpr inline char* toCharacterString(const char arg[]) { return LDKF::characterStringClone((char*) (NULL == arg ? "null" : arg)); }
                        constexpr inline static char* toCharacterString(unsigned long long arg, bool isSigned, unsigned char argCharacteristicsLength) { if (!arg) return LDKF::characterStringClone("0"); const unsigned char length = argCharacteristicsLength + isSigned; unsigned char iterator = length; char* characterString = (char*) std::malloc(length); isSigned && (*characterString = '-'); *(characterString + iterator) = '\0'; while (iterator != isSigned) { iterator -= 1; *(characterString + iterator) = *(LDKC::String::digits + (arg % 10)); arg /= 10; } return characterString; }
                        constexpr static char* toCharacterString(const unsigned long long arg, bool isSigned) { return LDKF::toCharacterString(arg, isSigned, LDKF::numberCharacteristicsLength(arg)); }
                        constexpr char* toCharacterString(const unsigned long long arg) { return LDKF::numberIsNaN(arg) ? LDKF::characterStringClone("NaN") : LDKF::toCharacterString(arg, false); }
                        constexpr static char* toCharacterString(const long long arg, bool isSigned, unsigned char argCharacteristicsLength) { return LDKF::toCharacterString((const unsigned long long) (isSigned ? -arg : arg), isSigned, argCharacteristicsLength); }
                        constexpr static char* toCharacterString(const long long arg, unsigned char argCharacteristicsLength) { return LDKF::toCharacterString(arg, arg < 0, argCharacteristicsLength); }
                        constexpr char* toCharacterString(const long long arg) { return LDKF::numberIsNaN(arg) ? LDKF::characterStringClone("NaN") : LDKF::toCharacterString(arg, LDKF::numberCharacteristicsLength(arg)); }
                        constexpr char* toCharacterString(long double arg) { if (LDKF::numberIsNaN(arg)) return LDKF::characterStringClone("NaN"); else { const unsigned char argCharacteristicsLength = LDKF::numberCharacteristicsLength(arg); unsigned char argMantissaLength = LDKF::numberMantissaLength(arg); const bool argIsSigned = arg < 0; char* characterString = LDKF::toCharacterString((const long long) arg, argIsSigned, argCharacteristicsLength); if (argMantissaLength) { const std::size_t length = argCharacteristicsLength + 1 + argMantissaLength; std::size_t iterator = length; characterString = (char*) std::realloc(characterString, length + 1); *(characterString + argCharacteristicsLength + argIsSigned) = '.'; while (argMantissaLength) *(characterString + (length - (argMantissaLength -= 1) - 1)) = *(LDKC::String::digits + LDKM::abs((long long) (arg *= 10) % 10)); while (iterator) { iterator -= 1; if (*(characterString + iterator) != '0') { *(characterString + iterator + 1) = '\0'; break; } } } return characterString; } }
                        constexpr char* toCharacterString(float arg) { return LDKF::numberIsNaN(arg) ? LDKF::characterStringClone("NaN") : LDKF::toCharacterString((long double) arg); }
                        constexpr char* toCharacterString(double arg) { return LDKF::numberIsNaN(arg) ? LDKF::characterStringClone("NaN") : LDKF::toCharacterString((long double) arg); }
                        constexpr char* toCharacterString(int arg) { return LDKF::numberIsNaN(arg) ? LDKF::characterStringClone("NaN") : LDKF::toCharacterString((const long long) arg); }
                        constexpr char* toCharacterString(long arg) { return LDKF::numberIsNaN(arg) ? LDKF::characterStringClone("NaN") : LDKF::toCharacterString((const long long) arg); }
                        constexpr char* toCharacterString(short arg) { return LDKF::numberIsNaN(arg) ? LDKF::characterStringClone("NaN") : LDKF::toCharacterString((const long long) arg); }
                        constexpr char* toCharacterString(const signed char arg) { return LDKF::toCharacterString(LDKF::toCharacter(arg)); }
                        constexpr char* toCharacterString(signed char arg[]) { return LDKF::toCharacterString((char*) arg); }
                        constexpr char* toCharacterString(const signed char arg[]) { return LDKF::toCharacterString((const char*) arg); }
                        constexpr char* toCharacterString(const unsigned char arg) { return LDKF::toCharacterString(LDKF::toCharacter(arg)); }
                        constexpr char* toCharacterString(unsigned char arg[]) { return LDKF::toCharacterString((char*) arg); }
                        constexpr char* toCharacterString(const unsigned char arg[]) { return LDKF::toCharacterString((const char*) arg); }
                        constexpr char* toCharacterString(unsigned int arg) { return LDKF::numberIsNaN(arg) ? LDKF::characterStringClone("NaN") : LDKF::toCharacterString((const unsigned long long) arg); }
                        constexpr char* toCharacterString(unsigned long arg) { return LDKF::numberIsNaN(arg) ? LDKF::characterStringClone("NaN") : LDKF::toCharacterString((const unsigned long long) arg); }
                        constexpr char* toCharacterString(unsigned short arg) { return LDKF::numberIsNaN(arg) ? LDKF::characterStringClone("NaN") : LDKF::toCharacterString((const unsigned long long) arg); }
                        inline char* toCharacterString(const void* arg) { if (NULL == arg) return LDKF::characterStringClone((char*) "null"); else { bool isNullLike = true; char pointerString[8]; std::sprintf(pointerString, "%p", arg); unsigned char iterator = 8; while (iterator) { iterator -= 1; if (*(pointerString + iterator) != '0') { isNullLike = false; iterator = 0; break; } } if (isNullLike) return LDKF::characterStringClone((char*) "null"); else { static char characterString[11]; unsigned char length = 2; *characterString = '0'; *(characterString + 1) = 'x'; do { switch (*pointerString) { case 'a': *(characterString + length) = 'A'; break; case 'b': *(characterString + length) = 'B'; break; case 'c': *(characterString + length) = 'C'; break; case 'd': *(characterString + length) = 'D'; break; case 'e': *(characterString + length) = 'E'; break; case 'f': *(characterString + length) = 'F'; break; default: *(characterString + length) = *pointerString; } iterator += 1; length += 1; } while (*pointerString = *(pointerString + iterator)); *(characterString + length) = '\0'; return characterString; } } }
                        constexpr char* toCharacterString(const wchar_t arg) { return LDKF::toCharacterString(LDKF::toCharacter(arg)); }
                        constexpr inline char* toCharacterString(wchar_t arg[]) { char* characterString = (char*) std::malloc(LDKF::wideCharacterStringLength((wchar_t*) arg)); unsigned codepoint = 0; std::size_t iterator = 0; while (*arg) { if (*arg > 0xD800 - 1 && *arg < 0xDBFF + 1) codepoint = ((*arg - 0xD800) << 10) + 0x10000; else { codepoint = *arg > 0xDC00 - 1 && *arg < 0xDFFF + 1 ? codepoint | *arg - 0xDC00 : *arg; if (codepoint < 0x7F + 1) { *(characterString + iterator) = (char) codepoint; iterator += 1; } else if (codepoint < 0x7FF + 1) { *(characterString + iterator) = (char) (0xC0 | ((codepoint >> 6) & 0x1F)); iterator += 1; *(characterString + iterator) = (char) (0x80 | (codepoint & 0x3F)); iterator += 1; } else if (codepoint < 0xFFFF + 1) { *(characterString + iterator) = (char) (0xE0 | ((codepoint >> 12) & 0x0F)); iterator += 1; *(characterString + iterator) = (char) (0x80 | ((codepoint >> 6) & 0x3F)); iterator += 1; *(characterString + iterator) = (char) (0x80 | (codepoint & 0x3F)); iterator += 1; } else { *(characterString + iterator) = (char) (0xF0 | ((codepoint >> 18) & 0x07)); iterator += 1; *(characterString + iterator) = (char) (0x80 | ((codepoint >> 12) & 0x3F)); iterator += 1; *(characterString + iterator) = (char) (0x80 | ((codepoint >> 6) & 0x3F)); iterator += 1; *(characterString + iterator) = (char) (0x80 | (codepoint & 0x3F)); iterator += 1; } codepoint = 0; } arg += 1; } return characterString; }
                        constexpr char* toCharacterString(const wchar_t arg[]) { return LDKF::toCharacterString((wchar_t*) arg); }
                        constexpr char* toCharacterString(const char16_t arg) { return LDKF::toCharacterString(LDKF::toCharacter(arg)); }
                        constexpr char* toCharacterString(char16_t arg[]) { return LDKF::toCharacterString((wchar_t*) arg); }
                        constexpr char* toCharacterString(const char16_t arg[]) { return LDKF::toCharacterString((wchar_t*) arg); }
                        constexpr char* toCharacterString(const char32_t arg) { return LDKF::toCharacterString(LDKF::toCharacter(arg)); }
                        constexpr char* toCharacterString(char32_t arg[]) { return LDKF::toCharacterString(LDKF::toWideCharacterString(arg)); }
                        constexpr char* toCharacterString(const char32_t arg[]) { return LDKF::toCharacterString(LDKF::toWideCharacterString((char32_t*) arg)); }
                        constexpr inline char* toCharacterString(std::nullptr_t) { return LDKF::characterStringClone((char*) "null"); }
                        inline char* toCharacterString(std::string arg) { char* characterString = (char*) arg.c_str(); return LDKF::characterStringClone(characterString); }
                        char* toCharacterString(std::u16string arg) { return LDKF::toCharacterString(arg.c_str()); }
                        char* toCharacterString(std::u32string arg) { return LDKF::toCharacterString(arg.c_str()); }
                        char* toCharacterString(std::wstring arg) { return LDKF::toCharacterString(arg.c_str()); }

                        // Character String > Concatenate --- WARN (Lapys) -> Does not concatenate a Source onto a Destination.
                        constexpr inline static char* characterStringConcatenate() { return (char*) ""; }
                        constexpr inline static char* characterStringConcatenate(char characterString[]) { return characterString; }
                        constexpr inline static char* characterStringConcatenate(const char characterString[]) { return (char*) characterString; }
                        template <typename type> char* characterStringConcatenate(type arg) { return LDKF::toCharacterString(arg); }
                        constexpr char* characterStringConcatenate(const char characterStringA[], const char characterStringB[]) { std::size_t characterStringALength = LDKF::characterStringLength((char*) characterStringA), characterStringBLength = LDKF::characterStringLength((char*) characterStringB); if (characterStringALength && !characterStringBLength) return LDKF::characterStringClone(characterStringA); else if (!characterStringALength && characterStringBLength) return LDKF::characterStringClone(characterStringB); else { const std::size_t length = characterStringALength + characterStringBLength; std::size_t iterator = length; char* characterString = (char*) std::malloc(iterator + 1); *(characterString + iterator) = '\0'; while (iterator != characterStringALength) { iterator -= 1; *(characterString + length - (iterator - characterStringALength) - 1) = *(characterStringB + length - iterator - 1); } while (iterator) { iterator -= 1; *(characterString + iterator) = *(characterStringA + iterator); } return characterString; } }
                        constexpr char* characterStringConcatenate(char characterStringA[], char characterStringB[]) { return LDKF::characterStringConcatenate((const char*) characterStringA, (const char*) characterStringB); }
                        constexpr char* characterStringConcatenate(char characterStringA[], const char characterStringB[]) { return LDKF::characterStringConcatenate((const char*) characterStringA, characterStringB); }
                        constexpr char* characterStringConcatenate(const char characterStringA[], char characterStringB[]) { return LDKF::characterStringConcatenate(characterStringA, (const char*) characterStringB); }
                        template <typename type> constexpr char* characterStringConcatenate(char characterStringA[], type characterStringB) { return LDKF::characterStringConcatenate(characterStringA, LDKF::toCharacterString(characterStringB)); }
                        template <typename type> constexpr char* characterStringConcatenate(const char characterStringA[], type characterStringB) { return LDKF::characterStringConcatenate(characterStringA, LDKF::toCharacterString(characterStringB)); }
                        template <typename type> constexpr char* characterStringConcatenate(type characterStringA, char characterStringB[]) { return LDKF::characterStringConcatenate(LDKF::toCharacterString(characterStringA), characterStringB); }
                        template <typename type> constexpr char* characterStringConcatenate(type characterStringA, const char characterStringB[]) { return LDKF::characterStringConcatenate(LDKF::toCharacterString(characterStringA), characterStringB); }
                        template <typename typeA, typename typeB> constexpr char* characterStringConcatenate(typeA characterStringA, typeB characterStringB) { return LDKF::characterStringConcatenate(LDKF::toCharacterString(characterStringA), LDKF::toCharacterString(characterStringB)); }
                        template <typename typeA, typename typeB, typename... types> constexpr char* characterStringConcatenate(typeA characterStringA, typeB characterStringB, types... characterStrings) { char* characterString = LDKF::characterStringConcatenate(characterStringA, characterStringB), *concatenation = LDKF::characterStringConcatenate(characterString, characterStrings...); std::free(characterString); return concatenation; }

                        // Array > Join --- MINIFY
                        template <typename type> inline char* arrayJoin(type array, const std::size_t length, const char* separator = ", ") {
                            char* arrayString[length]; std::size_t arrayStringLength[length];
                            std::size_t characterStringLength = 0, iterator = length;
                            const std::size_t separatorLength = LDKF::characterStringLength((char*) separator);

                            while (iterator) {
                                (iterator -= 1) && (characterStringLength += separatorLength);
                                characterStringLength += *(arrayStringLength + iterator) = LDKF::characterStringLength(*(arrayString + iterator) = LDKF::toCharacterString(array[iterator]));
                            }

                            char* characterString = (char*) std::malloc(characterStringLength + 1);
                            characterStringLength = 0;
                            iterator = length;

                            while (iterator) {
                                iterator -= 1;
                                char* elementString = *(arrayString + length - iterator - 1);
                                const std::size_t elementStringLength = *(arrayStringLength + length - iterator - 1);
                                std::size_t elementStringIterator = elementStringLength;
                                std::size_t separatorIterator = separatorLength;

                                while (elementStringIterator) {
                                    elementStringIterator -= 1;
                                    *(characterString + characterStringLength + elementStringIterator) = *(elementString + elementStringIterator);
                                }

                                characterStringLength += elementStringLength;

                                std::free(elementString);

                                if (iterator) {
                                    while (separatorIterator) { separatorIterator -= 1; *(characterString + characterStringLength + separatorIterator) = *(separator + separatorIterator); }
                                    characterStringLength += separatorLength;
                                }
                            }

                            std::free(arrayString);
                            std::free(arrayStringLength);

                            *(characterString + characterStringLength) = '\0';

                            return characterString;
                        }
                        template <std::size_t length, typename type> char* arrayJoin(type (&array)[length], const char* separator = ", ") { return LDKF::arrayJoin(array, length, separator); }

                        // To Long Double --- MINIFY --- NOTE (Lapys) -> Does not support non-decimal base conversions with strings.
                        constexpr inline long double toLongDouble(bool arg) { return arg; }
                        constexpr inline long double toLongDouble(char arg) { switch (arg) { case '0': return 0; case '1': return 1; case '2': return 2; case '3': return 3; case '4': return 4; case '5': return 5; case '6': return 6; case '7': return 7; case '8': return 8; case '9': return 9; default: return NaN; } }
                        constexpr long double toLongDouble(char arg[]) { if (NULL == arg || *arg == '\0') return 0; else if (*arg == '-') { std::size_t iterator = LDKF::characterStringLength(arg); char stream[iterator] {0}; while (iterator -= 1) *(stream + iterator - 1) = *(arg + iterator); return -LDKF::toLongDouble(stream); } else if (LDKF::characterIsDigit(*arg)) { long double exponent = 1, number = 0; bool isDecimalNotation = false, isNotANumber = false, isScientificNotation = false; const std::size_t length = LDKF::characterStringLength(arg); std::size_t iterator = length; if (length == 1) number = LDKF::toLongDouble(*arg); else { while (iterator -= 1) { char character = *(arg + length - iterator); if (character == 'e' || character == '.') break; exponent *= 10; } iterator = length; while (iterator && !isNotANumber && !isScientificNotation) { char character = *(arg + (length - (iterator -= 1) - 1)); unsigned long long digit = 0; if (LDKF::characterIsDigit(character)) { switch (character) { case '1': digit = 1; break; case '2': digit = 2; break; case '3': digit = 3; break; case '4': digit = 4; break; case '5': digit = 5; break; case '6': digit = 6; break; case '7': digit = 7; break; case '8': digit = 8; break; case '9': digit = 9; break; } number += digit * exponent; exponent /= 10; } else { switch (character) { case 'e': isScientificNotation = true; break; case '.': if (isDecimalNotation) isNotANumber = true; else isDecimalNotation = true; break; default: isNotANumber = true; break; } } } if (isNotANumber) number = NaN; else if (isScientificNotation) { char exponentStream[length - (iterator + 2)] {0}; std::size_t exponentStreamLength = 0; while (iterator) { char character = *(arg + (length - (iterator -= 1) - 1)); if (LDKF::characterIsDigit(character)) *(exponentStream + (exponentStreamLength += 1) - 1) = character; else { iterator = 0; number = NaN; } } if (!LDKF::numberIsNaN(number)) { exponent = LDKF::toLongDouble(exponentStream) + 1; while (exponent -= 1) number *= 10; } } } return number; } else return NaN; }
                        long double toLongDouble(const char arg[]) { return LDKF::toLongDouble((char*) arg); }
                        long double toLongDouble(char16_t arg[]) { return LDKF::toLongDouble(LDKF::toCharacterString(arg)); }
                        long double toLongDouble(const char16_t arg[]) { return LDKF::toLongDouble(LDKF::toCharacterString(arg)); }
                        long double toLongDouble(char32_t arg[]) { return LDKF::toLongDouble(LDKF::toCharacterString(arg)); }
                        long double toLongDouble(const char32_t arg[]) { return LDKF::toLongDouble(LDKF::toCharacterString(arg)); }
                        constexpr inline long double toLongDouble(double arg) { return arg; }
                        constexpr inline long double toLongDouble(float arg) { return arg; }
                        constexpr inline long double toLongDouble(int arg) { return arg; }
                        constexpr inline long double toLongDouble(long arg) { return arg; }
                        constexpr inline long double toLongDouble(long double arg) { return arg; }
                        constexpr inline long double toLongDouble(long long arg) { return arg; }
                        constexpr inline long double toLongDouble(short arg) { return arg; }
                        long double toLongDouble(signed char arg[]) { return LDKF::toLongDouble((char*) arg); }
                        long double toLongDouble(const signed char arg[]) { return LDKF::toLongDouble((const char*) arg); }
                        long double toLongDouble(unsigned char arg[]) { return LDKF::toLongDouble((char*) arg); }
                        long double toLongDouble(const unsigned char arg[]) { return LDKF::toLongDouble((const char*) arg); }
                        constexpr inline long double toLongDouble(unsigned int arg) { return arg; }
                        constexpr inline long double toLongDouble(unsigned long arg) { return arg; }
                        constexpr inline long double toLongDouble(unsigned long long arg) { return arg; }
                        constexpr inline long double toLongDouble(unsigned short arg) { return arg; }
                        long double toLongDouble(wchar_t arg[]) { return LDKF::toLongDouble(LDKF::toCharacterString(arg)); }
                        long double toLongDouble(const wchar_t arg[]) { return LDKF::toLongDouble(LDKF::toCharacterString(arg)); }
                        constexpr inline long double toLongDouble(std::nullptr_t) { return 0; }
                        inline long double toLongDouble(std::string arg) { return LDKF::toLongDouble(LDKF::toCharacterString(arg)); }
                        inline long double toLongDouble(std::u16string arg) { return LDKF::toLongDouble(LDKF::toCharacterString(arg)); }
                        inline long double toLongDouble(std::u32string arg) { return LDKF::toLongDouble(LDKF::toCharacterString(arg)); }
                        inline long double toLongDouble(std::wstring arg) { return LDKF::toLongDouble(LDKF::toCharacterString(arg)); }

                        // (Unsigned, UTF-16) Character String > Length
                        constexpr inline std::size_t unsignedCharacterStringLength(unsigned char unsignedCharacterString[]) { if (NULL == unsignedCharacterString) return 0; std::size_t length = 0; while (*(unsignedCharacterString + length) != '\0') length += 1; return length; }
                        constexpr inline std::size_t utf16CharacterStringLength(char16_t utf16CharacterString[]) { if (NULL == utf16CharacterString) return 0; std::size_t length = 0; while (*(utf16CharacterString + length) != u'\0') length += 1; return length; }

                        /* Print
                                --- NOTE (Lapys) -> Mainly for debugging.
                                --- WARN ---
                                    #Lapys:
                                        - Has "unpredictable" behavior for non-referenced pointers (i.e. in use-cases like `void ::print(NULL)` and `void ::print(std::string().c_str())`).
                                        - Will execute string manipulators such as `std::endl`.
                        */
                            // []
                            inline static void print() { std::fflush(stdout); }

                            // [[Output Stream] Manipulators]
                            constexpr inline void print(std::ios_base& (&argA)(std::ios_base&), std::ostream& argB) { argA(argB); }
                            constexpr void print(std::ios_base& (&arg)(std::ios_base&)) { LDKF::print(arg, std::cout); }

                            constexpr inline void print(std::ostream& (&argA)(std::ostream&), std::ostream& argB) { argA(argB); }
                            constexpr void print(std::ostream& (&arg)(std::ostream&)) { LDKF::print(arg, std::cout); }

                            template <typename type> constexpr inline void print(type (&argA)(int), std::ostream& argB, int argC) { argB << argA(argC); }
                            template <typename type> constexpr void print(type (&argA)(int), std::ostream& argB) { LDKF::print(argA, argB, int()); }
                            template <typename type> constexpr void print(type (&arg)(int)) { LDKF::print(arg, std::cout); }

                            template <typename type> constexpr inline void print(type (&argA)(std::ios_base::fmtflags), std::ostream& argB, std::ios_base::fmtflags argC) { argB << argA(argC); }
                            template <typename type> constexpr void print(type (&argA)(std::ios_base::fmtflags), std::ostream& argB) { LDKF::print(argA, argB, std::ios::showbase); }
                            template <typename type> constexpr void print(type (&arg)(std::ios_base::fmtflags)) { LDKF::print(arg, std::cout); }

                            template <typename characterType, typename traits> constexpr inline void print(std::basic_ostream<characterType, traits>& (&argA)(std::basic_ostream<characterType, traits>&), std::ostream& argB) { argA(argB); }
                            template <typename characterType, typename traits> constexpr void print(std::basic_ostream<characterType, traits>& (&arg)(std::basic_ostream<characterType, traits>&)) { LDKF::print(arg, std::cout); }

                            template <typename characterType, typename type> constexpr inline void print(type (&argA)(characterType), std::ostream& argB, characterType argC) { argB << argA(argC); }
                            template <typename characterType, typename type> constexpr void print(type (&argA)(characterType), std::ostream& argB) { LDKF::print(argA, argB, characterType()); }
                            template <typename characterType, typename type> constexpr void print(type (&arg)(characterType)) { LDKF::print(arg, std::cout); }

                            // [Pointers]
                            void print(const void* arg) { char* characterString = LDKF::toCharacterString(arg); ::write(STDOUT_FILENO, characterString, LDKF::characterStringLength(characterString)); }

                            // [Character String Literals]
                            void print(char*& arg) { NULL == arg ? ::write(STDOUT_FILENO, "null", 4) : ::write(STDOUT_FILENO, (const char*) arg, LDKF::characterStringLength(arg)); }
                            inline void print(const char arg) { if (NULL == (void*) (int) arg) ::write(STDOUT_FILENO, "null", 4); else { if (arg == '\0') ::write(STDOUT_FILENO, "\\0", 2); else { (arg == '\n') && std::fflush(stdout); const char characterString[2] {arg, '\0'}; ::write(STDOUT_FILENO, characterString, 1); } } }
                            void print(const char*& arg) { NULL == arg ? ::write(STDOUT_FILENO, "null", 4) : ::write(STDOUT_FILENO, arg, LDKF::characterStringLength((char*) arg)); }

                            void print(wchar_t*& arg) { if (NULL == arg) ::write(STDOUT_FILENO, "null", 4); else { char* characterString = LDKF::toCharacterString(arg); print((char*&) characterString); std::free(characterString); } }
                            void print(const wchar_t arg) { if (NULL == (void*) (int) arg) ::write(STDOUT_FILENO, "null", 4); else { wchar_t wideCharacterString[2] = {arg, L'\0'}; char* characterString = LDKF::toCharacterString(wideCharacterString); LDKF::print(*characterString); std::free(characterString); } }
                            void print(const wchar_t*& arg) { if (NULL == arg) ::write(STDOUT_FILENO, "null", 4); else { char* characterString = LDKF::toCharacterString((wchar_t*) arg); print((const char*&) characterString); std::free(characterString); } }

                            void print(char16_t*& arg) { if (NULL == arg) ::write(STDOUT_FILENO, "null", 4); else LDKF::print((wchar_t*&) arg); }
                            void print(const char16_t arg) { if (NULL == (void*) (int) arg) ::write(STDOUT_FILENO, "null", 4); else LDKF::print((const wchar_t) arg); }
                            void print(const char16_t*& arg) { if (NULL == arg) ::write(STDOUT_FILENO, "null", 4); else LDKF::print((const wchar_t*&) arg); }

                            void print(char32_t*& arg) { if (NULL == arg) ::write(STDOUT_FILENO, "null", 4); else { wchar_t* wideCharacterString = LDKF::toWideCharacterString(arg); print((wchar_t*&) wideCharacterString); std::free(wideCharacterString); } }
                            void print(const char32_t arg) { if (NULL == (void*) arg) ::write(STDOUT_FILENO, "null", 4); else LDKF::print((const wchar_t) arg); }
                            void print(const char32_t*& arg) { if (NULL == arg) ::write(STDOUT_FILENO, "null", 4); else { wchar_t* wideCharacterString = LDKF::toWideCharacterString((char32_t*) arg); print((const wchar_t*&) wideCharacterString); std::free(wideCharacterString); } }

                            void print(signed char*& arg) { if (NULL == arg) ::write(STDOUT_FILENO, "null", 4); else LDKF::print((char*&) arg); }
                            void print(const signed char arg) { if (NULL == (void*) (int) arg) ::write(STDOUT_FILENO, "null", 4); else LDKF::print((char) arg); }
                            void print(const signed char*& arg) { if (NULL == arg) ::write(STDOUT_FILENO, "null", 4); else LDKF::print((const char*&) arg); }

                            void print(unsigned char*& arg) { if (NULL == arg) ::write(STDOUT_FILENO, "null", 4); else LDKF::print((char*&) arg); }
                            void print(const unsigned char arg) { if (NULL == (void*) (int) arg) ::write(STDOUT_FILENO, "null", 4); else LDKF::print((char) arg); }
                            void print(const unsigned char*& arg) { if (NULL == arg) ::write(STDOUT_FILENO, "null", 4); else LDKF::print((const char*&) arg); }

                            // [Plain-Old-Data] --- WARN (Lapys) -> Passing `NULL` as an argument calls `void ::print(const int)` and may throw a compiler warning.
                            inline void print(const bool arg) { arg ? ::write(STDOUT_FILENO, "true", 4) : ::write(STDOUT_FILENO, "false", 5); }
                            void print(const double arg) { if (arg - 1 == arg + 1) ::write(STDOUT_FILENO, "Infinity", 8); else if (LDKF::numberIsNaN(arg)) ::write(STDOUT_FILENO, "NaN", 3); else { char* characterString = LDKF::toCharacterString((long double) arg); ::write(STDOUT_FILENO, characterString, LDKF::characterStringLength(characterString)); std::free(characterString); } }
                            void print(const float arg) { if (arg - 1 == arg + 1) ::write(STDOUT_FILENO, "Infinity", 8); else if (LDKF::numberIsNaN(arg)) ::write(STDOUT_FILENO, "NaN", 3); else { char* characterString = LDKF::toCharacterString((long double) arg); ::write(STDOUT_FILENO, characterString, LDKF::characterStringLength(characterString)); std::free(characterString); } }
                            void print(const int arg) { if (arg - 1 == arg + 1) ::write(STDOUT_FILENO, "Infinity", 8); else if (LDKF::numberIsNaN(arg)) ::write(STDOUT_FILENO, "NaN", 3); else { char* characterString = LDKF::toCharacterString((long long) arg); ::write(STDOUT_FILENO, characterString, LDKF::characterStringLength(characterString)); std::free(characterString); } }
                            void print(const long arg) { if (arg - 1 == arg + 1) ::write(STDOUT_FILENO, "Infinity", 8); else if (LDKF::numberIsNaN(arg)) ::write(STDOUT_FILENO, "NaN", 3); else { char* characterString = LDKF::toCharacterString((long long) arg); ::write(STDOUT_FILENO, characterString, LDKF::characterStringLength(characterString)); std::free(characterString); } }
                            void print(const long double arg) { if (arg - 1 == arg + 1) ::write(STDOUT_FILENO, "Infinity", 8); else if (LDKF::numberIsNaN(arg)) ::write(STDOUT_FILENO, "NaN", 3); else { char* characterString = LDKF::toCharacterString(arg); ::write(STDOUT_FILENO, characterString, LDKF::characterStringLength(characterString)); std::free(characterString); } }
                            void print(const long long arg) { if (arg - 1 == arg + 1) ::write(STDOUT_FILENO, "Infinity", 8); else if (LDKF::numberIsNaN(arg)) ::write(STDOUT_FILENO, "NaN", 3); else { char* characterString = LDKF::toCharacterString(arg); ::write(STDOUT_FILENO, characterString, LDKF::characterStringLength(characterString)); std::free(characterString); } }
                            void print(const short arg) { if (arg - 1 == arg + 1) ::write(STDOUT_FILENO, "Infinity", 8); else if (LDKF::numberIsNaN(arg)) ::write(STDOUT_FILENO, "NaN", 3); else { char* characterString = LDKF::toCharacterString((long long) arg); ::write(STDOUT_FILENO, characterString, LDKF::characterStringLength(characterString)); std::free(characterString); } }
                            void print(const unsigned int arg) { if (arg - 1 == arg + 1) ::write(STDOUT_FILENO, "Infinity", 8); else if (LDKF::numberIsNaN(arg)) ::write(STDOUT_FILENO, "NaN", 3); else { char* characterString = LDKF::toCharacterString((unsigned long long) arg); ::write(STDOUT_FILENO, characterString, LDKF::characterStringLength(characterString)); std::free(characterString); } }
                            void print(const unsigned long arg) { if (arg - 1 == arg + 1) ::write(STDOUT_FILENO, "Infinity", 8); else if (LDKF::numberIsNaN(arg)) ::write(STDOUT_FILENO, "NaN", 3); else { char* characterString = LDKF::toCharacterString((unsigned long long) arg); ::write(STDOUT_FILENO, characterString, LDKF::characterStringLength(characterString)); std::free(characterString); } }
                            void print(const unsigned long long arg) { if (arg - 1 == arg + 1) ::write(STDOUT_FILENO, "Infinity", 8); else if (LDKF::numberIsNaN(arg)) ::write(STDOUT_FILENO, "NaN", 3); else { char* characterString = LDKF::toCharacterString(arg); ::write(STDOUT_FILENO, characterString, LDKF::characterStringLength(characterString)); std::free(characterString); } }
                            void print(const unsigned short arg) { if (arg - 1 == arg + 1) ::write(STDOUT_FILENO, "Infinity", 8); else if (LDKF::numberIsNaN(arg)) ::write(STDOUT_FILENO, "NaN", 3); else { char* characterString = LDKF::toCharacterString((unsigned long long) arg); ::write(STDOUT_FILENO, characterString, LDKF::characterStringLength(characterString)); std::free(characterString); } }

                            /* [Aggregates, Classes, Structures & Unions]
                                    --- NOTE (Lapys) -> For non-determinable values.
                                    --- WARN (Lapys) -> Will detect empty arrays of unknown bounds.
                            */
                            void print(std::string arg) { LDKF::print(LDKF::toCharacterString(arg)); }
                            void print(std::u16string arg) { LDKF::print(LDKF::toCharacterString(arg)); }
                            void print(std::u32string arg) { LDKF::print(LDKF::toCharacterString(arg)); }
                            void print(std::wstring arg) { LDKF::print(LDKF::toCharacterString(arg)); }
                            template <typename type> inline void print(type&) { ::write(STDOUT_FILENO, "[object]", 8); }

                            // [Pointers]
                            void print(std::FILE* arg) { if (arg == stderr) ::write(STDOUT_FILENO, "[standard error file pointer]", 29); else if (arg == stdin) ::write(STDOUT_FILENO, "[standard input file pointer]", 29); else if (arg == stdout) ::write(STDOUT_FILENO, "[standard output file pointer]", 30); else LDKF::print((const void*) arg); }
                            template <typename type> void print(type*& arg) { LDKF::print((const void*) arg); }

                            // [Functions]
                            template <typename type> constexpr inline void print(type (&)()) { ::write(STDOUT_FILENO, "[function]", 10); }
                            template <typename type> constexpr inline void print(type (&)(...)) { ::write(STDOUT_FILENO, "[function]", 10); }
                            template <typename type, typename... types> constexpr inline void print(type (&)(types...)) { ::write(STDOUT_FILENO, "[function]", 10); }

                            // [Function Pointers]
                            template <typename type> inline void print(type (*&arg)()) { NULL == arg ? ::write(STDOUT_FILENO, "null", 4) : ::write(STDOUT_FILENO, "[function pointer]", 18); }
                            template <typename type> inline void print(type (*&arg)(...)) { NULL == arg ? ::write(STDOUT_FILENO, "null", 4) : ::write(STDOUT_FILENO, "[function pointer]", 18); }
                            template <typename type, typename... types> inline void print(type (*&arg)(types...)) { NULL == arg ? ::write(STDOUT_FILENO, "null", 4) : ::write(STDOUT_FILENO, "[function pointer]", 18); }

                            /* [Arrays]
                                --- NOTE (Lapys) ->
                                    - Not allowed to distinguish between constant character arrays and constant expression character strings (e.g.: `const char[...] {...}` and `"Hello, World!"`).
                                    - Prints non-null-terminated character strings properly by identifying them as arrays with template `length` (i.e.: `template <std::size_t length> void ::print(const char (&)[length])`).

                                --- UPDATE REQUIRED (Lapys) -> Can not detect empty multi-dimensional arrays (e.g.: `int array[0][0]`).
                                --- WARN (Lapys) -> Can only print arrays with a depth less than the recursive function limit or template instantiation depth.
                            */
                            template <std::size_t length> constexpr void print(const char (&arg)[length]) { std::size_t iterator = length; while (iterator) { const char character = *(arg + (length - (iterator -= 1) - 1)); if (character == '\0') break; else LDKF::print(character); } }
                            template <std::size_t length> constexpr void print(const wchar_t (&arg)[length]) { std::size_t iterator = length; while (iterator) { const wchar_t character = *(arg + (length - (iterator -= 1) - 1)); if (character == L'\0') break; else LDKF::print(character); } }
                            template <std::size_t length> constexpr void print(const char16_t (&arg)[length]) { std::size_t iterator = length; while (iterator) { const char16_t character = *(arg + (length - (iterator -= 1) - 1)); if (character == u'\0') break; else LDKF::print(character); } }
                            template <std::size_t length> constexpr void print(const char32_t (&arg)[length]) { std::size_t iterator = length; while (iterator) { const char32_t character = *(arg + (length - (iterator -= 1) - 1)); if (character == U'\0') break; else LDKF::print(character); } }
                            template <std::size_t length> constexpr void print(const signed char (&arg)[length]) { std::size_t iterator = length; while (iterator) { const signed char character = *(arg + (length - (iterator -= 1) - 1)); if (character == '\0') break; else LDKF::print(character); } }
                            template <std::size_t length> constexpr void print(const unsigned char (&arg)[length]) { std::size_t iterator = length; while (iterator) { const unsigned char character = *(arg + (length - (iterator -= 1) - 1)); if (character) LDKF::print(character); else break; } }
                            template <typename type> constexpr inline void print(type (&)[0]) { ::write(STDOUT_FILENO, "[]", 2); }
                            template <std::size_t length, typename type> constexpr void print(type (&arg)[length]) { char* characterString = LDKF::arrayJoin(arg); ::write(STDOUT_FILENO, "[", 1); ::write(STDOUT_FILENO, characterString, LDKF::characterStringLength(characterString)); ::write(STDOUT_FILENO, "]", 1); std::free(characterString); }

                            // [...] --- WARN (Lapys) -> May not pick up on other non-plain-old-data structures (such as manipulators) and may not resolve data correctly.
                                // [Plain-Old-Data]
                                template <typename type, typename... types> void print(type arg, types... args) { LDKF::print(arg); LDKF::print(args...); }

                                // [Functions]
                                template <typename type, typename... types> void print(type (&arg)(), types... args) { LDKF::print(arg); LDKF::print(args...); }
                                template <typename type, typename... types> void print(type (&arg)(...), types... args) { LDKF::print(arg); LDKF::print(args...); }
                                template <typename type, typename typeTypes, typename... types> void print(type (&arg)(typeTypes...), types... args) { LDKF::print(arg); LDKF::print(args...); }

                                // [Arrays]
                                template <typename type, typename... types> void print(type (&arg)[0], types... args) { LDKF::print(arg); LDKF::print(args...); }
                                template <std::size_t length, typename type, typename... types> void print(type (&arg)[length], types... args) { LDKF::print(arg); LDKF::print(args...); }

                                // [Function Pointers]
                                template <typename type, typename... types> void print(type (*&arg)(), types... args) { LDKF::print(arg); LDKF::print(args...); }
                                template <typename type, typename... types> void print(type (*&arg)(...), types... args) { LDKF::print(arg); LDKF::print(args...); }
                                template <typename type, typename typeTypes, typename... types> void print(type (*&arg)(typeTypes...), types... args) { LDKF::print(arg); LDKF::print(args...); }
                }

                // Objects --- NOTE (Lapys) -> Declare proprietary data structures for the rest of the library.
                inline namespace Objects {
                    /* Class */
                        // Accessor --- NOTE (Lapys) -> For reading data only.
                        template <typename classType>
                        class accessor {};

                        // Flexible Array --- NOTE (Lapys) -> Dynamically allocate/ remove elements from a (re-)sizable array.
                        template <typename structType>
                        struct flexible_array {
                            // [Private]
                            private:
                                // Initialization > (Array, Is Batched, Length, Size, Structure Type Size)
                                structType* array = NULL;
                                bool isBatched = false;
                                std::size_t length = 0, size = 0;
                                const std::size_t STRUCT_TYPE_SIZE = sizeof(structType);

                                // Phase
                                    // Initiate
                                    constexpr inline void init() { this -> array = (structType*) std::malloc(this -> STRUCT_TYPE_SIZE); }

                                    // Terminate
                                    constexpr inline void terminate() { std::free(this -> array); this -> isBatched = this -> length = this -> size = 0; }

                                // Function > (Allocate, Request) Size
                                constexpr inline void allocateSize(std::size_t size) { (this -> size < size) && (this -> array = (structType*) std::realloc(this -> array, sizeof(&(this -> array)) + ((this -> size = size) * this -> STRUCT_TYPE_SIZE))); }
                                constexpr inline static std::size_t requestSize() { return 0; }
                                constexpr inline std::size_t requestSize(structType element) { return sizeof element; }
                                template <typename... types, typename = structType> constexpr std::size_t requestSize(structType element, types... elements) { return this -> requestSize(element) + this -> requestSize(elements...); }

                            // [Public]
                            public:
                                // [Constructor]
                                explicit flexible_array(structType element) { this -> init(); this -> add(element); }
                                template <typename... types, typename = structType> explicit flexible_array(types... elements) { this -> init(); this -> isBatched = true; this -> allocateSize(this -> requestSize(elements...)); this -> add(elements...); this -> isBatched = false; }

                                // [Destructor]
                                ~flexible_array() { this -> terminate(); }

                                // [Operator] > [[]]
                                constexpr inline structType operator [](std::size_t index) { return *(this -> array + index); }

                                // Function
                                    // Add
                                    constexpr inline static void add() {}
                                    constexpr inline void add(structType element) { if (!(this -> isBatched)) this -> allocateSize(this -> size + this -> requestSize(element)); *(this -> array + this -> length) = element; this -> length += 1; }
                                    template <typename... types, typename = structType> constexpr void add(structType element, types... elements) { this -> add(element); this -> add(elements...); }

                                    // Free
                                    constexpr inline void free() { this -> terminate(); this -> init(); }

                                    // Index --- NOTE (Lapys) -> Forward indexing.
                                    constexpr inline int index(structType element) { std::size_t iterator = this -> length; while (iterator) if (*(this -> array + (this -> length - (iterator -= 1) - 1)) == element) return this -> length - iterator - 1; return -1; }

                                    // Remove
                                    constexpr inline static void remove() {}
                                    constexpr inline void remove(structType element) {
                                        // Initialization > Index
                                        int index = this -> index(element);

                                        // Logic
                                        if (~index) {
                                            // Initialization > Length
                                            const std::size_t length = this -> length;

                                            // Logic
                                            if (length == 1)
                                                // Target > Free --- NOTE (Lapys) -> Faster processing...
                                                this -> free();

                                            else {
                                                // Initialization > (Element Is Removed, Former Array, Iterator, Size)
                                                bool elementIsRemoved = false;
                                                structType formerArray[length - 1] {0};
                                                std::size_t iterator = length, size = 0;

                                                // Loop --- NOTE (Lapys) -> Populate the Former Array.
                                                while (iterator) {
                                                    // Update > Index --- NOTE (Lapys) -> Re-purpose the Index variable.
                                                    index = length - (iterator -= 1) - 1;

                                                    // Initialization > Former Element
                                                    structType formerElement = *(this -> array + index);

                                                    // Logic > Update > (...)
                                                    if (element == formerElement && !elementIsRemoved) elementIsRemoved = true;
                                                    else size += this -> requestSize(*(formerArray + index - elementIsRemoved) = formerElement);
                                                }

                                                // Target > (Free, Allocate Size)
                                                this -> free();
                                                this -> allocateSize(size);

                                                // Modification > Target > Length
                                                this -> length = index;

                                                // Loop > Update > (Index, Target > Array)
                                                while (index) { index -= 1; *(this -> array + index) = *(formerArray + index); }
                                            }
                                        }
                                    }
                                    template <typename... types, typename = structType> constexpr void remove(structType element, types... elements) { this -> remove(element); this -> remove(elements...); }

                                    // Request Length
                                    constexpr inline std::size_t requestLength() { return this -> length; }

                                    // To String
                                    const char* toString() { return LDKF::characterStringConcatenate('[', LDKF::arrayJoin(*this, this -> length), ']'); }
                        };

                        // Mutator --- NOTE (Lapys) -> For writing data only.
                        template <typename classType>
                        class mutator {};

                        // Smart Pointer --- NOTE (Lapys) -> Autonomously free up memory used by pointers.
                        template <typename structType>
                        struct smart_pointer {};

                        /* Variable
                            --- NOTE (Lapys) ->
                                - Assess any plain-old-data and a few structures value within this storage class.
                                - Default value is `undefined`.
                                - Stored pointers (except character strings) evaluate to non-numbers.
                                - String conversion is implicitly prioritized over numeric casting.

                            --- WARN (Lapys) -> Does not support array-like values.
                        */
                        class var {
                            // [Private]
                            private:
                                // Function
                                    // Add
                                    LDKO::var add(bool arg) { if (this -> type == this -> string) return LDKF::characterStringConcatenate(this -> toString(), LDKF::characterStringClone(arg ? "true" : "false")); else return this -> toNumber() + arg; }
                                    LDKO::var add(char arg) { return LDKF::characterStringConcatenate(this -> toString(), LDKF::toCharacterString(arg)); }
                                    LDKO::var add(char arg[]) { if (this -> type == this -> string) return LDKF::characterStringConcatenate(this -> toString(), LDKF::characterStringClone(arg)); else return this -> toNumber() + LDKF::toLongDouble(arg); }
                                    LDKO::var add(const char arg[]) { return this -> add((char*) arg); }
                                    LDKO::var add(char16_t arg) { return this -> add(LDKF::toCharacter(arg)); }
                                    LDKO::var add(char32_t arg) { return this -> add(LDKF::toCharacter(arg)); }
                                    LDKO::var add(double arg) { if (this -> type == this -> string) return LDKF::characterStringConcatenate(this -> toString(), LDKF::toCharacterString(arg)); else return this -> toNumber() + arg; }
                                    LDKO::var add(float arg) { if (this -> type == this -> string) return LDKF::characterStringConcatenate(this -> toString(), LDKF::toCharacterString(arg)); else return this -> toNumber() + arg; }
                                    LDKO::var add(int arg) { if (this -> type == this -> string) return LDKF::characterStringConcatenate(this -> toString(), LDKF::toCharacterString(arg)); else return this -> toNumber() + arg; }
                                    LDKO::var add(long arg) { if (this -> type == this -> string) return LDKF::characterStringConcatenate(this -> toString(), LDKF::toCharacterString(arg)); else return this -> toNumber() + arg; }
                                    LDKO::var add(long double arg) { if (this -> type == this -> string) return LDKF::characterStringConcatenate(this -> toString(), LDKF::toCharacterString(arg)); else return this -> toNumber() + arg; }
                                    LDKO::var add(long long arg) { if (this -> type == this -> string) return LDKF::characterStringConcatenate(this -> toString(), LDKF::toCharacterString(arg)); else return this -> toNumber() + arg; }
                                    LDKO::var add(signed char arg) { return LDKF::characterStringConcatenate(this -> toString(), LDKF::toCharacterString(arg)); }
                                    LDKO::var add(short arg) { if (this -> type == this -> string) return LDKF::characterStringConcatenate(this -> toString(), LDKF::toCharacterString(arg)); else return this -> toNumber() + arg; }
                                    LDKO::var add(unsigned char arg) { return LDKF::characterStringConcatenate(this -> toString(), LDKF::toCharacterString(arg)); }
                                    LDKO::var add(unsigned int arg) { if (this -> type == this -> string) return LDKF::characterStringConcatenate(this -> toString(), LDKF::toCharacterString(arg)); else return this -> toNumber() + arg; }
                                    LDKO::var add(unsigned long arg) { if (this -> type == this -> string) return LDKF::characterStringConcatenate(this -> toString(), LDKF::toCharacterString(arg)); else return this -> toNumber() + arg; }
                                    LDKO::var add(unsigned long long arg) { if (this -> type == this -> string) return LDKF::characterStringConcatenate(this -> toString(), LDKF::toCharacterString(arg)); else return this -> toNumber() + arg; }
                                    LDKO::var add(unsigned short arg) { if (this -> type == this -> string) return LDKF::characterStringConcatenate(this -> toString(), LDKF::toCharacterString(arg)); else return this -> toNumber() + arg; }
                                    LDKO::var add(wchar_t arg) { return this -> add(LDKF::toCharacter(arg)); }
                                    LDKO::var add(std::nullptr_t arg) { if (this -> type == this -> string) return LDKF::characterStringConcatenate(this -> toString(), LDKF::characterStringClone("null")); else return this -> toNumber(); }
                                    LDKO::var add(std::string arg) { return this -> add(LDKF::toCharacterString(arg)); }
                                    LDKO::var add(std::u16string arg) { return this -> add(LDKF::toCharacterString(arg)); }
                                    LDKO::var add(std::u32string arg) { return this -> add(LDKF::toCharacterString(arg)); }
                                    LDKO::var add(std::wstring arg) { return this -> add(LDKF::toCharacterString(arg)); }
                                    LDKO::var add(LDKO::var& variable) { if (this -> type == this -> string || variable.type == this -> string) return this -> add(variable.toString()); else  return this -> add(variable.toNumber()); }
                                    LDKO::var add(LDKO::var&& variable) { if (this -> type == this -> string || variable.type == this -> string) return this -> add(variable.toString()); else  return this -> add(variable.toNumber()); }
                                    template <typename type> LDKO::var add(type* arg) { if (this -> type == this -> string) return LDKF::characterStringConcatenate(this -> toString(), LDKF::toCharacterString(arg)); else return NaN; }

                                    // Clone
                                    inline void clone(const LDKO::var& variable) { this -> isInteger = variable.isInteger; this -> isSigned = variable.isSigned; switch (this -> type = variable.type) { case this -> boolean: this -> value.unsignedInteger = variable.value.unsignedInteger; break; case this -> number: this -> isInteger ? (this -> isSigned ? this -> value.signedInteger = variable.value.signedInteger : this -> value.unsignedInteger = variable.value.unsignedInteger) : this -> value.decimal = variable.value.decimal; break; case this -> pointer: this -> value.pointer = variable.value.pointer; break; case this -> string: this -> value.characterString = variable.value.characterString; break; } }

                            // [Protected]
                            protected:
                                // Initialization > (Is (Integer, Not-A-Number, Signed), Type, Value)
                                bool isInteger = false, isNotANumber = false, isSigned = false;
                                enum {boolean, null, number, pointer, string, symbol, undefined} type = this -> undefined;
                                union { char* characterString; long double decimal; long long signedInteger; unsigned long long unsignedInteger; void* pointer; } value;

                                // Phase --- NOTE (Lapys) -> Variables do not have an Initiate or Terminate phase.
                                    // Reset
                                    inline void reset() { switch (this -> type) { case this -> pointer: std::free(this -> value.pointer); break; case this -> string: std::free(this -> value.characterString); break; } this -> isInteger = this -> isNotANumber = this -> isSigned = false; this -> type = this -> undefined; }

                                    // Update
                                    inline void update() { this -> reset(); this -> type = this -> undefined; }
                                    inline void update(bool arg) { this -> reset(); this -> type = this -> boolean; this -> value.unsignedInteger = arg; }
                                    inline void update(char arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(char* arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(const char* arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(char16_t arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(char16_t* arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(const char16_t* arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(char32_t arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(char32_t* arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(const char32_t* arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(double arg) { this -> reset(); LDKF::numberIsNaN(arg) && (this -> isNotANumber = true); this -> type = this -> number; this -> isNotANumber || (this -> value.decimal = arg); }
                                    inline void update(float arg) { this -> reset(); LDKF::numberIsNaN(arg) && (this -> isNotANumber = true); this -> type = this -> number; this -> isNotANumber || (this -> value.decimal = arg); }
                                    inline void update(int arg) { this -> reset(); LDKF::numberIsNaN(arg) && (this -> isNotANumber = true); this -> isInteger = true; this -> isSigned = true; this -> type = this -> number; this -> isNotANumber || (this -> value.signedInteger = arg); }
                                    inline void update(long arg) { this -> reset(); LDKF::numberIsNaN(arg) && (this -> isNotANumber = true); this -> isInteger = true; this -> isSigned = true; this -> type = this -> number; this -> isNotANumber || (this -> value.signedInteger = arg); }
                                    inline void update(long double arg) { this -> reset(); LDKF::numberIsNaN(arg) && (this -> isNotANumber = true); this -> type = this -> number; this -> isNotANumber || (this -> value.decimal = arg); }
                                    inline void update(long long arg) { this -> reset(); LDKF::numberIsNaN(arg) && (this -> isNotANumber = true); this -> isInteger = true; this -> isSigned = true; this -> type = this -> number; this -> isNotANumber || (this -> value.signedInteger = arg); }
                                    inline void update(signed char arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(signed char* arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(const signed char* arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(short arg) { this -> reset(); LDKF::numberIsNaN(arg) && (this -> isNotANumber = true); this -> isInteger = true; this -> isSigned = true; this -> type = this -> number; this -> isNotANumber || (this -> value.signedInteger = arg); }
                                    inline void update(unsigned char arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(unsigned char* arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(const unsigned char* arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(unsigned int arg) { this -> reset(); LDKF::numberIsNaN(arg) && (this -> isNotANumber = true); this -> isInteger = true; this -> type = this -> number; this -> isNotANumber || (this -> value.unsignedInteger = arg); }
                                    inline void update(unsigned long arg) { this -> reset(); LDKF::numberIsNaN(arg) && (this -> isNotANumber = true); this -> isInteger = true; this -> type = this -> number; this -> isNotANumber || (this -> value.unsignedInteger = arg); }
                                    inline void update(unsigned long long arg) { this -> reset(); LDKF::numberIsNaN(arg) && (this -> isNotANumber = true); this -> isInteger = true; this -> type = this -> number; this -> isNotANumber || (this -> value.unsignedInteger = arg); }
                                    inline void update(unsigned short arg) { this -> reset(); LDKF::numberIsNaN(arg) && (this -> isNotANumber = true); this -> isInteger = true; this -> type = this -> number; this -> isNotANumber || (this -> value.unsignedInteger = arg); }
                                    inline void update(wchar_t arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(wchar_t* arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(const wchar_t* arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(std::nullptr_t arg) { this -> reset(); this -> type = this -> null; }
                                    inline void update(std::string arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(std::u16string arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(std::u32string arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    inline void update(std::wstring arg) { this -> reset(); this -> type = this -> string; this -> value.characterString = LDKF::toCharacterString(arg); }
                                    void update(const LDKO::var& variable) { this -> reset(); this -> clone(variable); }
                                    inline void update(LDKO::var&& variable) { this -> reset(); this -> clone(variable); variable.reset(); }
                                    template <typename type> inline void update(type* arg) { this -> reset(); this -> type = this -> pointer; this -> value.pointer = (void*) arg; }

                            // [Public]
                            public:
                                // [Constructor]
                                var() { this -> update(); }
                                var(bool arg) { this -> update(arg); }
                                var(char arg) { this -> update(arg); }
                                var(char* arg) { this -> update(arg); }
                                var(const char* arg) { this -> update(arg); }
                                var(char16_t arg) { this -> update(arg); }
                                var(char16_t* arg) { this -> update(arg); }
                                var(const char16_t* arg) { this -> update(arg); }
                                var(char32_t arg) { this -> update(arg); }
                                var(char32_t* arg) { this -> update(arg); }
                                var(const char32_t* arg) { this -> update(arg); }
                                var(double arg) { this -> update(arg); }
                                var(float arg) { this -> update(arg); }
                                var(int arg) { this -> update(arg); }
                                var(long arg) { this -> update(arg); }
                                var(long double arg) { this -> update(arg); }
                                var(long long arg) { this -> update(arg); }
                                var(signed char arg) { this -> update(arg); }
                                var(signed char* arg) { this -> update(arg); }
                                var(const signed char* arg) { this -> update(arg); }
                                var(short arg) { this -> update(arg); }
                                var(unsigned char arg) { this -> update(arg); }
                                var(unsigned char* arg) { this -> update(arg); }
                                var(const unsigned char* arg) { this -> update(arg); }
                                var(unsigned int arg) { this -> update(arg); }
                                var(unsigned long arg) { this -> update(arg); }
                                var(unsigned long long arg) { this -> update(arg); }
                                var(unsigned short arg) { this -> update(arg); }
                                var(wchar_t arg) { this -> update(arg); }
                                var(wchar_t* arg) { this -> update(arg); }
                                var(const wchar_t* arg) { this -> update(arg); }
                                var(std::nullptr_t arg) { this -> update(arg); }
                                var(std::string arg) { this -> update(arg); }
                                var(std::u16string arg) { this -> update(arg); }
                                var(std::u32string arg) { this -> update(arg); }
                                var(std::wstring arg) { this -> update(arg); }
                                var(const LDKO::var& variable) { this -> update(variable); }
                                var(LDKO::var&& variable) { this -> update(variable); }
                                template <typename type> explicit var(type* arg) { this -> update(arg); }

                                // [Destructor]
                                ~var() { this -> reset(); }

                                // [Operator] --- CHECKPOINT
                                    // [+]
                                    LDKO::var operator +(bool arg) { return this -> add(arg); }
                                    LDKO::var operator +(char arg) { return this -> add(arg); }
                                    LDKO::var operator +(char16_t arg) { return this -> add(arg); }
                                    LDKO::var operator +(char32_t arg) { return this -> add(arg); }
                                    LDKO::var operator +(double arg) { return this -> add(arg); }
                                    LDKO::var operator +(float arg) { return this -> add(arg); }
                                    LDKO::var operator +(int arg) { return this -> add(arg); }
                                    LDKO::var operator +(long arg) { return this -> add(arg); }
                                    LDKO::var operator +(long double arg) { return this -> add(arg); }
                                    LDKO::var operator +(long long arg) { return this -> add(arg); }
                                    LDKO::var operator +(signed char arg) { return this -> add(arg); }
                                    LDKO::var operator +(short arg) { return this -> add(arg); }
                                    LDKO::var operator +(unsigned char arg) { return this -> add(arg); }
                                    LDKO::var operator +(unsigned int arg) { return this -> add(arg); }
                                    LDKO::var operator +(unsigned long arg) { return this -> add(arg); }
                                    LDKO::var operator +(unsigned long long arg) { return this -> add(arg); }
                                    LDKO::var operator +(unsigned short arg) { return this -> add(arg); }
                                    LDKO::var operator +(wchar_t arg) { return this -> add(arg); }
                                    LDKO::var operator +(std::nullptr_t arg) { return this -> add(arg); }
                                    LDKO::var operator +(std::string arg) { return this -> add(arg); }
                                    LDKO::var operator +(std::u16string arg) { return this -> add(arg); }
                                    LDKO::var operator +(std::u32string arg) { return this -> add(arg); }
                                    LDKO::var operator +(std::wstring arg) { return this -> add(arg); }
                                    LDKO::var operator +(LDKO::var& variable) { return this -> add(variable); }
                                    LDKO::var operator +(LDKO::var&& variable) { return this -> add(variable); }
                                    template <typename type> LDKO::var operator +(type* arg) { return this -> add(arg); }

                                    // [-]
                                    // [*]
                                    // [/]
                                    // [%]
                                    // [^]
                                    // [&]
                                    // [|]
                                    // [~]
                                    // [!]
                                    // [,]

                                    // [=]
                                    LDKO::var& operator =(bool arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(char arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(char16_t arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(char32_t arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(double arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(float arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(int arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(long arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(long double arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(long long arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(signed char arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(short arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(unsigned char arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(unsigned int arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(unsigned long arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(unsigned long long arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(unsigned short arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(wchar_t arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(std::nullptr_t arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(std::string arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(std::u16string arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(std::u32string arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(std::wstring arg) { this -> update(arg); return *this; }
                                    LDKO::var& operator =(LDKO::var& variable) { this -> update(variable); return *this; }
                                    LDKO::var& operator =(LDKO::var&& variable) { this -> update(variable); return *this; }
                                    template <typename type> LDKO::var& operator =(type* arg) { this -> update(arg); return *this; }

                                    // [<]
                                    // [>]
                                    // [<=]
                                    // [>=]
                                    // [++]
                                    // [--]
                                    // [==]
                                    // [!=]
                                    // [&&]
                                    // [||]
                                    // [+=]
                                    // [-=]
                                    // [/=]
                                    // [%=]
                                    // [^=]
                                    // [&=]
                                    // [|=]
                                    // [*=]
                                    // [new]
                                    // [delete]

                                // Function
                                    // To Boolean
                                    const bool toBoolean() {
                                        // Logic > Return --- REDACT
                                        switch (this -> type) {
                                            case this -> boolean: return this -> value.unsignedInteger;
                                            case this -> null: return false;
                                            case this -> number: if (this -> isNotANumber) return NaN; else { if (this -> isInteger) if (this -> isSigned) return this -> value.signedInteger; else return this -> value.unsignedInteger; else return this -> value.decimal; }
                                            case this -> pointer: return NULL != this -> value.pointer;
                                            case this -> string: return !LDKF::characterStringIsEmpty(this -> value.characterString);
                                            case this -> symbol: return true;
                                            case this -> undefined: return false;
                                        }
                                    }

                                    // To Number
                                    const long double toNumber() {
                                        // Logic > Return --- REDACT
                                        switch (this -> type) {
                                            case this -> boolean: return this -> value.unsignedInteger;
                                            case this -> null: return 0;
                                            case this -> number: if (this -> isNotANumber) return NaN; else { if (this -> isInteger) if (this -> isSigned) return this -> value.signedInteger; else return this -> value.unsignedInteger; else return this -> value.decimal; }
                                            case this -> pointer: return (int) this -> value.pointer;
                                            case this -> string: return LDKF::toLongDouble(this -> value.characterString);
                                            case this -> symbol: return NaN;
                                            case this -> undefined: return 0;
                                        }
                                    }

                                    // To String
                                    const char* toString() {
                                        // Logic > Return --- REDACT
                                        switch (this -> type) {
                                            case this -> boolean: return LDKF::characterStringClone(this -> value.unsignedInteger ? "true" : "false");
                                            case this -> null: return LDKF::characterStringClone("null");
                                            case this -> number: if (this -> isNotANumber) return LDKF::characterStringClone("NaN"); else { if (this -> isInteger) if (this -> isSigned) return LDKF::toCharacterString(this -> value.signedInteger); else return LDKF::toCharacterString(this -> value.unsignedInteger); else return LDKF::toCharacterString(this -> value.decimal); }
                                            case this -> pointer: return LDKF::toCharacterString(this -> value.pointer);
                                            case this -> string: return LDKF::characterStringClone(this -> value.characterString);
                                            case this -> symbol: return LDKF::characterStringConcatenate("Symbol(", this -> value.characterString, ')');
                                            case this -> undefined: return LDKF::characterStringClone("undefined");
                                        }
                                    }
                        };
                }

                // Data
                inline namespace Data {}

                // Environment
                inline namespace Environment {}

                // Functions
                inline namespace Functions {
                    /* Function */
                        // Print --- NOTE (Lapys) -> Capture the `LapysDevelopmentKit::Functions::print` function for objects made by the library as well.
                            // [LapysDevelopmentKit::Objects::flexible_array]
                            template <typename flexibleArrayType> inline void print(LDKO::flexible_array<flexibleArrayType>& arg) { char* characterString = (char*) arg.toString(); ::write(STDOUT_FILENO, characterString, LDKF::characterStringLength(characterString)); std::free(characterString); }

                            // [LapysDevelopmentKit::Objects::var]
                            inline void print(LDKO::var& arg) { char* characterString = (char*) arg.toString(); ::write(STDOUT_FILENO, characterString, LDKF::characterStringLength(characterString)); std::free(characterString); }
                }

                // Information
                inline namespace Information {}

                // Mathematics
                inline namespace Mathematics {}

                // Objects
                inline namespace Objects {}
        }

        // Lapys
        namespace Lapys {
            /* Namespace > (...) */
            namespace LDKC = LapysDevelopmentKit::Constants;
            namespace LDKD = LapysDevelopmentKit::Data;
            namespace LDKE = LapysDevelopmentKit::Environment;
            namespace LDKF = LapysDevelopmentKit::Functions;
            namespace LDKI = LapysDevelopmentKit::Information;
            namespace LDKM = LapysDevelopmentKit::Mathematics;
            namespace LDKO = LapysDevelopmentKit::Objects;

            /* Class */
                // Object --- CHECKPOINT --- NOTE (Lapys) -> An ECMAScript-style object.
                class Object {
                    // [Private]
                    private:
                        // Class > Property
                        struct property {
                            protected:
                                Object* owner;
                                LDKO::var name = "", value;

                                void init(Object* object) { this -> owner = object; }
                                void update(LDKO::var name) { this -> name = name; }
                                void update(LDKO::var name, LDKO::var value) { this -> name = name; this -> value = value; }

                            public:
                                property(Object* object) { this -> init(object); }
                                property(Object* object, LDKO::var name) { this -> init(object); this -> update(name); }
                                property(Object* object, LDKO::var name, LDKO::var value) { this -> init(object); this -> update(name, value); }

                                LDKO::var operator =(LDKO::var value) {
                                    if (~this -> owner -> properties.index(this))
                                        this -> owner -> properties.add(*this);
                                    this -> update(this -> name, value);
                                }

                                const char* toString() { return LDKF::characterStringConcatenate('"', this -> name.toString(), "\": ", this -> value.toString()); }
                        };

                        // Initialization > Properties
                        LDKO::flexible_array<Object::property> properties;

                    // [Public]
                    public:
                        // [Operator]
                            // [[]]
                            Object::property operator [](LDKO::var name) { return Object::property(this, name); }

                        // Function
                            // To String
                            const char* toString() {
                                const std::size_t length = this -> properties.requestLength(); std::size_t iterator = length;
                                char* propertiesString[iterator];

                                while (iterator) {
                                    iterator -= 1;
                                    *(propertiesString + iterator) = (char*) properties[iterator].toString();
                                }

                                return LDKF::characterStringConcatenate('{', LDKF::arrayJoin(propertiesString, length), '}');
                            }
                };
        }

    /* Utilization */
    using LapysDevelopmentKit::Functions::print;
    using var = LapysDevelopmentKit::Objects::var;

    /* Initialization > Undefined */
    LapysDevelopmentKit::Objects::var undefined;
#endif
