<!-- Array API -->
<h1 style=text-transform:none> Arrays </h1>
General-purpose arrays supporting an initial fixed-size memory buffer

```cpp
// Always dynamically allocated
Array<int>;
Array<int, 0zu>;
Array<int, HEAP>;
```
```cpp
// Fixed-size buffer of `sizeof(…) == 3zu * sizeof int`
//   the default `Allocator …` used does not allow
//   for further allocation once the buffer is at capacity
Array<int, 3zu, …>;

// — but `Allocator<HEAP>` and any non-default `Allocator`
//   may ignore said behavior
Array<int, 3zu, Allocator<HEAP> >;
```

<!-- Compile-time Operations -->
<h1 style=text-transform:none> Compile-time operations <small> <em> (with <code>template</code>s) </em> </small> </h1>
Traits that allow for compile-time arithmetic operations (intended for floating-point numbers)

```cpp
// Needs better design
// --> floating_point<true, 1zu, 0u>
operate::add<
  floating_point<false, 1zu, 0zu>,
  floating_point<true,  2zu, 0zu>
>::value;
```

<!-- Function API -->
<h1 style=text-transform:none> Function API </h1>
Runtime interpreter which generates platform-specific machine code

```cpp
Function function = {}; // --> Function{ARM_64}

// Needs better design
function.addInstruction(…);

Function::addInstruction(INTEL_x86_64, function, …);
Function::addInstruction(function, …);
```

<!-- Mathematics API -->
<h1 style=text-transform:none> Mathematics API </h1>
General-purpose mathematics library with common numeric constants & utility functions that work with generic types

<!-- Memory API -->
<h1 style=text-transform:none> Memory API </h1>
General-purpose memory allocator which supports special-purpose allocation strategies

* Allocator for platform-specific executable memory
* Defaults dynamic memory management on the program heap
* Provides the allocator interface for pre-reserved memory

```cpp
Allocator<> allocator = {}; // --> Allocator<byte, HEAP>
allocator.allocate(…);
```
```cpp
// Allocates from the program heap
Memory::allocateHeap(…);
Memory::allocateHeap(…, EXECUTABLE | ZEROED);

// Allocates from an instantiated `static` buffer
Memory::allocateStatic(…);

// Likely wouldn't be developed
Memory::allocateStack(…);
```

<!-- Shorthand Lambdas -->
<h1 style=text-transform:none> Shorthand lambdas <small> <em> — even shorter function shorthands </em> </small> </h1>

```cpp
$0;      // function(a) { return a }
$0 + $1; // function(a, b) { return a + b }
$0 + …; // function(a, …) { return a + … }
```

<!-- String API -->
<h1 style=text-transform:none> Strings </h1>
General-purpose strings supporting ASCII and Unicode-aware text (for cyrillic, CJK, and emoji support)

— see [CopperSpice strings](https://github.com/copperspice/cs_string)

```cpp
// Inherits from `Array` since both can be SSO optimized
// ->> quantifies by code units, not by character type
// --> String<…, UNICODE>
String<char16_t>; // Standard 16-bit codepoint string
String<char32_t>; // Standard 32-bit codepoint string
String<char8_t>;  // Standard 8-bit codepoint string
String<char>;     // Standard character strings (supports ASCII and Latin-1 (ISO-8859-1))
String<wchar_t>;  // Standard wide character strings
```
