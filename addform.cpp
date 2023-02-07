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
