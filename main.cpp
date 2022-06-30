/*
 *
 * Autoren: Rene Meier,Adrian Musella, Fanjun
 * Version:16.01.2018
 *
 */

#include "mainwindow.h"
#include <QApplication>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

