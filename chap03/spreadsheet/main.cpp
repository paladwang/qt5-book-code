#include <QApplication>

#include "mainwindow.h"
#include "widget.h"
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWin;
    //mainWin.show();
    mainWin.setHidden(true);

    ///////////////////////////////////
    //登录
    LoginDialog *dlg = new LoginDialog;
    if (dlg->exec() != QDialog::Accepted)
    {
        return 0;
    }

    mainWin.setHidden(false);
    mainWin.show();
    delete dlg;
    ///////////////////////////////////


    //Widget mainWin;
    //mainWin.show();
    return app.exec();
}
