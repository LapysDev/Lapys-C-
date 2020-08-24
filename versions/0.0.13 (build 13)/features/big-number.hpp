/* Definition > Big ... */
class BigFloat;
class BigSignedInteger;
class BigUnsignedInteger;

/* Class > Digit */
namespace {
class Digit {

};
}

/* Class */
    /* Big Unsigned Integer */
    class BigUnsignedInteger : public Array<::Digit> {};

    /* Big Signed Integer */
    class BigSignedInteger : public Array<::Digit>, public BigUnsignedInteger {};

    /* Big Float */
    class BigFloat : public Array<::Digit>, public BigSignedInteger {};
