#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "jsonreaderclass.h"
#include "addform.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
    QJsonDocument currentDoc;
    QJsonArray currentDocAr;
    QStandardItem* itemToAdd;
    QStandardItem* itemHeader;
    QMenu* contextMenu=new QMenu(this);
    QAction* addTelemetryRuleAction;
    QStandardItemModel* currentModel;



private:

    AddForm *addform= new AddForm();

private slots:

    void contextMenuExpand(const QPoint &index);
    void SaveJSON();

    void addTelemetryRule();

    void popupForm();

    void on_pushButton_2_clicked();

    void ReadTelemetry();

    void itemDataValidation(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);
    void on_telemetryReadButton_clicked();

    void showAddForm();
    void deleteTelemetryRule();




};

#endif // MAINWINDOW_H
