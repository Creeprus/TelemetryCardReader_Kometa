#ifndef DBSENDER_H
#define DBSENDER_H

#include "addform.h"
#include "jsonreaderclass.h"

#include <QWidget>

namespace Ui {
class DBSender;
}

class DBSender : public QDialog {
    Q_OBJECT

public:
    explicit DBSender(QWidget* parent = 0);
    ~DBSender();

    QStandardItemModel* model;
    QStandardItem* itemModel = new QStandardItem();
    QStandardItem* itemToAppend = new QStandardItem();
    QStandardItem* itemToAppendType = new QStandardItem();
    void initValues();
    QSqlDatabase db;
    QJsonDocument currentDoc;
    QStandardItem* itemHeader;
    QStandardItem* itemToAdd = new QStandardItem("");
    QStringList itemTypes;
    void sendToDb(int id, QVariant data, QVariant dataValue);

    void sendToDb(int id, QVariant data, QVariant dataValue, QVariant dataScriptValue, QVariant dataScriptColor);
private slots:
    void on_senToDbButton_clicked();

private:
    Ui::DBSender* ui;
};

#endif // DBSENDER_H
