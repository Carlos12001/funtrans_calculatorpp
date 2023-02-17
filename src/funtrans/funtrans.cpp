//
// Created by carlo on 2/16/2023.
//
#include "../header.hpp"
#include "funtrans.hpp"

const decimal_50_digits funtrans::pi_t = 3.1415926535897932384626433832795028841971693993751;
const decimal_50_digits funtrans::tol_t = 0.00000001;

decimal_50_digits funtrans::divi_t(decimal_50_digits number) {
    return decimal_50_digits();
}

decimal_50_digits funtrans::factorial_t(decimal_50_digits number) {
    decimal_50_digits result = 1;
    while(number!=0)
        result *= number--;
    return result;
}
