#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QStackedBarSeries>
#include "pjarea.h"

class QAction;
class QLabel;
class FindDialog;
class Spreadsheet;

class QIcon;
class QSplitter;
class QTextEdit;
class QTreeWidget;
//class QStackedBarSeries;

//用QT的QChartView,必须用这个
QT_CHARTS_USE_NAMESPACE

typedef map<int,country*>::const_iterator countryIter;

typedef QPair<QPointF, QString> Data;
typedef QList<Data> DataList;
typedef QList<DataList> DataTable;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void find();
    void goToCell();
    void sort();
    void parse();
    void about();
    void openRecentFile();
    void updateStatusBar();
    void spreadsheetModified();
    void shiftFile(QTreeWidgetItem* item, int column);
    bool setIsLoadDefaultData(bool isLoadDefaultData);
    void sheetChanged();

private:
    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();
    void createInfo();
    void readSettings();
    void writeSettings();
    bool okToContinue();
    bool loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    QString strippedName(const QString &fullFileName);
    void addFolder(const QIcon &icon, const QString &name);
    void drawChartView(QChartView* curChartView,string& title,vector<string>& cateGor, map<string,vector<double>> charItem);
    void initSpSheetByDefaultData();
    void fillSpreadsheet(Spreadsheet* form, countryIter begin,countryIter end, int sRow, int sColumn, bool isInsertBlankRow=false);
    void fillSpreadsheetHeader(Spreadsheet* form, bool isInsertBlankRow=false);
    void createTree();
    void setTreeDisable(bool bIsDisabled);

    void drawOriData(); //画原始结果图
    void drawResult(); //画结果图


    Spreadsheet *spreadsheet; //原始表
    Spreadsheet *spreadsheetGYH; //原始信息带归一化的表
    Spreadsheet *spreadsheetResult; //带除了归一化外所有数据的表
    FindDialog *findDialog;
    QLabel *locationLabel;
    QLabel *formulaLabel;
    QStringList recentFiles;
    QString curFile;

    enum { MaxRecentFiles = 5 };
    QAction *recentFileActions[MaxRecentFiles];
    QAction *separatorAction;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *selectSubMenu;
    QMenu *toolsMenu;
    QMenu *optionsMenu;
    QMenu *helpMenu;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *exitAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *deleteAction;
    QAction *selectRowAction;
    QAction *selectColumnAction;
    QAction *selectAllAction;
    QAction *findAction;
    QAction *goToCellAction;
    QAction *recalculateAction;
    QAction *sortAction;
    QAction *parseAction;
    QAction *showGridAction;
    QAction *autoRecalcAction;
    QAction *aboutAction;
    QAction *aboutQtAction;
    QAction *setDefaultDataAction;

    //palad 新增
    QSplitter *mainSplitter;
    QSplitter *rightSplitter;
    QTreeWidget *foldersTreeWidget;
    QTextEdit* textEdit;
    QChartView* chartView;
    QChartView* charViewResult;
    pjarea*  pjArea;
    bool m_bIsLoadDefaultData;
    bool m_bIsNewSheet; //数据是最新的吗?
};

#endif
