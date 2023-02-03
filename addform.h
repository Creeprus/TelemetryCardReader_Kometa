#ifndef ADDFORM_H
#define ADDFORM_H

#include <QDialog>
#include "jsonreaderclass.h"
#include "QStringList"
#include "QStringListModel"

namespace Ui {
class AddForm;
}

class AddForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddForm(QWidget *parent = 0);
    ~AddForm();

private:
    Ui::AddForm *ui;
    QStringList typeList={"ВЕЩЕСТВЕННОЕ","ФОК","ЦЕЛОЕ","ВРЕМЯ","МЕТАДАННЫЕ"};
    QStringList byteList={"8","16","32","64","128","256"};


};

#endif // ADDFORM_H
