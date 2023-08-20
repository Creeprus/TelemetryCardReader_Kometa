#ifndef JSONREADERCLASS_H
#define JSONREADERCLASS_H
#include "QDebug"
#include "QFile"
#include "QFileDialog"
#include "QFrame"
#include "QJsonArray"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonValue"
#include "QLabel"
#include "QLineEdit"
#include "QListWidgetItem"
#include "QMenu"
#include "QMessageBox"
#include "QObject"
#include "QSortFilterProxyModel"
#include "QStandardItemModel"
#include "QString"
#include "QVariant"
#include "QWidget"
#include <QSqlQuery>
#include <QtSql/QSqlDatabase>

enum SigType {
    REAL = 0,
    INT = 1,
    FLAG = 2,
    META = 3,
    TIME = 4,
    INVALID = 5
};
class JSONReaderClass {
public:
    JSONReaderClass();
    QJsonDocument readJSON();

    void saveJSON(QString saveFileName, QJsonDocument doc);
    QJsonDocument getEditJSON(QString saveFileName);
    QJsonDocument currentDoc;
    QJsonObject currentJSONObject;
    QFile file;
    SigType getType(QStandardItem* item);
    QJsonObject getObject(QStandardItem* item, SigType type);
};

#endif // JSONREADERCLASS_H
