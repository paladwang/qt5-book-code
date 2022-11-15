#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;
class QSplashScreen;


class LoginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

//槽函数
private slots:
    void login();

protected:
    void paintEvent(QPaintEvent *event);
    void focusInEvent(QFocusEvent * event);
    bool checkPwd(QString& userin_pwd);

private:
    QLabel *userLabel;
    QLabel *pwdLabel;

    QLineEdit *userEditLine;
    QLineEdit *pwdEditLine;

    QPushButton *loginBtn;
    QPushButton *exitBtn;

    QSplashScreen * splash; //启动画面
};

#endif // LOGINDIALOG_H
