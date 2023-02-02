#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jsonreaderclass.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
 ui->setupUi(this);
 contextMenu=new QMenu(ui->treeView);

 contextMenu->addAction("Добавить правило",this,
                        SLOT(showAddForm()));

 contextMenu->addAction("Удалить правило",this,
                        SLOT(deleteTelemetryRule()));


 ui->treeView->setContextMenuPolicy(Qt::CustomContextMenu);



 connect(ui->treeView,&QTreeView::customContextMenuRequested,this,
         &MainWindow::contextMenuExpand);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::contextMenuExpand(const QPoint &point)
{
    QModelIndex curIndex=ui->treeView->indexAt(point);
    QModelIndex index=curIndex.sibling(curIndex.row(),0);

    if(index.isValid())
    {

      auto cur=QCursor::pos();
      contextMenu->move(cur);
      contextMenu->show();

    }

}



void MainWindow::SaveJSON()
{
    QString saveFileName=QFileDialog::getOpenFileName(
                                                       this,
                                                      "Сохранить файл JSON",
                                                      QDir::homePath(),
                                                     "JSON (*.json)");
    QJsonArray finalArray;
    JSONReaderClass json;


   // auto model=ui->treeView->model();
    QStandardItemModel* model=new QStandardItemModel(nullptr);
    QSortFilterProxyModel* currentModel=new QSortFilterProxyModel();
    QJsonDocument doc;

    auto abstract_model=ui->treeView->model();
    currentModel->setSourceModel(abstract_model);

    for (int i=0;i<currentModel->rowCount();i++)
    {

      auto item=  currentModel->data(currentModel->index(i,0));
    ui->textBrowser->append(item.toByteArray());
        auto array=item.toJsonArray();

        qDebug()<<item.data();
        for(int j=0;j<item.toJsonObject().size();j++)
        {
            finalArray.append(array.at(j));
        }


    }
   model=new QStandardItemModel(abstract_model);
   // ui->treeView->selectionModel();
    doc.setArray(finalArray);






    json.saveJSON(saveFileName,doc);
}

void MainWindow::addTelemetryRule()
{

    auto model=ui->treeView->model();
    qDebug()<<model->columnCount();

}

void MainWindow::popupForm()
{
//    QFrame* popup=new QFrame(this,Qt::Popup|Qt::Window);
//    popup->resize(300,300);
//    QLineEdit *tmp=new QLineEdit(popup);
//    connect(tmp,SIGNAL(returnPressed()),popup,SLOT(hide()));
//    tmp->setGeometry(50,50,130,30);
//    tmp->setFocus();
//    auto cur=QCursor::pos();
//    popup->move(cur);
//    popup->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    SaveJSON();
}



void MainWindow::ReadTelemetry()
{

    JSONReaderClass json;
    QJsonDocument doc;
    doc=json.readJSON();
    currentDoc=doc;
    QJsonObject obj;
    QStandardItemModel* model=new QStandardItemModel(nullptr);
    QStandardItem* header=new QStandardItem(json.file.fileName());

    model->setHorizontalHeaderItem(0,header);
    connect(model,&QStandardItemModel::dataChanged,this,&MainWindow::itemDataValidation);
    QJsonArray json_aray=currentDoc.array();

     if(json_aray.isEmpty()==false)
     {
         for (int i=0;i<json_aray.size();i++)
         {

            obj=json_aray[i].toObject();
            auto head = obj.value("устройство").toVariant().toString();
            if(head.isEmpty())
            {
                auto head = obj.value("id времени").toVariant().toString();
                itemHeader=new QStandardItem("Сигнал устройства с id "+head);

            }
            itemHeader=new QStandardItem("Телеметрия устройства: "+head);
            itemHeader->setEditable(false);
            model->appendRow(itemHeader);

            for(int j=0;j<obj.size();j++)
            {
                auto key=obj.keys().at(j);
                auto value = obj.value(key);
                if(value.isString())
                {
                    itemToAdd=new QStandardItem(key);
                    itemToAdd->setEditable(true);
                    itemHeader->appendRow(itemToAdd);
                    itemToAdd->appendRow(new QStandardItem(value.toVariant().toString()));
                    itemToAdd->setEditable(false);

                }
                else if(value.toVariant().toInt())
                {
                    itemToAdd=new QStandardItem(key);
                    itemToAdd->setEditable(true);
                    itemHeader->appendRow(itemToAdd);
                    itemToAdd->appendRow(new QStandardItem(value.toVariant().toString()));
                    itemToAdd->setEditable(false);

                }
                else if(value.isArray())
                {

                    if(value[0].isArray())
                    {
                        itemToAdd=new QStandardItem(key);
                        itemToAdd->setEditable(true);
                        itemHeader->appendRow(itemToAdd);
                        QJsonArray ar=value.toArray();

                        int j=0;

                        for (QJsonValue value:ar)
                        {
                            QJsonArray ar2=value.toArray();

                            quint16 currentValue=j+1;

                            QStandardItem* currentItem= new QStandardItem(QString("Значение %1").arg(currentValue));
                            currentItem->setEditable(false);
                            itemToAdd->appendRow(currentItem);

                            for (int ix=0;ix<ar2.size();ix++)
                            {
                                QStandardItem* item=new QStandardItem(ar2[ix].toVariant().toString());
                                 currentItem->appendRow(item);
                            }



                            j++;
                        }
                        itemToAdd->setEditable(false);
                    }
                    else
                    {
                       itemToAdd=new QStandardItem(key);
                       itemHeader->appendRow(itemToAdd);
                       itemToAdd->setEditable(true);
                       QJsonArray itemArray=value.toArray();
                       for (int j=0;j<itemArray.count();j++)
                       {
                           itemToAdd->appendRow(new QStandardItem(itemArray[j].toVariant().toString()));

                       }
                       itemToAdd->setEditable(false);
                    }
                }
            }
         }
           ui->treeView->setModel(model);
           currentModel=model;
     }

}

void MainWindow::itemDataValidation(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles)
{
    qDebug()<<topLeft.data();
    qDebug()<<bottomRight.data();

}




void MainWindow::on_telemetryReadButton_clicked()
{
    ReadTelemetry();
}

void MainWindow::showAddForm()
{
    addform->show();
}

void MainWindow::deleteTelemetryRule()
{

    QAbstractItemModel* model=ui->treeView->model();
    QModelIndex curIndex=ui->treeView->currentIndex();



     while(curIndex.parent().isValid())
     {
         curIndex=curIndex.parent();
     }
     int idx=curIndex.row();
     model->removeRow(idx);
       // currentModel=model;


}

//Построчное выборочное удаление
//void MainWindow::deleteTelemetryRule()
//{

//    QAbstractItemModel* model=ui->treeView->model();
//    QModelIndex curIndex=ui->treeView->currentIndex();
//    int idx=curIndex.row();

//    model->removeRow(idx,curIndex.parent());
//    ui->treeView->setModel(model);

//}
