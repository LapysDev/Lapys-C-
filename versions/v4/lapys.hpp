/**
    @author: Lapys
    @description: Experimental test version of Lapys C.
    @version: 0.0.1

    --- NOTE ---
        #Lapys:
            - Supported environment standards:
                -- ISO/IEC 14882:1998 (C++98) (1998 - 2003) - current...
*/
/* Import */
#include <cmath> // C Math
#include <cstdlib> // C Standard Library
#include <iostream> // Input-Output Stream
#include <unistd.h> // UNIX Standard
#include <windows.h> // Windows

/* Namespace > Lapys C++ */
namespace LapysCPP {
    /* Namespace > [Private] --- NOTE (Lapys) -> Define primitive abstractions. */
    namespace {
        /* Class */
            /* Boolean */
            typedef struct boolean {
                // [Private]
                private:
                    // Initialization > Value
                    unsigned char value : 1;

                // [Public]
                public:
                    // [Constructor]
                    inline boolean() : value(0u) {}

                    inline boolean(const char argument) : value(argument ? 1u : 0u) {}
                    inline boolean(const char16_t argument) : value(argument ? 1u : 0u) {}
                    inline boolean(const char32_t argument) : value(argument ? 1u : 0u) {}
                    inline boolean(const double argument) : value(argument ? 1u : 0u) {}
                    inline boolean(const float argument) : value(argument ? 1u : 0u) {}
                    inline boolean(const int argument) : value(argument ? 1u : 0u) {}
                    inline boolean(const long argument) : value(argument ? 1u : 0u) {}
                    inline boolean(const long double argument) : value(argument ? 1u : 0u) {}
                    inline boolean(const long long argument) : value(argument ? 1u : 0u) {}
                    inline boolean(const short argument) : value(argument ? 1u : 0u) {}
                    inline boolean(const signed char argument) : value(argument ? 1u : 0u) {}
                    inline boolean(const unsigned char argument) : value(argument ? 1u : 0u) {}
                    inline boolean(const unsigned int argument) : value(argument ? 1u : 0u) {}
                    inline boolean(const unsigned long argument) : value(argument ? 1u : 0u) {}
                    inline boolean(const unsigned long long argument) : value(argument ? 1u : 0u) {}
                    inline boolean(const unsigned short argument) : value(argument ? 1u : 0u) {}
                    inline boolean(void* argument) : value(NULL == argument ? 1u : 0u) {}
                    inline boolean(const void* argument) : value(NULL == argument ? 1u : 0u) {}
                    inline boolean(const wchar_t argument) : value(argument ? 1u : 0u) {}

                    inline boolean(boolean& argument) : value(argument.valueOf()) {}
                    inline boolean(boolean&& argument) : value(argument.valueOf()) {}
                    inline boolean(const boolean& argument) : value(argument.valueOf()) {}
                    inline boolean(const boolean&& argument) : value(argument.valueOf()) {}

                    // [Destructor]
                    inline ~boolean() { this -> value = 0u; }

                    // [Operator]
                        // [+]
                        inline const boolean operator +() const { return this -> value; }

                        inline const boolean operator +(const char argument) const { return (this -> value) || argument; }
                        friend const char operator +(const char argumentA, const boolean argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const char operator +(const char argumentA, boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const char operator +(const char argumentA, const boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const char operator +(const char argumentA, boolean&& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const char operator +(const char argumentA, const boolean&& argumentB) { return argumentA + argumentB.valueOf(); }

                        inline const boolean operator +(const char16_t argument) const { return (this -> value) || argument; }
                        friend const char16_t operator +(const char16_t argumentA, const boolean argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const char16_t operator +(const char16_t argumentA, boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const char16_t operator +(const char16_t argumentA, const boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const char16_t operator +(const char16_t argumentA, boolean&& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const char16_t operator +(const char16_t argumentA, const boolean&& argumentB) { return argumentA + argumentB.valueOf(); }

                        inline const boolean operator +(const char32_t argument) const { return (this -> value) || argument; }
                        friend const char32_t operator +(const char32_t argumentA, const boolean argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const char32_t operator +(const char32_t argumentA, boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const char32_t operator +(const char32_t argumentA, const boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const char32_t operator +(const char32_t argumentA, boolean&& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const char32_t operator +(const char32_t argumentA, const boolean&& argumentB) { return argumentA + argumentB.valueOf(); }

                        inline const boolean operator +(const double argument) const { return (this -> value) || argument; }
                        friend const double operator +(const double argumentA, const boolean argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const double operator +(const double argumentA, boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const double operator +(const double argumentA, const boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const double operator +(const double argumentA, boolean&& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const double operator +(const double argumentA, const boolean&& argumentB) { return argumentA + argumentB.valueOf(); }

                        inline const boolean operator +(const float argument) const { return (this -> value) || argument; }
                        friend const float operator +(const float argumentA, const boolean argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const float operator +(const float argumentA, boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const float operator +(const float argumentA, const boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const float operator +(const float argumentA, boolean&& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const float operator +(const float argumentA, const boolean&& argumentB) { return argumentA + argumentB.valueOf(); }

                        inline const boolean operator +(const int argument) const { return (this -> value) || argument; }
                        friend const int operator +(const int argumentA, const boolean argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const int operator +(const int argumentA, boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const int operator +(const int argumentA, const boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const int operator +(const int argumentA, boolean&& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const int operator +(const int argumentA, const boolean&& argumentB) { return argumentA + argumentB.valueOf(); }

                        inline const boolean operator +(const long argument) const { return (this -> value) || argument; }
                        friend const long operator +(const long argumentA, const boolean argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const long operator +(const long argumentA, boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const long operator +(const long argumentA, const boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const long operator +(const long argumentA, boolean&& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const long operator +(const long argumentA, const boolean&& argumentB) { return argumentA + argumentB.valueOf(); }

                        inline const boolean operator +(const long double argument) const { return (this -> value) || argument; }
                        friend const long double operator +(const long double argumentA, const boolean argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const long double operator +(const long double argumentA, boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const long double operator +(const long double argumentA, const boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const long double operator +(const long double argumentA, boolean&& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const long double operator +(const long double argumentA, const boolean&& argumentB) { return argumentA + argumentB.valueOf(); }

                        inline const boolean operator +(const long long argument) const { return (this -> value) || argument; }
                        friend const long long operator +(const long long argumentA, const boolean argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const long long operator +(const long long argumentA, boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const long long operator +(const long long argumentA, const boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const long long operator +(const long long argumentA, boolean&& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const long long operator +(const long long argumentA, const boolean&& argumentB) { return argumentA + argumentB.valueOf(); }

                        inline const boolean operator +(const short argument) const { return (this -> value) || argument; }
                        friend const short operator +(const short argumentA, const boolean argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const short operator +(const short argumentA, boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const short operator +(const short argumentA, const boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const short operator +(const short argumentA, boolean&& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const short operator +(const short argumentA, const boolean&& argumentB) { return argumentA + argumentB.valueOf(); }

                        inline const boolean operator +(const signed char argument) const { return (this -> value) || argument; }
                        friend const signed char operator +(const signed char argumentA, const boolean argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const signed char operator +(const signed char argumentA, boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const signed char operator +(const signed char argumentA, const boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const signed char operator +(const signed char argumentA, boolean&& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const signed char operator +(const signed char argumentA, const boolean&& argumentB) { return argumentA + argumentB.valueOf(); }

                        inline const boolean operator +(const unsigned char argument) const { return (this -> value) || argument; }
                        friend const unsigned char operator +(const unsigned char argumentA, const boolean argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const unsigned char operator +(const unsigned char argumentA, boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const unsigned char operator +(const unsigned char argumentA, const boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const unsigned char operator +(const unsigned char argumentA, boolean&& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const unsigned char operator +(const unsigned char argumentA, const boolean&& argumentB) { return argumentA + argumentB.valueOf(); }

                        inline const boolean operator +(const unsigned int argument) const { return (this -> value) || argument; }
                        friend const unsigned int operator +(const unsigned int argumentA, const boolean argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const unsigned int operator +(const unsigned int argumentA, boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const unsigned int operator +(const unsigned int argumentA, const boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const unsigned int operator +(const unsigned int argumentA, boolean&& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const unsigned int operator +(const unsigned int argumentA, const boolean&& argumentB) { return argumentA + argumentB.valueOf(); }

                        inline const boolean operator +(const unsigned long argument) const { return (this -> value) || argument; }
                        friend const unsigned long operator +(const unsigned long argumentA, const boolean argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const unsigned long operator +(const unsigned long argumentA, boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const unsigned long operator +(const unsigned long argumentA, const boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const unsigned long operator +(const unsigned long argumentA, boolean&& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const unsigned long operator +(const unsigned long argumentA, const boolean&& argumentB) { return argumentA + argumentB.valueOf(); }

                        inline const boolean operator +(const unsigned long long argument) const { return (this -> value) || argument; }
                        friend const unsigned long long operator +(const unsigned long long argumentA, const boolean argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const unsigned long long operator +(const unsigned long long argumentA, boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const unsigned long long operator +(const unsigned long long argumentA, const boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const unsigned long long operator +(const unsigned long long argumentA, boolean&& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const unsigned long long operator +(const unsigned long long argumentA, const boolean&& argumentB) { return argumentA + argumentB.valueOf(); }

                        inline const boolean operator +(const unsigned short argument) const { return (this -> value) || argument; }
                        friend const short operator +(const unsigned short argumentA, const boolean argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const short operator +(const unsigned short argumentA, boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const short operator +(const unsigned short argumentA, const boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const short operator +(const unsigned short argumentA, boolean&& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const short operator +(const unsigned short argumentA, const boolean&& argumentB) { return argumentA + argumentB.valueOf(); }

                        inline const boolean operator +(void* argument) const { return (this -> value) || (NULL != argument); }
                        inline const boolean operator +(const void* argument) const { return (this -> value) || (NULL != argument); }

                        inline const boolean operator +(const wchar_t argument) const { return (this -> value) || argument; }
                        friend const wchar_t operator +(const wchar_t argumentA, const boolean argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const wchar_t operator +(const wchar_t argumentA, boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const wchar_t operator +(const wchar_t argumentA, const boolean& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const wchar_t operator +(const wchar_t argumentA, boolean&& argumentB) { return argumentA + argumentB.valueOf(); }
                        friend const wchar_t operator +(const wchar_t argumentA, const boolean&& argumentB) { return argumentA + argumentB.valueOf(); }

                        const boolean operator +(boolean& argument) { return this -> value || argument.valueOf(); }
                        const boolean operator +(boolean&& argument) { return this -> value || argument.valueOf(); }
                        const boolean operator +(const boolean& argument) { return this -> value || argument.valueOf(); }
                        const boolean operator +(const boolean&& argument) { return this -> value || argument.valueOf(); }

                        // [-]
                        inline const boolean operator -() const { return this -> value; }

                        inline const boolean operator -(const char argument) const { return !(this -> value || argument); }
                        friend const char operator -(const char argumentA, const boolean argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const char operator -(const char argumentA, boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const char operator -(const char argumentA, const boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const char operator -(const char argumentA, boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const char operator -(const char argumentA, const boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }

                        inline const boolean operator -(const char16_t argument) const { return !(this -> value || argument); }
                        friend const char16_t operator -(const char16_t argumentA, const boolean argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const char16_t operator -(const char16_t argumentA, boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const char16_t operator -(const char16_t argumentA, const boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const char16_t operator -(const char16_t argumentA, boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const char16_t operator -(const char16_t argumentA, const boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }

                        inline const boolean operator -(const char32_t argument) const { return !(this -> value || argument); }
                        friend const char32_t operator -(const char32_t argumentA, const boolean argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const char32_t operator -(const char32_t argumentA, boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const char32_t operator -(const char32_t argumentA, const boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const char32_t operator -(const char32_t argumentA, boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const char32_t operator -(const char32_t argumentA, const boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }

                        inline const boolean operator -(const double argument) const { return !(this -> value || argument); }
                        friend const double operator -(const double argumentA, const boolean argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const double operator -(const double argumentA, boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const double operator -(const double argumentA, const boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const double operator -(const double argumentA, boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const double operator -(const double argumentA, const boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }

                        inline const boolean operator -(const float argument) const { return !(this -> value || argument); }
                        friend const float operator -(const float argumentA, const boolean argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const float operator -(const float argumentA, boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const float operator -(const float argumentA, const boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const float operator -(const float argumentA, boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const float operator -(const float argumentA, const boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }

                        inline const boolean operator -(const int argument) const { return !(this -> value || argument); }
                        friend const int operator -(const int argumentA, const boolean argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const int operator -(const int argumentA, boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const int operator -(const int argumentA, const boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const int operator -(const int argumentA, boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const int operator -(const int argumentA, const boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }

                        inline const boolean operator -(const long argument) const { return !(this -> value || argument); }
                        friend const long operator -(const long argumentA, const boolean argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const long operator -(const long argumentA, boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const long operator -(const long argumentA, const boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const long operator -(const long argumentA, boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const long operator -(const long argumentA, const boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }

                        inline const boolean operator -(const long double argument) const { return !(this -> value || argument); }
                        friend const long double operator -(const long double argumentA, const boolean argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const long double operator -(const long double argumentA, boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const long double operator -(const long double argumentA, const boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const long double operator -(const long double argumentA, boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const long double operator -(const long double argumentA, const boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }

                        inline const boolean operator -(const long long argument) const { return !(this -> value || argument); }
                        friend const long long operator -(const long long argumentA, const boolean argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const long long operator -(const long long argumentA, boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const long long operator -(const long long argumentA, const boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const long long operator -(const long long argumentA, boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const long long operator -(const long long argumentA, const boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }

                        inline const boolean operator -(const short argument) const { return !(this -> value || argument); }
                        friend const short operator -(const short argumentA, const boolean argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const short operator -(const short argumentA, boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const short operator -(const short argumentA, const boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const short operator -(const short argumentA, boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const short operator -(const short argumentA, const boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }

                        inline const boolean operator -(const signed char argument) const { return !(this -> value || argument); }
                        friend const signed char operator -(const signed char argumentA, const boolean argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const signed char operator -(const signed char argumentA, boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const signed char operator -(const signed char argumentA, const boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const signed char operator -(const signed char argumentA, boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const signed char operator -(const signed char argumentA, const boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }

                        inline const boolean operator -(const unsigned char argument) const { return !(this -> value || argument); }
                        friend const unsigned char operator -(const unsigned char argumentA, const boolean argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned char operator -(const unsigned char argumentA, boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned char operator -(const unsigned char argumentA, const boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned char operator -(const unsigned char argumentA, boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned char operator -(const unsigned char argumentA, const boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }

                        inline const boolean operator -(const unsigned int argument) const { return !(this -> value || argument); }
                        friend const unsigned int operator -(const unsigned int argumentA, const boolean argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned int operator -(const unsigned int argumentA, boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned int operator -(const unsigned int argumentA, const boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned int operator -(const unsigned int argumentA, boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned int operator -(const unsigned int argumentA, const boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }

                        inline const boolean operator -(const unsigned long argument) const { return !(this -> value || argument); }
                        friend const unsigned long operator -(const unsigned long argumentA, const boolean argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned long operator -(const unsigned long argumentA, boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned long operator -(const unsigned long argumentA, const boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned long operator -(const unsigned long argumentA, boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned long operator -(const unsigned long argumentA, const boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }

                        inline const boolean operator -(const unsigned long long argument) const { return !(this -> value || argument); }
                        friend const unsigned long long operator -(const unsigned long long argumentA, const boolean argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned long long operator -(const unsigned long long argumentA, boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned long long operator -(const unsigned long long argumentA, const boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned long long operator -(const unsigned long long argumentA, boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned long long operator -(const unsigned long long argumentA, const boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }

                        inline const boolean operator -(const unsigned short argument) const { return !(this -> value || argument); }
                        friend const unsigned short operator -(const unsigned short argumentA, const boolean argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned short operator -(const unsigned short argumentA, boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned short operator -(const unsigned short argumentA, const boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned short operator -(const unsigned short argumentA, boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const unsigned short operator -(const unsigned short argumentA, const boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }

                        inline const boolean operator -(void* argument) const { return !(this -> value) && (NULL == argument); }
                        inline const boolean operator -(const void* argument) const { return !(this -> value) && (NULL == argument); }

                        inline const boolean operator -(const wchar_t argument) const { return !(this -> value || argument); }
                        friend const wchar_t operator -(const wchar_t argumentA, const boolean argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const wchar_t operator -(const wchar_t argumentA, boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const wchar_t operator -(const wchar_t argumentA, const boolean& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const wchar_t operator -(const wchar_t argumentA, boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }
                        friend const wchar_t operator -(const wchar_t argumentA, const boolean&& argumentB) { return !(argumentA || argumentB.valueOf()); }

                        const boolean operator -(boolean& argument) { return !(this -> value || argument.valueOf()); }
                        const boolean operator -(boolean&& argument) { return !(this -> value || argument.valueOf()); }
                        const boolean operator -(const boolean& argument) { return !(this -> value || argument.valueOf()); }
                        const boolean operator -(const boolean&& argument) { return !(this -> value || argument.valueOf()); }

                        // [*]
                        inline const boolean operator *(const char argument) const { return this -> value && argument; }
                        friend const char operator *(const char argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char operator *(const char argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char operator *(const char argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char operator *(const char argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char operator *(const char argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator *(const char16_t argument) const { return this -> value && argument; }
                        friend const char16_t operator *(const char16_t argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char16_t operator *(const char16_t argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char16_t operator *(const char16_t argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char16_t operator *(const char16_t argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char16_t operator *(const char16_t argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator *(const char32_t argument) const { return this -> value && argument; }
                        friend const char32_t operator *(const char32_t argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char32_t operator *(const char32_t argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char32_t operator *(const char32_t argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char32_t operator *(const char32_t argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char32_t operator *(const char32_t argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator *(const double argument) const { return this -> value && argument; }
                        friend const double operator *(const double argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const double operator *(const double argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const double operator *(const double argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const double operator *(const double argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const double operator *(const double argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator *(const float argument) const { return this -> value && argument; }
                        friend const float operator *(const float argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const float operator *(const float argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const float operator *(const float argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const float operator *(const float argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const float operator *(const float argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator *(const int argument) const { return this -> value && argument; }
                        friend const int operator *(const int argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const int operator *(const int argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const int operator *(const int argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const int operator *(const int argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const int operator *(const int argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator *(const long argument) const { return this -> value && argument; }
                        friend const long operator *(const long argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long operator *(const long argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long operator *(const long argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long operator *(const long argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long operator *(const long argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator *(const long double argument) const { return this -> value && argument; }
                        friend const long double operator *(const long double argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long double operator *(const long double argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long double operator *(const long double argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long double operator *(const long double argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long double operator *(const long double argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator *(const long long argument) const { return this -> value && argument; }
                        friend const long long operator *(const long long argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long long operator *(const long long argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long long operator *(const long long argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long long operator *(const long long argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long long operator *(const long long argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator *(const short argument) const { return this -> value && argument; }
                        friend const short operator *(const short argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const short operator *(const short argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const short operator *(const short argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const short operator *(const short argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const short operator *(const short argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator *(const signed char argument) const { return this -> value && argument; }
                        friend const signed char operator *(const signed char argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const signed char operator *(const signed char argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const signed char operator *(const signed char argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const signed char operator *(const signed char argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const signed char operator *(const signed char argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator *(const unsigned char argument) const { return this -> value && argument; }
                        friend const unsigned char operator *(const unsigned char argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned char operator *(const unsigned char argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned char operator *(const unsigned char argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned char operator *(const unsigned char argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned char operator *(const unsigned char argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator *(const unsigned int argument) const { return this -> value && argument; }
                        friend const unsigned int operator *(const unsigned int argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned int operator *(const unsigned int argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned int operator *(const unsigned int argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned int operator *(const unsigned int argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned int operator *(const unsigned int argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator *(const unsigned long argument) const { return this -> value && argument; }
                        friend const unsigned long operator *(const unsigned long argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long operator *(const unsigned long argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long operator *(const unsigned long argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long operator *(const unsigned long argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long operator *(const unsigned long argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator *(const unsigned long long argument) const { return this -> value && argument; }
                        friend const unsigned long long operator *(const unsigned long long argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long long operator *(const unsigned long long argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long long operator *(const unsigned long long argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long long operator *(const unsigned long long argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long long operator *(const unsigned long long argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator *(const unsigned short argument) const { return this -> value && argument; }
                        friend const unsigned short operator *(const unsigned short argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned short operator *(const unsigned short argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned short operator *(const unsigned short argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned short operator *(const unsigned short argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned short operator *(const unsigned short argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator *(void* argument) const { return this -> value && (NULL != argument); }
                        inline const boolean operator *(const void* argument) const { return this -> value && (NULL != argument); }

                        inline const boolean operator *(const wchar_t argument) const { return this -> value && argument; }
                        friend const wchar_t operator *(const wchar_t argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const wchar_t operator *(const wchar_t argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const wchar_t operator *(const wchar_t argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const wchar_t operator *(const wchar_t argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const wchar_t operator *(const wchar_t argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator *(boolean& argument) { return this -> value && argument.valueOf(); }
                        const boolean operator *(boolean&& argument) { return this -> value && argument.valueOf(); }
                        const boolean operator *(const boolean& argument) { return this -> value && argument.valueOf(); }
                        const boolean operator *(const boolean&& argument) { return this -> value && argument.valueOf(); }

                        // [/]
                        const boolean operator /(const char argument) { return this -> value && argument; }
                        friend const char operator /(const char argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char operator /(const char argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char operator /(const char argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char operator /(const char argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char operator /(const char argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator /(const char16_t argument) { return this -> value && argument; }
                        friend const char16_t operator /(const char16_t argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char16_t operator /(const char16_t argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char16_t operator /(const char16_t argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char16_t operator /(const char16_t argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char16_t operator /(const char16_t argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator /(const char32_t argument) { return this -> value && argument; }
                        friend const char32_t operator /(const char32_t argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char32_t operator /(const char32_t argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char32_t operator /(const char32_t argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char32_t operator /(const char32_t argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char32_t operator /(const char32_t argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator /(const double argument) { return this -> value && argument; }
                        friend const double operator /(const double argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const double operator /(const double argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const double operator /(const double argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const double operator /(const double argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const double operator /(const double argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator /(const float argument) { return this -> value && argument; }
                        friend const float operator /(const float argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const float operator /(const float argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const float operator /(const float argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const float operator /(const float argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const float operator /(const float argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator /(const int argument) { return this -> value && argument; }
                        friend const int operator /(const int argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const int operator /(const int argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const int operator /(const int argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const int operator /(const int argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const int operator /(const int argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator /(const long argument) { return this -> value && argument; }
                        friend const long operator /(const long argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long operator /(const long argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long operator /(const long argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long operator /(const long argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long operator /(const long argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator /(const long double argument) { return this -> value && argument; }
                        friend const long double operator /(const long double argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long double operator /(const long double argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long double operator /(const long double argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long double operator /(const long double argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long double operator /(const long double argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator /(const long long argument) { return this -> value && argument; }
                        friend const long long operator /(const long long argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long long operator /(const long long argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long long operator /(const long long argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long long operator /(const long long argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long long operator /(const long long argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator /(const short argument) { return this -> value && argument; }
                        friend const short operator /(const short argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const short operator /(const short argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const short operator /(const short argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const short operator /(const short argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const short operator /(const short argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator /(const signed char argument) { return this -> value && argument; }
                        friend const signed char operator /(const signed char argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const signed char operator /(const signed char argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const signed char operator /(const signed char argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const signed char operator /(const signed char argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const signed char operator /(const signed char argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator /(const unsigned char argument) { return this -> value && argument; }
                        friend const unsigned char operator /(const unsigned char argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned char operator /(const unsigned char argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned char operator /(const unsigned char argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned char operator /(const unsigned char argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned char operator /(const unsigned char argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator /(const unsigned int argument) { return this -> value && argument; }
                        friend const unsigned int operator /(const unsigned int argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned int operator /(const unsigned int argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned int operator /(const unsigned int argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned int operator /(const unsigned int argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned int operator /(const unsigned int argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator /(const unsigned long argument) { return this -> value && argument; }
                        friend const unsigned long operator /(const unsigned long argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long operator /(const unsigned long argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long operator /(const unsigned long argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long operator /(const unsigned long argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long operator /(const unsigned long argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator /(const unsigned long long argument) { return this -> value && argument; }
                        friend const unsigned long long operator /(const unsigned long long argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long long operator /(const unsigned long long argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long long operator /(const unsigned long long argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long long operator /(const unsigned long long argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long long operator /(const unsigned long long argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator /(const unsigned short argument) { return this -> value && argument; }
                        friend const unsigned short operator /(const unsigned short argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned short operator /(const unsigned short argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned short operator /(const unsigned short argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned short operator /(const unsigned short argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned short operator /(const unsigned short argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator /(void* argument) { return this -> value && (NULL != argument); }
                        const boolean operator /(const void* argument) { return this -> value && (NULL != argument); }

                        const boolean operator /(const wchar_t argument) { return this -> value && argument; }
                        friend const wchar_t operator /(const wchar_t argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const wchar_t operator /(const wchar_t argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const wchar_t operator /(const wchar_t argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const wchar_t operator /(const wchar_t argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const wchar_t operator /(const wchar_t argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator /(boolean& argument) { return this -> value && argument.valueOf(); }
                        const boolean operator /(boolean&& argument) { return this -> value && argument.valueOf(); }
                        const boolean operator /(const boolean& argument) { return this -> value && argument.valueOf(); }
                        const boolean operator /(const boolean&& argument) { return this -> value && argument.valueOf(); }

                        // [%]
                        inline const boolean operator %(const char) { return 0; }
                        friend const char operator %(const char argumentA, const boolean argumentB) { return 0; }
                        friend const char operator %(const char argumentA, boolean& argumentB) { return 0; }
                        friend const char operator %(const char argumentA, const boolean& argumentB) { return 0; }
                        friend const char operator %(const char argumentA, boolean&& argumentB) { return 0; }
                        friend const char operator %(const char argumentA, const boolean&& argumentB) { return 0; }

                        inline const boolean operator %(const char16_t) { return 0; }
                        friend const char16_t operator %(const char16_t argumentA, const boolean argumentB) { return 0; }
                        friend const char16_t operator %(const char16_t argumentA, boolean& argumentB) { return 0; }
                        friend const char16_t operator %(const char16_t argumentA, const boolean& argumentB) { return 0; }
                        friend const char16_t operator %(const char16_t argumentA, boolean&& argumentB) { return 0; }
                        friend const char16_t operator %(const char16_t argumentA, const boolean&& argumentB) { return 0; }

                        inline const boolean operator %(const char32_t) { return 0; }
                        friend const char32_t operator %(const char32_t argumentA, const boolean argumentB) { return 0; }
                        friend const char32_t operator %(const char32_t argumentA, boolean& argumentB) { return 0; }
                        friend const char32_t operator %(const char32_t argumentA, const boolean& argumentB) { return 0; }
                        friend const char32_t operator %(const char32_t argumentA, boolean&& argumentB) { return 0; }
                        friend const char32_t operator %(const char32_t argumentA, const boolean&& argumentB) { return 0; }

                        inline const boolean operator %(const double) { return 0; }
                        friend const double operator %(const double argumentA, const boolean argumentB) { return 0; }
                        friend const double operator %(const double argumentA, boolean& argumentB) { return 0; }
                        friend const double operator %(const double argumentA, const boolean& argumentB) { return 0; }
                        friend const double operator %(const double argumentA, boolean&& argumentB) { return 0; }
                        friend const double operator %(const double argumentA, const boolean&& argumentB) { return 0; }

                        inline const boolean operator %(const float) { return 0; }
                        friend const float operator %(const float argumentA, const boolean argumentB) { return 0; }
                        friend const float operator %(const float argumentA, boolean& argumentB) { return 0; }
                        friend const float operator %(const float argumentA, const boolean& argumentB) { return 0; }
                        friend const float operator %(const float argumentA, boolean&& argumentB) { return 0; }
                        friend const float operator %(const float argumentA, const boolean&& argumentB) { return 0; }

                        inline const boolean operator %(const int) { return 0; }
                        friend const int operator %(const int argumentA, const boolean argumentB) { return 0; }
                        friend const int operator %(const int argumentA, boolean& argumentB) { return 0; }
                        friend const int operator %(const int argumentA, const boolean& argumentB) { return 0; }
                        friend const int operator %(const int argumentA, boolean&& argumentB) { return 0; }
                        friend const int operator %(const int argumentA, const boolean&& argumentB) { return 0; }

                        inline const boolean operator %(const long) { return 0; }
                        friend const long operator %(const long argumentA, const boolean argumentB) { return 0; }
                        friend const long operator %(const long argumentA, boolean& argumentB) { return 0; }
                        friend const long operator %(const long argumentA, const boolean& argumentB) { return 0; }
                        friend const long operator %(const long argumentA, boolean&& argumentB) { return 0; }
                        friend const long operator %(const long argumentA, const boolean&& argumentB) { return 0; }

                        inline const boolean operator %(const long double) { return 0; }
                        friend const double operator %(const long double argumentA, const boolean argumentB) { return 0; }
                        friend const double operator %(const long double argumentA, boolean& argumentB) { return 0; }
                        friend const double operator %(const long double argumentA, const boolean& argumentB) { return 0; }
                        friend const double operator %(const long double argumentA, boolean&& argumentB) { return 0; }
                        friend const double operator %(const long double argumentA, const boolean&& argumentB) { return 0; }

                        inline const boolean operator %(const long long) { return 0; }
                        friend const boolean operator %(const long long argumentA, const boolean argumentB) { return 0; }
                        friend const boolean operator %(const long long argumentA, boolean& argumentB) { return 0; }
                        friend const boolean operator %(const long long argumentA, const boolean& argumentB) { return 0; }
                        friend const boolean operator %(const long long argumentA, boolean&& argumentB) { return 0; }
                        friend const boolean operator %(const long long argumentA, const boolean&& argumentB) { return 0; }

                        inline const boolean operator %(const short) { return 0; }
                        friend const short operator %(const short argumentA, const boolean argumentB) { return 0; }
                        friend const short operator %(const short argumentA, boolean& argumentB) { return 0; }
                        friend const short operator %(const short argumentA, const boolean& argumentB) { return 0; }
                        friend const short operator %(const short argumentA, boolean&& argumentB) { return 0; }
                        friend const short operator %(const short argumentA, const boolean&& argumentB) { return 0; }

                        inline const boolean operator %(const signed char) { return 0; }
                        friend const signed char operator %(const signed char argumentA, const boolean argumentB) { return 0; }
                        friend const signed char operator %(const signed char argumentA, boolean& argumentB) { return 0; }
                        friend const signed char operator %(const signed char argumentA, const boolean& argumentB) { return 0; }
                        friend const signed char operator %(const signed char argumentA, boolean&& argumentB) { return 0; }
                        friend const signed char operator %(const signed char argumentA, const boolean&& argumentB) { return 0; }

                        inline const boolean operator %(const unsigned char) { return 0; }
                        friend const unsigned char operator %(const unsigned char argumentA, const boolean argumentB) { return 0; }
                        friend const unsigned char operator %(const unsigned char argumentA, boolean& argumentB) { return 0; }
                        friend const unsigned char operator %(const unsigned char argumentA, const boolean& argumentB) { return 0; }
                        friend const unsigned char operator %(const unsigned char argumentA, boolean&& argumentB) { return 0; }
                        friend const unsigned char operator %(const unsigned char argumentA, const boolean&& argumentB) { return 0; }

                        inline const boolean operator %(const unsigned int) { return 0; }
                        friend const unsigned int operator %(const unsigned int argumentA, const boolean argumentB) { return 0; }
                        friend const unsigned int operator %(const unsigned int argumentA, boolean& argumentB) { return 0; }
                        friend const unsigned int operator %(const unsigned int argumentA, const boolean& argumentB) { return 0; }
                        friend const unsigned int operator %(const unsigned int argumentA, boolean&& argumentB) { return 0; }
                        friend const unsigned int operator %(const unsigned int argumentA, const boolean&& argumentB) { return 0; }

                        inline const boolean operator %(const unsigned long) { return 0; }
                        friend const unsigned long operator %(const unsigned long argumentA, const boolean argumentB) { return 0; }
                        friend const unsigned long operator %(const unsigned long argumentA, boolean& argumentB) { return 0; }
                        friend const unsigned long operator %(const unsigned long argumentA, const boolean& argumentB) { return 0; }
                        friend const unsigned long operator %(const unsigned long argumentA, boolean&& argumentB) { return 0; }
                        friend const unsigned long operator %(const unsigned long argumentA, const boolean&& argumentB) { return 0; }

                        inline const boolean operator %(const unsigned long long) { return 0; }
                        friend const unsigned long long operator %(const unsigned long long argumentA, const boolean argumentB) { return 0; }
                        friend const unsigned long long operator %(const unsigned long long argumentA, boolean& argumentB) { return 0; }
                        friend const unsigned long long operator %(const unsigned long long argumentA, const boolean& argumentB) { return 0; }
                        friend const unsigned long long operator %(const unsigned long long argumentA, boolean&& argumentB) { return 0; }
                        friend const unsigned long long operator %(const unsigned long long argumentA, const boolean&& argumentB) { return 0; }

                        inline const boolean operator %(const unsigned short) { return 0; }
                        friend const unsigned short operator %(const unsigned short argumentA, const boolean argumentB) { return 0; }
                        friend const unsigned short operator %(const unsigned short argumentA, boolean& argumentB) { return 0; }
                        friend const unsigned short operator %(const unsigned short argumentA, const boolean& argumentB) { return 0; }
                        friend const unsigned short operator %(const unsigned short argumentA, boolean&& argumentB) { return 0; }
                        friend const unsigned short operator %(const unsigned short argumentA, const boolean&& argumentB) { return 0; }

                        inline const boolean operator %(void*) { return 0; }
                        inline const boolean operator %(const void*) { return 0; }

                        inline const boolean operator %(const wchar_t) { return 0; }
                        friend const wchar_t operator %(const wchar_t argumentA, const boolean argumentB) { return 0; }
                        friend const wchar_t operator %(const wchar_t argumentA, boolean& argumentB) { return 0; }
                        friend const wchar_t operator %(const wchar_t argumentA, const boolean& argumentB) { return 0; }
                        friend const wchar_t operator %(const wchar_t argumentA, boolean&& argumentB) { return 0; }
                        friend const wchar_t operator %(const wchar_t argumentA, const boolean&& argumentB) { return 0; }

                        inline const boolean operator %(boolean&) { return 0; }
                        inline const boolean operator %(boolean&&) { return 0; }
                        inline const boolean operator %(const boolean&) { return 0; }
                        inline const boolean operator %(const boolean&&) { return 0; }

                        // [^]
                        const boolean operator ^(const char argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        friend const char operator ^(const char argumentA, const boolean argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const char operator ^(const char argumentA, boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const char operator ^(const char argumentA, const boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const char operator ^(const char argumentA, boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const char operator ^(const char argumentA, const boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }

                        const boolean operator ^(const char16_t argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        friend const char16_t operator ^(const char16_t argumentA, const boolean argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const char16_t operator ^(const char16_t argumentA, boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const char16_t operator ^(const char16_t argumentA, const boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const char16_t operator ^(const char16_t argumentA, boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const char16_t operator ^(const char16_t argumentA, const boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }

                        const boolean operator ^(const char32_t argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        friend const char32_t operator ^(const char32_t argumentA, const boolean argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const char32_t operator ^(const char32_t argumentA, boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const char32_t operator ^(const char32_t argumentA, const boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const char32_t operator ^(const char32_t argumentA, boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const char32_t operator ^(const char32_t argumentA, const boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }

                        const boolean operator ^(const double argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        friend const double operator ^(const double argumentA, const boolean argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const double operator ^(const double argumentA, boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const double operator ^(const double argumentA, const boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const double operator ^(const double argumentA, boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const double operator ^(const double argumentA, const boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }

                        const boolean operator ^(const float argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        friend const float operator ^(const float argumentA, const boolean argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const float operator ^(const float argumentA, boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const float operator ^(const float argumentA, const boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const float operator ^(const float argumentA, boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const float operator ^(const float argumentA, const boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }

                        const boolean operator ^(const int argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        friend const int operator ^(const int argumentA, const boolean argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const int operator ^(const int argumentA, boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const int operator ^(const int argumentA, const boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const int operator ^(const int argumentA, boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const int operator ^(const int argumentA, const boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }

                        const boolean operator ^(const long argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        friend const long operator ^(const long argumentA, const boolean argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const long operator ^(const long argumentA, boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const long operator ^(const long argumentA, const boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const long operator ^(const long argumentA, boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const long operator ^(const long argumentA, const boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }

                        const boolean operator ^(const long double argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        friend const long double operator ^(const long double argumentA, const boolean argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const long double operator ^(const long double argumentA, boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const long double operator ^(const long double argumentA, const boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const long double operator ^(const long double argumentA, boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const long double operator ^(const long double argumentA, const boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }

                        const boolean operator ^(const long long argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        friend const long long operator ^(const long long argumentA, const boolean argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const long long operator ^(const long long argumentA, boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const long long operator ^(const long long argumentA, const boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const long long operator ^(const long long argumentA, boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const long long operator ^(const long long argumentA, const boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }

                        const boolean operator ^(const short argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        friend const short operator ^(const short argumentA, const boolean argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const short operator ^(const short argumentA, boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const short operator ^(const short argumentA, const boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const short operator ^(const short argumentA, boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const short operator ^(const short argumentA, const boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }

                        const boolean operator ^(const signed char argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        friend const signed char operator ^(const signed char argumentA, const boolean argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const signed char operator ^(const signed char argumentA, boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const signed char operator ^(const signed char argumentA, const boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const signed char operator ^(const signed char argumentA, boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const signed char operator ^(const signed char argumentA, const boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }

                        const boolean operator ^(const unsigned char argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        friend const unsigned char operator ^(const unsigned char argumentA, const boolean argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned char operator ^(const unsigned char argumentA, boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned char operator ^(const unsigned char argumentA, const boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned char operator ^(const unsigned char argumentA, boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned char operator ^(const unsigned char argumentA, const boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }

                        const boolean operator ^(const unsigned int argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        friend const unsigned int operator ^(const unsigned int argumentA, const boolean argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned int operator ^(const unsigned int argumentA, boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned int operator ^(const unsigned int argumentA, const boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned int operator ^(const unsigned int argumentA, boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned int operator ^(const unsigned int argumentA, const boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }

                        const boolean operator ^(const unsigned long argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        friend const unsigned long operator ^(const unsigned long argumentA, const boolean argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned long operator ^(const unsigned long argumentA, boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned long operator ^(const unsigned long argumentA, const boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned long operator ^(const unsigned long argumentA, boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned long operator ^(const unsigned long argumentA, const boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }

                        const boolean operator ^(const unsigned long long argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        friend const unsigned long long operator ^(const unsigned long long argumentA, const boolean argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned long long operator ^(const unsigned long long argumentA, boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned long long operator ^(const unsigned long long argumentA, const boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned long long operator ^(const unsigned long long argumentA, boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned long long operator ^(const unsigned long long argumentA, const boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }

                        const boolean operator ^(const unsigned short argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        friend const unsigned short operator ^(const unsigned short argumentA, const boolean argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned short operator ^(const unsigned short argumentA, boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned short operator ^(const unsigned short argumentA, const boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned short operator ^(const unsigned short argumentA, boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const unsigned short operator ^(const unsigned short argumentA, const boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }

                        const boolean operator ^(void* argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        const boolean operator ^(const void* argument) const { return this -> value ^ boolean(argument).valueOf(); }

                        const boolean operator ^(const wchar_t argument) const { return this -> value ^ boolean(argument).valueOf(); }
                        friend const wchar_t operator ^(const wchar_t argumentA, const boolean argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const wchar_t operator ^(const wchar_t argumentA, boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const wchar_t operator ^(const wchar_t argumentA, const boolean& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const wchar_t operator ^(const wchar_t argumentA, boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }
                        friend const wchar_t operator ^(const wchar_t argumentA, const boolean&& argumentB) { return boolean(argumentA).valueOf() ^ argumentB.valueOf(); }

                        const boolean operator ^(boolean& argument) { return this -> value ^ argument.valueOf(); }
                        const boolean operator ^(boolean&& argument) { return this -> value ^ argument.valueOf(); }
                        const boolean operator ^(const boolean& argument) { return this -> value ^ argument.valueOf(); }
                        const boolean operator ^(const boolean&& argument) { return this -> value ^ argument.valueOf(); }

                        // [&]
                        inline const boolean operator &(const char argument) const { return this -> value && argument; }
                        friend const char operator &(const char argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char operator &(const char argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char operator &(const char argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char operator &(const char argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char operator &(const char argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &(const char16_t argument) const { return this -> value && argument; }
                        friend const char16_t operator &(const char16_t argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char16_t operator &(const char16_t argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char16_t operator &(const char16_t argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char16_t operator &(const char16_t argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char16_t operator &(const char16_t argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &(const char32_t argument) const { return this -> value && argument; }
                        friend const char32_t operator &(const char32_t argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char32_t operator &(const char32_t argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char32_t operator &(const char32_t argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char32_t operator &(const char32_t argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const char32_t operator &(const char32_t argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &(const double argument) const { return this -> value && argument; }
                        friend const double operator &(const double argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const double operator &(const double argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const double operator &(const double argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const double operator &(const double argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const double operator &(const double argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &(const float argument) const { return this -> value && argument; }
                        friend const float operator &(const float argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const float operator &(const float argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const float operator &(const float argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const float operator &(const float argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const float operator &(const float argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &(const int argument) const { return this -> value && argument; }
                        friend const int operator &(const int argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const int operator &(const int argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const int operator &(const int argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const int operator &(const int argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const int operator &(const int argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &(const long argument) const { return this -> value && argument; }
                        friend const long operator &(const long argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long operator &(const long argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long operator &(const long argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long operator &(const long argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long operator &(const long argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &(const long double argument) const { return this -> value && argument; }
                        friend const long double operator &(const long double argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long double operator &(const long double argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long double operator &(const long double argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long double operator &(const long double argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long double operator &(const long double argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &(const long long argument) const { return this -> value && argument; }
                        friend const long long operator &(const long long argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long long operator &(const long long argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long long operator &(const long long argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long long operator &(const long long argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const long long operator &(const long long argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &(const short argument) const { return this -> value && argument; }
                        friend const short operator &(const short argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const short operator &(const short argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const short operator &(const short argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const short operator &(const short argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const short operator &(const short argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &(const signed char argument) const { return this -> value && argument; }
                        friend const signed char operator &(const signed char argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const signed char operator &(const signed char argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const signed char operator &(const signed char argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const signed char operator &(const signed char argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const signed char operator &(const signed char argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &(const unsigned char argument) const { return this -> value && argument; }
                        friend const unsigned char operator &(const unsigned char argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned char operator &(const unsigned char argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned char operator &(const unsigned char argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned char operator &(const unsigned char argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned char operator &(const unsigned char argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &(const unsigned int argument) const { return this -> value && argument; }
                        friend const unsigned int operator &(const unsigned int argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned int operator &(const unsigned int argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned int operator &(const unsigned int argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned int operator &(const unsigned int argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned int operator &(const unsigned int argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &(const unsigned long argument) const { return this -> value && argument; }
                        friend const unsigned long operator &(const unsigned long argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long operator &(const unsigned long argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long operator &(const unsigned long argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long operator &(const unsigned long argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long operator &(const unsigned long argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &(const unsigned long long argument) const { return this -> value && argument; }
                        friend const unsigned long long operator &(const unsigned long long argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long long operator &(const unsigned long long argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long long operator &(const unsigned long long argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long long operator &(const unsigned long long argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned long long operator &(const unsigned long long argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &(const unsigned short argument) const { return this -> value && argument; }
                        friend const unsigned short operator &(const unsigned short argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned short operator &(const unsigned short argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned short operator &(const unsigned short argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned short operator &(const unsigned short argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const unsigned short operator &(const unsigned short argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &(void* argument) const { return this -> value && (NULL != argument); }
                        inline const boolean operator &(const void* argument) const { return this -> value && (NULL != argument); }

                        inline const boolean operator &(const wchar_t argument) const { return this -> value && argument; }
                        friend const wchar_t operator &(const wchar_t argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const wchar_t operator &(const wchar_t argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const wchar_t operator &(const wchar_t argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const wchar_t operator &(const wchar_t argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const wchar_t operator &(const wchar_t argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator &(boolean& argument) { return this -> value && argument.valueOf(); }
                        const boolean operator &(boolean&& argument) { return this -> value && argument.valueOf(); }
                        const boolean operator &(const boolean& argument) { return this -> value && argument.valueOf(); }
                        const boolean operator &(const boolean&& argument) { return this -> value && argument.valueOf(); }

                        // [|]
                        inline const boolean operator |(const char argument) const { return this -> value || argument; }
                        friend const char operator |(const char argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const char operator |(const char argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const char operator |(const char argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const char operator |(const char argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const char operator |(const char argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator |(const char16_t argument) const { return this -> value || argument; }
                        friend const char16_t operator |(const char16_t argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const char16_t operator |(const char16_t argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const char16_t operator |(const char16_t argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const char16_t operator |(const char16_t argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const char16_t operator |(const char16_t argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator |(const char32_t argument) const { return this -> value || argument; }
                        friend const char32_t operator |(const char32_t argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const char32_t operator |(const char32_t argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const char32_t operator |(const char32_t argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const char32_t operator |(const char32_t argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const char32_t operator |(const char32_t argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator |(const double argument) const { return this -> value || argument; }
                        friend const double operator |(const double argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const double operator |(const double argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const double operator |(const double argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const double operator |(const double argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const double operator |(const double argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator |(const float argument) const { return this -> value || argument; }
                        friend const float operator |(const float argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const float operator |(const float argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const float operator |(const float argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const float operator |(const float argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const float operator |(const float argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator |(const int argument) const { return this -> value || argument; }
                        friend const int operator |(const int argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const int operator |(const int argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const int operator |(const int argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const int operator |(const int argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const int operator |(const int argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator |(const long argument) const { return this -> value || argument; }
                        friend const long operator |(const long argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const long operator |(const long argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const long operator |(const long argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const long operator |(const long argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const long operator |(const long argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator |(const long double argument) const { return this -> value || argument; }
                        friend const long double operator |(const long double argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const long double operator |(const long double argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const long double operator |(const long double argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const long double operator |(const long double argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const long double operator |(const long double argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator |(const long long argument) const { return this -> value || argument; }
                        friend const long long operator |(const long long argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const long long operator |(const long long argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const long long operator |(const long long argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const long long operator |(const long long argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const long long operator |(const long long argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator |(const short argument) const { return this -> value || argument; }
                        friend const short operator |(const short argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const short operator |(const short argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const short operator |(const short argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const short operator |(const short argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const short operator |(const short argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator |(const signed char argument) const { return this -> value || argument; }
                        friend const signed char operator |(const signed char argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const signed char operator |(const signed char argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const signed char operator |(const signed char argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const signed char operator |(const signed char argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const signed char operator |(const signed char argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator |(const unsigned char argument) const { return this -> value || argument; }
                        friend const unsigned char operator |(const unsigned char argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned char operator |(const unsigned char argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned char operator |(const unsigned char argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned char operator |(const unsigned char argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned char operator |(const unsigned char argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator |(const unsigned int argument) const { return this -> value || argument; }
                        friend const unsigned int operator |(const unsigned int argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned int operator |(const unsigned int argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned int operator |(const unsigned int argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned int operator |(const unsigned int argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned int operator |(const unsigned int argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator |(const unsigned long argument) const { return this -> value || argument; }
                        friend const unsigned long operator |(const unsigned long argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned long operator |(const unsigned long argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned long operator |(const unsigned long argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned long operator |(const unsigned long argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned long operator |(const unsigned long argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator |(const unsigned long long argument) const { return this -> value || argument; }
                        friend const unsigned long long operator |(const unsigned long long argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned long long operator |(const unsigned long long argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned long long operator |(const unsigned long long argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned long long operator |(const unsigned long long argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned long long operator |(const unsigned long long argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator |(const unsigned short argument) const { return this -> value || argument; }
                        friend const unsigned short operator |(const unsigned short argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned short operator |(const unsigned short argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned short operator |(const unsigned short argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned short operator |(const unsigned short argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const unsigned short operator |(const unsigned short argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator |(void* argument) const { return this -> value || argument; }
                        inline const boolean operator |(const void* argument) const { return this -> value || argument; }

                        inline const boolean operator |(const wchar_t argument) const { return this -> value || argument; }
                        friend const wchar_t operator |(const wchar_t argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const wchar_t operator |(const wchar_t argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const wchar_t operator |(const wchar_t argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const wchar_t operator |(const wchar_t argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const wchar_t operator |(const wchar_t argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        const boolean operator |(boolean& argument) { return this -> value || argument.valueOf(); }
                        const boolean operator |(boolean&& argument) { return this -> value || argument.valueOf(); }
                        const boolean operator |(const boolean& argument) { return this -> value || argument.valueOf(); }
                        const boolean operator |(const boolean&& argument) const { return this -> value || argument.valueOf(); }

                        // [~]
                        inline const boolean operator ~() const { return 1; }

                        // [!]
                        inline const boolean operator !() const { return this -> value ? 0 : 1; }

                        // [=]
                        inline const boolean& operator =(const char argument) { this -> value = argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(const char16_t argument) { this -> value = argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(const char32_t argument) { this -> value = argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(const double argument) { this -> value = argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(const float argument) { this -> value = argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(const int argument) { this -> value = argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(const long argument) { this -> value = argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(const long double argument) { this -> value = argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(const long long argument) { this -> value = argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(const short argument) { this -> value = argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(const signed char argument) { this -> value = argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(const unsigned char argument) { this -> value = argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(const unsigned int argument) { this -> value = argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(const unsigned long argument) { this -> value = argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(const unsigned long long argument) { this -> value = argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(const unsigned short argument) { this -> value = argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(void* argument) { this -> value = NULL == argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(const void* argument) { this -> value = NULL == argument ? 1 : 0; return *this; }
                        inline const boolean& operator =(const wchar_t argument) { this -> value = argument ? 1 : 0; return *this; }

                        const boolean& operator =(boolean& argument) { this -> value = argument.valueOf(); return *this; }
                        const boolean& operator =(boolean&& argument) { this -> value = argument.valueOf(); return *this; }
                        const boolean& operator =(const boolean& argument) { this -> value = argument.valueOf(); return *this; }
                        const boolean& operator =(const boolean&& argument) { this -> value = argument.valueOf(); return *this; }

                        // [<]
                        inline const boolean operator <(const char argument) const { return !(this -> value) && argument; }
                        friend const boolean operator <(const char argumentA, const boolean argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const char argumentA, boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const char argumentA, const boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const char argumentA, boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const char argumentA, const boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }

                        inline const boolean operator <(const char16_t argument) const { return !(this -> value) && argument; }
                        friend const boolean operator <(const char16_t argumentA, const boolean argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const char16_t argumentA, boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const char16_t argumentA, const boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const char16_t argumentA, boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const char16_t argumentA, const boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }

                        inline const boolean operator <(const char32_t argument) const { return !(this -> value) && argument; }
                        friend const boolean operator <(const char32_t argumentA, const boolean argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const char32_t argumentA, boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const char32_t argumentA, const boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const char32_t argumentA, boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const char32_t argumentA, const boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }

                        inline const boolean operator <(const double argument) const { return !(this -> value) && argument; }
                        friend const boolean operator <(const double argumentA, const boolean argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const double argumentA, boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const double argumentA, const boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const double argumentA, boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const double argumentA, const boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }

                        inline const boolean operator <(const float argument) const { return !(this -> value) && argument; }
                        friend const boolean operator <(const float argumentA, const boolean argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const float argumentA, boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const float argumentA, const boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const float argumentA, boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const float argumentA, const boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }

                        inline const boolean operator <(const int argument) const { return !(this -> value) && argument; }
                        friend const boolean operator <(const int argumentA, const boolean argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const int argumentA, boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const int argumentA, const boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const int argumentA, boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const int argumentA, const boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }

                        inline const boolean operator <(const long argument) const { return !(this -> value) && argument; }
                        friend const boolean operator <(const long argumentA, const boolean argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const long argumentA, boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const long argumentA, const boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const long argumentA, boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const long argumentA, const boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }

                        inline const boolean operator <(const long double argument) const { return !(this -> value) && argument; }
                        friend const boolean operator <(const long double argumentA, const boolean argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const long double argumentA, boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const long double argumentA, const boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const long double argumentA, boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const long double argumentA, const boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }

                        inline const boolean operator <(const long long argument) const { return !(this -> value) && argument; }
                        friend const boolean operator <(const long long argumentA, const boolean argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const long long argumentA, boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const long long argumentA, const boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const long long argumentA, boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const long long argumentA, const boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }

                        inline const boolean operator <(const short argument) const { return !(this -> value) && argument; }
                        friend const boolean operator <(const short argumentA, const boolean argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const short argumentA, boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const short argumentA, const boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const short argumentA, boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const short argumentA, const boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }

                        inline const boolean operator <(const signed char argument) const { return !(this -> value) && argument; }
                        friend const boolean operator <(const signed char argumentA, const boolean argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const signed char argumentA, boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const signed char argumentA, const boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const signed char argumentA, boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const signed char argumentA, const boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }

                        inline const boolean operator <(const unsigned char argument) const { return !(this -> value) && argument; }
                        friend const boolean operator <(const unsigned char argumentA, const boolean argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned char argumentA, boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned char argumentA, const boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned char argumentA, boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned char argumentA, const boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }

                        inline const boolean operator <(const unsigned int argument) const { return !(this -> value) && argument; }
                        friend const boolean operator <(const unsigned int argumentA, const boolean argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned int argumentA, boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned int argumentA, const boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned int argumentA, boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned int argumentA, const boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }

                        inline const boolean operator <(const unsigned long argument) const { return !(this -> value) && argument; }
                        friend const boolean operator <(const unsigned long argumentA, const boolean argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned long argumentA, boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned long argumentA, const boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned long argumentA, boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned long argumentA, const boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }

                        inline const boolean operator <(const unsigned long long argument) const { return !(this -> value) && argument; }
                        friend const boolean operator <(const unsigned long long argumentA, const boolean argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned long long argumentA, boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned long long argumentA, const boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned long long argumentA, boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned long long argumentA, const boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }

                        inline const boolean operator <(const unsigned short argument) const { return !(this -> value) && argument; }
                        friend const boolean operator <(const unsigned short argumentA, const boolean argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned short argumentA, boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned short argumentA, const boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned short argumentA, boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const unsigned short argumentA, const boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }

                        inline const boolean operator <(void* argument) const { return !(this -> value) && (NULL != argument); }
                        friend const boolean operator <(void* argumentA, const boolean argumentB) { return (NULL == argumentA) && argumentB.valueOf(); }
                        friend const boolean operator <(void* argumentA, boolean& argumentB) { return (NULL == argumentA) && argumentB.valueOf(); }
                        friend const boolean operator <(void* argumentA, const boolean& argumentB) { return (NULL == argumentA) && argumentB.valueOf(); }
                        friend const boolean operator <(void* argumentA, boolean&& argumentB) { return (NULL == argumentA) && argumentB.valueOf(); }
                        friend const boolean operator <(void* argumentA, const boolean&& argumentB) { return (NULL == argumentA) && argumentB.valueOf(); }

                        inline const boolean operator <(const void* argument) const { return !(this -> value) && (NULL != argument); }
                        friend const boolean operator <(const void* argumentA, const boolean argumentB) { return (NULL == argumentA) && argumentB.valueOf(); }
                        friend const boolean operator <(const void* argumentA, boolean& argumentB) { return (NULL == argumentA) && argumentB.valueOf(); }
                        friend const boolean operator <(const void* argumentA, const boolean& argumentB) { return (NULL == argumentA) && argumentB.valueOf(); }
                        friend const boolean operator <(const void* argumentA, boolean&& argumentB) { return (NULL == argumentA) && argumentB.valueOf(); }
                        friend const boolean operator <(const void* argumentA, const boolean&& argumentB) { return (NULL == argumentA) && argumentB.valueOf(); }

                        inline const boolean operator <(const wchar_t argument) const { return !(this -> value) && argument; }
                        friend const boolean operator <(const wchar_t argumentA, const boolean argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const wchar_t argumentA, boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const wchar_t argumentA, const boolean& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const wchar_t argumentA, boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }
                        friend const boolean operator <(const wchar_t argumentA, const boolean&& argumentB) { return !argumentA && argumentB.valueOf(); }

                        const boolean operator <(boolean& argument) { return !(this -> value) && argument.valueOf(); }
                        const boolean operator <(boolean&& argument) { return !(this -> value) && argument.valueOf(); }
                        const boolean operator <(const boolean& argument) { return !(this -> value) && argument.valueOf(); }
                        const boolean operator <(const boolean&& argument) { return !(this -> value) && argument.valueOf(); }

                        // [>]
                        inline const boolean operator >(const char argument) const { return this -> value && !argument; }
                        friend const boolean operator >(const char argumentA, const boolean argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const char argumentA, boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const char argumentA, const boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const char argumentA, boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const char argumentA, const boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }

                        inline const boolean operator >(const char16_t argument) const { return this -> value && !argument; }
                        friend const boolean operator >(const char16_t argumentA, const boolean argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const char16_t argumentA, boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const char16_t argumentA, const boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const char16_t argumentA, boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const char16_t argumentA, const boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }

                        inline const boolean operator >(const char32_t argument) const { return this -> value && !argument; }
                        friend const boolean operator >(const char32_t argumentA, const boolean argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const char32_t argumentA, boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const char32_t argumentA, const boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const char32_t argumentA, boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const char32_t argumentA, const boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }

                        inline const boolean operator >(const double argument) const { return this -> value && !argument; }
                        friend const boolean operator >(const double argumentA, const boolean argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const double argumentA, boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const double argumentA, const boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const double argumentA, boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const double argumentA, const boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }

                        inline const boolean operator >(const float argument) const { return this -> value && !argument; }
                        friend const boolean operator >(const float argumentA, const boolean argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const float argumentA, boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const float argumentA, const boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const float argumentA, boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const float argumentA, const boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }

                        inline const boolean operator >(const int argument) const { return this -> value && !argument; }
                        friend const boolean operator >(const int argumentA, const boolean argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const int argumentA, boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const int argumentA, const boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const int argumentA, boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const int argumentA, const boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }

                        inline const boolean operator >(const long argument) const { return this -> value && !argument; }
                        friend const boolean operator >(const long argumentA, const boolean argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const long argumentA, boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const long argumentA, const boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const long argumentA, boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const long argumentA, const boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }

                        inline const boolean operator >(const long double argument) const { return this -> value && !argument; }
                        friend const boolean operator >(const long double argumentA, const boolean argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const long double argumentA, boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const long double argumentA, const boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const long double argumentA, boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const long double argumentA, const boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }

                        inline const boolean operator >(const long long argument) const { return this -> value && !argument; }
                        friend const boolean operator >(const long long argumentA, const boolean argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const long long argumentA, boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const long long argumentA, const boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const long long argumentA, boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const long long argumentA, const boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }

                        inline const boolean operator >(const short argument) const { return this -> value && !argument; }
                        friend const boolean operator >(const short argumentA, const boolean argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const short argumentA, boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const short argumentA, const boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const short argumentA, boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const short argumentA, const boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }

                        inline const boolean operator >(const signed char argument) const { return this -> value && !argument; }
                        friend const boolean operator >(const signed char argumentA, const boolean argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const signed char argumentA, boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const signed char argumentA, const boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const signed char argumentA, boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const signed char argumentA, const boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }

                        inline const boolean operator >(const unsigned char argument) const { return this -> value && !argument; }
                        friend const boolean operator >(const unsigned char argumentA, const boolean argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned char argumentA, boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned char argumentA, const boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned char argumentA, boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned char argumentA, const boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }

                        inline const boolean operator >(const unsigned int argument) const { return this -> value && !argument; }
                        friend const boolean operator >(const unsigned int argumentA, const boolean argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned int argumentA, boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned int argumentA, const boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned int argumentA, boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned int argumentA, const boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }

                        inline const boolean operator >(const unsigned long argument) const { return this -> value && !argument; }
                        friend const boolean operator >(const unsigned long argumentA, const boolean argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned long argumentA, boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned long argumentA, const boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned long argumentA, boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned long argumentA, const boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }

                        inline const boolean operator >(const unsigned long long argument) const { return this -> value && !argument; }
                        friend const boolean operator >(const unsigned long long argumentA, const boolean argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned long long argumentA, boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned long long argumentA, const boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned long long argumentA, boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned long long argumentA, const boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }

                        inline const boolean operator >(const unsigned short argument) const { return this -> value && !argument; }
                        friend const boolean operator >(const unsigned short argumentA, const boolean argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned short argumentA, boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned short argumentA, const boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned short argumentA, boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const unsigned short argumentA, const boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }

                        inline const boolean operator >(void* argument) const { return this -> value && (NULL == argument); }
                        friend const boolean operator >(void* argumentA, const boolean argumentB) { return (NULL != argumentA) && !(argumentB.valueOf()); }
                        friend const boolean operator >(void* argumentA, boolean& argumentB) { return (NULL != argumentA) && !(argumentB.valueOf()); }
                        friend const boolean operator >(void* argumentA, const boolean& argumentB) { return (NULL != argumentA) && !(argumentB.valueOf()); }
                        friend const boolean operator >(void* argumentA, boolean&& argumentB) { return (NULL != argumentA) && !(argumentB.valueOf()); }
                        friend const boolean operator >(void* argumentA, const boolean&& argumentB) { return (NULL != argumentA) && !(argumentB.valueOf()); }

                        inline const boolean operator >(const void* argument) const { return this -> value && (NULL == argument); }
                        friend const boolean operator >(const void* argumentA, const boolean argumentB) { return (NULL != argumentA) && !(argumentB.valueOf()); }
                        friend const boolean operator >(const void* argumentA, boolean& argumentB) { return (NULL != argumentA) && !(argumentB.valueOf()); }
                        friend const boolean operator >(const void* argumentA, const boolean& argumentB) { return (NULL != argumentA) && !(argumentB.valueOf()); }
                        friend const boolean operator >(const void* argumentA, boolean&& argumentB) { return (NULL != argumentA) && !(argumentB.valueOf()); }
                        friend const boolean operator >(const void* argumentA, const boolean&& argumentB) { return (NULL != argumentA) && !(argumentB.valueOf()); }

                        inline const boolean operator >(const wchar_t argument) const { return this -> value && !argument; }
                        friend const boolean operator >(const wchar_t argumentA, const boolean argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const wchar_t argumentA, boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const wchar_t argumentA, const boolean& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const wchar_t argumentA, boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }
                        friend const boolean operator >(const wchar_t argumentA, const boolean&& argumentB) { return argumentA && !(argumentB.valueOf()); }

                        const boolean operator >(boolean& argument) { return this -> value && !(argument.valueOf()); }
                        const boolean operator >(boolean&& argument) { return this -> value && !(argument.valueOf()); }
                        const boolean operator >(const boolean& argument) { return this -> value && !(argument.valueOf()); }
                        const boolean operator >(const boolean&& argument) { return this -> value && !(argument.valueOf()); }

                        // [<=]
                        inline const boolean operator <=(const char argument) const { return !(this -> value && !argument); }
                        friend const boolean operator <=(const char argumentA, const boolean argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const char argumentA, boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const char argumentA, const boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const char argumentA, boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const char argumentA, const boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }

                        inline const boolean operator <=(const char16_t argument) const { return !(this -> value && !argument); }
                        friend const boolean operator <=(const char16_t argumentA, const boolean argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const char16_t argumentA, boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const char16_t argumentA, const boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const char16_t argumentA, boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const char16_t argumentA, const boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }

                        inline const boolean operator <=(const char32_t argument) const { return !(this -> value && !argument); }
                        friend const boolean operator <=(const char32_t argumentA, const boolean argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const char32_t argumentA, boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const char32_t argumentA, const boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const char32_t argumentA, boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const char32_t argumentA, const boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }

                        inline const boolean operator <=(const double argument) const { return !(this -> value && !argument); }
                        friend const boolean operator <=(const double argumentA, const boolean argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const double argumentA, boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const double argumentA, const boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const double argumentA, boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const double argumentA, const boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }

                        inline const boolean operator <=(const float argument) const { return !(this -> value && !argument); }
                        friend const boolean operator <=(const float argumentA, const boolean argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const float argumentA, boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const float argumentA, const boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const float argumentA, boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const float argumentA, const boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }

                        inline const boolean operator <=(const int argument) const { return !(this -> value && !argument); }
                        friend const boolean operator <=(const int argumentA, const boolean argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const int argumentA, boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const int argumentA, const boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const int argumentA, boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const int argumentA, const boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }

                        inline const boolean operator <=(const long argument) const { return !(this -> value && !argument); }
                        friend const boolean operator <=(const long argumentA, const boolean argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const long argumentA, boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const long argumentA, const boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const long argumentA, boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const long argumentA, const boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }

                        inline const boolean operator <=(const long double argument) const { return !(this -> value && !argument); }
                        friend const boolean operator <=(const long double argumentA, const boolean argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const long double argumentA, boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const long double argumentA, const boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const long double argumentA, boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const long double argumentA, const boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }

                        inline const boolean operator <=(const long long argument) const { return !(this -> value && !argument); }
                        friend const boolean operator <=(const long long argumentA, const boolean argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const long long argumentA, boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const long long argumentA, const boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const long long argumentA, boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const long long argumentA, const boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }

                        inline const boolean operator <=(const short argument) const { return !(this -> value && !argument); }
                        friend const boolean operator <=(const short argumentA, const boolean argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const short argumentA, boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const short argumentA, const boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const short argumentA, boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const short argumentA, const boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }

                        inline const boolean operator <=(const signed char argument) const { return !(this -> value && !argument); }
                        friend const boolean operator <=(const signed char argumentA, const boolean argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const signed char argumentA, boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const signed char argumentA, const boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const signed char argumentA, boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const signed char argumentA, const boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }

                        inline const boolean operator <=(const unsigned char argument) const { return !(this -> value && !argument); }
                        friend const boolean operator <=(const unsigned char argumentA, const boolean argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned char argumentA, boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned char argumentA, const boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned char argumentA, boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned char argumentA, const boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }

                        inline const boolean operator <=(const unsigned int argument) const { return !(this -> value && !argument); }
                        friend const boolean operator <=(const unsigned int argumentA, const boolean argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned int argumentA, boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned int argumentA, const boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned int argumentA, boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned int argumentA, const boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }

                        inline const boolean operator <=(const unsigned long argument) const { return !(this -> value && !argument); }
                        friend const boolean operator <=(const unsigned long argumentA, const boolean argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned long argumentA, boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned long argumentA, const boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned long argumentA, boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned long argumentA, const boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }

                        inline const boolean operator <=(const unsigned long long argument) const { return !(this -> value && !argument); }
                        friend const boolean operator <=(const unsigned long long argumentA, const boolean argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned long long argumentA, boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned long long argumentA, const boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned long long argumentA, boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned long long argumentA, const boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }

                        inline const boolean operator <=(const unsigned short argument) const { return !(this -> value && !argument); }
                        friend const boolean operator <=(const unsigned short argumentA, const boolean argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned short argumentA, boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned short argumentA, const boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned short argumentA, boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const unsigned short argumentA, const boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }

                        inline const boolean operator <=(void* argument) const { return !(this -> value && (NULL == argument)); }
                        friend const boolean operator <=(void* argumentA, const boolean argumentB) { return !((NULL != argumentA) && !(argumentB.valueOf())); }
                        friend const boolean operator <=(void* argumentA, boolean& argumentB) { return !((NULL != argumentA) && !(argumentB.valueOf())); }
                        friend const boolean operator <=(void* argumentA, const boolean& argumentB) { return !((NULL != argumentA) && !(argumentB.valueOf())); }
                        friend const boolean operator <=(void* argumentA, boolean&& argumentB) { return !((NULL != argumentA) && !(argumentB.valueOf())); }
                        friend const boolean operator <=(void* argumentA, const boolean&& argumentB) { return !((NULL != argumentA) && !(argumentB.valueOf())); }

                        inline const boolean operator <=(const void* argument) const { return !(this -> value && (NULL == argument)); }
                        friend const boolean operator <=(const void* argumentA, const boolean argumentB) { return !((NULL != argumentA) && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const void* argumentA, boolean& argumentB) { return !((NULL != argumentA) && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const void* argumentA, const boolean& argumentB) { return !((NULL != argumentA) && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const void* argumentA, boolean&& argumentB) { return !((NULL != argumentA) && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const void* argumentA, const boolean&& argumentB) { return !((NULL != argumentA) && !(argumentB.valueOf())); }

                        inline const boolean operator <=(const wchar_t argument) const { return !(this -> value && !argument); }
                        friend const boolean operator <=(const wchar_t argumentA, const boolean argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const wchar_t argumentA, boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const wchar_t argumentA, const boolean& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const wchar_t argumentA, boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }
                        friend const boolean operator <=(const wchar_t argumentA, const boolean&& argumentB) { return !(argumentA && !(argumentB.valueOf())); }

                        const boolean operator <=(boolean& argument) { return !(this -> value && !(argument.valueOf())); }
                        const boolean operator <=(boolean&& argument) { return !(this -> value && !(argument.valueOf())); }
                        const boolean operator <=(const boolean& argument) { return !(this -> value && !(argument.valueOf())); }
                        const boolean operator <=(const boolean&& argument) { return !(this -> value && !(argument.valueOf())); }

                        // [>=]
                        inline const boolean operator >=(const char argument) const { return !(!(this -> value) && argument); }
                        friend const boolean operator >=(const char argumentA, const boolean argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const char argumentA, boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const char argumentA, const boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const char argumentA, boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const char argumentA, const boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }

                        inline const boolean operator >=(const char16_t argument) const { return !(!(this -> value) && argument); }
                        friend const boolean operator >=(const char16_t argumentA, const boolean argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const char16_t argumentA, boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const char16_t argumentA, const boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const char16_t argumentA, boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const char16_t argumentA, const boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }

                        inline const boolean operator >=(const char32_t argument) const { return !(!(this -> value) && argument); }
                        friend const boolean operator >=(const char32_t argumentA, const boolean argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const char32_t argumentA, boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const char32_t argumentA, const boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const char32_t argumentA, boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const char32_t argumentA, const boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }

                        inline const boolean operator >=(const double argument) const { return !(!(this -> value) && argument); }
                        friend const boolean operator >=(const double argumentA, const boolean argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const double argumentA, boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const double argumentA, const boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const double argumentA, boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const double argumentA, const boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }

                        inline const boolean operator >=(const float argument) const { return !(!(this -> value) && argument); }
                        friend const boolean operator >=(const float argumentA, const boolean argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const float argumentA, boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const float argumentA, const boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const float argumentA, boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const float argumentA, const boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }

                        inline const boolean operator >=(const int argument) const { return !(!(this -> value) && argument); }
                        friend const boolean operator >=(const int argumentA, const boolean argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const int argumentA, boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const int argumentA, const boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const int argumentA, boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const int argumentA, const boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }

                        inline const boolean operator >=(const long argument) const { return !(!(this -> value) && argument); }
                        friend const boolean operator >=(const long argumentA, const boolean argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const long argumentA, boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const long argumentA, const boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const long argumentA, boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const long argumentA, const boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }

                        inline const boolean operator >=(const long double argument) const { return !(!(this -> value) && argument); }
                        friend const boolean operator >=(const long double argumentA, const boolean argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const long double argumentA, boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const long double argumentA, const boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const long double argumentA, boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const long double argumentA, const boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }

                        inline const boolean operator >=(const long long argument) const { return !(!(this -> value) && argument); }
                        friend const boolean operator >=(const long long argumentA, const boolean argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const long long argumentA, boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const long long argumentA, const boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const long long argumentA, boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const long long argumentA, const boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }

                        inline const boolean operator >=(const short argument) const { return !(!(this -> value) && argument); }
                        friend const boolean operator >=(const short argumentA, const boolean argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const short argumentA, boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const short argumentA, const boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const short argumentA, boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const short argumentA, const boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }

                        inline const boolean operator >=(const signed char argument) const { return !(!(this -> value) && argument); }
                        friend const boolean operator >=(const signed char argumentA, const boolean argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const signed char argumentA, boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const signed char argumentA, const boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const signed char argumentA, boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const signed char argumentA, const boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }

                        inline const boolean operator >=(const unsigned char argument) const { return !(!(this -> value) && argument); }
                        friend const boolean operator >=(const unsigned char argumentA, const boolean argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned char argumentA, boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned char argumentA, const boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned char argumentA, boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned char argumentA, const boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }

                        inline const boolean operator >=(const unsigned int argument) const { return !(!(this -> value) && argument); }
                        friend const boolean operator >=(const unsigned int argumentA, const boolean argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned int argumentA, boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned int argumentA, const boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned int argumentA, boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned int argumentA, const boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }

                        inline const boolean operator >=(const unsigned long argument) const { return !(!(this -> value) && argument); }
                        friend const boolean operator >=(const unsigned long argumentA, const boolean argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned long argumentA, boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned long argumentA, const boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned long argumentA, boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned long argumentA, const boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }

                        inline const boolean operator >=(const unsigned long long argument) const { return !(!(this -> value) && argument); }
                        friend const boolean operator >=(const unsigned long long argumentA, const boolean argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned long long argumentA, boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned long long argumentA, const boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned long long argumentA, boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned long long argumentA, const boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }

                        inline const boolean operator >=(const unsigned short argument) const { return !(!(this -> value) && argument); }
                        friend const boolean operator >=(const unsigned short argumentA, const boolean argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned short argumentA, boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned short argumentA, const boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned short argumentA, boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const unsigned short argumentA, const boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }

                        inline const boolean operator >=(void* argument) const { return !(!(this -> value) && (NULL != argument)); }
                        friend const boolean operator >=(void* argumentA, const boolean argumentB) { return !((NULL == argumentA) && argumentB.valueOf()); }
                        friend const boolean operator >=(void* argumentA, boolean& argumentB) { return !((NULL == argumentA) && argumentB.valueOf()); }
                        friend const boolean operator >=(void* argumentA, const boolean& argumentB) { return !((NULL == argumentA) && argumentB.valueOf()); }
                        friend const boolean operator >=(void* argumentA, boolean&& argumentB) { return !((NULL == argumentA) && argumentB.valueOf()); }
                        friend const boolean operator >=(void* argumentA, const boolean&& argumentB) { return !((NULL == argumentA) && argumentB.valueOf()); }

                        inline const boolean operator >=(const void* argument) const { return !(!(this -> value) && (NULL != argument)); }
                        friend const boolean operator >=(const void* argumentA, const boolean argumentB) { return !((NULL == argumentA) && argumentB.valueOf()); }
                        friend const boolean operator >=(const void* argumentA, boolean& argumentB) { return !((NULL == argumentA) && argumentB.valueOf()); }
                        friend const boolean operator >=(const void* argumentA, const boolean& argumentB) { return !((NULL == argumentA) && argumentB.valueOf()); }
                        friend const boolean operator >=(const void* argumentA, boolean&& argumentB) { return !((NULL == argumentA) && argumentB.valueOf()); }
                        friend const boolean operator >=(const void* argumentA, const boolean&& argumentB) { return !((NULL == argumentA) && argumentB.valueOf()); }

                        inline const boolean operator >=(const wchar_t argument) const { return !(!(this -> value) && argument); }
                        friend const boolean operator >=(const wchar_t argumentA, const boolean argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const wchar_t argumentA, boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const wchar_t argumentA, const boolean& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const wchar_t argumentA, boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }
                        friend const boolean operator >=(const wchar_t argumentA, const boolean&& argumentB) { return !(!argumentA && argumentB.valueOf()); }

                        const boolean operator >=(boolean& argument) { return !(!(this -> value) && argument.valueOf()); }
                        const boolean operator >=(boolean&& argument) { return !(!(this -> value) && argument.valueOf()); }
                        const boolean operator >=(const boolean& argument) { return !(!(this -> value) && argument.valueOf()); }
                        const boolean operator >=(const boolean&& argument) { return !(!(this -> value) && argument.valueOf()); }

                        // [++]
                        inline const boolean& operator ++() { this -> value = 1; return *this; }
                        inline const boolean& operator ++(int) { this -> value = 1; return *this; }

                        // [--]
                        inline const boolean& operator --() { this -> value = 1; return *this; }
                        inline const boolean& operator --(int) { this -> value = 1; return *this; }

                        // [==]
                        inline const boolean operator ==(const char argument) const { return this -> value == argument; }
                        friend const boolean operator ==(const char argumentA, const boolean argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const char argumentA, boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const char argumentA, const boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const char argumentA, boolean&& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const char argumentA, const boolean&& argumentB) { return argumentA == argumentB.valueOf(); }

                        inline const boolean operator ==(const char16_t argument) const { return this -> value == argument; }
                        friend const boolean operator ==(const char16_t argumentA, const boolean argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const char16_t argumentA, boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const char16_t argumentA, const boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const char16_t argumentA, boolean&& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const char16_t argumentA, const boolean&& argumentB) { return argumentA == argumentB.valueOf(); }

                        inline const boolean operator ==(const char32_t argument) const { return this -> value == argument; }
                        friend const boolean operator ==(const char32_t argumentA, const boolean argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const char32_t argumentA, boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const char32_t argumentA, const boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const char32_t argumentA, boolean&& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const char32_t argumentA, const boolean&& argumentB) { return argumentA == argumentB.valueOf(); }

                        inline const boolean operator ==(const double argument) const { return this -> value == argument; }
                        friend const boolean operator ==(const double argumentA, const boolean argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const double argumentA, boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const double argumentA, const boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const double argumentA, boolean&& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const double argumentA, const boolean&& argumentB) { return argumentA == argumentB.valueOf(); }

                        inline const boolean operator ==(const float argument) const { return this -> value == argument; }
                        friend const boolean operator ==(const float argumentA, const boolean argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const float argumentA, boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const float argumentA, const boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const float argumentA, boolean&& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const float argumentA, const boolean&& argumentB) { return argumentA == argumentB.valueOf(); }

                        inline const boolean operator ==(const int argument) const { return this -> value == argument; }
                        friend const boolean operator ==(const int argumentA, const boolean argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const int argumentA, boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const int argumentA, const boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const int argumentA, boolean&& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const int argumentA, const boolean&& argumentB) { return argumentA == argumentB.valueOf(); }

                        inline const boolean operator ==(const long argument) const { return this -> value == argument; }
                        friend const boolean operator ==(const long argumentA, const boolean argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const long argumentA, boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const long argumentA, const boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const long argumentA, boolean&& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const long argumentA, const boolean&& argumentB) { return argumentA == argumentB.valueOf(); }

                        inline const boolean operator ==(const long double argument) const { return this -> value == argument; }
                        friend const boolean operator ==(const long double argumentA, const boolean argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const long double argumentA, boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const long double argumentA, const boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const long double argumentA, boolean&& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const long double argumentA, const boolean&& argumentB) { return argumentA == argumentB.valueOf(); }

                        inline const boolean operator ==(const long long argument) const { return this -> value == argument; }
                        friend const boolean operator ==(const long long argumentA, const boolean argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const long long argumentA, boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const long long argumentA, const boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const long long argumentA, boolean&& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const long long argumentA, const boolean&& argumentB) { return argumentA == argumentB.valueOf(); }

                        inline const boolean operator ==(const short argument) const { return this -> value == argument; }
                        friend const boolean operator ==(const short argumentA, const boolean argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const short argumentA, boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const short argumentA, const boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const short argumentA, boolean&& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const short argumentA, const boolean&& argumentB) { return argumentA == argumentB.valueOf(); }

                        inline const boolean operator ==(const signed char argument) const { return this -> value == argument; }
                        friend const boolean operator ==(const signed char argumentA, const boolean argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const signed char argumentA, boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const signed char argumentA, const boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const signed char argumentA, boolean&& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const signed char argumentA, const boolean&& argumentB) { return argumentA == argumentB.valueOf(); }

                        inline const boolean operator ==(const unsigned char argument) const { return this -> value == argument; }
                        friend const boolean operator ==(const unsigned char argumentA, const boolean argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned char argumentA, boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned char argumentA, const boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned char argumentA, boolean&& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned char argumentA, const boolean&& argumentB) { return argumentA == argumentB.valueOf(); }

                        inline const boolean operator ==(const unsigned int argument) const { return this -> value == argument; }
                        friend const boolean operator ==(const unsigned int argumentA, const boolean argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned int argumentA, boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned int argumentA, const boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned int argumentA, boolean&& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned int argumentA, const boolean&& argumentB) { return argumentA == argumentB.valueOf(); }

                        inline const boolean operator ==(const unsigned long argument) const { return this -> value == argument; }
                        friend const boolean operator ==(const unsigned long argumentA, const boolean argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned long argumentA, boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned long argumentA, const boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned long argumentA, boolean&& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned long argumentA, const boolean&& argumentB) { return argumentA == argumentB.valueOf(); }

                        inline const boolean operator ==(const unsigned long long argument) const { return this -> value == argument; }
                        friend const boolean operator ==(const unsigned long long argumentA, const boolean argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned long long argumentA, boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned long long argumentA, const boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned long long argumentA, boolean&& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned long long argumentA, const boolean&& argumentB) { return argumentA == argumentB.valueOf(); }

                        inline const boolean operator ==(const unsigned short argument) const { return this -> value == argument; }
                        friend const boolean operator ==(const unsigned short argumentA, const boolean argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned short argumentA, boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned short argumentA, const boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned short argumentA, boolean&& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const unsigned short argumentA, const boolean&& argumentB) { return argumentA == argumentB.valueOf(); }

                        inline const boolean operator ==(void* argument) const { return NULL == argument ? !(this -> value) : this -> value; }
                        friend const boolean operator ==(void* argumentA, const boolean argumentB) { return (NULL == argumentA ? 0 : 1) == argumentB.valueOf(); }
                        friend const boolean operator ==(void* argumentA, boolean& argumentB) { return (NULL == argumentA ? 0 : 1) == argumentB.valueOf(); }
                        friend const boolean operator ==(void* argumentA, const boolean& argumentB) { return (NULL == argumentA ? 0 : 1) == argumentB.valueOf(); }
                        friend const boolean operator ==(void* argumentA, boolean&& argumentB) { return (NULL == argumentA ? 0 : 1) == argumentB.valueOf(); }
                        friend const boolean operator ==(void* argumentA, const boolean&& argumentB) { return (NULL == argumentA ? 0 : 1) == argumentB.valueOf(); }

                        inline const boolean operator ==(const void* argument) const { return NULL == argument ? !(this -> value) : this -> value; }
                        friend const boolean operator ==(const void* argumentA, const boolean argumentB) { return (NULL == argumentA ? 0 : 1) == argumentB.valueOf(); }
                        friend const boolean operator ==(const void* argumentA, boolean& argumentB) { return (NULL == argumentA ? 0 : 1) == argumentB.valueOf(); }
                        friend const boolean operator ==(const void* argumentA, const boolean& argumentB) { return (NULL == argumentA ? 0 : 1) == argumentB.valueOf(); }
                        friend const boolean operator ==(const void* argumentA, boolean&& argumentB) { return (NULL == argumentA ? 0 : 1) == argumentB.valueOf(); }
                        friend const boolean operator ==(const void* argumentA, const boolean&& argumentB) { return (NULL == argumentA ? 0 : 1) == argumentB.valueOf(); }

                        inline const boolean operator ==(const wchar_t argument) const { return this -> value == argument; }
                        friend const boolean operator ==(const wchar_t argumentA, const boolean argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const wchar_t argumentA, boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const wchar_t argumentA, const boolean& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const wchar_t argumentA, boolean&& argumentB) { return argumentA == argumentB.valueOf(); }
                        friend const boolean operator ==(const wchar_t argumentA, const boolean&& argumentB) { return argumentA == argumentB.valueOf(); }

                        const boolean operator ==(boolean& argument) { return this -> value == argument.valueOf(); }
                        const boolean operator ==(boolean&& argument) { return this -> value == argument.valueOf(); }
                        const boolean operator ==(const boolean& argument) { return this -> value == argument.valueOf(); }
                        const boolean operator ==(const boolean&& argument) { return this -> value == argument.valueOf(); }

                        // [!=]
                        inline const boolean operator !=(const char argument) const { return this -> value != argument; }
                        friend const boolean operator !=(const char argumentA, const boolean argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const char argumentA, boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const char argumentA, const boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const char argumentA, boolean&& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const char argumentA, const boolean&& argumentB) { return argumentA != argumentB.valueOf(); }

                        inline const boolean operator !=(const char16_t argument) const { return this -> value != argument; }
                        friend const boolean operator !=(const char16_t argumentA, const boolean argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const char16_t argumentA, boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const char16_t argumentA, const boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const char16_t argumentA, boolean&& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const char16_t argumentA, const boolean&& argumentB) { return argumentA != argumentB.valueOf(); }

                        inline const boolean operator !=(const char32_t argument) const { return this -> value != argument; }
                        friend const boolean operator !=(const char32_t argumentA, const boolean argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const char32_t argumentA, boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const char32_t argumentA, const boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const char32_t argumentA, boolean&& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const char32_t argumentA, const boolean&& argumentB) { return argumentA != argumentB.valueOf(); }

                        inline const boolean operator !=(const double argument) const { return this -> value != argument; }
                        friend const boolean operator !=(const double argumentA, const boolean argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const double argumentA, boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const double argumentA, const boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const double argumentA, boolean&& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const double argumentA, const boolean&& argumentB) { return argumentA != argumentB.valueOf(); }

                        inline const boolean operator !=(const float argument) const { return this -> value != argument; }
                        friend const boolean operator !=(const float argumentA, const boolean argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const float argumentA, boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const float argumentA, const boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const float argumentA, boolean&& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const float argumentA, const boolean&& argumentB) { return argumentA != argumentB.valueOf(); }

                        inline const boolean operator !=(const int argument) const { return this -> value != argument; }
                        friend const boolean operator !=(const int argumentA, const boolean argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const int argumentA, boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const int argumentA, const boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const int argumentA, boolean&& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const int argumentA, const boolean&& argumentB) { return argumentA != argumentB.valueOf(); }

                        inline const boolean operator !=(const long argument) const { return this -> value != argument; }
                        friend const boolean operator !=(const long argumentA, const boolean argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const long argumentA, boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const long argumentA, const boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const long argumentA, boolean&& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const long argumentA, const boolean&& argumentB) { return argumentA != argumentB.valueOf(); }

                        inline const boolean operator !=(const long double argument) const { return this -> value != argument; }
                        friend const boolean operator !=(const long double argumentA, const boolean argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const long double argumentA, boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const long double argumentA, const boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const long double argumentA, boolean&& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const long double argumentA, const boolean&& argumentB) { return argumentA != argumentB.valueOf(); }

                        inline const boolean operator !=(const long long argument) const { return this -> value != argument; }
                        friend const boolean operator !=(const long long argumentA, const boolean argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const long long argumentA, boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const long long argumentA, const boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const long long argumentA, boolean&& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const long long argumentA, const boolean&& argumentB) { return argumentA != argumentB.valueOf(); }

                        inline const boolean operator !=(const short argument) const { return this -> value != argument; }
                        friend const boolean operator !=(const short argumentA, const boolean argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const short argumentA, boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const short argumentA, const boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const short argumentA, boolean&& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const short argumentA, const boolean&& argumentB) { return argumentA != argumentB.valueOf(); }

                        inline const boolean operator !=(const signed char argument) const { return this -> value != argument; }
                        friend const boolean operator !=(const signed char argumentA, const boolean argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const signed char argumentA, boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const signed char argumentA, const boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const signed char argumentA, boolean&& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const signed char argumentA, const boolean&& argumentB) { return argumentA != argumentB.valueOf(); }

                        inline const boolean operator !=(const unsigned char argument) const { return this -> value != argument; }
                        friend const boolean operator !=(const unsigned char argumentA, const boolean argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned char argumentA, boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned char argumentA, const boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned char argumentA, boolean&& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned char argumentA, const boolean&& argumentB) { return argumentA != argumentB.valueOf(); }

                        inline const boolean operator !=(const unsigned int argument) const { return this -> value != argument; }
                        friend const boolean operator !=(const unsigned int argumentA, const boolean argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned int argumentA, boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned int argumentA, const boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned int argumentA, boolean&& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned int argumentA, const boolean&& argumentB) { return argumentA != argumentB.valueOf(); }

                        inline const boolean operator !=(const unsigned long argument) const { return this -> value != argument; }
                        friend const boolean operator !=(const unsigned long argumentA, const boolean argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned long argumentA, boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned long argumentA, const boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned long argumentA, boolean&& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned long argumentA, const boolean&& argumentB) { return argumentA != argumentB.valueOf(); }

                        inline const boolean operator !=(const unsigned long long argument) const { return this -> value != argument; }
                        friend const boolean operator !=(const unsigned long long argumentA, const boolean argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned long long argumentA, boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned long long argumentA, const boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned long long argumentA, boolean&& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned long long argumentA, const boolean&& argumentB) { return argumentA != argumentB.valueOf(); }

                        inline const boolean operator !=(const unsigned short argument) const { return this -> value != argument; }
                        friend const boolean operator !=(const unsigned short argumentA, const boolean argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned short argumentA, boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned short argumentA, const boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned short argumentA, boolean&& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const unsigned short argumentA, const boolean&& argumentB) { return argumentA != argumentB.valueOf(); }

                        inline const boolean operator !=(void* argument) const { return NULL == argument ? this -> value : !(this -> value); }
                        friend const boolean operator !=(void* argumentA, const boolean argumentB) { return (NULL != argumentA ? 0 : 1) != argumentB.valueOf(); }
                        friend const boolean operator !=(void* argumentA, boolean& argumentB) { return (NULL != argumentA ? 0 : 1) != argumentB.valueOf(); }
                        friend const boolean operator !=(void* argumentA, const boolean& argumentB) { return (NULL != argumentA ? 0 : 1) != argumentB.valueOf(); }
                        friend const boolean operator !=(void* argumentA, boolean&& argumentB) { return (NULL != argumentA ? 0 : 1) != argumentB.valueOf(); }
                        friend const boolean operator !=(void* argumentA, const boolean&& argumentB) { return (NULL != argumentA ? 0 : 1) != argumentB.valueOf(); }

                        inline const boolean operator !=(const void* argument) const { return NULL == argument ? this -> value : !(this -> value); }
                        friend const boolean operator !=(const void* argumentA, const boolean argumentB) { return (NULL != argumentA ? 0 : 1) != argumentB.valueOf(); }
                        friend const boolean operator !=(const void* argumentA, boolean& argumentB) { return (NULL != argumentA ? 0 : 1) != argumentB.valueOf(); }
                        friend const boolean operator !=(const void* argumentA, const boolean& argumentB) { return (NULL != argumentA ? 0 : 1) != argumentB.valueOf(); }
                        friend const boolean operator !=(const void* argumentA, boolean&& argumentB) { return (NULL != argumentA ? 0 : 1) != argumentB.valueOf(); }
                        friend const boolean operator !=(const void* argumentA, const boolean&& argumentB) { return (NULL != argumentA ? 0 : 1) != argumentB.valueOf(); }

                        inline const boolean operator !=(const wchar_t argument) const { return this -> value != argument; }
                        friend const boolean operator !=(const wchar_t argumentA, const boolean argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const wchar_t argumentA, boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const wchar_t argumentA, const boolean& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const wchar_t argumentA, boolean&& argumentB) { return argumentA != argumentB.valueOf(); }
                        friend const boolean operator !=(const wchar_t argumentA, const boolean&& argumentB) { return argumentA != argumentB.valueOf(); }

                        const boolean operator !=(boolean& argument) { return this -> value != argument.valueOf(); }
                        const boolean operator !=(boolean&& argument) { return this -> value != argument.valueOf(); }
                        const boolean operator !=(const boolean& argument) { return this -> value != argument.valueOf(); }
                        const boolean operator !=(const boolean&& argument) { return this -> value != argument.valueOf(); }

                        // [&&]
                        inline const boolean operator &&(const char argument) const { return this -> value && argument; }
                        friend const boolean operator &&(const char argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const char argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const char argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const char argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const char argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &&(const char16_t argument) const { return this -> value && argument; }
                        friend const boolean operator &&(const char16_t argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const char16_t argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const char16_t argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const char16_t argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const char16_t argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &&(const char32_t argument) const { return this -> value && argument; }
                        friend const boolean operator &&(const char32_t argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const char32_t argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const char32_t argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const char32_t argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const char32_t argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &&(const double argument) const { return this -> value && argument; }
                        friend const boolean operator &&(const double argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const double argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const double argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const double argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const double argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &&(const float argument) const { return this -> value && argument; }
                        friend const boolean operator &&(const float argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const float argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const float argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const float argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const float argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &&(const int argument) const { return this -> value && argument; }
                        friend const boolean operator &&(const int argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const int argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const int argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const int argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const int argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &&(const long argument) const { return this -> value && argument; }
                        friend const boolean operator &&(const long argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const long argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const long argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const long argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const long argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &&(const long double argument) const { return this -> value && argument; }
                        friend const boolean operator &&(const long double argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const long double argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const long double argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const long double argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const long double argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &&(const long long argument) const { return this -> value && argument; }
                        friend const boolean operator &&(const long long argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const long long argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const long long argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const long long argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const long long argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &&(const short argument) const { return this -> value && argument; }
                        friend const boolean operator &&(const short argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const short argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const short argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const short argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const short argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &&(const signed char argument) const { return this -> value && argument; }
                        friend const boolean operator &&(const signed char argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const signed char argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const signed char argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const signed char argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const signed char argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &&(const unsigned char argument) const { return this -> value && argument; }
                        friend const boolean operator &&(const unsigned char argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned char argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned char argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned char argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned char argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &&(const unsigned int argument) const { return this -> value && argument; }
                        friend const boolean operator &&(const unsigned int argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned int argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned int argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned int argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned int argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &&(const unsigned long argument) const { return this -> value && argument; }
                        friend const boolean operator &&(const unsigned long argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned long argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned long argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned long argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned long argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &&(const unsigned long long argument) const { return this -> value && argument; }
                        friend const boolean operator &&(const unsigned long long argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned long long argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned long long argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned long long argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned long long argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &&(const unsigned short argument) const { return this -> value && argument; }
                        friend const boolean operator &&(const unsigned short argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned short argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned short argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned short argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const unsigned short argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        inline const boolean operator &&(void* argument) const { return this -> value && (NULL != argument); }
                        friend const boolean operator &&(void* argumentA, const boolean argumentB) { return (NULL != argumentA) && argumentB.valueOf(); }
                        friend const boolean operator &&(void* argumentA, boolean& argumentB) { return (NULL != argumentA) && argumentB.valueOf(); }
                        friend const boolean operator &&(void* argumentA, const boolean& argumentB) { return (NULL != argumentA) && argumentB.valueOf(); }
                        friend const boolean operator &&(void* argumentA, boolean&& argumentB) { return (NULL != argumentA) && argumentB.valueOf(); }
                        friend const boolean operator &&(void* argumentA, const boolean&& argumentB) { return (NULL != argumentA) && argumentB.valueOf(); }

                        inline const boolean operator &&(const void* argument) const { return this -> value && (NULL != argument); }
                        friend const boolean operator &&(const void* argumentA, const boolean argumentB) { return (NULL != argumentA) && argumentB.valueOf(); }
                        friend const boolean operator &&(const void* argumentA, boolean& argumentB) { return (NULL != argumentA) && argumentB.valueOf(); }
                        friend const boolean operator &&(const void* argumentA, const boolean& argumentB) { return (NULL != argumentA) && argumentB.valueOf(); }
                        friend const boolean operator &&(const void* argumentA, boolean&& argumentB) { return (NULL != argumentA) && argumentB.valueOf(); }
                        friend const boolean operator &&(const void* argumentA, const boolean&& argumentB) { return (NULL != argumentA) && argumentB.valueOf(); }

                        inline const boolean operator &&(const wchar_t argument) const { return this -> value && argument; }
                        friend const boolean operator &&(const wchar_t argumentA, const boolean argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const wchar_t argumentA, boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const wchar_t argumentA, const boolean& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const wchar_t argumentA, boolean&& argumentB) { return argumentA && argumentB.valueOf(); }
                        friend const boolean operator &&(const wchar_t argumentA, const boolean&& argumentB) { return argumentA && argumentB.valueOf(); }

                        const boolean operator &&(boolean& argument) { return this -> value && argument.valueOf(); }
                        const boolean operator &&(boolean&& argument) { return this -> value && argument.valueOf(); }
                        const boolean operator &&(const boolean& argument) { return this -> value && argument.valueOf(); }
                        const boolean operator &&(const boolean&& argument) { return this -> value && argument.valueOf(); }

                        // [||]
                        inline const boolean operator ||(const char argument) const { return this -> value || argument; }
                        friend const boolean operator ||(const char argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const char argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const char argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const char argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const char argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator ||(const char16_t argument) const { return this -> value || argument; }
                        friend const boolean operator ||(const char16_t argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const char16_t argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const char16_t argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const char16_t argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const char16_t argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator ||(const char32_t argument) const { return this -> value || argument; }
                        friend const boolean operator ||(const char32_t argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const char32_t argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const char32_t argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const char32_t argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const char32_t argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator ||(const double argument) const { return this -> value || argument; }
                        friend const boolean operator ||(const double argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const double argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const double argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const double argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const double argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator ||(const float argument) const { return this -> value || argument; }
                        friend const boolean operator ||(const float argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const float argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const float argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const float argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const float argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator ||(const int argument) const { return this -> value || argument; }
                        friend const boolean operator ||(const int argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const int argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const int argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const int argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const int argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator ||(const long argument) const { return this -> value || argument; }
                        friend const boolean operator ||(const long argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const long argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const long argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const long argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const long argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator ||(const long double argument) const { return this -> value || argument; }
                        friend const boolean operator ||(const long double argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const long double argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const long double argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const long double argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const long double argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator ||(const long long argument) const { return this -> value || argument; }
                        friend const boolean operator ||(const long long argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const long long argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const long long argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const long long argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const long long argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator ||(const short argument) const { return this -> value || argument; }
                        friend const boolean operator ||(const short argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const short argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const short argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const short argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const short argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator ||(const signed char argument) const { return this -> value || argument; }
                        friend const boolean operator ||(const signed char argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const signed char argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const signed char argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const signed char argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const signed char argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator ||(const unsigned char argument) const { return this -> value || argument; }
                        friend const boolean operator ||(const unsigned char argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned char argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned char argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned char argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned char argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator ||(const unsigned int argument) const { return this -> value || argument; }
                        friend const boolean operator ||(const unsigned int argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned int argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned int argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned int argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned int argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator ||(const unsigned long argument) const { return this -> value || argument; }
                        friend const boolean operator ||(const unsigned long argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned long argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned long argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned long argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned long argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator ||(const unsigned long long argument) const { return this -> value || argument; }
                        friend const boolean operator ||(const unsigned long long argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned long long argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned long long argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned long long argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned long long argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator ||(const unsigned short argument) const { return this -> value || argument; }
                        friend const boolean operator ||(const unsigned short argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned short argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned short argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned short argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const unsigned short argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        inline const boolean operator ||(void* argument) const { return this -> value || (NULL != argument); }
                        friend const boolean operator ||(void* argumentA, const boolean argumentB) { return (NULL != argumentA) || argumentB.valueOf(); }
                        friend const boolean operator ||(void* argumentA, boolean& argumentB) { return (NULL != argumentA) || argumentB.valueOf(); }
                        friend const boolean operator ||(void* argumentA, const boolean& argumentB) { return (NULL != argumentA) || argumentB.valueOf(); }
                        friend const boolean operator ||(void* argumentA, boolean&& argumentB) { return (NULL != argumentA) || argumentB.valueOf(); }
                        friend const boolean operator ||(void* argumentA, const boolean&& argumentB) { return (NULL != argumentA) || argumentB.valueOf(); }

                        inline const boolean operator ||(const void* argument) const { return this -> value || (NULL != argument); }
                        friend const boolean operator ||(const void* argumentA, const boolean argumentB) { return (NULL != argumentA) || argumentB.valueOf(); }
                        friend const boolean operator ||(const void* argumentA, boolean& argumentB) { return (NULL != argumentA) || argumentB.valueOf(); }
                        friend const boolean operator ||(const void* argumentA, const boolean& argumentB) { return (NULL != argumentA) || argumentB.valueOf(); }
                        friend const boolean operator ||(const void* argumentA, boolean&& argumentB) { return (NULL != argumentA) || argumentB.valueOf(); }
                        friend const boolean operator ||(const void* argumentA, const boolean&& argumentB) { return (NULL != argumentA) || argumentB.valueOf(); }

                        inline const boolean operator ||(const wchar_t argument) const { return this -> value || argument; }
                        friend const boolean operator ||(const wchar_t argumentA, const boolean argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const wchar_t argumentA, boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const wchar_t argumentA, const boolean& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const wchar_t argumentA, boolean&& argumentB) { return argumentA || argumentB.valueOf(); }
                        friend const boolean operator ||(const wchar_t argumentA, const boolean&& argumentB) { return argumentA || argumentB.valueOf(); }

                        const boolean operator ||(boolean& argument) { return this -> value || argument.valueOf(); }
                        const boolean operator ||(boolean&& argument) { return this -> value || argument.valueOf(); }
                        const boolean operator ||(const boolean& argument) { return this -> value || argument.valueOf(); }
                        const boolean operator ||(const boolean&& argument) { return this -> value || argument.valueOf(); }

                        // [+=]
                        inline const boolean& operator +=(const char argument) { argument && (this -> value = 1); return *this; }
                        friend char& operator +=(char& argumentA, boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend char& operator +=(char& argumentA, boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend char& operator +=(char& argumentA, const boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend char& operator +=(char& argumentA, const boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator +=(const char16_t argument) { argument && (this -> value = 1); return *this; }
                        friend char16_t& operator +=(char16_t& argumentA, boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator +=(char16_t& argumentA, boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator +=(char16_t& argumentA, const boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator +=(char16_t& argumentA, const boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator +=(const char32_t argument) { argument && (this -> value = 1); return *this; }
                        friend char32_t& operator +=(char32_t& argumentA, boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator +=(char32_t& argumentA, boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator +=(char32_t& argumentA, const boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator +=(char32_t& argumentA, const boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator +=(const double argument) { argument && (this -> value = 1); return *this; }
                        friend double& operator +=(double& argumentA, boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend double& operator +=(double& argumentA, boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend double& operator +=(double& argumentA, const boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend double& operator +=(double& argumentA, const boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator +=(const float argument) { argument && (this -> value = 1); return *this; }
                        friend float& operator +=(float& argumentA, boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend float& operator +=(float& argumentA, boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend float& operator +=(float& argumentA, const boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend float& operator +=(float& argumentA, const boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator +=(const int argument) { argument && (this -> value = 1); return *this; }
                        friend int& operator +=(int& argumentA, boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend int& operator +=(int& argumentA, boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend int& operator +=(int& argumentA, const boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend int& operator +=(int& argumentA, const boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator +=(const long argument) { argument && (this -> value = 1); return *this; }
                        friend long& operator +=(long& argumentA, boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend long& operator +=(long& argumentA, boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend long& operator +=(long& argumentA, const boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend long& operator +=(long& argumentA, const boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator +=(const long double argument) { argument && (this -> value = 1); return *this; }
                        friend long double& operator +=(long double& argumentA, boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend long double& operator +=(long double& argumentA, boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend long double& operator +=(long double& argumentA, const boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend long double& operator +=(long double& argumentA, const boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator +=(const long long argument) { argument && (this -> value = 1); return *this; }
                        friend long long& operator +=(long long& argumentA, boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend long long& operator +=(long long& argumentA, boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend long long& operator +=(long long& argumentA, const boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend long long& operator +=(long long& argumentA, const boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator +=(const short argument) { argument && (this -> value = 1); return *this; }
                        friend short& operator +=(short& argumentA, boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend short& operator +=(short& argumentA, boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend short& operator +=(short& argumentA, const boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend short& operator +=(short& argumentA, const boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator +=(const signed char argument) { argument && (this -> value = 1); return *this; }
                        friend signed char& operator +=(signed char& argumentA, boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend signed char& operator +=(signed char& argumentA, boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend signed char& operator +=(signed char& argumentA, const boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend signed char& operator +=(signed char& argumentA, const boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator +=(const unsigned char argument) { argument && (this -> value = 1); return *this; }
                        friend unsigned char& operator +=(unsigned char& argumentA, boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator +=(unsigned char& argumentA, boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator +=(unsigned char& argumentA, const boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator +=(unsigned char& argumentA, const boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator +=(const unsigned int argument) { argument && (this -> value = 1); return *this; }
                        friend unsigned int& operator +=(unsigned int& argumentA, boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator +=(unsigned int& argumentA, boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator +=(unsigned int& argumentA, const boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator +=(unsigned int& argumentA, const boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator +=(const unsigned long argument) { argument && (this -> value = 1); return *this; }
                        friend unsigned long& operator +=(unsigned long& argumentA, boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator +=(unsigned long& argumentA, boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator +=(unsigned long& argumentA, const boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator +=(unsigned long& argumentA, const boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator +=(const unsigned long long argument) { argument && (this -> value = 1); return *this; }
                        friend unsigned long long& operator +=(unsigned long long& argumentA, boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator +=(unsigned long long& argumentA, boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator +=(unsigned long long& argumentA, const boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator +=(unsigned long long& argumentA, const boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator +=(const unsigned short argument) { argument && (this -> value = 1); return *this; }
                        friend unsigned short& operator +=(unsigned short& argumentA, boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator +=(unsigned short& argumentA, boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator +=(unsigned short& argumentA, const boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator +=(unsigned short& argumentA, const boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator +=(void* argument) { (NULL == argument) || (this -> value = 1); return *this; }
                        inline const boolean& operator +=(const void* argument) { (NULL == argument) || (this -> value = 1); return *this; }

                        inline const boolean& operator +=(const wchar_t argument) { argument && (this -> value = 1); return *this; }
                        friend wchar_t& operator +=(wchar_t& argumentA, boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator +=(wchar_t& argumentA, boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator +=(wchar_t& argumentA, const boolean& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator +=(wchar_t& argumentA, const boolean&& argumentB) { argumentA += argumentB.valueOf(); return argumentA; }

                        const boolean& operator +=(boolean& argument) { argument.valueOf() && (this -> value = 1); return *this; }
                        const boolean& operator +=(boolean&& argument) { argument.valueOf() && (this -> value = 1); return *this; }
                        const boolean& operator +=(const boolean& argument) { argument.valueOf() && (this -> value = 1); return *this; }
                        const boolean& operator +=(const boolean&& argument) { argument.valueOf() && (this -> value = 1); return *this; }

                        // [-=]
                        inline const boolean& operator -=(const char argument) { argument && (this -> value = 0); return *this; }
                        friend char& operator -=(char& argumentA, boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend char& operator -=(char& argumentA, boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend char& operator -=(char& argumentA, const boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend char& operator -=(char& argumentA, const boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator -=(const char16_t argument) { argument && (this -> value = 0); return *this; }
                        friend char16_t& operator -=(char16_t& argumentA, boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator -=(char16_t& argumentA, boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator -=(char16_t& argumentA, const boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator -=(char16_t& argumentA, const boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator -=(const char32_t argument) { argument && (this -> value = 0); return *this; }
                        friend char32_t& operator -=(char32_t& argumentA, boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator -=(char32_t& argumentA, boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator -=(char32_t& argumentA, const boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator -=(char32_t& argumentA, const boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator -=(const double argument) { argument && (this -> value = 0); return *this; }
                        friend double& operator -=(double& argumentA, boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend double& operator -=(double& argumentA, boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend double& operator -=(double& argumentA, const boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend double& operator -=(double& argumentA, const boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator -=(const float argument) { argument && (this -> value = 0); return *this; }
                        friend float& operator -=(float& argumentA, boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend float& operator -=(float& argumentA, boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend float& operator -=(float& argumentA, const boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend float& operator -=(float& argumentA, const boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator -=(const int argument) { argument && (this -> value = 0); return *this; }
                        friend int& operator -=(int& argumentA, boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend int& operator -=(int& argumentA, boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend int& operator -=(int& argumentA, const boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend int& operator -=(int& argumentA, const boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator -=(const long argument) { argument && (this -> value = 0); return *this; }
                        friend long& operator -=(long& argumentA, boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend long& operator -=(long& argumentA, boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend long& operator -=(long& argumentA, const boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend long& operator -=(long& argumentA, const boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator -=(const long double argument) { argument && (this -> value = 0); return *this; }
                        friend long double& operator -=(long double& argumentA, boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend long double& operator -=(long double& argumentA, boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend long double& operator -=(long double& argumentA, const boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend long double& operator -=(long double& argumentA, const boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator -=(const long long argument) { argument && (this -> value = 0); return *this; }
                        friend long long& operator -=(long long& argumentA, boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend long long& operator -=(long long& argumentA, boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend long long& operator -=(long long& argumentA, const boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend long long& operator -=(long long& argumentA, const boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator -=(const short argument) { argument && (this -> value = 0); return *this; }
                        friend short& operator -=(short& argumentA, boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend short& operator -=(short& argumentA, boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend short& operator -=(short& argumentA, const boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend short& operator -=(short& argumentA, const boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator -=(const signed char argument) { argument && (this -> value = 0); return *this; }
                        friend signed char& operator -=(signed char& argumentA, boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator -=(signed char& argumentA, boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator -=(signed char& argumentA, const boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator -=(signed char& argumentA, const boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator -=(const unsigned char argument) { argument && (this -> value = 0); return *this; }
                        friend unsigned char& operator -=(unsigned char& argumentA, boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator -=(unsigned char& argumentA, boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator -=(unsigned char& argumentA, const boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator -=(unsigned char& argumentA, const boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator -=(const unsigned int argument) { argument && (this -> value = 0); return *this; }
                        friend unsigned int& operator -=(unsigned int& argumentA, boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator -=(unsigned int& argumentA, boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator -=(unsigned int& argumentA, const boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator -=(unsigned int& argumentA, const boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator -=(const unsigned long argument) { argument && (this -> value = 0); return *this; }
                        friend unsigned long& operator -=(unsigned long& argumentA, boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator -=(unsigned long& argumentA, boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator -=(unsigned long& argumentA, const boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator -=(unsigned long& argumentA, const boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator -=(const unsigned long long argument) { argument && (this -> value = 0); return *this; }
                        friend unsigned long long& operator -=(unsigned long long& argumentA, boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator -=(unsigned long long& argumentA, boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator -=(unsigned long long& argumentA, const boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator -=(unsigned long long& argumentA, const boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator -=(const unsigned short argument) { argument && (this -> value = 0); return *this; }
                        friend unsigned short& operator -=(unsigned short& argumentA, boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator -=(unsigned short& argumentA, boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator -=(unsigned short& argumentA, const boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator -=(unsigned short& argumentA, const boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator -=(void* argument) { (NULL == argument) || (this -> value = 0); return *this; }
                        inline const boolean& operator -=(const void* argument) { (NULL == argument) || (this -> value = 0); return *this; }

                        inline const boolean& operator -=(const wchar_t argument) { argument && (this -> value = 0); return *this; }
                        friend wchar_t& operator -=(wchar_t& argumentA, boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator -=(wchar_t& argumentA, boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator -=(wchar_t& argumentA, const boolean& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator -=(wchar_t& argumentA, const boolean&& argumentB) { argumentA -= argumentB.valueOf(); return argumentA; }

                        const boolean& operator -=(boolean& argument) { argument.valueOf() && (this -> value = 0); return *this; }
                        const boolean& operator -=(boolean&& argument) { argument.valueOf() && (this -> value = 0); return *this; }
                        const boolean& operator -=(const boolean& argument) { argument.valueOf() && (this -> value = 0); return *this; }
                        const boolean& operator -=(const boolean&& argument) { argument.valueOf() && (this -> value = 0); return *this; }

                        // [/=]
                        inline const boolean& operator /=(const char argument) { this -> value = argument && this -> value; return *this; }
                        friend char& operator /=(char& argumentA, boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend char& operator /=(char& argumentA, boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend char& operator /=(char& argumentA, const boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend char& operator /=(char& argumentA, const boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator /=(const char16_t argument) { this -> value = argument && this -> value; return *this; }
                        friend char16_t& operator /=(char16_t& argumentA, boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator /=(char16_t& argumentA, boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator /=(char16_t& argumentA, const boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator /=(char16_t& argumentA, const boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator /=(const char32_t argument) { this -> value = argument && this -> value; return *this; }
                        friend char32_t& operator /=(char32_t& argumentA, boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator /=(char32_t& argumentA, boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator /=(char32_t& argumentA, const boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator /=(char32_t& argumentA, const boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator /=(const double argument) { this -> value = argument && this -> value; return *this; }
                        friend double& operator /=(double& argumentA, boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend double& operator /=(double& argumentA, boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend double& operator /=(double& argumentA, const boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend double& operator /=(double& argumentA, const boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator /=(const float argument) { this -> value = argument && this -> value; return *this; }
                        friend float& operator /=(float& argumentA, boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend float& operator /=(float& argumentA, boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend float& operator /=(float& argumentA, const boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend float& operator /=(float& argumentA, const boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator /=(const int argument) { this -> value = argument && this -> value; return *this; }
                        friend int& operator /=(int& argumentA, boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend int& operator /=(int& argumentA, boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend int& operator /=(int& argumentA, const boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend int& operator /=(int& argumentA, const boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator /=(const long argument) { this -> value = argument && this -> value; return *this; }
                        friend long& operator /=(long& argumentA, boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend long& operator /=(long& argumentA, boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend long& operator /=(long& argumentA, const boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend long& operator /=(long& argumentA, const boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator /=(const long double argument) { this -> value = argument && this -> value; return *this; }
                        friend long double& operator /=(long double& argumentA, boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend long double& operator /=(long double& argumentA, boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend long double& operator /=(long double& argumentA, const boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend long double& operator /=(long double& argumentA, const boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator /=(const long long argument) { this -> value = argument && this -> value; return *this; }
                        friend long long& operator /=(long long& argumentA, boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend long long& operator /=(long long& argumentA, boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend long long& operator /=(long long& argumentA, const boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend long long& operator /=(long long& argumentA, const boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator /=(const short argument) { this -> value = argument && this -> value; return *this; }
                        friend short& operator /=(short& argumentA, boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend short& operator /=(short& argumentA, boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend short& operator /=(short& argumentA, const boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend short& operator /=(short& argumentA, const boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator /=(const signed char argument) { this -> value = argument && this -> value; return *this; }
                        friend signed char& operator /=(signed char& argumentA, boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator /=(signed char& argumentA, boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator /=(signed char& argumentA, const boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator /=(signed char& argumentA, const boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator /=(const unsigned char argument) { this -> value = argument && this -> value; return *this; }
                        friend unsigned char& operator /=(unsigned char& argumentA, boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator /=(unsigned char& argumentA, boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator /=(unsigned char& argumentA, const boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator /=(unsigned char& argumentA, const boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator /=(const unsigned int argument) { this -> value = argument && this -> value; return *this; }
                        friend unsigned int& operator /=(unsigned int& argumentA, boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator /=(unsigned int& argumentA, boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator /=(unsigned int& argumentA, const boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator /=(unsigned int& argumentA, const boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator /=(const unsigned long argument) { this -> value = argument && this -> value; return *this; }
                        friend unsigned long& operator /=(unsigned long& argumentA, boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator /=(unsigned long& argumentA, boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator /=(unsigned long& argumentA, const boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator /=(unsigned long& argumentA, const boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator /=(const unsigned long long argument) { this -> value = argument && this -> value; return *this; }
                        friend unsigned long long& operator /=(unsigned long long& argumentA, boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator /=(unsigned long long& argumentA, boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator /=(unsigned long long& argumentA, const boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator /=(unsigned long long& argumentA, const boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator /=(const unsigned short argument) { this -> value = argument && this -> value; return *this; }
                        friend unsigned short& operator /=(unsigned short& argumentA, boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator /=(unsigned short& argumentA, boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator /=(unsigned short& argumentA, const boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator /=(unsigned short& argumentA, const boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator /=(void* argument) { this -> value = (NULL != argument) && this -> value; return *this; }
                        inline const boolean& operator /=(const void* argument) { this -> value = (NULL != argument) && this -> value; return *this; }

                        inline const boolean& operator /=(const wchar_t argument) { this -> value = argument && this -> value; return *this; }
                        friend wchar_t& operator /=(wchar_t& argumentA, boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator /=(wchar_t& argumentA, boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator /=(wchar_t& argumentA, const boolean& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator /=(wchar_t& argumentA, const boolean&& argumentB) { argumentA /= argumentB.valueOf(); return argumentA; }

                        const boolean& operator /=(boolean& argument) { this -> value = argument.valueOf() && this -> value; return *this; }
                        const boolean& operator /=(boolean&& argument) { this -> value = argument.valueOf() && this -> value; return *this; }
                        const boolean& operator /=(const boolean& argument) { this -> value = argument.valueOf() && this -> value; return *this; }
                        const boolean& operator /=(const boolean&& argument) { this -> value = argument.valueOf() && this -> value; return *this; }

                        // [%=]
                        inline const boolean& operator %=(const char argument) { this -> value = 0; return *this; }
                        friend char& operator %=(char& argumentA, boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend char& operator %=(char& argumentA, boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend char& operator %=(char& argumentA, const boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend char& operator %=(char& argumentA, const boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator %=(const char16_t argument) { this -> value = 0; return *this; }
                        friend char16_t& operator %=(char16_t& argumentA, boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator %=(char16_t& argumentA, boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator %=(char16_t& argumentA, const boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator %=(char16_t& argumentA, const boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator %=(const char32_t argument) { this -> value = 0; return *this; }
                        friend char32_t& operator %=(char32_t& argumentA, boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator %=(char32_t& argumentA, boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator %=(char32_t& argumentA, const boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator %=(char32_t& argumentA, const boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator %=(const double argument) { this -> value = 0; return *this; }
                        friend double& operator %=(double& argumentA, boolean& argumentB) { argumentB.valueOf() ? argumentA = double(0.0) : argumentA /= double(0.0); return argumentA; }
                        friend double& operator %=(double& argumentA, boolean&& argumentB) { argumentB.valueOf() ? argumentA = double(0.0) : argumentA /= double(0.0); return argumentA; }
                        friend double& operator %=(double& argumentA, const boolean& argumentB) { argumentB.valueOf() ? argumentA = double(0.0) : argumentA /= double(0.0); return argumentA; }
                        friend double& operator %=(double& argumentA, const boolean&& argumentB) { argumentB.valueOf() ? argumentA = double(0.0) : argumentA /= double(0.0); return argumentA; }

                        inline const boolean& operator %=(const float argument) { this -> value = 0; return *this; }
                        friend float& operator %=(float& argumentA, boolean& argumentB) { argumentB.valueOf() ? argumentA = 0.0f : argumentA /= 0.0f; return argumentA; }
                        friend float& operator %=(float& argumentA, boolean&& argumentB) { argumentB.valueOf() ? argumentA = 0.0f : argumentA /= 0.0f; return argumentA; }
                        friend float& operator %=(float& argumentA, const boolean& argumentB) { argumentB.valueOf() ? argumentA = 0.0f : argumentA /= 0.0f; return argumentA; }
                        friend float& operator %=(float& argumentA, const boolean&& argumentB) { argumentB.valueOf() ? argumentA = 0.0f : argumentA /= 0.0f; return argumentA; }

                        inline const boolean& operator %=(const int argument) { this -> value = 0; return *this; }
                        friend int& operator %=(int& argumentA, boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend int& operator %=(int& argumentA, boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend int& operator %=(int& argumentA, const boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend int& operator %=(int& argumentA, const boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator %=(const long argument) { this -> value = 0; return *this; }
                        friend long& operator %=(long& argumentA, boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend long& operator %=(long& argumentA, boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend long& operator %=(long& argumentA, const boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend long& operator %=(long& argumentA, const boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator %=(const long double argument) { this -> value = 0; return *this; }
                        friend long double& operator %=(long double& argumentA, boolean& argumentB) { argumentB.valueOf() ? argumentA = 0.00 : argumentA /= 0.00; return argumentA; }
                        friend long double& operator %=(long double& argumentA, boolean&& argumentB) { argumentB.valueOf() ? argumentA = 0.00 : argumentA /= 0.00; return argumentA; }
                        friend long double& operator %=(long double& argumentA, const boolean& argumentB) { argumentB.valueOf() ? argumentA = 0.00 : argumentA /= 0.00; return argumentA; }
                        friend long double& operator %=(long double& argumentA, const boolean&& argumentB) { argumentB.valueOf() ? argumentA = 0.00 : argumentA /= 0.00; return argumentA; }

                        inline const boolean& operator %=(const long long argument) { this -> value = 0; return *this; }
                        friend long long& operator %=(long long& argumentA, boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend long long& operator %=(long long& argumentA, boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend long long& operator %=(long long& argumentA, const boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend long long& operator %=(long long& argumentA, const boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator %=(const short argument) { this -> value = 0; return *this; }
                        friend short& operator %=(short& argumentA, boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend short& operator %=(short& argumentA, boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend short& operator %=(short& argumentA, const boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend short& operator %=(short& argumentA, const boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator %=(const signed char argument) { this -> value = 0; return *this; }
                        friend signed char& operator %=(signed char& argumentA, boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator %=(signed char& argumentA, boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator %=(signed char& argumentA, const boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator %=(signed char& argumentA, const boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator %=(const unsigned char argument) { this -> value = 0; return *this; }
                        friend unsigned char& operator %=(unsigned char& argumentA, boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator %=(unsigned char& argumentA, boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator %=(unsigned char& argumentA, const boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator %=(unsigned char& argumentA, const boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator %=(const unsigned int argument) { this -> value = 0; return *this; }
                        friend unsigned int& operator %=(unsigned int& argumentA, boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator %=(unsigned int& argumentA, boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator %=(unsigned int& argumentA, const boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator %=(unsigned int& argumentA, const boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator %=(const unsigned long argument) { this -> value = 0; return *this; }
                        friend unsigned long& operator %=(unsigned long& argumentA, boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator %=(unsigned long& argumentA, boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator %=(unsigned long& argumentA, const boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator %=(unsigned long& argumentA, const boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator %=(const unsigned long long argument) { this -> value = 0; return *this; }
                        friend unsigned long long& operator %=(unsigned long long& argumentA, boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator %=(unsigned long long& argumentA, boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator %=(unsigned long long& argumentA, const boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator %=(unsigned long long& argumentA, const boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator %=(const unsigned short argument) { this -> value = 0; return *this; }
                        friend unsigned short& operator %=(unsigned short& argumentA, boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator %=(unsigned short& argumentA, boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator %=(unsigned short& argumentA, const boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator %=(unsigned short& argumentA, const boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator %=(void* argument) { this -> value = 0; return *this; }
                        inline const boolean& operator %=(const void* argument) { this -> value = 0; return *this; }

                        inline const boolean& operator %=(const wchar_t argument) { this -> value = 0; return *this; }
                        friend wchar_t& operator %=(wchar_t& argumentA, boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator %=(wchar_t& argumentA, boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator %=(wchar_t& argumentA, const boolean& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator %=(wchar_t& argumentA, const boolean&& argumentB) { argumentA %= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator %=(boolean& argument) { this -> value = 0; return *this; }
                        inline const boolean& operator %=(boolean&& argument) { this -> value = 0; return *this; }
                        inline const boolean& operator %=(const boolean& argument) { this -> value = 0; return *this; }
                        inline const boolean& operator %=(const boolean&& argument) { this -> value = 0; return *this; }

                        // [^=]
                        inline const boolean& operator ^=(const char argument) { this -> value = boolean(this -> value ^ argument).valueOf(); return *this; }
                        friend char& operator ^=(char& argumentA, boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend char& operator ^=(char& argumentA, boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend char& operator ^=(char& argumentA, const boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend char& operator ^=(char& argumentA, const boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator ^=(const char16_t argument) { this -> value = boolean(this -> value ^ argument).valueOf(); return *this; }
                        friend char16_t& operator ^=(char16_t& argumentA, boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator ^=(char16_t& argumentA, boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator ^=(char16_t& argumentA, const boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator ^=(char16_t& argumentA, const boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator ^=(const char32_t argument) { this -> value = boolean(this -> value ^ argument).valueOf(); return *this; }
                        friend char32_t& operator ^=(char32_t& argumentA, boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator ^=(char32_t& argumentA, boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator ^=(char32_t& argumentA, const boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator ^=(char32_t& argumentA, const boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator ^=(const double argument) { this -> value = boolean(this -> value ^ long(argument)).valueOf(); return *this; }
                        friend double& operator ^=(double& argumentA, boolean& argumentB) { argumentA = long(argumentA) ^ argumentB.valueOf(); return argumentA; }
                        friend double& operator ^=(double& argumentA, boolean&& argumentB) { argumentA = long(argumentA) ^ argumentB.valueOf(); return argumentA; }
                        friend double& operator ^=(double& argumentA, const boolean& argumentB) { argumentA = long(argumentA) ^ argumentB.valueOf(); return argumentA; }
                        friend double& operator ^=(double& argumentA, const boolean&& argumentB) { argumentA = long(argumentA) ^ argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator ^=(const float argument) { this -> value = boolean(this -> value ^ int(argument)).valueOf(); return *this; }
                        friend float& operator ^=(float& argumentA, boolean& argumentB) { argumentA = int(argumentA) ^ argumentB.valueOf(); return argumentA; }
                        friend float& operator ^=(float& argumentA, boolean&& argumentB) { argumentA = int(argumentA) ^ argumentB.valueOf(); return argumentA; }
                        friend float& operator ^=(float& argumentA, const boolean& argumentB) { argumentA = int(argumentA) ^ argumentB.valueOf(); return argumentA; }
                        friend float& operator ^=(float& argumentA, const boolean&& argumentB) { argumentA = int(argumentA) ^ argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator ^=(const int argument) { this -> value = boolean(this -> value ^ argument).valueOf(); return *this; }
                        friend int& operator ^=(int& argumentA, boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend int& operator ^=(int& argumentA, boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend int& operator ^=(int& argumentA, const boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend int& operator ^=(int& argumentA, const boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator ^=(const long argument) { this -> value = boolean(this -> value ^ argument).valueOf(); return *this; }
                        friend long& operator ^=(long& argumentA, boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend long& operator ^=(long& argumentA, boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend long& operator ^=(long& argumentA, const boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend long& operator ^=(long& argumentA, const boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator ^=(const long double argument) { this -> value = boolean(this -> value ^ (long long) argument).valueOf(); return *this; }
                        friend long double& operator ^=(long double& argumentA, boolean& argumentB) { argumentA = (long long) argumentA ^ argumentB.valueOf(); return argumentA; }
                        friend long double& operator ^=(long double& argumentA, boolean&& argumentB) { argumentA = (long long) argumentA ^ argumentB.valueOf(); return argumentA; }
                        friend long double& operator ^=(long double& argumentA, const boolean& argumentB) { argumentA = (long long) argumentA ^ argumentB.valueOf(); return argumentA; }
                        friend long double& operator ^=(long double& argumentA, const boolean&& argumentB) { argumentA = (long long) argumentA ^ argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator ^=(const long long argument) { this -> value = boolean(this -> value ^ argument).valueOf(); return *this; }
                        friend long long& operator ^=(long long& argumentA, boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend long long& operator ^=(long long& argumentA, boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend long long& operator ^=(long long& argumentA, const boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend long long& operator ^=(long long& argumentA, const boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator ^=(const short argument) { this -> value = boolean(this -> value ^ argument).valueOf(); return *this; }
                        friend short& operator ^=(short& argumentA, boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend short& operator ^=(short& argumentA, boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend short& operator ^=(short& argumentA, const boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend short& operator ^=(short& argumentA, const boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator ^=(const signed char argument) { this -> value = boolean(this -> value ^ argument).valueOf(); return *this; }
                        friend signed char& operator ^=(signed char& argumentA, boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator ^=(signed char& argumentA, boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator ^=(signed char& argumentA, const boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator ^=(signed char& argumentA, const boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator ^=(const unsigned char argument) { this -> value = boolean(this -> value ^ argument).valueOf(); return *this; }
                        friend unsigned char& operator ^=(unsigned char& argumentA, boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator ^=(unsigned char& argumentA, boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator ^=(unsigned char& argumentA, const boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator ^=(unsigned char& argumentA, const boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator ^=(const unsigned int argument) { this -> value = boolean(this -> value ^ argument).valueOf(); return *this; }
                        friend unsigned int& operator ^=(unsigned int& argumentA, boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator ^=(unsigned int& argumentA, boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator ^=(unsigned int& argumentA, const boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator ^=(unsigned int& argumentA, const boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator ^=(const unsigned long argument) { this -> value = boolean(this -> value ^ argument).valueOf(); return *this; }
                        friend unsigned long& operator ^=(unsigned long& argumentA, boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator ^=(unsigned long& argumentA, boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator ^=(unsigned long& argumentA, const boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator ^=(unsigned long& argumentA, const boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator ^=(const unsigned long long argument) { this -> value = boolean(this -> value ^ argument).valueOf(); return *this; }
                        friend unsigned long long& operator ^=(unsigned long long& argumentA, boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator ^=(unsigned long long& argumentA, boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator ^=(unsigned long long& argumentA, const boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator ^=(unsigned long long& argumentA, const boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator ^=(const unsigned short argument) { this -> value = boolean(this -> value ^ argument).valueOf(); return *this; }
                        friend unsigned short& operator ^=(unsigned short& argumentA, boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator ^=(unsigned short& argumentA, boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator ^=(unsigned short& argumentA, const boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator ^=(unsigned short& argumentA, const boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator ^=(void* argument) { this -> value = boolean(this -> value ^ (NULL == argument ? 0 : (int) argument)).valueOf(); return *this; }
                        inline const boolean& operator ^=(const void* argument) { this -> value = boolean(this -> value ^ (NULL == argument ? 0 : (int) argument)).valueOf(); return *this; }

                        inline const boolean& operator ^=(const wchar_t argument) { this -> value = boolean(this -> value ^ argument).valueOf(); return *this; }
                        friend wchar_t& operator ^=(wchar_t& argumentA, boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator ^=(wchar_t& argumentA, boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator ^=(wchar_t& argumentA, const boolean& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator ^=(wchar_t& argumentA, const boolean&& argumentB) { argumentA ^= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator ^=(boolean& argument) { this -> value = boolean(this -> value ^ argument.valueOf()).valueOf(); return *this; }
                        inline const boolean& operator ^=(boolean&& argument) { this -> value = boolean(this -> value ^ argument.valueOf()).valueOf(); return *this; }
                        inline const boolean& operator ^=(const boolean& argument) { this -> value = boolean(this -> value ^ argument.valueOf()).valueOf(); return *this; }
                        inline const boolean& operator ^=(const boolean&& argument) { this -> value = boolean(this -> value ^ argument.valueOf()).valueOf(); return *this; }

                        // [&=]
                        inline const boolean& operator &=(const char argument) { this -> value = boolean(this -> value & argument).valueOf(); return *this; }
                        friend char& operator &=(char& argumentA, boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend char& operator &=(char& argumentA, boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend char& operator &=(char& argumentA, const boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend char& operator &=(char& argumentA, const boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator &=(const char16_t argument) { this -> value = boolean(this -> value & argument).valueOf(); return *this; }
                        friend char16_t& operator &=(char16_t& argumentA, boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator &=(char16_t& argumentA, boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator &=(char16_t& argumentA, const boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator &=(char16_t& argumentA, const boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator &=(const char32_t argument) { this -> value = boolean(this -> value & argument).valueOf(); return *this; }
                        friend char32_t& operator &=(char32_t& argumentA, boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator &=(char32_t& argumentA, boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator &=(char32_t& argumentA, const boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator &=(char32_t& argumentA, const boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator &=(const double argument) { this -> value = boolean(this -> value & long(argument)).valueOf(); return *this; }
                        friend double& operator &=(double& argumentA, boolean& argumentB) { argumentA = long(argumentA) & argumentB.valueOf(); return argumentA; }
                        friend double& operator &=(double& argumentA, boolean&& argumentB) { argumentA = long(argumentA) & argumentB.valueOf(); return argumentA; }
                        friend double& operator &=(double& argumentA, const boolean& argumentB) { argumentA = long(argumentA) & argumentB.valueOf(); return argumentA; }
                        friend double& operator &=(double& argumentA, const boolean&& argumentB) { argumentA = long(argumentA) & argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator &=(const float argument) { this -> value = boolean(this -> value & int(argument)).valueOf(); return *this; }
                        friend float& operator &=(float& argumentA, boolean& argumentB) { argumentA = int(argumentA) & argumentB.valueOf(); return argumentA; }
                        friend float& operator &=(float& argumentA, boolean&& argumentB) { argumentA = int(argumentA) & argumentB.valueOf(); return argumentA; }
                        friend float& operator &=(float& argumentA, const boolean& argumentB) { argumentA = int(argumentA) & argumentB.valueOf(); return argumentA; }
                        friend float& operator &=(float& argumentA, const boolean&& argumentB) { argumentA = int(argumentA) & argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator &=(const int argument) { this -> value = boolean(this -> value & argument).valueOf(); return *this; }
                        friend int& operator &=(int& argumentA, boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend int& operator &=(int& argumentA, boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend int& operator &=(int& argumentA, const boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend int& operator &=(int& argumentA, const boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator &=(const long argument) { this -> value = boolean(this -> value & argument).valueOf(); return *this; }
                        friend long& operator &=(long& argumentA, boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend long& operator &=(long& argumentA, boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend long& operator &=(long& argumentA, const boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend long& operator &=(long& argumentA, const boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator &=(const long double argument) { this -> value = boolean(this -> value & (long long) argument).valueOf(); return *this; }
                        friend long double& operator &=(long double& argumentA, boolean& argumentB) { argumentA = (long long) argumentA & argumentB.valueOf(); return argumentA; }
                        friend long double& operator &=(long double& argumentA, boolean&& argumentB) { argumentA = (long long) argumentA & argumentB.valueOf(); return argumentA; }
                        friend long double& operator &=(long double& argumentA, const boolean& argumentB) { argumentA = (long long) argumentA & argumentB.valueOf(); return argumentA; }
                        friend long double& operator &=(long double& argumentA, const boolean&& argumentB) { argumentA = (long long) argumentA & argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator &=(const long long argument) { this -> value = boolean(this -> value & argument).valueOf(); return *this; }
                        friend long long& operator &=(long long& argumentA, boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend long long& operator &=(long long& argumentA, boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend long long& operator &=(long long& argumentA, const boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend long long& operator &=(long long& argumentA, const boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator &=(const short argument) { this -> value = boolean(this -> value & argument).valueOf(); return *this; }
                        friend short& operator &=(short& argumentA, boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend short& operator &=(short& argumentA, boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend short& operator &=(short& argumentA, const boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend short& operator &=(short& argumentA, const boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator &=(const signed char argument) { this -> value = boolean(this -> value & argument).valueOf(); return *this; }
                        friend signed char& operator &=(signed char& argumentA, boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator &=(signed char& argumentA, boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator &=(signed char& argumentA, const boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator &=(signed char& argumentA, const boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator &=(const unsigned char argument) { this -> value = boolean(this -> value & argument).valueOf(); return *this; }
                        friend unsigned char& operator &=(unsigned char& argumentA, boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator &=(unsigned char& argumentA, boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator &=(unsigned char& argumentA, const boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator &=(unsigned char& argumentA, const boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator &=(const unsigned int argument) { this -> value = boolean(this -> value & argument).valueOf(); return *this; }
                        friend unsigned int& operator &=(unsigned int& argumentA, boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator &=(unsigned int& argumentA, boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator &=(unsigned int& argumentA, const boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator &=(unsigned int& argumentA, const boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator &=(const unsigned long argument) { this -> value = boolean(this -> value & argument).valueOf(); return *this; }
                        friend unsigned long& operator &=(unsigned long& argumentA, boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator &=(unsigned long& argumentA, boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator &=(unsigned long& argumentA, const boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator &=(unsigned long& argumentA, const boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator &=(const unsigned long long argument) { this -> value = boolean(this -> value & argument).valueOf(); return *this; }
                        friend unsigned long long& operator &=(unsigned long long& argumentA, boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator &=(unsigned long long& argumentA, boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator &=(unsigned long long& argumentA, const boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator &=(unsigned long long& argumentA, const boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator &=(const unsigned short argument) { this -> value = boolean(this -> value & argument).valueOf(); return *this; }
                        friend unsigned short& operator &=(unsigned short& argumentA, boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator &=(unsigned short& argumentA, boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator &=(unsigned short& argumentA, const boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator &=(unsigned short& argumentA, const boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator &=(void* argument) { this -> value = boolean(this -> value & (NULL == argument ? 0 : (int) argument)).valueOf(); return *this; }
                        inline const boolean& operator &=(const void* argument) { this -> value = boolean(this -> value & (NULL == argument ? 0 : (int) argument)).valueOf(); return *this; }

                        inline const boolean& operator &=(const wchar_t argument) { this -> value = boolean(this -> value & argument).valueOf(); return *this; }
                        friend wchar_t& operator &=(wchar_t& argumentA, boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator &=(wchar_t& argumentA, boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator &=(wchar_t& argumentA, const boolean& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator &=(wchar_t& argumentA, const boolean&& argumentB) { argumentA &= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator &=(boolean& argument) { this -> value = boolean(this -> value & argument.valueOf()).valueOf(); return *this; }
                        inline const boolean& operator &=(boolean&& argument) { this -> value = boolean(this -> value & argument.valueOf()).valueOf(); return *this; }
                        inline const boolean& operator &=(const boolean& argument) { this -> value = boolean(this -> value & argument.valueOf()).valueOf(); return *this; }
                        inline const boolean& operator &=(const boolean&& argument) { this -> value = boolean(this -> value & argument.valueOf()).valueOf(); return *this; }

                        // [|=]
                        inline const boolean& operator |=(const char argument) { this -> value = boolean(this -> value | argument).valueOf(); return *this; }
                        friend char& operator |=(char& argumentA, boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend char& operator |=(char& argumentA, boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend char& operator |=(char& argumentA, const boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend char& operator |=(char& argumentA, const boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator |=(const char16_t argument) { this -> value = boolean(this -> value | argument).valueOf(); return *this; }
                        friend char16_t& operator |=(char16_t& argumentA, boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator |=(char16_t& argumentA, boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator |=(char16_t& argumentA, const boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator |=(char16_t& argumentA, const boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator |=(const char32_t argument) { this -> value = boolean(this -> value | argument).valueOf(); return *this; }
                        friend char32_t& operator |=(char32_t& argumentA, boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator |=(char32_t& argumentA, boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator |=(char32_t& argumentA, const boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator |=(char32_t& argumentA, const boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator |=(const double argument) { this -> value = boolean(this -> value | long(argument)).valueOf(); return *this; }
                        friend double& operator |=(double& argumentA, boolean& argumentB) { argumentA = long(argumentA) | argumentB.valueOf(); return argumentA; }
                        friend double& operator |=(double& argumentA, boolean&& argumentB) { argumentA = long(argumentA) | argumentB.valueOf(); return argumentA; }
                        friend double& operator |=(double& argumentA, const boolean& argumentB) { argumentA = long(argumentA) | argumentB.valueOf(); return argumentA; }
                        friend double& operator |=(double& argumentA, const boolean&& argumentB) { argumentA = long(argumentA) | argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator |=(const float argument) { this -> value = boolean(this -> value | int(argument)).valueOf(); return *this; }
                        friend float& operator |=(float& argumentA, boolean& argumentB) { argumentA = int(argumentA) | argumentB.valueOf(); return argumentA; }
                        friend float& operator |=(float& argumentA, boolean&& argumentB) { argumentA = int(argumentA) | argumentB.valueOf(); return argumentA; }
                        friend float& operator |=(float& argumentA, const boolean& argumentB) { argumentA = int(argumentA) | argumentB.valueOf(); return argumentA; }
                        friend float& operator |=(float& argumentA, const boolean&& argumentB) { argumentA = int(argumentA) | argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator |=(const int argument) { this -> value = boolean(this -> value | argument).valueOf(); return *this; }
                        friend int& operator |=(int& argumentA, boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend int& operator |=(int& argumentA, boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend int& operator |=(int& argumentA, const boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend int& operator |=(int& argumentA, const boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator |=(const long argument) { this -> value = boolean(this -> value | argument).valueOf(); return *this; }
                        friend long& operator |=(long& argumentA, boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend long& operator |=(long& argumentA, boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend long& operator |=(long& argumentA, const boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend long& operator |=(long& argumentA, const boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator |=(const long double argument) { this -> value = boolean(this -> value | (long long) argument).valueOf(); return *this; }
                        friend long double& operator |=(long double& argumentA, boolean& argumentB) { argumentA = (long long) argumentA | argumentB.valueOf(); return argumentA; }
                        friend long double& operator |=(long double& argumentA, boolean&& argumentB) { argumentA = (long long) argumentA | argumentB.valueOf(); return argumentA; }
                        friend long double& operator |=(long double& argumentA, const boolean& argumentB) { argumentA = (long long) argumentA | argumentB.valueOf(); return argumentA; }
                        friend long double& operator |=(long double& argumentA, const boolean&& argumentB) { argumentA = (long long) argumentA | argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator |=(const long long argument) { this -> value = boolean(this -> value | argument).valueOf(); return *this; }
                        friend long long& operator |=(long long& argumentA, boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend long long& operator |=(long long& argumentA, boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend long long& operator |=(long long& argumentA, const boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend long long& operator |=(long long& argumentA, const boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator |=(const short argument) { this -> value = boolean(this -> value | argument).valueOf(); return *this; }
                        friend short& operator |=(short& argumentA, boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend short& operator |=(short& argumentA, boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend short& operator |=(short& argumentA, const boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend short& operator |=(short& argumentA, const boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator |=(const signed char argument) { this -> value = boolean(this -> value | argument).valueOf(); return *this; }
                        friend signed char& operator |=(signed char& argumentA, boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator |=(signed char& argumentA, boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator |=(signed char& argumentA, const boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator |=(signed char& argumentA, const boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator |=(const unsigned char argument) { this -> value = boolean(this -> value | argument).valueOf(); return *this; }
                        friend unsigned char& operator |=(unsigned char& argumentA, boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator |=(unsigned char& argumentA, boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator |=(unsigned char& argumentA, const boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator |=(unsigned char& argumentA, const boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator |=(const unsigned int argument) { this -> value = boolean(this -> value | argument).valueOf(); return *this; }
                        friend unsigned int& operator |=(unsigned int& argumentA, boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator |=(unsigned int& argumentA, boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator |=(unsigned int& argumentA, const boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator |=(unsigned int& argumentA, const boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator |=(const unsigned long argument) { this -> value = boolean(this -> value | argument).valueOf(); return *this; }
                        friend unsigned long& operator |=(unsigned long& argumentA, boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator |=(unsigned long& argumentA, boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator |=(unsigned long& argumentA, const boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator |=(unsigned long& argumentA, const boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator |=(const unsigned long long argument) { this -> value = boolean(this -> value | argument).valueOf(); return *this; }
                        friend unsigned long long& operator |=(unsigned long long& argumentA, boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator |=(unsigned long long& argumentA, boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator |=(unsigned long long& argumentA, const boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator |=(unsigned long long& argumentA, const boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator |=(const unsigned short argument) { this -> value = boolean(this -> value | argument).valueOf(); return *this; }
                        friend unsigned short& operator |=(unsigned short& argumentA, boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator |=(unsigned short& argumentA, boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator |=(unsigned short& argumentA, const boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator |=(unsigned short& argumentA, const boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator |=(void* argument) { this -> value = boolean(this -> value | (NULL == argument ? 0 : (int) argument)).valueOf(); return *this; }
                        inline const boolean& operator |=(const void* argument) { this -> value = boolean(this -> value | (NULL == argument ? 0 : (int) argument)).valueOf(); return *this; }

                        inline const boolean& operator |=(const wchar_t argument) { this -> value = boolean(this -> value | argument).valueOf(); return *this; }
                        friend wchar_t& operator |=(wchar_t& argumentA, boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator |=(wchar_t& argumentA, boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator |=(wchar_t& argumentA, const boolean& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator |=(wchar_t& argumentA, const boolean&& argumentB) { argumentA |= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator |=(boolean& argument) { this -> value = boolean(this -> value | argument.valueOf()).valueOf(); return *this; }
                        inline const boolean& operator |=(boolean&& argument) { this -> value = boolean(this -> value | argument.valueOf()).valueOf(); return *this; }
                        inline const boolean& operator |=(const boolean& argument) { this -> value = boolean(this -> value | argument.valueOf()).valueOf(); return *this; }
                        inline const boolean& operator |=(const boolean&& argument) { this -> value = boolean(this -> value | argument.valueOf()).valueOf(); return *this; }

                        // [*=]
                        inline const boolean& operator *=(const char argument) { this -> value = this -> value && argument; return *this; }
                        friend char& operator *=(char& argumentA, boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend char& operator *=(char& argumentA, boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend char& operator *=(char& argumentA, const boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend char& operator *=(char& argumentA, const boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator *=(const char16_t argument) { this -> value = this -> value && argument; return *this; }
                        friend char16_t& operator *=(char16_t& argumentA, boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator *=(char16_t& argumentA, boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator *=(char16_t& argumentA, const boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend char16_t& operator *=(char16_t& argumentA, const boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator *=(const char32_t argument) { this -> value = this -> value && argument; return *this; }
                        friend char32_t& operator *=(char32_t& argumentA, boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator *=(char32_t& argumentA, boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator *=(char32_t& argumentA, const boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend char32_t& operator *=(char32_t& argumentA, const boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator *=(const double argument) { this -> value = this -> value && argument; return *this; }
                        friend double& operator *=(double& argumentA, boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend double& operator *=(double& argumentA, boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend double& operator *=(double& argumentA, const boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend double& operator *=(double& argumentA, const boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator *=(const float argument) { this -> value = this -> value && argument; return *this; }
                        friend float& operator *=(float& argumentA, boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend float& operator *=(float& argumentA, boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend float& operator *=(float& argumentA, const boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend float& operator *=(float& argumentA, const boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator *=(const int argument) { this -> value = this -> value && argument; return *this; }
                        friend int& operator *=(int& argumentA, boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend int& operator *=(int& argumentA, boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend int& operator *=(int& argumentA, const boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend int& operator *=(int& argumentA, const boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator *=(const long argument) { this -> value = this -> value && argument; return *this; }
                        friend long& operator *=(long& argumentA, boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend long& operator *=(long& argumentA, boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend long& operator *=(long& argumentA, const boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend long& operator *=(long& argumentA, const boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator *=(const long double argument) { this -> value = this -> value && argument; return *this; }
                        friend long double& operator *=(long double& argumentA, boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend long double& operator *=(long double& argumentA, boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend long double& operator *=(long double& argumentA, const boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend long double& operator *=(long double& argumentA, const boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator *=(const long long argument) { this -> value = this -> value && argument; return *this; }
                        friend long long& operator *=(long long& argumentA, boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend long long& operator *=(long long& argumentA, boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend long long& operator *=(long long& argumentA, const boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend long long& operator *=(long long& argumentA, const boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator *=(const short argument) { this -> value = this -> value && argument; return *this; }
                        friend short& operator *=(short& argumentA, boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend short& operator *=(short& argumentA, boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend short& operator *=(short& argumentA, const boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend short& operator *=(short& argumentA, const boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator *=(const signed char argument) { this -> value = this -> value && argument; return *this; }
                        friend signed char& operator *=(signed char& argumentA, boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator *=(signed char& argumentA, boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator *=(signed char& argumentA, const boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend signed char& operator *=(signed char& argumentA, const boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator *=(const unsigned char argument) { this -> value = this -> value && argument; return *this; }
                        friend unsigned char& operator *=(unsigned char& argumentA, boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator *=(unsigned char& argumentA, boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator *=(unsigned char& argumentA, const boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend unsigned char& operator *=(unsigned char& argumentA, const boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator *=(const unsigned int argument) { this -> value = this -> value && argument; return *this; }
                        friend unsigned int& operator *=(unsigned int& argumentA, boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator *=(unsigned int& argumentA, boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator *=(unsigned int& argumentA, const boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend unsigned int& operator *=(unsigned int& argumentA, const boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator *=(const unsigned long argument) { this -> value = this -> value && argument; return *this; }
                        friend unsigned long& operator *=(unsigned long& argumentA, boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator *=(unsigned long& argumentA, boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator *=(unsigned long& argumentA, const boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend unsigned long& operator *=(unsigned long& argumentA, const boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator *=(const unsigned long long argument) { this -> value = this -> value && argument; return *this; }
                        friend unsigned long long& operator *=(unsigned long long& argumentA, boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator *=(unsigned long long& argumentA, boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator *=(unsigned long long& argumentA, const boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend unsigned long long& operator *=(unsigned long long& argumentA, const boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator *=(const unsigned short argument) { this -> value = this -> value && argument; return *this; }
                        friend unsigned short& operator *=(unsigned short& argumentA, boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator *=(unsigned short& argumentA, boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator *=(unsigned short& argumentA, const boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend unsigned short& operator *=(unsigned short& argumentA, const boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }

                        inline const boolean& operator *=(void* argument) { this -> value = this -> value && (NULL != argument); return *this; }
                        inline const boolean& operator *=(const void* argument) { this -> value = this -> value && (NULL != argument); return *this; }

                        inline const boolean& operator *=(const wchar_t argument) { this -> value = this -> value && argument; return *this; }
                        friend wchar_t& operator *=(wchar_t& argumentA, boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator *=(wchar_t& argumentA, boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator *=(wchar_t& argumentA, const boolean& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }
                        friend wchar_t& operator *=(wchar_t& argumentA, const boolean&& argumentB) { argumentA *= argumentB.valueOf(); return argumentA; }

                        const boolean& operator *=(boolean& argument) { argument.valueOf() && (this -> value = 1); return *this; }
                        const boolean& operator *=(boolean&& argument) { argument.valueOf() && (this -> value = 1); return *this; }
                        const boolean& operator *=(const boolean& argument) { argument.valueOf() && (this -> value = 1); return *this; }
                        const boolean& operator *=(const boolean&& argument) { argument.valueOf() && (this -> value = 1); return *this; }

                        // [...]
                        operator unsigned char() const { return this -> valueOf(); }

                        operator boolean() const { return this -> valueOf(); }

                    // Function
                        // To String
                        const char* toString() const { return this -> value ? "true" : "false"; }

                        // Value Of
                        inline const unsigned char valueOf() const { return this -> value; }
            } boolean;

            /* Array --- UPDATE REQUIRED (Lapys) -> Experiment with multi-level void pointers. If all that doesn't work, smash the pointer to the biggest data type and experiment there. */
            typedef struct array {
                // [Private]
                private:
                    unsigned length = 0u; void *value;
            } array;
    }

    /* Namespace > Lapys Development Kit --- NOTE (Lapys) -> Define general-purpose abstractions. */
    namespace LapysDevelopmentKit {
    }
}
