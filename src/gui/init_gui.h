//
// Created by carlo on 2/16/2023.
//

#ifndef FUNTRANS_CALCULATORPP_INITGUI_H
#define FUNTRANS_CALCULATORPP_INITGUI_H

#include "mainwindow.h"
#include "QApplication"


class InitGUI {
public:
    static int start(int argc, char **argv) {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }
};


#endif //FUNTRANS_CALCULATORPP_INITGUI_H
