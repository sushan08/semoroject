#include <iostream>
#include <string>
#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char** argv) {

    QApplication a(argc,argv);
    MainWindow w;
    w.setWindowTitle("Currency bois");
    w.show();

    return a.exec();
}
