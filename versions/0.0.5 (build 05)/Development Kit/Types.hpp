/* ... */
#if !defined(LAPYS) && !defined(LAPYS_TYPES)
    /* Definition > ... */
    #define LAPYS_TYPES

    /* Import */
    #include "Functions.hpp" // Functions
    #include "Mathematics.hpp" // Mathematics

    /* Namespace > Types */
    inline namespace Types {
        /* Shorthand */
        namespace LDKT = Types;

        /* Definition > ... */
        class Array; class BigNumber; class Boolean; class Function; class Number; class Object; class String; class Symbol;

        /* Import > ... */
        #include "../Types/Boolean.hpp"

        #include "../Types/BigNumber.hpp"
        #include "../Types/Number.hpp"

        #include "../Types/Array.hpp"
        #include "../Types/String.hpp"
        #include "../Types/Symbol.hpp"

        #include "../Types/Function.hpp"
        #include "../Types/Object.hpp"
    }
#endif
