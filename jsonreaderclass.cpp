#include "jsonreaderclass.h"

JSONReaderClass::JSONReaderClass()
{

}

QJsonDocument JSONReaderClass::readJSON()
{
    QString val;

    QFileDialog dialog;


    dialog.open();

    file.setFileName(dialog.getOpenFileName());

    file.open(QIODevice::ReadOnly|QIODevice::Text);
    val=file.readAll();

    file.close();


    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    if(doc.isObject())
    {
       QJsonObject jsonobject=doc.object();
       jsonobject.keys();
    }


    return doc;

}

void JSONReaderClass::saveJSON( QString saveFileName,QJsonDocument doc)
{

    QFileInfo fileInfo(saveFileName);
    QDir::setCurrent(fileInfo.path());
    QFile jsonFile(saveFileName);
    if(!jsonFile.open(QIODevice::WriteOnly))
    {
        return;
    }
    //jsonFile.write(QJsonDocument(currentJSONObject).toJson(QJsonDocument::Indented));
    jsonFile.write(doc.toJson(QJsonDocument::Indented));

    jsonFile.close();
}

QJsonDocument JSONReaderClass::getEditJSON(QString saveFileName)
{
    QString val;
    QFile file;



    file.setFileName(saveFileName);
   // file.setFileName("jsontest.json");
   file.open(QIODevice::ReadOnly|QIODevice::Text);
    val=file.readAll();
    file.close();
   // qWarning()<<val;

    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    if(doc.isObject())
    {
       QJsonObject jsonobject=doc.object();
       jsonobject.keys();
    }
    return doc;
}



