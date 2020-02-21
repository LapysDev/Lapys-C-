/* ... */
#if !defined(LAPYS) && !defined(LAPYS_MATHEMATICS)
      // ...
      #define LAPYS_MATHEMATICS

      /* Namespace > Mathematics */
      namespace Mathematics {
            /* Shorthand */
            namespace LDKM = Mathematics;

            /* Constant > ... */
            const long double E = 2.718281828459045;
            const long double PI = 3.141592653589793;

            /* Function */
                  // Absolute
                  inline const double abs(const double number) { return number < 0.0 ? -number : number; }
                  inline const float abs(const float number) { return number < 0.0f ? -number : number; }
                  inline const int abs(const int number) { return number < 0 ? -number : number; }
                  inline const long abs(const long number) { return number < 0L ? -number : number; }
                  inline const long double abs(const long double number) { return number < 0.00 ? -number : number; }
                  inline const long long abs(const long long number) { return number < 0LL ? -number : number; }
                  inline const short abs(const short number) { return number < 0 ? -number : number; }
                  inline const unsigned int abs(const unsigned int number) { return number; }
                  inline const unsigned long abs(const unsigned long number) { return number; }
                  inline const unsigned long long abs(const unsigned long long number) { return number; }
                  inline const unsigned short abs(const unsigned short number) { return number; }

                  // Arc Cosine --- UPDATE (Lapys)
                  inline void acos(...);

                  // Arc Cosine Hypotenuse --- UPDATE (Lapys)
                  inline void acosh(...);

                  // Arc Sine --- UPDATE (Lapys)
                  inline void asin(...);

                  // Arc Sine Hypotenuse --- UPDATE (Lapys)
                  inline void asinh(...);

                  // Arc Tangent --- UPDATE (Lapys)
                  inline void atan(...);

                  // Arc Tangent Hypotenuse --- UPDATE (Lapys)
                  inline void atanh(...);

                  // Ceiling --- UPDATE (Lapys)
                  inline void ceil(...);

                  // Cube Root --- UPDATE (Lapys)
                  inline void cbrt(...);

                  // Cosine --- UPDATE (Lapys)
                  inline void cos(...);

                  // Cosine Hypotenuse --- UPDATE (Lapys)
                  inline void cosh(...);

                  // Floor --- UPDATE (Lapys)
                  inline void floor(...);

                  // [Natural] Logarithm --- UPDATE (Lapys)
                  inline void log(...);

                  // Maximum --- UPDATE (Lapys)
                  inline void max(...);

                  // Minimum --- UPDATE (Lapys)
                  inline void min(...);

                  // Modulus
                  const double mod(const double, const double); const float mod(const float, const float); const long double mod(const long double, const long double);

                  const double mod(const double numberA, const double numberB) { if (numberB) { double divisor = LDKM::abs(numberB), modulus = LDKM::abs(numberA); while (modulus >= divisor) { modulus -= divisor; } return numberA < 0.0 ? -modulus : modulus; } else return std::nan(""); } const double mod(const double numberA, const float numberB) { return LDKM::mod(numberA, double(numberB)); } const double mod(const double numberA, const int numberB) { return LDKM::mod(numberA, double(numberB)); } const double mod(const double numberA, const long numberB) { return LDKM::mod(numberA, double(numberB)); } const long double mod(const double numberA, const long double numberB) { return LDKM::mod((long double) numberA, numberB); } const long double mod(const double numberA, const long long numberB) { return LDKM::mod((long double) numberA, (long double) numberB); } const double mod(const double numberA, const short numberB) { return LDKM::mod(numberA, double(numberB)); } const double mod(const double numberA, const unsigned int numberB) { return LDKM::mod(numberA, double(numberB)); } const double mod(const double numberA, const unsigned long numberB) { return LDKM::mod(numberA, double(numberB)); } const long double mod(const double numberA, const unsigned long long numberB) { return LDKM::mod((long double) numberA, (long double) numberB); } const double mod(const double numberA, const unsigned short numberB) { return LDKM::mod(numberA, double(numberB)); }
                  const double mod(const float numberA, const double numberB) { return LDKM::mod(double(numberA), numberB); } const float mod(const float numberA, const float numberB) { if (numberB) { float divisor = LDKM::abs(numberB), modulus = LDKM::abs(numberA); while (modulus >= divisor) { modulus -= divisor; } return numberA < 0.0f ? -modulus : modulus; } else return std::nanf(""); } const float mod(const float numberA, const int numberB) { return LDKM::mod(numberA, float(numberB)); } const double mod(const float numberA, const long numberB) { return LDKM::mod(double(numberA), double(numberB)); } const long double mod(const float numberA, const long double numberB) { return LDKM::mod((long double) numberA, numberB); } const long double mod(const float numberA, const long long numberB) { return LDKM::mod((long double) numberA, (long double) numberB); } const float mod(const float numberA, const short numberB) { return LDKM::mod(numberA, float(numberB)); } const float mod(const float numberA, const unsigned int numberB) { return LDKM::mod(numberA, float(numberB)); } const double mod(const float numberA, const unsigned long numberB) { return LDKM::mod(double(numberA), double(numberB)); } const long double mod(const float numberA, const unsigned long long numberB) { return LDKM::mod((long double) numberA, (long double) numberB); } const float mod(const float numberA, const unsigned short numberB) { return LDKM::mod(numberA, float(numberB)); }
                  const double mod(const int numberA, const double numberB) { return LDKM::mod(double(numberA), numberB); } const float mod(const int numberA, const float numberB) { return LDKM::mod(float(numberA), numberB); } inline const int mod(const int numberA, const int numberB) { return numberA % numberB; } inline const long mod(const int numberA, const long numberB) { return long(numberA) % numberB; } const long double mod(const int numberA, const long double numberB) { return LDKM::mod((long double) numberA, numberB); } inline const long long mod(const int numberA, const long long numberB) { return ((long long) numberA) % numberB; } inline const int mod(const int numberA, const short numberB) { return numberA % int(numberB); } inline const int mod(const int numberA, const unsigned int numberB) { return numberA % numberB; } inline const long mod(const int numberA, const unsigned long numberB) { return long(numberA) % numberB; } inline const long long mod(const int numberA, const unsigned long long numberB) { return ((long long) numberA) % numberB; } inline const int mod(const int numberA, const unsigned short numberB) { return numberA % int(numberB); }
                  const double mod(const long numberA, const double numberB) { return LDKM::mod(double(numberA), numberB); } const double mod(const long numberA, const float numberB) { return LDKM::mod(double(numberA), double(numberB)); } inline const long mod(const long numberA, const int numberB) { return numberA % long(numberB); } inline const long mod(const long numberA, const long numberB) { return numberA % numberB; } const long double mod(const long numberA, const long double numberB) { return LDKM::mod((long double) numberA, numberB); } inline const long long mod(const long numberA, const long long numberB) { return ((long long) numberA) % numberB; } inline const long mod(const long numberA, const short numberB) { return numberA % long(numberB); } inline const long mod(const long numberA, const unsigned int numberB) { return numberA % (unsigned long) numberB; } inline const long mod(const long numberA, const unsigned long numberB) { return numberA % numberB; } inline const long long mod(const long numberA, const unsigned long long numberB) { return ((long long) numberA) % numberB; } inline const long mod(const long numberA, const unsigned short numberB) { return numberA % (unsigned long) numberB; }
                  const long double mod(const long double numberA, const double numberB) { return LDKM::mod(numberA, (long double) numberB); } const long double mod(const long double numberA, const float numberB) { return LDKM::mod(numberA, (long double) numberB); } const long double mod(const long double numberA, const int numberB) { return LDKM::mod(numberA, (long double) numberB); } const long double mod(const long double numberA, const long numberB) { return LDKM::mod(numberA, (long double) numberB); } const long double mod(const long double numberA, const long double numberB) { if (numberB) { long double divisor = LDKM::abs(numberB), modulus = LDKM::abs(numberA); while (modulus >= divisor) { modulus -= divisor; } return numberA < 0.00 ? -modulus : modulus; } else return std::nanl(""); } const long double mod(const long double numberA, const long long numberB) { return LDKM::mod(numberA, (long double) numberB); } const long double mod(const long double numberA, const short numberB) { return LDKM::mod(numberA, (long double) numberB); } const long double mod(const long double numberA, const unsigned int numberB) { return LDKM::mod(numberA, (long double) numberB); } const long double mod(const long double numberA, const unsigned long numberB) { return LDKM::mod(numberA, (long double) numberB); } const long double mod(const long double numberA, const unsigned long long numberB) { return LDKM::mod(numberA, (long double) numberB); } const long double mod(const long double numberA, const unsigned short numberB) { return LDKM::mod(numberA, (long double) numberB); }
                  const long double mod(const long long numberA, const double numberB) { return LDKM::mod((long double) numberA, (long double) numberB); } const long double mod(const long long numberA, const float numberB) { return LDKM::mod((long double) numberA, (long double) numberB); } inline const long long mod(const long long numberA, const int numberB) { return numberA % (long long) numberB; } inline const long long mod(const long long numberA, const long numberB) { return numberA % (long long) numberB; } const long double mod(const long long numberA, const long double numberB) { return LDKM::mod((long double) numberA, numberB); } inline const long long mod(const long long numberA, const long long numberB) { return numberA % numberB; } inline const long long mod(const long long numberA, const short numberB) { return numberA % (long long) numberB; } inline const long long mod(const long long numberA, const unsigned int numberB) { return numberA % (unsigned long long) numberB; } inline const long long mod(const long long numberA, const unsigned long numberB) { return numberA % (unsigned long long) numberB; } inline const long long mod(const long long numberA, const unsigned long long numberB) { return numberA % numberB; } inline const long long mod(const long long numberA, const unsigned short numberB) { return numberA % (unsigned long long) numberB; }
                  const double mod(const short numberA, const double numberB) { return LDKM::mod((double) numberA, numberB); } const float mod(const short numberA, const float numberB) { return LDKM::mod((float) numberA, numberB); } inline const int mod(const short numberA, const int numberB) { return int(numberA) % numberB; } inline const long mod(const short numberA, const long numberB) { return long(numberA) % numberB; } const long double mod(const short numberA, const long double numberB) { return LDKM::mod((long double) numberA, numberB); } inline const long long mod(const short numberA, const long long numberB) { return ((long long) numberA) % numberB; } inline const short mod(const short numberA, const short numberB) { return numberA % numberB; } inline const int mod(const short numberA, const unsigned int numberB) { return int(numberA) % numberB; } inline const int mod(const short numberA, const unsigned long numberB) { return long(numberA) % numberB; } inline const long long mod(const short numberA, const unsigned long long numberB) { return ((long long) numberA) % numberB; } inline const short mod(const short numberA, const unsigned short numberB) { return numberA % numberB; }
                  const double mod(const unsigned int numberA, const double numberB) { return LDKM::mod(double(numberA), numberB); } const float mod(const unsigned int numberA, const float numberB) { return LDKM::mod(float(numberA), numberB); } inline const unsigned int mod(const unsigned int numberA, const int numberB) { return numberA % numberB; } inline const unsigned long mod(const unsigned int numberA, const long numberB) { return ((unsigned long) numberA) % numberB; } const long double mod(const unsigned int numberA, const long double numberB) { return LDKM::mod((long double) numberA, numberB); } inline const unsigned long long mod(const unsigned int numberA, const long long numberB) { return ((unsigned long long) numberA) % numberB; } inline const unsigned int mod(const unsigned int numberA, const short numberB) { return numberA % (unsigned int) numberB; } inline const unsigned int mod(const unsigned int numberA, const unsigned int numberB) { return numberA % numberB; } inline const unsigned long mod(const unsigned int numberA, const unsigned long numberB) { return ((unsigned long) numberA) % numberB; } inline const unsigned long long mod(const unsigned int numberA, const unsigned long long numberB) { return ((unsigned long long) numberA) % numberB; } inline const unsigned int mod(const unsigned int numberA, const unsigned short numberB) { return numberA % (unsigned int) numberB; }
                  const double mod(const unsigned long numberA, const double numberB) { return LDKM::mod(double(numberA), numberB); } const float mod(const unsigned long numberA, const float numberB) { return LDKM::mod(float(numberA), numberB); } inline const unsigned long mod(const unsigned long numberA, const int numberB) { return numberA % long(numberB); } inline const unsigned long mod(const unsigned long numberA, const long numberB) { return numberA % numberB; } const long double mod(const unsigned long numberA, const long double numberB) { return LDKM::mod((long double) numberA, numberB); } inline const unsigned long long mod(const unsigned long numberA, const long long numberB) { return ((unsigned long long) numberA) % numberB; } inline const unsigned long mod(const unsigned long numberA, const short numberB) { return numberA % long(numberB); } inline const unsigned long mod(const unsigned long numberA, const unsigned int numberB) { return numberA % (unsigned long) numberB; } inline const unsigned long mod(const unsigned long numberA, const unsigned long numberB) { return numberA % numberB; } inline const unsigned long long mod(const unsigned long numberA, const unsigned long long numberB) { return ((unsigned long long) numberA) % numberB; } inline const unsigned long mod(const unsigned long numberA, const unsigned short numberB) { return numberA % (unsigned short) numberB; }
                  const long double mod(const unsigned long long numberA, const double numberB) { return LDKM::mod((long double) numberA, (long double) numberB); } const long double mod(const unsigned long long numberA, const float numberB) { return LDKM::mod((long double) numberA, (long double) numberB); } inline const unsigned long long mod(const unsigned long long numberA, const int numberB) { return numberA % (long long) numberB; } inline const unsigned long long mod(const unsigned long long numberA, const long numberB) { return numberA % (long long) numberB; } const long double mod(const unsigned long long numberA, const long double numberB) { return LDKM::mod((long double) numberA, numberB); } inline const unsigned long long mod(const unsigned long long numberA, const long long numberB) { return numberA % numberB; } inline const unsigned long long mod(const unsigned long long numberA, const short numberB) { return numberA % (long long) numberB; } inline const unsigned long long mod(const unsigned long long numberA, const unsigned int numberB) { return numberA % (unsigned long long) numberB; } inline const unsigned long long mod(const unsigned long long numberA, const unsigned long numberB) { return numberA % (unsigned long long) numberB; } inline const unsigned long long mod(const unsigned long long numberA, const unsigned long long numberB) { return numberA % numberB; } inline const unsigned long long mod(const unsigned long long numberA, const unsigned short numberB) { return numberA % (unsigned long long) numberB; }
                  const double mod(const unsigned short numberA, const double numberB) { return LDKM::mod(double(numberA), numberB); } const float mod(const unsigned short numberA, const float numberB) { return LDKM::mod(float(numberA), numberB); } inline const unsigned int mod(const unsigned short numberA, const int numberB) { return ((unsigned int) numberA) % numberB; } inline const unsigned long mod(const unsigned short numberA, const long numberB) { return ((unsigned long) numberA) % numberB; } const long double mod(const unsigned short numberA, const long double numberB) { return LDKM::mod((long double) numberA, numberB); } inline const unsigned long long mod(const unsigned short numberA, const long long numberB) { return ((unsigned long long) numberA) % numberB; } inline const unsigned short mod(const unsigned short numberA, const short numberB) { return numberA % numberB; } inline const unsigned int mod(const unsigned short numberA, const unsigned int numberB) { return ((unsigned int) numberA) % numberB; } inline const unsigned long mod(const unsigned short numberA, const unsigned long numberB) { return ((unsigned long) numberA) % numberB; } inline const unsigned long long mod(const unsigned short numberA, const unsigned long long numberB) { return ((unsigned long long) numberA) % numberB; } inline const unsigned short mod(const unsigned short numberA, const unsigned short numberB) { return numberA % numberB; }

                  // [Exponent] Power --- UPDATE (Lapys)
                  inline void pow(...);

                  // Random --- UPDATE (Lapys)
                  inline void random(...);

                  // Round --- UPDATE (Lapys)
                  inline void round(...);

                  // Sign --- UPDATE (Lapys)
                  inline void sign(...);

                  // Sine --- UPDATE (Lapys)
                  inline void sin(...);

                  // Sine Hypotenuse --- UPDATE (Lapys)
                  inline void sinh(...);

                  // Square Root --- UPDATE (Lapys)
                  inline void sqrt(...);

                  // Tangent --- UPDATE (Lapys)
                  inline void tan(...);

                  // Tangent Hypotenuse --- UPDATE (Lapys)
                  inline void tanh(...);

                  // Truncate --- UPDATE (Lapys)
                  inline void trunc(...);

            // ...
            #ifdef LAPYS_TYPES
            /* Function */
                  // Absolute
                  inline const Number abs(const Number number) { return number < 0 ? -number : number; }

                  // Arc Cosine --- UPDATE (Lapys)
                  // Arc Cosine Hypotenuse --- UPDATE (Lapys)
                  // Arc Sine --- UPDATE (Lapys)
                  // Arc Sine Hypotenuse --- UPDATE (Lapys)
                  // Arc Tangent --- UPDATE (Lapys)
                  // Arc Tangent Hypotenuse --- UPDATE (Lapys)
                  // Ceiling --- UPDATE (Lapys)
                  // Cube Root --- UPDATE (Lapys)
                  // Cosine --- UPDATE (Lapys)
                  // Cosine Hypotenuse --- UPDATE (Lapys)
                  // Floor --- UPDATE (Lapys)
                  // [Natural] Logarithm --- UPDATE (Lapys)
                  // Maximum --- UPDATE (Lapys)
                  // Minimum --- UPDATE (Lapys)
                  // Modulus --- UPDATE (Lapys)
                  const Number mod(const Number, const Number);

                  // [Exponent] Power --- UPDATE (Lapys)
                  // Random --- UPDATE (Lapys)
                  // Round --- UPDATE (Lapys)
                  // Sign --- UPDATE (Lapys)
                  // Sine --- UPDATE (Lapys)
                  // Sine Hypotenuse --- UPDATE (Lapys)
                  // Square Root --- UPDATE (Lapys)
                  // Tangent --- UPDATE (Lapys)
                  // Tangent Hypotenuse --- UPDATE (Lapys)
                  // Truncate --- UPDATE (Lapys)
            #endif
      }
            /* Utilization */
            using Mathematics::abs;
            using Mathematics::cbrt;
            using Mathematics::mod;
            using Mathematics::trunc;
#endif
