#include "mainwindow.h"

#include <QApplication>
//#include <codecvt>

int main(int argc, char *argv[])
{
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);

    setlocale(LC_ALL, "RUSSIAN");


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
