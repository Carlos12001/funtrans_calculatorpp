//
// Created by carlo on 2/16/2023.
//
#include "../header.hpp"
#include "funtrans.hpp"

/**
 * @brief The mathematical constant pi with 50 digits of precision.
 */
const decimal_50_digits funtrans::pi_t =
        3.1415926535897932384626433832795028841971693993751;

/**
 * @brief The tolerance level for numerical computations.
 *
 * This constant is used to determine when the iterative numerical computations
 * have reached a satisfactory level of precision.
 */
const decimal_50_digits funtrans::tol_t = 0.0000000001;

/**
 * @brief The maximum number of iterations allowed for numerical computations.
 *
 * This constant limits the number of iterations that are allowed for iterative
 * numerical
 * computations to avoid infinite loops and excessively long computations.
 */
const int funtrans::iteration_max_t = 2500;

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
decimal_50_digits funtrans::factorial_t(decimal_50_digits x) {
    if (x < 0){
        cout << "Error factorial x<0 " << endl;
        return 1;
    }
    decimal_50_digits result = 1;
    for (int i = 0; i <= iteration_max_t; ++i) {
        if(0==x)
            break;
        result *= x--;
    }
    return result;
}

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
decimal_50_digits funtrans::divi_t(const decimal_50_digits& x) {

    // Check 1/0
    if (x == 0){
        cout << "Error x==0 " << endl;
        return 1;
    }

    decimal_50_digits a_x = abs_t(x);
    int mult = 0 < x ? 1 : -1;

    // Check eps condition
    decimal_50_digits eps = 2.2204 * 0.0000000000000001;
    int exponent_eps = exponent_eps_aux_divi_t(a_x);
    if (exponent_eps==0)
        return 0;

    // Set the x_0 with eps condition
    decimal_50_digits previous_x_k = power_t(eps, exponent_eps);
    decimal_50_digits x_k;

    for (int i = 0; i < iteration_max_t; ++i) {
        x_k = previous_x_k*(2 - a_x * previous_x_k);
        if (abs_t(x_k-previous_x_k) < tol_t*abs_t(x_k))
            break;
        else
            previous_x_k = x_k;
    }
    return mult*x_k;

}

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
decimal_50_digits funtrans::power_t(const decimal_50_digits& x,
                                    const decimal_50_digits& y) {
    decimal_50_digits result = 1;


    // Check unnecessary iterations
    if(x==0 || x== 1)
        return x;

    // Check if y == 0
    if(y==0)
        return 1;

    int valor_entero = static_cast<int>(y);

    // Only works for integers and positives
    if(is_positive_integer(y)){
        for (int i = 0; i < iteration_max_t; ++i){
            if(i >= y)
                break;
            result *= x;
        }
    }
    else if(y==valor_entero){
        return divi_t(power_t(x, abs_t(y)));
    }
    else if(0<x) {
        result = exp_t(y * ln_t(abs_t(x)));
    }
    else {
        cout << "Error para un y decimal x tiene que ser 0<x" << endl;
        return 1;
    }

    return result;
}

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
bool funtrans::is_positive_integer(const decimal_50_digits & x) {
    int valor_entero = static_cast<int>(x);
    return (x == valor_entero) && (valor_entero > 0);
}

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
int funtrans::exponent_eps_aux_divi_t(const decimal_50_digits& x) {
    if (1 <= x && x <= factorial_t(20))
        return 2;
    else if (x <= factorial_t(40))
        return 4;
    else if (x <= factorial_t(60))
        return 8;
    else if (x <= factorial_t(80))
        return 11;
    else if (x <= factorial_t(100))
        return 15;
    else
        return 0;
}

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
decimal_50_digits funtrans::abs_t(const decimal_50_digits& a){
    if (a < 0)
        return -1 * a;
    else
        return a;
}

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
decimal_50_digits funtrans::ln_t(const decimal_50_digits& x) {

    if (x <= 0){
        cout << "Error x<=0 " << endl;
        return 1;
    }

    decimal_50_digits S = 0;
    decimal_50_digits constant = (2 * (x - 1)) * divi_t((x + 1));
    decimal_50_digits S_k;
    decimal_50_digits S_k_1;

    for (int n = 0; n <= iteration_max_t; n++) {

        S_k = divi_t((2*n)+1) *
                power_t(((x - 1) * divi_t(x + 1)), 2 * n);

        S_k_1 = divi_t((2*(n+1))+1) *
                power_t(((x - 1) * divi_t(x + 1)), 2 * (n + 1));

        if (abs_t((constant * S_k_1) - (constant * S_k)) < tol_t)
            return S + (constant * S_k);

        else
            S += (constant * S_k);

    }
    return S;
}

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
decimal_50_digits  funtrans::log_t(const decimal_50_digits& y,
                                   const decimal_50_digits& x){
    if (y > 0 && x > 0){
        auto b = ln_t(y);
        if (y!=1 && b!=0)
            return ln_t(x) * divi_t(b);
        else{
            cout << "Error ln_t(y)==0" << endl;
            return 1;
        }
    }
    cout << "Error y<=0 || x<=0 " << endl;
    return 1;
}

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
decimal_50_digits funtrans::atan_t(const decimal_50_digits& a){
    if (a >= -1 && a <= 1){
        decimal_50_digits S = 0;
        decimal_50_digits S_k;
        decimal_50_digits S_k_1;
        for (int n = 0; n < iteration_max_t; n++) {
            S_k = power_t(-1,n) *
                    (power_t(a, (2*n) + 1)/((2*n) + 1));

            S_k_1 = power_t(-1,n+1) *
                    (power_t(a, (2*(n+1)) + 1)/((2*(n+1)) + 1));
            if (abs_t(S_k_1 - S_k) < tol_t)
                return S;

            else
                S += S_k;
        }
    }
    if (a > 1){
        decimal_50_digits S = 0;
        decimal_50_digits S_k;
        decimal_50_digits S_k_1;
        for (int n = 0; n < iteration_max_t; n++) {
            S_k = power_t(-1, n) * divi_t(((2*n)+1) *
                    power_t(a,(2*n)+1));

            S_k_1 = power_t(-1, n+1) * divi_t(((2*(n+1))+1) *
                    power_t(a,(2*(n+1))+1));
            if (abs_t(S_k_1 - S_k) < tol_t)
                return (pi_t * divi_t(2)) - S;

            else
                S += S_k;

        }
    }
    if (a < -1){
        decimal_50_digits S = 0;
        decimal_50_digits S_k;
        decimal_50_digits S_k_1;

        for (int n = 0; n < iteration_max_t; n++) {
            S_k = pow(-1,n) * (1/((2*n)+1)*
                    (pow(a,(2*n)+1)));

            S_k_1 = pow(-1,(n+1)) * (1/((2*(n+1))+1)*
                    (pow(a,(2*(n+1))+1)));

            if (abs_t(S_k_1 - S_k) < tol_t)
                return (-1 * (pi_t * divi_t(2))) - S;

            else
                S += S_k;
        }
    }
    else{
        cout << "Error x fuera de dominio " << endl;
        return 1;
    }
    cout << "Error x fuera de dominio " << endl;
    return 1;
}

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
decimal_50_digits funtrans::asin_t(const decimal_50_digits& x){
    decimal_50_digits S = 0;
    decimal_50_digits S_k;
    decimal_50_digits S_k_1;
    if (x >= -1 && x <= 1) {
        for (int n = 0; n < iteration_max_t; n++) {

            S_k = (factorial_t(2 * n) *
                    divi_t(power_t(4,n) *
                    power_t(factorial_t(n),2) *
                    ((2 * n) + 1)) * power_t(x, (2 * n) + 1));

            S_k_1 = (factorial_t(2 * (n+1)) *
                    divi_t(power_t(4,n+1) *
                    power_t(factorial_t(n+1),2) *
                    ((2 * (n+1)) + 1)) * power_t(x, (2 * (n + 1)) + 1));

            if(abs_t(S_k_1 - S_k) < tol_t)
                break;

            else
                S += S_k;
        }
        return S;
    }
    else {
        cout << "Error x fuera de dominio " << endl;
        return 1;
    }
}

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
decimal_50_digits funtrans::root_t(const decimal_50_digits& x,
                                   const int& y){
    decimal_50_digits X_k = x * divi_t(2);
    decimal_50_digits X_k_1;
    if (is_positive_integer(y) && y > 2 && y % 2 == 0 && x > 0){
        for (int n = 1; n < iteration_max_t; n++) {
            X_k_1 = X_k - ((power_t(X_k, y) - x) *
                           divi_t(y * power_t(X_k, y - 1)));

            if (abs_t(X_k_1 - X_k) < (tol_t * (X_k_1)))
                return X_k_1;

            X_k = X_k_1;
        }
    }
    else
        return  power_t(x, divi_t(y));
    cout << "Error x o y fuera de dominio " << endl;
    return 1;
}

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
decimal_50_digits funtrans::exp_t(const decimal_50_digits &x) {
    // sk anterior
    decimal_50_digits sk = 0;
    // sk+1
    decimal_50_digits sk_1 = 0;
    for (int i = 0; i < iteration_max_t ; ++i) {
        sk = sk_1;
        sk_1 += power_t(x, i) * divi_t(factorial_t(i));

        if (abs_t(sk_1-sk)<tol_t)
            break;
    }
    return sk;
}

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
decimal_50_digits funtrans::sinh_t(const decimal_50_digits& x){
    decimal_50_digits s_k;
    decimal_50_digits s_k_1;

    for (int n = 0; n < iteration_max_t; n++){
        s_k = s_k_1;
        s_k_1 += power_t(x, 2 * n + 1) * divi_t(factorial_t(2 * n + 1));

        if (abs_t(s_k_1 - s_k) < tol_t)
            return s_k_1;
    }
    return s_k_1;
}

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
decimal_50_digits funtrans::cosh_t(const decimal_50_digits& x){
    decimal_50_digits s_k;
    decimal_50_digits s_k_1;

    for (int n = 0; n < iteration_max_t; n++){
        s_k = s_k_1;
        s_k_1 = s_k_1 + power_t(x, 2 * n) * divi_t(factorial_t(2 * n));

        if (abs_t(s_k_1 - s_k) < tol_t)
            return s_k_1;
    }
    return s_k_1;
}

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
decimal_50_digits funtrans::tanh_t(const decimal_50_digits& x){
    decimal_50_digits result = cosh_t(x);
    if (result != 0)
        return sinh_t(x) * divi_t(result);
    else {
        cout << "Error cosh(x)==0, eso esta fuera de dominio " << endl;
        return 1;
    }
}

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
decimal_50_digits funtrans::sec_t(const decimal_50_digits& x){
    decimal_50_digits result = cos_t(x);
    if (result != 0)
        return 1 * divi_t(result);
    else {
        cout << "Error x=(k*PI)/2 fuera de dominio " << endl;
        return 1;
    }
}

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
decimal_50_digits funtrans::cot_t(const decimal_50_digits& x){
    if(is_mult_pi_divi2(x)|| is_mult_pi(x)){
        cout << "Valor de x no permitido "
                        "(x no puede ser (2k+1)*pi/2) "
                        "(x no puede ser k*pi/2)" << endl;
        return 1;
    }
    decimal_50_digits result = tan_t(x);

    if (result != 0)
        return 1 * divi_t(result);
    else {
        cout << "Error x=(2k+1)*PI/2 fuera de dominio " << endl;
        return 1;
    }
}

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
decimal_50_digits funtrans::sin_t(decimal_50_digits x) {
    x = adjust_inter(x);
    if(is_mult_pi(x))
        return 0 ;
    if(is_mult_pi_divi2(x))
        return static_cast<int>(round(x / (pi_t*decimal_50_digits("0.5"))))%3!=0
               ? 1 : -1;;

    int n =0;
    decimal_50_digits sk =0;
    decimal_50_digits  sk_1 =0;
    decimal_50_digits error =1;
    for(int i =0; i < iteration_max_t; i++) {
        sk_1 = sk + (power_t(-1, i) * (power_t(x, 2 * i + 1) * divi_t(factorial_t(2 * i + 1))));
        error = abs_t(sk_1 - sk);
        if (error < tol_t) {
            sk = sk_1;
            break;
        }
        else
            sk = sk_1;
    }
    return sk;
}

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
decimal_50_digits funtrans::cos_t(decimal_50_digits x) {
    x = adjust_inter(x);
    if(is_mult_pi(x))
        return static_cast<int>(round(x / pi_t))%2!=0
                ? -1 : 1;
    if(is_mult_pi_divi2(x))
        return 0;

    decimal_50_digits sk =1;
    decimal_50_digits  sk_1 =0;
    decimal_50_digits error =1;
    for(int i=1; i < iteration_max_t; ++i){
        sk_1 = sk+ (power_t(-1, i)*(power_t(x,2*i)* divi_t(factorial_t(2*i))));
        error = sk_1 - sk;
        if (abs_t(error) < tol_t) {
            sk = sk_1;
            break;
        }
        else
            sk = sk_1;
    }
    return sk;
}

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
decimal_50_digits funtrans::tan_t(const decimal_50_digits& x) {
    if(funtrans::is_mult_pi_divi2(x)){
        cout << "Valor de x no permitido "
                "(x no puede ser (2k+1)*pi/2)" << endl;
        return 1;
    }
    if (cos_t(x) == 0){
        cout << "Error x=(2k+1)*pi/2 fuera de dominio " << endl;
        return 1;
    }
    else {
        auto s = sin_t(x);
        auto c = divi_t(cos_t(x));
        return s * c;
    }
}

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
decimal_50_digits funtrans::csc_t(decimal_50_digits x) {
    decimal_50_digits result = sin_t(x);
    if (result != 0)
        return 1 * divi_t(result);
    else {
        cout << "Error x=k*PI fuera de dominio " << endl;
        return 1;
    }
}

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
decimal_50_digits funtrans::adjust_inter(decimal_50_digits x) {
    while(x<0 || x>2*pi_t){
        if (x < 0)
            x = x + (2 * pi_t);
        else
            x = x - (2 * pi_t);
    }
    return x;
}

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
decimal_50_digits funtrans::sqrt_t(const decimal_50_digits &x) {
    if(is_positive_integer(x)){
        return power_t(abs_t(x), divi_t(2));
    }
    else{
        cout << "Error x<0 fuera de dominio " << endl;
        return 1;
    }
}

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
decimal_50_digits funtrans::acos_t(const decimal_50_digits& x) {
    if (x >= -1 && x <= 1) {
        int multp = 0 < x ? 1 : -1;
        return pi_t * 0.5 - multp * asin_t(abs(x));
    }
    else {
        cout << "x fuera del dominio, "
                "(x pertenece -1<x<1)" << endl;
        return 1;
    }
}

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
decimal_50_digits funtrans::log10_t(const decimal_50_digits& x) {
    if (x > 0)
        return log_t(10, x);
    cout << "Error x<0 fuera de dominio " << endl;
    return 1;
}

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
decimal_50_digits funtrans::trigonometric_ajust(const decimal_50_digits& x) {
    if(-2*pi_t <= x && x <= 2*pi_t)
        return x;
    else{
        int multp = 0 < x ? 1 : -1;
        decimal_50_digits result = abs(x);
        while(2*pi_t < result)
            result -= 2*pi_t;
        return multp*result;
    }
}

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
bool funtrans::is_mult_pi_divi2(const decimal_50_digits &x) {
    decimal_50_digits mult = funtrans::pi_t * decimal_50_digits("0.5");
    decimal_50_digits diff = abs(x - (round(x / mult) * mult));
    return x!=funtrans::pi_t && (diff < decimal_50_digits("0.000000001") ||
    diff > mult - decimal_50_digits("0.000000001"));
}

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
bool funtrans::notRealNumber(const string &s) {
    std::regex patron(R"(^-?\d+(\.\d+)?$)");
    return !(std::regex_match(s, patron));
}

/**
 * @brief Determines if the input angle `x` is a multiple of pi radians.
 *
 * If the input angle is a multiple of pi, returns `true`. Otherwise, returns
 * `false`.
 *
 * @param x The input angle in radians, as a decimal with 50 digits of precision.
 * @return `true` if the input angle is a multiple of pi, `false` otherwise.
 */
bool funtrans::is_mult_pi(const decimal_50_digits &x) {
    decimal_50_digits mult = funtrans::pi_t;
    decimal_50_digits diff = abs(x - (round(x / mult) * mult));
    return diff < decimal_50_digits("0.000000001") ||
           diff > mult - decimal_50_digits("0.000000001");
}
