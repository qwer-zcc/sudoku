#include "mainwindow.h"
#include <QApplication>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>

int main(int argc, char *argv[])
{
    srand(unsigned(time(0)));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
