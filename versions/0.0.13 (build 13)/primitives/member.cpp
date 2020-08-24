/* Modification */
    /* Immutable Accessor */
        // [Constructor]
        template <class type, class> constexpr inline immutable_accessor::immutable_accessor(type const& value) : value{*new type(value)} {}
        template <class type, class> constexpr inline immutable_accessor::immutable_accessor(type&& value) : value{*new type(value)} {}
        template <class type, class> template <class... types> constexpr inline immutable_accessor::immutable_accessor(types... values) : value{*new type(values...)} {}

        // [Destructor]
        template <class, class> inline immutable_accessor::~immutable_accessor(void) { delete &(this -> value); }

        // [Operator] > ...
        template <class type, class> template <class subtype> inline immutable_accessor& immutable_accessor::operator =(subtype value) { this -> value = value; return *this; }
        template <class type, class> constexpr inline immutable_accessor::operator type&(void) const noexcept { return this -> value; }


    /* Inaccessible Mutator */
        // [Constructor]
        template <class type, class> inline inaccessible_mutator::inaccessible_mutator(type const& value) : value{*new type(value)} {}
        template <class type, class> inline inaccessible_mutator::inaccessible_mutator(type&& value) : value{*new type(value)} {}
        template <class type, class> template <class... types> inline inaccessible_mutator::inaccessible_mutator(types... values) : value {*new type(values...)} {}

        // [Destructor]
        template <class, class> inline inaccessible_mutator::~inaccessible_mutator(void) { delete &(this -> value); }

        // [Operator] > ...
        template <class type, class> constexpr inline type& inaccessible_mutator::operator =(type const& value) { this -> value = value; return this -> value; }
        template <class type, class> constexpr inline type& inaccessible_mutator::operator =(type&& value) { this -> value = value; return this -> value; }
        template <class type, class> template <class subtype> constexpr inline type& inaccessible_mutator::operator =(subtype value) { this -> value = value; return this -> value; }

        template <class type, class> inline inaccessible_mutator::operator type&(void) const noexcept { return this -> value; }
