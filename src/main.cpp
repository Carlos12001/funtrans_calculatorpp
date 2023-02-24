#include "header.hpp"
#include "gui/init_gui.hpp"
#include "funtrans/funtrans.hpp"

int main(int argc, char *argv[]) {
    //cout <<  std::fixed << funtrans::pi_t.str() << endl;
    //cout << std::fixed << funtrans::factorial_t(50).str() << endl;
    //cout << std::fixed << funtrans::power_t(0, 0).str() << endl;
    cout << std::fixed << funtrans::asin_t(0.5).str() << endl;
    return 0;
}