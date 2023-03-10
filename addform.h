#ifndef ADDFORM_H
#define ADDFORM_H

#include "QSpinBox"
#include "QStringList"
#include "QStringListModel"
#include "QTableWidget"
#include "QTableWidgetItem"
#include "QtMath"
#include "jsonreaderclass.h"
#include <QDialog>

static const QStringList SigTypeAdd{ "ЦЕЛОЕ", "ВЕЩЕСТВЕННОЕ", "ФОК", "МЕТАДАННЫЕ", "ВРЕМЯ" };
namespace Ui {
class AddForm;
}

class AddForm : public QDialog {
    Q_OBJECT

public:
    explicit AddForm(QWidget* parent = 0);
    ~AddForm();
    QStandardItemModel* model;
    QStandardItem* itemModel = new QStandardItem();
    QStandardItem* itemToAppend = new QStandardItem();
    QStandardItem* itemToAppendType = new QStandardItem();
    QStringList* idsToCheck;

private slots:
    void on_groupBox_toggled(bool arg1);

    void on_comboBox_currentTextChanged(const QString& arg1);

    void on_MKOTableReal_customContextMenuRequested(const QPoint& pos);

    void on_MKORealDeleteButton_clicked();

    void on_valuesTableFlag_customContextMenuRequested(const QPoint& pos);

    void on_pushButton_2_clicked();

    void on_MKOTableTime_customContextMenuRequested(const QPoint& pos);

    void on_pushButton_3_clicked();

    void on_readMeta_customContextMenuRequested(const QPoint& pos);

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddForm* ui;
    QStringList typeList = { "ЦЕЛОЕ", "ФОК", "ВЕЩЕСТВЕННОЕ", "ВРЕМЯ", "МЕТАДАННЫЕ" };
    QStringList byteList = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15" };
    const static int mko1Max = 30;
    const static int mko2Max = 30;
    const static int mko3Max = 32;
};

#endif // ADDFORM_H
