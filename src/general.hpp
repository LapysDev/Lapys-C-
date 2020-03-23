/* Pragma */
#pragma once

/* Import */
#include "libraries/c/includes.h" // C Standard Library
#include "libraries/c++/includes.hpp" // C++ Standard Library

#include "environments/linux/includes.h" // Linux
#include "environments/windows/includes.h" // Windows

#include "shims/polyfills.hpp" // ... --- NOTE (Lapys) -> Shiv required differences between alternative implementations and versions of C++.

/* Class > ... */
struct array;
struct boolean;
struct character;
struct integral;
struct null_pointer;
struct number;
struct pointer;
struct primitive;
struct rational;
struct raw_pointer;
struct string;
struct wide;

/* Definition --- NOTE (Lapys) -> Some of these function definitions may be optimized in-definition. */
    // Array ...
    // Number ... --- CHECKPOINT (Lapys)
    constexpr inline double number__absolute(double const) noexcept;
    constexpr inline float number__absolute(float const) noexcept;
    constexpr inline int number__absolute(int const) noexcept;
    inline long number__absolute(long const) noexcept;
    constexpr inline long double number__absolute(long double const) noexcept;
    constexpr inline short number__absolute(short const) noexcept;
    constexpr inline unsigned int number__absolute(unsigned int const) noexcept;
    constexpr inline unsigned long number__absolute(unsigned long const) noexcept;
    constexpr inline unsigned short number__absolute(unsigned short const) noexcept;
    inline wide number__absolute(wide const) noexcept;

    constexpr inline double number__arc_cosine(double const);
    constexpr inline float number__arc_cosine(float const);
    constexpr inline float number__arc_cosine(int const);
    constexpr inline double number__arc_cosine(long const);
    constexpr inline long double number__arc_cosine(long double const);
    constexpr inline float number__arc_cosine(short const);
    constexpr inline float number__arc_cosine(unsigned int const);
    constexpr inline double number__arc_cosine(unsigned long const);
    constexpr inline float number__arc_cosine(unsigned short const);
    inline long double number__arc_cosine(wide const);

    constexpr inline double number__arc_sine(double const);
    constexpr inline float number__arc_sine(float const);
    constexpr inline float number__arc_sine(int const);
    constexpr inline double number__arc_sine(long const);
    constexpr inline long double number__arc_sine(long double const);
    constexpr inline float number__arc_sine(short const);
    constexpr inline float number__arc_sine(unsigned int const);
    constexpr inline double number__arc_sine(unsigned long const);
    constexpr inline float number__arc_sine(unsigned short const);
    inline long double number__arc_sine(wide const);

    constexpr inline double number__arc_tangent(double const);
    constexpr inline float number__arc_tangent(float const);
    constexpr inline float number__arc_tangent(int const);
    constexpr inline double number__arc_tangent(long const);
    constexpr inline long double number__arc_tangent(long double const);
    constexpr inline float number__arc_tangent(short const);
    constexpr inline float number__arc_tangent(unsigned int const);
    constexpr inline double number__arc_tangent(unsigned long const);
    constexpr inline float number__arc_tangent(unsigned short const);
    inline long double number__arc_tangent(wide const);

    constexpr inline double number__area_hyperbolic_cosine(double const);
    constexpr inline float number__area_hyperbolic_cosine(float const);
    constexpr inline float number__area_hyperbolic_cosine(int const);
    constexpr inline double number__area_hyperbolic_cosine(long const);
    constexpr inline long double number__area_hyperbolic_cosine(long double const);
    constexpr inline float number__area_hyperbolic_cosine(short const);
    constexpr inline float number__area_hyperbolic_cosine(unsigned int const);
    constexpr inline double number__area_hyperbolic_cosine(unsigned long const);
    constexpr inline float number__area_hyperbolic_cosine(unsigned short const);
    inline long double number__area_hyperbolic_cosine(wide const);

    constexpr inline double number__area_hyperbolic_sine(double const);
    constexpr inline float number__area_hyperbolic_sine(float const);
    constexpr inline float number__area_hyperbolic_sine(int const);
    constexpr inline double number__area_hyperbolic_sine(long const);
    constexpr inline long double number__area_hyperbolic_sine(long double const);
    constexpr inline float number__area_hyperbolic_sine(short const);
    constexpr inline float number__area_hyperbolic_sine(unsigned int const);
    constexpr inline double number__area_hyperbolic_sine(unsigned long const);
    constexpr inline float number__area_hyperbolic_sine(unsigned short const);
    inline long double number__area_hyperbolic_sine(wide const);

    constexpr inline double number__area_hyperbolic_tangent(double const);
    constexpr inline float number__area_hyperbolic_tangent(float const);
    constexpr inline float number__area_hyperbolic_tangent(int const);
    constexpr inline double number__area_hyperbolic_tangent(long const);
    constexpr inline long double number__area_hyperbolic_tangent(long double const);
    constexpr inline float number__area_hyperbolic_tangent(short const);
    constexpr inline float number__area_hyperbolic_tangent(unsigned int const);
    constexpr inline double number__area_hyperbolic_tangent(unsigned long const);
    constexpr inline float number__area_hyperbolic_tangent(unsigned short const);
    inline long double number__area_hyperbolic_tangent(wide const);

    constexpr inline double number__ceiling(double const) noexcept;
    constexpr inline float number__ceiling(float const) noexcept;
    constexpr inline int number__ceiling(int const) noexcept;
    constexpr inline long number__ceiling(long const) noexcept;
    constexpr inline long double number__ceiling(long double const) noexcept;
    constexpr inline short number__ceiling(short const) noexcept;
    constexpr inline unsigned int number__ceiling(unsigned int const) noexcept;
    constexpr inline unsigned long number__ceiling(unsigned long const) noexcept;
    constexpr inline unsigned short number__ceiling(unsigned short const) noexcept;
    inline wide number__ceiling(wide const) noexcept;

    constexpr inline double number__cosine(double const);
    constexpr inline float number__cosine(float const);
    constexpr inline float number__cosine(int const);
    constexpr inline double number__cosine(long const);
    inline long double number__cosine(long double const);
    constexpr inline float number__cosine(short const);
    constexpr inline float number__cosine(unsigned int const);
    constexpr inline double number__cosine(unsigned long const);
    constexpr inline float number__cosine(unsigned short const);
    inline long double number__cosine(wide const);

    constexpr inline double number__exponentiate(double const);
    constexpr inline float number__exponentiate(float const);
    constexpr inline float number__exponentiate(int const);
    inline long double number__exponentiate(long const);
    inline long double number__exponentiate(long double const);
    constexpr inline float number__exponentiate(short const);
    constexpr inline float number__exponentiate(unsigned int const);
    inline long double number__exponentiate(unsigned long const);
    constexpr inline float number__exponentiate(unsigned short const);
    inline long double number__exponentiate(wide const);

    inline double number__floor(double const) noexcept;
    inline float number__floor(float const) noexcept;
    constexpr inline int number__floor(int const) noexcept;
    constexpr inline long number__floor(long const) noexcept;
    inline long double number__floor(long double const) noexcept;
    constexpr inline short number__floor(short const) noexcept;
    constexpr inline unsigned int number__floor(unsigned int const) noexcept;
    constexpr inline unsigned long number__floor(unsigned long const) noexcept;
    constexpr inline unsigned short number__floor(unsigned short const) noexcept;
    constexpr inline wide number__floor(wide const) noexcept;

    constexpr inline double number__hyperbolic_cosine(double const);
    constexpr inline float number__hyperbolic_cosine(float const);
    constexpr inline float number__hyperbolic_cosine(int const);
    constexpr inline double number__hyperbolic_cosine(long const);
    inline long double number__hyperbolic_cosine(long double const);
    constexpr inline float number__hyperbolic_cosine(short const);
    constexpr inline float number__hyperbolic_cosine(unsigned int const);
    constexpr inline double number__hyperbolic_cosine(unsigned long const);
    constexpr inline float number__hyperbolic_cosine(unsigned short const);
    inline long double number__hyperbolic_cosine(wide const);

    constexpr inline double number__hyperbolic_sine(double const);
    constexpr inline float number__hyperbolic_sine(float const);
    constexpr inline float number__hyperbolic_sine(int const);
    constexpr inline double number__hyperbolic_sine(long const);
    inline long double number__hyperbolic_sine(long double const);
    constexpr inline float number__hyperbolic_sine(short const);
    constexpr inline float number__hyperbolic_sine(unsigned int const);
    constexpr inline double number__hyperbolic_sine(unsigned long const);
    constexpr inline float number__hyperbolic_sine(unsigned short const);
    inline long double number__hyperbolic_sine(wide const);

    constexpr inline double number__hyperbolic_tangent(double const);
    constexpr inline float number__hyperbolic_tangent(float const);
    constexpr inline float number__hyperbolic_tangent(int const);
    constexpr inline double number__hyperbolic_tangent(long const);
    inline long double number__hyperbolic_tangent(long double const);
    constexpr inline float number__hyperbolic_tangent(short const);
    constexpr inline float number__hyperbolic_tangent(unsigned int const);
    constexpr inline double number__hyperbolic_tangent(unsigned long const);
    constexpr inline float number__hyperbolic_tangent(unsigned short const);
    inline long double number__hyperbolic_tangent(wide const);

    constexpr inline bool number__is_computable(double const) noexcept;
    constexpr inline bool number__is_computable(float const) noexcept;
    constexpr inline bool number__is_computable(int const) noexcept;
    constexpr inline bool number__is_computable(long const) noexcept;
    constexpr inline bool number__is_computable(long double const) noexcept;
    constexpr inline bool number__is_computable(short const) noexcept;
    constexpr inline bool number__is_computable(unsigned int const) noexcept;
    constexpr inline bool number__is_computable(unsigned long const) noexcept;
    constexpr inline bool number__is_computable(unsigned short const) noexcept;
    constexpr inline bool number__is_computable(wide const) noexcept;

    inline bool number__is_determinate(double const) noexcept;
    inline bool number__is_determinate(float const) noexcept;
    constexpr inline bool number__is_determinate(int const) noexcept;
    constexpr inline bool number__is_determinate(long const) noexcept;
    inline bool number__is_determinate(long double const) noexcept;
    constexpr inline bool number__is_determinate(short const) noexcept;
    constexpr inline bool number__is_determinate(unsigned int const) noexcept;
    constexpr inline bool number__is_determinate(unsigned long const) noexcept;
    constexpr inline bool number__is_determinate(unsigned short const) noexcept;
    constexpr inline bool number__is_determinate(wide const) noexcept;

    inline bool number__is_finite(double const) noexcept;
    inline bool number__is_finite(float const) noexcept;
    constexpr inline bool number__is_finite(int const) noexcept;
    constexpr inline bool number__is_finite(long const) noexcept;
    inline bool number__is_finite(long double const) noexcept;
    constexpr inline bool number__is_finite(short const) noexcept;
    constexpr inline bool number__is_finite(unsigned int const) noexcept;
    constexpr inline bool number__is_finite(unsigned long const) noexcept;
    constexpr inline bool number__is_finite(unsigned short const) noexcept;
    constexpr inline bool number__is_finite(wide const) noexcept;

    constexpr inline bool number__is_infinite(double const) noexcept;
    constexpr inline bool number__is_infinite(float const) noexcept;
    constexpr inline bool number__is_infinite(int const) noexcept;
    constexpr inline bool number__is_infinite(long const) noexcept;
    constexpr inline bool number__is_infinite(long double const) noexcept;
    constexpr inline bool number__is_infinite(short const) noexcept;
    constexpr inline bool number__is_infinite(unsigned int const) noexcept;
    constexpr inline bool number__is_infinite(unsigned long const) noexcept;
    constexpr inline bool number__is_infinite(unsigned short const) noexcept;
    constexpr inline bool number__is_infinite(wide const) noexcept;

    inline bool number__is_normalized(double const) noexcept;
    inline bool number__is_normalized(float const) noexcept;
    constexpr inline bool number__is_normalized(int const) noexcept;
    constexpr inline bool number__is_normalized(long const) noexcept;
    inline bool number__is_normalized(long double const) noexcept;
    constexpr inline bool number__is_normalized(short const) noexcept;
    constexpr inline bool number__is_normalized(unsigned int const) noexcept;
    constexpr inline bool number__is_normalized(unsigned long const) noexcept;
    constexpr inline bool number__is_normalized(unsigned short const) noexcept;
    constexpr inline bool number__is_normalized(wide const) noexcept;

    inline bool number__is_safe(double const) noexcept;
    inline bool number__is_safe(float const) noexcept;
    inline bool number__is_safe(int const) noexcept;
    inline bool number__is_safe(long const) noexcept;
    inline bool number__is_safe(long double const) noexcept;
    inline bool number__is_safe(short const) noexcept;
    inline bool number__is_safe(unsigned int const) noexcept;
    inline bool number__is_safe(unsigned long const) noexcept;
    inline bool number__is_safe(unsigned short const) noexcept;
    inline bool number__is_safe(wide const) noexcept;

    constexpr inline double number__logarithm(double const);
    constexpr inline float number__logarithm(float const);
    constexpr inline float number__logarithm(int const);
    constexpr inline double number__logarithm(long const);
    constexpr inline long double number__logarithm(long double const);
    constexpr inline float number__logarithm(short const);
    constexpr inline float number__logarithm(unsigned int const);
    constexpr inline double number__logarithm(unsigned long const);
    constexpr inline float number__logarithm(unsigned short const);
    inline long double number__logarithm(wide const);

    constexpr inline double number__maximum(double const, double const) noexcept;
    constexpr inline double number__maximum(double const, float const) noexcept;
    constexpr inline double number__maximum(double const, int const) noexcept;
    constexpr inline double number__maximum(double const, long const) noexcept;
    constexpr inline long double number__maximum(double const, long double const) noexcept;
    constexpr inline double number__maximum(double const, short const) noexcept;
    constexpr inline double number__maximum(double const, unsigned int const) noexcept;
    constexpr inline double number__maximum(double const, unsigned long const) noexcept;
    constexpr inline double number__maximum(double const, unsigned short const) noexcept;
    inline long double number__maximum(double const, wide const) noexcept;
    constexpr inline double number__maximum(float const, double const) noexcept;
    constexpr inline float number__maximum(float const, float const) noexcept;
    constexpr inline float number__maximum(float const, int const) noexcept;
    constexpr inline double number__maximum(float const, long const) noexcept;
    constexpr inline long double number__maximum(float const, long double const) noexcept;
    constexpr inline float number__maximum(float const, short const) noexcept;
    constexpr inline float number__maximum(float const, unsigned int const) noexcept;
    constexpr inline double number__maximum(float const, unsigned long const) noexcept;
    constexpr inline double number__maximum(float const, unsigned short const) noexcept;
    inline long double number__maximum(float const, wide const) noexcept;
    constexpr inline double number__maximum(int const, double const) noexcept;
    constexpr inline float number__maximum(int const, float const) noexcept;
    constexpr inline int number__maximum(int const, int const) noexcept;
    constexpr inline long number__maximum(int const, long const) noexcept;
    constexpr inline long double number__maximum(int const, long double const) noexcept;
    constexpr inline int number__maximum(int const, short const) noexcept;
    constexpr inline long number__maximum(int const, unsigned int const) noexcept;
    constexpr inline double number__maximum(int const, unsigned long const) noexcept;
    constexpr inline long number__maximum(int const, unsigned short const) noexcept;
    inline wide number__maximum(int const, wide const) noexcept;
    constexpr inline double number__maximum(long const, double const) noexcept;
    constexpr inline double number__maximum(long const, float const) noexcept;
    constexpr inline long number__maximum(long const, int const) noexcept;
    constexpr inline long number__maximum(long const, long const) noexcept;
    constexpr inline long double number__maximum(long const, long double const) noexcept;
    constexpr inline long number__maximum(long const, short const) noexcept;
    constexpr inline double number__maximum(long const, unsigned int const) noexcept;
    constexpr inline double number__maximum(long const, unsigned long const) noexcept;
    constexpr inline double number__maximum(long const, unsigned short const) noexcept;
    inline long double number__maximum(long const, wide const) noexcept;
    constexpr inline long double number__maximum(long double const, double const) noexcept;
    constexpr inline long double number__maximum(long double const, float const) noexcept;
    constexpr inline long double number__maximum(long double const, int const) noexcept;
    constexpr inline long double number__maximum(long double const, long const) noexcept;
    constexpr inline long double number__maximum(long double const, long double const) noexcept;
    constexpr inline long double number__maximum(long double const, short const) noexcept;
    constexpr inline long double number__maximum(long double const, unsigned int const) noexcept;
    constexpr inline long double number__maximum(long double const, unsigned long const) noexcept;
    constexpr inline long double number__maximum(long double const, unsigned short const) noexcept;
    inline long double number__maximum(long double const, wide const) noexcept;
    constexpr inline double number__maximum(short const, double const) noexcept;
    constexpr inline float number__maximum(short const, float const) noexcept;
    constexpr inline int number__maximum(short const, int const) noexcept;
    constexpr inline long number__maximum(short const, long const) noexcept;
    constexpr inline long double number__maximum(short const, long double const) noexcept;
    constexpr inline short number__maximum(short const, short const) noexcept;
    constexpr inline long number__maximum(short const, unsigned int const) noexcept;
    constexpr inline double number__maximum(short const, unsigned long const) noexcept;
    constexpr inline int number__maximum(short const, unsigned short const) noexcept;
    inline long double number__maximum(short const, wide const) noexcept;
    constexpr inline double number__maximum(unsigned int const, double const) noexcept;
    constexpr inline float number__maximum(unsigned int const, float const) noexcept;
    constexpr inline long number__maximum(unsigned int const, int const) noexcept;
    constexpr inline long number__maximum(unsigned int const, long const) noexcept;
    constexpr inline long double number__maximum(unsigned int const, long double const) noexcept;
    constexpr inline long number__maximum(unsigned int const, short const) noexcept;
    constexpr inline unsigned int number__maximum(unsigned int const, unsigned int const) noexcept;
    constexpr inline unsigned long number__maximum(unsigned int const, unsigned long const) noexcept;
    constexpr inline unsigned int number__maximum(unsigned int const, unsigned short const) noexcept;
    inline wide number__maximum(unsigned int const, wide const) noexcept;
    constexpr inline double number__maximum(unsigned long const, double const) noexcept;
    constexpr inline float number__maximum(unsigned long const, float const) noexcept;
    constexpr inline double number__maximum(unsigned long const, int const) noexcept;
    constexpr inline double number__maximum(unsigned long const, long const) noexcept;
    constexpr inline long double number__maximum(unsigned long const, long double const) noexcept;
    constexpr inline double number__maximum(unsigned long const, short const) noexcept;
    constexpr inline double number__maximum(unsigned long const, unsigned int const) noexcept;
    constexpr inline unsigned long number__maximum(unsigned long const, unsigned long const) noexcept;
    constexpr inline unsigned long number__maximum(unsigned long const, unsigned short const) noexcept;
    inline wide number__maximum(unsigned long const, wide const) noexcept;
    constexpr inline double number__maximum(unsigned short const, double const) noexcept;
    constexpr inline float number__maximum(unsigned short const, float const) noexcept;
    constexpr inline long number__maximum(unsigned short const, int const) noexcept;
    constexpr inline long number__maximum(unsigned short const, long const) noexcept;
    constexpr inline long double number__maximum(unsigned short const, long double const) noexcept;
    constexpr inline int number__maximum(unsigned short const, short const) noexcept;
    constexpr inline unsigned int number__maximum(unsigned short const, unsigned int const) noexcept;
    constexpr inline unsigned long number__maximum(unsigned short const, unsigned long const) noexcept;
    constexpr inline unsigned short number__maximum(unsigned short const, unsigned short const) noexcept;
    inline wide number__maximum(unsigned short const, wide const) noexcept;
    inline long double number__maximum(wide const, double const) noexcept;
    inline long double number__maximum(wide const, float const) noexcept;
    inline wide number__maximum(wide const, int const) noexcept;
    inline wide number__maximum(wide const, long const) noexcept;
    inline long double number__maximum(wide const, long double const) noexcept;
    inline wide number__maximum(wide const, short const) noexcept;
    inline wide number__maximum(wide const, unsigned int const) noexcept;
    inline wide number__maximum(wide const, unsigned long const) noexcept;
    inline wide number__maximum(wide const, unsigned short const) noexcept;
    inline wide number__maximum(wide const, wide const) noexcept;

    constexpr inline double number__minimum(double const, double const) noexcept;
    constexpr inline double number__minimum(double const, float const) noexcept;
    constexpr inline double number__minimum(double const, int const) noexcept;
    constexpr inline double number__minimum(double const, long const) noexcept;
    constexpr inline long double number__minimum(double const, long double const) noexcept;
    constexpr inline double number__minimum(double const, short const) noexcept;
    constexpr inline double number__minimum(double const, unsigned int const) noexcept;
    constexpr inline double number__minimum(double const, unsigned long const) noexcept;
    constexpr inline double number__minimum(double const, unsigned short const) noexcept;
    inline long double number__minimum(double const, wide const) noexcept;
    constexpr inline double number__minimum(float const, double const) noexcept;
    constexpr inline float number__minimum(float const, float const) noexcept;
    constexpr inline float number__minimum(float const, int const) noexcept;
    constexpr inline double number__minimum(float const, long const) noexcept;
    constexpr inline long double number__minimum(float const, long double const) noexcept;
    constexpr inline float number__minimum(float const, short const) noexcept;
    constexpr inline float number__minimum(float const, unsigned int const) noexcept;
    constexpr inline double number__minimum(float const, unsigned long const) noexcept;
    constexpr inline double number__minimum(float const, unsigned short const) noexcept;
    inline long double number__minimum(float const, wide const) noexcept;
    constexpr inline double number__minimum(int const, double const) noexcept;
    constexpr inline float number__minimum(int const, float const) noexcept;
    constexpr inline int number__minimum(int const, int const) noexcept;
    constexpr inline long number__minimum(int const, long const) noexcept;
    constexpr inline long double number__minimum(int const, long double const) noexcept;
    constexpr inline int number__minimum(int const, short const) noexcept;
    constexpr inline long number__minimum(int const, unsigned int const) noexcept;
    constexpr inline double number__minimum(int const, unsigned long const) noexcept;
    constexpr inline long number__minimum(int const, unsigned short const) noexcept;
    inline wide number__minimum(int const, wide const) noexcept;
    constexpr inline double number__minimum(long const, double const) noexcept;
    constexpr inline double number__minimum(long const, float const) noexcept;
    constexpr inline long number__minimum(long const, int const) noexcept;
    constexpr inline long number__minimum(long const, long const) noexcept;
    constexpr inline long double number__minimum(long const, long double const) noexcept;
    constexpr inline long number__minimum(long const, short const) noexcept;
    constexpr inline double number__minimum(long const, unsigned int const) noexcept;
    constexpr inline double number__minimum(long const, unsigned long const) noexcept;
    constexpr inline double number__minimum(long const, unsigned short const) noexcept;
    inline long double number__minimum(long const, wide const) noexcept;
    constexpr inline long double number__minimum(long double const, double const) noexcept;
    constexpr inline long double number__minimum(long double const, float const) noexcept;
    constexpr inline long double number__minimum(long double const, int const) noexcept;
    constexpr inline long double number__minimum(long double const, long const) noexcept;
    constexpr inline long double number__minimum(long double const, long double const) noexcept;
    constexpr inline long double number__minimum(long double const, short const) noexcept;
    constexpr inline long double number__minimum(long double const, unsigned int const) noexcept;
    constexpr inline long double number__minimum(long double const, unsigned long const) noexcept;
    constexpr inline long double number__minimum(long double const, unsigned short const) noexcept;
    inline long double number__minimum(long double const, wide const) noexcept;
    constexpr inline double number__minimum(short const, double const) noexcept;
    constexpr inline float number__minimum(short const, float const) noexcept;
    constexpr inline int number__minimum(short const, int const) noexcept;
    constexpr inline long number__minimum(short const, long const) noexcept;
    constexpr inline long double number__minimum(short const, long double const) noexcept;
    constexpr inline short number__minimum(short const, short const) noexcept;
    constexpr inline long number__minimum(short const, unsigned int const) noexcept;
    constexpr inline double number__minimum(short const, unsigned long const) noexcept;
    constexpr inline int number__minimum(short const, unsigned short const) noexcept;
    inline long double number__minimum(short const, wide const) noexcept;
    constexpr inline double number__minimum(unsigned int const, double const) noexcept;
    constexpr inline float number__minimum(unsigned int const, float const) noexcept;
    constexpr inline long number__minimum(unsigned int const, int const) noexcept;
    constexpr inline long number__minimum(unsigned int const, long const) noexcept;
    constexpr inline long double number__minimum(unsigned int const, long double const) noexcept;
    constexpr inline long number__minimum(unsigned int const, short const) noexcept;
    constexpr inline unsigned int number__minimum(unsigned int const, unsigned int const) noexcept;
    constexpr inline unsigned long number__minimum(unsigned int const, unsigned long const) noexcept;
    constexpr inline unsigned int number__minimum(unsigned int const, unsigned short const) noexcept;
    inline wide number__minimum(unsigned int const, wide const) noexcept;
    constexpr inline double number__minimum(unsigned long const, double const) noexcept;
    constexpr inline float number__minimum(unsigned long const, float const) noexcept;
    constexpr inline double number__minimum(unsigned long const, int const) noexcept;
    constexpr inline double number__minimum(unsigned long const, long const) noexcept;
    constexpr inline long double number__minimum(unsigned long const, long double const) noexcept;
    constexpr inline double number__minimum(unsigned long const, short const) noexcept;
    constexpr inline double number__minimum(unsigned long const, unsigned int const) noexcept;
    constexpr inline unsigned long number__minimum(unsigned long const, unsigned long const) noexcept;
    constexpr inline unsigned long number__minimum(unsigned long const, unsigned short const) noexcept;
    inline wide number__minimum(unsigned long const, wide const) noexcept;
    constexpr inline double number__minimum(unsigned short const, double const) noexcept;
    constexpr inline float number__minimum(unsigned short const, float const) noexcept;
    constexpr inline long number__minimum(unsigned short const, int const) noexcept;
    constexpr inline long number__minimum(unsigned short const, long const) noexcept;
    constexpr inline long double number__minimum(unsigned short const, long double const) noexcept;
    constexpr inline int number__minimum(unsigned short const, short const) noexcept;
    constexpr inline unsigned int number__minimum(unsigned short const, unsigned int const) noexcept;
    constexpr inline unsigned long number__minimum(unsigned short const, unsigned long const) noexcept;
    constexpr inline unsigned short number__minimum(unsigned short const, unsigned short const) noexcept;
    inline wide number__minimum(unsigned short const, wide const) noexcept;
    inline long double number__minimum(wide const, double const) noexcept;
    inline long double number__minimum(wide const, float const) noexcept;
    inline wide number__minimum(wide const, int const) noexcept;
    inline wide number__minimum(wide const, long const) noexcept;
    inline long double number__minimum(wide const, long double const) noexcept;
    inline wide number__minimum(wide const, short const) noexcept;
    inline wide number__minimum(wide const, unsigned int const) noexcept;
    inline wide number__minimum(wide const, unsigned long const) noexcept;
    inline wide number__minimum(wide const, unsigned short const) noexcept;
    inline wide number__minimum(wide const, wide const) noexcept;

    constexpr inline double number__power(double const, double const);
    constexpr inline double number__power(double const, float const);
    constexpr inline double number__power(double const, int const);
    constexpr inline double number__power(double const, long const);
    constexpr inline long double number__power(double const, long double const);
    constexpr inline double number__power(double const, short const);
    constexpr inline double number__power(double const, unsigned int const);
    constexpr inline double number__power(double const, unsigned long const);
    constexpr inline double number__power(double const, unsigned short const);
    inline long double number__power(double const, wide const);
    constexpr inline double number__power(float const, double const);
    constexpr inline float number__power(float const, float const);
    constexpr inline float number__power(float const, int const);
    constexpr inline double number__power(float const, long const);
    constexpr inline long double number__power(float const, long double const);
    constexpr inline float number__power(float const, short const);
    constexpr inline float number__power(float const, unsigned int const);
    constexpr inline double number__power(float const, unsigned long const);
    constexpr inline double number__power(float const, unsigned short const);
    inline long double number__power(float const, wide const);
    constexpr inline double number__power(int const, double const);
    constexpr inline float number__power(int const, float const);
    constexpr inline int number__power(int const, int const);
    constexpr inline long number__power(int const, long const);
    constexpr inline long double number__power(int const, long double const);
    constexpr inline int number__power(int const, short const);
    constexpr inline long number__power(int const, unsigned int const);
    constexpr inline double number__power(int const, unsigned long const);
    constexpr inline long number__power(int const, unsigned short const);
    inline wide number__power(int const, wide const);
    constexpr inline double number__power(long const, double const);
    constexpr inline double number__power(long const, float const);
    constexpr inline long number__power(long const, int const);
    constexpr inline long number__power(long const, long const);
    constexpr inline long double number__power(long const, long double const);
    constexpr inline long number__power(long const, short const);
    constexpr inline double number__power(long const, unsigned int const);
    constexpr inline double number__power(long const, unsigned long const);
    constexpr inline double number__power(long const, unsigned short const);
    inline long double number__power(long const, wide const);
    constexpr inline long double number__power(long double const, double const);
    constexpr inline long double number__power(long double const, float const);
    constexpr inline long double number__power(long double const, int const);
    constexpr inline long double number__power(long double const, long const);
    constexpr inline long double number__power(long double const, long double const);
    constexpr inline long double number__power(long double const, short const);
    constexpr inline long double number__power(long double const, unsigned int const);
    constexpr inline long double number__power(long double const, unsigned long const);
    constexpr inline long double number__power(long double const, unsigned short const);
    inline long double number__power(long double const, wide const);
    constexpr inline double number__power(short const, double const);
    constexpr inline float number__power(short const, float const);
    constexpr inline int number__power(short const, int const);
    constexpr inline long number__power(short const, long const);
    constexpr inline long double number__power(short const, long double const);
    constexpr inline short number__power(short const, short const);
    constexpr inline long number__power(short const, unsigned int const);
    constexpr inline double number__power(short const, unsigned long const);
    constexpr inline int number__power(short const, unsigned short const);
    inline long double number__power(short const, wide const);
    constexpr inline double number__power(unsigned int const, double const);
    constexpr inline float number__power(unsigned int const, float const);
    constexpr inline long number__power(unsigned int const, int const);
    constexpr inline long number__power(unsigned int const, long const);
    constexpr inline long double number__power(unsigned int const, long double const);
    constexpr inline long number__power(unsigned int const, short const);
    constexpr inline unsigned int number__power(unsigned int const, unsigned int const);
    constexpr inline unsigned long number__power(unsigned int const, unsigned long const);
    constexpr inline unsigned int number__power(unsigned int const, unsigned short const);
    inline wide number__power(unsigned int const, wide const);
    constexpr inline double number__power(unsigned long const, double const);
    constexpr inline float number__power(unsigned long const, float const);
    constexpr inline double number__power(unsigned long const, int const);
    constexpr inline double number__power(unsigned long const, long const);
    constexpr inline long double number__power(unsigned long const, long double const);
    constexpr inline double number__power(unsigned long const, short const);
    constexpr inline double number__power(unsigned long const, unsigned int const);
    constexpr inline unsigned long number__power(unsigned long const, unsigned long const);
    constexpr inline unsigned long number__power(unsigned long const, unsigned short const);
    inline wide number__power(unsigned long const, wide const);
    constexpr inline double number__power(unsigned short const, double const);
    constexpr inline float number__power(unsigned short const, float const);
    constexpr inline long number__power(unsigned short const, int const);
    constexpr inline long number__power(unsigned short const, long const);
    constexpr inline long double number__power(unsigned short const, long double const);
    constexpr inline int number__power(unsigned short const, short const);
    constexpr inline unsigned int number__power(unsigned short const, unsigned int const);
    constexpr inline unsigned long number__power(unsigned short const, unsigned long const);
    constexpr inline unsigned short number__power(unsigned short const, unsigned short const);
    inline wide number__power(unsigned short const, wide const);
    inline long double number__power(wide const, double const);
    inline long double number__power(wide const, float const);
    inline wide number__power(wide const, int const);
    inline wide number__power(wide const, long const);
    inline long double number__power(wide const, long double const);
    inline wide number__power(wide const, short const);
    inline wide number__power(wide const, unsigned int const);
    inline wide number__power(wide const, unsigned long const);
    inline wide number__power(wide const, unsigned short const);
    inline wide number__power(wide const, wide const);

    constexpr inline double number__sine(double const);
    constexpr inline float number__sine(float const);
    constexpr inline float number__sine(int const);
    constexpr inline double number__sine(long const);
    inline long double number__sine(long double const);
    constexpr inline float number__sine(short const);
    constexpr inline float number__sine(unsigned int const);
    constexpr inline double number__sine(unsigned long const);
    constexpr inline float number__sine(unsigned short const);
    inline long double number__sine(wide const);

    constexpr inline double number__tangent(double const);
    constexpr inline float number__tangent(float const);
    constexpr inline float number__tangent(int const);
    constexpr inline double number__tangent(long const);
    inline long double number__tangent(long double const);
    constexpr inline float number__tangent(short const);
    constexpr inline float number__tangent(unsigned int const);
    constexpr inline double number__tangent(unsigned long const);
    constexpr inline float number__tangent(unsigned short const);
    inline long double number__tangent(wide const);

    // Pointer ...
    struct pointer__allocate_heap_memory;
    struct pointer__allocate_stack_memory;
    template <typename type> void pointer__free_heap_memory(type* const) noexcept;
    template <typename type> constexpr void pointer__free_stack_memory(type* const) noexcept;
    struct pointer__map_heap_memory;
    struct pointer__reallocate_heap_memory;
    struct pointer__reallocate_stack_memory;
    template <typename type> void pointer__source_copy_memory(type* const, type* const, size_t const) noexcept;
    template <typename type> void pointer__source_move_memory(type* const, type* const, size_t const) noexcept;
    template <typename type> void pointer__unmap_heap_memory(type* const, size_t const) noexcept;
    template <typename type> void pointer__zero_memory(type* const, size_t const) noexcept;

    // String ... --- CHECKPOINT (Lapys)
    bool string__is_empty(char* const) noexcept;
    bool string__is_empty(char const* const) noexcept;
    bool string__is_empty(char8_t* const) noexcept;
    bool string__is_empty(char8_t const* const) noexcept;
    bool string__is_empty(char16_t* const) noexcept;
    bool string__is_empty(char16_t const* const) noexcept;
    bool string__is_empty(char32_t* const) noexcept;
    bool string__is_empty(char32_t const* const) noexcept;
    bool string__is_empty(signed char* const) noexcept;
    bool string__is_empty(signed char const* const) noexcept;
    bool string__is_empty(unsigned char* const) noexcept;
    bool string__is_empty(unsigned char const* const) noexcept;
    bool string__is_empty(wchar_t* const) noexcept;
    bool string__is_empty(wchar_t const* const) noexcept;

    size_t string__length(char* const) noexcept;
    size_t string__length(char const* const) noexcept;
    template <size_t length> size_t string__length(char (&)[length]) noexcept;
    template <size_t length> size_t string__length(char const (&)[length]) noexcept;
    size_t string__length(char8_t* const) noexcept;
    size_t string__length(char8_t const* const) noexcept;
    template <size_t length> size_t string__length(char8_t (&)[length]) noexcept;
    template <size_t length> size_t string__length(char8_t const (&)[length]) noexcept;
    size_t string__length(char16_t* const) noexcept;
    size_t string__length(char16_t const* const) noexcept;
    template <size_t length> size_t string__length(char16_t (&)[length]) noexcept;
    template <size_t length> size_t string__length(char16_t const (&)[length]) noexcept;
    size_t string__length(char32_t* const) noexcept;
    size_t string__length(char32_t const* const) noexcept;
    template <size_t length> size_t string__length(char32_t (&)[length]) noexcept;
    template <size_t length> size_t string__length(char32_t const (&)[length]) noexcept;
    size_t string__length(signed char* const) noexcept;
    size_t string__length(signed char const* const) noexcept;
    template <size_t length> size_t string__length(signed char (&)[length]) noexcept;
    template <size_t length> size_t string__length(signed char const (&)[length]) noexcept;
    size_t string__length(unsigned char* const) noexcept;
    size_t string__length(unsigned char const* const) noexcept;
    template <size_t length> size_t string__length(unsigned char (&)[length]) noexcept;
    template <size_t length> size_t string__length(unsigned char const (&)[length]) noexcept;
    size_t string__length(wchar_t* const) noexcept;
    size_t string__length(wchar_t const* const) noexcept;
    template <size_t length> size_t string__length(wchar_t (&)[length]) noexcept;
    template <size_t length> size_t string__length(wchar_t const (&)[length]) noexcept;

/* Import */
#include "general.cpp" // NOTE (Lapys) -> Define all data interfaces.
#include "shims/primitives.cpp" // NOTE (Lapys) -> Modified self-managed atomic types.
#include "shims/types.cpp" // NOTE (Lapys) -> Modified type interfaces.

#include "shims/definitions.hpp" // NOTE (Lapys) -> Atomic/ minimal development code features and re-definitions.
#include "shims/constants.hpp" // NOTE (Lapys) -> Global utility constants and objects.

/* Main */
void Main(Arguments const);

#if environment__is_linux
int main(int const /*argumentCount*/, char* const /*argumentVector*/[]) {
    // Return
    return EXIT_SUCCESS;
}

#elif environment__is_windows // CHECKPOINT (Lapys) -> Get the directory of the executing script and de-allocate each argument string.
int WinMain(HINSTANCE const /*instanceHandle*/, HINSTANCE const /*previousInstanceHandle*/, LPSTR const /*programInitiationCommandLineArguments*/, int const/*windowAppearance*/) {
    // Return
    return EXIT_SUCCESS;
}

#else
int main(void) {
    // Return
    return EXIT_SUCCESS;
}

#endif
