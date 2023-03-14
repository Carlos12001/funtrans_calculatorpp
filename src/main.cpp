#include "header.hpp"
#include "gui/init_gui.hpp"
#include "test/test_funtras.hpp"

int main(int argc, char *argv[]) {
    Test();
    return InitGUI::start(argc, argv);
    return 0;
}
