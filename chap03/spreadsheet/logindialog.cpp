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
#include <QGridLayout>
#include <QStyle>
#include <QStyleFactory>

LoginDialog::LoginDialog(QWidget *parent):QDialog(parent)
{

    //黑体加粗
    QFont fontHei = QFont("SimHei",16);
    fontHei.setBold(true);
    QFont fontNormal = QFont("Arial",16);
    QFont fontButton = QFont("Arial",14);
    QFont fontLocation = QFont("Arial",6);

    userLabel = new QLabel(this);
    //userLabel->move(70, 80);
    //userLabel->setGeometry(70,80,240,80);
    userLabel->setText(tr("用户名:"));
    userLabel->setFont(fontHei);
    userLabel->setStyleSheet("color:rgb(47,49,139);");

    userEditLine = new QLineEdit(this);
    //userEditLine->setGeometry(300,80,600,80);
    //userEditLine->move(240, 80);
    userEditLine->setPlaceholderText(tr("请输入用户名"));
    //userEditLine->setStyleSheet("border:1px solid white;background:transparent;border-width:1;border-radius:5px;border-style:outset");
    //userEditLine->setAttribute(Qt::WA_TranslucentBackground, true);
    userEditLine->setFont(fontNormal);
    userEditLine->setFocus();
    userEditLine->setStyleSheet("border:2px solid white;background-color:rgb(255,255,255,70%);border-width:1;border-radius:5px;border-style:outset");

    pwdLabel = new QLabel(this);
    //pwdLabel->move(70, 150);
    //pwdLabel->setGeometry(70,190,240,80);
    pwdLabel->setText(tr("密  码:"));
    pwdLabel->setFont(fontHei);
    pwdLabel->setStyleSheet("color:rgb(47,49,139);");

    pwdEditLine = new QLineEdit(this);
    //pwdEditLine->move(240, 150);
    //pwdEditLine->setGeometry(300,190,600,80);
    pwdEditLine->setPlaceholderText(tr("请输入密码"));
    pwdEditLine->setEchoMode(QLineEdit::Password);
    pwdEditLine->setFont(fontNormal);
    pwdEditLine->setStyleSheet("border:2px solid white;background-color:rgb(255,255,255,70%);border-width:1;border-radius:5px;border-style:outset");

    loginBtn = new QPushButton(this);
    //loginBtn->move(50, 200);
    //loginBtn->setGeometry(300,340,200,80);
    loginBtn->setText(tr("登 录"));
    loginBtn->setFont(fontButton);
    loginBtn->setStyleSheet("color:white;background-color:rgb(85,170,255);border-radius:10px;border:3px groove gray;border-style:outset");

    exitBtn = new QPushButton(this);
    //exitBtn->move(210, 200);
    //exitBtn->setGeometry(700,340,200,80);
    exitBtn->setText(tr("取 消"));
    exitBtn->setFont(fontButton);
    exitBtn->setStyleSheet("color:white;background-color:rgb(85,170,255);border-radius:10px;border:3px groove gray;border-style:outset");

    QGridLayout* mainLayout = new QGridLayout;
    /*mainLayout->addWidget(userLabel,0,0);
    mainLayout->addWidget(userEditLine,0,1);
    mainLayout->addWidget(pwdLabel,1,0);
    mainLayout->addWidget(pwdEditLine,1,1);
    mainLayout->setSpacing(100);
    mainLayout->addWidget(loginBtn,2,0);
    mainLayout->addWidget(exitBtn,2,1);
    setLayout(mainLayout);*/

    QLabel* emptyLabel = new QLabel(this);
    emptyLabel->setText(tr("")); //占位
    emptyLabel->setFont(fontLocation);
    //emptyLabel->setStyleSheet("color:white;");

    QLabel* emptyLabel1 = new QLabel(this);
    emptyLabel1->setText(tr("       ")); //占位
    emptyLabel1->setFont(fontHei);

    QLabel* emptyLabel2 = new QLabel(this);
    emptyLabel2->setText(tr("    ")); //占位
    emptyLabel2->setFont(fontHei);

    QHBoxLayout* upOneLayout = new QHBoxLayout;
    upOneLayout->addWidget(userLabel);
    upOneLayout->addWidget(userEditLine);
    upOneLayout->setSpacing(8);

    QHBoxLayout* upTwoLayout = new QHBoxLayout;
    upTwoLayout->addWidget(pwdLabel);
    upTwoLayout->addWidget(pwdEditLine);
    upTwoLayout->setSpacing(8);

    QGridLayout* upLayout = new QGridLayout;
    upLayout->addLayout(upOneLayout,0,0);
    upLayout->addLayout(upTwoLayout,1,0);
    upLayout->setSpacing(20);
    //upLayout->addChildWidget();
    upLayout->addWidget(emptyLabel,2,0);

    QHBoxLayout* downLayout = new QHBoxLayout;
    downLayout->addWidget(emptyLabel1);
    downLayout->addWidget(loginBtn);
    downLayout->addWidget(emptyLabel2);
    downLayout->addWidget(exitBtn);

    mainLayout->addLayout(upLayout,0,0);
    mainLayout->addLayout(downLayout,1,0);
    setLayout(mainLayout);

    //信号与槽关联
    connect(loginBtn, &QPushButton::clicked, this, &LoginDialog::login);
    connect(exitBtn, &QPushButton::clicked, this, &LoginDialog::close);

    setWindowFlags(Qt::FramelessWindowHint);    //设置无边框窗体
    setAttribute(Qt::WA_TranslucentBackground, true);   //设置透明背景 painter重绘实现

    //设置启动背景
    //设置启动动画代替背景色
    this->splash = new QSplashScreen;
    QPixmap pixmap(":/images/win10.png");
    QRect deskRect = QGuiApplication::screens().at(0)->availableGeometry();//默认启动程序在屏幕居中显示
    QPixmap m_pixmap = pixmap.scaled(deskRect.width() , deskRect.height() );
    splash->setPixmap(m_pixmap);
    splash->setWindowFlag(Qt::FramelessWindowHint);
    splash->setAttribute(Qt::WA_TranslucentBackground, true);
    splash->showFullScreen();
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
        QMessageBox::warning(this, tr("警告"), tr("用户名或密码错误"), QMessageBox::Yes);
        /*
        QMessageBox messageBox(QMessageBox::NoIcon,
                                   tr("警告"), tr("用户名或密码错误"),
                                   QMessageBox::Yes, NULL);
        messageBox.setStyle(QStyleFactory::create("windows"));
        messageBox.exec();*/
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
