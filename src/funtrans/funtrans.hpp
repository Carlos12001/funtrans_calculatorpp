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

    static decimal_50_digits divi_t(decimal_50_digits x);

    static decimal_50_digits power_t(decimal_50_digits x, decimal_50_digits y);

    static decimal_50_digits absolute(const decimal_50_digits& num);

    static decimal_50_digits sinh_t(const decimal_50_digits& a);

    static decimal_50_digits cosh_t(const decimal_50_digits& a);

    static decimal_50_digits tanh_t(const decimal_50_digits& a);

    static decimal_50_digits sec_t(const decimal_50_digits& a);

    static decimal_50_digits cot_t(const decimal_50_digits& a);

private:

    static const decimal_50_digits tol_t;

    static const int iteration_max_t;

    static int exponent_eps_aux_divi_t(decimal_50_digits x);

};




#endif //FUNTRANS_CALCULATORPP_FUNTRANS_HPP
