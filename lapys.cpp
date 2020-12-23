/* Import */
#include <iostream>
#include <type_traits>
#include "lapys.hpp" // Lapys

// #define MUTABLE true
// class Object final {
//     public:
//         class String { friend Object;
//             private: char const *value;
//             public:
//                 constexpr inline String(char const value[]) noexcept : value{value} {}
//                 constexpr inline String(String const& string) noexcept : value{string.value} {}
//                 constexpr inline String(String&& string) noexcept : value{string.value} {}

//                 constexpr inline String& operator =(String const& string) const noexcept { return this -> operator =(string.value); }
//                 constexpr inline String& operator =(String&& string) const noexcept { return this -> operator =(string.value); }

//                 template <typename type, typename base = typename std::enable_if<false == std::is_same<String, typename std::decay<type>::type>::value, String&>::type>
//                 constexpr inline base& operator =(type&& value) const noexcept { return static_cast<void>(const_cast<String*>(this) -> value = value), const_cast<String&>(*this); }

//                 #if MUTABLE
//                   inline char const*& operator +(void) noexcept { return ++(this -> value); }
//                 #else
//                   constexpr inline char const* const& operator +(void) const noexcept { return this -> value; }
//                 #endif

//                 constexpr inline operator char const*&(void) const noexcept { return const_cast<char const*&>(this -> value); }
//         };

//         // String name;
//         // Lapys::shadow<String> name;
//         // Lapys::property<Object, String> name;
//         Lapys::property_accessor<Object, String> name;

//         constexpr inline Object(String const& name) noexcept : name{name} {}

//         #if MUTABLE
//             inline auto getName(void) noexcept -> decltype(static_cast<String*>(NULL) -> operator +()) { return this -> name.operator +(); }
//         #else
//             constexpr inline auto getName(void) const noexcept -> decltype(static_cast<String const*>(NULL) -> operator +()) { return this -> name.operator +(); }
//         #endif
// };

int main(void) /* ... Lapys::Main(ArgumentList const); */ {
    class Number { public:
        int operator +(void) { return 0x45; }
        operator int(void) const { return 1337; }
    };
    std::cout << "[...]: " << +Lapys::shadow<Number>() << std::endl;
    // Object object = {"@Lapys"};

    // std::cout << "[...]: " << '"' << object.name << '"' << std::endl;
    // std::cout << "[...]: " << '"' << object.getName() << '"' << std::endl;
    // std::cout << "[...]: " << '"' << +(object.name) << '"' << std::endl;
    // std::cout << "[...]: " << '"' << const_cast<Lapys::property_accessor<Object, Object::String> const&>(object.name).operator +() << '"' << std::endl;

    std::printf("%18s", "[PROGRAM EXECUTED]");
}
