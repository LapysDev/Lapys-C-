/* Class */
    /* Immutable Accessor */
    template <class type, class base>
    struct immutable_accessor { friend __MAIN__; friend base;
        // [...]
        private:
            // Definition > Value
            type& value;

            // [Operator] > [=]
            template <class subtype> immutable_accessor& operator =(subtype);

        // [...]
        public:
            // [Constructor]
            constexpr inline immutable_accessor(immutable_accessor const&) = delete;
            constexpr inline immutable_accessor(immutable_accessor&&) = delete;
            constexpr immutable_accessor(type const&);
            constexpr immutable_accessor(type&&);
            template <class... types> constexpr immutable_accessor(types...);

            // [Destructor]
            ~immutable_accessor(void);

            // [Operator] > ([=], [...])
            constexpr inline immutable_accessor& operator =(immutable_accessor const&) const noexcept = delete;
            constexpr inline immutable_accessor& operator =(immutable_accessor&&) const noexcept = delete;

            constexpr operator type&(void) const noexcept;
    };

    /* Inaccessible Mutator */
    template <class type, class base>
    struct inaccessible_mutator { friend __MAIN__; friend base;
        // [...]
        private:
            // Definition > Value
            type& value;

            // [Operator] > [...]
            operator type&(void) const noexcept;

        // [...]
        public:
            // [Constructor]
            inline inaccessible_mutator(inaccessible_mutator const&) = delete;
            inline inaccessible_mutator(inaccessible_mutator&&) = delete;
            inaccessible_mutator(type const&);
            inaccessible_mutator(type&&);
            template <class... types> inline inaccessible_mutator(types...);

            ~inaccessible_mutator(void);

            constexpr inline inaccessible_mutator& operator =(inaccessible_mutator const&) const noexcept = delete;
            constexpr inline inaccessible_mutator& operator =(inaccessible_mutator&&) const noexcept = delete;
            constexpr type& operator =(type const&);
            constexpr type& operator =(type&&);
            template <class subtype> constexpr type& operator =(subtype);
    };

/* Import */
#include "member.cpp"
