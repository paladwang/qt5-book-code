//Widget.cpp
#include "Widget.h"
#include "spreadsheet.h"
#include <QPlainTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //QTabWidget的基本设置
    m_tabWidget.setParent(this);
    //m_tabWidget.move(10, 10);
    //m_tabWidget.resize(200, 200);
    //m_tabWidget.setTabPosition(QTabWidget::North);
    //m_tabWidget.setTabShape(QTabWidget::Triangular);
    m_tabWidget.setTabsClosable(false);
    //m_tabWidget.resize(win->size());

    /*
    QPlainTextEdit* edit = new QPlainTextEdit(&m_tabWidget);
    edit->insertPlainText("页面1");
    m_tabWidget.addTab(edit, "1st"); */

    spreadsheet = new Spreadsheet;
    m_tabWidget.addTab(spreadsheet,"原始数据");



    /*
    QWidget* widget = new QWidget(&m_tabWidget);
    QVBoxLayout* layout = new QVBoxLayout();
    QLabel* lbl = new QLabel(widget);
    QPushButton* btn = new QPushButton(widget);

    lbl->setText("页面2");
    lbl->setAlignment(Qt::AlignCenter);

    btn->setText("页面2");

    layout->addWidget(lbl);
    layout->addWidget(btn);

    widget->setLayout(layout);*/

    Spreadsheet* ss2 = new Spreadsheet;
    m_tabWidget.addTab(ss2, "分析过程");

    m_tabWidget.setCurrentIndex(1);

    connect(&m_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(onTabCurrentChanged(int)));
    connect(&m_tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(onTabCloseRequested(int)));

}

void Widget::onTabCurrentChanged(int index)
{
    qDebug() << "Page change to: " << index;
}

void Widget::onTabCloseRequested(int index)
{
    m_tabWidget.removeTab(index);
}

Widget::~Widget()
{

}
