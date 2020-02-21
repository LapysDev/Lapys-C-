/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Modification > Size */
        // [Constructor]
        size::size(boolean& argument) { this -> initiate(argument.value == argument.boolean_true); }
        size::size(boolean&& argument) { this -> initiate(argument.value == argument.boolean_true); }
        size::size(const boolean& argument) { this -> initiate(argument.value == argument.boolean_true); }
        size::size(const boolean&& argument) { this -> initiate(argument.value == argument.boolean_true); }

        size::size(primitive& argument) { switch (argument.type) { case argument.integral_type: this -> initiate((std::size_t) *((primitive::integral*) argument.value)); break; case argument.rational_type: this -> initiate((std::size_t) *((primitive::rational*) argument.value)); break; } }
        size::size(primitive&& argument) { switch (argument.type) { case argument.integral_type: this -> initiate((std::size_t) *((primitive::integral*) argument.value)); break; case argument.rational_type: this -> initiate((std::size_t) *((primitive::rational*) argument.value)); break; } }
        size::size(const primitive& argument) { switch (argument.type) { case argument.integral_type: this -> initiate((std::size_t) *((primitive::integral*) argument.value)); break; case argument.rational_type: this -> initiate((std::size_t) *((primitive::rational*) argument.value)); break; } }
        size::size(const primitive&& argument) { switch (argument.type) { case argument.integral_type: this -> initiate((std::size_t) *((primitive::integral*) argument.value)); break; case argument.rational_type: this -> initiate((std::size_t) *((primitive::rational*) argument.value)); break; } }

        // [Operator] > [=]
        size& size::operator =(boolean& argument) { this -> reset(argument.value == argument.boolean_true); return *this; }
        size& size::operator =(boolean&& argument) { this -> reset(argument.value == argument.boolean_true); return *this; }
        size& size::operator =(const boolean& argument) { this -> reset(argument.value == argument.boolean_true); return *this; }
        size& size::operator =(const boolean&& argument) { this -> reset(argument.value == argument.boolean_true); return *this; }

        size& size::operator =(primitive& argument) { switch (argument.type) { case argument.integral_type: this -> reset((std::size_t) *((primitive::integral*) argument.value)); break; case argument.rational_type: this -> reset((std::size_t) *((primitive::rational*) argument.value)); break; } return *this; }
        size& size::operator =(primitive&& argument) { switch (argument.type) { case argument.integral_type: this -> reset((std::size_t) *((primitive::integral*) argument.value)); break; case argument.rational_type: this -> reset((std::size_t) *((primitive::rational*) argument.value)); break; } return *this; }
        size& size::operator =(const primitive& argument) { switch (argument.type) { case argument.integral_type: this -> reset((std::size_t) *((primitive::integral*) argument.value)); break; case argument.rational_type: this -> reset((std::size_t) *((primitive::rational*) argument.value)); break; } return *this; }
        size& size::operator =(const primitive&& argument) { switch (argument.type) { case argument.integral_type: this -> reset((std::size_t) *((primitive::integral*) argument.value)); break; case argument.rational_type: this -> reset((std::size_t) *((primitive::rational*) argument.value)); break; } return *this; }
#endif
