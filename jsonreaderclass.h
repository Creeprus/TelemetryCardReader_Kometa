#ifndef JSONREADERCLASS_H
#define JSONREADERCLASS_H
#include "QMessageBox"
#include "QWidget"
#include "QLabel"
#include "QObject"
#include "QString"
#include "QFile"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonValue"
#include "QFileDialog"
#include "QListWidgetItem"
#include "QStandardItemModel"
#include "QDebug"
#include "QMenu"
#include "QFrame"
#include "QLineEdit"
#include "QSortFilterProxyModel"


enum SigType
{
    REAL=0,
    INT=1,
    FLAG=2,
    META=3,
    TIME=4,
    INVALID=5
};
class JSONReaderClass
{
public:
    JSONReaderClass();
    QJsonDocument readJSON();

    void saveJSON(QString saveFileName,QJsonDocument doc);
    QJsonDocument getEditJSON(QString saveFileName);
    QJsonDocument currentDoc;
    QJsonObject currentJSONObject;
    QFile file;
    SigType getType(QStandardItem* item);
    QJsonObject getObject(QStandardItem* item,SigType type);
};

#endif // JSONREADERCLASS_H
