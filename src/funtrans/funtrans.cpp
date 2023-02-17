//
// Created by carlo on 2/16/2023.
//
#include "../header.hpp"
#include "funtrans.hpp"

const decimal_50_digits funtrans::pi_t = 3.1415926535897932384626433832795028841971693993751;

const decimal_50_digits funtrans::tol_t = 0.00000001;

const int funtrans::iteration_max_t = 2500;

decimal_50_digits funtrans::factorial_t(decimal_50_digits x) {
    decimal_50_digits result = 1;
    for (int i = 0; 0 < x && i <= iteration_max_t; ++i)
        result *= x--;
    return result;
}

//decimal_50_digits funtrans::divi_t(decimal_50_digits x) {
//    decimal_50_digits result = 0;
//    int iteration_counter = 0;
//
//    decimal_50_digits eps = 2.2204 * 0.0000000000000001;
//
//    return result;
//}
//
//decimal_50_digits funtrans::power_t(decimal_50_digits x, decimal_50_digits y) {
//    decimal_50_digits result = x;
//
//    // Check unnecessary iterations
//    if(x==0 || x== 1)
//        return x;
//
//    // Check if y == 0
//    if(y==0)
//        return 1;
//
//    // Check if y is an integer and positive
//    if (std::is_integral<decltype(y)>::value && y > 0) {
//        for (int i = 0; i < y && i < iteration_max_t; ++i)
//            result *= result;
//    } else {
//
//    }
//
//    return result;
//}
