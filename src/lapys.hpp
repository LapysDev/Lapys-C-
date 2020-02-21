/* Import > Lapys Development Kit */
#include <iostream>
#include "ldk.hpp"

/* Namespace > Lapys */
namespace Lapys {
    /* Class > ... */
        // [Primitive]
        class Array;
        class BigNumber;
        class Boolean;
        class ClampedArray;
        class ClampedNumber;
        class FixedNumber;
        class Function;
        class MemoryPool;
        class Number;
        class Object;
        class RegularExpression;
        class String;
        class Symbol;

        // [Stream]
        class FileStream;
        class InputStream;
        class OutputStream;
        class Stream;

        // [Shorthand]
        struct var;

    /* Utilization > ... */
    namespace LDK = LapysDevelopmentKit;
    namespace LDKE = LapysDevelopmentKit::Environment;
    namespace LDKF = LapysDevelopmentKit::Functions;
    namespace LDKT = LapysDevelopmentKit::Types;

    using namespace LapysDevelopmentKit;
    using namespace LapysDevelopmentKit::Functions;
    using namespace LapysDevelopmentKit::Types;
}

namespace Lapys {
    /* Import > ... */
    #include "lapys/clamped-array.hpp"
    #include "lapys/stream.hpp"
    #  include "lapys/stream/output-stream.hpp"
}

namespace Lapys {
    /* Definition > ... */
    typedef ClampedArray Arguments;

    /* Function > ... */
    template <typename... types> void print(types... arguments) { console.print(arguments...); }
    template <typename... types> void println(types... arguments) { console.print(arguments...); console.linefeed(); }

    /* Main */
    void Main(const Arguments arguments);
}

/* (Shorthand, Utilization) > ... */
typedef Lapys::Array Array;
typedef Lapys::Arguments Arguments;
typedef Lapys::BigNumber BigNumber;
typedef Lapys::Boolean Boolean;
typedef Lapys::ClampedArray ClampedArray;
typedef Lapys::ClampedNumber ClampedNumber;
typedef Lapys::FixedNumber FixedNumber;
typedef Lapys::Function Function;
typedef Lapys::Number Number;
typedef Lapys::Object Object;
typedef Lapys::RegularExpression RegularExpression;
typedef Lapys::String String;
typedef Lapys::Symbol Symbol;

using Lapys::Main;
using Lapys::OutputStream::console;
using Lapys::print;
using Lapys::println;

/* Main */
int main(void) { Lapys::Main(Arguments{}); return EXIT_SUCCESS; }
