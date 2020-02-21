/* Namespace > Development Kit */
namespace DevelopmentKit {
    /* Namespace > ... */
    namespace Constants {}
    namespace Functions {}
    namespace Mathematics {}
    inline namespace Types {}
}

namespace DevelopmentKit {
    /* Namespace > ... */
    inline namespace Types {
        /* Class > ... */
        class Array; class Boolean; class Error; class Function; class Number; class Object; class String; class Symbol;
        union var;
    }

    namespace Constants {
        /* Import */
        #include "ldk/constants.hpp"
    }

    namespace Functions {
        /* Utilization */
        using namespace Constants;

        /* Import */
        #include "ldk/functions.hpp"
    }

    namespace Mathematics {
        /* Utilization */
        using namespace Constants;
        using namespace Functions;

        /* Import */
        #include "ldk/mathematics/constants.hpp"
        #include "ldk/mathematics/functions.hpp"
    }

    inline namespace Types {
        /* Utilization > ... */
        using namespace Constants;
        using namespace Functions;
        using namespace Mathematics;

        /* Import */
        #include "ldk/types/object.hpp" // [Object] --- NOTE (Lapys) -> Minimal, private base interface for all custom types.
        #include "ldk/types/primitive.hpp" // [Primitive] --- NOTE (Lapys) -> Container for plain/ POD/ primitive data types.

        #include "ldk/types/primitive/error.hpp" // [Custom Data]
        #include "ldk/types/primitive/boolean.hpp"
        #include "ldk/types/primitive/big-number.hpp"
        #include "ldk/types/primitive/number.hpp"
        #include "ldk/types/primitive/array.hpp"
        #include "ldk/types/primitive/string.hpp"
        #include "ldk/types/primitive/symbol.hpp"
        #include "ldk/types/primitive/function.hpp"
        #include "ldk/types/primitive/object.hpp"

        #include "ldk/types/variable/var.hpp" // [Variable] --- NOTE (Lapys) -> Container, public base interface for all custom types.

        #include "ldk/types/interface/buffer.hpp" // [Interface]
        #include "ldk/types/interface/buffer/screen-buffer.hpp"
        #include "ldk/types/interface/console.hpp"
    }
}
