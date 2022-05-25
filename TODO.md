<!-- Arrays -->
<h1 style=text-transform:none> <a href=#arrays target=_self> Arrays </a> </h1>
General-purpose arrays supporting an initial fixed-size memory buffer <br/>
with compile-time support <br/> <br/>
<table>
<tbody>
<tr>
  <th> Explanation </th>
  <th> Examples </th>
</tr>
<tr style=vertical-align:top>
  <td>

  ```cpp
  // Always dynamically allocated
  Array<int>
  Array<int, 0zu>
  Array<int, HEAP>
  ```
  ```cpp
  // Fixed-size buffer of `sizeof(…) == 3zu * sizeof int`
  //   the default `Allocator …` does not allow
  //   for further allocation once the buffer is at capacity
  Array<int, 3zu, …>

  // — but `Allocator<HEAP>` and any non-default `Allocator`
  //   may ignore said behavior
  Array<int, 3zu, Allocator<HEAP> >
  ```
  </td>
  <td>

  ```cpp
  Array<int, 3zu> fixed {1, 2}; // int[3] {1, 2, 0}
  Array<int>      dynamic;      // int*

  fixed.add(…);         // ❌ can’t add to a fixed-sized array
  dynamic.add(1, 2, 3); // ✅ int (*)[3] {1, 2, 3}
  ```
  ```cpp
  Array<int, 3zu, Allocator<HEAP> > heaped;  // int (*)[3] {0, 0, 0}

  heaped.add(1, 2, 3); // ✅ int (*)[6] {0, 0, 0, 1, 2, 3}
  ```
  </td>
</tr>
</tbody>
</table>

<!-- Compile-time Operations -->
<h1 style=text-transform:none> <a href=#constops target=_self> Compile-time operations <small> <em> (with <code>template</code>s) </em> </small> </a> </h1>
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
<h1 style=text-transform:none> <a href=#functions target=_self> Function API </a> </h1>
Runtime interpreter which generates platform-specific machine code

```cpp
Function function = {}; // --> Function{ARM_64}

// Needs better design
function.addInstruction(…);

Function::addInstruction(INTEL_x86_64, function, …);
Function::addInstruction(function, …);
```

<!-- Mathematics API -->
<h1 style=text-transform:none> <a href=#mathematics target=_self> Mathematics API </a> </h1>
General-purpose mathematics library with common numeric constants & utility functions that work with generic types

<!-- Memory API -->
<h1 style=text-transform:none> <a href=#memory target=_self> Memory API </a> </h1>
General-purpose memory allocator which supports special-purpose allocation strategies with compile-time support for block-based allocations

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

<!-- Properties -->
<h1 style=text-transform:none> <a href=#properties target=_self> Properties </a> </h1>
Accessor/ mutator objects that allow for more expressive behavior when modified/ referenced <br/>
with compile-time support. <br/> <br/>
Akin to how constructors/ destructors allow for more expressive resource management with object lifetimes

```cpp
class Array {
  public:
  property<unsigned, get, set> length;
};
```
```cpp
Array array = {};

array.length;       // get(unsigned&, …)
array.length = 42u; // set(unsigned&, …, 42u)
```

<!-- Shorthand Lambdas -->
<h1 style=text-transform:none> <a href=#lambdas target=_self> Shorthand lambdas <small> <em> — even shorter function shorthands </em> </small> </a> </h1>

```cpp
$0;      // function(a) { return a }
$0 + $1; // function(a, b) { return a + b }
$0 + …; // function(a, …) { return a + … }
```

<!-- String API -->
<h1 style=text-transform:none> <a href=#strings target=_self> Strings </a> </h1>
General-purpose strings supporting ASCII and Unicode-aware text (for cyrillic, CJK, and emoji support) <br/>
with compile-time support

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
