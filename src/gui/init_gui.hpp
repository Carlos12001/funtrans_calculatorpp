//
// Created by carlo on 2/16/2023.
//

#ifndef FUNTRANS_CALCULATORPP_INITGUI_H
#define FUNTRANS_CALCULATORPP_INITGUI_H

#include "mainwindow.hpp"
#include <QApplication>

/**
 * A class that provides a method for initializing the GUI for a
 * Qt-based application.
 *
 * This class includes a single method, `start()`, which initializes a
 * `QApplication` object and a
 * `MainWindow` object, shows the main window, and starts the Qt event loop.
 * The method takes two
 * arguments: `argc`, an integer representing the number of command-line
 * arguments passed to the
 * application, and `argv`, an array of strings containing the command-line
 * arguments.
 *
 * Note that this class relies on the Qt library and requires that
 * `QApplication` and `MainWindow` be
 * properly defined and included in the application.
 *
 * @param argc An integer representing the number of command-line
 * arguments passed to the application.
 * @param argv An array of strings containing the command-line arguments.
 * @return An integer representing the exit code of the application.
 *
 * @see QApplication
 * @see MainWindow
 */
class InitGUI {
public:

    /**
     * Initializes the GUI for a Qt-based application.
     *
     * This method initializes a `QApplication` object and a `MainWindow`
     * object, shows the main window,
     * and starts the Qt event loop. The method takes two arguments: `argc`,
     * an integer representing the
     * number of command-line arguments passed to the application, and `argv`,
     * an array of strings
     * containing the command-line arguments.
     *
     * Note that this method relies on the Qt library and requires that
     * `QApplication` and `MainWindow`
     * be properly defined and included in the application.
     *
     * @param argc An integer representing the number of command-line
     * arguments passed to the application.
     * @param argv An array of strings containing the command-line arguments.
     * @return An integer representing the exit code of the application.
     *
     * @see QApplication
     * @see MainWindow
     */
    static int start(int argc, char **argv) {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }
};


#endif //FUNTRANS_CALCULATORPP_INITGUI_H
