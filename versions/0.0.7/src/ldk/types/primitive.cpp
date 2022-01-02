/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Modification > Primitive */
        // [Constructor]
        inline primitive::primitive(size& argument) { this -> initiate((std::size_t) argument); }
        inline primitive::primitive(size&& argument) { this -> initiate((std::size_t) argument); }
        inline primitive::primitive(const size& argument) { this -> initiate((std::size_t) argument); }
        inline primitive::primitive(const size&& argument) { this -> initiate((std::size_t) argument); }

        // [Operator] > [=]
        primitive& primitive::operator =(size& argument) { this -> terminate(); this -> initiate((std::size_t) argument); return *this; }
        primitive& primitive::operator =(size&& argument) { this -> terminate(); this -> initiate((std::size_t) argument); return *this; }
        primitive& primitive::operator =(const size& argument) { this -> terminate(); this -> initiate((std::size_t) argument); return *this; }
        primitive& primitive::operator =(const size&& argument) { this -> terminate(); this -> initiate((std::size_t) argument); return *this; }
#endif
