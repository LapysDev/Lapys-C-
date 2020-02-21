/**
    @author: Lapys Dev Team
    @description: Lapys C++ is a general-purpose C++ library for personal project use.
    @version: 0.0.8
    @url: https://www.github.com/LapysDev/LapysCPP

    --- NOTE ---
        #Lapys:
            - Supported environment standards:
                -- ISO/IEC 14882:1998 (C++98) (1998 - 2003) - current...
            - Over its years of development, the library is still a bare-bones version of what it could be.
            - Characteristics Length: Math.floor(Math.log10(x)) + 1

    --- RULES ---
        #Lapys:
            - Functions can only be minified if they perform at optimal absolutism.
*/
#pragma once
#ifndef LAPYS_H
    /* Import --- NOTE (Lapys) -> Import all Lapys C++ sub-systems. */
    #include "lapys/includes.h"
    #include "lapys/polyfills.h"
    #include "lapys/types.h"
    #include "lapys/main.h"

    /* Namespace > Lapys */
    namespace Lapys {
        /* Namespace > Lapys Development Kit */
        namespace LapysDevelopmentKit {
            /* Namespace */
                // ...
                namespace {
                    /* Global */
                        // Strict  --- NOTE (Lapys) -> Cause alternative logical paths within a function or method. Also known as an argument flag.
                        int STRICT;
                }

                /* Constants */
                inline namespace Constants {
                    // Number --- REDACT (Lapys)
                    inline namespace Number {
                        const double Infinity = INFINITY;
                        const float NaN = NAN;
                        const minimal_numeric_type
                            significantDigits = 6,
                            tabFillLength = 1, tabWidth = 4;
                    }

                    // String --- NOTE (Lapys) -> This is the English iteration. --- REDACT (Lapys)
                    inline namespace String {
                        const char
                            alphabets[52] {'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z'},
                            binary[2] {'0', '1'},
                            digits[10] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'},
                            hexadecimal[22] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F'},
                            lowercaseAlphabets[26] {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
                            octal[8] {'0', '1', '2', '3', '4', '5', '6', '7'},
                            sortableCharacters[64] {'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '_', '$'},
                            uppercaseAlphabets[26] {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
                            variableCharacters[64] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z', '_', '$'};
                        const char
                            *cardinal[][69] {
                                {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"},
                                {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"},
                                {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"},
                                {
                                    "hundred", "thousand",
                                    "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion", "octillion", "nonillion", "decillion",
                                    "undecillion", "duodecillion", "tredecillion", "quattordecillion", "quindecillion", "sexdecillion", "septendecillion", "octodecillion", "novemdecillion",
                                    "vigintillion", "unvigintillion", "duovigintillion", "trevigintillion", "quattorvigintillion", "quinvigintillion", "sexvigintillion", "septvigintillion", "octovigintillion", "nonvigintillion",
                                    "trigintillion", "untrigintillion", "duotrigintillion", "googol", "trestrigintillion", "quattuortrigintillion", "sestrigintillion", "septentrigintillion", "octotrigintillion", "noventrigintillion",
                                    "quadragintillion", "quinquagintillion", "sexagintillion", "septuagintillion", "octogintillion", "nonagintillion",
                                    "centillion", "uncentillion", "decicentillion", "undecicentillion", "viginticentillion", "unviginticentillion", "trigintacentillion", "quadragintacentillion", "quinquagintacentillion", "sexagintacentillion", "septuagintacentillion", "octogintacentillion", "nonagintacentillion", "ducentillion", "trecentillion", "quadringentillion", "sescentillion", "septingentillion", "octingentillion", "nongentillion",
                                    "millinillion",
                                    "googolplex"
                                }
                            },
                            *ordinal[4] {"th", "st", "nd", "rd"};
                        const char tabFill[] = " ";
                    }
                }
                    // Utilization
                    using LDKC::Number::Infinity;
                    using LDKC::Number::NaN;

                /* Functions */
                inline namespace Functions {
                    /* Function */
                        // Is Negative
                        inline const bool numberIsNegative(double number) { return number < 0; }
                        inline const bool numberIsNegative(float number) { return number < 0; }
                        inline const bool numberIsNegative(int number) { return number < 0; }
                        inline const bool numberIsNegative(long number) { return number < 0; }
                        inline const bool numberIsNegative(long double number) { return number < 0; }
                        inline const bool numberIsNegative(long long number) { return number < 0; }
                        inline const bool numberIsNegative(short number) { return number < 0; }
                        inline const bool numberIsNegative(unsigned int number) { return number < 0; }
                        inline const bool numberIsNegative(unsigned long number) { return number < 0; }
                        inline const bool numberIsNegative(unsigned long long number) { return number < 0; }
                        inline const bool numberIsNegative(unsigned short number) { return number < 0; }

                        // Is Positive
                        inline const bool numberIsPositive(double number) { return !number || number > 0; }
                        inline const bool numberIsPositive(float number) { return !number || number > 0; }
                        inline const bool numberIsPositive(int number) { return !number || number > 0; }
                        inline const bool numberIsPositive(long number) { return !number || number > 0; }
                        inline const bool numberIsPositive(long double number) { return !number || number > 0; }
                        inline const bool numberIsPositive(long long number) { return !number || number > 0; }
                        inline const bool numberIsPositive(short number) { return !number || number > 0; }
                        inline const bool numberIsPositive(unsigned int number) { return !number || number > 0; }
                        inline const bool numberIsPositive(unsigned long number) { return !number || number > 0; }
                        inline const bool numberIsPositive(unsigned long long number) { return !number || number > 0; }
                        inline const bool numberIsPositive(unsigned short number) { return !number || number > 0; }

                        // Is Safe --- UPDATE REQUIRED (Lapys) -> Update the limits for the decimal numbers.
                        inline const bool numberIsSafe(double number) { return number > -0x7FFFFFFFFFFFFFFF && number < 0x8000000000000000; }
                        inline const bool numberIsSafe(float number) { return number > -0x7FFFFFFFFFFFFFFF && number < 0x8000000000000000; }
                        inline const bool numberIsSafe(int number) { return number > -0x80000000 && number < 0x7FFFFFFF; }
                        inline const bool numberIsSafe(long number) { return number > -0x80000000 && number < 0x7FFFFFFF; }
                        inline const bool numberIsSafe(long double number) { return number > -0x7FFFFFFFFFFFFFFF && number < 0x8000000000000000; }
                        inline const bool numberIsSafe(long long number) { return number > -0x7FFFFFFFFFFFFFFF && number < 0x8000000000000000; }
                        inline const bool numberIsSafe(short number) { return number > -0x8000 && number < 0x7FFF; }
                        inline const bool numberIsSafe(unsigned int number) { return number > 0x0 && number < 0x100000000; }
                        inline const bool numberIsSafe(unsigned long number) { return number > 0x0 && number < 0x100000000; }
                        inline const bool numberIsSafe(unsigned long long number) { return number > 0x0 && number < 1.84e17; }
                        inline const bool numberIsSafe(unsigned short number) { return number > 0x0 && number < 0x10000; }
                }

                /* Mathematics */
                inline namespace Mathematics {
                    /* Function */
                        // Absolute
                        const double abs(const double number) { return LDKF::numberIsNegative(number) ? -number : number; }
                        const float abs(const float number) { return LDKF::numberIsNegative(number) ? -number : number; }
                        inline const int abs(const int number) { return (number ^ (number >> 31)) - (number >> 31); }
                        inline const long abs(const long number) { return (number ^ (number >> 31)) - (number >> 31); }
                        const long double abs(const long double number) { return LDKF::numberIsNegative(number) ? -number : number; }
                        inline const long long abs(const long long number) { return (number ^ (number >> 63)) - (number >> 63); }
                        inline const short abs(const short number) { return (number ^ (number >> 15)) - (number >> 15); }
                        inline const unsigned int abs(const unsigned int number) { return number; }
                        inline const unsigned long abs(const unsigned long number) { return number; }
                        inline const unsigned long long abs(const unsigned long long number) { return number; }
                        inline const unsigned short abs(const unsigned short number) { return number; }

                        // Modulus
                        const long double mod(const long double numberA, const long double numberB) { if (numberB) { long double modulus = LDKM::abs(numberA), divisor = LDKM::abs(numberB); while (modulus >= divisor) modulus -= divisor; return LDKF::numberIsNegative(numberA) ? -modulus : modulus; } else return std::nanl(""); }
                        const long double mod(const long double numberA, const double numberB) { return LDKM::mod(numberA, (long double) numberB); }
                        const long double mod(const long double numberA, const float numberB) { return LDKM::mod(numberA, (long double) numberB); }
                        const long double mod(const long double numberA, const int numberB) { return LDKM::mod(numberA, (long double) numberB); }
                        const long double mod(const long double numberA, const long numberB) { return LDKM::mod(numberA, (long double) numberB); }
                        const long double mod(const long double numberA, const long long numberB) { return LDKM::mod(numberA, (long double) numberB); }
                        const long double mod(const long double numberA, const short numberB) { return LDKM::mod(numberA, (long double) numberB); }
                        const long double mod(const long double numberA, const unsigned int numberB) { return LDKM::mod(numberA, (long double) numberB); }
                        const long double mod(const long double numberA, const unsigned long numberB) { return LDKM::mod(numberA, (long double) numberB); }
                        const long double mod(const long double numberA, const unsigned long long numberB) { return LDKM::mod(numberA, (long double) numberB); }
                        const long double mod(const long double numberA, const unsigned short numberB) { return LDKM::mod(numberA, (long double) numberB); }

                        const double mod(const double numberA, const double numberB) { if (numberB) { double modulus = LDKM::abs(numberA), divisor = LDKM::abs(numberB); while (modulus >= divisor) modulus -= divisor; return LDKF::numberIsNegative(numberA) ? -modulus : modulus; } else return std::nan(""); }
                        const double mod(const double numberA, const float numberB) { return LDKM::mod(numberA, (double) numberB); }
                        const double mod(const double numberA, const int numberB) { return LDKM::mod(numberA, (double) numberB); }
                        const double mod(const double numberA, const long numberB) { return LDKM::mod(numberA, (double) numberB); }
                        const long double mod(const double numberA, const long double numberB) { return LDKM::mod((long double) numberA, numberB); }
                        const double mod(const double numberA, const long long numberB) { return LDKM::mod(numberA, (double) numberB); }
                        const double mod(const double numberA, const short numberB) { return LDKM::mod(numberA, (double) numberB); }
                        const double mod(const double numberA, const unsigned int numberB) { return LDKM::mod(numberA, (double) numberB); }
                        const double mod(const double numberA, const unsigned long numberB) { return LDKM::mod(numberA, (double) numberB); }
                        const long double mod(const double numberA, const unsigned long long numberB) { return LDKM::mod((long double) numberA, (long double) numberB); }
                        const double mod(const double numberA, const unsigned short numberB) { return LDKM::mod(numberA, (double) numberB); }

                        const float mod(const float numberA, const float numberB) { if (numberB) { float modulus = LDKM::abs(numberA), divisor = LDKM::abs(numberB); while (modulus >= divisor) modulus -= divisor; return LDKF::numberIsNegative(numberA) ? -modulus : modulus; } else return NaN; }
                        const double mod(const float numberA, const double numberB) { return LDKM::mod((double) numberA, numberB); }
                        const float mod(const float numberA, const int numberB) { return LDKM::mod(numberA, (float) numberB); }
                        const float mod(const float numberA, const long numberB) { return LDKM::mod(numberA, (float) numberB); }
                        const long double mod(const float numberA, const long double numberB) { return LDKM::mod((long double) numberA, numberB); }
                        const double mod(const float numberA, const long long numberB) { return LDKM::mod((double) numberA, (double) numberB); }
                        const float mod(const float numberA, const short numberB) { return LDKM::mod(numberA, (float) numberB); }
                        const double mod(const float numberA, const unsigned int numberB) { return LDKM::mod((double) numberA, (double) numberB); }
                        const double mod(const float numberA, const unsigned long numberB) { return LDKM::mod((double) numberA, (double) numberB); }
                        const long double mod(const float numberA, const unsigned long long numberB) { return LDKM::mod((long double) numberA, (long double) numberB); }
                        const float mod(const float numberA, const unsigned short numberB) { return LDKM::mod(numberA, numberB); }
                }

                /* Functions */
                inline namespace Functions {
                    /* Function */
                        // Character
                            // Is Digit
                            inline const bool characterIsDigit(const char character) { return character == '0' || character == '1' || character == '2' || character == '3' || character == '4' || character == '5' || character == '6' || character == '7' || character == '8' || character == '9'; }

                            // Is Non-Digit
                            const bool characterIsNonDigit(const char character) { return !LDKF::characterIsDigit(character); }

                        // Get Arguments Length
                        inline const minimal_numeric_type getArgumentsLength() { return 0; }
                        template <typename type> inline const minimal_numeric_type getArgumentsLength(type) { return 1; }
                        template <typename type, typename... types> const minimal_numeric_type getArgumentsLength(type argument, types... arguments) { return LDKF::getArgumentsLength(argument) + LDKF::getArgumentsLength(arguments...); }

                        // Pointer
                            // Is Null
                            inline const bool pointerIsNull(const void* pointer) { return NULL == pointer; }
                            inline const bool pointerIsNull(void* pointer) { return NULL == pointer; }

                        // Number
                            // To Integer
                            inline const long long numberToInteger(double number) { return number; }
                            inline const long numberToInteger(float number) { return number; }
                            inline const int numberToInteger(int number) { return number; }
                            inline const long numberToInteger(long number) { return number; }
                            inline const long long numberToInteger(long double number) { return number; }
                            inline const long long numberToInteger(long long number) { return number; }
                            inline const short numberToInteger(short number) { return number; }
                            inline const unsigned int numberToInteger(unsigned int number) { return number; }
                            inline const unsigned long numberToInteger(unsigned long number) { return number; }
                            inline const unsigned long long numberToInteger(unsigned long long number) { return number; }
                            inline const unsigned short numberToInteger(unsigned short number) { return number; }

                        // Character String
                            // Is Empty
                            const bool characterStringIsEmpty(const char* characterString) { return LDKF::pointerIsNull(characterString) || *characterString == '\0'; }
                            const bool characterStringIsEmpty(char* characterString) { return LDKF::characterStringIsEmpty((const char*) characterString); }

                            // Is Non-Empty
                            const bool characterStringIsNonEmpty(const char* characterString) { return !LDKF::characterStringIsEmpty(characterString); }
                            const bool characterStringIsNonEmpty(char* characterString) { return !LDKF::characterStringIsEmpty(characterString); }

                            // Length
                            inline const unsigned characterStringLength(const char* characterString) {
                                // Logic > ...
                                if (LDKF::characterStringIsEmpty(characterString)) return 0;
                                else { unsigned length = 0; const char* pointer = characterString; while (*((pointer += 1) - 1)) length += 1; return length; }
                            }
                            inline const unsigned characterStringLength(char* characterString) { return LDKF::characterStringLength((const char*) characterString); }

                            // Allocate On Heap
                            void characterStringAllocateOnHeap(char*& characterString) {
                                // Initialization > (Character String (Length, Iterator), Former Character String)
                                const unsigned characterStringLength = LDKF::characterStringLength(characterString);
                                unsigned characterStringIterator;
                                char formerCharacterString[characterStringLength];

                                // Update > Character String Iterator --- NOTE (Lapys) -> Cache the content of the Character String.
                                characterStringIterator = characterStringLength;
                                while (characterStringIterator) { characterStringIterator -= 1; *(formerCharacterString + characterStringIterator) = *(characterString + characterStringIterator); }

                                // Update > Character String (Iterator)
                                characterString = (char*) std::malloc((characterStringLength + 1) * sizeof(char));
                                *(characterString + characterStringLength) = '\0';
                                characterStringIterator = characterStringLength;

                                // Loop > Update > Character String (Iterator) --- NOTE (Lapys) -> Fill the Character String again.
                                while (characterStringIterator) { characterStringIterator -= 1; *(characterString + characterStringIterator) = *(formerCharacterString + characterStringIterator); }
                            }

                            // Binary To Decimal
                            inline const unsigned characterStringBinaryToDecimal(const char* characterStringBinarySegment, const unsigned characterStringBinarySegmentLength) {
                                // Initialization > ((Character String) (Decimal, Iterator), Exponent)
                                const char* characterString = characterStringBinarySegment;
                                unsigned long long characterStringDecimal = 0;
                                unsigned characterStringIterator = characterStringBinarySegmentLength - 1;
                                unsigned long long exponent = 1;

                                // Loop > Update > (Character String, Exponent)
                                while (characterStringIterator) { (*(characterString + (characterStringIterator -= 1)) == '1') && (characterStringDecimal += exponent); exponent *= 2; }

                                // Return
                                return characterStringDecimal;
                            }
                            const unsigned characterStringBinaryToDecimal(const char* characterStringBinarySegment) { return LDKF::characterStringBinaryToDecimal(characterStringBinarySegment, LDKF::characterStringLength(characterStringBinarySegment)); }

                            // Clone
                            const char* characterStringClone(const char* characterString, const unsigned characterStringLength) {
                                // Initialization > Character String (Clone, Iterator)
                                char* _characterStringClone = (char*) std::malloc((characterStringLength + 1) * sizeof(char));
                                unsigned characterStringIterator = characterStringLength;

                                // (Loop > )Update > ...
                                *(_characterStringClone + characterStringLength) = '\0';
                                while (characterStringIterator) { characterStringIterator -= 1; *(_characterStringClone + characterStringIterator) = *(characterString + characterStringIterator); }

                                // Return
                                return _characterStringClone;
                            }
                            const char* characterStringClone(const char* characterString) { return LDKF::characterStringClone(characterString, LDKF::characterStringLength(characterString)); }
                            const char* characterStringClone(char* characterString, const unsigned characterStringLength) { return LDKF::characterStringClone((const char*) characterString, characterStringLength); }
                            const char* characterStringClone(char* characterString) { return LDKF::characterStringClone((const char*) characterString, LDKF::characterStringLength(characterString)); }

                            // Source Concatenate
                            const char* characterStringSourceConcatenate(char*& characterString, const char characterConcatenation, const unsigned characterStringLength) {
                                // Initialization > Former Character String
                                char* formerCharacterString = (char*) LDKF::characterStringClone(characterString);

                                // Deletion
                                std::free(characterString);

                                // Update > Character String
                                characterString = (char*) LDKF::characterStringClone(formerCharacterString, characterStringLength);

                                // Deletion
                                std::free(formerCharacterString);

                                // Update > Character String
                                characterString = (char*) std::realloc(characterString, (characterStringLength + 2) * sizeof(char));
                                *(characterString + characterStringLength) = characterConcatenation;
                                *(characterString + (characterStringLength + 1)) = '\0';

                                // Return
                                return characterString;
                            }
                            const char* characterStringSourceConcatenate(char*& characterString, const char characterConcatenation) { return LDKF::characterStringSourceConcatenate(characterString, characterConcatenation, LDKF::characterStringLength(characterString)); }
                            const char* characterStringSourceConcatenate(const char*& characterString, const char characterConcatenation, const unsigned characterStringLength) { return LDKF::characterStringSourceConcatenate((char*&) characterString, characterConcatenation, characterStringLength); }
                            const char* characterStringSourceConcatenate(const char*& characterString, const char characterConcatenation) { return LDKF::characterStringSourceConcatenate((char*&) characterString, characterConcatenation, LDKF::characterStringLength(characterString)); }

                            const char* characterStringSourceConcatenate(char*& characterString, const char* characterStringConcatenation, const unsigned characterStringLength, const unsigned characterStringConcatenationLength) {
                                // Initialization > Character String Concatenation Iterator
                                unsigned characterStringConcatenationIterator = characterStringConcatenationLength;
                                char* formerCharacterString = (char*) LDKF::characterStringClone(characterString);

                                // Deletion
                                std::free(characterString);

                                // Update > Character String
                                characterString = (char*) LDKF::characterStringClone(formerCharacterString, characterStringLength);

                                // Deletion
                                std::free(formerCharacterString);

                                // (Loop > )Update > ...
                                characterString = (char*) std::realloc(characterString, (characterStringLength + characterStringConcatenationLength + 1) * sizeof(char));
                                *(characterString + (characterStringLength + characterStringConcatenationLength)) = '\0';
                                while (characterStringConcatenationIterator) { characterStringConcatenationIterator -= 1; *(characterString + characterStringLength + (characterStringConcatenationLength - characterStringConcatenationIterator - 1)) = *(characterStringConcatenation + (characterStringConcatenationLength - characterStringConcatenationIterator - 1)); }

                                // Return
                                return characterString;
                            }
                            const char* characterStringSourceConcatenate(char*& characterString, char* characterStringConcatenation, const unsigned characterStringLength, const unsigned characterStringConcatenationLength) { return LDKF::characterStringSourceConcatenate(characterString, (const char*) characterStringConcatenation, characterStringLength, characterStringConcatenationLength); }
                            const char* characterStringSourceConcatenate(char*& characterString, char* characterStringConcatenation, const unsigned characterStringLength) { return LDKF::characterStringSourceConcatenate(characterString, (const char*) characterStringConcatenation, characterStringLength, LDKF::characterStringLength(characterStringConcatenation)); }
                            const char* characterStringSourceConcatenate(char*& characterString, char* characterStringConcatenation) { return LDKF::characterStringSourceConcatenate(characterString, (const char*) characterStringConcatenation, LDKF::characterStringLength(characterString), LDKF::characterStringLength(characterStringConcatenation)); }
                            const char* characterStringSourceConcatenate(char*& characterString, const char* characterStringConcatenation, const unsigned characterStringLength) { return LDKF::characterStringSourceConcatenate(characterString, characterStringConcatenation, characterStringLength, LDKF::characterStringLength(characterStringConcatenation)); }
                            const char* characterStringSourceConcatenate(char*& characterString, const char* characterStringConcatenation) { return LDKF::characterStringSourceConcatenate(characterString, characterStringConcatenation, LDKF::characterStringLength(characterString), LDKF::characterStringLength(characterStringConcatenation)); }
                            const char* characterStringSourceConcatenate(const char*& characterString, const char* characterStringConcatenation, const unsigned characterStringLength, const unsigned characterStringConcatenationLength) { return LDKF::characterStringSourceConcatenate((char*&) characterString, characterStringConcatenation, characterStringLength, characterStringConcatenationLength); }
                            const char* characterStringSourceConcatenate(const char*& characterString, const char* characterStringConcatenation, const unsigned characterStringLength) { return LDKF::characterStringSourceConcatenate((char*&) characterString, characterStringConcatenation, characterStringLength, LDKF::characterStringLength(characterStringConcatenation)); }
                            const char* characterStringSourceConcatenate(const char*& characterString, const char* characterStringConcatenation) { return LDKF::characterStringSourceConcatenate((char*&) characterString, characterStringConcatenation, LDKF::characterStringLength(characterString), LDKF::characterStringLength(characterStringConcatenation)); }
                            const char* characterStringSourceConcatenate(const char*& characterString, char* characterStringConcatenation, const unsigned characterStringLength, const unsigned characterStringConcatenationLength) { return LDKF::characterStringSourceConcatenate((char*&) characterString, (const char*) characterStringConcatenation, characterStringLength, characterStringConcatenationLength); }
                            const char* characterStringSourceConcatenate(const char*& characterString, char* characterStringConcatenation, const unsigned characterStringLength) { return LDKF::characterStringSourceConcatenate((char*&) characterString, (const char*) characterStringConcatenation, characterStringLength, LDKF::characterStringLength(characterStringConcatenation)); }
                            const char* characterStringSourceConcatenate(const char*& characterString, char* characterStringConcatenation) { return LDKF::characterStringSourceConcatenate((char*&) characterString, (const char*) characterStringConcatenation, LDKF::characterStringLength(characterString), LDKF::characterStringLength(characterStringConcatenation)); }

                            // Concatenate
                            const char* characterStringConcatenate(const char* characterString, const char character, const unsigned characterStringLength) {
                                // Initialization > Character String
                                char* characterString_ = NULL;

                                // Update > Character String
                                LDKF::characterStringSourceConcatenate(characterString_, characterString, 0u, characterStringLength);
                                LDKF::characterStringSourceConcatenate(characterString_, character, characterStringLength);

                                // Return
                                return characterString_;
                            }
                            const char* characterStringConcatenate(const char* characterString, const char character) { return LDKF::characterStringConcatenate(characterString, character, LDKF::characterStringLength(characterString)); }
                            const char* characterStringConcatenate(char* characterString, const char character, const unsigned characterStringLength) { return LDKF::characterStringConcatenate((const char*) characterString, character, characterStringLength); }
                            const char* characterStringConcatenate(char* characterString, const char character) { return LDKF::characterStringConcatenate((const char*) characterString, character, LDKF::characterStringLength(characterString)); }
                            const char* characterStringConcatenate(const char* characterStringA, const char* characterStringB, const unsigned characterStringALength, const unsigned characterStringBLength) {
                                // Initialization > Character String
                                char* characterString = NULL;

                                // Update > Character String
                                LDKF::characterStringSourceConcatenate(characterString, characterStringA, 0u, characterStringALength);
                                LDKF::characterStringSourceConcatenate(characterString, characterStringB, characterStringALength, characterStringBLength);

                                // Return
                                return characterString;
                            }
                            const char* characterStringConcatenate(const char* characterStringA, const char* characterStringB, const unsigned characterStringALength) { return LDKF::characterStringConcatenate(characterStringA, characterStringB, characterStringALength, LDKF::characterStringLength(characterStringB)); }
                            const char* characterStringConcatenate(const char* characterStringA, const char* characterStringB) { return LDKF::characterStringConcatenate(characterStringA, characterStringB, LDKF::characterStringLength(characterStringA), LDKF::characterStringLength(characterStringB)); }
                            const char* characterStringConcatenate(const char* characterStringA, char* characterStringB, const unsigned characterStringALength, const unsigned characterStringBLength) { return LDKF::characterStringConcatenate(characterStringA, (const char*) characterStringB, characterStringALength, characterStringBLength); }
                            const char* characterStringConcatenate(const char* characterStringA, char* characterStringB, const unsigned characterStringALength) { return LDKF::characterStringConcatenate(characterStringA, (const char*) characterStringB, characterStringALength, LDKF::characterStringLength(characterStringB)); }
                            const char* characterStringConcatenate(const char* characterStringA, char* characterStringB) { return LDKF::characterStringConcatenate(characterStringA, (const char*) characterStringB, LDKF::characterStringLength(characterStringA), LDKF::characterStringLength(characterStringB)); }
                            const char* characterStringConcatenate(char* characterStringA, const char* characterStringB, const unsigned characterStringALength, const unsigned characterStringBLength) { return LDKF::characterStringConcatenate((const char*) characterStringA, characterStringB, characterStringALength, characterStringBLength); }
                            const char* characterStringConcatenate(char* characterStringA, const char* characterStringB, const unsigned characterStringALength) { return LDKF::characterStringConcatenate((const char*) characterStringA, characterStringB, characterStringALength, LDKF::characterStringLength(characterStringB)); }
                            const char* characterStringConcatenate(char* characterStringA, const char* characterStringB) { return LDKF::characterStringConcatenate((const char*) characterStringA, characterStringB, LDKF::characterStringLength(characterStringA), LDKF::characterStringLength(characterStringB)); }
                            const char* characterStringConcatenate(char* characterStringA, char* characterStringB, const unsigned characterStringALength, const unsigned characterStringBLength) { return LDKF::characterStringConcatenate((const char*) characterStringA, (const char*) characterStringB, characterStringALength, characterStringBLength); }
                            const char* characterStringConcatenate(char* characterStringA, char* characterStringB, const unsigned characterStringALength) { return LDKF::characterStringConcatenate((const char*) characterStringA, (const char*) characterStringB, characterStringALength, LDKF::characterStringLength(characterStringB)); }
                            const char* characterStringConcatenate(char* characterStringA, char* characterStringB) { return LDKF::characterStringConcatenate((const char*) characterStringA, (const char*) characterStringB, LDKF::characterStringLength(characterStringA), LDKF::characterStringLength(characterStringB)); }


                            // Hexadecimal To Decimal
                            inline const unsigned long long characterStringHexadecimalToDecimal(const char* characterStringHexadecimalSegment, const unsigned characterStringHexadecimalSegmentLength) {
                                // Initialization > (Character String (Decimal, Iterator), Exponent)
                                unsigned long long characterStringDecimal = 0;
                                unsigned characterStringIterator = characterStringHexadecimalSegmentLength - 1;
                                unsigned long long exponent = 1;

                                // Loop
                                while (characterStringIterator) {
                                    // Initialization > Character String Hexadecimal Segment Character
                                    const char characterStringHexadecimalSegmentCharacter = *(characterStringHexadecimalSegment + (characterStringIterator -= 1));

                                    // Logic
                                    if (LDKF::characterIsDigit(characterStringHexadecimalSegmentCharacter)) {
                                        // Logic > Update > Character String Decimal
                                        switch (characterStringHexadecimalSegmentCharacter) {
                                            case '1': characterStringDecimal += exponent; break;
                                            case '2': characterStringDecimal += 2 * exponent; break;
                                            case '3': characterStringDecimal += 3 * exponent; break;
                                            case '4': characterStringDecimal += 4 * exponent; break;
                                            case '5': characterStringDecimal += 5 * exponent; break;
                                            case '6': characterStringDecimal += 6 * exponent; break;
                                            case '7': characterStringDecimal += 7 * exponent; break;
                                            case '8': characterStringDecimal += 8 * exponent; break;
                                            case '9': characterStringDecimal += 9 * exponent;
                                        }

                                        // Update > Exponent
                                        exponent *= 16;
                                    }

                                    else if (
                                        (characterStringHexadecimalSegmentCharacter == 'a' || characterStringHexadecimalSegmentCharacter == 'A') ||
                                        (characterStringHexadecimalSegmentCharacter == 'b' || characterStringHexadecimalSegmentCharacter == 'B') ||
                                        (characterStringHexadecimalSegmentCharacter == 'c' || characterStringHexadecimalSegmentCharacter == 'C') ||
                                        (characterStringHexadecimalSegmentCharacter == 'd' || characterStringHexadecimalSegmentCharacter == 'D') ||
                                        (characterStringHexadecimalSegmentCharacter == 'e' || characterStringHexadecimalSegmentCharacter == 'E') ||
                                        (characterStringHexadecimalSegmentCharacter == 'f' || characterStringHexadecimalSegmentCharacter == 'F')
                                    ) {
                                        // Logic > Update > Character String Decimal
                                        switch (characterStringHexadecimalSegmentCharacter) {
                                            case 'a': case 'A': characterStringDecimal += 10 * exponent; break;
                                            case 'b': case 'B': characterStringDecimal += 11 * exponent; break;
                                            case 'c': case 'C': characterStringDecimal += 12 * exponent; break;
                                            case 'd': case 'D': characterStringDecimal += 13 * exponent; break;
                                            case 'e': case 'E': characterStringDecimal += 14 * exponent; break;
                                            case 'f': case 'F': characterStringDecimal += 15 * exponent;
                                        }

                                        // Update > Exponent
                                        exponent *= 16;
                                    }
                                }

                                // Return
                                return characterStringDecimal;
                            }
                            const unsigned characterStringHexadecimalToDecimal(const char* characterStringHexadecimalSegment) { return LDKF::characterStringHexadecimalToDecimal(characterStringHexadecimalSegment, LDKF::characterStringLength(characterStringHexadecimalSegment)); }

                            // Is
                            inline const bool characterStringIs(const char* characterStringA, const char* characterStringB, const unsigned characterStringALength, const unsigned characterStringBLength) {
                                // Logic
                                if (characterStringALength == characterStringBLength) {
                                    // Initialization > Character String Iterator
                                    unsigned characterStringIterator = characterStringALength;

                                    // Loop
                                    while (characterStringIterator) {
                                        // Update > Character String Iterator
                                        characterStringIterator -= 1;

                                        // Logic > Return
                                        if (*(characterStringA + characterStringIterator) ^ *(characterStringB + characterStringIterator))
                                            return false;
                                    }

                                    // Return
                                    return true;
                                }

                                else
                                    // Return
                                    return false;
                            }
                            const bool characterStringIs(const char* characterStringA, const char* characterStringB, const unsigned characterStringALength) { return LDKF::characterStringIs(characterStringA, characterStringB, characterStringALength, LDKF::characterStringLength(characterStringB)); }
                            const bool characterStringIs(const char* characterStringA, const char* characterStringB) { return LDKF::characterStringIs(characterStringA, characterStringB, LDKF::characterStringLength(characterStringA), LDKF::characterStringLength(characterStringB)); }
                            const bool characterStringIs(const char* characterStringA, char* characterStringB, const unsigned characterStringALength, const unsigned characterStringBLength) { return LDKF::characterStringIs(characterStringA, (const char*) characterStringB, characterStringALength, characterStringBLength); }
                            const bool characterStringIs(const char* characterStringA, char* characterStringB, const unsigned characterStringALength) { return LDKF::characterStringIs(characterStringA, (const char*) characterStringB, characterStringALength, LDKF::characterStringLength(characterStringB)); }
                            const bool characterStringIs(const char* characterStringA, char* characterStringB) { return LDKF::characterStringIs(characterStringA, (const char*) characterStringB, LDKF::characterStringLength(characterStringA), LDKF::characterStringLength(characterStringB)); }
                            const bool characterStringIs(char* characterStringA, const char* characterStringB, const unsigned characterStringALength, const unsigned characterStringBLength) { return LDKF::characterStringIs((const char*) characterStringA, characterStringB, characterStringALength, characterStringBLength); }
                            const bool characterStringIs(char* characterStringA, const char* characterStringB, const unsigned characterStringALength) { return LDKF::characterStringIs((const char*) characterStringA, characterStringB, characterStringALength, LDKF::characterStringLength(characterStringB)); }
                            const bool characterStringIs(char* characterStringA, const char* characterStringB) { return LDKF::characterStringIs((const char*) characterStringA, characterStringB, LDKF::characterStringLength(characterStringA), LDKF::characterStringLength(characterStringB)); }
                            const bool characterStringIs(char* characterStringA, char* characterStringB, const unsigned characterStringALength, const unsigned characterStringBLength) { return LDKF::characterStringIs((const char*) characterStringA, (const char*) characterStringB, characterStringALength, characterStringBLength); }
                            const bool characterStringIs(char* characterStringA, char* characterStringB, const unsigned characterStringALength) { return LDKF::characterStringIs((const char*) characterStringA, (const char*) characterStringB, characterStringALength, LDKF::characterStringLength(characterStringB)); }
                            const bool characterStringIs(char* characterStringA, char* characterStringB) { return LDKF::characterStringIs((const char*) characterStringA, (const char*) characterStringB, LDKF::characterStringLength(characterStringA), LDKF::characterStringLength(characterStringB)); }

                            // Slice
                            const char* characterStringSlice(const char* characterString, unsigned index, unsigned length, unsigned characterStringLength) {
                                // Initialization > Character String Slice
                                char* characterStringSlice = (char*) std::malloc(sizeof(char));

                                // Update > Character String Slice
                                *characterStringSlice = '\0';

                                // Logic
                                if (characterStringLength)
                                    // Logic
                                    if (index < length + 1 && index < characterStringLength + 1) {
                                        // Update > (Length, Character String (Length, Slice))
                                        (length > characterStringLength - 1) && (length = characterStringLength - 1);
                                        characterStringLength = length - index;
                                        characterStringSlice = (char*) std::realloc(characterStringSlice, (characterStringLength + 1) * sizeof(char));

                                        // Initialization > Character String Iterator
                                        unsigned characterStringIterator = 0;

                                        // Loop
                                        while (index ^ length + 1) {
                                            // Update > (Character String (Slice, Iterator), Iterator)
                                            *(characterStringSlice + characterStringIterator) = *(characterString + index);
                                            characterStringIterator += 1;
                                            index += 1;
                                        }

                                        // Update > Character String Slice
                                        *(characterStringSlice + characterStringIterator) = '\0';
                                    }

                                    else if (index > length) {
                                        // Initialization > Character (String Slice, (Substring Slice) (Length, Iterator))
                                        unsigned characterStringSliceLength = 0,
                                            characterSubtringSliceIterator = 0,
                                            characterSubtringSliceLength = length > characterStringLength - 1 ? characterStringLength : length;
                                        char* characterSubtringSlice = (char*) LDKF::characterStringSlice(characterString, 0, characterSubtringSliceLength, characterStringLength);

                                        // Update > Character String Slice
                                        characterStringSlice = (char*) std::realloc(characterStringSlice, (characterSubtringSliceLength + 1) * sizeof(char));
                                        *(characterStringSlice + characterSubtringSliceLength) = '\0';

                                        // Loop
                                        while (characterSubtringSliceIterator ^ characterSubtringSliceLength) {
                                            // Update > Character (String Slice (Length), Substring Slice Iterator)
                                            *(characterStringSlice + characterStringSliceLength) = *(characterSubtringSlice + characterSubtringSliceIterator);
                                            characterStringSliceLength += 1;
                                            characterSubtringSliceIterator += 1;
                                        }

                                        // Logic
                                        if (index < characterStringLength) {
                                            // Update > Character ((Substring Slice) (Iterator, Length), Slice)
                                            characterSubtringSlice = (char*) LDKF::characterStringSlice(characterString, index, characterStringLength, characterStringLength);
                                            characterSubtringSliceIterator = 0;
                                            characterSubtringSliceLength = characterStringLength - index;
                                            characterStringSlice = (char*) std::realloc(characterStringSlice, (characterStringSliceLength + characterSubtringSliceLength + 1) * sizeof(char));

                                            // Loop
                                            while (characterSubtringSliceIterator ^ characterSubtringSliceLength) {
                                                // Update > Character (String Slice (Length), Substring Slice Iterator)
                                                *(characterStringSlice + characterStringSliceLength) = *(characterSubtringSlice + characterSubtringSliceIterator);
                                                characterStringSliceLength += 1;
                                                characterSubtringSliceIterator += 1;
                                            }

                                            // Update > Character String Slice
                                            *(characterStringSlice + characterStringSliceLength) = '\0';
                                        }
                                    }

                                // Return
                                return characterStringSlice;
                            }
                            const char* characterStringSlice(const char* characterString, unsigned index, unsigned length) { return LDKF::characterStringSlice(characterString, index, length, LDKF::characterStringLength(characterString)); }
                            const char* characterStringSlice(char* characterString, unsigned index, unsigned length, const unsigned characterStringLength) { return LDKF::characterStringSlice((const char*) characterString, index, length, characterStringLength); }
                            const char* characterStringSlice(char* characterString, unsigned index, unsigned length) { return LDKF::characterStringSlice((const char*) characterString, index, length, LDKF::characterStringLength(characterString)); }

                            // Begins With
                            inline const bool characterStringBeginsWith(const char* characterString, const char character, const unsigned characterStringLength = 1) { return *characterString == character; }
                            const bool characterStringBeginsWith(char* characterString, const char character, const unsigned characterStringLength = 1) { return LDKF::characterStringBeginsWith((const char*) characterString, character); }
                            const bool characterStringBeginsWith(const char* characterString, const char* characterSubstring, const unsigned characterStringLength, unsigned characterSubstringLength) { return LDKF::characterStringIsEmpty(characterSubstring) || LDKF::characterStringIs(LDKF::characterStringSlice(characterString, 0u, characterSubstringLength - 1, characterStringLength), characterSubstring, characterSubstringLength - 1, characterSubstringLength); }
                            const bool characterStringBeginsWith(const char* characterString, const char* characterSubstring, const unsigned characterStringLength) { return LDKF::characterStringBeginsWith(characterString, characterSubstring, characterStringLength, LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringBeginsWith(const char* characterString, const char* characterSubstring) { return LDKF::characterStringBeginsWith(characterString, characterSubstring, LDKF::characterStringLength(characterString), LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringBeginsWith(const char* characterString, char* characterSubstring, const unsigned characterStringLength, const unsigned characterSubstringLength) { return LDKF::characterStringBeginsWith(characterString, (const char*) characterSubstring, characterStringLength, characterSubstringLength); }
                            const bool characterStringBeginsWith(const char* characterString, char* characterSubstring, const unsigned characterStringLength) { return LDKF::characterStringBeginsWith(characterString, (const char*) characterSubstring, characterStringLength, LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringBeginsWith(const char* characterString, char* characterSubstring) { return LDKF::characterStringBeginsWith(characterString, (const char*) characterSubstring, LDKF::characterStringLength(characterString), LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringBeginsWith(char* characterString, const char* characterSubstring, const unsigned characterStringLength, const unsigned characterSubstringLength) { return LDKF::characterStringBeginsWith((const char*) characterString, characterSubstring, characterStringLength, characterSubstringLength); }
                            const bool characterStringBeginsWith(char* characterString, const char* characterSubstring, const unsigned characterStringLength) { return LDKF::characterStringBeginsWith((const char*) characterString, characterSubstring, characterStringLength, LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringBeginsWith(char* characterString, const char* characterSubstring) { return LDKF::characterStringBeginsWith((const char*) characterString, characterSubstring, LDKF::characterStringLength(characterString), LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringBeginsWith(char* characterString, char* characterSubstring, const unsigned characterStringLength, const unsigned characterSubstringLength) { return LDKF::characterStringBeginsWith((const char*) characterString, (const char*) characterSubstring, characterStringLength, characterSubstringLength); }
                            const bool characterStringBeginsWith(char* characterString, char* characterSubstring, const unsigned characterStringLength) { return LDKF::characterStringBeginsWith((const char*) characterString, (const char*) characterSubstring, characterStringLength, LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringBeginsWith(char* characterString, char* characterSubstring) { return LDKF::characterStringBeginsWith((const char*) characterString, (const char*) characterSubstring, LDKF::characterStringLength(characterString), LDKF::characterStringLength(characterSubstring)); }

                            // Ends With
                            inline const bool characterStringEndsWith(const char* characterString, const char character, const unsigned characterStringLength) { return *(characterString + (characterStringLength - 1)) == character; }
                            const bool characterStringEndsWith(const char* characterString, const char character) { return LDKF::characterStringEndsWith(characterString, character, LDKF::characterStringLength(characterString)); }
                            const bool characterStringEndsWith(char* characterString, const char character, const unsigned characterStringLength) { return LDKF::characterStringEndsWith((const char*) characterString, character, characterStringLength); }
                            const bool characterStringEndsWith(char* characterString, const char character) { return LDKF::characterStringEndsWith((const char*) characterString, character, LDKF::characterStringLength(characterString)); }
                            const bool characterStringEndsWith(const char* characterString, const char* characterSubstring, const unsigned characterStringLength, const unsigned characterSubstringLength) { return LDKF::characterStringIsEmpty(characterSubstring) || LDKF::characterStringIs(LDKF::characterStringSlice(characterString, characterStringLength - characterSubstringLength, characterStringLength, characterStringLength), characterSubstring, characterStringLength - (characterStringLength - characterSubstringLength), characterSubstringLength); }
                            const bool characterStringEndsWith(const char* characterString, const char* characterSubstring, const unsigned characterStringLength) { return LDKF::characterStringEndsWith(characterString, characterSubstring, characterStringLength, LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringEndsWith(const char* characterString, const char* characterSubstring) { return LDKF::characterStringEndsWith(characterString, characterSubstring, LDKF::characterStringLength(characterString), LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringEndsWith(const char* characterString, char* characterSubstring, const unsigned characterStringLength, const unsigned characterSubstringLength) { return LDKF::characterStringEndsWith(characterString, (const char*) characterSubstring, characterStringLength, characterSubstringLength); }
                            const bool characterStringEndsWith(const char* characterString, char* characterSubstring, const unsigned characterStringLength) { return LDKF::characterStringEndsWith(characterString, (const char*) characterSubstring, characterStringLength, LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringEndsWith(const char* characterString, char* characterSubstring) { return LDKF::characterStringEndsWith(characterString, (const char*) characterSubstring, LDKF::characterStringLength(characterString), LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringEndsWith(char* characterString, const char* characterSubstring, const unsigned characterStringLength, const unsigned characterSubstringLength) { return LDKF::characterStringEndsWith((const char*) characterString, characterSubstring, characterStringLength, characterSubstringLength); }
                            const bool characterStringEndsWith(char* characterString, const char* characterSubstring, const unsigned characterStringLength) { return LDKF::characterStringEndsWith((const char*) characterString, characterSubstring, characterStringLength, LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringEndsWith(char* characterString, const char* characterSubstring) { return LDKF::characterStringEndsWith((const char*) characterString, characterSubstring, LDKF::characterStringLength(characterString), LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringEndsWith(char* characterString, char* characterSubstring, const unsigned characterStringLength, const unsigned characterSubstringLength) { return LDKF::characterStringEndsWith((const char*) characterString, (const char*) characterSubstring, characterStringLength, characterSubstringLength); }
                            const bool characterStringEndsWith(char* characterString, char* characterSubstring, const unsigned characterStringLength) { return LDKF::characterStringEndsWith((const char*) characterString, (const char*) characterSubstring, characterStringLength, LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringEndsWith(char* characterString, char* characterSubstring) { return LDKF::characterStringEndsWith((const char*) characterString, (const char*) characterSubstring, LDKF::characterStringLength(characterString), LDKF::characterStringLength(characterSubstring)); }

                            // Includes
                            inline const bool characterStringIncludes(const char* characterString, const char character, const unsigned characterStringLength) {
                                // Logic
                                if (characterStringLength == 1)
                                    // Return
                                    return *characterString == character;

                                else {
                                    // Initialization > (Stop Length, String Iterator)
                                    unsigned stopLength = LDKF::numberToInteger(characterStringLength / 4),
                                        characterStringIterator = characterStringLength - ((stopLength * 3) - 1);

                                    // Loop
                                    while (characterStringIterator) {
                                        // Update > String Iterator
                                        characterStringIterator -= 1;

                                        // Logic > Return
                                        if (
                                            *(characterString + (characterStringLength - characterStringIterator)) == character ||
                                            *(characterString + (characterStringLength - stopLength - characterStringIterator)) == character ||
                                            *(characterString + (characterStringIterator + stopLength)) == character ||
                                            *(characterString + characterStringIterator) == character
                                        ) return true;
                                    }

                                    // Return
                                    return false;
                                }
                            }
                            const bool characterStringIncludes(const char* characterString, const char character) { return LDKF::characterStringIncludes(characterString, character, LDKF::characterStringLength(characterString)); }
                            const bool characterStringIncludes(char* characterString, const char character, const unsigned characterStringLength) { return LDKF::characterStringIncludes((const char*) characterString, character, characterStringLength); }
                            const bool characterStringIncludes(char* characterString, const char character) { return LDKF::characterStringIncludes(characterString, character, LDKF::characterStringLength(characterString)); }
                            const bool characterStringIncludes(const char* characterString, const char* characterSubstring, const unsigned characterStringLength, const unsigned characterSubstringLength) {
                                // Logic
                                if (!characterSubstringLength)
                                    // Return
                                    return true;

                                else if (characterStringLength == characterSubstringLength)
                                    // Return
                                    return LDKF::characterStringIs(characterString, characterSubstring);

                                else if (characterSubstringLength == 1)
                                    // Return
                                    return LDKF::characterStringIncludes(characterString, *characterSubstring);

                                else if (
                                    LDKF::characterStringBeginsWith(characterString, characterSubstring, characterStringLength, characterSubstringLength) ||
                                    LDKF::characterStringEndsWith(characterString, characterSubstring, characterStringLength, characterSubstringLength)
                                )
                                    // Return
                                    return true;

                                else {
                                    // Initialization > Character String Iterator
                                    unsigned characterStringIterator = characterStringLength;

                                    // Loop
                                    while (characterStringIterator) {
                                        // Update > Character String Iterator
                                        characterStringIterator -= 1;

                                        // Logic
                                        if (*(characterString + (characterStringLength - characterStringIterator - 1)) == *characterSubstring) {
                                            // Initialization > Character String (Index)
                                            unsigned index = characterSubstringLength - 1,
                                                characterStringIndex = characterStringLength - characterStringIterator - 1;

                                            // Loop > Update > Index
                                            while ((index ^ 1) && *(characterString + (characterStringIndex + index)) == *(characterSubstring + index)) index -= 1;

                                            // Logic > Return
                                            if (index == 1 && *(characterString + (characterStringIndex + 1)) == *(characterSubstring + 1))
                                                return true;
                                        }

                                        else if (*(characterString + characterStringIterator) == *(characterSubstring + (characterSubstringLength - 1))) {
                                            // Initialization > Index
                                            unsigned index = 0;

                                            // Loop > Update > Index
                                            while ((index ^ (characterSubstringLength - 1)) && *(characterString + (characterStringIterator - index)) == *(characterSubstring + (characterSubstringLength - index - 1))) index += 1;

                                            // Logic > Return
                                            if (index == characterSubstringLength - 1 && *(characterString + (characterStringIterator - index)) == *characterSubstring)
                                                return true;
                                        }
                                    }

                                    // Return
                                    return false;
                                }
                            }
                            const bool characterStringIncludes(const char* characterString, const char* characterSubstring, const unsigned characterStringLength) { return LDKF::characterStringIncludes(characterString, characterSubstring, characterStringLength, LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringIncludes(const char* characterString, const char* characterSubstring) { return LDKF::characterStringIncludes(characterString, characterSubstring, LDKF::characterStringLength(characterString), LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringIncludes(const char* characterString, char* characterSubstring, const unsigned characterStringLength, const unsigned characterSubstringLength) { return LDKF::characterStringIncludes(characterString, (const char*) characterSubstring, characterStringLength, characterSubstringLength); }
                            const bool characterStringIncludes(const char* characterString, char* characterSubstring, const unsigned characterStringLength) { return LDKF::characterStringIncludes(characterString, (const char*) characterSubstring, characterStringLength, LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringIncludes(const char* characterString, char* characterSubstring) { return LDKF::characterStringIncludes(characterString, (const char*) characterSubstring, LDKF::characterStringLength(characterString), LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringIncludes(char* characterString, const char* characterSubstring, const unsigned characterStringLength, const unsigned characterSubstringLength) { return LDKF::characterStringIncludes((const char*) characterString, characterSubstring, characterStringLength, characterSubstringLength); }
                            const bool characterStringIncludes(char* characterString, const char* characterSubstring, const unsigned characterStringLength) { return LDKF::characterStringIncludes((const char*) characterString, characterSubstring, characterStringLength, LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringIncludes(char* characterString, const char* characterSubstring) { return LDKF::characterStringIncludes((const char*) characterString, characterSubstring, LDKF::characterStringLength(characterString), LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringIncludes(char* characterString, char* characterSubstring, const unsigned characterStringLength, const unsigned characterSubstringLength) { return LDKF::characterStringIncludes((const char*) characterString, (const char*) characterSubstring, characterStringLength, characterSubstringLength); }
                            const bool characterStringIncludes(char* characterString, char* characterSubstring, const unsigned characterStringLength) { return LDKF::characterStringIncludes((const char*) characterString, (const char*) characterSubstring, characterStringLength, LDKF::characterStringLength(characterSubstring)); }
                            const bool characterStringIncludes(char* characterString, char* characterSubstring) { return LDKF::characterStringIncludes((const char*) characterString, (const char*) characterSubstring, LDKF::characterStringLength(characterString), LDKF::characterStringLength(characterSubstring)); }

                        // Number
                            // Characteristics Length
                            inline const minimal_numeric_type numberCharacteristicsLength(int number) { minimal_numeric_type length = 0; while (number) { length += 1; number /= 10; } return length; }
                            inline const minimal_numeric_type numberCharacteristicsLength(long number) { minimal_numeric_type length = 0; while (number) { length += 1; number /= 10; } return length; }
                            const minimal_numeric_type numberCharacteristicsLength(float number) { return LDKF::numberCharacteristicsLength((long) number); }
                            inline const minimal_numeric_type numberCharacteristicsLength(long long number) { minimal_numeric_type length = 0; while (number) { length += 1; number /= 10; } return length; }
                            const minimal_numeric_type numberCharacteristicsLength(double number) { return LDKF::numberCharacteristicsLength((long long) number); }
                            const minimal_numeric_type numberCharacteristicsLength(long double number) { return LDKF::numberCharacteristicsLength((long long) number); }
                            inline const minimal_numeric_type numberCharacteristicsLength(short number) { minimal_numeric_type length = 0; while (number) { length += 1; number /= 10; } return length; }
                            inline const minimal_numeric_type numberCharacteristicsLength(unsigned int number) { minimal_numeric_type length = 0; while (number) { length += 1; number /= 10; } return length; }
                            inline const minimal_numeric_type numberCharacteristicsLength(unsigned long number) { minimal_numeric_type length = 0; while (number) { length += 1; number /= 10; } return length; }
                            inline const minimal_numeric_type numberCharacteristicsLength(unsigned long long number) { minimal_numeric_type length = 0; while (number) { length += 1; number /= 10; } return length; }
                            inline const minimal_numeric_type numberCharacteristicsLength(unsigned short number) { minimal_numeric_type length = 0; while (number) { length += 1; number /= 10; } return length; }

                            // Is Infinite
                            const bool numberIsInfinite(const double number) { return std::isinf(number); }
                            const bool numberIsInfinite(const float number) { return std::isinf(number); }
                            const bool numberIsInfinite(const int number) { return std::isinf(number); }
                            const bool numberIsInfinite(const long number) { return std::isinf(number); }
                            const bool numberIsInfinite(const long double number) { return std::isinf(number); }
                            const bool numberIsInfinite(const long long number) { return std::isinf(number); }
                            const bool numberIsInfinite(const short number) { return std::isinf(number); }
                            const bool numberIsInfinite(const unsigned int number) { return std::isinf(number); }
                            const bool numberIsInfinite(const unsigned long number) { return std::isinf(number); }
                            const bool numberIsInfinite(const unsigned long long number) { return std::isinf(number); }
                            const bool numberIsInfinite(const unsigned short number) { return std::isinf(number); }

                            // Is Finite
                            const bool numberIsFinite(const double number) { return !LDKF::numberIsInfinite(number); }
                            const bool numberIsFinite(const float number) { return !LDKF::numberIsInfinite(number); }
                            const bool numberIsFinite(const int number) { return !LDKF::numberIsInfinite(number); }
                            const bool numberIsFinite(const long number) { return !LDKF::numberIsInfinite(number); }
                            const bool numberIsFinite(const long double number) { return !LDKF::numberIsInfinite(number); }
                            const bool numberIsFinite(const long long number) { return !LDKF::numberIsInfinite(number); }
                            const bool numberIsFinite(const short number) { return !LDKF::numberIsInfinite(number); }
                            const bool numberIsFinite(const unsigned int number) { return !LDKF::numberIsInfinite(number); }
                            const bool numberIsFinite(const unsigned long number) { return !LDKF::numberIsInfinite(number); }
                            const bool numberIsFinite(const unsigned long long number) { return !LDKF::numberIsInfinite(number); }
                            const bool numberIsFinite(const unsigned short number) { return !LDKF::numberIsInfinite(number); }

                            // Is Not-A-Number
                            const bool numberIsNaN(const double number) { return std::isnan(number); }
                            const bool numberIsNaN(const float number) { return std::isnan(number); }
                            inline const bool numberIsNaN(const int number) { return false; }
                            inline const bool numberIsNaN(const long number) { return false; }
                            const bool numberIsNaN(const long double number) { return std::isnan(number); }
                            inline const bool numberIsNaN(const long long number) { return false; }
                            inline const bool numberIsNaN(const short number) { return false; }
                            inline const bool numberIsNaN(const unsigned int number) { return false; }
                            inline const bool numberIsNaN(const unsigned long number) { return false; }
                            inline const bool numberIsNaN(const unsigned long long number) { return false; }
                            inline const bool numberIsNaN(const unsigned short number) { return false; }

                            // Mantissa Length --- MINIFY (Lapys)
                            const minimal_numeric_type numberMantissaLength(double number) { bool isSafe = false; const bool isSigned = LDKF::numberIsNegative(number); long long integer = number; minimal_numeric_type length = 0; if (number != integer) while ((isSafe = LDKF::numberIsSafe(integer)) && (isSafe ? number < integer : number > integer) && (isSigned ? LDKF::numberIsNegative(integer) : LDKF::numberIsPositive(integer))) { number *= 10; integer = number; length += 1; } return length + isSafe; }
                            const minimal_numeric_type numberMantissaLength(float number) { bool isSafe = false; const bool isSigned = LDKF::numberIsNegative(number); long integer = number; minimal_numeric_type length = 0; if (number != integer) while ((isSafe = LDKF::numberIsSafe(integer)) && (isSafe ? number < integer : number > integer) && (isSigned ? LDKF::numberIsNegative(integer) : LDKF::numberIsPositive(integer))) { number *= 10; integer = number; length += 1; } return length + isSafe; }
                            inline const minimal_numeric_type numberMantissaLength(const int) { return 0; }
                            inline const minimal_numeric_type numberMantissaLength(const long) { return 0; }
                            const minimal_numeric_type numberMantissaLength(long double number) { bool isSafe = false; const bool isSigned = LDKF::numberIsNegative(number); long long integer = number; minimal_numeric_type length = 0; if (number != integer) while ((isSafe = LDKF::numberIsSafe(integer)) && (isSigned ? number < integer : number > integer) && (isSigned ? LDKF::numberIsNegative(integer) : LDKF::numberIsPositive(integer))) { number *= 10; integer = number; length += 1; } return length + isSafe; }
                            inline const minimal_numeric_type numberMantissaLength(const long long) { return 0; }
                            inline const minimal_numeric_type numberMantissaLength(const short) { return 0; }
                            inline const minimal_numeric_type numberMantissaLength(const unsigned int) { return 0; }
                            inline const minimal_numeric_type numberMantissaLength(const unsigned long) { return 0; }
                            inline const minimal_numeric_type numberMantissaLength(const unsigned long long) { return 0; }
                            inline const minimal_numeric_type numberMantissaLength(const unsigned short) { return 0; }

                        // Signed Character String
                            // Is Empty
                            const bool signedCharacterStringIsEmpty(const signed char* signedCharacterString) { return LDKF::pointerIsNull(signedCharacterString) || *signedCharacterString == '\0'; }
                            const bool signedCharacterStringIsEmpty(signed char* signedCharacterString) { return LDKF::signedCharacterStringIsEmpty((const signed char*) signedCharacterString); }

                            // Is Non-Empty
                            const bool signedCharacterStringIsNonEmpty(const signed char* signedCharacterString) { return !LDKF::signedCharacterStringIsEmpty(signedCharacterString); }
                            const bool signedCharacterStringIsNonEmpty(signed char* signedCharacterString) { return !LDKF::signedCharacterStringIsEmpty(signedCharacterString); }

                            // Length
                            inline const signed signedCharacterStringLength(const signed char* signedCharacterString) {
                                // Logic > ...
                                if (LDKF::signedCharacterStringIsEmpty(signedCharacterString)) return 0;
                                else { signed length = 0; const signed char* pointer = signedCharacterString; while (*((pointer += 1) - 1)) length += 1; return length; }
                            }
                            inline const signed signedCharacterStringLength(signed char* signedCharacterString) { return LDKF::signedCharacterStringLength((const signed char*) signedCharacterString); }

                        // Unsigned Character String
                            // Is Empty
                            const bool unsignedCharacterStringIsEmpty(const unsigned char* unsignedCharacterString) { return LDKF::pointerIsNull(unsignedCharacterString) || *unsignedCharacterString == '\0'; }
                            const bool unsignedCharacterStringIsEmpty(unsigned char* unsignedCharacterString) { return LDKF::unsignedCharacterStringIsEmpty((const unsigned char*) unsignedCharacterString); }

                            // Is Non-Empty
                            const bool unsignedCharacterStringIsNonEmpty(const unsigned char* unsignedCharacterString) { return !LDKF::unsignedCharacterStringIsEmpty(unsignedCharacterString); }
                            const bool unsignedCharacterStringIsNonEmpty(unsigned char* unsignedCharacterString) { return !LDKF::unsignedCharacterStringIsEmpty(unsignedCharacterString); }

                            // Length
                            inline const unsigned unsignedCharacterStringLength(const unsigned char* unsignedCharacterString) {
                                // Logic > ...
                                if (LDKF::unsignedCharacterStringIsEmpty(unsignedCharacterString)) return 0;
                                else { unsigned length = 0; const unsigned char* pointer = unsignedCharacterString; while (*((pointer += 1) - 1)) length += 1; return length; }
                            }
                            inline const unsigned unsignedCharacterStringLength(unsigned char* unsignedCharacterString) { return LDKF::unsignedCharacterStringLength((const unsigned char*) unsignedCharacterString); }

                        // UTF-16 Character String
                            // Is Empty
                            const bool utf16CharacterStringIsEmpty(const char16_t* utf16CharacterString) { return LDKF::pointerIsNull(utf16CharacterString) || *utf16CharacterString == u'\0'; }
                            const bool utf16CharacterStringIsEmpty(char16_t* utf16CharacterString) { return LDKF::utf16CharacterStringIsEmpty((const char16_t*) utf16CharacterString); }

                            // Is Non-Empty
                            const bool utf16CharacterStringIsNonEmpty(const char16_t* utf16CharacterString) { return !LDKF::utf16CharacterStringIsEmpty(utf16CharacterString); }
                            const bool utf16CharacterStringIsNonEmpty(char16_t* utf16CharacterString) { return !LDKF::utf16CharacterStringIsEmpty(utf16CharacterString); }

                            // Length
                            inline const unsigned utf16CharacterStringLength(const char16_t* utf16CharacterString) {
                                // Logic > ...
                                if (LDKF::utf16CharacterStringIsEmpty(utf16CharacterString)) return 0;
                                else { unsigned length = 0; const char16_t* pointer = utf16CharacterString; while (*((pointer += 1) - 1)) length += 1; return length; }
                            }
                            inline const unsigned utf16CharacterStringLength(char16_t* utf16CharacterString) { return LDKF::utf16CharacterStringLength((const char16_t*) utf16CharacterString); }

                        // UTF-32 Character String
                            // Is Empty
                            const bool utf32CharacterStringIsEmpty(const char32_t* utf32CharacterString) { return LDKF::pointerIsNull(utf32CharacterString) || *utf32CharacterString == U'\0'; }
                            const bool utf32CharacterStringIsEmpty(char32_t* utf32CharacterString) { return LDKF::utf32CharacterStringIsEmpty((const char32_t*) utf32CharacterString); }

                            // Is Non-Empty
                            const bool utf32CharacterStringIsNonEmpty(const char32_t* utf32CharacterString) { return !LDKF::utf32CharacterStringIsEmpty(utf32CharacterString); }
                            const bool utf32CharacterStringIsNonEmpty(char32_t* utf32CharacterString) { return !LDKF::utf32CharacterStringIsEmpty(utf32CharacterString); }

                            // Length
                            inline const unsigned utf32CharacterStringLength(const char32_t* utf32CharacterString) {
                                // Logic > ...
                                if (LDKF::utf32CharacterStringIsEmpty(utf32CharacterString)) return 0;
                                else { unsigned length = 0; const char32_t* pointer = utf32CharacterString; while (*((pointer += 1) - 1)) length += 1; return length; }
                            }
                            inline const unsigned utf32CharacterStringLength(char32_t* utf32CharacterString) { return LDKF::utf32CharacterStringLength((const char32_t*) utf32CharacterString); }

                        // Wide Character String
                            // Is Empty
                            const bool wideCharacterStringIsEmpty(const wchar_t* wideCharacterString) { return LDKF::pointerIsNull(wideCharacterString) || *wideCharacterString == L'\0'; }
                            const bool wideCharacterStringIsEmpty(wchar_t* wideCharacterString) { return LDKF::wideCharacterStringIsEmpty((const wchar_t*) wideCharacterString); }

                            // Is Non-Empty
                            const bool wideCharacterStringIsNonEmpty(const wchar_t* wideCharacterString) { return !LDKF::wideCharacterStringIsEmpty(wideCharacterString); }
                            const bool wideCharacterStringIsNonEmpty(wchar_t* wideCharacterString) { return !LDKF::wideCharacterStringIsEmpty(wideCharacterString); }

                            // Length
                            inline const unsigned wideCharacterStringLength(const wchar_t* wideCharacterString) {
                                // Logic > ...
                                if (LDKF::wideCharacterStringIsEmpty(wideCharacterString)) return 0;
                                else { unsigned length = 0; const wchar_t* pointer = wideCharacterString; while (*((pointer += 1) - 1)) length += 1; return length; }
                            }
                            inline const unsigned wideCharacterStringLength(wchar_t* wideCharacterString) { return LDKF::wideCharacterStringLength((const wchar_t*) wideCharacterString); }

                        // To
                            // Number
                            inline const char toNumber(const char argument, bool CAST_ARGUMENT = true) {
                                // Logic > ...
                                if (CAST_ARGUMENT) return argument;
                                else switch (argument) { case '0': return 0; case '1': return 1; case '2': return 2; case '3': return 3; case '4': return 4; case '5': return 5; case '6': return 6; case '7': return 7; case '8': return 8; case '9': return 9; }
                            }
                            const long double toNumber(const char* argument) {
                                // Logic
                                if (LDKF::characterStringIsEmpty(argument))
                                    // Return
                                    return 0;

                                else if (*argument == '-') {
                                    // Initialization > (Argument (Length, Iterator), Character String (Length))
                                    const unsigned argumentLength = LDKF::characterStringLength(argument);
                                    unsigned argumentIterator = argumentLength - 1;
                                    const unsigned characterStringLength = (argumentLength - 1) + 1;
                                    char characterString[characterStringLength];

                                    // (Loop > )Update > ...
                                    *(characterString + characterStringLength - 1) = '\0';
                                    while (argumentIterator) { argumentIterator -= 1; *(characterString + argumentIterator) = *(argument + argumentIterator + 1); }

                                    // Return
                                    return -LDKF::toNumber(characterString);
                                }

                                else if (*argument == '.') {
                                    // Initialization > (Argument (Length, Iterator), Character String (Length))
                                    const unsigned argumentLength = LDKF::characterStringLength(argument);
                                    unsigned argumentIterator = argumentLength - 1;
                                    const unsigned characterStringLength = (argumentLength + 1);
                                    char characterString[argumentLength + 1];

                                    // Update > Character String
                                    *characterString = '0';
                                    *(characterString + 1) = '.';
                                    *(characterString + characterStringLength) = '\0';

                                    // Loop > Update > (Argument Iterator, Character String)
                                    while (argumentIterator) { argumentIterator -= 1; *(characterString + argumentIterator + 2) = *(argument + argumentIterator + 1); }

                                    // Return
                                    return LDKF::toNumber(characterString);
                                }

                                else if (
                                    (*(argument + 3) == '\0') &&
                                    (
                                        ((*argument == 'n' && *(argument + 1) == 'a' && *(argument + 2) == 'n')) ||
                                        ((*argument == 'N' && *(argument + 1) == 'a' && *(argument + 2) == 'N')) ||
                                        ((*argument == 'N' && *(argument + 1) == 'A' && *(argument + 2) == 'N'))
                                    )
                                )
                                    // Return
                                    return NaN;

                                else if (
                                    (*(argument + 8) == '\0') &&
                                    (
                                        ((*argument == 'i' && *(argument + 1) == 'n' && *(argument + 2) == 'f' && *(argument + 3) == 'i' && *(argument + 4) == 'n' && *(argument + 5) == 'i' && *(argument + 6) == 't' && *(argument + 7) == 'y')) ||
                                        ((*argument == 'I' && *(argument + 1) == 'n' && *(argument + 2) == 'f' && *(argument + 3) == 'i' && *(argument + 4) == 'n' && *(argument + 5) == 'i' && *(argument + 6) == 't' && *(argument + 7) == 'y')) ||
                                        ((*argument == 'I' && *(argument + 1) == 'N' && *(argument + 2) == 'F' && *(argument + 3) == 'I' && *(argument + 4) == 'N' && *(argument + 5) == 'I' && *(argument + 6) == 'T' && *(argument + 7) == 'Y'))
                                    )
                                )
                                    // Return
                                    return Infinity;

                                else if (LDKF::characterIsDigit(*argument)) {
                                    // Initialization > (Argument Length, Number)
                                    const unsigned argumentLength = LDKF::characterStringLength(argument);
                                    long double number = 0;

                                    // Logic
                                    if (argumentLength == 1)
                                        // Update > Number
                                        number = LDKF::toNumber(*argument, STRICT = false);

                                    else {
                                        // Initialization > (Argument Iterator, Number (Natural Base, Has Mantissa, Is Malformed, Is Scientific Notation))
                                        unsigned argumentIterator;
                                        minimal_numeric_type numberNaturalBase = 10;
                                        bool numberHasMantissa = false, numberIsMalformed = false, numberIsScientificNotation = false;

                                        // Logic
                                        if (*argument == '0') {
                                            // Logic > Update > Number Natural Base
                                            if (*(argument + 1) == 'b' || *(argument + 1) == 'B') numberNaturalBase = 2; // NOTE (Lapys) -> Binary.
                                            else if (*(argument + 1) == 'x' || *(argument + 1) == 'X') numberNaturalBase = 16; // NOTE (Lapys) -> Hexadecimal.
                                        }

                                        // Logic
                                        if (numberNaturalBase == 10) {
                                            // Update > Argument Iterator
                                            argumentIterator = argumentLength;

                                            // Loop
                                            while (argumentIterator && !numberIsMalformed) {
                                                // Initialization > Argument Character
                                                const char argumentCharacter = *(argument + (argumentIterator -= 1));

                                                // Update > Number Is Malformed
                                                numberIsMalformed = (argumentCharacter ^ '.') && ((argumentCharacter ^ 'e') && (argumentCharacter ^ 'E')) && LDKF::characterIsNonDigit(argumentCharacter);
                                            }
                                        }

                                        // Logic
                                        if (numberIsMalformed)
                                            // Update > Number
                                            number = NaN;

                                        else {
                                            // Update > Number (Has Mantissa, Is Scientific Notation)
                                            numberHasMantissa = LDKF::characterStringIncludes(argument, '.', argumentLength);
                                            numberIsScientificNotation = LDKF::characterStringIncludes(argument, 'e', argumentLength) || LDKF::characterStringIncludes(argument, 'E', argumentLength);

                                            // Logic
                                            switch (numberNaturalBase) {
                                                // [Binary]
                                                case 2:
                                                    // Update > Argument Iterator
                                                    argumentIterator = argumentLength;

                                                    // Loop
                                                    while ((argumentIterator ^ 2) && !numberIsMalformed) {
                                                        // Initialization > Argument Character
                                                        const char argumentCharacter = *(argument + (argumentIterator -= 1));

                                                        // Update > Number Is Malformed
                                                        numberIsMalformed = (argumentCharacter ^ '0') && (argumentCharacter ^ '1');
                                                    }

                                                    // Logic
                                                    if (numberIsMalformed)
                                                        // Update > Number
                                                        number = NAN;

                                                    else {
                                                        // Initialization > Argument Binary Segment (Length)
                                                        const unsigned argumentBinarySegmentLength = (argumentLength - 2) + 1;
                                                        char argumentBinarySegment[argumentBinarySegmentLength];

                                                        // Loop > Update > Argument (Binary Segment, Iterator)
                                                        while (argumentIterator ^ argumentLength) { *(argumentBinarySegment + (argumentIterator - 2)) = *(argument + argumentIterator); argumentIterator += 1; }

                                                        // Update > (Argument Binary Segment, Number)
                                                        *(argumentBinarySegment + argumentBinarySegmentLength) = '\0';
                                                        number = LDKF::characterStringBinaryToDecimal((const char*) argumentBinarySegment, argumentBinarySegmentLength);
                                                    }

                                                    // [Break]
                                                    break;

                                                // [Decimal]
                                                case 10: {
                                                    // Initialization > (Argument Character, Exponent)
                                                    char argumentCharacter;
                                                    long double exponent = 1;

                                                    // Update > Argument Iterator
                                                    argumentIterator = 0;

                                                    // Loop ---  NOTE (Lapys) -> Update Exponent based on the length of the characteristic segment of the Argument.
                                                    while (argumentIterator ^ argumentLength) {
                                                        // Update > Argument Character
                                                        argumentCharacter = *(argument + argumentIterator);

                                                        // Logic
                                                        if (argumentCharacter == '.' || (argumentCharacter == 'e' || argumentCharacter == 'E'))
                                                            // [Break]
                                                            break;

                                                        else {
                                                            // Update > (Argument Iterator, Exponent)
                                                            argumentIterator += 1; exponent = exponent == 1 ? 10 : exponent * 10;
                                                        }
                                                    }

                                                    // Update > (Argument Iterator, Exponent)
                                                    argumentIterator = 0; exponent /= 10;

                                                    // Loop --- NOTE (Lapys) -> Construct the characteristic portion of the Argument into the Number.
                                                    while (argumentIterator ^ argumentLength) {
                                                        // Update > Argument Character
                                                        argumentCharacter = *(argument + argumentIterator);

                                                        // Logic
                                                        if (argumentCharacter == '.' || (argumentCharacter == 'e' || argumentCharacter == 'E'))
                                                            // [Break]
                                                            break;

                                                        else {
                                                            // Update > (Argument Iterator, Number, Exponent)
                                                            argumentIterator += 1;
                                                            number += LDKF::toNumber(argumentCharacter, STRICT = false) * exponent;
                                                            exponent /= 10;
                                                        }
                                                    }

                                                    // Update > Number Is Malformed
                                                    numberIsMalformed = LDKF::characterIsNonDigit(argumentCharacter) && argumentIterator == argumentLength;

                                                    // Logic
                                                    if (!numberIsMalformed)
                                                        // Logic
                                                        if (argumentCharacter == '.' && argumentIterator == argumentLength)
                                                            // Update > Number Is Malformed
                                                            numberIsMalformed = true;

                                                        else {
                                                            // Logic --- NOTE (Lapys) -> Construct the mantissa.
                                                            if (numberHasMantissa) {
                                                                // Update > (Argument Iterator, Exponent)
                                                                argumentIterator += 1;
                                                                exponent = .1;

                                                                // Loop
                                                                while (argumentIterator ^ argumentLength) {
                                                                    // Update > Argument Character
                                                                    argumentCharacter = *(argument + argumentIterator);

                                                                    // Logic
                                                                    if (argumentCharacter == '.' || (argumentCharacter == 'e' || argumentCharacter == 'E'))
                                                                        // [Break]
                                                                        break;

                                                                    else {
                                                                        // Update > (Argument Iterator, Number, Exponent)
                                                                        argumentIterator += 1;
                                                                        number += LDKF::toNumber(argumentCharacter, STRICT = false) * exponent;
                                                                        exponent /= 10;
                                                                    }
                                                                }

                                                                // Update > Number Is Malformed
                                                                numberIsMalformed = argumentCharacter == '.' || ((argumentCharacter ^ 'e' && argumentCharacter ^ 'E') && LDKF::characterIsNonDigit(argumentCharacter)) || ((argumentCharacter == 'e' || argumentCharacter == 'E') && argumentIterator == argumentLength);
                                                            }

                                                            // Logic --- NOTE (Lapys) -> Update Number via the scientific notation format.
                                                            if (!numberIsMalformed && numberIsScientificNotation) {
                                                                // Update > Argument Iterator
                                                                argumentIterator += 1;

                                                                // Initialization > (Argument Exponent Segment) (Iterator, Length)
                                                                unsigned argumentExponentSegmentIterator = 0;
                                                                const unsigned argumentExponentSegmentLength = argumentLength - argumentIterator;
                                                                char argumentExponentSegment[argumentExponentSegmentLength + 1];

                                                                // Update > Argument Exponent Segment
                                                                *(argumentExponentSegment + argumentExponentSegmentLength) = '\0';

                                                                // Loop
                                                                while ((argumentIterator ^ argumentLength) && !numberIsMalformed) {
                                                                    // Update
                                                                        // Argument (Character, Iterator)
                                                                        argumentCharacter = *(argument + argumentIterator);
                                                                        argumentIterator += 1;

                                                                        // Argument Exponent Segment (Iterator), Number Is Malformed
                                                                        *(argumentExponentSegment + argumentExponentSegmentIterator) = argumentCharacter;
                                                                        argumentExponentSegmentIterator += 1;
                                                                        numberIsMalformed = LDKF::characterIsNonDigit(argumentCharacter);
                                                                }

                                                                // Logic --- NOTE (Lapys) -> Multiply the Exponent.
                                                                if (!numberIsMalformed) {
                                                                    // (Loop > )Update > ...
                                                                    exponent = LDKF::toNumber((const char*) argumentExponentSegment);
                                                                    while (exponent) { exponent -= 1; number *= 10; }
                                                                }
                                                            }
                                                        }

                                                    // Update > Number
                                                    numberIsMalformed && (number = NaN);

                                                    // [Break]
                                                    break;
                                                }

                                                // [Hexadecimal]
                                                case 16:
                                                    // Update > Argument Iterator
                                                    argumentIterator = argumentLength;

                                                    // Loop
                                                    while ((argumentIterator ^ 2) && !numberIsMalformed) {
                                                        // Initialization > Argument Character
                                                        char argumentCharacter = *(argument + (argumentIterator -= 1));

                                                        // Update > Number Is Malformed
                                                        numberIsMalformed = (argumentCharacter ^ '0') && (argumentCharacter ^ '1') && (argumentCharacter ^ '2') && (argumentCharacter ^ '3') && (argumentCharacter ^ '4') && (argumentCharacter ^ '5') && (argumentCharacter ^ '6') && (argumentCharacter ^ '7') && (argumentCharacter ^ '8') && (argumentCharacter ^ '9') && (argumentCharacter ^ 'a') && (argumentCharacter ^ 'A') && (argumentCharacter ^ 'b') && (argumentCharacter ^ 'B') && (argumentCharacter ^ 'c') && (argumentCharacter ^ 'C') && (argumentCharacter ^ 'd') && (argumentCharacter ^ 'D') && (argumentCharacter ^ 'e') && (argumentCharacter ^ 'E') && (argumentCharacter ^ 'f') && (argumentCharacter ^ 'F');
                                                    }

                                                    // Logic
                                                    if (numberIsMalformed)
                                                        // Update > Number
                                                        number = NAN;

                                                    else {
                                                        // Initialization > Argument Hexadecimal Segment (Length)
                                                        const unsigned argumentHexadecimalSegmentLength = (argumentLength - 2) + 1;
                                                        char argumentHexadecimalSegment[argumentHexadecimalSegmentLength];

                                                        // Loop > Update > Argument (Hexadecimal Segment, Iterator)
                                                        while (argumentIterator ^ argumentLength) { *(argumentHexadecimalSegment + (argumentIterator - 2)) = *(argument + argumentIterator); argumentIterator += 1; }

                                                        // Update > (Argument Hexadecimal Segment, Number)
                                                        *(argumentHexadecimalSegment + argumentHexadecimalSegmentLength) = '\0';
                                                        number = LDKF::characterStringHexadecimalToDecimal((const char*) argumentHexadecimalSegment, argumentHexadecimalSegmentLength);
                                                    }

                                                    // [Break]
                                                    break;

                                                // [Default]
                                                default:
                                                    // Update > Number
                                                    number = NaN;
                                            }
                                        }
                                    }

                                    // Return
                                    return number;
                                }

                                else
                                    // Return
                                    return NaN;
                            }
                            inline const long double toNumber(char* argument) { return LDKF::toNumber((const char*) argument); }
                            inline const unsigned short toNumber(const char16_t argument) { return argument; }
                            inline const unsigned int toNumber(const char32_t argument) { return argument; }
                            inline const double toNumber(const double argument) { return argument; }
                            inline const float toNumber(const float argument) { return argument; }
                            inline const int toNumber(const int argument) { return argument; }
                            inline const long toNumber(const long argument) { return argument; }
                            inline const long long toNumber(const long long argument) { return argument; }
                            inline const short toNumber(const short argument) { return argument; }
                            inline const signed char toNumber(const signed char argument) { return argument; }
                            inline const unsigned char toNumber(const unsigned char argument) { return argument; }
                            inline const unsigned int toNumber(const unsigned int argument) { return argument; }
                            inline const unsigned long toNumber(const unsigned long argument) { return argument; }
                            inline const unsigned long long toNumber(const unsigned long long argument) { return argument; }
                            inline const unsigned short toNumber(const unsigned short argument) { return argument; }
                            inline const pointer_numeric_type toNumber(const void* argument) { return (pointer_numeric_type) argument; }
                            inline const pointer_numeric_type toNumber(void* argument) { return LDKF::toNumber((const void*) argument); }
                            inline const wchar_t_numeric_type toNumber(const wchar_t argument) { return argument; }

                            // Wide Character
                            inline const wchar_t toWideCharacter(const char argument) { return argument; }
                            inline const wchar_t toWideCharacter(const char16_t argument) { return (wchar_t) argument; }
                            inline const wchar_t toWideCharacter(const char32_t argument) { return (wchar_t) argument; }
                            inline const char toWideCharacter(const double argument) { return argument; }
                            inline const char toWideCharacter(const float argument) { return argument; }
                            inline const char toWideCharacter(const int argument) { return argument; }
                            inline const char toWideCharacter(const long argument) { return argument; }
                            inline const char toWideCharacter(const long double argument) { return argument; }
                            inline const char toWideCharacter(const long long argument) { return argument; }
                            inline const char toWideCharacter(const short argument) { return argument; }
                            inline const char toWideCharacter(const signed char argument) { return argument; }
                            inline const char toWideCharacter(const unsigned char argument) { return argument; }
                            inline const char toWideCharacter(const unsigned int argument) { return argument; }
                            inline const char toWideCharacter(const unsigned long argument) { return argument; }
                            inline const char toWideCharacter(const unsigned long long argument) { return argument; }
                            inline const char toWideCharacter(const unsigned short argument) { return argument; }
                            const wchar_t toWideCharacter(const void* argument) { return LDKF::toNumber(argument); }
                            const wchar_t toWideCharacter(void* argument) { return LDKF::toWideCharacter((const void*) argument); }
                            inline const wchar_t toWideCharacter(const wchar_t argument) { return argument; }

                            // Character
                            inline const char toCharacter(const char argument) { return argument; }
                            inline const char toCharacter(const wchar_t argument) { return (char) argument; }
                            const char toCharacter(const char16_t argument) { return LDKF::toCharacter(LDKF::toWideCharacter(argument)); }
                            const char toCharacter(const char32_t argument) { return LDKF::toCharacter(LDKF::toWideCharacter(argument)); }
                            inline const char toCharacter(const double argument) { return argument; }
                            inline const char toCharacter(const float argument) { return argument; }
                            inline const char toCharacter(const int argument) { return argument; }
                            inline const char toCharacter(const long argument) { return argument; }
                            inline const char toCharacter(const long double argument) { return argument; }
                            inline const char toCharacter(const long long argument) { return argument; }
                            inline const char toCharacter(const short argument) { return argument; }
                            inline const char toCharacter(const signed char argument) { return argument; }
                            inline const char toCharacter(const unsigned char argument) { return argument; }
                            inline const char toCharacter(const unsigned int argument) { return argument; }
                            inline const char toCharacter(const unsigned long argument) { return argument; }
                            inline const char toCharacter(const unsigned long long argument) { return argument; }
                            inline const char toCharacter(const unsigned short argument) { return argument; }
                            const char toCharacter(const void* argument) { return LDKF::toNumber(argument); }
                            const char toCharacter(void* argument) { return LDKF::toCharacter((const void*) argument); }

                            // Character String
                            const char* toCharacterString(const char argument) { char *characterString = NULL; if (argument) { characterString = (char*) std::malloc(1 * sizeof(char)); *(characterString + 1) = '\0'; } else { characterString = (char*) std::malloc(1 * sizeof(char)); } *characterString = argument; return characterString; }
                            const char* toCharacterString(const char* argument) { return LDKF::characterStringClone(argument); }
                            const char* toCharacterString(char* argument) { return LDKF::toCharacterString((const char*) argument); }
                            const char* toCharacterString(const wchar_t argument) { return LDKF::toCharacterString(LDKF::toCharacter(argument)); }
                            const char* toCharacterString(const char16_t argument) { return LDKF::toCharacterString(LDKF::toCharacter((wchar_t) argument)); }
                            const char* toCharacterString(const char16_t* argument) {
                                // Initialization > (Argument (Length, Iterator), Character String)
                                const unsigned argumentLength = LDKF::utf16CharacterStringLength(argument);
                                unsigned argumentIterator = argumentLength;
                                char* characterString = (char*) std::malloc((argumentLength + 1) * sizeof(char));

                                // (Loop > )Update > ...
                                *(characterString + argumentLength) = '\0';
                                while (argumentIterator) { argumentIterator -= 1; *(characterString + argumentIterator) = LDKF::toCharacter(*(argument + argumentIterator)); }

                                // Return
                                return characterString;
                            }
                            const char* toCharacterString(char16_t* argument) { return LDKF::toCharacterString((const char16_t*) argument); }
                            const char* toCharacterString(const char32_t argument) { return LDKF::toCharacterString(LDKF::toCharacter((wchar_t) argument)); }
                            const char* toCharacterString(const char32_t* argument) {
                                // Initialization > (Argument (Length, Iterator), Character String)
                                const unsigned argumentLength = LDKF::utf32CharacterStringLength(argument);
                                unsigned argumentIterator = argumentLength;
                                char* characterString = (char*) std::malloc((argumentLength + 1) * sizeof(char));

                                // (Loop > )Update > ...
                                *(characterString + argumentLength) = '\0';
                                while (argumentIterator) { argumentIterator -= 1; *(characterString + argumentIterator) = LDKF::toCharacter(*(argument + argumentIterator)); }

                                // Return
                                return characterString;
                            }
                            const char* toCharacterString(char32_t* argument) { return LDKF::toCharacterString((const char32_t*) argument); }
                            const char* toCharacterString(const unsigned long long argument, const bool IS_SIGNED, const minimal_numeric_type CHARACTERISTICS_LENGTH) {
                                // Logic
                                if (argument) {
                                    // Initialization > Character String
                                    char* characterString = NULL;

                                    // Logic
                                    if (LDKF::numberIsInfinite(argument)) {
                                        // Update > Character String
                                        characterString = (char*) std::malloc(9 * sizeof(char));
                                        *characterString = 'I'; *(characterString + 1) = 'n'; *(characterString + 2) = 'f'; *(characterString + 3) = 'i'; *(characterString + 4) = 'n'; *(characterString + 5) = 'i'; *(characterString + 6) = 't'; *(characterString + 7) = 'y'; *(characterString + 8) = '\0';
                                    }

                                    else {
                                        // Initialization > (Character String (Length, Iterator), Number)
                                        const minimal_numeric_type characterStringLength = CHARACTERISTICS_LENGTH + IS_SIGNED;
                                        minimal_numeric_type characterStringIterator = characterStringLength;
                                        unsigned long long number = argument;

                                        // Update > Character String
                                        characterString = (char*) std::malloc((characterStringLength + 1) * sizeof(char));
                                        IS_SIGNED && (*characterString = '-');
                                        *(characterString + characterStringLength) = '\0';

                                        // Loop > Update > (Character String (Iterator), Number)
                                        while (characterStringIterator ^ IS_SIGNED) { characterStringIterator -= 1; *(characterString + characterStringIterator) = *(LDKC::String::digits + (number % 10)); number /= 10; }
                                    }

                                    // Return
                                    return characterString;
                                }

                                else
                                    // Return
                                    return LDKF::toCharacterString('0');
                            }
                            const char* toCharacterString(const unsigned long long argument, const bool IS_SIGNED) { return LDKF::toCharacterString(argument, IS_SIGNED, LDKF::numberCharacteristicsLength(argument)); }
                            const char* toCharacterString(const unsigned long long argument) { return LDKF::toCharacterString(argument, false, LDKF::numberCharacteristicsLength(argument)); }
                            const char* toCharacterString(const long long argument, const bool IS_SIGNED, const minimal_numeric_type CHARACTERISTICS_LENGTH) { return LDKF::toCharacterString((unsigned long long) (IS_SIGNED ? -argument : argument), IS_SIGNED, CHARACTERISTICS_LENGTH); }
                            const char* toCharacterString(const long long argument, const bool IS_SIGNED) { const unsigned long long argumentAbsolute = (unsigned long long) (IS_SIGNED ? -argument : argument); return LDKF::toCharacterString(argumentAbsolute, IS_SIGNED, LDKF::numberCharacteristicsLength(argumentAbsolute)); }
                            const char* toCharacterString(const long long argument) { const unsigned long long argumentAbsolute = LDKM::abs(argument); return LDKF::toCharacterString(argumentAbsolute, argument ^ argumentAbsolute, LDKF::numberCharacteristicsLength(argumentAbsolute)); }
                            const char* toCharacterString(const int argument) { return LDKF::toCharacterString((long long) argument); }
                            const char* toCharacterString(const long argument) { return LDKF::toCharacterString((long long) argument); }
                            const char* toCharacterString(const short argument) { return LDKF::toCharacterString((long long) argument); }
                            const char* toCharacterString(const signed char argument) { return LDKF::toCharacterString(LDKF::toCharacter(argument)); }
                            const char* toCharacterString(const signed char* argument) {
                                // Initialization > (Argument (Length, Iterator), Character String)
                                const unsigned argumentLength = LDKF::signedCharacterStringLength(argument);
                                unsigned argumentIterator = argumentLength;
                                char* characterString = (char*) std::malloc((argumentLength + 1) * sizeof(char));

                                // (Loop > )Update > ...
                                *(characterString + argumentLength) = '\0';
                                while (argumentIterator) { argumentIterator -= 1; *(characterString + argumentIterator) = LDKF::toCharacter(*(argument + argumentIterator)); }

                                // Return
                                return characterString;
                            }
                            const char* toCharacterString(signed char* argument) { return LDKF::toCharacterString((const signed char*) argument); }
                            const char* toCharacterString(const unsigned char argument) { return LDKF::toCharacterString(LDKF::toCharacter(argument)); }
                            const char* toCharacterString(const unsigned char* argument) {
                                // Initialization > (Argument (Length, Iterator), Character String)
                                const unsigned argumentLength = LDKF::unsignedCharacterStringLength(argument);
                                unsigned argumentIterator = argumentLength;
                                char* characterString = (char*) std::malloc((argumentLength + 1) * sizeof(char));

                                // (Loop > )Update > ...
                                *(characterString + argumentLength) = '\0';
                                while (argumentIterator) { argumentIterator -= 1; *(characterString + argumentIterator) = LDKF::toCharacter(*(argument + argumentIterator)); }

                                // Return
                                return characterString;
                            }
                            const char* toCharacterString(unsigned char* argument) { return LDKF::toCharacterString((const unsigned char*) argument); }
                            const char* toCharacterString(const unsigned int argument) { return LDKF::toCharacterString((unsigned long long) argument); }
                            const char* toCharacterString(const unsigned long argument) { return LDKF::toCharacterString((unsigned long long) argument); }
                            const char* toCharacterString(const unsigned short argument) { return LDKF::toCharacterString((unsigned long long) argument); }
                            const char* toCharacterString(const long double argument) {
                                // Initialization > Character String
                                char *characterString = NULL;

                                // Logic
                                if (LDKF::numberIsInfinite(argument)) {
                                    // Update > Character String
                                    characterString = (char*) std::malloc(9 * sizeof(char));
                                    *characterString = 'I'; *(characterString + 1) = 'n'; *(characterString + 2) = 'f'; *(characterString + 3) = 'i'; *(characterString + 4) = 'n'; *(characterString + 5) = 'i'; *(characterString + 6) = 't'; *(characterString + 7) = 'y'; *(characterString + 8) = '\0';
                                }

                                else if (LDKF::numberIsNaN(argument)) {
                                    // Update > Character String
                                    characterString = (char*) std::malloc(4 * sizeof(char));
                                    *characterString = 'N'; *(characterString + 1) = 'a'; *(characterString + 2) = 'N'; *(characterString + 3) = '\0';
                                }

                                else {
                                    // Initialization > Argument ((Characteristics, Mantissa) Length, Is Signed)
                                    const minimal_numeric_type argumentCharacteristicsLength = LDKF::numberCharacteristicsLength(argument);
                                    minimal_numeric_type argumentMantissaLength = LDKF::numberMantissaLength(argument);
                                    const bool argumentIsSigned = LDKF::numberIsNegative(argument);

                                    // Update > Character String
                                    characterString = (char*) LDKF::toCharacterString((const long long) argument, argumentIsSigned, argumentCharacteristicsLength);

                                    // Logic
                                    if (argumentMantissaLength) {
                                        // Update > Argument Mantissa Length
                                        (argumentMantissaLength > LDKC::Number::significantDigits) && (argumentMantissaLength = LDKC::Number::significantDigits);

                                        // Initialization > (Character String (Length, Iterator), Number)
                                        const minimal_numeric_type characterStringLength = (argumentCharacteristicsLength + 1 /* NOTE (Lapys) -> The length of the decimal point. */ + argumentMantissaLength) + argumentIsSigned;
                                        minimal_numeric_type characterStringIterator = argumentMantissaLength + 1 /* NOTE (Lapys) -> The length of the decimal point. */ + argumentIsSigned;
                                        long double number = argument;

                                        // Update > Character String
                                        characterString = (char*) std::realloc(characterString, (characterStringLength + 1) * sizeof(char));
                                        *(characterString + argumentCharacteristicsLength + argumentIsSigned) = '.';

                                        // Loop
                                        do {
                                            // Update > Character String
                                            *(characterString + (characterStringLength - (characterStringIterator -= 1))) =
                                            *(LDKC::String::digits + LDKM::abs(LDKF::numberToInteger(number *= 10) % 10));
                                        } while (characterStringIterator);

                                        // Update > Character String (Iterator)
                                        *(characterString + characterStringLength) = '\0';
                                        characterStringIterator = characterStringLength;

                                        // Loop --- NOTE (Lapys) -> Remove trailing zeros.
                                        while (characterStringIterator) {
                                            // Initialization > Previous Character
                                            const char previousCharacter = *(characterString + ((characterStringIterator -= 1) - 1));

                                            // Logic
                                            if (previousCharacter ^ '0') {
                                                // Update > Character String (Iterator)
                                                (previousCharacter == '.') && (characterStringIterator -= 1);
                                                characterString = (char*) std::realloc(characterString, (characterStringIterator + 1) * sizeof(char));
                                                *(characterString + characterStringIterator) = '\0';
                                                characterStringIterator = 0;
                                            }
                                        }
                                    }
                                }

                                // Return
                                return characterString;
                            }
                            const char* toCharacterString(const double argument) { return LDKF::toCharacterString((long double) argument); }
                            const char* toCharacterString(const float argument) { return LDKF::toCharacterString((long double) argument); }
                            const char* toCharacterString(const void* argument) {
                                // Initialization > Character String
                                char* characterString = (char*) std::malloc(sizeof(char));

                                // Logic
                                if (LDKF::pointerIsNull(argument)) {
                                    // Update > Character String
                                    characterString = (char*) std::realloc(characterString, 5 * sizeof(char));
                                    *characterString = 'n'; *(characterString + 1) = 'u'; *(characterString + 2) = *(characterString + 3) = 'l'; *(characterString + 4) = '\0';
                                }

                                else {
                                    // Initialization > (Argument Number, Character String Iterator) --- NOTE (Lapys) -> Convert the pointer Argument to a numeral.
                                    pointer_numeric_type argumentNumber = LDKF::toNumber(argument);
                                    minimal_numeric_type characterStringIterator = 0;

                                    // Loop
                                    while (argumentNumber) {
                                        // Initialization > Remainder
                                        pointer_numeric_type remainder = argumentNumber % 16;

                                        // Update
                                            // Argument Number, Character String Iterator
                                            argumentNumber /= 16;
                                            characterStringIterator += 1;

                                            // Character String
                                            characterString = (char*) std::realloc(characterString, (characterStringIterator + 1) * sizeof(char));
                                            *(characterString + (characterStringIterator - 1)) = remainder + (remainder < 10 ? 48 : 55);
                                    }

                                    // Initialization > Character String Length
                                    const minimal_numeric_type characterStringLength = characterStringIterator + 2;

                                    // Update > Character String
                                    characterString = (char*) std::realloc(characterString, (characterStringLength + 1) * sizeof(char));

                                    // Update > Character String Iterator; Loop --- NOTE (Lapys) -> Reverse the characters already parsed in the Character String.
                                    characterStringIterator /= 2;
                                    while (characterStringIterator) {
                                        // Initialization > Character (String Index)
                                        const char character = characterString[characterStringIterator -= 1];
                                        const minimal_numeric_type characterStringIndex = (characterStringLength - 2) - characterStringIterator - 1;

                                        // Update > Character String
                                        *(characterString + characterStringIterator) ^= *(characterString + characterStringIndex);
                                        *(characterString + characterStringIndex) ^= *(characterString + characterStringIterator);
                                        *(characterString + characterStringIterator) ^= *(characterString + characterStringIndex);
                                    }

                                    // Update > Character String Iterator; Loop > Update > Character String --- NOTE (Lapys) -> Shift all parsed characters 2 spaces forward.
                                    characterStringIterator = characterStringLength + 2;
                                    while (characterStringIterator ^ 2) *(characterString + (characterStringIterator -= 1)) = *(characterString + (characterStringIterator - 2));

                                    // Update > Character String
                                    *characterString = '0'; *(characterString + 1) = 'x';
                                    *(characterString + characterStringLength) = '\0';
                                }

                                // Return
                                return characterString;
                            }
                            const char* toCharacterString(void* argument) { return LDKF::toCharacterString((const void*) argument); }
                            const char* toCharacterString(const wchar_t* argument) {
                                // Initialization > (Argument (Length, Iterator), Character String)
                                const unsigned argumentLength = LDKF::wideCharacterStringLength(argument);
                                unsigned argumentIterator = argumentLength;
                                char* characterString = (char*) std::malloc((argumentLength + 1) * sizeof(char));

                                // (Loop > )Update > ...
                                *(characterString + argumentLength) = '\0';
                                while (argumentIterator) { argumentIterator -= 1; *(characterString + argumentIterator) = LDKF::toCharacter(*(argument + argumentIterator)); }

                                // Return
                                return characterString;
                            }
                            const char* toCharacterString(wchar_t* argument) { return LDKF::toCharacterString((const wchar_t*) argument); }
                            template <typename type> const char* toCharacterString(type& argument) { return argument.toString(); }

                    // Array
                        // Join
                        template <typename type>
                        const char* arrayJoin(type* array, const char* separator, const unsigned arrayLength, const unsigned separatorLength) {
                            // Initialization > (Array (Character String (Length), Iterator), Character String Length)
                            char* arrayCharacterString[arrayLength];
                            unsigned arrayIterator, arrayCharacterStringLength[arrayLength],
                                characterStringLength = 0u;

                            // Update > Array Iterator
                            arrayIterator = arrayLength;

                            // Loop --- NOTE (Lapys) -> Cache the string content of the Array and determine the length of the Character String returned.
                            while (arrayIterator) {
                                // Initialization > Element Character String (Length)
                                char* elementCharacterString = (char*) LDKF::toCharacterString(*(array + (arrayIterator -= 1)));
                                const unsigned elementCharacterStringLength = LDKF::characterStringLength(elementCharacterString);

                                // Update > (Array Character String (Length), Character String Length)
                                *(arrayCharacterString + arrayIterator) = elementCharacterString;
                                *(arrayCharacterStringLength + arrayIterator) = elementCharacterStringLength;
                                characterStringLength += elementCharacterStringLength;
                                arrayIterator && (characterStringLength += separatorLength);
                            }

                            // Initialization > Character String (Iterator)
                            char* characterString = (char*) std::malloc((characterStringLength + 1) * sizeof(char));
                            unsigned characterStringIterator = 0u;

                            // Update > Character String
                            *(characterString + characterStringLength) = '\0';

                            // Update > Array Iterator
                            arrayIterator = arrayLength;

                            // Loop --- NOTE (Lapys) -> Iterate through the Array string content cache and populate the Character String.
                            while (arrayIterator) {
                                // Update > Array Iterator
                                arrayIterator -= 1;

                                // Initialization > (Element Character String) (Length, Iterator)
                                const char* elementCharacterString = (const char*) *(arrayCharacterString + (arrayLength - arrayIterator - 1));
                                const unsigned elementCharacterStringLength = *(arrayCharacterStringLength + (arrayLength - arrayIterator - 1));
                                unsigned elementCharacterStringIterator = elementCharacterStringLength;

                                // Loop > Update > Character String (Iterator)
                                while (elementCharacterStringIterator) { *(characterString + characterStringIterator) = *(elementCharacterString + (elementCharacterStringLength - (elementCharacterStringIterator -= 1) - 1)); characterStringIterator += 1; }

                                // Deletion
                                std::free((char*) elementCharacterString);

                                // Logic --- NOTE (Lapys) -> Delimit with the Separator.
                                if (arrayIterator) {
                                    // Initialization > Separator Iterator
                                    unsigned separatorIterator = separatorLength;

                                    // Loop > Update > Character String (Iterator)
                                    while (separatorIterator) { *(characterString + characterStringIterator) = *(separator + (separatorLength - (separatorIterator -= 1) - 1)); characterStringIterator += 1; }
                                }
                            }

                            // Return
                            return characterString;
                        }

                        template <typename type> const char* arrayJoin(type* array, const char* separator, const unsigned arrayLength) { return LDKF::arrayJoin(array, separator, LDKF::characterStringLength(separator)); }
                        template <typename type> const char* arrayJoin(type* array, char* separator, const unsigned arrayLength, const unsigned separatorLength) { return LDKF::arrayJoin(array, (const char*) separator, separatorLength); }
                        template <typename type> const char* arrayJoin(type* array, char* separator, const unsigned arrayLength) { return LDKF::arrayJoin(array, (const char*) separator, LDKF::characterStringLength(separator)); }
                }

                /* Mathematics */
                inline namespace Mathematics {}

                /* Objects */
                inline namespace Objects {
                    /* Definition > ... */
                    class Array;
                    class Boolean;
                    class Character;
                    class Function;
                    class Number;
                    class Object;
                    class String;
                    class Symbol;
                    struct var;

                    /* Class */
                        /* Lapys C++ Exception */
                        class LapysCppException : public std::exception {
                            // [Private]
                            private:
                                // Constant > Message
                                const char* message = NULL;

                            // [Public]
                            public:
                                // [Constructor]
                                inline LapysCppException() : message(LDKF::characterStringClone("")) {}
                                inline LapysCppException(const char* message) : message(LDKF::characterStringConcatenate("LapysC++Exception: ", message, 19u)) {}

                                // [Destructor]
                                inline ~LapysCppException() { std::free((char*) this -> message); }

                                // Function > What
                                inline virtual const char* what() const throw() { return this -> message; }
                        };
                            // Input Exception
                            class InputException : public LapysCppException {};
                                // Invalid Input Exception
                                class InvalidInputException : public InputException { public: inline virtual const char* what() const throw() { return "InvalidInputException: The input given is invalid; Could not resolve input string to variable type"; } };

                                // Null Input Exception
                                class NullInputException : public InputException { public: inline virtual const char* what() const throw() { return "NullInputException: Input required and ignored."; } };

                        // Array --- CHECKPOINT (Lapys) --- NOTE (Lapys) -> Probably not smart to name the constructor `array` when there`s a pre-existing `Array` class.
                        template <typename structType>
                        struct array {
                            // [Private]
                            private:
                                // Initialization > (Has Requested Invalid Index, Is Batch Processing, Value)
                                bool hasRequestedInvalidIndex = false, isBatchProcessing = false;
                                structType** value = NULL;

                                // Function
                                    // Allocate --- WARN (Lapys) -> Only allocates memory for the main Value, not it`s elements.
                                    void allocate(const unsigned length, const unsigned size) {
                                        // Initialization > (Index, Iterator)
                                        unsigned index = this -> length, iterator = length;

                                        // Modification > Target > (Size, Value)
                                        this -> size += length * size;
                                        this -> value = (structType**) std::realloc(this -> value, this -> size);

                                        // Loop > ... --- NOTE (Lapys) -> Prevent the elements in Value from being wild pointers.
                                        while (iterator) { *((this -> value) + index) = NULL; index += 1; iterator -= 1; }
                                    }
                                    void allocate(const unsigned length) { this -> allocate(length, sizeof(structType*)); }
                                    void allocate() { this -> allocate(1u); }

                                    // Arguments To Array
                                    inline void argumentsToArray(structType& argumentList, const unsigned& length) {}
                                    template <typename type>
                                    void argumentsToArray(structType*& argumentList, unsigned& length, structType& element) {
                                        // Update > Argument List
                                        argumentList = (structType*) std::realloc(argumentList, (length += 1) * sizeof(structType));
                                        *(argumentList + (length - 1)) = element;
                                    }
                                    template <typename type>
                                    void argumentsToArray(structType*& argumentList, unsigned& length, type& element) {
                                        // Update > Argument List
                                        argumentList = (structType*) std::realloc(argumentList, (length += 1) * sizeof(structType));
                                        *(argumentList + (length - 1)) = element;
                                    }
                                    template <typename type, typename... types>
                                    void argumentsToArray(structType*& argumentList, unsigned& length, type& element, types&... elements) {
                                        // Target > Arguments To Array
                                        this -> argumentsToArray(argumentList, length, element);
                                        this -> argumentsToArray(argumentList, length, elements...);
                                    }

                                    // Concatenate
                                    array& concatenate(structType*& array, const unsigned length) {
                                        // Initialization > Iterator
                                        unsigned iterator = length;

                                        // Modification > Target > Is Batch Processing
                                        this -> isBatchProcessing = true;

                                        // Modification > Target > Allocate
                                        this -> allocate(length);

                                        // Loop > Target > Add To Front
                                        while (iterator) this -> addToFront(*(array + (length - (iterator -= 1u) - 1u)));

                                        // Modification > Target > Is Batch Processing
                                        this -> isBatchProcessing = false;
                                    }

                                    // Set Elements From --- NOTE (Lapys) -> Set elements of the array from a specified index.
                                    inline void setElementsFrom() {}
                                    inline void setElementsFrom(unsigned& index, structType& element) { if (index ^ this -> length) { this -> setIndex(index, element, STRICT = false); index += 1; } }
                                    template <typename type> inline void setElementsFrom(unsigned& index, type argument) { structType element(argument); this -> setElementsFrom(index, element); }
                                    template <typename... structTypes> void setElementsFrom(unsigned& index, structType& element, structTypes&... elements) { this -> setElementsFrom(index, element); this -> setElementsFrom(index, elements...); }

                                    // Set Index
                                    void setIndex(const unsigned index, structType& element, const bool ALLOCATE_NEW_MEMORY_ON_HEAP = false) { ALLOCATE_NEW_MEMORY_ON_HEAP && (*((this -> value) + index) = (structType*) std::malloc(sizeof(element))); **((this -> value) + index) = element; }

                            // [Protected]
                            protected:
                                // Initialization > Size
                                unsigned size = 1u;

                                /* Phase > Terminate */
                                void terminate() {
                                    // Initialization > Iterator
                                    unsigned iterator = this -> length;

                                    // (Loop > )Deletion
                                    while (iterator) std::free(*((this -> value) + (iterator -= 1)));
                                    std::free(this -> value);
                                }

                            // [Public]
                            public:
                                // [Constructor]
                                array() { this -> free(); }
                                array(structType& element) { this -> free(); this -> addToFront(element); }
                                template <typename type> array(type element) { this -> free(); this -> addToFront(element); }
                                template <typename... types>
                                array(types... elements) {
                                    // Initialization > (Array, Length)
                                    structType* array = (structType*) std::malloc(1u); unsigned length = 0u;

                                    // Target > (Free, Arguments To Array, Concatenate)
                                    this -> free();
                                    this -> argumentsToArray(array, length, elements...);
                                    this -> concatenate(array, length);

                                    // Deletion
                                    std::free(array);
                                }
                                template <typename... structTypes>
                                array(structType& element, structTypes&... elements) {
                                    // Initialization > (Array, Length)
                                    structType* array = (structType*) std::malloc(1u); unsigned length = 0u;

                                    // Target > (Free, Arguments To Array)
                                    this -> free();
                                    this -> argumentsToArray(array, length, element, elements...);

                                    // Initialization > Iterator
                                    unsigned iterator = length;

                                    // Loop > Target > Add To Front
                                    while (iterator) this -> addToFront(*(array + (length - (iterator -= 1) - 1)));

                                    // Deletion
                                    std::free(array);
                                }

                                // [Destructor]
                                ~array() { this -> terminate(); }

                                // [Operator] > ...
                                structType& operator [](const unsigned index) { return this -> elementAt(index); }

                                // Initialization > Length
                                unsigned length = 0u;

                                // Function
                                    // Add
                                    inline array& add() { return *this; }
                                    array& add(structType& element) { return this -> addToFront(element); }
                                    template <typename type> array& add(type element) { return this -> addToFront(element); }
                                    template <typename... structTypes> array& add(structType& element, structTypes&... elements) { return this -> addToFront(element, elements...); }
                                    template <typename... types> array& add(types... elements) { return this -> addToFront(elements...); }

                                    // Add To Back
                                    inline array& addToBack() { return *this; }
                                    array& addToBack(structType& element) {
                                        // Initialization > Iterator
                                        unsigned iterator = this -> length;

                                        // Logic > Target > Allocate
                                        if (!(this -> isBatchProcessing)) this -> allocate();

                                        // Loop > ... --- NOTE (Lapys) -> Shift the array forward by 1 unit.
                                        while (iterator) { iterator -= 1; this -> setIndex(iterator + 1, **((this -> value) + iterator), STRICT = (this -> length - iterator) <= length); }

                                        // Modification > Target > (Length, Value)
                                        this -> length += 1; **(this -> value) = element;

                                        // Return
                                        return *this;
                                    }
                                    template <typename type> array& addToBack(type argument) { structType element(argument); this -> addToBack(element); return *this; }
                                    template <typename... structTypes>
                                    array& addToBack(structType& element, structTypes&... elements) {
                                        // Initialization > Index
                                        unsigned index = 0u;
                                        const unsigned length = LDKF::getArgumentsLength(element, elements...);
                                        unsigned iterator = this -> length;

                                        // Target > Allocate
                                        this -> allocate(length);

                                        // Loop > ...
                                        while (iterator) { iterator -= 1; this -> setIndex(iterator + length, **((this -> value) + iterator), STRICT = (this -> length - iterator) <= length); }

                                        // Target > Set Elements From
                                        this -> setElementsFrom(index, element, elements...);

                                        // Modification > Target > Length
                                        this -> length += length;

                                        // Return
                                        return *this;
                                    }
                                    template <typename type, typename... types> array& addToBack(type argument, types... elements) { structType element(argument); this -> addToBack(element, elements...); return *this; }

                                    // Add To Front
                                    inline array& addToFront() { return *this; }
                                    array& addToFront(structType& element) {
                                        // Logic > Target > Allocate
                                        if (!(this -> isBatchProcessing)) this -> allocate();

                                        // Target > Set Index
                                        this -> setIndex(this -> length, element, STRICT = true);

                                        // Modification > Target > Length
                                        this -> length += 1;

                                        // Return
                                        return *this;
                                    }
                                    template <typename type> array& addToFront(type argument) { structType element(argument); this -> addToFront(element); return *this; }
                                    template <typename... structTypes>
                                    array& addToFront(structType& element, structTypes&... elements) {
                                        // Logic --- NOTE (Lapys) -> Allocate memory space in bulk.
                                        if (!(this -> isBatchProcessing)) {
                                            // Target > Allocate; Modification > Target > Is Batch Processing
                                            this -> allocate(LDKF::getArgumentsLength(element, elements...));
                                            this -> isBatchProcessing = true;
                                        }

                                        // Target > Add To Front
                                        this -> addToFront(element); this -> addToFront(elements...);

                                        // Modification > Target > Is Batch Processing
                                        this -> isBatchProcessing = false;

                                        // Return
                                        return *this;
                                    }
                                    template <typename type, typename... types> array& addToFront(type argument, types... elements) { structType element(argument); this -> addToFront(element, elements...); return *this; }

                                    // Concatenate --- WARN (Lapys) -> Only concatenates to the front of the array.
                                    inline array& concatenate() { return *this; }
                                    array& concatenate(array<structType>& concatenationArray) {
                                        // Initialization > Concatenation Array (Length, Iterator)
                                        const unsigned concatenationArrayLength = concatenationArray.length;
                                        unsigned concatenationArrayIterator = concatenationArrayLength, index = 0u;

                                        // Target > Allocate
                                        this -> allocate(concatenationArrayLength);

                                        // Loop > Target > Set Index
                                        while (concatenationArrayIterator) this -> setIndex((this -> length) + (index += 1u) - 1u, concatenationArray.elementAt(concatenationArrayLength - (concatenationArrayIterator -= 1u) - 1u), STRICT = true);

                                        // Modification > Target > Length
                                        this -> length += index;

                                        // Return
                                        return *this;
                                    }
                                    template <typename... structTypes> array& concatenate(array<structType>& concatenationArray, structTypes&... concatenationArrays) { this -> concatenate(concatenationArray); this -> concatenationArray(concatenationArrays...); return *this; }

                                    // Cut At --- CHECKPOINT (Lapys)

                                    // Element At
                                    inline structType& elementAt(const unsigned index) {
                                        // Logic
                                        if (index == (this -> length) || index > (this -> length)) {
                                            // Initialization > Undefined
                                            structType undefined;

                                            // Target > Allocate
                                            this -> allocate(index - (this -> length));

                                            // Modification > Target > Value
                                            *((this -> value) + index) = (structType*) std::malloc(sizeof(structType));
                                            **((this -> value) + index) = undefined;
                                        }

                                        // Return
                                        return **((this -> value) + index);
                                    }

                                    // Free
                                    array& free() {
                                        // Target > Terminate
                                        this -> terminate();

                                        // Modification > Target > ...
                                        this -> isBatchProcessing = false;
                                        this -> length = 0u;
                                        this -> size = 1u;
                                        this -> value = (structType**) std::malloc(this -> size);

                                        // Return
                                        return *this;
                                    }

                                    // Includes --- CHECKPOINT (Lapys)

                                    // Index --- CHECKPOINT (Lapys)
                                    // Index From --- CHECKPOINT (Lapys)
                                    // Index From Back --- CHECKPOINT (Lapys)
                                    // Index From Front --- CHECKPOINT (Lapys)

                                    // Remove --- CHECKPOINT (Lapys)
                                    // Remove All --- CHECKPOINT (Lapys)
                                    // Remove From --- CHECKPOINT (Lapys)
                                    // Remove From Back --- CHECKPOINT (Lapys)
                                    // Remove From Front --- CHECKPOINT (Lapys)

                                    // Request Size
                                    const unsigned requestSize() const { return this -> size; }

                                    // Resize --- CHECKPOINT (Lapys)

                                    // Shift Left --- CHECKPOINT (Lapys)
                                    // Shift Right --- CHECKPOINT (Lapys)

                                    // To String
                                    const char* toString() {
                                        // Initialization > Character String (Body)
                                        char* characterString = NULL;
                                        structType* pointer = this -> valueOf();
                                        const char* characterStringBody = LDKF::arrayJoin(pointer, ", ", this -> length, 2u);

                                        // Update > Character String
                                        LDKF::characterStringSourceConcatenate(characterString, '[');
                                        LDKF::characterStringSourceConcatenate(characterString, characterStringBody);
                                        LDKF::characterStringSourceConcatenate(characterString, ']');

                                        LDKF::characterStringAllocateOnHeap(characterString);

                                        // Deletion
                                        std::free((char*) characterStringBody);
                                        std::free(pointer);

                                        // Return
                                        return characterString;
                                    }

                                    // Value Of --- UPDATE REQUIRED (Lapys) -> Fix lossy conversion.
                                    structType* valueOf() {
                                        // Initialization > (Array, Iterator)
                                        structType* array = (structType*) std::malloc(this -> length * sizeof(structType));
                                        unsigned iterator;

                                        // Loop > Update > (Iterator, Array)
                                        iterator = this -> length;
                                        while (iterator) { iterator -= 1; *(array + iterator) = **((this -> value) + iterator); }

                                        iterator = this -> length;
                                        while (iterator) { iterator -= 1; *(array + iterator) = **((this -> value) + iterator); }

                                        // Return
                                        return array;
                                    }
                        };

                        // Let --- NOTE (Lapys) -> Wrapper for all primitive types (e.g.: `char`, `float`, `int`, e.t.c.).
                        struct let {
                            // [Private]
                            private:
                                // Initialization > (Type, Value)
                                enum {characterType, decimalType, signedIntegerType, undefinedType, unsignedIntegerType} type;
                                struct value {
                                    // [Public]
                                    public:
                                        // [Destructor]
                                        ~value() { std::free(this -> decimal); std::free(this -> integer); }

                                        // Initialization > (Decimal, Integer)
                                        long double* decimal = NULL;
                                        long long* integer = NULL;
                                } value;

                            // [Protected]
                            protected:
                                /* Phase > (Terminate, Update) */
                                inline void terminate() { this -> type = this -> undefinedType; std::free(this -> value.decimal); this -> value.decimal = NULL; std::free(this -> value.integer); this -> value.integer = NULL; }
                                void update(const char argument) { const long long value = argument; this -> type = this -> characterType; std::free(this -> value.decimal); this -> value.decimal = NULL; this -> value.integer = (long long*) std::malloc(sizeof(value)); *(this -> value.integer) = argument; }
                                void update(const char16_t argument) { const long long value = argument; this -> type = this -> characterType; std::free(this -> value.decimal); this -> value.decimal = NULL; this -> value.integer = (long long*) std::malloc(sizeof(value)); *(this -> value.integer) = argument; }
                                void update(const char32_t argument) { const long long value = argument; this -> type = this -> characterType; std::free(this -> value.decimal); this -> value.decimal = NULL; this -> value.integer = (long long*) std::malloc(sizeof(value)); *(this -> value.integer) = argument; }
                                void update(const double argument) { const long double value = argument; this -> type = this -> decimalType; this -> value.decimal = (long double*) std::malloc(sizeof(value)); *(this -> value.decimal) = argument; std::free(this -> value.integer); this -> value.integer = NULL; }
                                void update(const float argument) { const long double value = argument; this -> type = this -> decimalType; this -> value.decimal = (long double*) std::malloc(sizeof(value)); *(this -> value.decimal) = argument; std::free(this -> value.integer); this -> value.integer = NULL; }
                                void update(const int argument) { const long long value = argument; this -> type = this -> signedIntegerType; std::free(this -> value.decimal); this -> value.decimal = NULL; this -> value.integer = (long long*) std::malloc(sizeof(value)); *(this -> value.integer) = argument; }
                                void update(const long argument) { const long long value = argument; this -> type = this -> signedIntegerType; std::free(this -> value.decimal); this -> value.decimal = NULL; this -> value.integer = (long long*) std::malloc(sizeof(value)); *(this -> value.integer) = argument; }
                                void update(const long double argument) { const long double value = argument; this -> type = this -> decimalType; this -> value.decimal = (long double*) std::malloc(sizeof(value)); *(this -> value.decimal) = argument; std::free(this -> value.integer); this -> value.integer = NULL; }
                                void update(const long long argument) { const long long value = argument; this -> type = this -> signedIntegerType; std::free(this -> value.decimal); this -> value.decimal = NULL; this -> value.integer = (long long*) std::malloc(sizeof(value)); *(this -> value.integer) = argument; }
                                void update(const short argument) { const long long value = argument; this -> type = this -> signedIntegerType; std::free(this -> value.decimal); this -> value.decimal = NULL; this -> value.integer = (long long*) std::malloc(sizeof(value)); *(this -> value.integer) = argument; }
                                void update(const signed char argument) { const long long value = argument; this -> type = this -> signedIntegerType; std::free(this -> value.decimal); this -> value.decimal = NULL; this -> value.integer = (long long*) std::malloc(sizeof(value)); *(this -> value.integer) = argument; }
                                void update(const unsigned char argument) { const long long value = argument; this -> type = this -> unsignedIntegerType; std::free(this -> value.decimal); this -> value.decimal = NULL; this -> value.integer = (long long*) std::malloc(sizeof(value)); *(this -> value.integer) = argument; }
                                void update(const unsigned int argument) { const long long value = argument; this -> type = this -> unsignedIntegerType; std::free(this -> value.decimal); this -> value.decimal = NULL; this -> value.integer = (long long*) std::malloc(sizeof(value)); *(this -> value.integer) = argument; }
                                void update(const unsigned long argument) { const long long value = argument; this -> type = this -> unsignedIntegerType; std::free(this -> value.decimal); this -> value.decimal = NULL; this -> value.integer = (long long*) std::malloc(sizeof(value)); *(this -> value.integer) = argument; }
                                void update(const unsigned long long argument) { const long long value = argument; this -> type = this -> unsignedIntegerType; std::free(this -> value.decimal); this -> value.decimal = NULL; this -> value.integer = (long long*) std::malloc(sizeof(value)); *(this -> value.integer) = argument; }
                                void update(const unsigned short argument) { const long long value = argument; this -> type = this -> unsignedIntegerType; std::free(this -> value.decimal); this -> value.decimal = NULL; this -> value.integer = (long long*) std::malloc(sizeof(value)); *(this -> value.integer) = argument; }
                                void update(const wchar_t argument) { const long long value = argument; this -> type = this -> characterType; std::free(this -> value.decimal); this -> value.decimal = NULL; this -> value.integer = (long long*) std::malloc(sizeof(value)); *(this -> value.integer) = argument; }
                                void update(const LDKO::let& argument) {
                                    // Logic > Target > Update
                                    switch (argument.type) {
                                        case argument.characterType: this -> type = this -> characterType; std::free(this -> value.decimal); this -> value.decimal = NULL; this -> value.integer = (long long*) std::malloc(sizeof(*(argument.value.integer))); *(this -> value.integer) = *(argument.value.integer); break;
                                        case argument.decimalType: this -> type = this -> decimalType; this -> value.decimal = (long double*) std::malloc(sizeof(argument.value.decimal)); *(this -> value.decimal) = *(argument.value.decimal); std::free(this -> value.integer); this -> value.integer = NULL; break;
                                        case argument.signedIntegerType: this -> type = signedIntegerType; std::free(this -> value.decimal); this -> value.decimal = NULL; this -> value.integer = (long long*) std::malloc(sizeof(*(argument.value.integer))); *(this -> value.integer) = *(argument.value.integer); break;
                                        case argument.undefinedType: this -> terminate(); break;
                                        case argument.unsignedIntegerType: this -> type = unsignedIntegerType; std::free(this -> value.decimal); this -> value.decimal = NULL; this -> value.integer = (long long*) std::malloc(sizeof(*(argument.value.integer))); *(this -> value.integer) = *(argument.value.integer);
                                    }
                                }

                            // [Public]
                            public:
                                // [Constructor]
                                inline let() { this -> terminate(); }
                                let(const char argument) { this -> update(argument); }
                                let(const char16_t argument) { this -> update(argument); }
                                let(const char32_t argument) { this -> update(argument); }
                                let(const double argument) { this -> update(argument); }
                                let(const float argument) { this -> update(argument); }
                                let(const int argument) { this -> update(argument); }
                                let(const long argument) { this -> update(argument); }
                                let(const long double argument) { this -> update(argument); }
                                let(const long long argument) { this -> update(argument); }
                                let(const short argument) { this -> update(argument); }
                                let(const signed char argument) { this -> update(argument); }
                                let(const unsigned char argument) { this -> update(argument); }
                                let(const unsigned int argument) { this -> update(argument); }
                                let(const unsigned long argument) { this -> update(argument); }
                                let(const unsigned long long argument) { this -> update(argument); }
                                let(const unsigned short argument) { this -> update(argument); }
                                let(const wchar_t argument) { this -> update(argument); }
                                let(const LDKO::let& argument) { this -> update(argument); }

                                // [Destructor]
                                ~let() { this -> terminate(); }

                                // [Operator]
                                    // [=]
                                    let& operator =(const char argument) { this -> update(argument); return *this; }
                                    let& operator =(const char16_t argument) { this -> update(argument); return *this; }
                                    let& operator =(const char32_t argument) { this -> update(argument); return *this; }
                                    let& operator =(const double argument) { this -> update(argument); return *this; }
                                    let& operator =(const float argument) { this -> update(argument); return *this; }
                                    let& operator =(const int argument) { this -> update(argument); return *this; }
                                    let& operator =(const long argument) { this -> update(argument); return *this; }
                                    let& operator =(const long double argument) { this -> update(argument); return *this; }
                                    let& operator =(const long long argument) { this -> update(argument); return *this; }
                                    let& operator =(const short argument) { this -> update(argument); return *this; }
                                    let& operator =(const signed char argument) { this -> update(argument); return *this; }
                                    let& operator =(const unsigned char argument) { this -> update(argument); return *this; }
                                    let& operator =(const unsigned int argument) { this -> update(argument); return *this; }
                                    let& operator =(const unsigned long argument) { this -> update(argument); return *this; }
                                    let& operator =(const unsigned long long argument) { this -> update(argument); return *this; }
                                    let& operator =(const unsigned short argument) { this -> update(argument); return *this; }
                                    let& operator =(const wchar_t argument) { this -> update(argument); return *this; }
                                    let& operator =(const LDKO::let& argument) { this -> update(argument); return *this; }

                                    // ...
                                    inline operator char() const { return *(this -> value.integer); }
                                    inline operator char16_t() const { return *(this -> value.integer); }
                                    inline operator char32_t() const { return *(this -> value.integer); }
                                    inline operator double() const { return *(this -> value.decimal); }
                                    inline operator float() const { return *(this -> value.decimal); }
                                    inline operator int() const { return *(this -> value.integer); }
                                    inline operator long() const { return *(this -> value.integer); }
                                    inline operator long double() const { return *(this -> value.decimal); }
                                    inline operator long long() const { return *(this -> value.integer); }
                                    inline operator short() const { return *(this -> value.integer); }
                                    inline operator signed char() const { return *(this -> value.integer); }
                                    inline operator unsigned char() const { return *(this -> value.integer); }
                                    inline operator unsigned int() const { return *(this -> value.integer); }
                                    inline operator unsigned long() const { return *(this -> value.integer); }
                                    inline operator unsigned long long() const { return *(this -> value.integer); }
                                    inline operator unsigned short() const { return *(this -> value.integer); }
                                    inline operator wchar_t() const { return *(this -> value.integer); }

                                // Function
                                    // To String
                                    const char* toString() {
                                        // Logic > Return
                                        switch (this -> type) {
                                            case this -> characterType: return LDKF::toCharacterString(LDKF::toWideCharacter(*(this -> value.integer)));
                                            case this -> decimalType: return LDKF::toCharacterString(*(this -> value.decimal));
                                            case this -> signedIntegerType: return LDKF::toCharacterString(*(this -> value.integer));
                                            case this -> unsignedIntegerType: return LDKF::toCharacterString((unsigned long long) *(this -> value.integer));
                                            default: return LDKF::characterStringClone("undefined");
                                        }
                                    }

                                    // Value Of
                                    inline const long double valueOf() {
                                        // Logic > Return
                                        switch (this -> type) {
                                            case this -> characterType: case this -> signedIntegerType: case this -> unsignedIntegerType: return *(this -> value.integer);
                                            case this -> decimalType: return *(this -> value.decimal);
                                            default: long double undefined; return undefined;
                                        }
                                    }
                        };

                        // Boolean --- CHECKPOINT (Lapys)
                        class Boolean {};

                        // Character --- CHECKPOINT (Lapys)
                        class Character {};

                        // Function --- CHECKPOINT (Lapys)
                        class Function {};

                        // Number --- CHECKPOINT (Lapys)
                        class Number {};

                        // Symbol --- CHECKPOINT (Lapys)
                        class Symbol {};

                        // Variable --- CHECKPOINT (Lapys)
                        struct var {};

                        /* Object --- CHECKPOINT (Lapys) --- NOTE (Lapys) -> JavaScript-like `Object` constructor. */
                        class Object {};
                            // Array --- CHECKPOINT (Lapys)
                            class Array : Object {};

                            // Clock --- CHECKPOINT (Lapys) --- NOTE (Lapys) -> Asynchronous handler.
                            struct Clock : Object {};

                            // String --- CHECKPOINT (Lapys)
                            class String : Object {};

                    /* Namespace */
                        // Manager --- CHECKPOINT (Lapys) --- NOTE (Lapys) -> Container for communication with low-level system features.
                        namespace Manager {
                            /* Namespace */
                                // Devices
                                namespace Devices {
                                    /* Class */
                                        // Device
                                        struct Device {};

                                    /* Constant */
                                        // Keyboard
                                        LDKO::Manager::Devices::Device Keyboard;
                                }

                                // Graphics
                                namespace Graphics {
                                    /* Class */
                                        // Color
                                        struct Color {};

                                        // Coordinates
                                        struct Coordinates {};

                                        // Pixel
                                        struct Pixel {};

                                        // Text
                                        struct Text {};
                                }
                        }

                    /* Class */
                        // Interface --- CHECKPOINT (Lapys) --- NOTE (Lapys) -> Devices, graphics interfaces and so on.
                        class Interface : Object {};
                            /* Console
                                --- NOTE ---
                                    #Lapys:
                                        - Command-line user-interface component.
                                        - Handles all interactions with the user terminal, if existing.
                                        - Does not require the `LapysDevelopmentKit::Manager::Graphics` namespace to function.
                            */
                            struct Console : Interface {
                                // [Private]
                                private:
                                    // Class > Stream
                                    class Stream {
                                        // [Private]
                                        private:
                                            // Initialization > Stream
                                            const FILE* stream = NULL;

                                        // [Public]
                                        public:
                                            // [Constructor]
                                            Stream(const FILE* stream, const minimal_numeric_type fileNumber) : stream(stream), fileNumber(fileNumber) {}

                                            // [Destructor]
                                            ~Stream() { this -> terminate(); }

                                            /* Phase > Terminate */
                                            void terminate() const { std::free((FILE*) this -> stream); }

                                            // Initialization > File Number
                                            const minimal_numeric_type fileNumber;

                                            // Function > Value Of
                                            const FILE* valueOf() const { return this -> stream; }
                                    };

                                    // Initialization > Group Depth
                                    minimal_numeric_type groupDepth = 0;

                                // [Protected]
                                protected:
                                    /* Initialization > (Error, Input, Output) Stream */
                                    const Stream
                                        errorStream = Stream(stderr, STDERR_FILENO),
                                        inputStream = Stream(stdin, STDIN_FILENO),
                                        outputStream = Stream(stdout, STDOUT_FILENO);

                                    /* Phase > Terminate */
                                    void terminate() {
                                        // Target > Flush
                                        this -> flush();

                                        // Loop > Target > Group End
                                        while (this -> groupDepth) this -> groupEnd();

                                        // (Error, Input, Output) Stream > Terminate
                                        errorStream.terminate(); inputStream.terminate(); outputStream.terminate();
                                    }

                                    // Function > Write To Output Stream
                                    void writeToOutputStream(const char* stream, const unsigned length) {
                                        // Logic
                                        if (this -> isAvailable()) {
                                            // Logic
                                            if (this -> groupDepth) {
                                                // Initialization > Group Depth
                                                minimal_numeric_type groupDepth = this -> groupDepth;

                                                // Loop
                                                while (groupDepth) {
                                                    // Initialization > Tab Width
                                                    minimal_numeric_type tabWidth = LDKC::Number::tabWidth;

                                                    // Loop > (Write; Update > Tab Width)
                                                    while (tabWidth) { ::write(this -> outputStream.fileNumber, LDKC::String::tabFill, LDKC::Number::tabFillLength); tabWidth -= 1; }

                                                    // Update > Group Depth
                                                    groupDepth -= 1;
                                                }
                                            }

                                            // Write
                                            LDKF::pointerIsNull(stream) ? ::write(this -> outputStream.fileNumber, "null", 4) : ::write(this -> outputStream.fileNumber, stream, length);
                                        }
                                    }

                                // [Public]
                                public:
                                    // [Destructor]
                                    ~Console() { this -> terminate(); }

                                    // Initialization > Print Newlines On Log
                                    bool printNewlinesOnLog = false;

                                    // Function
                                        // Clear --- UPDATE REQUIRED (Lapys)
                                        void clear() {
                                            // Target > Flush
                                            this -> flush();

                                            // Logic > System > ...
                                            if (this -> isAvailable())
                                                #ifdef _WIN32
                                                    this -> command("cls");
                                                #elif defined(__APPLE__) || defined(__gnu_linux__) || defined(__LINUX__) || defined(__linux__)
                                                    this -> command("clear");
                                                #endif
                                        }

                                        // Command
                                        int command(const char* command) { return std::system(command); }

                                        // Flush
                                        void flush(const FILE* stream) { if (this -> isAvailable())  std::fflush((FILE*) stream); }
                                        void flush(FILE* stream) { this -> flush((const FILE*) stream); }
                                        void flush() { this -> flush(this -> outputStream.valueOf()); }

                                        // Is Available
                                        const bool isAvailable() { return this -> command(NULL); }

                                        // Group
                                        template <typename... types>
                                        void group(types... arguments) {
                                            // Initialization > Print Newlines On Log
                                            const bool printNewlinesOnLog = this -> printNewlinesOnLog;

                                            // Modification > Target > Print Newlines On Log
                                            this -> printNewlinesOnLog = false;

                                            // Logic > Target > Flush
                                            if (!(this -> groupDepth)) this -> flush();

                                            // Target > (Log, Write To Output Stream)
                                            this -> log(arguments...);
                                            this -> writeToOutputStream("\n", 1u);

                                            // Modification > Target > (Group Depth, Print Newlines On Log)
                                            this -> groupDepth += 1u;
                                            this -> printNewlinesOnLog = printNewlinesOnLog;
                                        }

                                        // Group End
                                        inline void groupEnd() { this -> writeToOutputStream("\n", 1u); this -> groupDepth && (this -> groupDepth -= 1); }

                                        // Log --- UPDATE REQUIRED (Lapys) -> Should be able to print objects without cloning them.
                                        void log() { this -> flush(); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const char* argument) { this -> writeToOutputStream(argument, LDKF::characterStringLength(argument)); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(char* argument) { this -> log((const char*) argument); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const char argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> writeToOutputStream(characterString, 1); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const char16_t argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> writeToOutputStream(characterString, 1); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const char32_t argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> writeToOutputStream(characterString, 1); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const double argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> log(characterString); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const float argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> log(characterString); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const int argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> log(characterString); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const long argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> log(characterString); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const long double argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> log(characterString); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const long long argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> log(characterString); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const short argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> log(characterString); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const signed char argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> log(characterString); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const unsigned char argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> log(characterString); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const unsigned int argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> log(characterString); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const unsigned long argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> log(characterString); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const unsigned long long argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> log(characterString); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const unsigned short argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> log(characterString); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const void* argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> log(characterString); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(const wchar_t argument) { char* characterString = (char*) LDKF::toCharacterString(argument); this -> writeToOutputStream(characterString, 1); std::free(characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }

                                        template <typename type> void log(LDKO::array<type>& argument) { const char* characterString = argument.toString(); this -> writeToOutputStream(characterString, LDKF::characterStringLength(characterString)); std::free((char*) characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        void log(LDKO::let& argument) { const char* characterString = argument.toString(); this -> writeToOutputStream(characterString, LDKF::characterStringLength(characterString)); std::free((char*) characterString); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }

                                        template <typename type> void log(type argument) { this -> writeToOutputStream("[object]", 8); if (this -> printNewlinesOnLog) { this -> writeToOutputStream("\n", 1); this -> flush(); } }
                                        template <typename... types> void log(types... arguments) { this -> log(arguments...); }
                                        template <typename type, typename... types>
                                        void log(type& argument, types&... arguments) {
                                            // Initialization > (Group Depth, Print Newlines On Log)
                                            const minimal_numeric_type groupDepth = this -> groupDepth;
                                            const bool printNewlinesOnLog = this -> printNewlinesOnLog;

                                            // Modification > Target > Print Newlines On Log
                                            this -> printNewlinesOnLog = false;

                                            // Target > Log
                                            this -> log(argument);

                                            // Modification > Target > Group Depth
                                            this -> groupDepth = 0;

                                            // Target > Log
                                            this -> log(arguments...);

                                            // Modification > Target > (Group Depth, Print Newlines On Log)
                                            this -> groupDepth = groupDepth;
                                            this -> printNewlinesOnLog = printNewlinesOnLog;

                                            // Logic
                                            if (this -> printNewlinesOnLog) {
                                                // Target > (Write To Output Stream, Flush)
                                                this -> writeToOutputStream("\n", 1);
                                                this -> flush();
                                            }
                                        }

                                        // Prompt
                                        const char* prompt() {
                                            // Logic
                                            if (this -> isAvailable()) {
                                                // Initialization > Character (String (Length))
                                                char character = '\0', *characterString = (char*) std::malloc(sizeof(char));
                                                unsigned characterStringLength = 1;

                                                // Update > Character String
                                                *characterString = '\0';

                                                // Loop
                                                while (true) {
                                                    // Update > Character
                                                    character = std::getchar();

                                                    // Logic > [Break]
                                                    if (character == EOF || character == '\n' || character == '\0') break;

                                                    // Update > Character String (Length)
                                                    characterString = (char*) std::realloc(characterString, (characterStringLength + 1) * sizeof(char));
                                                    *(characterString + (characterStringLength - 1)) = character;
                                                    characterStringLength += 1;
                                                }

                                                // Update > Character String
                                                *(characterString + characterStringLength - 1) = '\0';
                                                *characterString || (characterString = NULL);

                                                // Return
                                                return characterString;
                                            }

                                            else
                                                // Return
                                                return LDKF::characterStringClone("");
                                        }
                                        const char* prompt(const char*& argument) { return argument = this -> prompt(); }
                                        const char* prompt(char*& argument) { return this -> prompt((const char*&) argument); }
                                        const char* prompt(char& argument) { const char* characterString = this -> prompt(); return LDKF::toCharacterString(argument = LDKF::pointerIsNull(characterString) ? '\0' : *characterString); }
                                        const char* prompt(char16_t& argument) { const char* characterString = this -> prompt(); return LDKF::toCharacterString(argument = LDKF::pointerIsNull(characterString) ? '\0' : *characterString); }
                                        const char* prompt(char32_t& argument) { const char* characterString = this -> prompt(); return LDKF::toCharacterString(argument = LDKF::pointerIsNull(characterString) ? '\0' : *characterString); }
                                        const char* prompt(double& argument) { const char* characterString = this -> prompt(); if (LDKF::pointerIsNull(characterString)) throw LDKO::NullInputException(); else { long double number = LDKF::toNumber(characterString); if (!(*(characterString + 3) == '\0' && (((*characterString == 'n' && *(characterString + 1) == 'a' && *(characterString + 2) == 'n')) || ((*characterString == 'N' && *(characterString + 1) == 'a' && *(characterString + 2) == 'N')) || ((*characterString == 'N' && *(characterString + 1) == 'A' && *(characterString + 2) == 'N')))) && LDKF::numberIsNaN(number)) throw LDKO::InvalidInputException(); return LDKF::toCharacterString(argument = number); } }
                                        const char* prompt(float& argument) { const char* characterString = this -> prompt(); if (LDKF::pointerIsNull(characterString)) throw LDKO::NullInputException(); else { long double number = LDKF::toNumber(characterString); if (!(*(characterString + 3) == '\0' && (((*characterString == 'n' && *(characterString + 1) == 'a' && *(characterString + 2) == 'n')) || ((*characterString == 'N' && *(characterString + 1) == 'a' && *(characterString + 2) == 'N')) || ((*characterString == 'N' && *(characterString + 1) == 'A' && *(characterString + 2) == 'N')))) && LDKF::numberIsNaN(number)) throw LDKO::InvalidInputException(); return LDKF::toCharacterString(argument = number); } }
                                        const char* prompt(int& argument) { const char* characterString = this -> prompt(); if (LDKF::pointerIsNull(characterString)) throw LDKO::NullInputException(); else { long double number = LDKF::toNumber(characterString); if (!(*(characterString + 3) == '\0' && (((*characterString == 'n' && *(characterString + 1) == 'a' && *(characterString + 2) == 'n')) || ((*characterString == 'N' && *(characterString + 1) == 'a' && *(characterString + 2) == 'N')) || ((*characterString == 'N' && *(characterString + 1) == 'A' && *(characterString + 2) == 'N')))) && LDKF::numberIsNaN(number)) throw LDKO::InvalidInputException(); return LDKF::toCharacterString(argument = number); } }
                                        const char* prompt(long& argument) { const char* characterString = this -> prompt(); if (LDKF::pointerIsNull(characterString)) throw LDKO::NullInputException(); else { long double number = LDKF::toNumber(characterString); if (!(*(characterString + 3) == '\0' && (((*characterString == 'n' && *(characterString + 1) == 'a' && *(characterString + 2) == 'n')) || ((*characterString == 'N' && *(characterString + 1) == 'a' && *(characterString + 2) == 'N')) || ((*characterString == 'N' && *(characterString + 1) == 'A' && *(characterString + 2) == 'N')))) && LDKF::numberIsNaN(number)) throw LDKO::InvalidInputException(); return LDKF::toCharacterString(argument = number); } }
                                        const char* prompt(long long& argument) { const char* characterString = this -> prompt(); if (LDKF::pointerIsNull(characterString)) throw LDKO::NullInputException(); else { long double number = LDKF::toNumber(characterString); if (!(*(characterString + 3) == '\0' && (((*characterString == 'n' && *(characterString + 1) == 'a' && *(characterString + 2) == 'n')) || ((*characterString == 'N' && *(characterString + 1) == 'a' && *(characterString + 2) == 'N')) || ((*characterString == 'N' && *(characterString + 1) == 'A' && *(characterString + 2) == 'N')))) && LDKF::numberIsNaN(number)) throw LDKO::InvalidInputException(); return LDKF::toCharacterString(argument = number); } }
                                        const char* prompt(short& argument) { const char* characterString = this -> prompt(); if (LDKF::pointerIsNull(characterString)) throw LDKO::NullInputException(); else { long double number = LDKF::toNumber(characterString); if (!(*(characterString + 3) == '\0' && (((*characterString == 'n' && *(characterString + 1) == 'a' && *(characterString + 2) == 'n')) || ((*characterString == 'N' && *(characterString + 1) == 'a' && *(characterString + 2) == 'N')) || ((*characterString == 'N' && *(characterString + 1) == 'A' && *(characterString + 2) == 'N')))) && LDKF::numberIsNaN(number)) throw LDKO::InvalidInputException(); return LDKF::toCharacterString(argument = number); } }
                                        const char* prompt(signed char& argument) { const char* characterString = this -> prompt(); return LDKF::toCharacterString(argument = LDKF::pointerIsNull(characterString) ? '\0' : *characterString); }
                                        const char* prompt(unsigned char& argument) { const char* characterString = this -> prompt(); return LDKF::toCharacterString(argument = LDKF::pointerIsNull(characterString) ? '\0' : *characterString); }
                                        const char* prompt(unsigned int& argument) { const char* characterString = this -> prompt(); if (LDKF::pointerIsNull(characterString)) throw LDKO::NullInputException(); else { long double number = LDKF::toNumber(characterString); if (!(*(characterString + 3) == '\0' && (((*characterString == 'n' && *(characterString + 1) == 'a' && *(characterString + 2) == 'n')) || ((*characterString == 'N' && *(characterString + 1) == 'a' && *(characterString + 2) == 'N')) || ((*characterString == 'N' && *(characterString + 1) == 'A' && *(characterString + 2) == 'N')))) && LDKF::numberIsNaN(number)) throw LDKO::InvalidInputException(); return LDKF::toCharacterString(argument = number); } }
                                        const char* prompt(unsigned long& argument) { const char* characterString = this -> prompt(); if (LDKF::pointerIsNull(characterString)) throw LDKO::NullInputException(); else { long double number = LDKF::toNumber(characterString); if (!(*(characterString + 3) == '\0' && (((*characterString == 'n' && *(characterString + 1) == 'a' && *(characterString + 2) == 'n')) || ((*characterString == 'N' && *(characterString + 1) == 'a' && *(characterString + 2) == 'N')) || ((*characterString == 'N' && *(characterString + 1) == 'A' && *(characterString + 2) == 'N')))) && LDKF::numberIsNaN(number)) throw LDKO::InvalidInputException(); return LDKF::toCharacterString(argument = number); } }
                                        const char* prompt(unsigned long long& argument) { const char* characterString = this -> prompt(); if (LDKF::pointerIsNull(characterString)) throw LDKO::NullInputException(); else { long double number = LDKF::toNumber(characterString); if (!(*(characterString + 3) == '\0' && (((*characterString == 'n' && *(characterString + 1) == 'a' && *(characterString + 2) == 'n')) || ((*characterString == 'N' && *(characterString + 1) == 'a' && *(characterString + 2) == 'N')) || ((*characterString == 'N' && *(characterString + 1) == 'A' && *(characterString + 2) == 'N')))) && LDKF::numberIsNaN(number)) throw LDKO::InvalidInputException(); return LDKF::toCharacterString(argument = number); } }
                                        const char* prompt(unsigned short& argument) { const char* characterString = this -> prompt(); if (LDKF::pointerIsNull(characterString)) throw LDKO::NullInputException(); else { long double number = LDKF::toNumber(characterString); if (!(*(characterString + 3) == '\0' && (((*characterString == 'n' && *(characterString + 1) == 'a' && *(characterString + 2) == 'n')) || ((*characterString == 'N' && *(characterString + 1) == 'a' && *(characterString + 2) == 'N')) || ((*characterString == 'N' && *(characterString + 1) == 'A' && *(characterString + 2) == 'N')))) && LDKF::numberIsNaN(number)) throw LDKO::InvalidInputException(); return LDKF::toCharacterString(argument = number); } }
                                        const char* prompt(wchar_t& argument) { const char* characterString = this -> prompt(); return LDKF::toCharacterString(argument = LDKF::pointerIsNull(characterString) ? '\0' : *characterString); }
                                        template <typename type, typename... types> const char* prompt(types... arguments, type& argument) { this -> log(arguments...); return this -> prompt(argument); }
                            };

                            /* Control
                                --- NOTE (Lapys) -> Graphical user-Interface components.
                                --- WARN (Lapys) -> Requires the `LapysDevelopmentKit::Manager::Graphics` namespace to function.
                            */
                            class Control : Interface {};
                                // Button
                                class Button : Control {};

                                // Field
                                class Field : Control {};

                                // Frame
                                class Frame : Control {};
                                    // Window --- NOTE (Lapys) -> A Window is a top-level frame.
                                    class Window : Frame {};
                }
        }

        /* Constant */
            // Console
            LDKO::Console console;

            // Mathematics --- NOTE (Lapys) -> Basically a solid clone of the `Lapys::LapysDevelopmentKit::Mathematics` namespace.
            const struct Mathematics {} Math;
    }
#endif
