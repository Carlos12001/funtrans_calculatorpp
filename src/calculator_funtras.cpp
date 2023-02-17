#include "header.hpp"
#include "gui/init_gui.hpp"
#include "funtrans/funtrans.hpp"

int main(int argc, char *argv[]){
    cout << funtrans::pi_t.str() << endl;
    cout << funtrans::factorial_t(9) << endl;
    return 0;
}