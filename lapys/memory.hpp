// /* Namespace */
// namespace Lapys {
//   /* Namespace */
//   namespace Memory {
//     /* ... */
//     template <class> struct assess_allocator;
//     template <class> struct is_allocator;

//     /* Class > ... */
//     class Allocation;
//     template <typename, std::size_t = static_cast<std::size_t>(Traits::HEAP)> class Allocator;

//     /* Function > ... */
//     template <typename type> noignore inline type* align(type* const, std::size_t const, std::size_t const) noexcept;
//     template <typename typeA, typename typeB> noignore inline typeA* align(typeA*, std::size_t const, std::size_t const, typeB* const) noexcept;

//     // ...
//     noignore void* allocate(std::size_t const) noexcept;
//     noignore void* allocate(std::size_t const, std::size_t const) noexcept;
//     noignore void* allocate(control_parameter const, std::size_t const) noexcept;
//     noignore void* allocate(control_parameter, std::size_t, std::size_t const) noexcept;

//     // ...
//     #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
//       noignore inline HANDLE getHeap() noexcept {
//         static HANDLE heap = NULL;

//         // ...
//         if (NULL == heap) heap = ::GetProcessHeap();
//         if (NULL == heap) heap = ::HeapCreate(0x0u, 0u, 0u);

//         return heap;
//       }
//     #endif

//     // ...
//     template <typename type>
//     noignore constfunc(true) inline void inspect(type* const) noexcept;

//     // ...
//     template <typename type> noignore inline type* reallocate(type* const, std::size_t const) noexcept;
//     template <typename type> noignore type* reallocate(control_parameter const, type* const, std::size_t const) noexcept;

//     // ...
//     template <typename type> bool release(type* const) noexcept;
//     template <typename type> bool release(type* const, std::size_t const) noexcept;
//   }

//   namespace Memory {
//     template <class type>                          struct assess_allocator                             final { typedef type base; };
//     template <typename type, std::size_t capacity> struct assess_allocator<Allocator<type, capacity> > final { typedef type base; };

//     template <class base>
//     struct is_allocator final {
//       static bool const value = false == is_same<base, typename assess_allocator<base>::base>::value;
//     };

//     /* Class > ... */
//     class Allocation final {
//       template <typename, std::size_t> class Allocator;

//       friend void* allocate(control_parameter, std::size_t, std::size_t const) noexcept;
//       template <typename type> friend type* reallocate(control_parameter const, type* const, std::size_t const) noexcept;
//       template <typename type> friend bool release(type* const) noexcept;
//       template <typename type> friend bool release(type* const, std::size_t const) noexcept;

//       private:
//         #if CPP_VERSION < 2011uL
//           enum kind
//         #else
//           enum kind : typename uint_minimum_t::type
//         #endif
//         { C_STANDARD = 0x1u, CPP_STANDARD, MICROSOFT_WINDOWS__HEAP, MICROSOFT_WINDOWS__VIRTUAL, UNIX__MAP };
//         typedef typename uint_least_t<(sizeof(Allocation::kind) > sizeof(std::size_t) ? (sizeof(Allocation::kind) < sizeof(typename uint_maximum_t::type) ? sizeof(Allocation::kind) : sizeof(typename uint_maximum_t::type)) : sizeof(std::size_t))>::type metadata_t;

//         // ...
//         static typename uint_minimum_t::type const KIND_WIDTH = widthof<std::size_t, maximum<std::size_t, C_STANDARD, CPP_STANDARD, MICROSOFT_WINDOWS__HEAP, MICROSOFT_WINDOWS__VIRTUAL, UNIX__MAP>::value>::value;
//         metadata_t const metadata;

//         // ...
//         constfunc(true) inline Allocation(std::size_t const size) noexcept : metadata init(size) {}
//         constfunc(true) inline Allocation(Allocation::kind const kind, std::size_t const size) noexcept : metadata init(static_cast<std::size_t>(kind) | (size << Allocation::KIND_WIDTH)) {}

//         noignore constfunc(true) inline metadata_t getFullSize() const lref noexcept { return this -> metadata; }
//         noignore constfunc(true) inline Allocation::kind getKind() const lref noexcept { return static_cast<Allocation::kind>(this -> metadata & ~(~0u << Allocation::KIND_WIDTH)); }
//         noignore constfunc(true) inline typename uint_least_width_t<widthof<metadata_t, (maxof<metadata_t>::value >> Allocation::KIND_WIDTH)>::value>::type getSize() const lref noexcept { return this -> metadata >> Allocation::KIND_WIDTH; }
//     };

//     // ...
//     template <>
//     class Allocator<null, 0u> final {
//       private:
//         template <class allocator>
//         struct can_allocate final {
//           private:
//             template <dummy_parameter, class = alias<null> >
//             struct valueof final {
//               friend struct can_allocate<allocator>;
//               private: static bool const value = false;
//             };

//             template <dummy_parameter dummy>
//             struct valueof<dummy, alias<typeof((allocator::allocate(instanceof<std::size_t>()), null()))> > final {
//               friend struct can_allocate<allocator>;
//               private: static bool const value = true;
//             };

//           public:
//             static bool const value = valueof<DUMMY>::value;
//         };

//         // ...
//         template <class allocator, typename type>
//         struct can_deallocate final {
//           private:
//             template <dummy_parameter, class = alias<null> >
//             struct valueof final {
//               friend struct can_deallocate<allocator, type>;
//               private: static bool const value = false;
//             };

//             template <dummy_parameter dummy>
//             struct valueof<dummy, alias<typeof((allocator::deallocate(instanceof<type*>(), instanceof<std::size_t>()), null()))> > final {
//               friend struct can_deallocate<allocator, type>;
//               private: static bool const value = true;
//             };

//           public:
//             static bool const value = valueof<DUMMY>::value;
//         };

//         // ...
//         template <class allocator, typename type>
//         struct can_reallocate final {
//           private:
//             template <dummy_parameter, class = alias<null> >
//             struct valueof final {
//               friend struct can_reallocate<allocator, type>;
//               private: static bool const value = false;
//             };

//             template <dummy_parameter dummy>
//             struct valueof<dummy, alias<typeof((allocator::reallocate(instanceof<type*>(), instanceof<std::size_t>()), null()))> > final {
//               friend struct can_reallocate<allocator, type>;
//               private: static bool const value = true;
//             };

//           public:
//             static bool const value = valueof<DUMMY>::value;
//         };

//         // ...
//         template <class, typename, bool sized>
//         struct can_release;

//         template <class allocator, typename type>
//         struct can_release<allocator, type, false> final {
//           private:
//             template <dummy_parameter, class = alias<null> >
//             struct valueof final {
//               friend struct can_release<allocator, type, false>;
//               private: static bool const value = false;
//             };

//             template <dummy_parameter dummy>
//             struct valueof<dummy, alias<typeof((allocator::release(instanceof<type*>()), null()))> > final {
//               friend struct can_release<allocator, type, false>;
//               private: static bool const value = true;
//             };

//           public:
//             static bool const value = valueof<DUMMY>::value;
//         };

//         template <class allocator, typename type>
//         struct can_release<allocator, type, true> final {
//           private:
//             template <dummy_parameter, class = alias<null> >
//             struct valueof final {
//               friend struct can_release<allocator, type, true>;
//               private: static bool const value = false;
//             };

//             template <dummy_parameter dummy>
//             struct valueof<dummy, alias<typeof((allocator::release(instanceof<type*>(), instanceof<std::size_t>()), null()))> > final {
//               friend struct can_release<allocator, type, true>;
//               private: static bool const value = true;
//             };

//           public:
//             static bool const value = valueof<DUMMY>::value;
//         };

//       public:
//         constfunc(true) inline Allocator() noexcept discard;

//         // ...
//         template <class allocator> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_allocate<allocator>::value && false == is_pointer<typeof(allocator::allocate(instanceof<std::size_t>()))>::value, void*>::type allocate(std::size_t const size) const rref noexcept { return bit_cast<void*>(allocator::allocate(static_cast<std::size_t>(size))); }
//         template <class allocator> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_allocate<allocator>::value && false != is_pointer<typeof(allocator::allocate(instanceof<std::size_t>()))>::value, typeof(allocator::allocate(instanceof<std::size_t>()))>::type allocate(std::size_t const size) const rref noexcept { return allocator::allocate(static_cast<std::size_t>(size)); }
//         template <class allocator> constfunc(true) inline typename conditional<false != is_allocator<allocator>::value, typename assess_allocator<allocator>::base*>::type allocate(std::size_t const size) const rref noexcept { return allocator::allocate(size); }
//         template <class allocator> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value, typeof(Allocator<null>::allocate<allocator>(instanceof<std::size_t>()))>::type allocate(control_parameter const, std::size_t const size) const rref noexcept { return Allocator<null>::allocate<allocator>(size); }
//         template <class allocator> constfunc(true) inline typename conditional<false != is_allocator<allocator>::value, typename assess_allocator<allocator>::base*>::type allocate(control_parameter const control, std::size_t const size) const rref noexcept { return allocator::allocate(control, size); }

//         template <class allocator, typename type> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_reallocate<allocator, type>::value && false == is_pointer<typeof(allocator::reallocate(instanceof<type*>(), instanceof<std::size_t>()))>::value, type*>::type reallocate(type* const address, std::size_t const resize) const rref noexcept { return static_cast<void>(allocator::reallocate(static_cast<type*>(address), static_cast<std::size_t>(resize))), address; }
//         template <class allocator, typename type> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_reallocate<allocator, type>::value && false != is_pointer<typeof(allocator::reallocate(instanceof<type*>(), instanceof<std::size_t>()))>::value, typeof(allocator::reallocate(instanceof<type*>(), instanceof<std::size_t>()))>::type reallocate(type* const address, std::size_t const resize) const rref noexcept { return allocator::reallocate(static_cast<type*>(address), static_cast<std::size_t>(resize)); }
//         template <class allocator, typename type> constfunc(true) inline typename conditional<false != is_allocator<allocator>::value, typename assess_allocator<allocator>::base*>::type allocate(type* const address, std::size_t const resize) const rref noexcept { return allocator::reallocate(address, resize); }
//         template <class allocator, typename type> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value, typeof(Allocator<null>::reallocate<allocator>(instanceof<type*>(), instanceof<std::size_t>()))>::type allocate(control_parameter const, type* const address, std::size_t const resize) const rref noexcept { return Allocator<null>::reallocate<allocator>(address, resize); }
//         template <class allocator, typename type> constfunc(true) inline typename conditional<false != is_allocator<allocator>::value, typename assess_allocator<allocator>::base*>::type allocate(control_parameter const control, type* const address, std::size_t const resize) const rref noexcept { return allocator::reallocate(control, address, resize); }

//         template <class allocator, typename type> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_release<allocator, type, false>::value && false == is_void<typeof(allocator::release(instanceof<type*>()))>::value, bool>::type release(type* const address) const rref noexcept { return static_cast<bool>(allocator::release(static_cast<type*>(address))); }
//         template <class allocator, typename type> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_release<allocator, type, false>::value && false != is_void<typeof(allocator::release(instanceof<type*>()))>::value, bool>::type release(type* const address) const rref noexcept { return static_cast<void>(allocator::release(static_cast<type*>(address))), true; }
//         template <class allocator, typename type> constfunc(true) inline typename conditional<false != is_allocator<allocator>::value, bool>::type release(type* const address) const rref noexcept { return allocator::release(address); }
//         template <class allocator, typename type> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_release<allocator, type, true>::value && false == is_void<typeof(allocator::release(instanceof<type*>(), instanceof<std::size_t>()))>::value, bool>::type release(type* const address, std::size_t const size) const rref noexcept { return static_cast<bool>(allocator::release(static_cast<type*>(address)), static_cast<std::size_t>(size)); }
//         template <class allocator, typename type> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_release<allocator, type, true>::value && false != is_void<typeof(allocator::release(instanceof<type*>(), instanceof<std::size_t>()))>::value, bool>::type release(type* const address, std::size_t const size) const rref noexcept { return static_cast<void>(allocator::release(static_cast<type*>(address)), static_cast<std::size_t>(size)), true; }
//         template <class allocator, typename type> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_deallocate<allocator, type>::value && false == can_release<allocator, type, true>::value && false == is_void<typeof(allocator::deallocate(instanceof<type*>(), instanceof<std::size_t>()))>::value, bool>::type release(type* const address, std::size_t const size) const rref noexcept { return static_cast<bool>(allocator::deallocate(static_cast<type*>(address)), static_cast<std::size_t>(size)); }
//         template <class allocator, typename type> constfunc(true) inline typename conditional<false == is_allocator<allocator>::value && can_deallocate<allocator, type>::value && false == can_release<allocator, type, true>::value && false != is_void<typeof(allocator::deallocate(instanceof<type*>(), instanceof<std::size_t>()))>::value, bool>::type release(type* const address, std::size_t const size) const rref noexcept { return static_cast<void>(allocator::deallocate(static_cast<type*>(address)), static_cast<std::size_t>(size)), true; }
//         template <class allocator, typename type> constfunc(true) inline typename conditional<false != is_allocator<allocator>::value, bool>::type release(type* const address, std::size_t const size) const rref noexcept { return allocator::release(address, size); }
//     };

//     template <std::size_t capacity>
//     class Allocator<null, capacity> final {
//       public:
//         constfunc(true) inline Allocator() noexcept discard;

//         // ...
//         template <class allocator> constfunc(true) inline typeof((Allocator<null, 0u>::allocate<allocator>(instanceof<std::size_t>()))) allocate(std::size_t const size) const rref noexcept { return Allocator<null, 0u>::allocate<allocator>(size); }
//         template <class allocator> constfunc(true) inline typeof((Allocator<null, 0u>::allocate<allocator>(instanceof<control_parameter>(), instanceof<std::size_t>()))) allocate(control_parameter const control, std::size_t const size) const rref noexcept { return Allocator<null, 0u>::allocate<allocator>(control, size); }

//         template <class allocator, typename type> constfunc(true) inline typeof((Allocator<null, 0u>::reallocate<allocator>(instanceof<type*>(), instanceof<std::size_t>()))) reallocate(type* const address, std::size_t const resize) const rref noexcept { return Allocator<null, 0u>::reallocate<allocator>(address, resize); }
//         template <class allocator, typename type> constfunc(true) inline typeof((Allocator<null, 0u>::reallocate<allocator>(instanceof<control_parameter>(), instanceof<type*>(), instanceof<std::size_t>()))) reallocate(control_parameter const control, type* const address, std::size_t const resize) const rref noexcept { return Allocator<null, 0u>::reallocate<allocator>(control, address, resize); }

//         template <class allocator, typename type> constfunc(true) inline bool release(type* const address) const rref noexcept { return Allocator<null, 0u>::release<allocator>(address); }
//         template <class allocator, typename type> constfunc(true) inline bool release(type* const address, std::size_t const size) const rref noexcept { return Allocator<null, 0u>::release<allocator>(address, size); }
//     };

//     template <typename base, std::size_t capacity>
//     class Allocator final {
//       private:
//         mutable base *heap;
//         alignmentas(sizeof(typename uint_least_t<(sizeof(Allocation) < sizeof(typename uint_maximum_t::type) ? sizeof(Allocation) : sizeof(typename uint_maximum_t::type))>::type)) mutable byte stack[(0u != capacity) * maximum<std::size_t, capacity * sizeof(typename conditional<is_void<base>::value, byte, base>::type), sizeof(Allocation) + sizeof(typename conditional<is_void<base>::value, byte, base>::type)>::value];

//       public:
//         #if CPP_VERSION < 2011uL
//           inline Allocator() noexcept : heap(NULL) { new (this -> stack) Allocation(0u); }
//         #else
//           constexpr inline Allocator() noexcept : Allocator<base, capacity>::Allocator(bytesof(Allocation{0u}), typename index_sequence<0u, sizeof(Allocation)>::type{}) {}

//           private: template <std::size_t length, std::size_t... indexes> constexpr inline Allocator(byte const (&bytes)[length], index_collection<indexes...> const) noexcept : heap{NULL}, stack{bytes[indexes]...} {}
//           public:
//         #endif

//         // ...
//         constfunc(false) inline typename conditional<is_void<base>::value, Allocation, base*>::type allocate(std::size_t const count) const volatile noexcept { return Allocator::allocate(static_cast<control_parameter>(static_cast<unsigned>(Traits::DUMMY)), count); }
//         constfunc(true) typename conditional<is_void<base>::value, Allocation, base*>::type allocate(control_parameter const, std::size_t const) const volatile noexcept;

//         constfunc(true) inline typename conditional<is_void<base>::value, Allocation, base*>::type reallocate(base* const address, std::size_t const recount) const volatile noexcept { return Allocator::reallocate(static_cast<control_parameter>(static_cast<unsigned>(Traits::DUMMY)), address, recount); }
//         constfunc(true) typename conditional<is_void<base>::value, Allocation, base*>::type reallocate(control_parameter const, base* const, std::size_t const) const volatile noexcept;

//         constfunc(true) bool release(base* const) const volatile noexcept;
//         constfunc(true) inline bool release(base* const, std::size_t const) const volatile noexcept;
//     };

//     template <typename base>
//     class Allocator<base, Traits::HEAP> final {
//       public:
//         noignore inline typename conditional<is_void<base>::value, Allocation, base*>::type allocate(std::size_t const count) const volatile noexcept { return Allocator::allocate(static_cast<control_parameter>(static_cast<unsigned>(Traits::DUMMY)), count); }
//         noignore typename conditional<is_void<base>::value, Allocation, base*>::type allocate(control_parameter const control, std::size_t const count) const volatile noexcept { return Memory::allocate(control, count * sizeof(typename conditional<is_void<base>::value, byte, base>::type), alignmentof(typeof((instanceof<typename conditional<is_void<base>::value, byte, base>::type>())))); }

//         noignore inline typename conditional<is_void<base>::value, Allocation, base*>::type reallocate(base* const address, std::size_t const recount) const volatile noexcept { return Allocator::reallocate(static_cast<control_parameter>(static_cast<unsigned>(Traits::DUMMY)), address, recount); }
//         noignore typename conditional<is_void<base>::value, Allocation, base*>::type reallocate(control_parameter const control, base* const address, std::size_t const recount) const volatile noexcept { return Memory::reallocate(control, address, recount * sizeof(typename conditional<is_void<base>::value, byte, base>::type)); }

//         inline bool release(base* const address) const volatile noexcept { return Memory::release(address); }
//         bool release(base* const address, std::size_t const count) const volatile noexcept { return Memory::release(address, count * sizeof(typename conditional<is_void<base>::value, byte, base>::type)); }
//     };
//   }
// }

// /* Import > ... */
// #include "memory.tpp"
