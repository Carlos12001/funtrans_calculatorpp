//
// Created by carlo on 2/16/2023.
//
#include "../header.hpp"
#include "funtrans.hpp"
#include <cmath>

const decimal_50_digits funtrans::pi_t = 3.1415926535897932384626433832795028841971693993751;

const decimal_50_digits funtrans::tol_t = 0.00000001;

const int funtrans::iteration_max_t = 2500;

decimal_50_digits funtrans::factorial_t(decimal_50_digits x) {
    decimal_50_digits result = 1;
    for (int i = 0; i <= iteration_max_t; ++i) {
        if(0==x)
            break;
        result *= x--;
    }
    return result;
}

decimal_50_digits funtrans::divi_t(decimal_50_digits x) {

    // Check 1/0
    if(x==0)
        return 0;

    // Check eps condition
    decimal_50_digits eps = 2.2204 * 0.0000000000000001;
    int exponent_eps = exponent_eps_aux_divi_t(x);
    if (exponent_eps==0)
        return 0;

    // Set the x_0 with eps condition
    decimal_50_digits previous_x_k = power_t(eps, exponent_eps);
    decimal_50_digits x_k;

    for (int i = 0; i < iteration_max_t; ++i) {
        x_k = previous_x_k*(2 - x*previous_x_k);
        if (abs(x_k-previous_x_k) < tol_t*abs(x_k))
            break;
        else
            previous_x_k = x_k;
    }
    return x_k;

}

decimal_50_digits funtrans::power_t(decimal_50_digits x, decimal_50_digits y) {
    decimal_50_digits result = 1;

    // Check unnecessary iterations
    if(x==0 || x== 1)
        return x;

    // Check if y == 0
    if(y==0)
        return 1;


    // Only works for integers and positives
    for (int i = 0; i < iteration_max_t; ++i){
        if(i >= y)
            break;
        result *= x;
    }


    return result;
}

int funtrans::exponent_eps_aux_divi_t(decimal_50_digits x) {
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

decimal_50_digits funtrans::absolute(const decimal_50_digits& num){
    if (num < 0)
        return num * -1;
    return num;
}

/* ---------------- */
/* Function: sinh_t */
/* ---------------- */
decimal_50_digits funtrans::sinh_t(const decimal_50_digits& a){
    decimal_50_digits s_k;
    decimal_50_digits s_k_1;

    for (int n = 0; n < iteration_max_t; n++){
        s_k = s_k_1;
        s_k_1 += power_t(a,2*n+1)  * divi_t(factorial_t(2*n+1));

        if (absolute(s_k_1 - s_k) < tol_t)
            return s_k_1;
    }
    return s_k_1;
}

/* ---------------- */
/* Function: cosh_t */
/* ---------------- */
decimal_50_digits funtrans::cosh_t(const decimal_50_digits& a){
    decimal_50_digits s_k;
    decimal_50_digits s_k_1;

    for (int n = 0; n < iteration_max_t; n++){
        s_k = s_k_1;
        s_k_1 = s_k_1 + power_t(a, 2*n) * divi_t(factorial_t(2*n));

        if (absolute(s_k_1 - s_k) < tol_t)
            return s_k_1;
    }
    return s_k_1;
}

/* ---------------- */
/* Function: tanh_t */
/* ---------------- */
decimal_50_digits funtrans::tanh_t(const decimal_50_digits& a){
    return sinh_t(a) * divi_t(cosh_t(a));
}

/* sec_t */ // Depende de Moya
/*
decimal_50_digits funtrans::sec_t(const decimal_50_digits& a){
    return divi_t(cos_t(a));
}
*/

/* cot_t */ // Depende de Moya
/*
decimal_50_digits funtrans::cot_t(const decimal_50_digits& a){
    return divi_t(tan_t(a));
}
*/