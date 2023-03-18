//
// Created by carlo on 2/16/2023.
//

#ifndef FUNTRANS_CALCULATORPP_FUNTRANS_HPP
#define FUNTRANS_CALCULATORPP_FUNTRANS_HPP
#include "../header.hpp"
#include <regex>

class funtrans {
public:

    static const decimal_50_digits pi_t;

    static decimal_50_digits factorial_t(decimal_50_digits x);

    static decimal_50_digits divi_t(const decimal_50_digits& a_x);

    static decimal_50_digits power_t(const decimal_50_digits& x,
                                     const decimal_50_digits& y);

    static bool is_positive_integer(const decimal_50_digits & x);

    static decimal_50_digits exp_t(const decimal_50_digits& x);

    static decimal_50_digits ln_t(const decimal_50_digits& x);

    static decimal_50_digits log_t(const decimal_50_digits& y,
                                   const decimal_50_digits& x);

    static decimal_50_digits atan_t(const decimal_50_digits& a);

    static decimal_50_digits root_t(const decimal_50_digits& x,
                                    const int& y);

    static decimal_50_digits sqrt_t(const decimal_50_digits& x);

    static decimal_50_digits abs_t(const decimal_50_digits& a);

    static decimal_50_digits sinh_t(const decimal_50_digits& x);

    static decimal_50_digits asin_t(const decimal_50_digits& x);

    static decimal_50_digits cosh_t(const decimal_50_digits& x);

    static decimal_50_digits tanh_t(const decimal_50_digits& x);

    static decimal_50_digits sec_t(const decimal_50_digits& x);

    static decimal_50_digits cot_t(const decimal_50_digits& x);

    static decimal_50_digits sin_t(decimal_50_digits x);

    static decimal_50_digits tan_t(const decimal_50_digits& x);

    static decimal_50_digits cos_t(decimal_50_digits x);

    static decimal_50_digits csc_t(decimal_50_digits x);

    static decimal_50_digits acos_t(const decimal_50_digits& x);

    static decimal_50_digits log10_t(const decimal_50_digits& x);

    static decimal_50_digits trigonometric_ajust(const decimal_50_digits& x);

    static bool check_pi_divi2(const decimal_50_digits& x);

    static bool notRealNumber(const string& s);

private:

    static const decimal_50_digits tol_t;

    static const int iteration_max_t;

    static int exponent_eps_aux_divi_t(const decimal_50_digits& x);

    static decimal_50_digits adjust_inter(decimal_50_digits x);

};




#endif //FUNTRANS_CALCULATORPP_FUNTRANS_HPP
