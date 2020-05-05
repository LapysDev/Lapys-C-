/**
    @author: Lapys Dev Team
    @description: Lapys C is a general-purpose C library.
    @version: 0.0.10
    @url: https://github.com/LapysDev/LapysCPP

    --- NOTE ---
        #Lapys:
            - Supported environment standards:
                -- ISO/IEC 14882:1998 (C++98) (1998 - 2003) - current...

            - Over its years of development, the library is still a bare-bones version of what it could be.

    --- RULES ---
        #Lapys:
            - Functions can only be minified if they perform at optimal absolutism.
            - Most (if not all) strings returned from functions have to be allocated in heap storage.
*/
/* Logic */
#ifndef LAPYS_H
    /* Definition > ... */
    #define LAPYS_H

    /* Import */
    #include <math.h> // Mathematics
    #include <stdlib.h> // Standard Library
    #include <stdio.h> // Standard Input-Output
    #include <unistd.h> // UNIX Standard

    /* Namespace > Lapys */
    namespace Lapys {
        /* Namespace */
            /* [Lapys Development Kit] ... */
            namespace LapysDevelopmentKit {
                /* Namespace > ... */
                namespace Constants {}
                namespace Data {}
                namespace Functions {}
                namespace Information {}
                namespace Mathematics {}
                namespace Storage {}
            }

            /* [Shorthand] ... */
            namespace LDK = LapysDevelopmentKit;
            namespace LDKC = LapysDevelopmentKit::Constants;
            namespace LDKD = LapysDevelopmentKit::Data;
            namespace LDKF = LapysDevelopmentKit::Functions;
            namespace LDKI = LapysDevelopmentKit::Information;
            namespace LDKM = LapysDevelopmentKit::Mathematics;
            namespace LDKS = LapysDevelopmentKit::Storage;

            /* Lapys Development Kit */
            namespace LapysDevelopmentKit {
                /* Namespace */
                    /* Functions */
                    namespace Functions {
                        // Get Arguments Count
                        inline const unsigned short getArgumentsCount() { return 0u; }
                        template <typename type> inline const unsigned short getArgumentsCount(type argument) { return 1u; }
                        template <typename type, typename... types> const unsigned short getArgumentsCount(type argument, types... arguments) { return LDKF::getArgumentsCount(argument) + LDKF::getArgumentsCount(arguments...); }

                        // Get Referenced Arguments Count
                        inline const unsigned short getReferencedArgumentsCount() { return 0u; }
                        template <typename type> inline const unsigned short getReferencedArgumentsCount(type& argument) { return 1u; }
                        template <typename type, typename... types> const unsigned short getReferencedArgumentsCount(type& argument, types&... arguments) { return LDKF::getReferencedArgumentsCount(argument) + LDKF::getReferencedArgumentsCount(arguments...); }

                        // Get Type --- CHECKPOINT (Lapys)
                        struct getType {};

                        // To
                            // Integer
                            inline const long toInteger(const double number) { return number; }
                            inline const int toInteger(const float number) { return number; }
                            inline const int toInteger(const int number) { return number; }
                            inline const long toInteger(const long number) { return number; }
                            inline const long long toInteger(const long double number) { return number; }
                            inline const long long toInteger(const long long number) { return number; }
                            inline const short toInteger(const short number) { return number; }
                            inline const unsigned int toInteger(const unsigned int number) { return number; }
                            inline const unsigned long toInteger(const unsigned long number) { return number; }
                            inline const unsigned long long toInteger(const unsigned long long number) { return number; }
                            inline const unsigned short toInteger(const unsigned short number) { return number; }
                    }

                    /* Mathematics */
                    namespace Mathematics {
                        /* Function */
                            // Absolute
                            inline const double abs(const double number) { return number > -1.00 ? number : -number; } inline const float abs(const float number) { return number > -1.0f ? number : -number; } inline const unsigned int abs(const int number) { return number > -1 ? number : -number; } inline const unsigned long abs(const long number) { return number > -1L ? number : -number; } inline const long double abs(const long double number) { return number > -1.00 ? number : -number; } inline const unsigned long long abs(const long long number) { return number > -1LL ? number : -number; } inline const unsigned short abs(const short number) { return number > -1 ? number : -number; }
                            inline const unsigned int abs(const unsigned int number) { return number; } inline const unsigned long abs(const unsigned long number) { return number; } inline const unsigned long long abs(const unsigned long long number) { return number; } inline const unsigned short abs(const unsigned short number) { return number; }

                            // Floor
                            inline const long floor(const double number) { return number; } inline const int floor(const float number) { return number; } inline const int floor(const int number) { return number; } inline const long floor(const long number) { return number; } inline const long long floor(const long double number) { return number; } inline const long long floor(const long long number) { return number; } inline const short floor(const short number) { return number; } inline const unsigned int floor(const unsigned int number) { return number; } inline const unsigned long floor(const unsigned long number) { return number; } inline const unsigned long long floor(const unsigned long long number) { return number; } inline const unsigned short floor(const unsigned short number) { return number; }

                            // Logarithm [Base 10]
                            const double log10(const double number) { return std::log10(number); } const float log10(const float number) { return std::log10(number); } const float log10(const int number) { return std::log10(number); } const double log10(const long number) { return std::log10(number); } const long double log10(const long double number) { return std::log10(number); } const long double log10(const long long number) { return std::log10(number); } const float log10(const short number) { return std::log10(number); } const float log10(const unsigned int number) { return std::log10(number); } const double log10(const unsigned long number) { return std::log10(number); } const long double log10(const unsigned long long number) { return std::log10(number); } const float log10(const unsigned short number) { return std::log10(number); }

                            // Modulus
                            const double mod(const double numberA, const double numberB) { if (numberB) { double divisor = LDKM::abs(numberB), modulus = LDKM::abs(numberA); while (modulus >= divisor) modulus -= divisor; return numberA > -1.00 ? modulus : -modulus; } else return std::nan(""); } const double mod(const double numberA, const float numberB) { return LDKM::mod(numberA, (const double) numberB); } const double mod(const double numberA, const int numberB) { return LDKM::mod(numberA, (const double) numberB); } const double mod(const double numberA, const long numberB) { return LDKM::mod(numberA, (const double) numberB); } const double mod(const double numberA, const long long numberB) { return LDKM::mod(numberA, (const double) numberB); } const double mod(const double numberA, const short numberB) { return LDKM::mod(numberA, (const double) numberB); } const double mod(const double numberA, const unsigned int numberB) { return LDKM::mod(numberA, (const double) numberB); } const double mod(const double numberA, const unsigned long numberB) { return LDKM::mod(numberA, (const double) numberB); } const double mod(const double numberA, const unsigned long long numberB) { return LDKM::mod(numberA, (const double) numberB); } const double mod(const double numberA, const unsigned short numberB) { return LDKM::mod(numberA, (const double) numberB); }
                            const float mod(const float numberA, const double numberB) { return LDKM::mod((const double) numberA, numberB); } const float mod(const float numberA, const float numberB) { if (numberB) { float divisor = LDKM::abs(numberB), modulus = LDKM::abs(numberA); while (modulus >= divisor) modulus -= divisor; return numberA > -1.00f ? modulus : -modulus; } else return std::nanf(""); } const float mod(const float numberA, const int numberB) { return LDKM::mod(numberA, (const float) numberB); } const float mod(const float numberA, const long numberB) { return LDKM::mod(numberA, (const float) numberB); } const float mod(const float numberA, const long long numberB) { return LDKM::mod((const double) numberA, (const double) numberB); } const float mod(const float numberA, const short numberB) { return LDKM::mod(numberA, (const float) numberB); } const float mod(const float numberA, const unsigned int numberB) { return LDKM::mod(numberA, (const float) numberB); } const float mod(const float numberA, const unsigned long numberB) { return LDKM::mod(numberA, (const float) numberB); } const float mod(const float numberA, const unsigned long long numberB) { return LDKM::mod((const double) numberA, (const double) numberB); } const float mod(const float numberA, const unsigned short numberB) { return LDKM::mod(numberA, (const float) numberB); }
                            const double mod(const int numberA, const double numberB) { return LDKM::mod((const double) numberA, numberB); } const float mod(const int numberA, const float numberB) { return LDKM::mod((const float) numberA, numberB); } inline const int mod(const int numberA, const int numberB) { return numberA % numberB; } inline const int mod(const int numberA, const long numberB) { return numberA % numberB; } inline const int mod(const int numberA, const long long numberB) { return numberA % numberB; } inline const int mod(const int numberA, const short numberB) { return numberA % numberB; } inline const int mod(const int numberA, const unsigned int numberB) { return numberA % numberB; } inline const int mod(const int numberA, const unsigned long numberB) { return numberA % numberB; } inline const int mod(const int numberA, const unsigned long long numberB) { return numberA % numberB; } inline const int mod(const int numberA, const unsigned short numberB) { return numberA % numberB; }
                            const double mod(const long numberA, const double numberB) { return LDKM::mod((const double) numberA, numberB); } const float mod(const long numberA, const float numberB) { return LDKM::mod((const float) numberA, numberB); } inline const long mod(const long numberA, const int numberB) { return numberA % numberB; } inline const long mod(const long numberA, const long numberB) { return numberA % numberB; } inline const long mod(const long numberA, const long long numberB) { return numberA % numberB; } inline const long mod(const long numberA, const short numberB) { return numberA % numberB; } inline const long mod(const long numberA, const unsigned int numberB) { return numberA % numberB; } inline const long mod(const long numberA, const unsigned long numberB) { return numberA % numberB; } inline const long mod(const long numberA, const unsigned long long numberB) { return numberA % numberB; } inline const long mod(const long numberA, const unsigned short numberB) { return numberA % numberB; }
                            const long double mod(const long double numberA, const long double numberB) { if (numberB) { long double divisor = LDKM::abs(numberB), modulus = LDKM::abs(numberA); while (modulus >= divisor) modulus -= divisor; return numberA > -1.00 ? modulus : -modulus; } else return std::nanl(""); } const long double mod(const double numberA, const long double numberB) { return LDKM::mod((const long double) numberA, numberB); } const long double mod(const float numberA, const long double numberB) { return LDKM::mod((const long double) numberA, numberB); } const long double mod(const int numberA, const long double numberB) { return LDKM::mod((const long double) numberA, numberB); } const long double mod(const long numberA, const long double numberB) { return LDKM::mod((const long double) numberA, numberB); } const long double mod(const long double numberA, const double numberB) { return LDKM::mod(numberA, (const long double) numberB); } const long double mod(const long double numberA, const float numberB) { return LDKM::mod(numberA, (const long double) numberB); } const long double mod(const long double numberA, const int numberB) { return LDKM::mod(numberA, (const long double) numberB); } const long double mod(const long double numberA, const long numberB) { return LDKM::mod(numberA, (const long double) numberB); } const long double mod(const long double numberA, const long long numberB) { return LDKM::mod(numberA, (const long double) numberB); } const long double mod(const long double numberA, const short numberB) { return LDKM::mod(numberA, (const long double) numberB); } const long double mod(const long double numberA, const unsigned int numberB) { return LDKM::mod(numberA, (const long double) numberB); } const long double mod(const long double numberA, const unsigned long numberB) { return LDKM::mod(numberA, (const long double) numberB); } const long double mod(const long double numberA, const unsigned long long numberB) { return LDKM::mod(numberA, (const long double) numberB); } const long double mod(const long double numberA, const unsigned short numberB) { return LDKM::mod(numberA, (const long double) numberB); }
                            const double mod(const long long numberA, const double numberB) { return LDKM::mod((const double) numberA, numberB); } const double mod(const long long numberA, const float numberB) { return LDKM::mod((const double) numberA, (const double) numberB); } inline const long long mod(const long long numberA, const int numberB) { return numberA % numberB; } inline const long long mod(const long long numberA, const long numberB) { return numberA % numberB; } const long double mod(const long long numberA, const long double numberB) { return LDKM::mod((const long double) numberA, numberB); } inline const long long mod(const long long numberA, const long long numberB) { return numberA % numberB; } inline const long long mod(const long long numberA, const short numberB) { return numberA % numberB; } inline const long long mod(const long long numberA, const unsigned int numberB) { return numberA % numberB; } inline const long long mod(const long long numberA, const unsigned long numberB) { return numberA % numberB; } inline const long long mod(const long long numberA, const unsigned long long numberB) { return numberA % numberB; } inline const long long mod(const long long numberA, const unsigned short numberB) { return numberA % numberB; }
                            const double mod(const short numberA, const double numberB) { return LDKM::mod((const double) numberA, numberB); } const float mod(const short numberA, const float numberB) { return LDKM::mod((const float) numberA, numberB); } inline const short mod(const short numberA, const int numberB) { return numberA % numberB; } inline const short mod(const short numberA, const long numberB) { return numberA % numberB; } const long double mod(const short numberA, const long double numberB) { return LDKM::mod((const long double) numberA, numberB); } inline const short mod(const short numberA, const long long numberB) { return numberA % numberB; } inline const short mod(const short numberA, const short numberB) { return numberA % numberB; } inline const short mod(const short numberA, const unsigned int numberB) { return numberA % numberB; } inline const short mod(const short numberA, const unsigned long numberB) { return numberA % numberB; } inline const short mod(const short numberA, const unsigned long long numberB) { return numberA % numberB; } inline const short mod(const short numberA, const unsigned short numberB) { return numberA % numberB; }
                            const double mod(const unsigned int numberA, const double numberB) { return LDKM::mod((const double) numberA, numberB); } const float mod(const unsigned int numberA, const float numberB) { return LDKM::mod((const float) numberA, numberB); } inline const unsigned int mod(const unsigned int numberA, const int numberB) { return numberA % numberB; } inline const unsigned int mod(const unsigned int numberA, const long numberB) { return numberA % numberB; } const long double mod(const unsigned int numberA, const long double numberB) { return LDKM::mod((const long double) numberA, numberB); } inline const unsigned int mod(const unsigned int numberA, const long long numberB) { return numberA % numberB; } inline const unsigned int mod(const unsigned int numberA, const short numberB) { return numberA % numberB; } inline const unsigned int mod(const unsigned int numberA, const unsigned int numberB) { return numberA % numberB; } inline const unsigned int mod(const unsigned int numberA, const unsigned long numberB) { return numberA % numberB; } inline const unsigned int mod(const unsigned int numberA, const unsigned long long numberB) { return numberA % numberB; } inline const unsigned int mod(const unsigned int numberA, const unsigned short numberB) { return numberA % numberB; }
                            const double mod(const unsigned long numberA, const double numberB) { return LDKM::mod((const double) numberA, numberB); } const float mod(const unsigned long numberA, const float numberB) { return LDKM::mod((const float) numberA, numberB); } inline const unsigned long mod(const unsigned long numberA, const int numberB) { return numberA % numberB; } inline const unsigned long mod(const unsigned long numberA, const long numberB) { return numberA % numberB; } const long double mod(const unsigned long numberA, const long double numberB) { return LDKM::mod((const long double) numberA, numberB); } inline const unsigned long mod(const unsigned long numberA, const long long numberB) { return numberA % numberB; } inline const unsigned long mod(const unsigned long numberA, const short numberB) { return numberA % numberB; } inline const unsigned long mod(const unsigned long numberA, const unsigned int numberB) { return numberA % numberB; } inline const unsigned long mod(const unsigned long numberA, const unsigned long numberB) { return numberA % numberB; } inline const unsigned long mod(const unsigned long numberA, const unsigned long long numberB) { return numberA % numberB; } inline const unsigned long mod(const unsigned long numberA, const unsigned short numberB) { return numberA % numberB; }
                            const double mod(const unsigned long long numberA, const double numberB) { return LDKM::mod((const double) numberA, numberB); } const double mod(const unsigned long long numberA, const float numberB) { return LDKM::mod((const double) numberA, (const double) numberB); } inline const unsigned long long mod(const unsigned long long numberA, const int numberB) { return numberA % numberB; } inline const unsigned long long mod(const unsigned long long numberA, const long numberB) { return numberA % numberB; } const long double mod(const unsigned long long numberA, const long double numberB) { return LDKM::mod((const long double) numberA, numberB); } inline const unsigned long long mod(const unsigned long long numberA, const long long numberB) { return numberA % numberB; } inline const unsigned long long mod(const unsigned long long numberA, const short numberB) { return numberA % numberB; } inline const unsigned long long mod(const unsigned long long numberA, const unsigned int numberB) { return numberA % numberB; } inline const unsigned long long mod(const unsigned long long numberA, const unsigned long numberB) { return numberA % numberB; } inline const unsigned long long mod(const unsigned long long numberA, const unsigned long long numberB) { return numberA % numberB; } inline const unsigned long long mod(const unsigned long long numberA, const unsigned short numberB) { return numberA % numberB; }
                            const double mod(const unsigned short numberA, const double numberB) { return LDKM::mod((const double) numberA, numberB); } const float mod(const unsigned short numberA, const float numberB) { return LDKM::mod((const float) numberA, numberB); } inline const unsigned short mod(const unsigned short numberA, const int numberB) { return numberA % numberB; } inline const unsigned short mod(const unsigned short numberA, const long numberB) { return numberA % numberB; } const long double mod(const unsigned short numberA, const long double numberB) { return LDKM::mod((const long double) numberA, numberB); } inline const unsigned short mod(const unsigned short numberA, const long long numberB) { return numberA % numberB; } inline const unsigned short mod(const unsigned short numberA, const short numberB) { return numberA % numberB; } inline const unsigned short mod(const unsigned short numberA, const unsigned int numberB) { return numberA % numberB; } inline const unsigned short mod(const unsigned short numberA, const unsigned long numberB) { return numberA % numberB; } inline const unsigned short mod(const unsigned short numberA, const unsigned long long numberB) { return numberA % numberB; } inline const unsigned short mod(const unsigned short numberA, const unsigned short numberB) { return numberA % numberB; }
                    }

                    /* Functions */
                    namespace Functions {
                        /* Function */
                            // Number
                                // Characteristics Length
                                const unsigned short numberCharacteristicsLength(const double number) { return LDKM::floor(LDKM::log10(number)) + 1u; } const unsigned short numberCharacteristicsLength(const float number) { return LDKM::floor(LDKM::log10(number)) + 1u; } const unsigned short numberCharacteristicsLength(const int number) { return LDKM::floor(LDKM::log10(number)) + 1u; } const unsigned short numberCharacteristicsLength(const long number) { return LDKM::floor(LDKM::log10(number)) + 1u; } const unsigned short numberCharacteristicsLength(const long double number) { return LDKM::floor(LDKM::log10(number)) + 1u; } const unsigned short numberCharacteristicsLength(const long long number) { return LDKM::floor(LDKM::log10(number)) + 1u; } const unsigned short numberCharacteristicsLength(const short number) { return LDKM::floor(LDKM::log10(number)) + 1u; } const unsigned short numberCharacteristicsLength(const unsigned int number) { return LDKM::floor(LDKM::log10(number)) + 1u; } const unsigned short numberCharacteristicsLength(const unsigned long number) { return LDKM::floor(LDKM::log10(number)) + 1u; } const unsigned short numberCharacteristicsLength(const unsigned long long number) { return LDKM::floor(LDKM::log10(number)) + 1u; } const unsigned short numberCharacteristicsLength(const unsigned short number) { return LDKM::floor(LDKM::log10(number)) + 1u; }
                    }
            }

            /* [Private Features] ... */
            // inline namespace {
                /* Class --- NOTE (Lapys) -> These structures should have no functionality outside their intended utility. Except the `to...` and/ or `valueOf` member functions. */
                    // Boolean --- WARN (Lapys) -> Do not use as an alternative to any `bool` data type variants within function parameters.
                    struct boolean {
                        // [Private]
                        private:
                            // Initialization > Value
                            unsigned char value : 1;

                        // [Public]
                        public:
                            // [Constructor]
                            inline boolean() { this -> value = 0; }
                            inline boolean(const char value) { this -> value = !!value; }
                            inline boolean(const char16_t value) { this -> value = !!value; }
                            inline boolean(const char32_t value) { this -> value = !!value; }
                            inline boolean(const double value) { this -> value = !!value; }
                            inline boolean(const float value) { this -> value = !!value; }
                            inline boolean(const int value) { this -> value = !!value; }
                            inline boolean(const long value) { this -> value = !!value; }
                            inline boolean(const long double value) { this -> value = !!value; }
                            inline boolean(const long long value) { this -> value = !!value; }
                            inline boolean(const short value) { this -> value = !!value; }
                            inline boolean(const signed char value) { this -> value = !!value; }
                            inline boolean(const unsigned char value) { this -> value = !!value; }
                            inline boolean(const unsigned int value) { this -> value = !!value; }
                            inline boolean(const unsigned long value) { this -> value = !!value; }
                            inline boolean(const unsigned long long value) { this -> value = !!value; }
                            inline boolean(const unsigned short value) { this -> value = !!value; }
                            inline boolean(const wchar_t value) { this -> value = !!value; }
                            inline boolean(boolean& value) { this -> value = value.value; }
                            inline boolean(const boolean& value) { this -> value = value.value; }
                            template <typename type> inline boolean(type& value) { this -> value = value ? 1 : 0; }

                            // [Destructor]
                            inline ~boolean() { this -> value = 0; }

                            // [Operator] > ... --- NOTE (Lapys) -> All arithmetic operations are restricted back to `boolean`.
                            inline const boolean operator +() { return this -> value; }
                            inline const boolean operator +(const char argument) { return !!argument || this -> value; } friend inline const boolean operator +(const char argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } friend inline const boolean operator +(const char argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }
                            inline const boolean operator +(const char16_t argument) { return !!argument || this -> value; } friend inline const boolean operator +(const char16_t argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } friend inline const boolean operator +(const char16_t argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }
                            inline const boolean operator +(const char32_t argument) { return !!argument || this -> value; } friend inline const boolean operator +(const char32_t argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } friend inline const boolean operator +(const char32_t argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }
                            inline const boolean operator +(const double argument) { return !!argument || this -> value; } friend inline const boolean operator +(const double argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } friend inline const boolean operator +(const double argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }
                            inline const boolean operator +(const float argument) { return !!argument || this -> value; } friend inline const boolean operator +(const float argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } friend inline const boolean operator +(const float argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }
                            inline const boolean operator +(const int argument) { return !!argument || this -> value; } friend inline const boolean operator +(const int argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } friend inline const boolean operator +(const int argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }
                            inline const boolean operator +(const long argument) { return !!argument || this -> value; } friend inline const boolean operator +(const long argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } friend inline const boolean operator +(const long argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }
                            inline const boolean operator +(const long double argument) { return !!argument || this -> value; } friend inline const boolean operator +(const long double argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } friend inline const boolean operator +(const long double argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }
                            inline const boolean operator +(const long long argument) { return !!argument || this -> value; } friend inline const boolean operator +(const long long argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } friend inline const boolean operator +(const long long argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }
                            inline const boolean operator +(const short argument) { return !!argument || this -> value; } friend inline const boolean operator +(const short argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } friend inline const boolean operator +(const short argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }
                            inline const boolean operator +(const signed char argument) { return !!argument || this -> value; } friend inline const boolean operator +(const signed char argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } friend inline const boolean operator +(const signed char argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }
                            inline const boolean operator +(const unsigned char argument) { return !!argument || this -> value; } friend inline const boolean operator +(const unsigned char argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } friend inline const boolean operator +(const unsigned char argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }
                            inline const boolean operator +(const unsigned int argument) { return !!argument || this -> value; } friend inline const boolean operator +(const unsigned int argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } friend inline const boolean operator +(const unsigned int argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }
                            inline const boolean operator +(const unsigned long argument) { return !!argument || this -> value; } friend inline const boolean operator +(const unsigned long argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } friend inline const boolean operator +(const unsigned long argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }
                            inline const boolean operator +(const unsigned long long argument) { return !!argument || this -> value; } friend inline const boolean operator +(const unsigned long long argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } friend inline const boolean operator +(const unsigned long long argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }
                            inline const boolean operator +(const unsigned short argument) { return !!argument || this -> value; } friend inline const boolean operator +(const unsigned short argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } friend inline const boolean operator +(const unsigned short argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }
                            inline const boolean operator +(const wchar_t argument) { return !!argument || this -> value; } friend inline const boolean operator +(const wchar_t argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } friend inline const boolean operator +(const wchar_t argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }
                            template <typename type> inline const boolean operator +(type& argument) { return !!argument || this -> value; } template <typename type> friend inline const boolean operator +(type& argumentA, boolean& argumentB) { return !!argumentA || argumentB.value; } template <typename type> friend inline const boolean operator +(type& argumentA, const boolean& argumentB) { return !!argumentA || argumentB.value; }

                            inline const boolean operator -() { return -(this -> value); }
                            inline const boolean operator -(const char argument) { return -!!argument ^ this -> value; } friend inline const boolean operator -(const char argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } friend inline const boolean operator -(const char argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }
                            inline const boolean operator -(const char16_t argument) { return -!!argument ^ this -> value; } friend inline const boolean operator -(const char16_t argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } friend inline const boolean operator -(const char16_t argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }
                            inline const boolean operator -(const char32_t argument) { return -!!argument ^ this -> value; } friend inline const boolean operator -(const char32_t argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } friend inline const boolean operator -(const char32_t argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }
                            inline const boolean operator -(const double argument) { return -!!argument ^ this -> value; } friend inline const boolean operator -(const double argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } friend inline const boolean operator -(const double argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }
                            inline const boolean operator -(const float argument) { return -!!argument ^ this -> value; } friend inline const boolean operator -(const float argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } friend inline const boolean operator -(const float argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }
                            inline const boolean operator -(const int argument) { return -!!argument ^ this -> value; } friend inline const boolean operator -(const int argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } friend inline const boolean operator -(const int argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }
                            inline const boolean operator -(const long argument) { return -!!argument ^ this -> value; } friend inline const boolean operator -(const long argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } friend inline const boolean operator -(const long argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }
                            inline const boolean operator -(const long double argument) { return -!!argument ^ this -> value; } friend inline const boolean operator -(const long double argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } friend inline const boolean operator -(const long double argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }
                            inline const boolean operator -(const long long argument) { return -!!argument ^ this -> value; } friend inline const boolean operator -(const long long argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } friend inline const boolean operator -(const long long argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }
                            inline const boolean operator -(const short argument) { return -!!argument ^ this -> value; } friend inline const boolean operator -(const short argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } friend inline const boolean operator -(const short argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }
                            inline const boolean operator -(const signed char argument) { return -!!argument ^ this -> value; } friend inline const boolean operator -(const signed char argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } friend inline const boolean operator -(const signed char argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }
                            inline const boolean operator -(const unsigned char argument) { return -!!argument ^ this -> value; } friend inline const boolean operator -(const unsigned char argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } friend inline const boolean operator -(const unsigned char argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }
                            inline const boolean operator -(const unsigned int argument) { return -!!argument ^ this -> value; } friend inline const boolean operator -(const unsigned int argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } friend inline const boolean operator -(const unsigned int argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }
                            inline const boolean operator -(const unsigned long argument) { return -!!argument ^ this -> value; } friend inline const boolean operator -(const unsigned long argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } friend inline const boolean operator -(const unsigned long argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }
                            inline const boolean operator -(const unsigned long long argument) { return -!!argument ^ this -> value; } friend inline const boolean operator -(const unsigned long long argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } friend inline const boolean operator -(const unsigned long long argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }
                            inline const boolean operator -(const unsigned short argument) { return -!!argument ^ this -> value; } friend inline const boolean operator -(const unsigned short argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } friend inline const boolean operator -(const unsigned short argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }
                            inline const boolean operator -(const wchar_t argument) { return -!!argument ^ this -> value; } friend inline const boolean operator -(const wchar_t argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } friend inline const boolean operator -(const wchar_t argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }
                            template <typename type> inline const boolean operator -(type& argument) { return -!!argument ^ this -> value; } template <typename type> friend inline const boolean operator -(type& argumentA, boolean& argumentB) { return -!!argumentA ^ argumentB.value; } template <typename type> friend inline const boolean operator -(type& argumentA, const boolean& argumentB) { return -!!argumentA ^ argumentB.value; }

                            inline const boolean operator *(const char argument) { return !!argument && this -> value; } friend inline const boolean operator *(const char argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } friend inline const boolean operator *(const char argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }
                            inline const boolean operator *(const char16_t argument) { return !!argument && this -> value; } friend inline const boolean operator *(const char16_t argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } friend inline const boolean operator *(const char16_t argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }
                            inline const boolean operator *(const char32_t argument) { return !!argument && this -> value; } friend inline const boolean operator *(const char32_t argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } friend inline const boolean operator *(const char32_t argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }
                            inline const boolean operator *(const double argument) { return !!argument && this -> value; } friend inline const boolean operator *(const double argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } friend inline const boolean operator *(const double argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }
                            inline const boolean operator *(const float argument) { return !!argument && this -> value; } friend inline const boolean operator *(const float argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } friend inline const boolean operator *(const float argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }
                            inline const boolean operator *(const int argument) { return !!argument && this -> value; } friend inline const boolean operator *(const int argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } friend inline const boolean operator *(const int argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }
                            inline const boolean operator *(const long argument) { return !!argument && this -> value; } friend inline const boolean operator *(const long argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } friend inline const boolean operator *(const long argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }
                            inline const boolean operator *(const long double argument) { return !!argument && this -> value; } friend inline const boolean operator *(const long double argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } friend inline const boolean operator *(const long double argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }
                            inline const boolean operator *(const long long argument) { return !!argument && this -> value; } friend inline const boolean operator *(const long long argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } friend inline const boolean operator *(const long long argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }
                            inline const boolean operator *(const short argument) { return !!argument && this -> value; } friend inline const boolean operator *(const short argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } friend inline const boolean operator *(const short argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }
                            inline const boolean operator *(const signed char argument) { return !!argument && this -> value; } friend inline const boolean operator *(const signed char argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } friend inline const boolean operator *(const signed char argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }
                            inline const boolean operator *(const unsigned char argument) { return !!argument && this -> value; } friend inline const boolean operator *(const unsigned char argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } friend inline const boolean operator *(const unsigned char argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }
                            inline const boolean operator *(const unsigned int argument) { return !!argument && this -> value; } friend inline const boolean operator *(const unsigned int argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } friend inline const boolean operator *(const unsigned int argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }
                            inline const boolean operator *(const unsigned long argument) { return !!argument && this -> value; } friend inline const boolean operator *(const unsigned long argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } friend inline const boolean operator *(const unsigned long argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }
                            inline const boolean operator *(const unsigned long long argument) { return !!argument && this -> value; } friend inline const boolean operator *(const unsigned long long argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } friend inline const boolean operator *(const unsigned long long argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }
                            inline const boolean operator *(const unsigned short argument) { return !!argument && this -> value; } friend inline const boolean operator *(const unsigned short argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } friend inline const boolean operator *(const unsigned short argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }
                            inline const boolean operator *(const wchar_t argument) { return !!argument && this -> value; } friend inline const boolean operator *(const wchar_t argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } friend inline const boolean operator *(const wchar_t argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }
                            template <typename type> inline const boolean operator *(type& argument) { return !!argument && this -> value; } template <typename type> friend inline const boolean operator *(type& argumentA, boolean& argumentB) { return !!argumentA && argumentB.value; } template <typename type> friend inline const boolean operator *(type& argumentA, const boolean& argumentB) { return !!argumentA && argumentB.value; }

                            inline const boolean operator /(const char argument) { return !!((this -> value) / argument); } friend inline const boolean operator /(const char argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } friend inline const boolean operator /(const char argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }
                            inline const boolean operator /(const char16_t argument) { return !!((this -> value) / argument); } friend inline const boolean operator /(const char16_t argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } friend inline const boolean operator /(const char16_t argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }
                            inline const boolean operator /(const char32_t argument) { return !!((this -> value) / argument); } friend inline const boolean operator /(const char32_t argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } friend inline const boolean operator /(const char32_t argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }
                            inline const boolean operator /(const double argument) { return !!((this -> value) / argument); } friend inline const boolean operator /(const double argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } friend inline const boolean operator /(const double argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }
                            inline const boolean operator /(const float argument) { return !!((this -> value) / argument); } friend inline const boolean operator /(const float argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } friend inline const boolean operator /(const float argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }
                            inline const boolean operator /(const int argument) { return !!((this -> value) / argument); } friend inline const boolean operator /(const int argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } friend inline const boolean operator /(const int argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }
                            inline const boolean operator /(const long argument) { return !!((this -> value) / argument); } friend inline const boolean operator /(const long argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } friend inline const boolean operator /(const long argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }
                            inline const boolean operator /(const long double argument) { return !!((this -> value) / argument); } friend inline const boolean operator /(const long double argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } friend inline const boolean operator /(const long double argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }
                            inline const boolean operator /(const long long argument) { return !!((this -> value) / argument); } friend inline const boolean operator /(const long long argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } friend inline const boolean operator /(const long long argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }
                            inline const boolean operator /(const short argument) { return !!((this -> value) / argument); } friend inline const boolean operator /(const short argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } friend inline const boolean operator /(const short argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }
                            inline const boolean operator /(const signed char argument) { return !!((this -> value) / argument); } friend inline const boolean operator /(const signed char argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } friend inline const boolean operator /(const signed char argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }
                            inline const boolean operator /(const unsigned char argument) { return !!((this -> value) / argument); } friend inline const boolean operator /(const unsigned char argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } friend inline const boolean operator /(const unsigned char argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }
                            inline const boolean operator /(const unsigned int argument) { return !!((this -> value) / argument); } friend inline const boolean operator /(const unsigned int argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } friend inline const boolean operator /(const unsigned int argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }
                            inline const boolean operator /(const unsigned long argument) { return !!((this -> value) / argument); } friend inline const boolean operator /(const unsigned long argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } friend inline const boolean operator /(const unsigned long argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }
                            inline const boolean operator /(const unsigned long long argument) { return !!((this -> value) / argument); } friend inline const boolean operator /(const unsigned long long argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } friend inline const boolean operator /(const unsigned long long argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }
                            inline const boolean operator /(const unsigned short argument) { return !!((this -> value) / argument); } friend inline const boolean operator /(const unsigned short argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } friend inline const boolean operator /(const unsigned short argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }
                            inline const boolean operator /(const wchar_t argument) { return !!((this -> value) / argument); } friend inline const boolean operator /(const wchar_t argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } friend inline const boolean operator /(const wchar_t argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }
                            template <typename type> inline const boolean operator /(type& argument) { return !!((this -> value) / argument); } template <typename type> friend inline const boolean operator /(type& argumentA, boolean& argumentB) { return !!(argumentA / argumentB.value); } template <typename type> friend inline const boolean operator /(type& argumentA, const boolean& argumentB) { return !!(argumentA / argumentB.value); }

                            inline const boolean operator %(const char argument) { return !!((this -> value) % argument); } friend inline const boolean operator %(const char argumentA, boolean& argumentB) { return !!(argumentA % argumentB.value); } friend inline const boolean operator %(const char argumentA, const boolean& argumentB) { return !!(argumentA % argumentB.value); }
                            inline const boolean operator %(const char16_t argument) { return !!((this -> value) % argument); } friend inline const boolean operator %(const char16_t argumentA, boolean& argumentB) { return !!(argumentA % argumentB.value); } friend inline const boolean operator %(const char16_t argumentA, const boolean& argumentB) { return !!(argumentA % argumentB.value); }
                            inline const boolean operator %(const char32_t argument) { return !!((this -> value) % argument); } friend inline const boolean operator %(const char32_t argumentA, boolean& argumentB) { return !!(argumentA % argumentB.value); } friend inline const boolean operator %(const char32_t argumentA, const boolean& argumentB) { return !!(argumentA % argumentB.value); }
                            const boolean operator %(const double argument) { return !!LDKM::mod(this -> value, argument); } friend const boolean operator %(const double argumentA, boolean& argumentB) { return !!LDKM::mod(argumentA, argumentB.value); } friend const boolean operator %(const double argumentA, const boolean& argumentB) { return !!LDKM::mod(argumentA, argumentB.value); }
                            const boolean operator %(const float argument) { return !!LDKM::mod(this -> value, argument); } friend const boolean operator %(const float argumentA, boolean& argumentB) { return !!LDKM::mod(argumentA, argumentB.value); } friend const boolean operator %(const float argumentA, const boolean& argumentB) { return !!LDKM::mod(argumentA, argumentB.value); }
                            inline const boolean operator %(const int argument) { return !!((this -> value) % argument); } friend inline const boolean operator %(const int argumentA, boolean& argumentB) { return !!(argumentA % argumentB.value); } friend inline const boolean operator %(const int argumentA, const boolean& argumentB) { return !!(argumentA % argumentB.value); }
                            inline const boolean operator %(const long argument) { return !!((this -> value) % argument); } friend inline const boolean operator %(const long argumentA, boolean& argumentB) { return !!(argumentA % argumentB.value); } friend inline const boolean operator %(const long argumentA, const boolean& argumentB) { return !!(argumentA % argumentB.value); }
                            const boolean operator %(const long double argument) { return !!LDKM::mod(this -> value, argument); } friend const boolean operator %(const long double argumentA, boolean& argumentB) { return !!LDKM::mod(argumentA, argumentB.value); } friend const boolean operator %(const long double argumentA, const boolean& argumentB) { return !!LDKM::mod(argumentA, argumentB.value); }
                            inline const boolean operator %(const long long argument) { return !!((this -> value) % argument); } friend inline const boolean operator %(const long long argumentA, boolean& argumentB) { return !!(argumentA % argumentB.value); } friend inline const boolean operator %(const long long argumentA, const boolean& argumentB) { return !!(argumentA % argumentB.value); }
                            inline const boolean operator %(const short argument) { return !!((this -> value) % argument); } friend inline const boolean operator %(const short argumentA, boolean& argumentB) { return !!(argumentA % argumentB.value); } friend inline const boolean operator %(const short argumentA, const boolean& argumentB) { return !!(argumentA % argumentB.value); }
                            inline const boolean operator %(const signed char argument) { return !!((this -> value) % argument); } friend inline const boolean operator %(const signed char argumentA, boolean& argumentB) { return !!(argumentA % argumentB.value); } friend inline const boolean operator %(const signed char argumentA, const boolean& argumentB) { return !!(argumentA % argumentB.value); }
                            inline const boolean operator %(const unsigned char argument) { return !!((this -> value) % argument); } friend inline const boolean operator %(const unsigned char argumentA, boolean& argumentB) { return !!(argumentA % argumentB.value); } friend inline const boolean operator %(const unsigned char argumentA, const boolean& argumentB) { return !!(argumentA % argumentB.value); }
                            inline const boolean operator %(const unsigned int argument) { return !!((this -> value) % argument); } friend inline const boolean operator %(const unsigned int argumentA, boolean& argumentB) { return !!(argumentA % argumentB.value); } friend inline const boolean operator %(const unsigned int argumentA, const boolean& argumentB) { return !!(argumentA % argumentB.value); }
                            inline const boolean operator %(const unsigned long argument) { return !!((this -> value) % argument); } friend inline const boolean operator %(const unsigned long argumentA, boolean& argumentB) { return !!(argumentA % argumentB.value); } friend inline const boolean operator %(const unsigned long argumentA, const boolean& argumentB) { return !!(argumentA % argumentB.value); }
                            inline const boolean operator %(const unsigned long long argument) { return !!((this -> value) % argument); } friend inline const boolean operator %(const unsigned long long argumentA, boolean& argumentB) { return !!(argumentA % argumentB.value); } friend inline const boolean operator %(const unsigned long long argumentA, const boolean& argumentB) { return !!(argumentA % argumentB.value); }
                            inline const boolean operator %(const unsigned short argument) { return !!((this -> value) % argument); } friend inline const boolean operator %(const unsigned short argumentA, boolean& argumentB) { return !!(argumentA % argumentB.value); } friend inline const boolean operator %(const unsigned short argumentA, const boolean& argumentB) { return !!(argumentA % argumentB.value); }
                            inline const boolean operator %(const wchar_t argument) { return !!((this -> value) % argument); } friend inline const boolean operator %(const wchar_t argumentA, boolean& argumentB) { return !!(argumentA % argumentB.value); } friend inline const boolean operator %(const wchar_t argumentA, const boolean& argumentB) { return !!(argumentA % argumentB.value); }
                            template <typename type> inline const boolean operator %(type& argument) { return !!((this -> value) % argument); } template <typename type> friend inline const boolean operator %(type& argumentA, boolean& argumentB) { return !!(argumentA % argumentB.value); } template <typename type> friend inline const boolean operator %(type& argumentA, const boolean& argumentB) { return !!(argumentA % argumentB.value); }

                            inline const boolean operator ^(const char argument) { return !!(argument ^ this -> value); } friend inline const boolean operator ^(const char argumentA, boolean& argumentB) { return !!(argumentA ^ argumentB.value); } friend inline const boolean operator ^(const char argumentA, const boolean& argumentB) { return !!(argumentA ^ argumentB.value); }
                            inline const boolean operator ^(const char16_t argument) { return !!(argument ^ this -> value); } friend inline const boolean operator ^(const char16_t argumentA, boolean& argumentB) { return !!(argumentA ^ argumentB.value); } friend inline const boolean operator ^(const char16_t argumentA, const boolean& argumentB) { return !!(argumentA ^ argumentB.value); }
                            inline const boolean operator ^(const char32_t argument) { return !!(argument ^ this -> value); } friend inline const boolean operator ^(const char32_t argumentA, boolean& argumentB) { return !!(argumentA ^ argumentB.value); } friend inline const boolean operator ^(const char32_t argumentA, const boolean& argumentB) { return !!(argumentA ^ argumentB.value); }
                            const boolean operator ^(const double argument) { return !!(LDKF::toInteger(argument) ^ (this -> value)); } friend const boolean operator ^(const double argumentA, boolean& argumentB) { return !!(LDKF::toInteger(argumentA) ^ argumentB.value); } friend const boolean operator ^(const double argumentA, const boolean& argumentB) { return !!(LDKF::toInteger(argumentA) ^ argumentB.value); }
                            const boolean operator ^(const float argument) { return !!(LDKF::toInteger(argument) ^ (this -> value)); } friend const boolean operator ^(const float argumentA, boolean& argumentB) { return !!(LDKF::toInteger(argumentA) ^ argumentB.value); } friend const boolean operator ^(const float argumentA, const boolean& argumentB) { return !!(LDKF::toInteger(argumentA) ^ argumentB.value); }
                            inline const boolean operator ^(const int argument) { return !!(argument ^ this -> value); } friend inline const boolean operator ^(const int argumentA, boolean& argumentB) { return !!(argumentA ^ argumentB.value); } friend inline const boolean operator ^(const int argumentA, const boolean& argumentB) { return !!(argumentA ^ argumentB.value); }
                            inline const boolean operator ^(const long argument) { return !!(argument ^ this -> value); } friend inline const boolean operator ^(const long argumentA, boolean& argumentB) { return !!(argumentA ^ argumentB.value); } friend inline const boolean operator ^(const long argumentA, const boolean& argumentB) { return !!(argumentA ^ argumentB.value); }
                            const boolean operator ^(const long double argument) { return !!(LDKF::toInteger(argument) ^ (this -> value)); } friend const boolean operator ^(const long double argumentA, boolean& argumentB) { return !!(LDKF::toInteger(argumentA) ^ argumentB.value); } friend const boolean operator ^(const long double argumentA, const boolean& argumentB) { return !!(LDKF::toInteger(argumentA) ^ argumentB.value); }
                            inline const boolean operator ^(const long long argument) { return !!(argument ^ this -> value); } friend inline const boolean operator ^(const long long argumentA, boolean& argumentB) { return !!(argumentA ^ argumentB.value); } friend inline const boolean operator ^(const long long argumentA, const boolean& argumentB) { return !!(argumentA ^ argumentB.value); }
                            inline const boolean operator ^(const short argument) { return !!(argument ^ this -> value); } friend inline const boolean operator ^(const short argumentA, boolean& argumentB) { return !!(argumentA ^ argumentB.value); } friend inline const boolean operator ^(const short argumentA, const boolean& argumentB) { return !!(argumentA ^ argumentB.value); }
                            inline const boolean operator ^(const signed char argument) { return !!(argument ^ this -> value); } friend inline const boolean operator ^(const signed char argumentA, boolean& argumentB) { return !!(argumentA ^ argumentB.value); } friend inline const boolean operator ^(const signed char argumentA, const boolean& argumentB) { return !!(argumentA ^ argumentB.value); }
                            inline const boolean operator ^(const unsigned char argument) { return !!(argument ^ this -> value); } friend inline const boolean operator ^(const unsigned char argumentA, boolean& argumentB) { return !!(argumentA ^ argumentB.value); } friend inline const boolean operator ^(const unsigned char argumentA, const boolean& argumentB) { return !!(argumentA ^ argumentB.value); }
                            inline const boolean operator ^(const unsigned int argument) { return !!(argument ^ this -> value); } friend inline const boolean operator ^(const unsigned int argumentA, boolean& argumentB) { return !!(argumentA ^ argumentB.value); } friend inline const boolean operator ^(const unsigned int argumentA, const boolean& argumentB) { return !!(argumentA ^ argumentB.value); }
                            inline const boolean operator ^(const unsigned long argument) { return !!(argument ^ this -> value); }
                            friend inline const boolean operator ^(const unsigned long argumentA, boolean& argumentB) { return !!(argumentA ^ argumentB.value); }
                            friend inline const boolean operator ^(const unsigned long argumentA, const boolean& argumentB) { return !!(argumentA ^ argumentB.value); }
                            inline const boolean operator ^(const unsigned long long argument) { return !!(argument ^ this -> value); } friend inline const boolean operator ^(const unsigned long long argumentA, boolean& argumentB) { return !!(argumentA ^ argumentB.value); } friend inline const boolean operator ^(const unsigned long long argumentA, const boolean& argumentB) { return !!(argumentA ^ argumentB.value); }
                            inline const boolean operator ^(const unsigned short argument) { return !!(argument ^ this -> value); } friend inline const boolean operator ^(const unsigned short argumentA, boolean& argumentB) { return !!(argumentA ^ argumentB.value); } friend inline const boolean operator ^(const unsigned short argumentA, const boolean& argumentB) { return !!(argumentA ^ argumentB.value); }
                            inline const boolean operator ^(const wchar_t argument) { return !!(argument ^ this -> value); } friend inline const boolean operator ^(const wchar_t argumentA, boolean& argumentB) { return !!(argumentA ^ argumentB.value); } friend inline const boolean operator ^(const wchar_t argumentA, const boolean& argumentB) { return !!(argumentA ^ argumentB.value); }
                            template <typename type> inline const boolean operator ^(type& argument) { return !!(argument ^ this -> value); } template <typename type> friend inline const boolean operator ^(type& argumentA, boolean& argumentB) { return !!(argumentA ^ argumentB.value); } template <typename type> friend inline const boolean operator ^(type& argumentA, const boolean& argumentB) { return !!(argumentA ^ argumentB.value); }

                            inline const boolean operator ~() { return ~((signed char) this -> value); }
                            inline const boolean operator !() { return this -> value ? 0 : 1; }
                            inline boolean& operator =(const char argument) { this -> value = !!argument; return *this; } inline boolean& operator =(const char16_t argument) { this -> value = !!argument; return *this; } inline boolean& operator =(const char32_t argument) { this -> value = !!argument; return *this; } inline boolean& operator =(const double argument) { this -> value = !!argument; return *this; } inline boolean& operator =(const float argument) { this -> value = !!argument; return *this; } inline boolean& operator =(const int argument) { this -> value = !!argument; return *this; } inline boolean& operator =(const long argument) { this -> value = !!argument; return *this; } inline boolean& operator =(const long double argument) { this -> value = !!argument; return *this; } inline boolean& operator =(const long long argument) { this -> value = !!argument; return *this; } inline boolean& operator =(const short argument) { this -> value = !!argument; return *this; } inline boolean& operator =(const signed char argument) { this -> value = !!argument; return *this; } inline boolean& operator =(const unsigned char argument) { this -> value = !!argument; return *this; } inline boolean& operator =(const unsigned int argument) { this -> value = !!argument; return *this; } inline boolean& operator =(const unsigned long argument) { this -> value = !!argument; return *this; } inline boolean& operator =(const unsigned long long argument) { this -> value = !!argument; return *this; } inline boolean& operator =(const unsigned short argument) { this -> value = !!argument; return *this; } inline boolean& operator =(const wchar_t argument) { this -> value = !!argument; return *this; }

                            inline const boolean operator <(const char argument) { return !argument && !!(this -> value); } friend inline const boolean operator <(const char argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } friend inline const boolean operator <(const char argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }
                            inline const boolean operator <(const char16_t argument) { return !argument && !!(this -> value); } friend inline const boolean operator <(const char16_t argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } friend inline const boolean operator <(const char16_t argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }
                            inline const boolean operator <(const char32_t argument) { return !argument && !!(this -> value); } friend inline const boolean operator <(const char32_t argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } friend inline const boolean operator <(const char32_t argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }
                            inline const boolean operator <(const double argument) { return !argument && !!(this -> value); } friend inline const boolean operator <(const double argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } friend inline const boolean operator <(const double argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }
                            inline const boolean operator <(const float argument) { return !argument && !!(this -> value); } friend inline const boolean operator <(const float argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } friend inline const boolean operator <(const float argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }
                            inline const boolean operator <(const int argument) { return !argument && !!(this -> value); } friend inline const boolean operator <(const int argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } friend inline const boolean operator <(const int argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }
                            inline const boolean operator <(const long argument) { return !argument && !!(this -> value); } friend inline const boolean operator <(const long argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } friend inline const boolean operator <(const long argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }
                            inline const boolean operator <(const long double argument) { return !argument && !!(this -> value); } friend inline const boolean operator <(const long double argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } friend inline const boolean operator <(const long double argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }
                            inline const boolean operator <(const long long argument) { return !argument && !!(this -> value); } friend inline const boolean operator <(const long long argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } friend inline const boolean operator <(const long long argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }
                            inline const boolean operator <(const short argument) { return !argument && !!(this -> value); } friend inline const boolean operator <(const short argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } friend inline const boolean operator <(const short argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }
                            inline const boolean operator <(const signed char argument) { return !argument && !!(this -> value); } friend inline const boolean operator <(const signed char argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } friend inline const boolean operator <(const signed char argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }
                            inline const boolean operator <(const unsigned char argument) { return !argument && !!(this -> value); } friend inline const boolean operator <(const unsigned char argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } friend inline const boolean operator <(const unsigned char argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }
                            inline const boolean operator <(const unsigned int argument) { return !argument && !!(this -> value); } friend inline const boolean operator <(const unsigned int argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } friend inline const boolean operator <(const unsigned int argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }
                            inline const boolean operator <(const unsigned long argument) { return !argument && !!(this -> value); } friend inline const boolean operator <(const unsigned long argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } friend inline const boolean operator <(const unsigned long argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }
                            inline const boolean operator <(const unsigned long long argument) { return !argument && !!(this -> value); } friend inline const boolean operator <(const unsigned long long argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } friend inline const boolean operator <(const unsigned long long argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }
                            inline const boolean operator <(const unsigned short argument) { return !argument && !!(this -> value); } friend inline const boolean operator <(const unsigned short argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } friend inline const boolean operator <(const unsigned short argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }
                            inline const boolean operator <(const wchar_t argument) { return !argument && !!(this -> value); } friend inline const boolean operator <(const wchar_t argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } friend inline const boolean operator <(const wchar_t argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }
                            template <typename type> inline const boolean operator <(type& argument) { return !argument && !!(this -> value); } template <typename type> friend inline const boolean operator <(type& argumentA, boolean& argumentB) { return !argumentA && !!argumentB.value; } template <typename type> friend inline const boolean operator <(type& argumentA, const boolean& argumentB) { return !argumentA && !!argumentB.value; }

                            inline const boolean operator >(const char argument) { return !!argument && !(this -> value); } friend inline const boolean operator >(const char argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } friend inline const boolean operator >(const char argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }
                            inline const boolean operator >(const char16_t argument) { return !!argument && !(this -> value); } friend inline const boolean operator >(const char16_t argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } friend inline const boolean operator >(const char16_t argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }
                            inline const boolean operator >(const char32_t argument) { return !!argument && !(this -> value); } friend inline const boolean operator >(const char32_t argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } friend inline const boolean operator >(const char32_t argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }
                            inline const boolean operator >(const double argument) { return !!argument && !(this -> value); } friend inline const boolean operator >(const double argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } friend inline const boolean operator >(const double argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }
                            inline const boolean operator >(const float argument) { return !!argument && !(this -> value); } friend inline const boolean operator >(const float argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } friend inline const boolean operator >(const float argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }
                            inline const boolean operator >(const int argument) { return !!argument && !(this -> value); } friend inline const boolean operator >(const int argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } friend inline const boolean operator >(const int argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }
                            inline const boolean operator >(const long argument) { return !!argument && !(this -> value); } friend inline const boolean operator >(const long argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } friend inline const boolean operator >(const long argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }
                            inline const boolean operator >(const long double argument) { return !!argument && !(this -> value); } friend inline const boolean operator >(const long double argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } friend inline const boolean operator >(const long double argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }
                            inline const boolean operator >(const long long argument) { return !!argument && !(this -> value); } friend inline const boolean operator >(const long long argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } friend inline const boolean operator >(const long long argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }
                            inline const boolean operator >(const short argument) { return !!argument && !(this -> value); } friend inline const boolean operator >(const short argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } friend inline const boolean operator >(const short argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }
                            inline const boolean operator >(const signed char argument) { return !!argument && !(this -> value); } friend inline const boolean operator >(const signed char argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } friend inline const boolean operator >(const signed char argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }
                            inline const boolean operator >(const unsigned char argument) { return !!argument && !(this -> value); } friend inline const boolean operator >(const unsigned char argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } friend inline const boolean operator >(const unsigned char argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }
                            inline const boolean operator >(const unsigned int argument) { return !!argument && !(this -> value); } friend inline const boolean operator >(const unsigned int argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } friend inline const boolean operator >(const unsigned int argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }
                            inline const boolean operator >(const unsigned long argument) { return !!argument && !(this -> value); } friend inline const boolean operator >(const unsigned long argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } friend inline const boolean operator >(const unsigned long argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }
                            inline const boolean operator >(const unsigned long long argument) { return !!argument && !(this -> value); } friend inline const boolean operator >(const unsigned long long argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } friend inline const boolean operator >(const unsigned long long argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }
                            inline const boolean operator >(const unsigned short argument) { return !!argument && !(this -> value); } friend inline const boolean operator >(const unsigned short argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } friend inline const boolean operator >(const unsigned short argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }
                            inline const boolean operator >(const wchar_t argument) { return !!argument && !(this -> value); } friend inline const boolean operator >(const wchar_t argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } friend inline const boolean operator >(const wchar_t argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }
                            template <typename type> inline const boolean operator >(type& argument) { return !!argument && !(this -> value); } template <typename type> friend inline const boolean operator >(type& argumentA, boolean& argumentB) { return !!argumentA && !argumentB.value; } template <typename type> friend inline const boolean operator >(type& argumentA, const boolean& argumentB) { return !!argumentA && !argumentB.value; }

                            inline const boolean operator <=(const char argument) { return !(!!argument && !(this -> value)); } friend inline const boolean operator <=(const char argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } friend inline const boolean operator <=(const char argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }
                            inline const boolean operator <=(const char16_t argument) { return !(!!argument && !(this -> value)); } friend inline const boolean operator <=(const char16_t argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } friend inline const boolean operator <=(const char16_t argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }
                            inline const boolean operator <=(const char32_t argument) { return !(!!argument && !(this -> value)); } friend inline const boolean operator <=(const char32_t argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } friend inline const boolean operator <=(const char32_t argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }
                            inline const boolean operator <=(const double argument) { return !(!!argument && !(this -> value)); } friend inline const boolean operator <=(const double argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } friend inline const boolean operator <=(const double argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }
                            inline const boolean operator <=(const float argument) { return !(!!argument && !(this -> value)); } friend inline const boolean operator <=(const float argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } friend inline const boolean operator <=(const float argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }
                            inline const boolean operator <=(const int argument) { return !(!!argument && !(this -> value)); } friend inline const boolean operator <=(const int argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } friend inline const boolean operator <=(const int argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }
                            inline const boolean operator <=(const long argument) { return !(!!argument && !(this -> value)); } friend inline const boolean operator <=(const long argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } friend inline const boolean operator <=(const long argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }
                            inline const boolean operator <=(const long double argument) { return !(!!argument && !(this -> value)); } friend inline const boolean operator <=(const long double argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } friend inline const boolean operator <=(const long double argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }
                            inline const boolean operator <=(const long long argument) { return !(!!argument && !(this -> value)); } friend inline const boolean operator <=(const long long argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } friend inline const boolean operator <=(const long long argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }
                            inline const boolean operator <=(const short argument) { return !(!!argument && !(this -> value)); } friend inline const boolean operator <=(const short argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } friend inline const boolean operator <=(const short argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }
                            inline const boolean operator <=(const signed char argument) { return !(!!argument && !(this -> value)); } friend inline const boolean operator <=(const signed char argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } friend inline const boolean operator <=(const signed char argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }
                            inline const boolean operator <=(const unsigned char argument) { return !(!!argument && !(this -> value)); } friend inline const boolean operator <=(const unsigned char argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } friend inline const boolean operator <=(const unsigned char argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }
                            inline const boolean operator <=(const unsigned int argument) { return !(!!argument && !(this -> value)); } friend inline const boolean operator <=(const unsigned int argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } friend inline const boolean operator <=(const unsigned int argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }
                            inline const boolean operator <=(const unsigned long argument) { return !(!!argument && !(this -> value)); } friend inline const boolean operator <=(const unsigned long argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } friend inline const boolean operator <=(const unsigned long argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }
                            inline const boolean operator <=(const unsigned long long argument) { return !(!!argument && !(this -> value)); } friend inline const boolean operator <=(const unsigned long long argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } friend inline const boolean operator <=(const unsigned long long argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }
                            inline const boolean operator <=(const unsigned short argument) { return !(!!argument && !(this -> value)); } friend inline const boolean operator <=(const unsigned short argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } friend inline const boolean operator <=(const unsigned short argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }
                            inline const boolean operator <=(const wchar_t argument) { return !(!!argument && !(this -> value)); } friend inline const boolean operator <=(const wchar_t argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } friend inline const boolean operator <=(const wchar_t argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }
                            template <typename type> inline const boolean operator <=(type& argument) { return !(!!argument && !(this -> value)); } template <typename type> friend inline const boolean operator <=(type& argumentA, boolean& argumentB) { return !(!!argumentA && !argumentB.value); } template <typename type> friend inline const boolean operator <=(type& argumentA, const boolean& argumentB) { return !(!!argumentA && !argumentB.value); }

                            inline const boolean operator >=(const char argument) { return !(!argument && !!(this -> value)); } friend inline const boolean operator >=(const char argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } friend inline const boolean operator >=(const char argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }
                            inline const boolean operator >=(const char16_t argument) { return !(!argument && !!(this -> value)); } friend inline const boolean operator >=(const char16_t argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } friend inline const boolean operator >=(const char16_t argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }
                            inline const boolean operator >=(const char32_t argument) { return !(!argument && !!(this -> value)); } friend inline const boolean operator >=(const char32_t argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } friend inline const boolean operator >=(const char32_t argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }
                            inline const boolean operator >=(const double argument) { return !(!argument && !!(this -> value)); } friend inline const boolean operator >=(const double argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } friend inline const boolean operator >=(const double argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }
                            inline const boolean operator >=(const float argument) { return !(!argument && !!(this -> value)); } friend inline const boolean operator >=(const float argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } friend inline const boolean operator >=(const float argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }
                            inline const boolean operator >=(const int argument) { return !(!argument && !!(this -> value)); } friend inline const boolean operator >=(const int argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } friend inline const boolean operator >=(const int argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }
                            inline const boolean operator >=(const long argument) { return !(!argument && !!(this -> value)); } friend inline const boolean operator >=(const long argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } friend inline const boolean operator >=(const long argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }
                            inline const boolean operator >=(const long double argument) { return !(!argument && !!(this -> value)); } friend inline const boolean operator >=(const long double argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } friend inline const boolean operator >=(const long double argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }
                            inline const boolean operator >=(const long long argument) { return !(!argument && !!(this -> value)); } friend inline const boolean operator >=(const long long argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } friend inline const boolean operator >=(const long long argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }
                            inline const boolean operator >=(const short argument) { return !(!argument && !!(this -> value)); } friend inline const boolean operator >=(const short argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } friend inline const boolean operator >=(const short argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }
                            inline const boolean operator >=(const signed char argument) { return !(!argument && !!(this -> value)); } friend inline const boolean operator >=(const signed char argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } friend inline const boolean operator >=(const signed char argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }
                            inline const boolean operator >=(const unsigned char argument) { return !(!argument && !!(this -> value)); } friend inline const boolean operator >=(const unsigned char argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } friend inline const boolean operator >=(const unsigned char argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }
                            inline const boolean operator >=(const unsigned int argument) { return !(!argument && !!(this -> value)); } friend inline const boolean operator >=(const unsigned int argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } friend inline const boolean operator >=(const unsigned int argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }
                            inline const boolean operator >=(const unsigned long argument) { return !(!argument && !!(this -> value)); } friend inline const boolean operator >=(const unsigned long argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } friend inline const boolean operator >=(const unsigned long argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }
                            inline const boolean operator >=(const unsigned long long argument) { return !(!argument && !!(this -> value)); } friend inline const boolean operator >=(const unsigned long long argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } friend inline const boolean operator >=(const unsigned long long argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }
                            inline const boolean operator >=(const unsigned short argument) { return !(!argument && !!(this -> value)); } friend inline const boolean operator >=(const unsigned short argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } friend inline const boolean operator >=(const unsigned short argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }
                            inline const boolean operator >=(const wchar_t argument) { return !(!argument && !!(this -> value)); } friend inline const boolean operator >=(const wchar_t argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } friend inline const boolean operator >=(const wchar_t argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }
                            template <typename type> inline const boolean operator >=(type& argument) { return !(!argument && !!(this -> value)); } template <typename type> friend inline const boolean operator >=(type& argumentA, boolean& argumentB) { return !(!argumentA && !!argumentB.value); } template <typename type> friend inline const boolean operator >=(type& argumentA, const boolean& argumentB) { return !(!argumentA && !!argumentB.value); }

                            inline boolean& operator ++() { this -> value = 1; return *this; } inline boolean& operator ++(int) { this -> value = 1; return *this; }
                            inline boolean& operator --() { this -> value = 0; return *this; } inline boolean& operator --(int) { this -> value = 0; return *this; }

                            inline const boolean operator ==(const char argument) { return this -> value == !!argument; } friend inline const boolean operator ==(const char argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } friend inline const boolean operator ==(const char argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }
                            inline const boolean operator ==(const char16_t argument) { return this -> value == !!argument; } friend inline const boolean operator ==(const char16_t argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } friend inline const boolean operator ==(const char16_t argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }
                            inline const boolean operator ==(const char32_t argument) { return this -> value == !!argument; } friend inline const boolean operator ==(const char32_t argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } friend inline const boolean operator ==(const char32_t argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }
                            inline const boolean operator ==(const double argument) { return this -> value == !!argument; } friend inline const boolean operator ==(const double argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } friend inline const boolean operator ==(const double argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }
                            inline const boolean operator ==(const float argument) { return this -> value == !!argument; } friend inline const boolean operator ==(const float argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } friend inline const boolean operator ==(const float argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }
                            inline const boolean operator ==(const int argument) { return this -> value == !!argument; } friend inline const boolean operator ==(const int argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } friend inline const boolean operator ==(const int argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }
                            inline const boolean operator ==(const long argument) { return this -> value == !!argument; } friend inline const boolean operator ==(const long argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } friend inline const boolean operator ==(const long argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }
                            inline const boolean operator ==(const long double argument) { return this -> value == !!argument; } friend inline const boolean operator ==(const long double argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } friend inline const boolean operator ==(const long double argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }
                            inline const boolean operator ==(const long long argument) { return this -> value == !!argument; } friend inline const boolean operator ==(const long long argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } friend inline const boolean operator ==(const long long argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }
                            inline const boolean operator ==(const short argument) { return this -> value == !!argument; } friend inline const boolean operator ==(const short argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } friend inline const boolean operator ==(const short argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }
                            inline const boolean operator ==(const signed char argument) { return this -> value == !!argument; } friend inline const boolean operator ==(const signed char argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } friend inline const boolean operator ==(const signed char argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }
                            inline const boolean operator ==(const unsigned char argument) { return this -> value == !!argument; } friend inline const boolean operator ==(const unsigned char argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } friend inline const boolean operator ==(const unsigned char argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }
                            inline const boolean operator ==(const unsigned int argument) { return this -> value == !!argument; } friend inline const boolean operator ==(const unsigned int argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } friend inline const boolean operator ==(const unsigned int argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }
                            inline const boolean operator ==(const unsigned long argument) { return this -> value == !!argument; } friend inline const boolean operator ==(const unsigned long argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } friend inline const boolean operator ==(const unsigned long argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }
                            inline const boolean operator ==(const unsigned long long argument) { return this -> value == !!argument; } friend inline const boolean operator ==(const unsigned long long argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } friend inline const boolean operator ==(const unsigned long long argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }
                            inline const boolean operator ==(const unsigned short argument) { return this -> value == !!argument; } friend inline const boolean operator ==(const unsigned short argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } friend inline const boolean operator ==(const unsigned short argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }
                            inline const boolean operator ==(const wchar_t argument) { return this -> value == !!argument; } friend inline const boolean operator ==(const wchar_t argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } friend inline const boolean operator ==(const wchar_t argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }
                            template <typename type> inline const boolean operator ==(type& argument) { return this -> value == !!argument; } template <typename type> friend inline const boolean operator ==(type& argumentA, boolean& argumentB) { return argumentB.value == !!argumentA; } template <typename type> friend inline const boolean operator ==(type& argumentA, const boolean& argumentB) { return argumentB.value == !!argumentA; }

                            inline const boolean operator !=(const char argument) { return this -> value ^ !!argument; } friend inline const boolean operator !=(const char argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } friend inline const boolean operator !=(const char argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }
                            inline const boolean operator !=(const char16_t argument) { return this -> value ^ !!argument; } friend inline const boolean operator !=(const char16_t argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } friend inline const boolean operator !=(const char16_t argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }
                            inline const boolean operator !=(const char32_t argument) { return this -> value ^ !!argument; } friend inline const boolean operator !=(const char32_t argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } friend inline const boolean operator !=(const char32_t argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }
                            inline const boolean operator !=(const double argument) { return this -> value ^ !!argument; } friend inline const boolean operator !=(const double argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } friend inline const boolean operator !=(const double argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }
                            inline const boolean operator !=(const float argument) { return this -> value ^ !!argument; } friend inline const boolean operator !=(const float argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } friend inline const boolean operator !=(const float argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }
                            inline const boolean operator !=(const int argument) { return this -> value ^ !!argument; } friend inline const boolean operator !=(const int argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } friend inline const boolean operator !=(const int argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }
                            inline const boolean operator !=(const long argument) { return this -> value ^ !!argument; } friend inline const boolean operator !=(const long argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } friend inline const boolean operator !=(const long argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }
                            inline const boolean operator !=(const long double argument) { return this -> value ^ !!argument; } friend inline const boolean operator !=(const long double argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } friend inline const boolean operator !=(const long double argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }
                            inline const boolean operator !=(const long long argument) { return this -> value ^ !!argument; } friend inline const boolean operator !=(const long long argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } friend inline const boolean operator !=(const long long argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }
                            inline const boolean operator !=(const short argument) { return this -> value ^ !!argument; } friend inline const boolean operator !=(const short argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } friend inline const boolean operator !=(const short argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }
                            inline const boolean operator !=(const signed char argument) { return this -> value ^ !!argument; } friend inline const boolean operator !=(const signed char argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } friend inline const boolean operator !=(const signed char argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }
                            inline const boolean operator !=(const unsigned char argument) { return this -> value ^ !!argument; } friend inline const boolean operator !=(const unsigned char argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } friend inline const boolean operator !=(const unsigned char argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }
                            inline const boolean operator !=(const unsigned int argument) { return this -> value ^ !!argument; } friend inline const boolean operator !=(const unsigned int argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } friend inline const boolean operator !=(const unsigned int argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }
                            inline const boolean operator !=(const unsigned long argument) { return this -> value ^ !!argument; } friend inline const boolean operator !=(const unsigned long argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } friend inline const boolean operator !=(const unsigned long argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }
                            inline const boolean operator !=(const unsigned long long argument) { return this -> value ^ !!argument; } friend inline const boolean operator !=(const unsigned long long argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } friend inline const boolean operator !=(const unsigned long long argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }
                            inline const boolean operator !=(const unsigned short argument) { return this -> value ^ !!argument; } friend inline const boolean operator !=(const unsigned short argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } friend inline const boolean operator !=(const unsigned short argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }
                            inline const boolean operator !=(const wchar_t argument) { return this -> value ^ !!argument; } friend inline const boolean operator !=(const wchar_t argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } friend inline const boolean operator !=(const wchar_t argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }
                            template <typename type> inline const boolean operator !=(type& argument) { return this -> value ^ !!argument; } template <typename type> friend inline const boolean operator !=(type& argumentA, boolean& argumentB) { return argumentB.value ^ !!argumentA; } template <typename type> friend inline const boolean operator !=(type& argumentA, const boolean& argumentB) { return argumentB.value ^ !!argumentA; }

                            inline boolean& operator +=(const char argument) { argument && (this -> value = 1); return *this; } inline boolean& operator +=(const char16_t argument) { argument && (this -> value = 1); return *this; } inline boolean& operator +=(const char32_t argument) { argument && (this -> value = 1); return *this; } inline boolean& operator +=(const double argument) { argument && (this -> value = 1); return *this; } inline boolean& operator +=(const float argument) { argument && (this -> value = 1); return *this; } inline boolean& operator +=(const int argument) { argument && (this -> value = 1); return *this; } inline boolean& operator +=(const long argument) { argument && (this -> value = 1); return *this; } inline boolean& operator +=(const long double argument) { argument && (this -> value = 1); return *this; } inline boolean& operator +=(const long long argument) { argument && (this -> value = 1); return *this; } inline boolean& operator +=(const short argument) { argument && (this -> value = 1); return *this; } inline boolean& operator +=(const signed char argument) { argument && (this -> value = 1); return *this; } inline boolean& operator +=(const unsigned char argument) { argument && (this -> value = 1); return *this; } inline boolean& operator +=(const unsigned int argument) { argument && (this -> value = 1); return *this; } inline boolean& operator +=(const unsigned long argument) { argument && (this -> value = 1); return *this; } inline boolean& operator +=(const unsigned long long argument) { argument && (this -> value = 1); return *this; } inline boolean& operator +=(const unsigned short argument) { argument && (this -> value = 1); return *this; } inline boolean& operator +=(const wchar_t argument) { argument && (this -> value = 1); return *this; }
                            inline boolean& operator -=(const char argument) { argument && (this -> value = 0); return *this; } inline boolean& operator -=(const char16_t argument) { argument && (this -> value = 0); return *this; } inline boolean& operator -=(const char32_t argument) { argument && (this -> value = 0); return *this; } inline boolean& operator -=(const double argument) { argument && (this -> value = 0); return *this; } inline boolean& operator -=(const float argument) { argument && (this -> value = 0); return *this; } inline boolean& operator -=(const int argument) { argument && (this -> value = 0); return *this; } inline boolean& operator -=(const long argument) { argument && (this -> value = 0); return *this; } inline boolean& operator -=(const long double argument) { argument && (this -> value = 0); return *this; } inline boolean& operator -=(const long long argument) { argument && (this -> value = 0); return *this; } inline boolean& operator -=(const short argument) { argument && (this -> value = 0); return *this; } inline boolean& operator -=(const signed char argument) { argument && (this -> value = 0); return *this; } inline boolean& operator -=(const unsigned char argument) { argument && (this -> value = 0); return *this; } inline boolean& operator -=(const unsigned int argument) { argument && (this -> value = 0); return *this; } inline boolean& operator -=(const unsigned long argument) { argument && (this -> value = 0); return *this; } inline boolean& operator -=(const unsigned long long argument) { argument && (this -> value = 0); return *this; } inline boolean& operator -=(const unsigned short argument) { argument && (this -> value = 0); return *this; } inline boolean& operator -=(const wchar_t argument) { argument && (this -> value = 0); return *this; }
                            inline boolean& operator /=(const char argument) { this -> value = !!(this -> value / argument); return *this; } inline boolean& operator /=(const char16_t argument) { this -> value = !!(this -> value / argument); return *this; } inline boolean& operator /=(const char32_t argument) { this -> value = !!(this -> value / argument); return *this; } inline boolean& operator /=(const double argument) { this -> value = !!(this -> value / argument); return *this; } inline boolean& operator /=(const float argument) { this -> value = !!(this -> value / argument); return *this; } inline boolean& operator /=(const int argument) { this -> value = !!(this -> value / argument); return *this; } inline boolean& operator /=(const long argument) { this -> value = !!(this -> value / argument); return *this; } inline boolean& operator /=(const long double argument) { this -> value = !!(this -> value / argument); return *this; } inline boolean& operator /=(const long long argument) { this -> value = !!(this -> value / argument); return *this; } inline boolean& operator /=(const short argument) { this -> value = !!(this -> value / argument); return *this; } inline boolean& operator /=(const signed char argument) { this -> value = !!(this -> value / argument); return *this; } inline boolean& operator /=(const unsigned char argument) { this -> value = !!(this -> value / argument); return *this; } inline boolean& operator /=(const unsigned int argument) { this -> value = !!(this -> value / argument); return *this; } inline boolean& operator /=(const unsigned long argument) { this -> value = !!(this -> value / argument); return *this; } inline boolean& operator /=(const unsigned long long argument) { this -> value = !!(this -> value / argument); return *this; } inline boolean& operator /=(const unsigned short argument) { this -> value = !!(this -> value / argument); return *this; } inline boolean& operator /=(const wchar_t argument) { this -> value = !!(this -> value / argument); return *this; }
                            inline boolean& operator %=(const char argument) { this -> value = !!(this -> value % argument); return *this; } inline boolean& operator %=(const char16_t argument) { this -> value = !!(this -> value % argument); return *this; } inline boolean& operator %=(const char32_t argument) { this -> value = !!(this -> value % argument); return *this; } boolean& operator %=(const double argument) { this -> value = !!(LDKM::mod((unsigned short) this -> value, argument)); return *this; } boolean& operator %=(const float argument) { this -> value = !!(LDKM::mod((unsigned short) this -> value, argument)); return *this; } inline boolean& operator %=(const int argument) { this -> value = !!(this -> value % argument); return *this; } inline boolean& operator %=(const long argument) { this -> value = !!(this -> value % argument); return *this; } boolean& operator %=(const long double argument) { this -> value = !!(LDKM::mod((unsigned short) this -> value, argument)); return *this; } inline boolean& operator %=(const long long argument) { this -> value = !!(this -> value % argument); return *this; } inline boolean& operator %=(const short argument) { this -> value = !!(this -> value % argument); return *this; } inline boolean& operator %=(const signed char argument) { this -> value = !!(this -> value % argument); return *this; } inline boolean& operator %=(const unsigned char argument) { this -> value = !!(this -> value % argument); return *this; } inline boolean& operator %=(const unsigned int argument) { this -> value = !!(this -> value % argument); return *this; } inline boolean& operator %=(const unsigned long argument) { this -> value = !!(this -> value % argument); return *this; } inline boolean& operator %=(const unsigned long long argument) { this -> value = !!(this -> value % argument); return *this; } inline boolean& operator %=(const unsigned short argument) { this -> value = !!(this -> value % argument); return *this; } inline boolean& operator %=(const wchar_t argument) { this -> value = !!(this -> value % argument); return *this; }
                            inline boolean& operator ^=(const char argument) { this -> value = !!(this -> value ^ argument); return *this; } inline boolean& operator ^=(const char16_t argument) { this -> value = !!(this -> value ^ argument); return *this; } inline boolean& operator ^=(const char32_t argument) { this -> value = !!(this -> value ^ argument); return *this; } inline boolean& operator ^=(const double argument) { this -> value = !!(this -> value ^ !!argument); return *this; } inline boolean& operator ^=(const float argument) { this -> value = !!(this -> value ^ !!argument); return *this; } inline boolean& operator ^=(const int argument) { this -> value = !!(this -> value ^ argument); return *this; } inline boolean& operator ^=(const long argument) { this -> value = !!(this -> value ^ argument); return *this; } inline boolean& operator ^=(const long double argument) { this -> value = !!(this -> value ^ !!argument); return *this; } inline boolean& operator ^=(const long long argument) { this -> value = !!(this -> value ^ argument); return *this; } inline boolean& operator ^=(const short argument) { this -> value = !!(this -> value ^ argument); return *this; } inline boolean& operator ^=(const signed char argument) { this -> value = !!(this -> value ^ argument); return *this; } inline boolean& operator ^=(const unsigned char argument) { this -> value = !!(this -> value ^ argument); return *this; } inline boolean& operator ^=(const unsigned int argument) { this -> value = !!(this -> value ^ argument); return *this; } inline boolean& operator ^=(const unsigned long argument) { this -> value = !!(this -> value ^ argument); return *this; } inline boolean& operator ^=(const unsigned long long argument) { this -> value = !!(this -> value ^ argument); return *this; } inline boolean& operator ^=(const unsigned short argument) { this -> value = !!(this -> value ^ argument); return *this; } inline boolean& operator ^=(const wchar_t argument) { this -> value = !!(this -> value ^ argument); return *this; }
                            inline boolean& operator &=(const char argument) { this -> value = !!(this -> value & argument); return *this; } inline boolean& operator &=(const char16_t argument) { this -> value = !!(this -> value & argument); return *this; } inline boolean& operator &=(const char32_t argument) { this -> value = !!(this -> value & argument); return *this; } inline boolean& operator &=(const double argument) { this -> value = !!(this -> value & !!argument); return *this; } inline boolean& operator &=(const float argument) { this -> value = !!(this -> value & !!argument); return *this; } inline boolean& operator &=(const int argument) { this -> value = !!(this -> value & argument); return *this; } inline boolean& operator &=(const long argument) { this -> value = !!(this -> value & argument); return *this; } inline boolean& operator &=(const long double argument) { this -> value = !!(this -> value & !!argument); return *this; } inline boolean& operator &=(const long long argument) { this -> value = !!(this -> value & argument); return *this; } inline boolean& operator &=(const short argument) { this -> value = !!(this -> value & argument); return *this; } inline boolean& operator &=(const signed char argument) { this -> value = !!(this -> value & argument); return *this; } inline boolean& operator &=(const unsigned char argument) { this -> value = !!(this -> value & argument); return *this; } inline boolean& operator &=(const unsigned int argument) { this -> value = !!(this -> value & argument); return *this; } inline boolean& operator &=(const unsigned long argument) { this -> value = !!(this -> value & argument); return *this; } inline boolean& operator &=(const unsigned long long argument) { this -> value = !!(this -> value & argument); return *this; } inline boolean& operator &=(const unsigned short argument) { this -> value = !!(this -> value & argument); return *this; } inline boolean& operator &=(const wchar_t argument) { this -> value = !!(this -> value & argument); return *this; }
                            inline boolean& operator |=(const char argument) { this -> value = !!(this -> value | argument); return *this; } inline boolean& operator |=(const char16_t argument) { this -> value = !!(this -> value | argument); return *this; } inline boolean& operator |=(const char32_t argument) { this -> value = !!(this -> value | argument); return *this; } inline boolean& operator |=(const double argument) { this -> value = !!(this -> value | !!argument); return *this; } inline boolean& operator |=(const float argument) { this -> value = !!(this -> value | !!argument); return *this; } inline boolean& operator |=(const int argument) { this -> value = !!(this -> value | argument); return *this; } inline boolean& operator |=(const long argument) { this -> value = !!(this -> value | argument); return *this; } inline boolean& operator |=(const long double argument) { this -> value = !!(this -> value | !!argument); return *this; } inline boolean& operator |=(const long long argument) { this -> value = !!(this -> value | argument); return *this; } inline boolean& operator |=(const short argument) { this -> value = !!(this -> value | argument); return *this; } inline boolean& operator |=(const signed char argument) { this -> value = !!(this -> value | argument); return *this; } inline boolean& operator |=(const unsigned char argument) { this -> value = !!(this -> value | argument); return *this; } inline boolean& operator |=(const unsigned int argument) { this -> value = !!(this -> value | argument); return *this; } inline boolean& operator |=(const unsigned long argument) { this -> value = !!(this -> value | argument); return *this; } inline boolean& operator |=(const unsigned long long argument) { this -> value = !!(this -> value | argument); return *this; } inline boolean& operator |=(const unsigned short argument) { this -> value = !!(this -> value | argument); return *this; } inline boolean& operator |=(const wchar_t argument) { this -> value = !!(this -> value | argument); return *this; }
                            inline boolean& operator *=(const char argument) { argument || (this -> value = 0); return *this; } inline boolean& operator *=(const char16_t argument) { argument || (this -> value = 0); return *this; } inline boolean& operator *=(const char32_t argument) { argument || (this -> value = 0); return *this; } inline boolean& operator *=(const double argument) { argument || (this -> value = 0); return *this; } inline boolean& operator *=(const float argument) { argument || (this -> value = 0); return *this; } inline boolean& operator *=(const int argument) { argument || (this -> value = 0); return *this; } inline boolean& operator *=(const long argument) { argument || (this -> value = 0); return *this; } inline boolean& operator *=(const long double argument) { argument || (this -> value = 0); return *this; } inline boolean& operator *=(const long long argument) { argument || (this -> value = 0); return *this; } inline boolean& operator *=(const short argument) { argument || (this -> value = 0); return *this; } inline boolean& operator *=(const signed char argument) { argument || (this -> value = 0); return *this; } inline boolean& operator *=(const unsigned char argument) { argument || (this -> value = 0); return *this; } inline boolean& operator *=(const unsigned int argument) { argument || (this -> value = 0); return *this; } inline boolean& operator *=(const unsigned long argument) { argument || (this -> value = 0); return *this; } inline boolean& operator *=(const unsigned long long argument) { argument || (this -> value = 0); return *this; } inline boolean& operator *=(const unsigned short argument) { argument || (this -> value = 0); return *this; } inline boolean& operator *=(const wchar_t argument) { argument || (this -> value = 0); return *this; }

                            operator bool() const { return this -> value ? true : false; } // UPDATE REQUIRED (Lapys) -> Is there a way to subvert this conversion.
                            operator char() const { return this -> value ? '0' : '1'; }
                            operator char16_t() const { return this -> value ? u'0' : u'1'; }
                            operator char32_t() const { return this -> value ? U'0' : U'1'; }
                            operator double() const { return this -> value ? 0.00 : 1.00; }
                            operator float() const { return this -> value ? 0.0f : 1.0f; }
                            operator int() const { return this -> value ? 0 : 1; }
                            operator long() const { return this -> value ? 0L : 1L; }
                            operator long double() const { return this -> value ? 0.00 : 1.00; }
                            operator long long() const { return this -> value ? 0LL : 1LL; }
                            operator short() const { return this -> value ? 0 : 1; }
                            operator signed char() const { return this -> value ? '0' : '1'; }
                            operator unsigned char() const { return this -> value ? '0' : '1'; }
                            operator unsigned int() const { return this -> value ? 0u : 1u; }
                            operator unsigned long() const { return this -> value ? 0uL : 1uL; }
                            operator unsigned long long() const { return this -> value ? 0uLL : 1uLL; }
                            operator unsigned short() const { return this -> value ? 0u : 1u; }
                            operator wchar_t() const { return this -> value ? L'0' : L'1'; }
                            operator boolean() const { return *this; }

                            // Function
                                // To String
                                const char* toString() const {
                                    // Initialization > Character String
                                    char *characterString = NULL;

                                    // Logic > Update > Character String
                                    if (this -> value) { characterString = (char*) std::malloc(5u * sizeof(char)); *characterString = 't'; *(characterString + 1u) = 'r'; *(characterString + 2u) = 'u'; *(characterString + 3u) = 'e'; *(characterString + 4u) = '\0'; }
                                    else { characterString = (char*) std::malloc(6u * sizeof(char)); *characterString = 'f'; *(characterString + 1u) = 'a'; *(characterString + 2u) = 'l'; *(characterString + 3u) = 's'; *(characterString + 4u) = 'e'; *(characterString + 5u) = '\0'; }

                                    // Return
                                    return characterString;
                                }

                                // Value Of
                                inline unsigned char valueOf() const { return this -> value; }
                    };

                    // Array --- NOTE (Lapys) -> All member functions here return the target object.
                    template <typename structType>
                    struct array {
                        // [Protected]
                        protected:
                            // [Destructor]
                            ~array() { std::free(this -> value); this -> value = NULL; }

                            // Initialization > (Is Batch Processing, Length, Value)
                            boolean isBatchProcessing = false;
                            structType *value = NULL;

                            // Function --- NOTE (Lapys) -> Some member functions will be defined here to prevent code redundancy.
                                // Copy
                                void copy(structType* array, const unsigned length) { unsigned iterator = length; this -> length = length; if (!(this -> isBatchProcessing)) this -> reallocateBySize(this -> length); while (iterator) { iterator -= 1u; *(this -> value + iterator) = *(array + iterator); } }
                                void copy(const structType* array, const unsigned length) { unsigned iterator = length; this -> length = length; if (!(this -> isBatchProcessing)) this -> reallocateBySize(this -> length); while (iterator) { iterator -= 1u; *(this -> value + iterator) = *(array + iterator); } }

                                // Empty
                                void empty() { this -> isBatchProcessing = false; this -> length = 0u; std::free(this -> value); this -> value = NULL; }

                                // Index Of From
                                const signed long indexOfFrom(structType& element) {
                                    // Initialization > (Index, Stop (Indexes), Iterator)
                                    signed long index = -1;
                                    unsigned stop = LDKF::toInteger((float) this -> length / 4.00f),
                                        iterator = this -> length - ((stop * 3u) - 1u);
                                    unsigned stopIndexes[4u];

                                    // Loop
                                    while (!~index && iterator) {
                                        // Update > (Iterator, Stop Indexes)
                                        iterator -= 1u;
                                        *stopIndexes = this -> length - iterator;
                                        *(stopIndexes + 1u) = *stopIndexes - stop;
                                        *(stopIndexes + 2u) = iterator + stop;
                                        *(stopIndexes + 3u) = iterator;

                                        // Update > Index
                                        (
                                            ((*(this -> value + *stopIndexes) == element) && (index = (*stopIndexes) + 1u)) ||
                                            ((*(this -> value + *(stopIndexes + 1u)) == element) && (index = *(stopIndexes + 1u) + 1u)) ||
                                            ((*(this -> value + *(stopIndexes + 2u)) == element) && (index = *(stopIndexes + 2u) + 1u)) ||
                                            ((*(this -> value + *(stopIndexes + 3u)) == element) && (index = *(stopIndexes + 3u) + 1u))
                                        ) && (index -= 1u);
                                    }

                                    // Return
                                    return index;
                                }

                                // Index Of From Back
                                inline const signed long indexOfFromBack(structType& element) {
                                    // Initialization > Iterator
                                    unsigned iterator = this -> length;

                                    // Loop > Logic > Return
                                    while (iterator) if (*(this -> value + (this -> length - (iterator -= 1u) - 1u)) == element) return this -> length - iterator - 1u;

                                    // Return
                                    return -1;
                                }

                                // Index Of From Front
                                inline const signed long indexOfFromFront(structType& element) {
                                    // Initialization > Iterator
                                    unsigned iterator = this -> length;

                                    // Loop > Logic > Return
                                    while (iterator) if (*(this -> value + (iterator -= 1u)) == element) return iterator;

                                    // Return
                                    return -1;
                                }

                                // Push
                                inline void push() {}
                                void push(structType& element) {
                                    // Logic > Target > Reallocate By Size
                                    if (!(this -> isBatchProcessing)) this -> reallocateBySize(this -> length + 1u);

                                    // Modification > Target > (Value, Length)
                                    *((this -> value) + (this -> length)) = element; this -> length += 1u;
                                }
                                template <typename... structTypes>
                                void push(structType& element, structTypes&... elements) {
                                    // ...
                                    if (!(this -> isBatchProcessing)) { this -> isBatchProcessing = true; this -> reallocateBySize(this -> length + LDKF::getReferencedArgumentsCount(element, elements...)); }
                                    this -> push(element); this -> push(elements...);
                                    this -> isBatchProcessing && (this -> isBatchProcessing = false);
                                }

                                // Reallocate
                                void reallocate(const unsigned size) { this -> value = (structType*) std::realloc(this -> value, size); }
                                    // By Size
                                    void reallocateBySize(const unsigned size) { this -> reallocate(size * sizeof(structType)); }

                                // Repeat
                                void repeat(const unsigned iterationCount) {
                                    // Logic
                                    if (iterationCount) {
                                        // Logic
                                        if (iterationCount ^ 1) {
                                            // Initialization > (Count, Length)
                                            unsigned count = iterationCount - 1u;
                                            const unsigned length = this -> length;

                                            // Target > Reallocate By Size
                                            this -> reallocateBySize(this -> length * iterationCount);

                                            // Modification > Target > Length
                                            this -> length += (this -> length * count);

                                            // Loop
                                            while (count) {
                                                // Initialization > Iterator; Loop > ...
                                                unsigned iterator = length;
                                                while (iterator) { iterator -= 1u; *(this -> value + (iterator + (count * length))) = *(this -> value + iterator); }

                                                // Update > Count
                                                count -= 1u;
                                            }
                                        }
                                    }

                                    else
                                        // Target > Empty
                                        this -> empty();
                                }

                                // Set Length
                                void setlength(const unsigned length) {
                                    // Logic > ...
                                    if (length) this -> reallocateBySize(this -> length = length);
                                    else this -> empty();
                                }

                                // Splice --- NOTE (Lapys) -> The Length parameter must be greater than the Index parameter.
                                void splice(const unsigned index) {
                                    // Logic
                                    if (this -> length && index < this -> length) {
                                        // Initialization > Iterator
                                        unsigned iterator = index;

                                        // (Loop >)Modification > Target > ...
                                        this -> length -= 1u;
                                        while (iterator ^ (this -> length)) *(this -> value + iterator) = *((this -> value) + (iterator += 1));

                                        // Logic > ...
                                        if (this -> length) this -> reallocateBySize(this -> length);
                                        else this -> empty();
                                    }
                                }
                                void splice(const unsigned index, const unsigned length) {
                                    // Logic
                                    if (this -> length && index < this -> length) {
                                        // Initialization > Stop
                                        const unsigned stop = index + length;

                                        // Logic
                                        if (stop == index)
                                            // Target > Splice
                                            this -> splice(index);

                                        else if (!index && length == this -> length)
                                            // Target > Empty
                                            this -> empty();

                                        else if (stop == this -> length || stop < this -> length) {
                                            // Initialization > Iterator
                                            unsigned iterator = stop;

                                            // Loop > ...
                                            while (iterator ^ this -> length) { *(this -> value + (index + iterator - stop)) = *(this -> value + iterator); iterator += 1u; }

                                            // Target > Reallocate By Size
                                            this -> reallocateBySize(this -> length -= length);
                                        }
                                    }
                                }

                                // Unshift
                                inline void unshift() {}
                                void unshift(structType& element) {
                                    // Logic
                                    if (this -> isBatchProcessing)
                                        // Modification > Target > Value --- NOTE (Lapys) -> The Length here serves more as an index.
                                        *((this -> value) + (this -> length)) = element;

                                    else {
                                        this -> reallocateBySize(this -> length + 1u);

                                        // Initialization > Iterator; Loop > ... --- NOTE (Lapys) -> Shift the array elements rightward by a single step.
                                        unsigned iterator = this -> length;
                                        while (iterator) *(this -> value + iterator) = *(this -> value + (iterator -= 1));

                                        // Modification > Target > (Value, Length)
                                        *(this -> value) = element;
                                        this -> length += 1u;
                                    }
                                }
                                template <typename... structTypes>
                                void unshift(structType& element, structTypes&... elements) {
                                    // Initialization > (Arguments Count, Length) --- NOTE (Lapys) -> Store the actual length of the array.
                                    const unsigned argumentsCount = LDKF::getReferencedArgumentsCount(element, elements...),
                                        length = this -> length;

                                    // Logic
                                    if (!(this -> isBatchProcessing)) {
                                        // Modification > Target > ... --- NOTE (Lapys) -> Re-purpose the mutable Length of the array to serve as an index for which to add new Elements.
                                        this -> isBatchProcessing = true;
                                        this -> length = 0u;

                                        // Target > Reallocate By Size
                                        this -> reallocateBySize(argumentsCount + length);

                                        // Initialization > Iterator; Loop > ... --- NOTE (Lapys) -> Shift the array elements rightward by the number of arguments specified.
                                        unsigned iterator = argumentsCount + length;
                                        while (iterator)  *(this -> value + (iterator -= 1u)) = *(this -> value + iterator - argumentsCount);
                                    }

                                    // Modification > Target > ... --- NOTE (Lapys) -> Use the Length data member as an index instead; This is to prevent adding the Elements in reverse order.
                                    *((this -> value) + (this -> length)) = element;
                                    this -> length += 1u;

                                    // Target > Unshift
                                    this -> unshift(elements...);

                                    // Modification > Target > Is Batch Processing
                                    this -> isBatchProcessing = false;
                                    this -> length = length + argumentsCount;
                                }

                        // [Public]
                        public:
                            // [Operator] > [[]]
                            structType& operator [](const unsigned int index) { return *(this -> value + index); }

                            // Initialization > Length
                            unsigned length = 0u;

                            // Function
                                // To String --- CHECKPOINT (Lapys)
                                const char* toString() const {}

                                // Value Of
                                inline structType*& valueOf() { return (structType*&) this -> value; }
                    };
                        // Reference Array --- NOTE (Lapys) -> Does not clone its data members (elements). Best used with complex data & objects.
                        template <typename structType>
                        struct reference_array : array<structType> {
                            // [Public]
                            public:
                                // [Constructor]
                                inline reference_array() { this -> value = (structType*) std::malloc(0u); }
                                reference_array(reference_array<structType>& array) { this -> value = (structType*) std::malloc(array.length * sizeof(structType)); this -> isBatchProcessing = true; this -> copy(array.value, array.length); this -> isBatchProcessing = false; }
                                reference_array(const reference_array<structType>& array) { this -> value = (structType*) std::malloc(array.length * sizeof(structType)); this -> isBatchProcessing = true; this -> copy(array.value, array.length); this -> isBatchProcessing = false; }
                                template <unsigned length> reference_array(structType (&array)[length]) { this -> value = (structType*) std::malloc(array.length * sizeof(structType)); this -> isBatchProcessing = true; this -> copy(array, length); this -> isBatchProcessing = false; }
                                template <typename... structTypes> reference_array(structTypes&... elements) { this -> value = (structType*) std::malloc(0u); this -> free(); this -> addToFront(elements...); }

                                // [Operator] > [=]
                                reference_array<structType>& operator =(reference_array<structType>& array) { this -> copy(array.value, array.length); return *this; }
                                reference_array<structType>& operator =(const reference_array<structType>& array) { this -> copy(array.value, array.length); return *this; }
                                template <unsigned length> reference_array<structType>& operator =(structType (&array)[length]) { this -> copy(array, length); return *this; }

                                // Function > ...
                                inline reference_array<structType>& add() { return *this; }
                                template <typename... structTypes> reference_array<structType>& add(structTypes&... elements) { this -> addToFront(elements...); return *this; }

                                inline reference_array<structType>& addToBack() { return *this; }
                                template <typename... structTypes> reference_array<structType>& addToBack(structTypes&... elements) { this -> unshift(elements...); return *this; }

                                inline reference_array<structType>& addToFront() { return *this; }
                                template <typename... structTypes> reference_array<structType>& addToFront(structTypes&... elements) { this -> push(elements...); return *this; }

                                reference_array<structType>& cutAt(const unsigned index) { this -> splice(index); return *this; }
                                reference_array<structType>& cut(const unsigned index) { this -> cutLeft(index); this -> cutRight(index); return *this; }
                                reference_array<structType>& cutLeft(const unsigned index) { this -> splice(0u, this -> length < index ? this -> length : index); return *this; }
                                reference_array<structType>& cutRight(const unsigned index) { this -> setlength(this -> length - (this -> length < index ? this -> length : index)); return *this; }

                                reference_array<structType>& free() { this -> empty(); return *this; }

                                reference_array<structType>& import(void* array, const unsigned length) { this -> copy(array, length); return *this; }

                                const signed long index(structType& element) { return this -> indexFrom(element); }
                                const signed long indexFrom(structType& element) { return this -> indexOfFrom(element); }
                                const signed long indexFromBack(structType& element) { return this -> indexOfFromBack(element); }
                                const signed long indexFromFront(structType& element) { return this -> indexOfFromFront(element); }

                                reference_array<structType>& remove(structType& element) { return this -> removeFrom(element); }
                                reference_array<structType>& removeFrom(structType& element) { signed long index = this -> indexFrom(element); if (~index) this -> cutAt(index); return *this; }
                                reference_array<structType>& removeFromBack(structType& element) { signed long index = this -> indexFromBack(element); if (~index) this -> cutAt(index); return *this; }
                                reference_array<structType>& removeFromFront(structType& element) { signed long index = this -> indexFromFront(element); if (~index) this -> cutAt(index); return *this; }

                                reference_array<structType>& resize(const unsigned length) { this -> setlength(length); return *this; }
                        };

                        // Value Array --- NOTE (Lapys) -> Stores copies of its elements. Best used with primitive data types.
                        template <typename structType>
                        struct value_array : array<structType> {
                            // [Public]
                            public:
                                // [Constructor]
                                inline value_array() { this -> value = (structType*) std::malloc(0u); }
                                value_array(value_array<structType>& array) { this -> value = (structType*) std::malloc(array.length * sizeof(structType)); this -> isBatchProcessing = true; this -> copy(array.value, array.length); this -> isBatchProcessing = false; }
                                value_array(const value_array<structType>& array) { this -> value = (structType*) std::malloc(array.length * sizeof(structType)); this -> isBatchProcessing = true; this -> copy(array.value, array.length); this -> isBatchProcessing = false; }
                                template <unsigned length> value_array(structType (&array)[length]) { this -> value = (structType*) std::malloc(array.length * sizeof(structType)); this -> isBatchProcessing = true; this -> copy(array, length); this -> isBatchProcessing = false; }
                                template <typename... structTypes> value_array(structTypes... elements) { this -> value = (structType*) std::malloc(0u); this -> free(); this -> addToFront(elements...); }

                                // [Operator] > [=]
                                value_array<structType>& operator =(value_array<structType>& array) { this -> copy(array.value, array.length); return *this; }
                                value_array<structType>& operator =(const value_array<structType>& array) { this -> copy(array.value, array.length); return *this; }
                                template <unsigned length> value_array<structType>& operator =(structType (&array)[length]) { this -> copy(array, length); return *this; }

                                // Function > ...
                                inline value_array<structType>& add() { return *this; }
                                template <typename... structTypes> value_array<structType>& add(structTypes... elements) { this -> addToFront(elements...); return *this; }

                                inline value_array<structType>& addToBack() { return *this; }
                                template <typename... structTypes> value_array<structType>& addToBack(structTypes... elements) { this -> unshift((structType&) elements...); return *this; }

                                inline value_array<structType>& addToFront() { return *this; }
                                template <typename... structTypes> value_array<structType>& addToFront(structTypes... elements) { this -> push((structType&) elements...); return *this; }

                                value_array<structType>& cutAt(const unsigned index) { this -> splice(index); return *this; }
                                value_array<structType>& cut(const unsigned index) { this -> cutLeft(index); this -> cutRight(index); return *this; }
                                value_array<structType>& cutLeft(const unsigned index) { this -> splice(0u, this -> length < index ? this -> length : index); return *this; }
                                value_array<structType>& cutRight(const unsigned index) { this -> setlength(this -> length - (this -> length < index ? this -> length : index)); return *this; }

                                value_array<structType>& free() { this -> empty(); return *this; }

                                reference_array<structType>& import(void* array, const unsigned length) { this -> copy(array, length); return *this; }

                                const signed long index(structType element) { return this -> indexOfFrom((structType&) element); }
                                const signed long indexFrom(structType element) { return this -> indexOfFrom((structType&) element); }
                                const signed long indexFromBack(structType element) { return this -> indexOfFromBack((structType&) element); }
                                const signed long indexFromFront(structType element) { return this -> indexOfFromFront((structType&) element); }

                                value_array<structType>& remove(structType element) { return this -> removeFrom(element); }
                                value_array<structType>& removeFrom(structType element) { signed long index = this -> indexFrom((structType&) element); if (~index) this -> cutAt(index); return *this; }
                                value_array<structType>& removeFromBack(structType element) { signed long index = this -> indexFromBack((structType&) element); if (~index) this -> cutAt(index); return *this; }
                                value_array<structType>& removeFromFront(structType element) { signed long index = this -> indexFromFront((structType&) element); if (~index) this -> cutAt(index); return *this; }

                                value_array<structType>& resize(const unsigned length) { this -> setlength(length); return *this; }
                        };

                    // Number --- NOTE (Lapys) -> Strictly a container for number types.
                    struct number {
                        // [Private]
                        private:
                            // Initialization > Value
                            void *value = NULL;

                        // [Public]
                        public:
                            // [Constructor]
                            inline number() {}
                            number(const double value) { this -> value = std::malloc(sizeof(value)); *((double*) (this -> value)) = value; }
                            number(const float value) { this -> value = std::malloc(sizeof(value)); *((float*) (this -> value)) = value; }
                            number(const int value) { this -> value = std::malloc(sizeof(value)); *((int*) (this -> value)) = value; }
                            number(const long value) { this -> value = std::malloc(sizeof(value)); *((long*) (this -> value)) = value; }
                            number(const long double value) { this -> value = std::malloc(sizeof(value)); *((long double*) (this -> value)) = value; }
                            number(const long long value) { this -> value = std::malloc(sizeof(value)); *((long long*) (this -> value)) = value; }
                            number(const short value) { this -> value = std::malloc(sizeof(value)); *((short*) (this -> value)) = value; }
                            number(const unsigned int value) { this -> value = std::malloc(sizeof(value)); *((unsigned int*) (this -> value)) = value; }
                            number(const unsigned long value) { this -> value = std::malloc(sizeof(value)); *((unsigned long*) (this -> value)) = value; }
                            number(const unsigned long long value) { this -> value = std::malloc(sizeof(value)); *((unsigned long long*) (this -> value)) = value; }
                            number(const unsigned short value) { this -> value = std::malloc(sizeof(value)); *((unsigned short*) (this -> value)) = value; }
                            number(number& value) { this -> value = std::malloc(sizeof(value)); *((number*) (this -> value)) = *((number*) value.value); }
                            number(const number& value) { this -> value = std::malloc(sizeof(value)); *((number*) (this -> value)) = *((number*) value.value); }

                            // [Destructor]
                            ~number() { std::free(this -> value); this -> value = NULL; }

                            // [Operator]
                                // [=]
                                number& operator =(const double argument) { this -> value = std::realloc(this -> value, sizeof(argument)); *((double*) (this -> value)) = argument; return *this; }
                                number& operator =(const float argument) { this -> value = std::realloc(this -> value, sizeof(argument)); *((float*) (this -> value)) = argument; return *this; }
                                number& operator =(const int argument) { this -> value = std::realloc(this -> value, sizeof(argument)); *((int*) (this -> value)) = argument; return *this; }
                                number& operator =(const long argument) { this -> value = std::realloc(this -> value, sizeof(argument)); *((long*) (this -> value)) = argument; return *this; }
                                number& operator =(const long double argument) { this -> value = std::realloc(this -> value, sizeof(argument)); *((long double*) (this -> value)) = argument; return *this; }
                                number& operator =(const long long argument) { this -> value = std::realloc(this -> value, sizeof(argument)); *((long long*) (this -> value)) = argument; return *this; }
                                number& operator =(const short argument) { this -> value = std::realloc(this -> value, sizeof(argument)); *((short*) (this -> value)) = argument; return *this; }
                                number& operator =(const unsigned int argument) { this -> value = std::realloc(this -> value, sizeof(argument)); *((unsigned int*) (this -> value)) = argument; return *this; }
                                number& operator =(const unsigned long argument) { this -> value = std::realloc(this -> value, sizeof(argument)); *((unsigned long*) (this -> value)) = argument; return *this; }
                                number& operator =(const unsigned long long argument) { this -> value = std::realloc(this -> value, sizeof(argument)); *((unsigned long long*) (this -> value)) = argument; return *this; }
                                number& operator =(const unsigned short argument) { this -> value = std::realloc(this -> value, sizeof(argument)); *((unsigned short*) (this -> value)) = argument; return *this; }
                                number& operator =(number& argument) { this -> value = std::realloc(this -> value, sizeof(value)); *((number*) (this -> value)) = *((number*) argument.value); return *this; }
                                number& operator =(const number& argument) { this -> value = std::realloc(this -> value, sizeof(value)); *((number*) (this -> value)) = *((number*) argument.value); return *this; }

                                // [...] --- NOTE (Lapys) -> To retrieve the value from this container, the object must be casted to the value`s type,
                                operator double() const { return *((double*) (this -> value)); }
                                operator float() const { return *((float*) (this -> value)); }
                                operator int() const { return *((int*) (this -> value)); }
                                operator long() const { return *((long*) (this -> value)); }
                                operator long double() const { return *((long double*) (this -> value)); }
                                operator long long() const { return *((long long*) (this -> value)); }
                                operator short() const { return *((short*) (this -> value)); }
                                operator unsigned int() const { return *((unsigned int*) (this -> value)); }
                                operator unsigned long() const { return *((unsigned long*) (this -> value)); }
                                operator unsigned long long() const { return *((unsigned long long*) (this -> value)); }
                                operator unsigned short() const { return *((unsigned short*) (this -> value)); }
                                inline operator number() const { return *this; }

                            // Function
                                // To String --- CHECKPOINT (Lapys)
                                const char* toString() const {}

                                // Value Of
                                inline const void* valueOf() const { return this -> value; }
                    };

                    // Pointer --- NOTE (Lapys) -> Container for pointer types. Frees up memory when destructed.
                    struct pointer {
                        // [Protected]
                        protected:
                            // Initialization > Value
                            void *value = NULL;

                        // [Public]
                        public:
                            // [Constructor]
                            inline pointer() {}
                            pointer(void *value) { this -> value = std::malloc(0u); this -> value = value; }
                            pointer(const void *value) { this -> value = std::malloc(0u); this -> value = (void*) value; }
                            inline pointer(pointer& value) { this -> value = value.value; }
                            inline pointer(const pointer& value) { this -> value = value.value; }
                            template <typename type> pointer(type* value) { this -> value = std::malloc(sizeof(type)); this -> value = value; }

                            // [Destructor]
                            ~pointer() { std::free(this -> value); this -> value = NULL; }

                            // [Operator] > ... --- NOTE (Lapys) -> Most of its operators act as if they are used on it`s base value.
                            inline void* operator +(int argument) { return ((int*) this -> value) + argument; } friend inline void* operator +(int argumentA, pointer& argumentB) { return ((int*) argumentB.value) + argumentA; } friend inline void* operator +(int argumentA, const pointer& argumentB) { return ((int*) argumentB.value) + argumentA; }
                            inline void* operator +(long argument) { return ((long*) this -> value) + argument; } friend inline void* operator +(long argumentA, pointer& argumentB) { return ((long*) argumentB.value) + argumentA; } friend inline void* operator +(long argumentA, const pointer& argumentB) { return ((long*) argumentB.value) + argumentA; }
                            inline void* operator +(long long argument) { return ((long long*) this -> value) + argument; } friend inline void* operator +(long long argumentA, pointer& argumentB) { return ((long long*) argumentB.value) + argumentA; } friend inline void* operator +(long long argumentA, const pointer& argumentB) { return ((long long*) argumentB.value) + argumentA; }
                            inline void* operator +(short argument) { return ((short*) this -> value) + argument; } friend inline void* operator +(short argumentA, pointer& argumentB) { return ((short*) argumentB.value) + argumentA; } friend inline void* operator +(short argumentA, const pointer& argumentB) { return ((short*) argumentB.value) + argumentA; }
                            inline void* operator +(unsigned int argument) { return ((unsigned int*) this -> value) + argument; } friend inline void* operator +(unsigned int argumentA, pointer& argumentB) { return ((unsigned int*) argumentB.value) + argumentA; } friend inline void* operator +(unsigned int argumentA, const pointer& argumentB) { return ((unsigned int*) argumentB.value) + argumentA; }
                            inline void* operator +(unsigned long argument) { return ((unsigned long*) this -> value) + argument; } friend inline void* operator +(unsigned long argumentA, pointer& argumentB) { return ((unsigned long*) argumentB.value) + argumentA; } friend inline void* operator +(unsigned long argumentA, const pointer& argumentB) { return ((unsigned long*) argumentB.value) + argumentA; }
                            inline void* operator +(unsigned long long argument) { return ((unsigned long long*) this -> value) + argument; } friend inline void* operator +(unsigned long long argumentA, pointer& argumentB) { return ((unsigned long long*) argumentB.value) + argumentA; } friend inline void* operator +(unsigned long long argumentA, const pointer& argumentB) { return ((unsigned long long*) argumentB.value) + argumentA; }
                            inline void* operator +(unsigned short argument) { return ((unsigned short*) this -> value) + argument; } friend inline void* operator +(unsigned short argumentA, pointer& argumentB) { return ((unsigned short*) argumentB.value) + argumentA; } friend inline void* operator +(unsigned short argumentA, const pointer& argumentB) { return ((unsigned short*) argumentB.value) + argumentA; }

                            inline void* operator -(int argument) { return ((int*) this -> value) - argument; } friend inline void* operator -(int argumentA, pointer& argumentB) { return ((int*) argumentB.value) - argumentA; } friend inline void* operator -(int argumentA, const pointer& argumentB) { return ((int*) argumentB.value) - argumentA; }
                            inline void* operator -(long argument) { return ((long*) this -> value) - argument; } friend inline void* operator -(long argumentA, pointer& argumentB) { return ((long*) argumentB.value) - argumentA; } friend inline void* operator -(long argumentA, const pointer& argumentB) { return ((long*) argumentB.value) - argumentA; }
                            inline void* operator -(long long argument) { return ((long long*) this -> value) - argument; } friend inline void* operator -(long long argumentA, pointer& argumentB) { return ((long long*) argumentB.value) - argumentA; } friend inline void* operator -(long long argumentA, const pointer& argumentB) { return ((long long*) argumentB.value) - argumentA; }
                            inline void* operator -(short argument) { return ((short*) this -> value) - argument; } friend inline void* operator -(short argumentA, pointer& argumentB) { return ((short*) argumentB.value) - argumentA; } friend inline void* operator -(short argumentA, const pointer& argumentB) { return ((short*) argumentB.value) - argumentA; }
                            inline void* operator -(unsigned int argument) { return ((unsigned int*) this -> value) - argument; } friend inline void* operator -(unsigned int argumentA, pointer& argumentB) { return ((unsigned int*) argumentB.value) - argumentA; } friend inline void* operator -(unsigned int argumentA, const pointer& argumentB) { return ((unsigned int*) argumentB.value) - argumentA; }
                            inline void* operator -(unsigned long argument) { return ((unsigned long*) this -> value) - argument; } friend inline void* operator -(unsigned long argumentA, pointer& argumentB) { return ((unsigned long*) argumentB.value) - argumentA; } friend inline void* operator -(unsigned long argumentA, const pointer& argumentB) { return ((unsigned long*) argumentB.value) - argumentA; }
                            inline void* operator -(unsigned long long argument) { return ((unsigned long long*) this -> value) - argument; } friend inline void* operator -(unsigned long long argumentA, pointer& argumentB) { return ((unsigned long long*) argumentB.value) - argumentA; } friend inline void* operator -(unsigned long long argumentA, const pointer& argumentB) { return ((unsigned long long*) argumentB.value) - argumentA; }
                            inline void* operator -(unsigned short argument) { return ((unsigned short*) this -> value) - argument; } friend inline void* operator -(unsigned short argumentA, pointer& argumentB) { return ((unsigned short*) argumentB.value) - argumentA; } friend inline void* operator -(unsigned short argumentA, const pointer& argumentB) { return ((unsigned short*) argumentB.value) - argumentA; }

                            pointer& operator =(void *argument) { this -> value = std::realloc(this -> value, sizeof(0u)); this -> value = argument; return *this; } pointer& operator =(const void *argument) { this -> value = std::realloc(this -> value, sizeof(0u)); this -> value = (void*) argument; return *this; } inline pointer& operator =(pointer& argument) { this -> value = argument.value; return *this; } inline pointer& operator =(const pointer& argument) { this -> value = argument.value; return *this; } template <typename type> pointer& operator =(type *argument) { this -> value = std::realloc(this -> value, sizeof(type)); this -> value = argument; return *this; }
                            inline void* operator ++() { int* value = (int*) this -> value; value++; return this -> value = value; } inline void* operator ++(int) { int* value = (int*) this -> value; ++value; return this -> value = value; }
                            inline void* operator --() { int* value = (int*) this -> value; value--; return this -> value = value; } inline void* operator --(int) { int* value = (int*) this -> value; --value; return this -> value = value; }
                            inline void* operator +=(int argument) { return this -> value = (void*) (((int*) this -> value) + argument); } inline void* operator +=(long argument) { return this -> value = (void*) (((long*) this -> value) + argument); } inline void* operator +=(long long argument) { return this -> value = (void*) (((long long*) this -> value) + argument); } inline void* operator +=(short argument) { return this -> value = (void*) (((short*) this -> value) + argument); } inline void* operator +=(unsigned int argument) { return this -> value = (void*) (((unsigned int*) this -> value) + argument); } inline void* operator +=(unsigned long argument) { return this -> value = (void*) (((unsigned long*) this -> value) + argument); } inline void* operator +=(unsigned long long argument) { return this -> value = (void*) (((unsigned long long*) this -> value) + argument); } inline void* operator +=(unsigned short argument) { return this -> value = (void*) (((unsigned short*) this -> value) + argument); }
                            inline void* operator -=(int argument) { return this -> value = (void*) (((int*) this -> value) - argument); } inline void* operator -=(long argument) { return this -> value = (void*) (((long*) this -> value) - argument); } inline void* operator -=(long long argument) { return this -> value = (void*) (((long long*) this -> value) - argument); } inline void* operator -=(short argument) { return this -> value = (void*) (((short*) this -> value) - argument); } inline void* operator -=(unsigned int argument) { return this -> value = (void*) (((unsigned int*) this -> value) - argument); } inline void* operator -=(unsigned long argument) { return this -> value = (void*) (((unsigned long*) this -> value) - argument); } inline void* operator -=(unsigned long long argument) { return this -> value = (void*) (((unsigned long long*) this -> value) - argument); } inline void* operator -=(unsigned short argument) { return this -> value = (void*) (((unsigned short*) this -> value) - argument); }

                            inline operator int() const { return !!(this -> value); }
                            inline operator void*() const { return this -> value; }

                            inline operator pointer() { return *this; }

                            // Function
                                // To String --- CHECKPOINT (Lapys)
                                const char* toString() const {}

                                // Value Of
                                inline void*& valueOf() const { return (void*&) this -> value; }
                    };
                        // Typed Pointer --- NOTE (Lapys) -> Built to be allow access to data members that `void` pointers do not.
                        template <typename structType>
                        struct typed_pointer : pointer {
                            // [Public]
                            public:
                                // [Constructor]
                                typed_pointer() {}
                                typed_pointer(structType *value) { this -> value = std::malloc(sizeof(structType)); this -> value = value; }
                                typed_pointer(typed_pointer<structType>& value) { this -> value = value.value; }
                                typed_pointer(const typed_pointer<structType>& value) { this -> value = value.value; }

                                // [Operator] > ...
                                inline structType& operator *() { return *((structType*) this -> value); }
                                inline typed_pointer<structType>& operator =(typed_pointer<structType>& argument) { this -> value = argument.value; return *this; }
                                inline typed_pointer<structType>& operator =(const typed_pointer<structType>& argument) { this -> value = argument.value; return *this; }
                                inline structType& operator [](const unsigned int index) { return *(((structType*) this -> value) + index); }
                                inline operator structType*() const { return this -> value; }
                                inline operator typed_pointer<structType>() const { return *this; }

                                // Function > Value Of
                                structType*& valueOf() const { return (structType*&) this -> value; }
                        };

                    // Primitive --- NOTE (Lapys) -> Strictly a container for C Plain-Old-Data types. --- WARN (Lapys) -> Does not resolve pointers.
                    struct primitive {
                        // [Private]
                        private:
                            // Initialization > Value
                            boolean isDecimal = false;
                            void *value = NULL;

                        // [Protected]
                        protected:
                            // Function > Clone
                            void clone(primitive& value) {
                                // Logic > ...
                                if (this -> isDecimal) { long double baseValue = (long double) value; this -> value = std::malloc(sizeof(baseValue)); *((long double*) (this -> value)) = baseValue; }
                                else { long long baseValue = (long long) value; this -> value = std::malloc(sizeof(baseValue)); *((long long*) (this -> value)) = baseValue; }
                            }

                        // [Public]
                        public:
                            // [Constructor]
                            inline primitive() {}
                            primitive(const int value) { ::printf("[CONSTRUCTOR]: %i\n", value); this -> value = std::malloc(sizeof(value)); *((int*) (this -> value)) = value; }
                            primitive(primitive& value) { ::printf("[CONSTRUCTOR]\n"); this -> clone(value); }
                            primitive(const primitive& value) { ::printf("[CONSTRUCTOR]\n"); this -> clone((primitive&) value); }

                            // [Destructor]
                            ~primitive() { std::free(this -> value); this -> value = NULL; }

                            // [Operator] > ... --- CHECKPOINT (Lapys)
                            primitive& operator =(const int argument) { ::printf("[UPDATE]: %i\n", argument); *((int*) (this -> value)) = argument; }
                            primitive& operator =(primitive& argument) { ::printf("[UPDATE]\n"); this -> clone(argument); return *this; }
                            primitive& operator =(const primitive& argument) { ::printf("[UPDATE]\n"); this -> clone((primitive&) argument); return *this; }

                            // [==]
                            inline const boolean operator ==(const int argument) { return (int) *this == argument; }
                            friend inline const boolean operator ==(const int argumentA, primitive& argumentB) { return argumentA == (int) argumentB; }

                            inline const boolean operator ==(primitive& argument) { return this -> isDecimal ? (long double) *this == (long double) argument : (long long) *this == (long long) argument; }
                            inline const boolean operator ==(const primitive& argument) { return this -> isDecimal ? (long double) *this == (long double) (primitive&) argument : (long long) *this == (long long) (primitive&) argument; }

                            inline operator int() { return *((int*) (this -> value)); }
                            inline operator long double() { return *((long double*) (this -> value)); }
                            inline operator long long() { return *((long long*) (this -> value)); }

                            // Function
                                // To String ---  CHECKPOINT (Lapys)
                                inline const char* toString() const {}

                                // Value Of
                                inline void*& valueOf() const { return (void*&) this -> value; }
                    };
            // }
    }
#endif
