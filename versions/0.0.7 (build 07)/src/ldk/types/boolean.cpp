/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Modification > Boolean */
        // [Constructor]
        inline boolean::boolean(object&) : value{this -> boolean_true} {}
        inline boolean::boolean(object&&) : value{this -> boolean_true} {}
        inline boolean::boolean(const object&) : value{this -> boolean_true} {}
        inline boolean::boolean(const object&&) : value{this -> boolean_true} {}

        inline boolean::boolean(primitive& argument) { switch (argument.type) { case argument.integral_type: this -> value = *((primitive::integral*) argument.value) ? this -> boolean_true : this -> boolean_false; break; case argument.rational_type: this -> value = *((primitive::rational*) argument.value) ? this -> boolean_true : this -> boolean_false; break; } }
        inline boolean::boolean(primitive&& argument) { switch (argument.type) { case argument.integral_type: this -> value = *((primitive::integral*) argument.value) ? this -> boolean_true : this -> boolean_false; break; case argument.rational_type: this -> value = *((primitive::rational*) argument.value) ? this -> boolean_true : this -> boolean_false; break; } }
        inline boolean::boolean(const primitive& argument) { switch (argument.type) { case argument.integral_type: this -> value = *((primitive::integral*) argument.value) ? this -> boolean_true : this -> boolean_false; break; case argument.rational_type: this -> value = *((primitive::rational*) argument.value) ? this -> boolean_true : this -> boolean_false; break; } }
        inline boolean::boolean(const primitive&& argument) { switch (argument.type) { case argument.integral_type: this -> value = *((primitive::integral*) argument.value) ? this -> boolean_true : this -> boolean_false; break; case argument.rational_type: this -> value = *((primitive::rational*) argument.value) ? this -> boolean_true : this -> boolean_false; break; } }

        inline boolean::boolean(size& argument) : value{(NULL != argument.first -> next || argument.current -> value) ? this -> boolean_true : this -> boolean_false} {}
        inline boolean::boolean(size&& argument) : value{(NULL != argument.first -> next || argument.current -> value) ? this -> boolean_true : this -> boolean_false} {}
        inline boolean::boolean(const size& argument) : value{(NULL != argument.first -> next || argument.current -> value) ? this -> boolean_true : this -> boolean_false} {}
        inline boolean::boolean(const size&& argument) : value{(NULL != argument.first -> next || argument.current -> value) ? this -> boolean_true : this -> boolean_false} {}

        // [Operator] > [=]
        inline boolean& boolean::operator =(object&) { this -> value = this -> boolean_true; return *this; }
        inline boolean& boolean::operator =(object&&) { this -> value = this -> boolean_true; return *this; }
        inline boolean& boolean::operator =(const object&) { this -> value = this -> boolean_true; return *this; }
        inline boolean& boolean::operator =(const object&&) { this -> value = this -> boolean_true; return *this; }

        inline boolean& boolean::operator =(primitive& argument) { switch (argument.type) { case argument.integral_type: this -> value = *((primitive::integral*) argument.value) ? this -> boolean_true : this -> boolean_false; break; case argument.rational_type: this -> value = *((primitive::rational*) argument.value) ? this -> boolean_true : this -> boolean_false; break; } return *this; }
        inline boolean& boolean::operator =(primitive&& argument) { switch (argument.type) { case argument.integral_type: this -> value = *((primitive::integral*) argument.value) ? this -> boolean_true : this -> boolean_false; break; case argument.rational_type: this -> value = *((primitive::rational*) argument.value) ? this -> boolean_true : this -> boolean_false; break; } return *this; }
        inline boolean& boolean::operator =(const primitive& argument) { switch (argument.type) { case argument.integral_type: this -> value = *((primitive::integral*) argument.value) ? this -> boolean_true : this -> boolean_false; break; case argument.rational_type: this -> value = *((primitive::rational*) argument.value) ? this -> boolean_true : this -> boolean_false; break; } return *this; }
        inline boolean& boolean::operator =(const primitive&& argument) { switch (argument.type) { case argument.integral_type: this -> value = *((primitive::integral*) argument.value) ? this -> boolean_true : this -> boolean_false; break; case argument.rational_type: this -> value = *((primitive::rational*) argument.value) ? this -> boolean_true : this -> boolean_false; break; } return *this; }

        inline boolean& boolean::operator =(size& argument) { this -> value = (NULL != argument.first -> next || argument.current -> value) ? this -> boolean_true : this -> boolean_false; return *this; }
        inline boolean& boolean::operator =(size&& argument) { this -> value = (NULL != argument.first -> next || argument.current -> value) ? this -> boolean_true : this -> boolean_false; return *this; }
        inline boolean& boolean::operator =(const size& argument) { this -> value = (NULL != argument.first -> next || argument.current -> value) ? this -> boolean_true : this -> boolean_false; return *this; }
        inline boolean& boolean::operator =(const size&& argument) { this -> value = (NULL != argument.first -> next || argument.current -> value) ? this -> boolean_true : this -> boolean_false; return *this; }
#endif
