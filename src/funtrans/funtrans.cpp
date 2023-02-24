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

decimal_50_digits funtrans::sin_t(decimal_50_digits x) {
    int n =0;
    decimal_50_digits sk =0;
    decimal_50_digits  sk_1 =0;
    decimal_50_digits error =1;
    for(int i =0; i < iteration_max_t; ++i) {
        sk_1 = sk + (power_t(-1, i) * (power_t(x, 2 * i + 1) * divi_t(factorial_t(2 * i + 1))));
        error = sk_1 - sk;
         if(abs(error) <tol_t){
             cout << std::fixed << error << endl;
            sk = sk_1;
            break;
        }
        else{
            sk = sk_1;
        }
    }
    return sk;
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
