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

    static decimal_50_digits sin_t(decimal_50_digits x); //Implementado pero con error

    static decimal_50_digits tan_t(decimal_50_digits x); //Implementado pero con error

    static decimal_50_digits cos_t(decimal_50_digits x); //Implementado pero con error

    static decimal_50_digits csc_t(decimal_50_digits x); //Implementado pero con error



private:

    static const decimal_50_digits tol_t;

    static const int iteration_max_t;

    static int exponent_eps_aux_divi_t(decimal_50_digits x);

    static decimal_50_digits adjust_inter(decimal_50_digits x);


};




#endif //FUNTRANS_CALCULATORPP_FUNTRANS_HPP
