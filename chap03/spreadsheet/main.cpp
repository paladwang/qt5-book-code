#include <QApplication>

#include "mainwindow.h"
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWin;
    //Widget mainWin;
    mainWin.show();
    return app.exec();
}
