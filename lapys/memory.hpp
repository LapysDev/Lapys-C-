/* Namespace */
namespace Lapys {
  /* Namespace */
  namespace Memory {
    /* Definition > ... */
    class Allocation;

    /* Function > ... */
    template <typename type> noignore inline type* align(type* const, std::size_t const, std::size_t const) noexcept;
    template <typename typeA, typename typeB> noignore inline typeA* align(typeA*, std::size_t const, std::size_t const, typeB* const) noexcept;

    // ...
    noignore Allocation allocateHeap(std::size_t const) noexcept;
    noignore Allocation allocateHeap(std::size_t const, std::size_t const) noexcept;
    noignore Allocation allocateHeap(control_parameter const, std::size_t const) noexcept;
    noignore Allocation allocateHeap(control_parameter const, std::size_t, std::size_t) noexcept;

    // ...
    #if CPP_VENDOR & CPP__MICROSOFT_WINDOWS__VENDOR
      noignore inline HANDLE getHeap() noexcept {
        static HANDLE heap = NULL;

        // ...
        if (NULL == heap) heap = ::GetProcessHeap();
        if (NULL == heap) heap = ::HeapCreate(0x0u, 0u, 0u);

        return heap;
      }
    #endif

    // ...
    template <typename type> noignore Allocation reallocateHeap(type* const, std::size_t const) noexcept;

    // ...
    template <typename type> bool releaseHeap(type* const) noexcept;
    template <typename type> bool releaseHeap(type* const, std::size_t) noexcept;

    /* Class > ... */
    class Allocation final {
      friend Allocation allocateHeap(control_parameter const, std::size_t, std::size_t) noexcept;
      template <typename type> friend Allocation reallocateHeap(type* const, std::size_t const) noexcept;
      template <typename type> friend bool releaseHeap(type* const) noexcept;
      template <typename type> friend bool releaseHeap(type* const, std::size_t) noexcept;

      private:
        #if CPP_VERSION < 2011uL
          static enum kind
        #else
          static enum kind : typename uint_minimum_t::type
        #endif
        {
          C_STANDARD = 0x2u,
          CPP_STANDARD,
          MICROSOFT_WINDOWS__HEAP,
          MICROSOFT_WINDOWS__VIRTUAL,
          UNIX__ALIGNED,
          UNIX__MAPPED
        } const KIND_COMPLETE_REFERENCE = static_cast<Allocation::kind>(0x0u), KIND_INCOMPLETE_REFERENCE = static_cast<Allocation::kind>(0x1u);
        static typename uint_minimum_t::type const KIND_WIDTH = 3u;

        union value {
          friend class Allocation;

          private:
            void *const address;
            typename uint_least_t<(sizeof(kind) > sizeof(std::size_t) ? (sizeof(kind) > sizeof(typename uint_maximum_t::type) ? sizeof(kind) : sizeof(typename uint_maximum_t::type)) : sizeof(std::size_t))>::type const metadata;

            // ...
            constfunc(true) inline value(void const volatile* const address) noexcept : address init(const_cast<void*>(address)) {}

            constfunc(true) inline value(std::size_t const offset) noexcept : metadata init(offset << Allocation::KIND_WIDTH) {}
            constfunc(true) inline value(Allocation::kind const kind, std::size_t const size) noexcept : metadata init((static_cast<std::size_t>(kind) & Allocation::KIND_WIDTH) | (0u != size && size == ((size << Allocation::KIND_WIDTH) >> Allocation::KIND_WIDTH) ? size << Allocation::KIND_WIDTH : 0u)) {}
        } const value;

        // ...
        constfunc(true) inline Allocation(std::size_t const offset) noexcept : value init(offset) {}
        template <typename type> constfunc(true) inline Allocation(type* const pointer) noexcept : value init(static_cast<void const volatile*>(pointer)) {}
        constfunc(true) inline Allocation(Allocation::kind const kind, std::size_t const size = 0u) noexcept : value(kind, size) {}

        // ...
        noignore constfunc(true) inline Allocation::kind getKind  () const lref noexcept { return static_cast<Allocation::kind>(this -> value.metadata & Allocation::KIND_WIDTH); }
        noignore constfunc(true) inline std::size_t      getOffset() const lref noexcept { return this -> value.metadata >> Allocation::KIND_WIDTH; }
        noignore constfunc(true) inline std::size_t      getSize  () const lref noexcept { return this -> value.metadata >> Allocation::KIND_WIDTH; }

        template <typename type>
        noignore inline static Allocation const* inspectHeap(type* const address) noexcept {
          for (byte *information = static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address))) - sizeof(Allocation); ; --information)
          if (0u == static_cast<std::size_t>(static_cast<byte*>(const_cast<void*>(static_cast<void const volatile*>(address))) - information) % alignmentof(Allocation)) {
            Allocation const *const metadata = launder(static_cast<Allocation const*>(static_cast<void const*>(information)));
            return Allocation::KIND_COMPLETE_REFERENCE == metadata -> getKind() ? launder(static_cast<Allocation const*>(static_cast<void const*>(information - (metadata -> getOffset())))) : metadata;
          }

          return NULL;
        }

      public:
        template <typename type>
        noignore constfunc(true) inline operator type*() const rref noexcept {
          return static_cast<type*>(this -> value.address);
        }
    };
  }
}

/* Import > ... */
#include "memory.tpp"
