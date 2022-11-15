#include "logindialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QPainter>
#include <QSplashScreen>
#include <QGuiApplication>
#include <QScreen>
#include <QCryptographicHash>

LoginDialog::LoginDialog(QWidget *parent):QDialog(parent)
{
    userLabel = new QLabel(this);
    userLabel->move(70, 80);
    userLabel->setText(tr("用户名"));

    userEditLine = new QLineEdit(this);
    userEditLine->move(140, 80);
    userEditLine->setPlaceholderText(tr("请输入用户名"));

    pwdLabel = new QLabel(this);
    pwdLabel->move(70, 130);
    pwdLabel->setText(tr("密码"));

    pwdEditLine = new QLineEdit(this);
    pwdEditLine->move(140, 130);
    pwdEditLine->setPlaceholderText(tr("请输入密码"));

    loginBtn = new QPushButton(this);
    loginBtn->move(50, 200);
    loginBtn->setText(tr("登录"));

    exitBtn = new QPushButton(this);
    exitBtn->move(210, 200);
    exitBtn->setText(tr("退出"));

    //信号与槽关联
    connect(loginBtn, &QPushButton::clicked, this, &LoginDialog::login);
    connect(exitBtn, &QPushButton::clicked, this, &LoginDialog::close);

    setWindowFlags(Qt::FramelessWindowHint);    //设置无边框窗体
    setAttribute(Qt::WA_TranslucentBackground, true);   //设置透明背景 painter重绘实现

    //设置启动背景
    //设置启动动画代替背景色
    this->splash = new QSplashScreen;
    QPixmap pixmap(":/images/win10.jpg");
    QRect deskRect = QGuiApplication::screens().at(0)->availableGeometry();//默认启动程序在屏幕居中显示
    QPixmap m_pixmap = pixmap.scaled(deskRect.width() , deskRect.height() );
    splash->setPixmap(m_pixmap);
    splash->show();

    /*
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash->showMessage(QObject::tr("Setting up the main window...") , topRight , Qt::white);

    Qt::Alignment center = Qt::AlignCenter;
    QFont font;
    font.setPointSize(48);
    splash->setFont(font);
    splash->showMessage(QObject::tr("welcome to iESlab DDC") , center , Qt::white);


    MainWindow w;
    w.showMaximized();
    w.setFixedSize(w.width(),w.height());

    splash->finish(&w);
    delete splash; */

}

void LoginDialog::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    // QColor最后一个参数代表alpha通道，一般用作透明度
    painter.fillRect(rect(), QColor(50, 50, 50, 0));
}

bool LoginDialog::checkPwd(QString& userin_pwd)
{
    const QString pwdout("506D512A0047279A4495859ACAF61462");
    QString signSrc("user=hwzx&key=35C89E416BF8D95F7B6F65252A49A174&pwdin=");
    signSrc += userin_pwd;

    QByteArray bb = QCryptographicHash::hash(signSrc.toLocal8Bit(), QCryptographicHash::Md5);
    if (pwdout!=bb.toHex().toUpper().data())
    {
        return false;
    }
    return true;
}

void LoginDialog::login()
{
    QString pwdin = pwdEditLine->text().trimmed();

    //判断用户名和密码是否正确
    if (userEditLine->text().trimmed() == tr("hwzx") && checkPwd(pwdin))
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this, tr("警告"), tr("用户名或者密码错误"), QMessageBox::Yes);
    }

    userEditLine->clear();
    pwdEditLine->clear();
    userEditLine->setFocus();
}

void LoginDialog::focusInEvent(QFocusEvent * event)
{
    //splash->show();
    splash->repaint();
}

LoginDialog::~LoginDialog()
{
    delete splash;
}
