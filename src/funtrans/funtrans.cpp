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
    for (int i = 0; i <= iteration_max_t; ++i) {
        if(0==x)
            break;
        result *= x--;
    }
    return result;
}

decimal_50_digits funtrans::divi_t(const decimal_50_digits& x) {

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

decimal_50_digits funtrans::power_t(const decimal_50_digits& x, const decimal_50_digits& y) {
    decimal_50_digits result = 1;

    // e^x y In x y = -1/5

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
    return 0;
}

decimal_50_digits  funtrans::abs_t(const decimal_50_digits& a){
    if (a < 0)
        return -1 * a;
    else
        return a;
}

decimal_50_digits funtrans::ln_t(const decimal_50_digits& a) {
    decimal_50_digits S = 0;
    decimal_50_digits x = (2 * (a - 1)) * divi_t((a + 1));
    decimal_50_digits S_k;
    decimal_50_digits S_k_1;

    for (int n = 0; n <= iteration_max_t; n++) {

        S_k = divi_t((2*n)+1) * power_t(((a-1)* divi_t(a+1)),2 * n);
        S_k_1 = divi_t((2*(n+1))+1) * power_t(((a-1)* divi_t(a+1)),2 * (n+1));

        if (abs_t(( x * S_k_1)-( x * S_k)) < tol_t){
            return S + (x * S_k);
        }
        else{
            S += (x * S_k);
        }
    }
    return S;
}

decimal_50_digits  funtrans::log_t(decimal_50_digits x,decimal_50_digits y){
    if ( x > 0 && y > 0){
        cout << "LOG: " << endl;
        return ln_t(y) * divi_t(ln_t(x));
    }
    cout << "Los valores de X y y deben ser mayores a 0" << endl;
    return 0;
}

decimal_50_digits funtrans::atan_t(const decimal_50_digits& a){
    if (a >= -1 && a <= 1){
        decimal_50_digits S = 0;
        decimal_50_digits S_k;
        decimal_50_digits S_k_1;
        for (int n = 0; n < iteration_max_t; n++) {
            S_k = power_t(-1,n) * (power_t(a, (2*n) + 1)/((2*n) + 1));
            S_k_1 = power_t(-1,n+1) * (power_t(a, (2*(n+1)) + 1)/((2*(n+1)) + 1));
            if (abs(S_k_1 - S_k) < tol_t){
                return S;
            }
            else{
                S += S_k;
            }
        }
    }
    if (a > 1){
        decimal_50_digits S = 0;
        decimal_50_digits S_k;
        decimal_50_digits S_k_1;
        for (int n = 0; n < iteration_max_t; n++) {
            S_k = power_t(-1, n) * divi_t(((2*n)+1) * power_t(a,(2*n)+1));
            S_k_1 = power_t(-1, n+1) * divi_t(((2*(n+1))+1) * power_t(a,(2*(n+1))+1));
            if (abs(S_k_1 - S_k) < tol_t){
                return (pi_t * divi_t(2)) - S;
            }
            else{
                S += S_k;
            }
        }
    }
    if (a < -1){
        decimal_50_digits S = 0;
        decimal_50_digits S_k;
        decimal_50_digits S_k_1;
        for (int n = 0; n < iteration_max_t; n++) {
            S_k = pow(-1,n) * (1/((2*n)+1)*(pow(a,(2*n)+1)));
            S_k_1 = pow(-1,(n+1)) * (1/((2*(n+1))+1)*(pow(a,(2*(n+1))+1)));
            if (abs(S_k_1 - S_k) < tol_t){
                return (-1 * (pi_t * divi_t(2))) - S;
            }
            else{
                S += S_k;
            }
        }
    }
    else{
        cout << "Valor fuera del dominio de la función" << endl;
    }
    return 0;
}

decimal_50_digits funtrans::asin_t(const decimal_50_digits& a){
    decimal_50_digits S = 0;
    decimal_50_digits S_k;
    decimal_50_digits S_k_1;
    if (a >= -1 && a <= 1) {
        for (int n = 0; n < iteration_max_t; n++) {
            S_k = (factorial_t(2 * n) * divi_t(power_t(4,n) * power_t(factorial_t(n),2) * ((2 * n) + 1)) * power_t(a, (2 * n) + 1));
            S_k_1 = (factorial_t(2 * (n+1)) * divi_t(power_t(4,n+1) * power_t(factorial_t(n+1),2) * ((2 * (n+1)) + 1)) * power_t(a, (2 * (n+1)) + 1));
            cout << "S_k: " << S_k.str() << endl;
            cout << "S_k_1: " << S_k_1.str() << endl;
            if(abs(S_k_1 - S_k) < tol_t){
                break;
            }
            else{
                S += S_k;
                cout << "S: " << S.str() << endl;
            }
        }
        return S;
    }
    else{
        cout << "Valor fuera del dominio de la funcion" << endl;
        return 0;
    }

}

decimal_50_digits funtrans::root_t(const decimal_50_digits& a, const int& p){
    decimal_50_digits X_k = a * divi_t(2);
    decimal_50_digits X_k_1;;
    if ( p > 2 && p % 2 == 0 && a > 0){
        for (int n = 1; n < iteration_max_t; n++) {
            X_k_1 = X_k - ((power_t(X_k,p)-a) *
                    divi_t(p * power_t(X_k, p-1)));

            if (abs_t(X_k_1 - X_k) < (tol_t * (X_k_1)))
                return X_k_1;

            X_k = X_k_1;
        }
    }
    else{
        cout << "P debe ser mayor a 2" << endl;
        //power_t(a, p);
        return 0;
    }
    return 0;
}



