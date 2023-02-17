#include "header.hpp"
#include "gui/init_gui.hpp"
#include "funtrans/funtrans.hpp"

int main(int argc, char *argv[]){
    cout <<  std::fixed << funtrans::pi_t.str() << endl;
    cout << std::fixed << funtrans::factorial_t(50).str(0) << endl;
    return 0;
}