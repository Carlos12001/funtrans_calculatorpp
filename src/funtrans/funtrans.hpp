//
// Created by carlo on 2/16/2023.
//

#ifndef FUNTRANS_CALCULATORPP_FUNTRANS_HPP
#define FUNTRANS_CALCULATORPP_FUNTRANS_HPP
#include "../header.hpp"
#include <regex>

/**
 * @brief A class that provides mathematical functions and constants, implemented
 *        using decimal precision with 50 digits.
 *
 * The `funtrans` class provides a range of mathematical functions and constants
 * that are implemented using decimal precision with 50 digits. These functions
 * include trigonometric, logarithmic, and exponential functions, as well as
 * functions for calculating roots and factorials. The class also provides
 * several methods for checking the properties of numbers and adjusting input
 * values to be within certain ranges.
 */
class funtrans {
public:

    /**
 * @brief The mathematical constant pi with 50 digits of precision.
 */
    static const decimal_50_digits pi_t;

    /**
 * @brief Compute the factorial of the given decimal number x.
 *
 * This function computes the factorial of the given decimal number x using an
 * iterative
 * approach. If the input x is less than zero, an error message is printed to
 * the console
 * and the function returns 1.
 *
 * @param x The decimal number to compute the factorial of.
 * @return The factorial of the given decimal number x.
 */
    static decimal_50_digits factorial_t(decimal_50_digits x);

    /**
 * @brief Compute the reciprocal of the given decimal number x.
 *
 * This function computes the reciprocal of the given decimal number x using the
 * Newton-Raphson method. If the input x is equal to zero, an error message is
 * printed
 * to the console and the function returns 1. The computation continues until
 * the
 * difference between successive approximations is less than a specified
 * tolerance level.
 *
 * @param x The decimal number to compute the reciprocal of.
 * @return The reciprocal of the given decimal number x.
 */
    static decimal_50_digits divi_t(const decimal_50_digits& a_x);

    /**
 * @brief Compute the power of the given decimal numbers x and y.
 *
 * This function computes the power of the given decimal numbers x and y. If
 * x is zero
 * or one, the result is x. If y is zero, the result is one. If y is a positive
 * integer,
 * the power is computed using an iterative approach. If y is not an integer,
 * the power
 * is computed using the exponential and natural logarithm functions. If x is
 * negative and
 * y is not an integer, an error message is printed to the console and the
 * function
 * returns 1.
 *
 * @param x The base decimal number.
 * @param y The exponent decimal number.
 * @return The power of the given decimal numbers x and y.
 */
    static decimal_50_digits power_t(const decimal_50_digits& x,
                                     const decimal_50_digits& y);

    /**
 * @brief Check if the given decimal number x is a positive integer.
 *
 * This function checks if the given decimal number x is a positive integer.
 * It returns
 * true if x is a positive integer, and false otherwise.
 *
 * @param x The decimal number to check.
 * @return true if the given decimal number x is a positive integer, false
 * otherwise.
 */
    static bool is_positive_integer(const decimal_50_digits & x);

    /**
 * @brief Compute the exponential function of the given decimal number x.
 *
 * This function computes the exponential function of the given decimal number
 * x using the Maclaurin series expansion. If x is a valid input, the result is
 * the value of e raised to the power of x. If x is outside of the valid domain,
 * an error message is printed to the console and the function returns 1.
 *
 * @param x The decimal number to be exponentiated.
 * @return The exponential function of the given decimal number x.
 */
    static decimal_50_digits exp_t(const decimal_50_digits& x);

    /**
 * @brief Compute the natural logarithm of the given decimal number x.
 *
 * This function computes the natural logarithm of the given decimal number x
 * using the
 * Taylor series expansion. If the input x is less than or equal to zero, an
 * error message
 * is printed to the console and the function returns 1. The computation
 * continues until
 * the difference between successive approximations is less than a specified
 * tolerance level.
 *
 * @param x The decimal number to compute the natural logarithm of.
 * @return The natural logarithm of the given decimal number x.
 */
    static decimal_50_digits ln_t(const decimal_50_digits& x);

    /**
 * @brief Compute the logarithm of the given decimal numbers y and x.
 *
 * This function computes the logarithm of the given decimal numbers y and x
 * using the
 * natural logarithm function. If y and x are positive, the result is the
 * natural logarithm
 * of x divided by the natural logarithm of y. If y is 1, an error message
 * is printed to the
 * console and the function returns 1. If y or x is less than or equal to
 * zero, an error
 * message is printed to the console and the function returns 1.
 *
 * @param y The denominator decimal number.
 * @param x The numerator decimal number.
 * @return The logarithm of the given decimal numbers y and x.
 */
    static decimal_50_digits log_t(const decimal_50_digits& y,
                                   const decimal_50_digits& x);

    /**
 * @brief Compute the arctangent of the given decimal number a.
 *
 * This function computes the arctangent of the given decimal number a using
 * the Maclaurin series expansion. If the value of a is within the range
 * [-1, 1], the result is the arctangent of a. If a is greater than 1, the
 * result is pi/2 minus the arctangent of the reciprocal of a. If a is less
 * than -1, the result is negative pi/2 minus the arctangent of the
 * reciprocal of a. If a is outside the range [-1, 1], an error message is
 * printed to the console and the function returns 1.
 *
 * @param a The decimal number whose arctangent will be computed.
 * @return The arctangent of the given decimal number a.
 */
    static decimal_50_digits atan_t(const decimal_50_digits& a);

    /**
 * @brief Compute the yth root of the given decimal number x.
 *
 * This function computes the yth root of the given decimal number x using
 * Newton's method for finding roots. If y is a positive even integer greater
 * than 2 and x is positive, the result is the yth root of x. Otherwise, the
 * function simply computes x to the power of 1/y. If x or y is outside of the
 * valid domain, an error message is printed to the console and the function
 * returns 1.
 *
 * @param x The decimal number whose yth root will be computed.
 * @param y The positive even integer exponent of the root.
 * @return The yth root of the given decimal number x.
 */
    static decimal_50_digits root_t(const decimal_50_digits& x,
                                    const int& y);

    /**
 * @brief Calculates the square root of the input value `x`.
 *
 * If the input value is a positive integer, returns its square root as a
 * decimal with 50 digits of precision. Otherwise, returns an error message
 * and a value of 1.
 *
 * @param x The input value, as a decimal with 50 digits of precision.
 * @return The square root of the input value, as a decimal with 50 digits
 *         of precision, or a value of 1 and an error message if the input
 *         is not valid.
 */
    static decimal_50_digits sqrt_t(const decimal_50_digits& x);

    /**
 * @brief Compute the absolute value of the given decimal number a.
 *
 * This function computes the absolute value of the given decimal number a. If
 * a is negative,
 * the result is the negation of a.
 *
 * @param a The decimal number to compute the absolute value of.
 * @return The absolute value of the given decimal number a.
 */
    static decimal_50_digits abs_t(const decimal_50_digits& a);

    /**
 * @brief Compute the hyperbolic sine function of the given decimal number x.
 *
 * This function computes the hyperbolic sine function of the given decimal
 * number x using the Maclaurin series expansion. If x is a valid input, the
 * result is the hyperbolic sine of x. If x is outside of the valid domain,
 * an error message is printed to the console and the function returns 1.
 *
 * @param x The decimal number whose hyperbolic sine will be computed.
 * @return The hyperbolic sine function of the given decimal number x.
 */
    static decimal_50_digits sinh_t(const decimal_50_digits& x);

    /**
 * @brief Compute the arcsine of the given decimal number x.
 *
 * This function computes the arcsine of the given decimal number x using
 * the Maclaurin series expansion. If x is within the range [-1, 1], the
 * result is the arcsine of x. If x is outside the range [-1, 1], an error
 * message is printed to the console and the function returns 1.
 *
 * @param x The decimal number whose arcsine will be computed.
 * @return The arcsine of the given decimal number x.
 */
    static decimal_50_digits asin_t(const decimal_50_digits& x);

    /**
 * @brief Compute the hyperbolic cosine function of the given decimal number x.
 *
 * This function computes the hyperbolic cosine function of the given decimal
 * number x using the Maclaurin series expansion. If x is a valid input, the
 * result is the hyperbolic cosine of x. If x is outside of the valid domain,
 * an error message is printed to the console and the function returns 1.
 *
 * @param x The decimal number whose hyperbolic cosine will be computed.
 * @return The hyperbolic cosine function of the given decimal number x.
 */
    static decimal_50_digits cosh_t(const decimal_50_digits& x);

    /**
 * @brief Compute the hyperbolic tangent of the given decimal number x.
 *
 * This function computes the hyperbolic tangent of the given decimal number x
 * using
 * the formula tanh(x) = sinh(x) / cosh(x). If cosh(x) is equal to zero, the
 * function returns an error message to the console and returns 1.
 *
 * @param x The decimal number whose hyperbolic tangent is to be computed.
 * @return The hyperbolic tangent of the given decimal number x.
 */
    static decimal_50_digits tanh_t(const decimal_50_digits& x);

    /**
 * @brief Computes the secant of the given decimal number x.
 *
 * This function computes the secant of the given decimal number x using the
 * cosine function. If the cosine of x is not equal to zero, the result is
 * one divided by the cosine of x. If the cosine of x is zero, an error message
 * is printed to the console and the function returns 1.
 *
 * @param x The decimal number.
 * @return The secant of the given decimal number x.
 */
    static decimal_50_digits sec_t(const decimal_50_digits& x);

    /**
 * @brief Computes the cotangent of the given decimal number x.
 *
 * This function computes the cotangent of the given decimal number x using the
 * tangent function. If x is not equal to a multiple of pi/2, the result is
 * one divided by the tangent of x. If x is equal to a multiple of pi/2, an error
 * message
 * is printed to the console and the function returns 1.
 *
 * @param x The decimal number.
 * @return The cotangent of the given decimal number x.
 */
    static decimal_50_digits cot_t(const decimal_50_digits& x);

    /**
 * @brief Compute the sine of the given decimal number x in radians.
 *
 * This function computes the sine of the given decimal number x in radians.
 * If x is a multiple of pi, the function returns 0. If x is a multiple of
 * pi/2,
 * the function returns 1 if x is an odd multiple of pi/2, and -1 if x is an
 * even
 * multiple of pi/2. Otherwise, the function uses the Taylor series to
 * approximate
 * the sine of x, using the desired number of iterations until the desired
 * tolerance
 * is achieved.
 *
 * @param x The input decimal number in radians.
 * @return The sine of the given decimal number x in radians.
 */
    static decimal_50_digits sin_t(decimal_50_digits x);

    /**
 * @brief Calculates the tangent of the input angle `x`, given in radians.
 *
 * If the input angle is an odd multiple of pi/2, returns a value of 1 and
 * prints an error message indicating that the input is not valid. If the
 * cosine of the input angle is 0, returns a value of 1 and prints an error
 * message indicating that the input is outside the domain of the function.
 * Otherwise, calculates the sine and cosine of the input angle and returns
 * their quotient as the result.
 *
 * @param x The input angle in radians, as a decimal with 50 digits of precision.
 * @return The tangent of the input angle, as a decimal with 50 digits of
 * precision,
 *         or a value of 1 and an error message if the input is not valid.
 */
    static decimal_50_digits tan_t(const decimal_50_digits& x);

    /**
 * @brief Computes the cosine of a given decimal value.
 *
 * This function computes the cosine of the given decimal value x in radians.
 * If x is a multiple of pi, the function returns -1 if the quotient is odd and
 * 1 if the quotient is even. If x is a multiple of pi/2, the function returns
 * 0. Otherwise, the function uses the Taylor series to approximate the cosine
 * of x, using the desired number of iterations until the desired tolerance is
 * achieved.
 *
 * @param x The input value in radians.
 * @return The cosine of the input value.
 */
    static decimal_50_digits cos_t(decimal_50_digits x);

    /**
 * @brief Calculates the cosecant of the input angle `x`, given in radians.
 *
 * If the sine of the input angle is 0, returns a value of 1 and prints an error
 * message indicating that the input is outside the domain of the function.
 * Otherwise, calculates the sine of the input angle and returns the reciprocal
 * of the result as the cosecant of the input angle.
 *
 * @param x The input angle in radians, as a decimal with 50 digits of precision.
 * @return The cosecant of the input angle, as a decimal with 50 digits of
 * precision,
 *         or a value of 1 and an error message if the input is not valid.
 */
    static decimal_50_digits csc_t(decimal_50_digits x);

    /**
 * @brief Calculates the arccosine of the input value `x`, given in radians.
 *
 * If the input value falls within the range [-1, 1], returns its arccosine
 * as a decimal with 50 digits of precision. Otherwise, returns an error
 * message and a value of 1.
 *
 * @param x The input value in radians, as a decimal with 50 digits of precision.
 * @return The arccosine of the input value, as a decimal with 50 digits of
 *         precision, or a value of 1 and an error message if the input is
 *         not valid.
 */
    static decimal_50_digits acos_t(const decimal_50_digits& x);

    /**
 * @brief Calculates the base-10 logarithm of the input value `x`.
 *
 * If the input value is positive, returns its base-10 logarithm as a decimal
 * with 50 digits of precision. Otherwise, returns an error message and a
 * value of 1.
 *
 * @param x The input value, as a decimal with 50 digits of precision.
 * @return The base-10 logarithm of the input value, as a decimal with 50
 *         digits of precision, or a value of 1 and an error message if the
 *         input is not valid.
 */
    static decimal_50_digits log10_t(const decimal_50_digits& x);

    /**
 * @brief Adjusts the input angle `x` to the range [-2*pi, 2*pi] radians.
 *
 * If the input angle falls outside this range, subtracts or adds multiples
 * of 2*pi until it falls within this range. Returns the adjusted angle.
 *
 * @param x The input angle in radians, as a decimal with 50 digits of precision.
 * @return The adjusted input angle in the range [-2*pi, 2*pi] radians, as a
 *         decimal with 50 digits of precision.
 */
    static decimal_50_digits trigonometric_ajust(const decimal_50_digits& x);

    /**
 * @brief Determines if the input angle `x` is an odd multiple of pi/2.
 *
 * If the input angle is a multiple of pi/2 that is not equal to pi/2, returns
 * `true`. Otherwise, returns `false`.
 *
 * @param x The input angle in radians, as a decimal with 50 digits of precision.
 * @return `true` if the input angle is an odd multiple of pi/2 and not equal to
 * pi/2,
 *         `false` otherwise.
 */
    static bool is_mult_pi_divi2(const decimal_50_digits& x);

    /**
 * @brief Determines if the input angle `x` is a multiple of pi radians.
 *
 * If the input angle is a multiple of pi, returns `true`. Otherwise, returns
 * `false`.
 *
 * @param x The input angle in radians, as a decimal with 50 digits of precision.
 * @return `true` if the input angle is a multiple of pi, `false` otherwise.
 */
    static bool is_mult_pi(const decimal_50_digits& x);

    /**
 * @brief Determines if the input string `s` represents a real number.
 *
 * If the input string can be parsed as a real number, returns `false`. Otherwise,
 * returns `true`.
 *
 * @param s The input string to check.
 * @return `true` if the input string does not represent a real number, `false`
 *         otherwise.
 */
    static bool notRealNumber(const string& s);

private:

    /**
 * @brief The tolerance level for numerical computations.
 *
 * This constant is used to determine when the iterative numerical computations
 * have reached a satisfactory level of precision.
 */
    static const decimal_50_digits tol_t;

    /**
 * @brief The maximum number of iterations allowed for numerical computations.
 *
 * This constant limits the number of iterations that are allowed for iterative
 * numerical
 * computations to avoid infinite loops and excessively long computations.
 */
    static const int iteration_max_t;

    /**
 * @brief Compute the exponent of the power of ten in the scientific notation
 * of the given decimal number x.
 *
 * This function computes the exponent of the power of ten in the scientific
 * notation of the
 * given decimal number x. The value of the exponent depends on the magnitude
 * of x, and is
 * determined by comparing x to the factorials of various integers.
 *
 * @param x The decimal number to compute the exponent for.
 * @return The exponent of the power of ten in the scientific notation of the
 * given decimal number x.
 */
    static int exponent_eps_aux_divi_t(const decimal_50_digits& x);

    /**
 * @brief Adjusts the input angle `x` to the range [0, 2*pi) radians.
 *
 * If the input angle is outside this range, it is shifted by multiples of
 * 2*pi until it falls within this range. Returns the adjusted angle.
 *
 * @param x The input angle in radians, as a decimal with 50 digits of
 * precision.
 * @return The adjusted input angle in the range [0, 2*pi), as a decimal with
 *         50 digits of precision.
 */
    static decimal_50_digits adjust_inter(decimal_50_digits x);

};




#endif //FUNTRANS_CALCULATORPP_FUNTRANS_HPP
