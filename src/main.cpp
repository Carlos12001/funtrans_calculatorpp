#include "header.hpp"
#include "gui/init_gui.hpp"
#include "funtrans/funtrans.hpp"

int main(int argc, char *argv[]) {
//    cout <<  std::fixed << funtrans::pi_t.str() << endl;
//    cout << std::fixed << funtrans::factorial_t(50).str() << endl;
//    cout << std::fixed << funtrans::power_t(0, 0).str() << endl;
//    cout << std::fixed << funtrans::log_t(2,16).str() << endl;
//    cout << std::fixed << funtrans::exp_t(2).str() << endl;
//    cout << std::fixed << funtrans::root_t(64, 6).str() << endl;
//    if(funtrans::is_positive_integer(3.3124451245))
//        cout << "Es positivo entero!" << endl;
//    else
//        cout << "No es positivo entero." << endl;
    cout << fixed << funtrans::power_t(funtrans::pi_t, 5.0 / 2.0).str() << endl;


    return 0;
}