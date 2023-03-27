#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "addform.h"
#include "dbsender.h"
#include "jsonreaderclass.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();
    Ui::MainWindow* ui;
    QJsonDocument currentDoc;
    QJsonArray currentDocAr;
    QStandardItem* itemToAdd;
    QStandardItem* itemToAddType;
    QStandardItem* itemHeader;
    QMenu* contextMenu = new QMenu(this);
    QAction* addTelemetryRuleAction;
    QStandardItemModel* currentModel;
    QSqlDatabase db;
    QStandardItemModel* returnModel;
    QStringList* ids;
    QStringList oldids;
    QStringList validateObject(QJsonObject obj);
    void connectToDb();
    void connectToDbSqlLite();

private:
    AddForm* addform = new AddForm();
    DBSender* dbssender = new DBSender();

private slots:

    void contextMenuExpand(const QPoint& index);
    void SaveJSON();

    void addTelemetryRule();

    void popupForm();

    void on_pushButton_2_clicked();

    void ReadTelemetry();

    void itemDataValidation(const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles);
    void on_telemetryReadButton_clicked();

    void showAddForm();
    void deleteTelemetryRule();

    QJsonObject toJsonObject(QStandardItem* item);

    void on_MainWindow_destroyed(QObject* arg1);

    void on_searchLine_returnPressed();
    void setNewIdList();
    bool isEqualList();

    void on_dbValuesWindowButton_clicked();

private:
    const static int mko1Max = 30;
    const static int mko2Max = 30;
    const static int mko3Max = 32;
    QStringList searchList = { "id", "Устройству", "Имени", "Сокращению" };
};

#endif // MAINWINDOW_H
