//
// Created by Ignac on 21/2/2023.
//
//
// Created by Ignac on 21/2/2023.
//
#include <cmath>
#include "header.hpp"
#include "funtrans/funtrans.hpp" // Biblioteca creada

using namespace boost::multiprecision;
/*
float absolute(float num){
    if (num < 0){
        return num * -1;
    }
    return num;
}*/

/* ---------------- */
/* Function: sinh_t */
/* ---------------- */
/*
decimal_50_digits sinh_t(int a){ // Libre
    //float tol = pow(10,-8);
    decimal_50_digits sum = 0;
    //while (abs()> tol){
    for (int n = 0; n < 100; n++){
        //s_k
        //s_k_1
        sum = sum + funtrans::power_t(a,2*n+1)  * funtrans::divi_t(funtrans::factorial_t(2*n+1)); //Not working for 6 and above
        cout << n << " " << sum << " " << std::fixed << funtrans::power_t(a,2*n+1) * funtrans::divi_t(funtrans::factorial_t(2*n+1));
        cout<<"\n";
    }
    return sum;
}*/
/*
decimal_50_digits absolute(decimal_50_digits num){
    if (num < 0)
        return num * -1;
    return num;
}

decimal_50_digits sinh_t(int a){ // Libre
    int max_iteration = 2500;
    double tol = pow(10, -8);

    decimal_50_digits s_k;
    decimal_50_digits s_k_1;

    for (int n = 0; n < 300; n++){
        s_k = s_k_1;
        s_k_1 += funtrans::power_t(a,2*n+1)  * funtrans::divi_t(funtrans::factorial_t(2*n+1));

        if (absolute(s_k_1 - s_k) < tol)
            return s_k_1;
    }
    return s_k_1;
    //return sum;
}

/* ---------------- */
/* Function: cosh_t */
/* ---------------- *//*
decimal_50_digits cosh_t(int a){ // Libre
    int max_iteration = 2500;
    //decimal_50_digits tol = funtrans::power_t(10,-8);
    double tol = pow(10, -8);
    decimal_50_digits s_k;
    decimal_50_digits s_k_1;

    for (int n = 0; n < max_iteration; n++){
        //s_k = s_k + funtrans::power_t(a, 2*n) * funtrans::divi_t(funtrans::factorial_t(2*n));
        s_k = s_k_1;
        s_k_1 = s_k_1 + funtrans::power_t(a, 2*n) * funtrans::divi_t(funtrans::factorial_t(2*n));
        //cout << n << " " << s_k << " " << s_k_1 << "\n";
        if (absolute(s_k_1 - s_k) < tol)
            return s_k_1;
        //sum = sum + pow(a, 2*n) * funtrans::divi_t(funtrans::factorial_t(2*n));
    }
    return s_k_1;
}

/* ---------------- */
/* Function: cosh_t */
/* ---------------- *//*
decimal_50_digits tanh_t(int a){ //Depende de otras
    return sinh_t(a) * funtrans::divi_t(cosh_t(a));
}

/* sec_t */ // Depende de otras
/*
decimal_50_digits sec_t(int a){
    return funtrans::divi_t(cos_t(a));
}
*/

/* cot_t */ // Depende de otras
/*
decimal_50_digits cot_t(int a){
    return funtrans::divi_t(tan_t(a));
}
*/

int main(){
    //cout<<"Hello world";

    //int num = 5;

    cout << std::fixed <<
        funtrans::tanh_t(5).str() << "\n" //setprecision(numeric_limits<float>::digits10)
        <<
        funtrans::sinh_t(5).str() << "\n"
        <<
        funtrans::cosh_t(5).str();

    return 0;
}