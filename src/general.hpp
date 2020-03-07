/* Pragma */
#pragma once

/* Import */
#include "libraries/c/includes.h" // C Standard Library
#include "libraries/c++/includes.hpp" // C++ Standard Library

#include "environments/linux/includes.h" // Linux
#include "environments/windows/includes.h" // Windows

#include "polyfills.cpp" // ... --- NOTE (Lapys) -> Shiv required differences between alternative implementations and versions of C++.

/* Class > ... */
struct boolean;
struct character;
struct integral;
struct null_pointer;
struct number;
struct pointer;
struct rational;
struct raw_pointer;
struct string;
struct var;
struct wide;

class Array;
class BigNumber;
class Boolean;
class ClampedArray;
class ClampedNumber;
class Function;
class Number;
class Object;
class RegularExpression;
class String;
class Symbol;

/* Definition > ... */
var __(...);
var array__(...);
var number__(...);
var pointer__(...);
var string__(...);

/* Import > ... --- NOTE (Lapys) -> Define all data interfaces. */
#include "general.cpp"

/* Definition > ... */
typedef ClampedArray Arguments;

/* Constant > ... */
const Console console;
const null_pointer null;

/* Main */
void Main(const Arguments);

#if IS_LINUX_ENVIRONMENT
    int main(int argumentCount, char* argumentVector[]) {
        /* ... */
        Main(Arguments<argumentCount>{argumentVector});

        // Return
        return EXIT_SUCCESS;
    }

#elif IS_WINDOWS_ENVIRONMENT // CHECKPOINT (Lapys) -> Get the directory of the executing script and de-allocate each argument string.
    int WinMain(HINSTANCE /*instanceHandle*/, HINSTANCE /*previousInstanceHandle*/, LPSTR programInitiationCommandLineArguments, int /*windowAppearance*/) {
        // Initialization > Argument ...
        unsigned char argumentCount = 0u;
        unsigned char argumentSize = 0u;
        LPSTR *argumentVector = NULL;

        // Loop > Logic --- NOTE (Lapys) -> Parse each argument (delimited by line terminators & whitespace).
        for (LPSTR index = programInitiationCommandLineArguments, iterator = index; *iterator; ++iterator)
        switch (*iterator) { case ' ': case '\f': case '\n': case '\r': case '\t': case '\v': {
            // Logic > Update > Argument (Size, Vector)
            if (argumentSize) { argumentSize <<= 1u; argumentVector = pointer__reallocate_heap_memory(argumentSize * sizeof(LPSTR)); }
            else { argumentSize = 1u; argumentVector = pointer__allocate_heap_memory(sizeof(LPSTR)); }

            // Update > (Argument (Count, Vector), ...)
            *(argumentCount + argumentVector) = pointer__allocate_heap_memory((iterator - index) * sizeof(STR));
            pointer__copy_memory(*(argumentCount + argumentVector), index, (iterator - index) * sizeof(STR));

            ++argumentCount;
            index = iterator; // NOTE (Lapys) -> Update the iteration index.
        } break; }

        // Constant > Arguments
        const Arguments arguments = Arguments<argumentCount>(argumentVector);

        // Deletion --- NOTE (Lapys) -> The contents of the argument vector are copied onto the `Arguments` (.a.k.a.: `ClampedArray`) object.
        pointer__free_memory(argumentVector);

        /* ... */
        Main(arguments);

        // Return
        return EXIT_SUCCESS;
    }

#else // CHECKPOINT (Lapys) -> Get the directory of the executing script.
    int main(void) {
        /* ... */
        Main(Arguments<1u>{NULL});

        // Return
        return EXIT_SUCCESS;
    }
#endif
