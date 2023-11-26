/* Import */
#define LAPYS_HOSTED             true
#define LAPYS_PREPROCESSOR_GUARD false

#include <cstdio>
#include "lapys.hpp"

/* ... */
using namespace Lapys;

/* Main */
template <typename cumulation, typename base, std::size_t>
struct cumulate {
  // typedef cumulation (*bruh)[sizeof(*instanceof<base>())];
};

template <typename, std::size_t>
struct map {
  typedef void type;
};

struct object { int member; object(object const&, ...) {} };
struct subobject : object {};

struct add {
  static int value(int, int);
};

// ...
int main(int, char*[]) /* noexcept(true) */ {
  // access_pointer              //   x  .* y
  // add                         //   x   + y
  // address                     //  &x
  // assign                      //   x   = y
  // assign_add                  //   x  += y
  // assign_bitwise_and          //   x  &= y
  // assign_bitwise_or           //   x  |= y
  // assign_bitwise_shift_left   //   x <<= y
  // assign_bitwise_shift_right  //   x >>= y
  // assign_bitwise_xor          //   x  ^= y
  // assign_divide               //   x  /= y
  // assign_modulo               //   x  %= y
  // assign_multiply             //   x  *= y
  // assign_subtract             //   x  -= y
  // bitwise_and                 //   x   & y
  // bitwise_or                  //   x   | y
  // bitwise_shift_left          //   x  << y
  // bitwise_shift_right         //   x  >> y
  // bitwise_xor                 //   x   ^ y
  // boolean_and                 //   x  && y
  // boolean_or                  //   x  || y
  // call                        //   x             (...)
  // call_static                 //   x::operator ()(...)
  // cast                        //  (x) y
  // cast_const                  // const_cast      <x>(y)
  // cast_dynamic                // dynamic_cast    <x>(y)
  // cast_reinterpret            // reinterpret_cast<x>(y)
  // cast_static                 // static_cast     <x>(y)
  // comma                       //   x   , y
  // compare                     //   x <=> y
  // complement                  //  ~x
  // construct                   //   x(...)
  // delete_array                // delete[] x
  // delete_object               // delete   x
  // dereference                 //  *x
  // dereferenced_access         //   x  -> y
  // dereferenced_access_pointer //   x ->* y
  // divide                      //   x   / y
  // equals                      //   x  == y
  // greater                     //   x   > y
  // greater_equals              //   x  >= y
  // initialize                  //   x{...}
  // lesser                      //   x   < y
  // lesser_equals               //   x  <= y
  // minus                       //   x   - y
  // modulo                      //   x   % y
  // multiply                    //   x   * y
  // negate                      //  !x
  // new_array                   // new     x[y]{...}
  // new_array_placement         // new (x) y[z]{...}
  // new_constructed             // new     x   (...)
  // new_constructed_placement   // new (x) y   (...)
  // new_initialized             // new     x   {...}
  // new_initialized_placement   // new (x) y   {...}
  // plus                        //  +x
  // post_decrement              //   x--
  // post_increment              //   x++
  // pre_decrement               // --x
  // pre_increment               // ++x
  // scope                       //   x  :: y
  // subscript                   //   x             [...]
  // subscript_static            //   x::operator [](...)
  // subtract                    //   x   - y
  // trilean_conditional         //   x   ? y : z
  // unequals                    //   x  != y
  // opinfo::nonoverloaded::operate<opinfo::add, int, int>::is_same   <int>::value;
  // opinfo::nonoverloaded::operate<opinfo::add, int, int>::is_similar<int>::value(2 + 2);
  // opinfo::nonoverloaded::operate<opinfo::add, int, int>::type;
  // opinfo::nonoverloaded::operate<opinfo::add, int, int>::value;

  // instanceof<collection<int (*)[1], int (*)[2], int (*)[3]>::build<cumulate>::type>() * 2;
  // std::printf("%1.13s", "Hello, World!");
  return 0x00; // --> EXIT_SUCCESS
}

// void Lapys::Main(CommandLineArguments const& arguments) {
//   static_cast<void>(arguments);
// }
