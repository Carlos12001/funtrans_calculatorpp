//
// Created by carlo on 2/16/2023.
//

#ifndef FUNTRANS_CALCULATORPP_FUNTRANS_HPP
#define FUNTRANS_CALCULATORPP_FUNTRANS_HPP
#include "../header.hpp"

class funtrans {
public:

    static const decimal_50_digits pi_t;

    static decimal_50_digits factorial_t(decimal_50_digits x);

    static decimal_50_digits divi_t(const decimal_50_digits& x);

    static decimal_50_digits power_t(const decimal_50_digits& x, const decimal_50_digits& y);

    static decimal_50_digits ln_t(const decimal_50_digits& a);

    static decimal_50_digits log_t(const decimal_50_digits& x, const decimal_50_digits& y);

    static decimal_50_digits atan_t(const decimal_50_digits& a);

    static decimal_50_digits root_t(const decimal_50_digits& a, const int& p);

    static decimal_50_digits abs_t(const decimal_50_digits& a);

    static decimal_50_digits asin_t(const decimal_50_digits& a);

private:

    static const decimal_50_digits tol_t;

    static const int iteration_max_t;

    static int exponent_eps_aux_divi_t(const decimal_50_digits& x);

};




#endif //FUNTRANS_CALCULATORPP_FUNTRANS_HPP
