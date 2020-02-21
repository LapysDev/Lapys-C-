// Number class has Infinity and NaN sub-classes

// x is NaN if and only if x != x.
// x is NaN or an infinity if and only if x - x != 0.
// x is a zero or an infinity if and only if x + x == x.
// x is a zero if and only if x == 0.
// If FLT_EVAL_METHOD is 0 or 1, then x is an infinity if and only if x + DBL_MAX == x.
// x is positive infinity if and only if x + infinity == x.

/* NaN
const unsigned long lnNAN[2] = {0x00000000, 0x7ff80000};
const double NOT_A_NUMBER = *( double* )lnNAN;

NAN std::nan("") std::nanf("") std::nanl("")

bool bNaN = false;
if( 0 == memcmp( &NOT_A_NUMBER, &dQNan, sizeof(double)))
{
    bNaN = true;
}
*/

/* Indeterminate
const unsigned long lnIND[2] = {0x00000000, 0xfff80000};
const double AN_INDETERMINATE  = *( double* )lnIND;

bool bIND = false;
if( 0 == memcmp( &AN_INDETERMINATE, &dIND, sizeof(double)))
{
    bIND = true;
}

if( dIND == dIND )
{
   // Code inside this block will NEVER be executed.
   int a = 0;
}
*/

/* Infinity
const unsigned long lnINF[2] = {0x00000000, 0x7ff00000};
const double AN_INFINITY_POSITIVE  = *( double* )lnINF;

bool bINF = false;
if( 0 == memcmp( &AN_INFINITY_POSITIVE, &dINF, sizeof(double)) ||
    0 == memcmp( &AN_INFINITY_NEGATIVE, &dINF, sizeof(double)))
{
    bINF = true;
}

if( dINF == dINF )
{
    // Code inside this block WILL be executed.
    int a = 0;
}

if( -dINF == -dINF )
{
        // Code inside this block WILL be executed.
        int a = 0;
}
*/

/* Denormalized
const unsigned long lnDEN[2] = {0x00000001, 0x00000000};
const double A_DENORMAL  = *( double* )lnDEN;

bool bDEN = false;
if( 0 == memcmp( &A_DENORMAL, &dDEN, sizeof(double)))
{
        bDEN = true;
}

if ( dDEN != 0 && fabs ( dDEN ) <= std::numeric_limits<double>::denorm_min())
{
    // it's denormalized
    bDEN = true;
}

if( dDEN == dDEN )
{
    // Code inside this block WILL be executed.
    int a = 0;
}
*/
