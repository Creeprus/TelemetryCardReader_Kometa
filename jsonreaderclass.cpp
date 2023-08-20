#include "jsonreaderclass.h"

JSONReaderClass::JSONReaderClass()
{

}

QJsonDocument JSONReaderClass::readJSON()
{
    QString val;

    QFileDialog dialog;


    dialog.open();
dialog.hide();
 dialog.close();
    file.setFileName(dialog.getOpenFileName());



    file.open(QIODevice::ReadOnly|QIODevice::Text);
    val=file.readAll();

    file.close();



    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());



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

    jsonFile.write(doc.toJson(QJsonDocument::Indented));
    qDebug() << doc;
    jsonFile.close();
}

QJsonDocument JSONReaderClass::getEditJSON(QString saveFileName)
{
    QString val;
    QFile file;



    file.setFileName(saveFileName);

   file.open(QIODevice::ReadOnly|QIODevice::Text);
    val=file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());


    return doc;
}

SigType JSONReaderClass::getType(QStandardItem *item)
{
     QString type;
    for (int j=0;j<item->rowCount();j++)
    {

         type=item->child(j)->text();
       if(type==QString("тип"))
       {
           type=item->child(j)->child(0)->text();
           break;
       }
    }
    if(type=="ВЕЩЕСТВЕННОЕ")
    {
        return SigType::REAL;
    }
    if(type=="ЦЕЛОЕ")
    {
        return SigType::INT;
    }
    if(type=="ВРЕМЯ")
    {
        return SigType::TIME;
    }
    if(type=="ФОК")
    {
        return SigType::FLAG;
    }
    if(type=="МЕТАДАННЫЕ")
    {
        return SigType::META;
    }
    return SigType::INVALID;
}

QJsonObject JSONReaderClass::getObject(QStandardItem *item, SigType type)
{
    QJsonObject finalObject;
     QJsonArray intArray;
     QJsonArray arrayOfArrays;

    switch (type)
    {

    case SigType::INT:
        {
         for (int i=0;i<item->rowCount();i++)
            {

                    if(item->child(i)->text()=="id")
                    {
                finalObject.insert(item->child(i)->text(),
                                   QJsonValue(item->child(i)->child(0)->text().toInt()));
                    }
                    if(item->child(i)->text()=="тип" ||
                            item->child(i)->text()=="имя" ||
                            item->child(i)->text()=="устройство" ||
                          //  item->child(i)->text()=="сокращение" ||
                            item->child(i)->text()=="биты")
                    {
                        finalObject.insert(item->child(i)->text(),
                                           QJsonValue(item->child(i)->child(0)->text()));

                    }
                    if(item->child(i)->text()=="мко" )
                    {
                        for(int j=0;j<item->child(i)->rowCount();j++)
                        {

                            intArray.append(QJsonValue(item->child(i)->child(j)->text().toInt()));
                      }
                        finalObject.insert(item->child(i)->text(),
                                           QJsonValue(intArray));

                    }
            }

             break;
    case SigType::REAL:
    {
    for (int i=0;i<item->rowCount();i++)
       {

               if(item->child(i)->text()=="id")
               {
           finalObject.insert(item->child(i)->text(),
                              QJsonValue(item->child(i)->child(0)->text().toInt()));
               }
               if(item->child(i)->text()=="тип" ||
                       item->child(i)->text()=="имя" ||
                       item->child(i)->text()=="устройство"
                     )
               {
                   finalObject.insert(item->child(i)->text(),
                                      QJsonValue(item->child(i)->child(0)->text()));

               }
               if(item->child(i)->text()=="мко" )
               {
                   for(int j=0;j<item->child(i)->rowCount();j++)
                   {
                        for(int k=0;k<item->child(i)->child(j)->rowCount();k++)
                       intArray.append(QJsonValue(item->child(i)->child(j)->child(k)->text().toInt()));
                        arrayOfArrays.append(QJsonValue(intArray));
                        intArray= QJsonArray();
                 }
                   finalObject.insert(item->child(i)->text(),
                                      QJsonValue(arrayOfArrays));

               }
       }
    }
        break;
    }
    case SigType::TIME:
    {
        for (int i=0;i<item->rowCount();i++)
           {

                   if(item->child(i)->text()=="id")
                   {
               finalObject.insert(item->child(i)->text(),
                                  QJsonValue(item->child(i)->child(0)->text().toInt()));
                   }
                   if(item->child(i)->text()=="тип" ||
                           item->child(i)->text()=="имя" ||
                           item->child(i)->text()=="устройство"

                         )
                   {
                       finalObject.insert(item->child(i)->text(),
                                          QJsonValue(item->child(i)->child(0)->text()));

                   }
                   if(item->child(i)->text()=="мко" )
                   {
                       for(int j=0;j<item->child(i)->rowCount();j++)
                       {
                            for(int k=0;k<item->child(i)->child(j)->rowCount();k++)
                           intArray.append(QJsonValue(item->child(i)->child(j)->child(k)->text().toInt()));
                            arrayOfArrays.append(QJsonValue(intArray));
                            intArray= QJsonArray();
                     }
                       finalObject.insert(item->child(i)->text(),
                                          QJsonValue(arrayOfArrays));

                   }
           }
        break;
    }
    case SigType::META:
    {
        for (int i=0;i<item->rowCount();i++)
           {

                   if(item->child(i)->text()=="id времени")
                   {
               finalObject.insert(item->child(i)->text(),
                                  QJsonValue(item->child(i)->child(0)->text().toInt()));
                   }
                   if(item->child(i)->text()=="тип"

                         )
                   {
                       finalObject.insert(item->child(i)->text(),
                                          QJsonValue(item->child(i)->child(0)->text()));

                   }
                   if(item->child(i)->text()=="id ПДЦМ" )
                   {
                       for(int j=0;j<item->child(i)->rowCount();j++)
                       {

                           intArray.append(QJsonValue(item->child(i)->child(j)->text().toInt()));
                     }
                       finalObject.insert(item->child(i)->text(),
                                          QJsonValue(intArray));
                        intArray=QJsonArray();

                   }
                   if(item->child(i)->text()=="читать" )
                   {
                       for(int j=0;j<item->child(i)->rowCount();j++)
                       {

                           intArray.append(QJsonValue(item->child(i)->child(j)->child(0)->text().toInt()));
                           intArray.append(QJsonValue(item->child(i)->child(j)->child(1)->text().toInt()));
                           intArray.append(QJsonValue(item->child(i)->child(j)->child(2)->text().toInt()));



                           arrayOfArrays.append(QJsonValue(intArray));
                           intArray= QJsonArray();
                     }
                       finalObject.insert(item->child(i)->text(),
                                          QJsonValue(arrayOfArrays));
                       intArray=QJsonArray();

                   }
           }
        break;
    }
    case SigType::FLAG:
    {
        for (int i=0;i<item->rowCount();i++)
           {

                   if(item->child(i)->text()=="id")
                   {
               finalObject.insert(item->child(i)->text(),
                                  QJsonValue(item->child(i)->child(0)->text().toInt()));
                   }
                   if(item->child(i)->text()=="тип" ||
                           item->child(i)->text()=="имя" ||
                           item->child(i)->text()=="устройство" ||
                           item->child(i)->text()=="сокращение" ||
                           item->child(i)->text()=="биты"
                         )
                   {
                       finalObject.insert(item->child(i)->text(),
                                          QJsonValue(item->child(i)->child(0)->text()));

                   }
                   if(item->child(i)->text()=="значения" )
                   {
                       for (int j = 0; j < item->child(i)->rowCount(); j++) {
                           qDebug() << ("First " + item->child(i)->child(j)->child(0)->text());
                           qDebug() << ("Second " + item->child(i)->child(j)->child(1)->text());
                           bool conv = true;
                           item->child(i)->child(j)->child(0)->text().toInt(&conv);
                           if (conv == false) {
                               intArray.append(QJsonValue(item->child(i)->child(j)->child(1)->text().toInt()));
                               intArray.append(QJsonValue(item->child(i)->child(j)->child(0)->text()));
                           } else {
                               intArray.append(QJsonValue(item->child(i)->child(j)->child(0)->text().toInt()));
                               intArray.append(QJsonValue(item->child(i)->child(j)->child(1)->text()));
                           }


                           arrayOfArrays.append(QJsonValue(intArray));
                           intArray= QJsonArray();
                     }
                       finalObject.insert(item->child(i)->text(),
                                          QJsonValue(arrayOfArrays));
                       intArray=QJsonArray();

                   }
                   if(item->child(i)->text()=="мко" )
                   {
                       for(int j=0;j<item->child(i)->rowCount();j++)
                       {

                           intArray.append(QJsonValue(item->child(i)->child(j)->text().toInt()));
                       }
                       finalObject.insert(item->child(i)->text(),
                                          QJsonValue(intArray));
                         intArray=QJsonArray();
                   }
           }
        break;
    }
    case SigType::INVALID:
    {
    finalObject.insert("invalid data",
                       "Данные телеметрии были введены неправильно");

        break;
    }
        }

    return finalObject;

    }





