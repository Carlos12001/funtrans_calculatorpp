#include "header.hpp"
#include "gui/init_gui.hpp"
#include "test/test_funtras.hpp"

/**
 * The main function of the program.
 *
 * This function calls the `Test()` function to perform some tests,
 * then calls the `start()`
 * function of the `InitGUI` class to initialize the graphical user
 * interface (GUI).
 *
 * @param[in] argc The number of command-line arguments.
 * @param[in] argv An array of strings containing the command-line arguments.
 * @return The exit code of the program.
 */
int main(int argc, char *argv[]) {
    Test();
    return InitGUI::start(argc, argv);
    return 0;
}
