//
// Created by Ignac on 21/2/2023.
//
//
// Created by Ignac on 21/2/2023.
//
#include "header.hpp"
#include "funtrans/funtrans.hpp"


int main(){
    //cout<<"Hello world";

    //int num = 5;

    cout << std::fixed <<
        funtrans::tanh_t(5).str() << "\n"
        <<
        funtrans::sinh_t(5).str() << "\n"
        <<
        funtrans::cosh_t(5).str();

    return 0;
}