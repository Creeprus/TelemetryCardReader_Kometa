#include "addform.h"
#include "ui_addform.h"

AddForm::AddForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddForm)
{

    ui->setupUi(this);


        ui->groupBoxFlag->hide();

        ui->groupBoxInt->hide();
        ui->groupBoxTime->hide();
        ui->groupBoxMeta->hide();
        ui->comboBox->addItems(typeList);
        ui->bytesCombobox->addItems(byteList);
        ui->bytesCombobox2->addItems(byteList);
}

AddForm::~AddForm()
{
    ui->comboBox->clear();
    delete ui;
}

void AddForm::on_groupBox_toggled(bool arg1)
{

}

void AddForm::on_comboBox_currentTextChanged(const QString &arg1)
{

    if(arg1 == "ВЕЩЕСТВЕННОЕ")
    {
        ui->groupBoxFlag->hide();
        ui->groupBoxInt->hide();
        ui->groupBoxTime->hide();
        ui->groupBoxMeta->hide();
        ui->groupBoxReal->show();

    }
    if(arg1 == "ЦЕЛОЕ")
    {
        ui->groupBoxFlag->hide();

        ui->groupBoxTime->hide();
        ui->groupBoxMeta->hide();
        ui->groupBoxReal->hide();
            ui->groupBoxInt->show();
    }
    if(arg1 == "ВРЕМЯ")
    {
        ui->groupBoxFlag->hide();
        ui->groupBoxInt->hide();

        ui->groupBoxMeta->hide();
        ui->groupBoxReal->hide();
          ui->groupBoxTime->show();
    }
    if(arg1 == "ФОК")
    {

        ui->groupBoxInt->hide();
        ui->groupBoxTime->hide();
        ui->groupBoxMeta->hide();
        ui->groupBoxReal->hide();
         ui->groupBoxFlag->show();
    }
    if(arg1 == "МЕТАДАННЫЕ")
    {
        ui->groupBoxFlag->hide();
        ui->groupBoxInt->hide();
        ui->groupBoxTime->hide();

        ui->groupBoxReal->hide();
           ui->groupBoxMeta->show();
    }
}









void AddForm::on_MKOTableReal_customContextMenuRequested(const QPoint &pos)
{
      ui->MKOTableReal->insertRow(ui->MKOTableReal->rowCount());
}







void AddForm::on_MKORealDeleteButton_clicked()
{
     ui->MKOTableReal->removeRow(ui->MKOTableReal->currentIndex().row());
}


void AddForm::on_valuesTableFlag_customContextMenuRequested(const QPoint &pos)
{
    ui->valuesTableFlag->insertRow(ui->valuesTableFlag->rowCount());
}


void AddForm::on_pushButton_2_clicked()
{
    ui->valuesTableFlag->removeRow(ui->valuesTableFlag->currentIndex().row());
}


void AddForm::on_MKOTableTime_customContextMenuRequested(const QPoint &pos)
{
     ui->MKOTableTime->insertRow(ui->MKOTableTime->rowCount());
}


void AddForm::on_pushButton_3_clicked()
{
       ui->MKOTableTime->removeRow(ui->MKOTableTime->currentIndex().row());
}


void AddForm::on_readMeta_customContextMenuRequested(const QPoint &pos)
{
      ui->readMeta->insertRow(ui->readMeta->rowCount());
}


void AddForm::on_pushButton_4_clicked()
{
     ui->readMeta->removeRow(ui->readMeta->currentIndex().row());
}


void AddForm::on_pushButton_clicked()
{



    QString currentType=ui->comboBox->currentText();
     itemModel->setEditable(false);
    if(currentType==SigTypeAdd[0])
        {
             itemModel=new QStandardItem("Телеметрия устройства: "+ui->controllerInt->toPlainText());
             model->appendRow(itemModel);


             //id

                itemToAppend=new QStandardItem("id");
                itemModel->appendRow(itemToAppend);
                itemToAppend->setEditable(true);



                itemToAppend->appendRow(new QStandardItem(ui->idInt->text()));
                itemToAppend->setEditable(false);
             //имя
             itemToAppend=new QStandardItem("имя");
                itemModel->appendRow(itemToAppend);
                itemToAppend->setEditable(true);
                  itemToAppend->appendRow(new QStandardItem(ui->nameInt->toPlainText()));
                itemToAppend->setEditable(false);
                //устройство

                itemToAppend=new QStandardItem("устройство");
                   itemModel->appendRow(itemToAppend);
                   itemToAppend->setEditable(true);
                     itemToAppend->appendRow(new QStandardItem(ui->controllerInt->toPlainText()));
                   itemToAppend->setEditable(false);

                   // биты
                   itemToAppend=new QStandardItem("биты");
                      itemModel->appendRow(itemToAppend);
                      itemToAppend->setEditable(true);
                        itemToAppend->appendRow(new QStandardItem(ui->bytesCombobox->currentText()));
                      itemToAppend->setEditable(false);


                      // тип
                      itemToAppend=new QStandardItem("тип");
                         itemModel->appendRow(itemToAppend);
                         itemToAppend->setEditable(true);
                           itemToAppend->appendRow(new QStandardItem(SigTypeAdd[0]));
                         itemToAppend->setEditable(false);

                         //мко
                         itemToAppend=new QStandardItem("мко");
                            itemModel->appendRow(itemToAppend);
                            itemToAppend->setEditable(true);
                            for(int i=0;i< ui->MKOTableInt->columnCount();i++)
                            {

                                  itemToAppend->appendRow(new QStandardItem(ui->MKOTableInt->item(0,i)->text()));
                            }

                            itemToAppend->setEditable(false);





        }

    if(currentType==SigTypeAdd[1])
        {

        itemModel=new QStandardItem("Телеметрия устройства: "+ui->controllerReal->text());
        itemModel->setEditable(false);
        model->appendRow(itemModel);

        //id

           itemToAppend=new QStandardItem("id");
           itemModel->appendRow(itemToAppend);
           itemToAppend->setEditable(true);



           itemToAppend->appendRow(new QStandardItem(ui->idReal->text()));
           itemToAppend->setEditable(false);
        //имя
        itemToAppend=new QStandardItem("имя");
           itemModel->appendRow(itemToAppend);
           itemToAppend->setEditable(true);
             itemToAppend->appendRow(new QStandardItem(ui->nameReal->text()));
           itemToAppend->setEditable(false);
           //устройство

           itemToAppend=new QStandardItem("устройство");
              itemModel->appendRow(itemToAppend);
              itemToAppend->setEditable(true);
                itemToAppend->appendRow(new QStandardItem(ui->controllerReal->text()));
              itemToAppend->setEditable(false);
              //мко
              itemToAppend=new QStandardItem("мко");
                 itemModel->appendRow(itemToAppend);
                 itemToAppend->setEditable(true);
                 for(int i=0;i< ui->MKOTableReal->rowCount();i++)
                 {

                QStandardItem* currentItem= new QStandardItem(QString("Значение %1").arg(i));
                currentItem->setEditable(false);
                itemToAppend->appendRow(currentItem);
                    for(int j=0;j<ui->MKOTableReal->columnCount();j++)
                    {
                         currentItem->appendRow(new QStandardItem(ui->MKOTableReal->item(i,j)->text()));
                    }
                 }

                 itemToAppend->setEditable(false);

              // тип
              itemToAppend=new QStandardItem("тип");
                 itemModel->appendRow(itemToAppend);
                 itemToAppend->setEditable(true);
                   itemToAppend->appendRow(new QStandardItem(SigTypeAdd[1]));
                 itemToAppend->setEditable(false);

        }
       ui->treeView->setModel(model);
       this->close();
}

