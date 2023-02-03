#include "addform.h"
#include "ui_addform.h"

AddForm::AddForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddForm)
{

    ui->setupUi(this);


       ui->comboBox->addItems(typeList);
           ui->bytesCombobox->addItems(byteList);
}

AddForm::~AddForm()
{
    ui->comboBox->clear();
    delete ui;
}
