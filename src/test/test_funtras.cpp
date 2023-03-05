//
// Created by carlo on 3/4/2023.
//

#include "test_funtras.hpp"

Test::Test(){
    all();
    cout << "--------- Prueba --------" << endl << endl
         << fixed << test_funtras().str() << endl;
}

void Test::all() {
    ostringstream oss;
    oss.precision(50);
    cout <<  fixed
    << "pi_t = " << funtrans::pi_t.str() << endl
    << "factorial_t(50) = " << funtrans::factorial_t(50).str() << endl
    << "divi_t(47) = " << funtrans::divi_t(47).str() << endl
    << "exp_t(8) = " << funtrans::exp_t(8).str() << endl
    << endl << "----------------------------------------------------" << endl
    << "sin_t(47.0 * funtrans::divi_t(230.0) = "<< funtrans::sin_t(47.0 *
    funtrans::divi_t(230.0)).str() << endl
    << "sin_t(0.0) = "<< funtrans::sin_t(0.0).str() << endl
    << "sin_t(pi_t * funtrans::divi_t(2.0) = "<<
    funtrans::sin_t(funtrans::pi_t * funtrans::divi_t(2.0)).str() << endl
    << "cos_t(47.0 * funtrans::divi_t(230.0) = "<< funtrans::cos_t(47.0 *
    funtrans::divi_t(230.0)).str() << endl
    << "cos_t(0.0) = "<< funtrans::cos_t(0.0).str() << endl;

    oss << fixed <<  funtrans::cos_t(funtrans::pi_t *
    funtrans::divi_t(2.0)).str();
    cout << "cos_t(pi_t * funtrans::divi_t(2.0) = " << oss.str() << endl

    << "tan_t(47.0 * funtrans::divi_t(230.0) = "<< funtrans::tan_t(47.0 *
    funtrans::divi_t(230.0)).str() << endl
    << "tan_t(0.0) = "<< funtrans::tan_t(0.0).str() << endl
    << "tan_t(pi_t * funtrans::divi_t(4.0) = "<<
    funtrans::tan_t(funtrans::pi_t * funtrans::divi_t(4.0)).str() << endl
    << endl << "----------------------------------------------------" << endl
    << "ln_t(pi_t) = " << funtrans::ln_t(funtrans::pi_t).str() << endl
    << "ln_t(7) = " << funtrans::ln_t(7).str() << endl
    << "log_t(2, 16) = " << funtrans::log_t(2,16).str() << endl
    << "ln_t(0.5) = " << funtrans::ln_t(0.5) << endl
    << "log_t(1.0 * funtrans::divi_t(2.0, 10.0 * funtrans::divi_t(3.0) = " <<
    funtrans::log_t(0.5,10.0 * funtrans::divi_t(3.0)).str() << endl
    << endl << "----------------------------------------------------" << endl
    <<  "power_t(0, 0) = " << funtrans::power_t(0, 0).str() << endl
    <<  "power_t(109, 5) = " << funtrans::power_t(109, 5).str() << endl
    << "power_t(funtrans::pi_t, 5.0  * funtrans::divi_t( 2.0) = "<<
    funtrans::power_t(funtrans::pi_t, 5.0  *
    funtrans::divi_t( 2.0)).str() << endl
    << endl << "----------------------------------------------------" << endl
            << "sinh_t(5) = " << funtrans::sinh_t(5).str() << endl
            << "sinh_t(14.0 * funtrans::divi_t(3.0) = " << funtrans::sinh_t(14.0 *
    funtrans::divi_t(3.0)).str() << endl
            << "cosh_t(5) = " << funtrans::cosh_t(5).str() << endl
            << "cosh_t(14.0 * funtrans::divi_t(3.0) = " << funtrans::cosh_t(14.0 *
    funtrans::divi_t(3.0)).str() << endl
            << "tanh_t(5) = " << funtrans::tanh_t(5).str() << endl
            << "tanh_t(14.0 * funtrans::divi_t(3.0) = " << funtrans::tanh_t(14.0 *
    funtrans::divi_t(3.0)).str() << endl
            << endl << "----------------------------------------------------" << endl
            << "sqrt_t(47) = " << funtrans::sqrt_t(47).str() << endl
    << "root_t(64, 6) = " << funtrans::root_t(64, 6).str() << endl
    << "root_t(34, 9) = " << funtrans::root_t(34, 9).str() << endl
    << endl << "----------------------------------------------------" << endl
    << "asin_t(0.5) = " << funtrans::asin_t(0.5).str() << endl
    << "atan_t(0.5) = " << funtrans::atan_t(0.5).str() << endl
    << endl << "----------------------------------------------------" << endl
    << "csc_t(47.0 * funtrans::divi_t(230.0) = " << funtrans::csc_t(47.0 *
    funtrans::divi_t(230.0)).str() << endl
    << "sec_t(47.0 * funtrans::divi_t(230.0) = "<< funtrans::sec_t(47.0 *
    funtrans::divi_t(230.0)).str() << endl
    << "cot_t(47.0 * funtrans::divi_t(230.0) = " << funtrans::cot_t(47.0 *
    funtrans::divi_t(230.0)).str() << endl;
}

decimal_50_digits Test::test_funtras() {
    //(root(cos(3/7)+ln(2), 3))/sinh(sqrt_t(2)) + arctan(e^-1)
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
