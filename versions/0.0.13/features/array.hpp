/* Class */
    // Array
    template <class type>
    class Array { friend __MAIN__; friend File;
        typedef ... length_t; // based on type

        type value[];
        immutable_accessor<length_t, Array> length;

        virtual type*& valueOf(void);
    };

    // Dynamic Array
    template <class type>
    class DynamicArray : public Array<type> { friend __MAIN__; friend File;
        typedef Array<type>::length_t length_t;

        DynamicArray(void);
        DynamicArray(length_t const);
        DynamicArray(length_t const, type* const);
    };

    // Static Array
    template <size_t length = 0u, class type>
    class StaticArray : public Array<type> { friend __MAIN__; friend File;
        typedef Array<type>::length_t length_t;

        type& value; // or `type*`?
    };
