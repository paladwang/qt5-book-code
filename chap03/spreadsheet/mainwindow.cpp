#include <QtWidgets>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

#include "finddialog.h"
#include "gotocelldialog.h"
#include "mainwindow.h"
#include "sortdialog.h"
#include "spreadsheet.h"
#include "pjarea.h"

QColor ligthgray = QColor(211,211,211);
QColor gray = QColor(128,128,128);
QColor black = QColor(0,0,0);
QBrush redBrush = QBrush(QColor(255,0,0));

note::noteMap note::m_mapNote = note::createNoteMap();

MainWindow::MainWindow()
{
    createInfo();
    createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();

    readSettings();

    findDialog = 0; //空指针

    setWindowIcon(QIcon(":/images/ycsy.svg"));
    setCurrentFile(""); //当前文件列表为空
    this->m_bIsNewSheet = true;
}

void MainWindow::createInfo()
{
    spreadsheet = new Spreadsheet;
    //setCentralWidget(spreadsheet);
    spreadsheet->setHidden(false); //不展示

    //数据变化导致分析失效
    //connect(spreadsheet,SIGNAL(cellChanged(int, int)),this,SLOT(sheetChanged(int,int)));
    //connect(spreadsheet,SIGNAL(itemChanged(QTableWidgetItem *)),this,SLOT(sheetChanged()));

    /*
    //设置原始数据表表头
    QStringList strs = {"序号", "登录名", "姓名"};
    spreadsheet->setHorizontalHeaderLabels(strs); //设置行表头
    spreadsheet->setVerticalHeaderLabels(strs); //设置列表头
    spreadsheet->setSpan(1,1,1,2);*/

    //设置第二个spreadsheet
    spreadsheetGYH = new Spreadsheet;
    spreadsheetGYH->setHidden(true); //这个先不展示

    //第三个spreadsheet
    spreadsheetResult = new Spreadsheet;
    spreadsheetResult->setHidden(true); //先不展示

    /*
    //paladwang 新增
    QIcon folderIcon(style()->standardPixmap(QStyle::SP_DirClosedIcon));
    QIcon trashIcon(style()->standardPixmap(QStyle::SP_FileIcon)); //设置图标风格

    QStringList folderLabels;
    folderLabels << tr("当前评价");

    this->foldersTreeWidget = new QTreeWidget;
    this->foldersTreeWidget->setHeaderLabels(folderLabels);
    //foldersTreeWidget->setColumnWidth(5,200); //只是初始宽度
    addFolder(folderIcon, tr("原始评价数据"));
    //addFolder(folderIcon, tr("评价过程"));
    //addFolder(folderIcon, tr("评价结果"));
    //addFolder(trashIcon, tr("Trash"));
    //连接树形节点的单击信号到函数,奇怪的是点了没反应
    connect(this->foldersTreeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(shiftFile(QTreeWidgetItem* ,int )));
    */

    createTree();

    rightSplitter = new QSplitter(Qt::Vertical);
    rightSplitter->addWidget(spreadsheet); //原始数据sheet
    rightSplitter->addWidget(spreadsheetGYH);//归一化sheet
    rightSplitter->addWidget(spreadsheetResult); //最终结果sheet

    /*
    QWidget中有一个函数.hide();它相当于把一个widget设为不可见setVisible(false);想要恢复它也很容易，setVisible(true)即可。
    QWidget *w = new QWidget();
    splitter->addWidget(w);
    QWidget *a = splitter->widget(0);
    a.hide();*/

    //第4个: 图形chart
    chartView = new QChartView;
    chartView->hide();
    rightSplitter->addWidget(chartView);
    charViewResult = new QChartView;
    charViewResult->hide();
    rightSplitter->addWidget(charViewResult);

    //rightSplitter->addWidget(textEdit);
    rightSplitter->setStretchFactor(1, 1);

    mainSplitter = new QSplitter(Qt::Horizontal);
    mainSplitter->addWidget(foldersTreeWidget);
    mainSplitter->addWidget(rightSplitter);
    mainSplitter->setStretchFactor(1, 1);
    setCentralWidget(mainSplitter);
    //设置宽度(似乎不管用)
    foldersTreeWidget->setMinimumWidth(300);
    foldersTreeWidget->setMaximumWidth(500);
    //foldersTreeWidget->resizeColumnToContents(240);
    //设置背景色
    QPalette p(foldersTreeWidget->palette());
    //p.setColor(QPalette::Base, Qt::green); //设置背景色为green
    foldersTreeWidget->setPalette(p);

    //默认数据
    pjArea = new pjarea("西亚地区区块评价");
    //pjArea->debugOriData();
    //pjArea->debugParse();
}

void MainWindow::sheetChanged() { //int row,int column) {
    //QMessageBox::warning(this, tr("数据已经被修改"), tr("curItem:(%1,%2):%3").arg(row).arg(column));
    if (!(this->m_bIsNewSheet)) {
        this->m_bIsNewSheet = true;
        this->setTreeDisable(true);
    }
}

void MainWindow::setTreeDisable(bool bIsDisabled) {

    //遍历treeWidget
    QTreeWidgetItemIterator it(this->foldersTreeWidget);
    while (*it) {
        if (bIsDisabled) {
            if ((*it)->text(0).toStdString()!=string("原始评价数据") || (*it)->text(0).toStdString()!=string("评价数据及结果")) {
                (*it)->setDisabled(true); //除原始评价数据节点外其他节点皆变灰
            } else {
                (*it)->setDisabled(false);
            }
        } else {
            (*it)->setDisabled(false);
        }

        ++it;
    }

    //先把所有的widget隐藏起来
    for(int i=1;i<rightSplitter->count();++i) {
        rightSplitter->widget(i)->hide();
    }
}

bool MainWindow::setIsLoadDefaultData(bool isLoadDefaultData)
{
    m_bIsLoadDefaultData = isLoadDefaultData;
    if(isLoadDefaultData) {
        initSpSheetByDefaultData();
    } else {
        newFile();
    }
}

void MainWindow::addFolder(const QIcon &icon, const QString &name)
{
    QTreeWidgetItem *root;
    if (foldersTreeWidget->topLevelItemCount() == 0) {
        root = new QTreeWidgetItem(foldersTreeWidget);
        root->setText(0, tr("Mail"));
        foldersTreeWidget->setItemExpanded(root, true);
    } else {
        root = foldersTreeWidget->topLevelItem(0);
    }

    QTreeWidgetItem *newItem = new QTreeWidgetItem(root);
    newItem->setText(0, name);
    newItem->setIcon(0, icon);
    newItem->setDisabled(false); //设置这个item不可用(展示上是灰的,不能点击)
    //connect(newItem, SIGNAL((itemClicked)), this, SLOT(newFile()));


    if (!foldersTreeWidget->currentItem())
        foldersTreeWidget->setCurrentItem(newItem);
}

void MainWindow::shiftFile(QTreeWidgetItem *item, int column)
{
    if (this->m_bIsNewSheet) {
        return; //新文件没做parse不能做任何切换
    }

    QTreeWidgetItem *parent=item->parent();//获得父节点
    if(NULL==parent)
        return;
    int row=parent->indexOfChild(item);//获得节点在父节点中的行号(从0开始)

    QString fileName=parent->text(0);//获得父节点的文本字符(Mail)
    QString text = item->text(0); //(当前节点文本)
    /*
    QMessageBox::warning(this, tr("切换数据"), tr("curItem:(%1,%2):%3").arg(row).arg(column).arg(text));
    //经过实验得知:(0,0):第一个,(1,0)是第二个, 以此类推
    return;

    QWidget中有一个函数.hide();它相当于把一个widget设为不可见setVisible(false);想要恢复它也很容易，setVisible(true)即可。
    QWidget *w = new QWidget();
    splitter->addWidget(w);
    QWidget *a = splitter->widget(0);
    a.hide();*/

    int index = -1;
    if(text.toStdString()==string("初始数据录入")) {
        index = 0;
    } else  if(text.toStdString()==string("初始数据归一化")) {
        index = 1;
    } else  if(text.toStdString()==string("主要参数计算")) {
        index = 2;
    } else  if(text.toStdString()==string("计算结果")) {
        index = 3;
    }else  if(text.toStdString()==string("结果对比")) {
        index = 4;
    }

    if(index>(rightSplitter->count()-1) || index==-1) {
        //没有对应的widget
        return;
    }

    //把之前的选中去掉,然后设置最新的选中
    //遍历treeWidget
    QTreeWidgetItemIterator it(this->foldersTreeWidget);
    while (*it) {
        (*it)->setSelected(false); //设置为未选中
        ++it;
    }
    item->setSelected(true); //当前节点设置为选中

    //先把所有的widget隐藏起来
    for(int i=0;i<rightSplitter->count();++i) {
        rightSplitter->widget(i)->hide();
    }


    rightSplitter->widget(index)->setVisible(true);

    //debug
    if(index==3) {
        drawOriData();
        rightSplitter->widget(index)->setVisible(true);
    }
    if(index==4) {
        drawResult();
        rightSplitter->widget(index)->setVisible(true);
    }

    /*
    //drawChartView();
    if(row==2) {
        drawChartView();
        //rightSplitter->widget(row)->resize(420, 300);
        //chartView->repaint();
    }
    //然后根据点击的内容展示相应的widget
    //QWidget* curWidget = NULL;
    rightSplitter->widget(row)->setVisible(true);
    //chartView->repaint(); */
}

void MainWindow::drawOriData() {
    string title = "各国一级指标得分柱状图";
    vector<string> cateGor;
    cateGor.push_back("尼日利亚");
    cateGor.push_back("安哥拉");
    cateGor.push_back("刚果布");
    cateGor.push_back("加蓬");
    cateGor.push_back("喀麦隆");

    map<string,vector<double>> charItem;
    {
        vector<double> item;
        item.push_back(0.028465734);
        item.push_back(0.093765198);
        item.push_back(0.069571996);
        item.push_back(0.152207);
        item.push_back(0.033204081);
        charItem["政治环境"]=item;
    }
    {
        vector<double> item;
        item.push_back(0.02465522);
        item.push_back(0.101681847);
        item.push_back(0.027951646);
        item.push_back(0.103346763);
        item.push_back(0.021676106);
        charItem["油气管理体制与法律法规"]=item;
    }
    {
        vector<double> item;
        item.push_back(0.072737263);
        item.push_back(0.092507684);
        item.push_back(0.112307847);
        item.push_back(0.034121831);
        item.push_back(0.021855541);
        charItem["对外合作开放"]=item;
    }
    {
        vector<double> item;
        item.push_back(0.080685634);
        item.push_back(0.092359436);
        item.push_back(0.070646722);
        item.push_back(0.076190981);
        item.push_back(0.051689743);
        charItem["运营制度"]=item;
    }
    {
        vector<double> item;
        item.push_back(0.065805781);
        item.push_back(0.08490061);
        item.push_back(0.05265403);
        item.push_back(0.084676212);
        item.push_back(0.101133308);
        charItem["基础设施和自然环境"]=item;
    }
    {
        vector<double> item;
        item.push_back(0.063531983);
        item.push_back(0.03929497);
        item.push_back(0.101171758);
        item.push_back(0.072808704);
        item.push_back(0.076911151);
        charItem["经济环境"]=item;
    }
    {
        vector<double> item;
        item.push_back(0.088864);
        item.push_back(0.029065129);
        item.push_back(0.013112571);
        item.push_back(0.006200099);
        item.push_back(0.002623373);
        charItem["油气资源潜力"]=item;
    }

    drawChartView(chartView,title,cateGor,charItem);
}

void MainWindow::drawResult() {
    string title = "各国最终得分柱状图";
    vector<string> cateGor;
    cateGor.push_back("尼日利亚");
    cateGor.push_back("安哥拉");
    cateGor.push_back("刚果布");
    cateGor.push_back("加蓬");
    cateGor.push_back("喀麦隆");

    map<string,vector<double>> charItem;
    {
        vector<double> item;
        item.push_back(0.424745616);
        item.push_back(0.514203585);
        item.push_back(0.427164768);
        item.push_back(0.509299788);
        item.push_back(0.288547997);
        charItem["最终得分"]=item;
    }

    drawChartView(charViewResult,title,cateGor,charItem);
}

#if 0
void MainWindow::drawResult() {
    //老的图形还在,delete,该chart相关的对象都会被Qt自动delete
    if (charViewResult->chart()!=NULL) {
        delete charViewResult->chart();
    }

    DataTable dataTable;
/*
    // set seed for random stuff
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    // generate random data
    for (int i(0); i < listCount; i++) {
        DataList dataList;
        qreal yValue(0);
        for (int j(0); j < valueCount; j++) {
            yValue = yValue + (qreal)(qrand() % valueMax) / (qreal) valueCount;
            QPointF value((j + (qreal) rand() / (qreal) RAND_MAX) * ((qreal) m_valueMax / (qreal) valueCount),
                          yValue);
            QString label = "Slice " + QString::number(i) + ":" + QString::number(j);
            dataList << Data(value, label);
        }
        dataTable << dataList;
    }*/

    {
        DataList dataList;
        qreal yValue(0);
        QPoint value(10,yValue);
        QString label = "尼日利亚";
        dataList << Data(value,label);
        dataTable << dataList;
    }

    int valueCount = 10;

         //Q_UNUSED(valueCount);
         QChart *chart = new QChart();
         chart->setTitle("最终结果");
{
         QStackedBarSeries *series = new QStackedBarSeries(chart);
         for (int i(0); i < dataTable.count(); i++) {
             QBarSet *set = new QBarSet("Bar set " + QString::number(i));
             for (const Data &data : dataTable[i])
                 *set << data.first.y();
             series->append(set);
         }
         chart->addSeries(series);
         chart->createDefaultAxes();
         }


                 charViewResult->setChart(chart);
                 charViewResult->setRenderHint(QPainter::Antialiasing);

         //return chart;
}
#endif

void MainWindow::drawChartView(QChartView* curChartView,string& title,vector<string>& cateGor, map<string,vector<double>> charItem)
{
    /*  很奇怪,有这个容易core
    //老的图形还在,delete,该chart相关的对象都会被Qt自动delete
    if (chartView->chart()!=NULL) {
        delete chartView->chart();
    } */
#if 1
    QBarSeries *series = new QBarSeries();
    map<string,vector<double>>::const_iterator it;
    for(it=charItem.begin();it!=charItem.end();++it) {
        const vector<double>& item = it->second;
        QBarSet *set = new QBarSet(it->first.c_str());
        for(int i=0;i<item.size();++i) {
            *set << item[i];
        }
        series->append(set);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(title.c_str());
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    for(int i=0;i<cateGor.size();++i) {
        categories <<cateGor[i].c_str();
    }

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）
    chart->setAxisX(axis, series);//设置坐标轴

    chart->legend()->setVisible(true); //设置图例为显示状态
    chart->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部

    //QChartView *chartView = new QChartView(chart);
    curChartView->setChart(chart);
    curChartView->setRenderHint(QPainter::Antialiasing);
#endif

#if 0
    //![1]
        QBarSet *set0 = new QBarSet("Jane");
        QBarSet *set1 = new QBarSet("John");
        QBarSet *set2 = new QBarSet("Axel");
        QBarSet *set3 = new QBarSet("Mary");
        QBarSet *set4 = new QBarSet("Samantha");

        *set0 << 1 << 2 << 3 << 4 << 5 << 6;// Jane 6个月份的值
        *set1 << 5 << 0 << 0 << 4 << 0 << 7;
        *set2 << 3 << 5 << 8 << 19<< 8 << 5;
        *set3 << 5 << 6 << 7 << 3 << 4 << 5;
        *set4 << 9 << 7 << 5 << 3 << 1 << 2;
    //![1]

    //![2]
        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        series->append(set4);
    //![2]

    //![3]
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Simple barchart example");
        chart->setAnimationOptions(QChart::SeriesAnimations);
    //![3]

    //![4]
        QStringList categories;
        categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）
        chart->setAxisX(axis, series);//设置坐标轴
    //![4]

    //![5]
        chart->legend()->setVisible(true); //设置图例为显示状态
        chart->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部
    //![5]

    //![6]
        //QChartView *chartView = new QChartView(chart);
        chartView->setChart(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
    //![6]
#endif
    //https://blog.csdn.net/weixin_42837024/article/details/82257021
}

void MainWindow::createTree() {
    //设置树型结构的title
    QStringList folderLabels;
    folderLabels << tr("当前评价");
    this->foldersTreeWidget = new QTreeWidget;
    this->foldersTreeWidget->setHeaderLabels(folderLabels);

    QTreeWidgetItem *root;
    if (foldersTreeWidget->topLevelItemCount() == 0) {
        root = new QTreeWidgetItem(foldersTreeWidget);
        root->setText(0, tr("油气投资环境评价"));
        foldersTreeWidget->setItemExpanded(root, true);
    } else {
        root = foldersTreeWidget->topLevelItem(0);
    }

    QIcon folderIcon(":/images/folder.png");
    QIcon fileIcon(":/images/file.png"); //设置图标风格

    //(0,0),原始评价数据
    QTreeWidgetItem *item1 = new QTreeWidgetItem(root);
    item1->setText(0, "评价数据"); //todo: 这个值改了后必须得改shifeFile那里
    item1->setIcon(0, folderIcon);
    item1->setDisabled(false); //设置这个item不可用(展示上是灰的,不能点击)
    //item1->setSelected(true);
    //connect(newItem, SIGNAL((itemClicked)), this, SLOT(newFile()));
    QTreeWidgetItem *item1_1 = new QTreeWidgetItem(item1);
    item1_1->setText(0, "初始数据录入");
    item1_1->setIcon(0, fileIcon);
    item1_1->setDisabled(false); //设置这个item不可用(展示上是灰的,不能点击)
    //item1_1->setFlags(item1_1->flags() & (~Qt::ItemIsEnabled));
    item1->addChild(item1_1);
    item1_1->setSelected(true);


    QTreeWidgetItem *item2 = new QTreeWidgetItem(root);
    item2->setText(0, "评价过程");
    item2->setIcon(0, folderIcon);
    //item2->setFlags(Qt::ItemIsSelectable); //这个和下边的setDisabled效果一样
    //item2->setDisabled(true); //设置这个item不可用(展示上是灰的,不能点击)
    item2->setFlags(item2->flags() & (~Qt::ItemIsEnabled));

    QTreeWidgetItem *item2_1 = new QTreeWidgetItem(item2);
    item2_1->setText(0, "初始数据归一化");
    item2_1->setIcon(0, fileIcon);
    item2_1->setDisabled(true); //设置这个item不可用(展示上是灰的,不能点击)
    item2_1->setFlags(item2_1->flags() & (~Qt::ItemIsEnabled));
    item2->addChild(item2_1);

    QTreeWidgetItem *item2_2 = new QTreeWidgetItem(item2);
    item2_2->setText(0, "主要参数计算");
    item2_2->setIcon(0, fileIcon);
    item2_2->setDisabled(true); //设置这个item不可用(展示上是灰的,不能点击)
    item2_2->setFlags(item2_2->flags() & (~Qt::ItemIsEnabled));
    item2->addChild(item2_2);

    QTreeWidgetItem *item3 = new QTreeWidgetItem(root);
    item3->setText(0, "评价结果");
    item3->setIcon(0, folderIcon);
    item3->setDisabled(true); //设置这个item不可用(展示上是灰的,不能点击)
    item3->setFlags(item3->flags() & (~Qt::ItemIsEnabled));

    QTreeWidgetItem *item3_1 = new QTreeWidgetItem(item3);
    item3_1->setText(0, "计算结果");
    item3_1->setIcon(0, QIcon(":/images/fx128.png"));
    item3_1->setDisabled(true); //设置这个item不可用(展示上是灰的,不能点击)
    item3_1->setFlags(item3_1->flags() & (~Qt::ItemIsEnabled));
    item3->addChild(item3_1);

    QTreeWidgetItem *item3_2 = new QTreeWidgetItem(item3);
    item3_2->setText(0, "结果对比");
    item3_2->setIcon(0, QIcon(":/images/zzt.png"));
    item3_2->setDisabled(true); //设置这个item不可用(展示上是灰的,不能点击)
    item3_2->setFlags(item3_2->flags() & (~Qt::ItemIsEnabled));
    item3->addChild(item3_2);

    if (!foldersTreeWidget->currentItem())
        foldersTreeWidget->setCurrentItem(item1);

    connect(this->foldersTreeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(shiftFile(QTreeWidgetItem* ,int )));
}

void MainWindow::fillSpreadsheetHeader(Spreadsheet *form, bool isInsertBlankRow)
{
    if (pjArea->begin(eDataType::ORI)==pjArea->end(eDataType::ORI)) {
        return; //万一pjArea还没初始化
    }

    //设置原始数据表表头
    QStringList rHeader;
    QStringList cHeader;
    int columnData = 4; //数据列从4开始(第0为一级指标名,第1列为二级指标名,第3列为二级指标备注,第4列为正负向说明)
    bool bIsFirstRow = true;
    rHeader<<""; //列头有2行

    //黑体加粗
    QFont fontHei = QFont("SimHei",12);
    fontHei.setBold(true);

    int twolevelCnt = 0;

    map<int,country*>::const_iterator it;
    for(it=pjArea->begin(eDataType::ORI);it!=pjArea->end(eDataType::ORI);++it) {
        country& curCy = *(it->second);
        rHeader<<curCy.getName().c_str();
        map<int,onelevel*>::const_iterator itOne;

        int rowData=1; // 数据行从1开始(第0行作为自设行头)
        for(itOne=curCy.begin();itOne!=curCy.end();++itOne) {
            onelevel& oneLevel = *(itOne->second);
            //QString cHeaderTwo = oneLevel.getName().c_str();
            //form->setFormula(rowData, columnData, cHeaderTwo);

            //自设行列头
            form->setFormula(0,columnData,curCy.getName().c_str());
            //form->item(0,columnData)->setTextAlignment(Qt::AlignRight); //Qt::AlignHCenter); //居中展示
            form->setFont(0,columnData,1,1,fontHei);

            form->setFormula(rowData,0,itOne->second->getName().c_str());
            form->setSpan(rowData,0,oneLevel.getTwoLevelNum(),1);
            form->setForeground(rowData,0,oneLevel.getTwoLevelNum(),1,redBrush);

            map<int,twolevel*>::const_iterator itTwo;
            for(itTwo=oneLevel.begin();itTwo!=oneLevel.end();++itTwo) {
                twolevel& twoLevel = *(itTwo->second);

                //自设二级列头
                if (bIsFirstRow) {
                    //cHeader<<twoLevel.getName().c_str();
                    form->setFormula(rowData,1,twoLevel.getName().c_str());
                    form->setFlags(rowData,1,1,1,Qt::ItemIsEditable);
                    //二级指标备注和正负向说明
                    form->setFormula(rowData,2,note::getNote(oneLevel.getLevelID(),twoLevel.getLevelID()).c_str());
                    form->setFormula(rowData,3,twoLevel.isPositive()?"正向指标":"负向指标");
                }
                /*
                QString tmpQStr = QString::number(twoLevel.getValue());
                form->setFormula(rowData, columnData, tmpQStr);
                //隔行换色
                {
                    if(rowData%2==0){
                        form->setColor(rowData,columnData,1,1,gray);
                    } else {
                        form->setColor(rowData,columnData,1,1,ligthgray);
                    }
                }*/
                //qDebug()<<rowData<<columnData<<tmpQStr<<endl;
                rowData++;
                twolevelCnt++;
            }

            //每一个onelevel完后再空一行
            //form->insertRow(rowData++);
        }
        bIsFirstRow = false;
        columnData++;
    }
    //form->setFlags(0,0,1,2,Qt::ItemIsEditable);
    form->setSpan(0,0,1,2); //把行头和列头之间的空白合并
    form->setFont(1,0,twolevelCnt,1,fontHei);
    form->setFlags(1,0,twolevelCnt,1,Qt::ItemIsEditable);
    //form->setColumnCount(twolevelCnt+10);
    //form->insertRow(6);

    //设置行头


    if(isInsertBlankRow) {
        //每个onelevel后边都增加一个空行
        country curCy = *(pjArea->begin(eDataType::ORI)->second);
        map<int,onelevel*>::const_iterator itOne;
        int spanRow = 1;
        for(itOne=curCy.begin();itOne!=curCy.end();++itOne) {
            onelevel& oneLevel = *(itOne->second);
            spanRow += oneLevel.getTwoLevelNum();
            form->insertRow(spanRow);
            form->setRowHeight(spanRow,25);
            form->setColor(spanRow,0,1,2+pjArea->getCountryNum(),black);
            form->setSpan(spanRow,0,1,2+pjArea->getCountryNum());
            spanRow++;
        }
    }

    //form->setHorizontalHeaderLabels(rHeader); //设置行表头
    //form->setVerticalHeaderLabels(cHeader); //设置列表头
    //因为表头不能合并,所以隐藏表头并用单元格合并
    //form->verticalHeader()->setHidden(true);
    //form->horizontalHeader()->setHidden(true);
    //form->setSpan(1,1,1,2);
}

void MainWindow::fillSpreadsheet(Spreadsheet* form, countryIter begin,countryIter end, int sRow, int sColumn, bool isInsertBlankRow) {
    int columnData = sColumn; //从给定列开始
    bool bIsFirstRow = true;


    //黑体加粗
    QFont fontHei = QFont("SimHei",12);
    fontHei.setBold(true);

    int twolevelCnt = 0;

    countryIter it;
    for(it=begin;it!=end;++it) {
        country& curCy = *(it->second);
        map<int,onelevel*>::const_iterator itOne;

        int rowData=sRow; //数据行从给定行开始(第0行作为自设行头)
        for(itOne=curCy.begin();itOne!=curCy.end();++itOne) {
            onelevel& oneLevel = *(itOne->second);
            //QString cHeaderTwo = oneLevel.getName().c_str();
            //form->setFormula(rowData, columnData, cHeaderTwo);

            //自设行列头
            form->setFormula(0,columnData,curCy.getName().c_str());
            //form->item(0,columnData)->setTextAlignment(Qt::AlignRight); //Qt::AlignHCenter); //居中展示
            form->setFont(0,columnData,1,1,fontHei);

            form->setFormula(rowData,0,itOne->second->getName().c_str());
            form->setSpan(rowData,0,oneLevel.getTwoLevelNum(),1);
            form->setForeground(rowData,0,oneLevel.getTwoLevelNum(),1,redBrush);

            map<int,twolevel*>::const_iterator itTwo;
            for(itTwo=oneLevel.begin();itTwo!=oneLevel.end();++itTwo) {
                twolevel& twoLevel = *(itTwo->second);

                //自设二级列头
                /*
                if (bIsFirstRow) {
                    //cHeader<<twoLevel.getName().c_str();
                    form->setFormula(rowData,1,twoLevel.getName().c_str());
                    form->setFlags(rowData,1,1,1,Qt::ItemIsEditable);
                    //二级指标备注和正负向说明
                    form->setFormula(rowData,2,note::getNote(oneLevel.getLevelID(),twoLevel.getLevelID()).c_str());
                    form->setFormula(rowData,3,twoLevel.isPositive()?"正向指标":"负向指标");
                }*/
                QString tmpQStr = QString::number(twoLevel.getValue());
                form->setFormula(rowData, columnData, tmpQStr);
                //隔行换色
                {
                    if(rowData%2==0){
                        form->setColor(rowData,columnData,1,1,gray);
                    } else {
                        form->setColor(rowData,columnData,1,1,ligthgray);
                    }
                }
                //qDebug()<<rowData<<columnData<<tmpQStr<<endl;
                rowData++;
                twolevelCnt++;
            }

            //每一个onelevel完后再空一行
            //form->insertRow(rowData++);
        }
        bIsFirstRow = false;
        columnData++;
    }
    /*
    //form->setFlags(0,0,1,2,Qt::ItemIsEditable);
    form->setSpan(0,0,1,2); //把行头和列头之间的空白合并
    form->setFont(1,0,twolevelCnt,1,fontHei);
    form->setFlags(1,0,twolevelCnt,1,Qt::ItemIsEditable);
    //form->setColumnCount(twolevelCnt+10);
    //form->insertRow(6);
    */

    if(isInsertBlankRow) {
        //每个onelevel后边都增加一个空行
        country curCy = *(pjArea->begin(eDataType::ORI)->second);
        map<int,onelevel*>::const_iterator itOne;
        int spanRow = 1;
        for(itOne=curCy.begin();itOne!=curCy.end();++itOne) {
            onelevel& oneLevel = *(itOne->second);
            spanRow += oneLevel.getTwoLevelNum();
            form->insertRow(spanRow);
            form->setRowHeight(spanRow,25);
            form->setColor(spanRow,0,1,2+pjArea->getCountryNum(),black);
            form->setSpan(spanRow,0,1,2+pjArea->getCountryNum());
            spanRow++;
        }
    }
}

void MainWindow::parse()
{
    pjArea->debugParse();
    /*
    QMessageBox::warning(this, tr("to parse the orignal data"),
                           tr("The document has been modified.\n"
                              "Do you want to save your changes?"),
                           QMessageBox::Yes | QMessageBox::No
                           | QMessageBox::Cancel);
    return;*/

    //parse过程就是把数据填入相应的sheet
    this->fillSpreadsheetHeader(spreadsheetGYH);
    this->fillSpreadsheet(spreadsheetGYH,pjArea->m_mapCountry.begin(),pjArea->m_mapCountry.end(),1,4);
    this->fillSpreadsheet(spreadsheetGYH,pjArea->m_mapCountryGYH.begin(),pjArea->m_mapCountryGYH.end(),1,4+pjArea->m_mapCountry.size(),true);

    //把后边的map组织下
    map<int,country*> mapAll;
    mapAll[pjArea->m_bzcOneResult->getCountryID()] = pjArea->m_bzcOneResult;//标准差结果
    mapAll[pjArea->m_preOneZYX->getCountryID()] = pjArea->m_preOneZYX;//重要性之比前驱值
    mapAll[pjArea->m_oneZYX->getCountryID()] = pjArea->m_oneZYX;//重要性之比
    mapAll[pjArea->m_onePower->getCountryID()] = pjArea->m_onePower;//指标权重
    /*mapAll[pjArea->m_bzcTwoResult->getCountryID()] = pjArea->m_bzcTwoResult;//准则层标准差
    mapAll[pjArea->m_preTwoZYX->getCountryID()] = pjArea->m_preTwoZYX;//准则层重要性之比前驱
    mapAll[pjArea->m_twoZYX->getCountryID()] = pjArea->m_twoZYX;//准则层重要性之比
    mapAll[pjArea->m_twoPower->getCountryID()] = pjArea->m_twoPower;//准则层权重
    */mapAll[pjArea->m_allPower->getCountryID()] = pjArea->m_allPower;//指标的全局权重
    //mapAll[pjArea->m_other->getCountryID()] = pjArea->m_other;//全局其他信息

    //再挨个输出这些值
    map<int,country*> mapResult = pjArea->m_mapCountryResult;
    this->fillSpreadsheetHeader(spreadsheetResult);
    this->fillSpreadsheet(spreadsheetResult,mapAll.begin(),mapAll.end(),1,4,false);
    this->fillSpreadsheet(spreadsheetResult,mapResult.begin(),mapResult.end(),1,4+mapAll.size(),true);

    //把相应的树型菜单都置亮
    this->setTreeDisable(false);
    this->m_bIsNewSheet = false;
}

void MainWindow::initSpSheetByDefaultData()
{
    newFile();
    pjArea->debugOriData(); //set orig data

    //设置原始数据表表头
    QStringList rHeader;
    QStringList cHeader;
    int columnData = 4; //数据列从4开始(第0为一级指标名,第1列为二级指标名,第3列为二级指标备注,第4列为正负向说明)
    bool bIsFirstRow = true;
    rHeader<<""; //列头有2行

    //黑体加粗
    QFont fontHei = QFont("SimHei",12);
    fontHei.setBold(true);

    int twolevelCnt = 0;

    map<int,country*>::const_iterator it;
    for(it=pjArea->begin(eDataType::ORI);it!=pjArea->end(eDataType::ORI);++it) {
        country& curCy = *(it->second);
        rHeader<<curCy.getName().c_str();
        map<int,onelevel*>::const_iterator itOne;

        int rowData=1; // 数据行从1开始(第0行作为自设行头)
        for(itOne=curCy.begin();itOne!=curCy.end();++itOne) {
            onelevel& oneLevel = *(itOne->second);
            //QString cHeaderTwo = oneLevel.getName().c_str();
            //spreadsheet->setFormula(rowData, columnData, cHeaderTwo);

            //自设行列头
            spreadsheet->setFormula(0,columnData,curCy.getName().c_str());
            //spreadsheet->item(0,columnData)->setTextAlignment(Qt::AlignRight); //Qt::AlignHCenter); //居中展示
            spreadsheet->setFont(0,columnData,1,1,fontHei);

            spreadsheet->setFormula(rowData,0,itOne->second->getName().c_str());
            spreadsheet->setSpan(rowData,0,oneLevel.getTwoLevelNum(),1);
            spreadsheet->setForeground(rowData,0,oneLevel.getTwoLevelNum(),1,redBrush);

            map<int,twolevel*>::const_iterator itTwo;
            for(itTwo=oneLevel.begin();itTwo!=oneLevel.end();++itTwo) {
                twolevel& twoLevel = *(itTwo->second);

                //自设二级列头
                if (bIsFirstRow) {
                    //cHeader<<twoLevel.getName().c_str();
                    spreadsheet->setFormula(rowData,1,twoLevel.getName().c_str());
                    spreadsheet->setFlags(rowData,1,1,1,Qt::ItemIsEditable);
                    //二级指标备注和正负向说明
                    spreadsheet->setFormula(rowData,2,note::getNote(oneLevel.getLevelID(),twoLevel.getLevelID()).c_str());
                    spreadsheet->setFormula(rowData,3,twoLevel.isPositive()?"正向指标":"负向指标");
                }
                QString tmpQStr = QString::number(twoLevel.getValue());
                spreadsheet->setFormula(rowData, columnData, tmpQStr);
                //隔行换色
                {
                    if(rowData%2==0){
                        spreadsheet->setColor(rowData,columnData,1,1,gray);
                    } else {
                        spreadsheet->setColor(rowData,columnData,1,1,ligthgray);
                    }
                }
                //qDebug()<<rowData<<columnData<<tmpQStr<<endl;
                rowData++;
                twolevelCnt++;
            }

            //每一个onelevel完后再空一行
            //spreadsheet->insertRow(rowData++);
        }
        bIsFirstRow = false;
        columnData++;
    }
    //spreadsheet->setFlags(0,0,1,2,Qt::ItemIsEditable);
    spreadsheet->setSpan(0,0,1,2); //把行头和列头之间的空白合并
    spreadsheet->setFont(1,0,twolevelCnt,1,fontHei);
    spreadsheet->setFlags(1,0,twolevelCnt,1,Qt::ItemIsEditable);
    //spreadsheet->setColumnCount(twolevelCnt+10);
    //spreadsheet->insertRow(6);

    //每个onelevel后边都增加一个空行
    country curCy = *(pjArea->begin(eDataType::ORI)->second);
    map<int,onelevel*>::const_iterator itOne;
    int spanRow = 1;
    for(itOne=curCy.begin();itOne!=curCy.end();++itOne) {
        onelevel& oneLevel = *(itOne->second);
        spanRow += oneLevel.getTwoLevelNum();
        spreadsheet->insertRow(spanRow);
        spreadsheet->setRowHeight(spanRow,25);
        spreadsheet->setColor(spanRow,0,1,2+pjArea->getCountryNum(),black);
        spreadsheet->setSpan(spanRow,0,1,2+pjArea->getCountryNum());
        spanRow++;
    }

    //spreadsheet->setHorizontalHeaderLabels(rHeader); //设置行表头
    //spreadsheet->setVerticalHeaderLabels(cHeader); //设置列表头
    //因为表头不能合并,所以隐藏表头并用单元格合并
    //spreadsheet->verticalHeader()->setHidden(true);
    //spreadsheet->horizontalHeader()->setHidden(true);
    //spreadsheet->setSpan(1,1,1,2);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (okToContinue()) {
        writeSettings();
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::newFile()
{
    if (okToContinue()) {
        spreadsheet->clear();
        setCurrentFile("");
    }
}

void MainWindow::open()
{
    if (okToContinue()) {
        QString fileName = QFileDialog::getOpenFileName(this,
                                   tr("Open Spreadsheet"), ".",
                                   tr("Spreadsheet files (*.sp)"));
        if (!fileName.isEmpty())
            loadFile(fileName); //最终是由spreadsheet类打开的
    }
}

bool MainWindow::save()
{
    if (curFile.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(curFile); //调用spreadsheet类来写入
    }
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                               tr("Save Spreadsheet"), ".",
                               tr("Spreadsheet files (*.sp)"));
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName); //调用spreadsheet类来写入
}

void MainWindow::find()
{
    if (!findDialog) {
        findDialog = new FindDialog(this);
        connect(findDialog, SIGNAL(findNext(const QString &,
                                            Qt::CaseSensitivity)),
                spreadsheet, SLOT(findNext(const QString &,
                                           Qt::CaseSensitivity)));
        connect(findDialog, SIGNAL(findPrevious(const QString &,
                                                Qt::CaseSensitivity)),
                spreadsheet, SLOT(findPrevious(const QString &,
                                               Qt::CaseSensitivity)));
    }

    findDialog->show();
    findDialog->raise();
    findDialog->activateWindow();
}

void MainWindow::goToCell()
{
    GoToCellDialog dialog(this);
    if (dialog.exec()) {
        QString str = dialog.lineEdit->text().toUpper();
        spreadsheet->setCurrentCell(str.mid(1).toInt() - 1,
                                    str[0].unicode() - 'A');
    }
}

void MainWindow::sort()
{
    SortDialog dialog(this);
    QTableWidgetSelectionRange range = spreadsheet->selectedRange();
    dialog.setColumnRange('A' + range.leftColumn(),
                          'A' + range.rightColumn());

    if (dialog.exec()) {
        SpreadsheetCompare compare;
        compare.keys[0] =
              dialog.primaryColumnCombo->currentIndex();
        compare.keys[1] =
              dialog.secondaryColumnCombo->currentIndex() - 1;
        compare.keys[2] =
              dialog.tertiaryColumnCombo->currentIndex() - 1;
        compare.ascending[0] =
              (dialog.primaryOrderCombo->currentIndex() == 0);
        compare.ascending[1] =
              (dialog.secondaryOrderCombo->currentIndex() == 0);
        compare.ascending[2] =
              (dialog.tertiaryOrderCombo->currentIndex() == 0);
        spreadsheet->sort(compare);
    }
}
void MainWindow::about()
{
    QMessageBox::about(this, tr("关于延长石油区块经济评价模块说明"),
            tr("<h2>延长石油区块经济评价模块V1.0</h2>"
               "<p>Copyright &copy; 2022 Software Inc."
               "<p>此软件采用标准差修正G1法确定指标权重，既能反映专家意见又能体现指标的数据信息。"
               "用户输入相应地区（国家)的初始评价数据后，点击Parse(或对应的快捷工具按钮)，"
               "即可获得评价结果，实现了海外油气投资环境由定性描述向定量评价的转变，"
               "使定量评价更加简单、高效、灵活。"
               "<p>         "));
}

void MainWindow::openRecentFile()
{
    if (okToContinue()) {
        QAction *action = qobject_cast<QAction *>(sender());
        if (action)
            loadFile(action->data().toString()); //action->data().toString()取到的是文件名

        //debug
        //QMessageBox::warning(this, tr("test"),action->data().toString());
    }
}

void MainWindow::updateStatusBar()
{
    locationLabel->setText(spreadsheet->currentLocation());
    formulaLabel->setText(spreadsheet->currentFormula());
}

void MainWindow::spreadsheetModified()
{
    setWindowModified(true);
    updateStatusBar();

    setTreeDisable(true);
}

void MainWindow::createActions()
{
    newAction = new QAction(tr("&New"), this);
    newAction->setIcon(QIcon(":/images/new128.png"));
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new spreadsheet file"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    openAction = new QAction(tr("&Open..."), this);
    openAction->setIcon(QIcon(":/images/open128.png"));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing spreadsheet file"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

    saveAction = new QAction(tr("&Save"), this);
    saveAction->setIcon(QIcon(":/images/save128.png"));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the spreadsheet to disk"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAction = new QAction(tr("Save &As..."), this);
    saveAsAction->setStatusTip(tr("Save the spreadsheet under a new "
                                  "name"));
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));

    for (int i = 0; i < MaxRecentFiles; ++i) {
        recentFileActions[i] = new QAction(this);
        recentFileActions[i]->setVisible(false);
        connect(recentFileActions[i], SIGNAL(triggered()),
                this, SLOT(openRecentFile()));
    }

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    cutAction = new QAction(tr("Cu&t"), this);
    cutAction->setIcon(QIcon(":/images/cut.png"));
    cutAction->setShortcut(QKeySequence::Cut);
    cutAction->setStatusTip(tr("Cut the current selection's contents "
                               "to the clipboard"));
    connect(cutAction, SIGNAL(triggered()), spreadsheet, SLOT(cut()));

    copyAction = new QAction(tr("&Copy"), this);
    copyAction->setIcon(QIcon(":/images/copy.png"));
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setStatusTip(tr("Copy the current selection's contents "
                                "to the clipboard"));
    connect(copyAction, SIGNAL(triggered()), spreadsheet, SLOT(copy()));

    pasteAction = new QAction(tr("&Paste"), this);
    pasteAction->setIcon(QIcon(":/images/paste.png"));
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("Paste the clipboard's contents into "
                                 "the current selection"));
    connect(pasteAction, SIGNAL(triggered()),
            spreadsheet, SLOT(paste()));

    deleteAction = new QAction(tr("&Delete"), this);
    deleteAction->setShortcut(QKeySequence::Delete);
    deleteAction->setStatusTip(tr("Delete the current selection's "
                                  "contents"));
    connect(deleteAction, SIGNAL(triggered()),
            spreadsheet, SLOT(del()));

    selectRowAction = new QAction(tr("&Row"), this);
    selectRowAction->setStatusTip(tr("Select all the cells in the "
                                     "current row"));
    connect(selectRowAction, SIGNAL(triggered()),
            spreadsheet, SLOT(selectCurrentRow()));

    selectColumnAction = new QAction(tr("&Column"), this);
    selectColumnAction->setStatusTip(tr("Select all the cells in the "
                                        "current column"));
    connect(selectColumnAction, SIGNAL(triggered()),
            spreadsheet, SLOT(selectCurrentColumn()));

    selectAllAction = new QAction(tr("&All"), this);
    selectAllAction->setShortcut(QKeySequence::SelectAll);
    selectAllAction->setStatusTip(tr("Select all the cells in the "
                                     "spreadsheet"));
    connect(selectAllAction, SIGNAL(triggered()),
            spreadsheet, SLOT(selectAll()));

    findAction = new QAction(tr("&Find..."), this);
    findAction->setIcon(QIcon(":/images/find.png"));
    findAction->setShortcut(QKeySequence::Find);
    findAction->setStatusTip(tr("Find a matching cell"));
    connect(findAction, SIGNAL(triggered()), this, SLOT(find()));

    goToCellAction = new QAction(tr("&Go to Cell..."), this);
    goToCellAction->setIcon(QIcon(":/images/gotocell.png"));
    goToCellAction->setShortcut(tr("Ctrl+G"));
    goToCellAction->setStatusTip(tr("Go to the specified cell"));
    connect(goToCellAction, SIGNAL(triggered()),
            this, SLOT(goToCell()));

    recalculateAction = new QAction(tr("&Recalculate"), this);
    recalculateAction->setShortcut(tr("F9"));
    recalculateAction->setStatusTip(tr("Recalculate all the "
                                       "spreadsheet's formulas"));
    connect(recalculateAction, SIGNAL(triggered()),
            spreadsheet, SLOT(recalculate()));

    sortAction = new QAction(tr("&Sort..."), this);
    sortAction->setStatusTip(tr("Sort the selected cells or all the "
                                "cells"));
    connect(sortAction, SIGNAL(triggered()), this, SLOT(sort()));

    //////////////////////////////////////////////////////////////
    parseAction = new QAction(tr("&Parse..."), this);
    parseAction->setIcon(QIcon(":/images/run96.png"));
    parseAction->setShortcut(tr("Ctrl+R"));
    parseAction->setStatusTip(tr("Parse the current origal data"));
    connect(parseAction, SIGNAL(triggered()), this, SLOT(parse()));
    //////////////////////////////////////////////////////////////

    showGridAction = new QAction(tr("&Show Grid"), this);
    showGridAction->setCheckable(true);
    showGridAction->setChecked(spreadsheet->showGrid());
    showGridAction->setStatusTip(tr("Show or hide the spreadsheet's "
                                    "grid"));
    connect(showGridAction, SIGNAL(toggled(bool)),
            spreadsheet, SLOT(setShowGrid(bool)));
#if QT_VERSION < 0x040102
    // workaround for a QTableWidget bug in Qt 4.1.1
    connect(showGridAction, SIGNAL(toggled(bool)),
            spreadsheet->viewport(), SLOT(update()));
#endif

    setDefaultDataAction = new QAction(tr("&Load default data"), this);
    setDefaultDataAction->setCheckable(true);
    setDefaultDataAction->setChecked(m_bIsLoadDefaultData);
    setDefaultDataAction->setStatusTip(tr("Load or not the default data"));
    connect(setDefaultDataAction, SIGNAL(toggled(bool)),
            this, SLOT(setIsLoadDefaultData(bool)));

    autoRecalcAction = new QAction(tr("&Auto-Recalculate"), this);
    autoRecalcAction->setCheckable(true);
    autoRecalcAction->setChecked(spreadsheet->autoRecalculate());
    autoRecalcAction->setStatusTip(tr("Switch auto-recalculation on or "
                                      "off"));
    connect(autoRecalcAction, SIGNAL(toggled(bool)),
            spreadsheet, SLOT(setAutoRecalculate(bool)));

    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setStatusTip(tr("Show the application's About box"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
    //menu被点击后触发的是活动
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    separatorAction = fileMenu->addSeparator();
    for (int i = 0; i < MaxRecentFiles; ++i)
        fileMenu->addAction(recentFileActions[i]);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addAction(deleteAction);

    selectSubMenu = editMenu->addMenu(tr("&Select"));
    selectSubMenu->addAction(selectRowAction);
    selectSubMenu->addAction(selectColumnAction);
    selectSubMenu->addAction(selectAllAction);

    editMenu->addSeparator();
    editMenu->addAction(findAction);
    editMenu->addAction(goToCellAction);

    toolsMenu = menuBar()->addMenu(tr("&Tools"));
    toolsMenu->addAction(recalculateAction);
    toolsMenu->addAction(sortAction);
    toolsMenu->addAction(parseAction);

    optionsMenu = menuBar()->addMenu(tr("&Options"));
    optionsMenu->addAction(showGridAction);
    optionsMenu->addAction(autoRecalcAction);
    optionsMenu->addSeparator();
    optionsMenu->addAction(setDefaultDataAction);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    //helpMenu->addAction(aboutQtAction);
}

void MainWindow::createContextMenu()
{
    spreadsheet->addAction(cutAction);
    spreadsheet->addAction(copyAction);
    spreadsheet->addAction(pasteAction);
    spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);

    editToolBar = addToolBar(tr("&Edit"));
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
    editToolBar->addSeparator();
    editToolBar->addAction(findAction);
    editToolBar->addAction(goToCellAction);
    editToolBar->addAction(parseAction);
}

void MainWindow::createStatusBar()
{
    locationLabel = new QLabel(" W999 ");
    locationLabel->setAlignment(Qt::AlignHCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());

    formulaLabel = new QLabel;
    formulaLabel->setIndent(3);

    statusBar()->addWidget(locationLabel);
    statusBar()->addWidget(formulaLabel, 1);

    connect(spreadsheet, SIGNAL(currentCellChanged(int, int, int, int)),
            this, SLOT(updateStatusBar()));
    connect(spreadsheet, SIGNAL(modified()),
            this, SLOT(spreadsheetModified()));

    updateStatusBar();
}

void MainWindow::readSettings()
{
    QSettings settings("Software Inc.", "Spreadsheet");

    restoreGeometry(settings.value("geometry").toByteArray());

    recentFiles = settings.value("recentFiles").toStringList();
    updateRecentFileActions();

    bool showGrid = settings.value("showGrid", true).toBool();
    showGridAction->setChecked(showGrid);

    bool autoRecalc = settings.value("autoRecalc", true).toBool();
    autoRecalcAction->setChecked(autoRecalc);

    bool showDefaultData = settings.value("loadDefaultData",true).toBool();
    setDefaultDataAction->setChecked(showDefaultData);
}

void MainWindow::writeSettings()
{
    QSettings settings("Software Inc.", "Spreadsheet");

    settings.setValue("geometry", saveGeometry());
    settings.setValue("recentFiles", recentFiles);
    settings.setValue("showGrid", showGridAction->isChecked());
    settings.setValue("autoRecalc", autoRecalcAction->isChecked());
    settings.setValue("loadDefaultData",setDefaultDataAction->isChecked());
}

bool MainWindow::okToContinue()
{
    if (isWindowModified()) {
        int r = QMessageBox::warning(this, tr("Spreadsheet"),
                        tr("The document has been modified.\n"
                           "Do you want to save your changes?"),
                        QMessageBox::Yes | QMessageBox::No
                        | QMessageBox::Cancel);
        if (r == QMessageBox::Yes) {
            return save();
        } else if (r == QMessageBox::Cancel) {
            return false;
        }
    }
    return true;
}

bool MainWindow::loadFile(const QString &fileName)
{
    if (!spreadsheet->readFile(fileName)) {
        statusBar()->showMessage(tr("Loading canceled"), 2000);
        return false;
    }

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
    return true;
}

bool MainWindow::saveFile(const QString &fileName)
{
    if (!spreadsheet->writeFile(fileName)) {
        statusBar()->showMessage(tr("Saving canceled"), 2000);
        return false;
    }

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

void MainWindow::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    setWindowModified(false); //qWidget成员函数

    QString shownName = tr("Untitled");
    if (!curFile.isEmpty()) {
        shownName = strippedName(curFile);
        recentFiles.removeAll(curFile);
        recentFiles.prepend(curFile);
        updateRecentFileActions();
    }

    setWindowTitle(tr("%1[*] - %2").arg(shownName)
                                   .arg(tr("Spreadsheet")));
}

void MainWindow::updateRecentFileActions()
{
    QMutableStringListIterator i(recentFiles);
    while (i.hasNext()) {
        if (!QFile::exists(i.next()))
            i.remove();
    }

    for (int j = 0; j < MaxRecentFiles; ++j) {
        if (j < recentFiles.count()) {
            QString text = tr("&%1 %2")
                           .arg(j + 1)
                           .arg(strippedName(recentFiles[j]));
            recentFileActions[j]->setText(text);
            recentFileActions[j]->setData(recentFiles[j]);
            recentFileActions[j]->setVisible(true);
        } else {
            recentFileActions[j]->setVisible(false);
        }
    }
    separatorAction->setVisible(!recentFiles.isEmpty());
}

QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}
