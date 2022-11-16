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
    QRect deskRect = QGuiApplication::screens().at(0)->availableGeometry();
    int width = deskRect.width()/2;
    int heigth = deskRect.height()/2;
    QPoint point(width-width/6,heigth);

    LoginDialog *dlg = new LoginDialog;
    //dlg->show();
    dlg->move(point); //要移动对话框(任何框)的位置,要在show之后,或者exec之前
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
