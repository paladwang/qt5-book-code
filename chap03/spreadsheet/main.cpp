#include <QApplication>

#include "mainwindow.h"
#include "widget.h"
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ///////////////////////////////////
    //登录
    LoginDialog *dlg = new LoginDialog;
    if (dlg->exec() != QDialog::Accepted)
    {
        return 0;
    }
    delete dlg;
    ///////////////////////////////////

    MainWindow mainWin;
    //Widget mainWin;
    mainWin.show();
    return app.exec();
}
