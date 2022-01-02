/** ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment.
    @author: LapysDev Team
    @description: Lapys C++ is a general-purpose, semantic and universal C++ library
    @version: 0.0.7
    @url: https://www.github.com/LapysDev/LapysC__

    --- NOTE ---
        #Lapys:
            - Details:
                -- Supported Environment Standards:
                    --- C++ 98 - current...
                    --- ISO/IEC 14882:1998) - current...

            - Notes:
                -- ...
*/
#ifndef LAPYS
    /* Import > ... --- NOTE (Lapys) -> Define the C and/ or C++ standard. */
    #include "api/includes.hpp"
    #include "api/polyfills.hpp"

    /* Namespace > Lapys */
    namespace Lapys {
        /* Import > ... --- NOTE (Lapys) -> Include all platform-specific codes & polyfills to allow cross-platform compatibility (& functionality). */
        #include "platform/android.hpp" // Android
        #include "platform/ios.hpp" // iPhone
        #include "platform/linux.hpp" // Linux
        #include "platform/macintosh.hpp" // Macintosh
        #include "platform/windows.hpp" // Windows

        /* Namespace > Lapys Development Kit --- NOTE (Lapys) -> Include the Lapys Development Kit which abstracts away complex code. */
        namespace LapysDevelopmentKit {
            /* Definition */
            namespace Constants {}
            namespace Functions {}
            namespace Mathematics {}
            namespace Types { struct boolean; struct object; struct primitive; struct size; }
        }

        /* Shorthand */
        namespace LDKF = LapysDevelopmentKit::Functions;
        namespace LDKM = LapysDevelopmentKit::Mathematics;
        namespace LDKT = LapysDevelopmentKit::Types;

        /* Namespace > ... */
        namespace LapysDevelopmentKit {
            /* Namespace */
                /* Types */
                inline namespace Types {
                    /* Import > ... */
                    #include "ldk/types/boolean.hpp" // Boolean
                }
        }

        /* Import > ... */
        #include "api/abstract/phases.hpp" // --- NOTE (Lapys) -> General data and information.

        /* Namespace > ... */
        namespace LapysDevelopmentKit {
            /* Namespace */
                /* Functions */
                inline namespace Functions {
                    /* Utilization */
                    using namespace Types;

                    /* Import > ... */
                    #include "ldk/functions/pointer.hpp" // Pointer
                    #include "ldk/functions/number.hpp" // Number
                    #include "ldk/functions/string.hpp" // String
                }

                /* Constants */
                inline namespace Constants {
                    /* Utilization */
                    using namespace Functions;
                    using namespace Types;

                    /* Import > ... */
                    #include "ldk/constants/infinity.hpp" // Infinity
                    #include "ldk/constants/nan.hpp" // Not-A-Number
                    #include "ldk/constants/null.hpp" // Not-A-Number
                }

                /* Mathematics */
                inline namespace Mathematics {
                    /* Utilization */
                    using namespace Constants;
                    using namespace Functions;
                    using namespace Types;

                    /* Import > ... */
                    #include "ldk/mathematics/constants.hpp"
                    #include "ldk/mathematics/functions.hpp"
                }

                /* Types */
                inline namespace Types {
                    /* Utilization */
                    using namespace Constants;
                    using namespace Functions;
                    using namespace Mathematics;

                    /* Import > ... */
                    #include "ldk/types/size.hpp" // Size
                    #include "ldk/types/object.hpp" // Object
                    #include "ldk/types/primitive.hpp" // Primitive

                    #include "ldk/types/boolean.cpp" // ...
                    #include "ldk/types/object.cpp"
                    #include "ldk/types/primitive.cpp"
                    #include "ldk/types/size.cpp"
                }
        }
    }

    /* Import > ... --- NOTE (Lapys) -> Global (or public) data from the library. */
    #include "api/constants.hpp"
    #include "api/functions.hpp"

    /* Namespace > Lapys */
    namespace Lapys {
        /* Utilization */
        using namespace LapysDevelopmentKit::Functions;
        using namespace LapysDevelopmentKit::Mathematics;
        using namespace LapysDevelopmentKit::Types;

        /* Import > ... */
        #include "api/information.hpp" // Information --- NOTE (Lapys) -> Metadata on the library.

        #include "api/types.hpp" // Type(s) --- NOTE (Lapys) -> Custom base data types.

        #include "api/type/array.hpp"
        #include "api/type/big-number.hpp"
        #include "api/type/context.hpp"
        #include "api/type/error.hpp"
        #include "api/type/function.hpp"
        #include "api/type/number.hpp"
        #include "api/type/object.hpp"
        #include "api/type/string.hpp"
        #include "api/type/symbol.hpp"
        #include "api/type/var.hpp"

        #include "api/type/array.cpp"
        #include "api/type/big-number.cpp"
        #include "api/type/context.cpp"
        #include "api/type/error.cpp"
        #include "api/type/function.cpp"
        #include "api/type/number.cpp"
        #include "api/type/object.cpp"
        #include "api/type/string.cpp"
        #include "api/type/symbol.cpp"
        #include "api/type/var.cpp"

        #include "api/interface/window.hpp" // Interface --- NOTE (Lapys) -> User-interface with abstracted data.

        #include "api/abstract/phases.cpp" // Abstract -- NOTE (Lapys) -> General data and information.
        #include "api/abstract/main.hpp"
    }

    /* Definition > ... */
    #define LAPYS
#endif
