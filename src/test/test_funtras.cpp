//
// Created by carlo on 3/4/2023.
//

#include "test_funtras.hpp"

Test::Test(){
//    all();
    cout << "--------- Prueba --------" << endl << endl
         << fixed << test_funtras().str() << endl;
}

void Test::all() {
    cout <<  fixed << setprecision(8)
    << "pi_t = " << funtrans::pi_t << endl
    << "factorial_t(50) = " << funtrans::factorial_t(50)    << endl
    << "divi_t(-47) = " << funtrans::divi_t(-47)    << endl
    << "exp_t(-8) = " << funtrans::exp_t(-8)    << endl
    << endl << "----------------------------------------------------" << endl
    << "sin_t(-47.0 * funtrans::divi_t(230.0) = "<< funtrans::sin_t(-47.0 *
    funtrans::divi_t(230.0))    << endl
    << "sin_t(0.0) = "<< funtrans::sin_t(0.0)    << endl
    << "sin_t(pi_t * funtrans::divi_t(2.0) = "<<
    funtrans::sin_t(funtrans::pi_t * funtrans::divi_t(2.0))    << endl
    << "cos_t(8.50) = "<< funtrans::cos_t(8.5)    << endl
    << "cos_t(-5) = "<< funtrans::cos_t(-5)    << endl;


    cout << "cos_t(pi_t * 0.5) = " <<
    funtrans::cos_t(funtrans::pi_t * 0.5)
    << endl

    << "tan_t(pi_t * funtrans::divi_t(2.0) + 0.2) = "<<
    funtrans::tan_t(funtrans::pi_t *
        funtrans::divi_t(2.0) + 0.2)    << endl
    << "tan_t(0.0) = "<< funtrans::tan_t(0.0)    << endl
    << "tan_t(pi_t * funtrans::divi_t(4.0) = "<<
    funtrans::tan_t(funtrans::pi_t * funtrans::divi_t(4.0))    << endl

    << endl << "----------------------------------------------------" << endl

    << "ln_t(pi_t) = " << funtrans::ln_t(funtrans::pi_t)    << endl
    << "ln_t(7) = " << funtrans::ln_t(7)    << endl
    << "log_t(2, 16) = " << funtrans::log_t(2,16)    << endl
    << "log_t(2, 0.3) = " << funtrans::log_t(2,0.3)    << endl
    << "ln_t(0.5) = " << funtrans::ln_t(0.5) << endl
    << "log_t(1.0 * funtrans::divi_t(2.0, 10.0 * funtrans::divi_t(3.0) = " <<
    funtrans::log_t(0.5,10.0 * funtrans::divi_t(3.0))    << endl

    << endl << "----------------------------------------------------" << endl

    <<  "power_t(0, 0) = " << funtrans::power_t(0, 0)    << endl
    <<  "power_t(109, 5) = " << funtrans::power_t(109, 5)    << endl
    << "power_t(funtrans::pi_t, -5.0  * funtrans::divi_t( 2.0) = "<<
    funtrans::power_t(funtrans::pi_t, -5.0  *
    funtrans::divi_t( 2.0))    << endl
    <<  "power_t(2, -5) = "
    << funtrans::power_t(2, -5)      << endl
            <<  "power_t(-9, 2) = "
            << funtrans::power_t(-9, 2)      << endl
            <<  "power_t(-2, 5) = "
            << funtrans::power_t(-2, 5)    << endl

            <<  "power_t(2, -2) = "
            << funtrans::power_t(2, -2)    << endl

    << endl << "----------------------------------------------------" << endl

            << "sinh_t(5) = " << funtrans::sinh_t(5)    << endl
            << "sinh_t(-12) = " << funtrans::sinh_t(-12)    << endl


            << "cosh_t(5) = " << funtrans::cosh_t(5)    << endl
            << "cosh_t(-12) = " << funtrans::cosh_t(-12)    << endl

            << "tanh_t(5) = " << funtrans::tanh_t(5)    << endl
            << "tanh_t(-12) = " << funtrans::tanh_t(-12)    << endl

    << endl << "----------------------------------------------------" << endl
    << "sqrt_t(47) = " << funtrans::sqrt_t(47)    << endl
    << "root_t(64, 6) = " << funtrans::root_t(64, 6)    << endl
    << "root_t(34, 9) = " << funtrans::root_t(34, 9)    << endl

    << endl << "----------------------------------------------------" << endl
    << "asin_t(-0.5) = " << funtrans::asin_t(-0.5)    << endl
    << "acos_t(-0.5) = " << funtrans::acos_t(-0.5)    << endl
    << "atan_t(-0.5) = " << funtrans::atan_t(-0.5)    << endl
    << endl << "----------------------------------------------------" << endl
    << "csc_t(-13.5) = " << funtrans::csc_t(-13.5)    << endl
    << "sec_t(-14.5) = "<< funtrans::sec_t(-14.5)    << endl
    << "cot_t(funtrans::pi_t *\n"
       "        funtrans::divi_t(2.0) + 0.2)"
       " = " << funtrans::cot_t(funtrans::pi_t *
                                funtrans::divi_t(2.0) + 0.2)    << endl;
}

decimal_50_digits Test::test_funtras() {
    cout << "(root(cos(3/7)+ln(2),  3))/sinh(sqrt(2)) + arctan(1/e) = \n";
    decimal_50_digits result =
    funtrans::root_t(
            funtrans::cos_t((3 * funtrans::divi_t(7))) +
            funtrans::ln_t(2)
    , 3)
    *
    funtrans::divi_t(funtrans::sinh_t(funtrans::sqrt_t(2)))
    +
    funtrans::atan_t(funtrans::divi_t(funtrans::exp_t(1)));
    return result;
}
