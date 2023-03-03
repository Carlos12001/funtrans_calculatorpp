//
// Created by carlo on 2/16/2023.
//
#include "../header.hpp"
#include "funtrans.hpp"

#include <utility>

const decimal_50_digits funtrans::pi_t =
        3.1415926535897932384626433832795028841971693993751;

const decimal_50_digits funtrans::tol_t = 0.00000000001;

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
        if (abs_t(x_k-previous_x_k) < tol_t*abs_t(x_k))
            break;
        else
            previous_x_k = x_k;
    }
    return x_k;

}

decimal_50_digits funtrans::power_t(const decimal_50_digits& x,
                                    const decimal_50_digits& y) {
    decimal_50_digits result = 1;


    // Check unnecessary iterations
    if(x==0 || x== 1)
        return x;

    // Check if y == 0
    if(y==0)
        return 1;


    // Only works for integers and positives
    if(is_positive_integer(y)){
        for (int i = 0; i < iteration_max_t; ++i){
            if(i >= y)
                break;
            result *= x;
        }
    }
    else
        result = exp_t(y * ln_t(abs_t(x)));


    return result;
}

bool funtrans::is_positive_integer(const decimal_50_digits & x) {
    int valor_entero = static_cast<int>(x);
    return (x == valor_entero) && (valor_entero > 0);
}


int funtrans::exponent_eps_aux_divi_t(const decimal_50_digits& x) {
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

decimal_50_digits funtrans::abs_t(const decimal_50_digits& a){
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

        S_k = divi_t((2*n)+1) *
                power_t(((a-1)* divi_t(a+1)),2 * n);

        S_k_1 = divi_t((2*(n+1))+1) *
                power_t(((a-1)* divi_t(a+1)),2 * (n+1));

        if (abs_t(( x * S_k_1)-( x * S_k)) < tol_t)
            return S + (x * S_k);

        else
            S += (x * S_k);

    }
    return S;
}

decimal_50_digits  funtrans::log_t(const decimal_50_digits& x,
                                   const decimal_50_digits& y){
    if ( x > 0 && y > 0)
        return ln_t(y) * divi_t(ln_t(x));

    return 0;
}

decimal_50_digits funtrans::atan_t(const decimal_50_digits& a){
    if (a >= -1 && a <= 1){
        decimal_50_digits S = 0;
        decimal_50_digits S_k;
        decimal_50_digits S_k_1;
        for (int n = 0; n < iteration_max_t; n++) {
            S_k = power_t(-1,n) *
                    (power_t(a, (2*n) + 1)/((2*n) + 1));

            S_k_1 = power_t(-1,n+1) *
                    (power_t(a, (2*(n+1)) + 1)/((2*(n+1)) + 1));
            if (abs_t(S_k_1 - S_k) < tol_t)
                return S;

            else
                S += S_k;

        }
    }
    if (a > 1){
        decimal_50_digits S = 0;
        decimal_50_digits S_k;
        decimal_50_digits S_k_1;
        for (int n = 0; n < iteration_max_t; n++) {
            S_k = power_t(-1, n) * divi_t(((2*n)+1) *
                    power_t(a,(2*n)+1));

            S_k_1 = power_t(-1, n+1) * divi_t(((2*(n+1))+1) *
                    power_t(a,(2*(n+1))+1));
            if (abs_t(S_k_1 - S_k) < tol_t)
                return (pi_t * divi_t(2)) - S;

            else
                S += S_k;

        }
    }
    if (a < -1){
        decimal_50_digits S = 0;
        decimal_50_digits S_k;
        decimal_50_digits S_k_1;

        for (int n = 0; n < iteration_max_t; n++) {
            S_k = pow(-1,n) * (1/((2*n)+1)*
                    (pow(a,(2*n)+1)));

            S_k_1 = pow(-1,(n+1)) * (1/((2*(n+1))+1)*
                    (pow(a,(2*(n+1))+1)));

            if (abs_t(S_k_1 - S_k) < tol_t)
                return (-1 * (pi_t * divi_t(2))) - S;

            else
                S += S_k;

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

            S_k = (factorial_t(2 * n) *
                    divi_t(power_t(4,n) *
                    power_t(factorial_t(n),2) *
                    ((2 * n) + 1)) * power_t(a, (2 * n) + 1));

            S_k_1 = (factorial_t(2 * (n+1)) *
                    divi_t(power_t(4,n+1) *
                    power_t(factorial_t(n+1),2) *
                    ((2 * (n+1)) + 1)) * power_t(a, (2 * (n+1)) + 1));

            if(abs_t(S_k_1 - S_k) < tol_t)
                break;

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

decimal_50_digits funtrans::root_t(const decimal_50_digits& a,
                                   const int& p){
    decimal_50_digits X_k = a * divi_t(2);
    decimal_50_digits X_k_1;
    if ( is_positive_integer(p) && p > 2 && p % 2 == 0 && a > 0){
        for (int n = 1; n < iteration_max_t; n++) {
            X_k_1 = X_k - ((power_t(X_k,p)-a) *
                    divi_t(p * power_t(X_k, p-1)));

            if (abs_t(X_k_1 - X_k) < (tol_t * (X_k_1)))
                return X_k_1;

            X_k = X_k_1;
        }
    }
    else
        return  power_t(a, p);

    return 0;
}

decimal_50_digits funtrans::exp_t(const decimal_50_digits &x) {
    // sk anterior
    decimal_50_digits sk = 0;
    // sk+1
    decimal_50_digits sk_1 = 0;
    for (int i = 0; i < iteration_max_t ; ++i) {
        sk = sk_1;
        sk_1 += power_t(x, i) * divi_t(factorial_t(i));

        if (abs_t(sk_1-sk)<tol_t)
            break;
    }
    return sk;
}
/* ---------------- */
/* Function: sinh_t */
/* ---------------- */
decimal_50_digits funtrans::sinh_t(const decimal_50_digits& a){
    decimal_50_digits s_k;
    decimal_50_digits s_k_1;

    for (int n = 0; n < iteration_max_t; n++){
        s_k = s_k_1;
        s_k_1 += power_t(a,2*n+1)  * divi_t(factorial_t(2*n+1));

        if (abs_t(s_k_1 - s_k) < tol_t)
            return s_k_1;
    }
    return s_k_1;
}

/* ---------------- */
/* Function: cosh_t */
/* ---------------- */
decimal_50_digits funtrans::cosh_t(const decimal_50_digits& a){
    decimal_50_digits s_k;
    decimal_50_digits s_k_1;

    for (int n = 0; n < iteration_max_t; n++){
        s_k = s_k_1;
        s_k_1 = s_k_1 + power_t(a, 2*n) * divi_t(factorial_t(2*n));

        if (abs_t(s_k_1 - s_k) < tol_t)
            return s_k_1;
    }
    return s_k_1;
}

/* ---------------- */
/* Function: tanh_t */
/* ---------------- */
decimal_50_digits funtrans::tanh_t(const decimal_50_digits& a){
    return sinh_t(a) * divi_t(cosh_t(a));
}

/* sec_t */
decimal_50_digits funtrans::sec_t(const decimal_50_digits& a){
    return divi_t(cos_t(a));
}


/* cot_t */
decimal_50_digits funtrans::cot_t(const decimal_50_digits& a){
    return divi_t(tan_t(a));
}

decimal_50_digits funtrans::sin_t(decimal_50_digits x) {
    x = adjust_inter(x);
    int n =0;
    decimal_50_digits sk =0;
    decimal_50_digits  sk_1 =0;
    decimal_50_digits error =1;
    for(int i =0; i < iteration_max_t; i++) {
        sk_1 = sk + (power_t(-1, i) * (power_t(x, 2 * i + 1) * divi_t(factorial_t(2 * i + 1))));
        error = abs_t(sk_1 - sk);
        if (error < tol_t) {
            sk = sk_1;
            break;
        }
        else
            sk = sk_1;
    }
    return sk;
}

decimal_50_digits funtrans::cos_t(decimal_50_digits x) {
    x = adjust_inter(x);
    decimal_50_digits sk =1;
    decimal_50_digits  sk_1 =0;
    decimal_50_digits error =1;
    for(int i=1; i < iteration_max_t; ++i){
        sk_1 = sk+ (power_t(-1, i)*(power_t(x,2*i)* divi_t(factorial_t(2*i))));
        error = sk_1 - sk;
        if (abs_t(error) < tol_t) {
            sk = sk_1;
            break;
        }
        else
            sk = sk_1;
    }
    return sk;
}

decimal_50_digits funtrans::tan_t(const decimal_50_digits& x) {
    if (cos_t(x) == 0)
        return 404;
    else
        return sin_t(x) * divi_t(cos_t(x));

}

decimal_50_digits funtrans::csc_t(decimal_50_digits x) {
    decimal_50_digits result = sin_t(std::move(x));
    if (result != 0)
        return 1 * divi_t(result);
    else {
        return 404;
    }

}

decimal_50_digits funtrans::adjust_inter(decimal_50_digits x) {
    while(x<0 || x>2*pi_t){
        if (x < 0)
            x = x + (2 * pi_t);
        else
            x = x - (2 * pi_t);


    }


    return x;

}
