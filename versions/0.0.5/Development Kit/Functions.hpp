/* ... */
#if !defined(LAPYS) && !defined(LAPYS_FUNCTIONS)
    // ...
    #define LAPYS_FUNCTIONS

    namespace Functions {
        /* Shorthand */
        namespace LDKF = Functions;

        /* Function */
            // Number ...
            inline const long numberToInteger(const double number) { return number; }
            inline const int numberToInteger(const float number) { return number; }
            inline const int numberToInteger(const int number) { return number; }
            inline const long numberToInteger(const long number) { return number; }
            inline const long long numberToInteger(const long double number) { return number; }
            inline const long long numberToInteger(const long long number) { return number; }
            inline const short numberToInteger(const short number) { return number; }
            inline const unsigned int numberToInteger(const unsigned int number) { return number; }
            inline const unsigned long numberToInteger(const unsigned long number) { return number; }
            inline const unsigned long long numberToInteger(const unsigned long long number) { return number; }
            inline const unsigned short numberToInteger(const unsigned short number) { return number; }

            char* numberToString(int number, char* string = NULL) { std::free(string); if (number) { unsigned length = 0u; for (int iterator = number; iterator; iterator /= 10) { length += 1u; } string = (char*) std::malloc((length + 2u) * sizeof(char)); *(string + length) = *(string + length + 1) = '\0'; for (int iterator = length + (number < 0); iterator; iterator -= 1) { if (number) { switch (number % 10) { case 0: *(string + iterator - 1) = '0'; break; case -1: case 1: *(string + iterator - 1) = '1'; break; case -2: case 2: *(string + iterator - 1) = '2'; break; case -3: case 3: *(string + iterator - 1) = '3'; break; case -4: case 4: *(string + iterator - 1) = '4'; break; case -5: case 5: *(string + iterator - 1) = '5'; break; case -6: case 6: *(string + iterator - 1) = '6'; break; case -7: case 7: *(string + iterator - 1) = '7'; break; case -8: case 8: *(string + iterator - 1) = '8'; break; case -9: case 9: *(string + iterator - 1) = '9'; } number /= 10; } else *string = '-'; } } else { string = (char*) std::malloc(2u * sizeof(char)); *string = '0'; *(string + 1) = '\0'; } return string; }
            char* numberToString(long number, char* string = NULL) { std::free(string); if (number) { unsigned length = 0u; for (long iterator = number; iterator; iterator /= 10L) { length += 1u; } string = (char*) std::malloc((length + 2u) * sizeof(char)); *(string + length) = *(string + length + 1) = '\0'; for (int iterator = length + (number < 0L); iterator; iterator -= 1) { if (number) { switch (number % 10L) { case 0L: *(string + iterator - 1) = '0'; break; case -1L: case 1L: *(string + iterator - 1) = '1'; break; case -2L: case 2L: *(string + iterator - 1) = '2'; break; case -3L: case 3L: *(string + iterator - 1) = '3'; break; case -4L: case 4L: *(string + iterator - 1) = '4'; break; case -5L: case 5L: *(string + iterator - 1) = '5'; break; case -6L: case 6L: *(string + iterator - 1) = '6'; break; case -7L: case 7L: *(string + iterator - 1) = '7'; break; case -8L: case 8L: *(string + iterator - 1) = '8'; break; case -9L: case 9L: *(string + iterator - 1) = '9'; } number /= 10L; } else *string = '-'; } } else { string = (char*) std::malloc(2u * sizeof(char)); *string = '0'; *(string + 1) = '\0'; } return string; }
            char* numberToString(long long number, char* string = NULL) { std::free(string); if (number) { unsigned length = 0u; for (long long iterator = number; iterator; iterator /= 10LL) { length += 1u; } string = (char*) std::malloc((length + 2u) * sizeof(char)); *(string + length) = *(string + length + 1) = '\0'; for (int iterator = length + (number < 0LL); iterator; iterator -= 1) { if (number) { switch (number % 10LL) { case 0LL: *(string + iterator - 1) = '0'; break; case -1LL: case 1LL: *(string + iterator - 1) = '1'; break; case -2LL: case 2LL: *(string + iterator - 1) = '2'; break; case -3LL: case 3LL: *(string + iterator - 1) = '3'; break; case -4LL: case 4LL: *(string + iterator - 1) = '4'; break; case -5LL: case 5LL: *(string + iterator - 1) = '5'; break; case -6LL: case 6LL: *(string + iterator - 1) = '6'; break; case -7LL: case 7LL: *(string + iterator - 1) = '7'; break; case -8LL: case 8LL: *(string + iterator - 1) = '8'; break; case -9LL: case 9LL: *(string + iterator - 1) = '9'; } number /= 10LL; } else *string = '-'; } } else { string = (char*) std::malloc(2u * sizeof(char)); *string = '0'; *(string + 1) = '\0'; } return string; }
            char* numberToString(short number, char* string = NULL) { std::free(string); if (number) { unsigned length = 0u; for (short iterator = number; iterator; iterator /= 10) { length += 1u; } string = (char*) std::malloc((length + 2u) * sizeof(char)); *(string + length) = *(string + length + 1) = '\0'; for (int iterator = length + (number < 0); iterator; iterator -= 1) { if (number) { switch (number % 10) { case 0: *(string + iterator - 1) = '0'; break; case -1: case 1: *(string + iterator - 1) = '1'; break; case -2: case 2: *(string + iterator - 1) = '2'; break; case -3: case 3: *(string + iterator - 1) = '3'; break; case -4: case 4: *(string + iterator - 1) = '4'; break; case -5: case 5: *(string + iterator - 1) = '5'; break; case -6: case 6: *(string + iterator - 1) = '6'; break; case -7: case 7: *(string + iterator - 1) = '7'; break; case -8: case 8: *(string + iterator - 1) = '8'; break; case -9: case 9: *(string + iterator - 1) = '9'; } number /= 10; } else *string = '-'; } } else { string = (char*) std::malloc(2u * sizeof(char)); *string = '0'; *(string + 1) = '\0'; } return string; }

            char* numberToString(double number, char* string = NULL) {
                long characteristics = long(number);
                signed length = 0;
                double mantissa = number - characteristics;

                string = LDKF::numberToString(characteristics, string);
                for (char *iterator = string; *iterator; iterator += 1) length += 1;

                if (mantissa) {
                    (mantissa < 0.0) && (mantissa = -mantissa);
                    *(string + length) = '.';

                    while (mantissa && (mantissa - long(mantissa))) {
                        length += 1; mantissa *= 10.0;

                        std::cout << "[PARSING]: " << mantissa << std::endl;
                        std::cout << "[PARSING]: " << mantissa - long(mantissa) << std::endl;

                        switch (long(mantissa) % 10L) {
                            case 0L: *(string + length) = '0'; break;
                            case 1L: *(string + length) = '1'; break;
                            case 2L: *(string + length) = '2'; break;
                            case 3L: *(string + length) = '3'; break;
                            case 4L: *(string + length) = '4'; break;
                            case 5L: *(string + length) = '5'; break;
                            case 6L: *(string + length) = '6'; break;
                            case 7L: *(string + length) = '7'; break;
                            case 8L: *(string + length) = '8'; break;
                            case 9L: *(string + length) = '9'; break;
                            default: mantissa = 0.0;
                        }
                    }
                }
                *(string + length + 1) = '\0';
                return string;
            }

            char* numberToString(unsigned int number, char* string = NULL) { return LDKF::numberToString(int(number < 0 ? -number : number), string); }
            char* numberToString(unsigned long number, char* string = NULL) { return LDKF::numberToString(long(number < 0L ? -number : number), string); }
            char* numberToString(unsigned long long number, char* string = NULL) { return LDKF::numberToString((long long) (number < 0LL ? -number : number), string); }
            char* numberToString(unsigned short number, char* string = NULL) { return LDKF::numberToString(short(number < 0 ? -number : number), string); }

        // ...
        #ifdef LAPYS_TYPES
        /* Function */
            // Number > ...
            inline const Number numberToInteger(const Number number);
            inline const String numberToString(const Number number);
        #endif
    }
#endif
