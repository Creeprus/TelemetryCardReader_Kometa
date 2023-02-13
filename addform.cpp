#include "addform.h"
#include "ui_addform.h"

AddForm::AddForm(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::AddForm)
{

    ui->setupUi(this);

    ui->groupBoxFlag->hide();

    ui->groupBoxInt->hide();
    ui->groupBoxTime->hide();
    ui->groupBoxMeta->hide();
    ui->comboBox->addItems(typeList);
    ui->bytesCombobox->addItems(byteList);
    ui->bytesCombobox2->addItems(byteList);
    ui->bytesCombobox2_2->addItems(byteList);
    ui->valuesTableFlag->setItemDelegateForColumn(0, nullptr);
}

AddForm::~AddForm()
{
    ui->comboBox->clear();
    delete ui;
}

void AddForm::on_groupBox_toggled(bool arg1)
{
}

void AddForm::on_comboBox_currentTextChanged(const QString& arg1)
{

    if (arg1 == "ВЕЩЕСТВЕННОЕ") {
        ui->groupBoxFlag->hide();
        ui->groupBoxInt->hide();
        ui->groupBoxTime->hide();
        ui->groupBoxMeta->hide();
        ui->groupBoxReal->show();
    }
    if (arg1 == "ЦЕЛОЕ") {
        ui->groupBoxFlag->hide();

        ui->groupBoxTime->hide();
        ui->groupBoxMeta->hide();
        ui->groupBoxReal->hide();
        ui->groupBoxInt->show();
    }
    if (arg1 == "ВРЕМЯ") {
        ui->groupBoxFlag->hide();
        ui->groupBoxInt->hide();

        ui->groupBoxMeta->hide();
        ui->groupBoxReal->hide();
        ui->groupBoxTime->show();
    }
    if (arg1 == "ФОК") {

        ui->groupBoxInt->hide();
        ui->groupBoxTime->hide();
        ui->groupBoxMeta->hide();
        ui->groupBoxReal->hide();
        ui->groupBoxFlag->show();
    }
    if (arg1 == "МЕТАДАННЫЕ") {
        ui->groupBoxFlag->hide();
        ui->groupBoxInt->hide();
        ui->groupBoxTime->hide();

        ui->groupBoxReal->hide();
        ui->groupBoxMeta->show();
    }
}

void AddForm::on_MKOTableReal_customContextMenuRequested(const QPoint& pos)
{
    ui->MKOTableReal->insertRow(ui->MKOTableReal->rowCount());
}

void AddForm::on_MKORealDeleteButton_clicked()
{
    ui->MKOTableReal->removeRow(ui->MKOTableReal->currentIndex().row());
}

void AddForm::on_valuesTableFlag_customContextMenuRequested(const QPoint& pos)
{

    ui->valuesTableFlag->insertRow(ui->valuesTableFlag->rowCount());

    ui->valuesTableFlag->setItem(ui->valuesTableFlag->rowCount(), 0, new QTableWidgetItem);
}

void AddForm::on_pushButton_2_clicked()
{
    ui->valuesTableFlag->removeRow(ui->valuesTableFlag->currentIndex().row());
}

void AddForm::on_MKOTableTime_customContextMenuRequested(const QPoint& pos)
{
    ui->MKOTableTime->insertRow(ui->MKOTableTime->rowCount());
}

void AddForm::on_pushButton_3_clicked()
{
    ui->MKOTableTime->removeRow(ui->MKOTableTime->currentIndex().row());
}

void AddForm::on_readMeta_customContextMenuRequested(const QPoint& pos)
{
    ui->readMeta->insertRow(ui->readMeta->rowCount());
}

void AddForm::on_pushButton_4_clicked()
{
    ui->readMeta->removeRow(ui->readMeta->currentIndex().row());
}

void AddForm::on_pushButton_clicked()
{

    int numBits = 0;
    QMessageBox* box = new QMessageBox();
    QString currentType = ui->comboBox->currentText();
    itemModel = new QStandardItem();
    itemModel->setEditable(false);
    // Целое
    if (currentType == SigTypeAdd[0]) {
        itemModel = new QStandardItem("Телеметрия устройства: " + ui->controllerInt->toPlainText());
        model->appendRow(itemModel);

        //id

        itemToAppend = new QStandardItem("id");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);

        itemToAppend->appendRow(new QStandardItem(ui->idInt->text()));
        itemToAppend->setEditable(false);
        //имя
        itemToAppend = new QStandardItem("имя");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(ui->nameInt->toPlainText()));
        itemToAppend->setEditable(false);
        //устройство

        itemToAppend = new QStandardItem("устройство");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(ui->controllerInt->toPlainText()));
        itemToAppend->setEditable(false);

        // биты
        itemToAppend = new QStandardItem("биты");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(ui->bytesCombobox->currentText()));
        itemToAppend->setEditable(false);

        // тип
        itemToAppend = new QStandardItem("тип");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(SigTypeAdd[0]));
        itemToAppend->setEditable(false);

        //мко
        itemToAppend = new QStandardItem("мко");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);
        for (int i = 0; i < ui->MKOTableInt->columnCount(); i++) {

            itemToAppend->appendRow(new QStandardItem(ui->MKOTableInt->item(0, i)->text()));
        }

        itemToAppend->setEditable(false);

        this->close();
    }
    // Вещественное
    if (currentType == SigTypeAdd[1]) {

        itemModel = new QStandardItem("Телеметрия устройства: " + ui->controllerReal->text());
        itemModel->setEditable(false);
        model->appendRow(itemModel);

        //id

        itemToAppend = new QStandardItem("id");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);

        itemToAppend->appendRow(new QStandardItem(ui->idReal->text()));
        itemToAppend->setEditable(false);
        //имя
        itemToAppend = new QStandardItem("имя");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(ui->nameReal->text()));
        itemToAppend->setEditable(false);
        //устройство

        itemToAppend = new QStandardItem("устройство");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(ui->controllerReal->text()));
        itemToAppend->setEditable(false);
        //мко
        itemToAppend = new QStandardItem("мко");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);
        for (int i = 0; i < ui->MKOTableReal->rowCount(); i++) {

            QStandardItem* currentItem = new QStandardItem(QString("Значение %1").arg(i));
            currentItem->setEditable(false);
            itemToAppend->appendRow(currentItem);
            for (int j = 0; j < ui->MKOTableReal->columnCount(); j++) {
                currentItem->appendRow(new QStandardItem(ui->MKOTableReal->item(i, j)->text()));
            }
        }

        itemToAppend->setEditable(false);

        // тип
        itemToAppend = new QStandardItem("тип");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(SigTypeAdd[1]));
        itemToAppend->setEditable(false);
        this->close();
    }
    // ФОК

    if (currentType == SigTypeAdd[2]) {
        auto min = ui->bytesCombobox2->currentText().toInt();
        auto max = ui->bytesCombobox2_2->currentText().toInt();
        if (min > max)
            std::swap(min, max);

        numBits = max - min + 1;
        int maxPossibleValue = (1 << numBits);

        auto numberOfValues = ui->valuesTableFlag->rowCount();
        struct ValueWithMeaning {
            int number = 0;
            QString meaning = "";
        };
        QVector<ValueWithMeaning> vector;
        if (ui->valuesTableFlag->rowCount() < 1) {
            box->setText("Поля не должны быть пустыми");
            box->show();
            return;
        }
        for (int a = 0; a < ui->valuesTableFlag->rowCount(); a++) {
            QTableWidgetItem* item = ui->valuesTableFlag->item(a, 0);
            if (!item || item->text().isEmpty()) {
                box->setText("Поля не должны быть пустыми");
                box->show();
                return;
            }
        }

        bool conversionSuccess = false;
        for (int l = 0; l < numberOfValues; l++) {

            auto str = ui->valuesTableFlag->item(l, 0)->text();
            conversionSuccess = false;
            auto num = str.toInt(&conversionSuccess, 10);

            if (!conversionSuccess) {
                box->setText("Значения имеют неправильный формат ввода");
                box->show();
                return;
            }
            vector.append({ num, ui->valuesTableFlag->item(l, 1)->text() });
        }
        QVector<int> vectorInt;
        for (int k = 0; k < numberOfValues; k++) {
            auto m = vector[k].number;
            if (vectorInt.contains(m)) {
                box->setText("Значения не могут иметь дубликатов");
                box->show();
                return;
            } else {
                vectorInt.append(m);
            }
        }
        int maxValue = vectorInt[0];
        for (int val : vectorInt) {
            if (val > maxValue) {
                maxValue = val;
            }
        }

        if (maxValue > maxPossibleValue) {
            box->setText("Биты несоответсвуют значениям");
            box->show();
            return;
        }
        QTableWidgetItem* itemMKO1 = ui->MKOTableFlag->item(0, 0);
        if (!itemMKO1 || itemMKO1->text().isEmpty()) {
            box->setText("Поля не должны быть пустыми");
            box->show();
            return;
        }
        QTableWidgetItem* itemMKO2 = ui->MKOTableFlag->item(0, 1);
        if (!itemMKO2 || itemMKO2->text().isEmpty()) {
            box->setText("Поля не должны быть пустыми");
            box->show();
            return;
        }
        QTableWidgetItem* itemMKO3 = ui->MKOTableFlag->item(0, 2);
        if (!itemMKO3 || itemMKO3->text().isEmpty()) {
            box->setText("Поля не должны быть пустыми");
            box->show();
            return;
        }
        int mko1 = ui->MKOTableFlag->item(0, 0)->text().toInt(&conversionSuccess, 10);
        if (!conversionSuccess) {
            box->setText("Данные МКО имеют неверный формат");
            box->show();
            return;
        } else if (mko1 > 30 || mko1 < 1) {
            box->setText("Адрес абонента должен быть не больше 30");
            box->show();
            return;
        }
        int mko2 = ui->MKOTableFlag->item(0, 1)->text().toInt(&conversionSuccess, 10);
        if (!conversionSuccess) {
            box->setText("Данные МКО имеют неверный формат");
            box->show();
            return;
        } else if (mko2 > 30 || mko2 < 1) {
            box->setText("Подадрес абонента должен быть не больше 30");
            box->show();
            return;
        }
        int mko3 = ui->MKOTableFlag->item(0, 2)->text().toInt(&conversionSuccess, 10);
        if (!conversionSuccess) {
            box->setText("Данные МКО имеют неверный формат");
            box->show();
            return;
        } else if (mko3 > 32 || mko3 < 1) {
            box->setText("Номер слова данных абонента должен быть не больше 32");
            box->show();
            return;
        }

        if (ui->nameFlag->text() == "" || ui->nameFlag->text() == "" || ui->controllerFlag->toPlainText() == "" || ui->MKOTableFlag->rowCount() == 0 || ui->abrevFlag->toPlainText() == "" || ui->valuesTableFlag->rowCount() == 0 || ui->MKOTableFlag->item(0, 0)->text() == ""
            || ui->MKOTableFlag->item(0, 1)->text() == "" || ui->MKOTableFlag->item(0, 2)->text() == "") {
            box->setText("Поля не должны быть пустыми");
            box->show();
            return;
        } else if (idsToCheck.contains(ui->idFlag->text())) {
            box->setText("id должен быть уникальным");
            box->show();
            return;
        }

        {
            itemModel = new QStandardItem("Телеметрия устройства: " + ui->controllerFlag->toPlainText());
            itemModel->setEditable(false);
            model->appendRow(itemModel);
            //id

            itemToAppend = new QStandardItem("id");
            itemModel->appendRow(itemToAppend);
            itemToAppend->setEditable(true);

            itemToAppend->appendRow(new QStandardItem(ui->idFlag->text()));
            itemToAppend->setEditable(false);
            idsToCheck.insert(idsToCheck.count(), ui->idFlag->text());
            //имя
            itemToAppend = new QStandardItem("имя");
            itemModel->appendRow(itemToAppend);
            itemToAppend->setEditable(true);
            itemToAppend->appendRow(new QStandardItem(ui->nameFlag->text()));
            itemToAppend->setEditable(false);
            //устройство

            itemToAppend = new QStandardItem("устройство");
            itemModel->appendRow(itemToAppend);
            itemToAppend->setEditable(true);
            itemToAppend->appendRow(new QStandardItem(ui->controllerFlag->toPlainText()));
            itemToAppend->setEditable(false);

            //мко
            itemToAppend = new QStandardItem("мко");
            itemModel->appendRow(itemToAppend);
            itemToAppend->setEditable(true);
            for (int i = 0; i < ui->MKOTableFlag->columnCount(); i++) {
                itemToAppend->appendRow(new QStandardItem(ui->MKOTableFlag->item(0, i)->text()));
            }

            itemToAppend->setEditable(false);

            // биты
            itemToAppend = new QStandardItem("биты");
            itemModel->appendRow(itemToAppend);
            itemToAppend->setEditable(true);
            if (ui->bytesCombobox2_2->currentText() == "") {
                itemToAppend->appendRow(new QStandardItem(ui->bytesCombobox2->currentText()));
            } else if (ui->bytesCombobox2->currentText() == "") {
                itemToAppend->appendRow(new QStandardItem(ui->bytesCombobox2_2->currentText()));

            } else {
                itemToAppend->appendRow(new QStandardItem(ui->bytesCombobox2->currentText() + "-" + ui->bytesCombobox2_2->currentText()));
            }
            itemToAppend->setEditable(false);
            //значения
            itemToAppend = new QStandardItem("значения");
            itemModel->appendRow(itemToAppend);
            itemToAppend->setEditable(true);
            for (int i = 0; i < ui->valuesTableFlag->rowCount(); i++) {
                QStandardItem* currentItem = new QStandardItem(QString("Значение %1").arg(i));
                currentItem->setEditable(false);
                itemToAppend->appendRow(currentItem);
                for (int j = 0; j < ui->valuesTableFlag->columnCount(); j++) {

                    currentItem->appendRow(new QStandardItem(ui->valuesTableFlag->item(i, j)->text()));
                }
            }

            itemToAppend->setEditable(false);
            // тип
            itemToAppend = new QStandardItem("тип");
            itemModel->appendRow(itemToAppend);
            itemToAppend->setEditable(true);
            itemToAppend->appendRow(new QStandardItem(SigTypeAdd[2]));
            itemToAppend->setEditable(false);

            //сокращение
            itemToAppend = new QStandardItem("сокращение");
            itemModel->appendRow(itemToAppend);
            itemToAppend->setEditable(true);
            itemToAppend->appendRow(new QStandardItem(ui->abrevFlag->toPlainText()));
            itemToAppend->setEditable(false);

            this->close();
        }
    }
    if (currentType == SigTypeAdd[3]) {
        itemModel = new QStandardItem("Сигнал устройства с id " + ui->idTImeMeta->text());
        itemModel->setEditable(false);
        model->appendRow(itemModel);
        //id времени

        itemToAppend = new QStandardItem("id времени");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);

        itemToAppend->appendRow(new QStandardItem(ui->idTImeMeta->text()));
        itemToAppend->setEditable(false);

        //id ПДЦМ
        itemToAppend = new QStandardItem("id ПДЦМ");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);
        for (int i = 0; i < ui->idPDCMMeta->columnCount(); i++) {

            itemToAppend->appendRow(new QStandardItem(ui->idPDCMMeta->item(0, i)->text()));
        }

        itemToAppend->setEditable(false);

        //читать
        itemToAppend = new QStandardItem("читать");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);
        for (int i = 0; i < ui->readMeta->rowCount(); i++) {

            QStandardItem* currentItem = new QStandardItem(QString("Значение %1").arg(i));
            currentItem->setEditable(false);
            itemToAppend->appendRow(currentItem);
            for (int j = 0; j < ui->readMeta->columnCount(); j++) {
                currentItem->appendRow(new QStandardItem(ui->readMeta->item(i, j)->text()));
            }
        }

        itemToAppend->setEditable(false);

        // тип
        itemToAppend = new QStandardItem("тип");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(SigTypeAdd[3]));
        itemToAppend->setEditable(false);
        this->close();
    }
    if (currentType == SigTypeAdd[4]) {
        itemModel = new QStandardItem("Телеметрия устройства: " + ui->controllerTime->toPlainText());
        itemModel->setEditable(false);
        model->appendRow(itemModel);
        //id

        itemToAppend = new QStandardItem("id");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);

        itemToAppend->appendRow(new QStandardItem(ui->idTime->text()));
        itemToAppend->setEditable(false);
        //имя
        itemToAppend = new QStandardItem("имя");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(ui->nameTime->text()));
        itemToAppend->setEditable(false);
        //устройство

        itemToAppend = new QStandardItem("устройство");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(ui->controllerTime->toPlainText()));
        itemToAppend->setEditable(false);

        //мко
        itemToAppend = new QStandardItem("мко");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);
        for (int i = 0; i < ui->MKOTableTime->rowCount(); i++) {

            QStandardItem* currentItem = new QStandardItem(QString("Значение %1").arg(i));
            currentItem->setEditable(false);
            itemToAppend->appendRow(currentItem);
            for (int j = 0; j < ui->MKOTableTime->columnCount(); j++) {
                currentItem->appendRow(new QStandardItem(ui->MKOTableTime->item(i, j)->text()));
            }
        }

        itemToAppend->setEditable(false);

        // тип
        itemToAppend = new QStandardItem("тип");
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(SigTypeAdd[4]));
        itemToAppend->setEditable(false);
        this->close();
    }
}
