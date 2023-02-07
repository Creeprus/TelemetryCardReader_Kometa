#ifndef ADDFORM_H
#define ADDFORM_H

#include <QDialog>
#include "jsonreaderclass.h"
#include "QStringList"
#include "QStringListModel"
#include "QTableWidget"
#include "QTableWidgetItem"
#include "QSpinBox"

static const QStringList SigTypeAdd{"ЦЕЛОЕ","ВЕЩЕСТВЕННОЕ","ФОК","МЕТАДАННЫЕ","ВРЕМЯ"};
namespace Ui {
class AddForm;
}

class AddForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddForm(QWidget *parent = 0);
    ~AddForm();
   QStandardItemModel* model;
   QStandardItem* itemModel=new QStandardItem();
   QStandardItem* itemToAppend=new QStandardItem();

private slots:
    void on_groupBox_toggled(bool arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);






    void on_MKOTableReal_customContextMenuRequested(const QPoint &pos);


    void on_MKORealDeleteButton_clicked();

    void on_valuesTableFlag_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_2_clicked();

    void on_MKOTableTime_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_3_clicked();

    void on_readMeta_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddForm *ui;
    QStringList typeList={"ЦЕЛОЕ","ФОК","ВЕЩЕСТВЕННОЕ","ВРЕМЯ","МЕТАДАННЫЕ"};
    QStringList byteList={"4","8","16","32","64","128","256"};


};

#endif // ADDFORM_H
