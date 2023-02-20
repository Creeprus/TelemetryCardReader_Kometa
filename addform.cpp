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
    ui->bytesCombobox2_1->addItems(byteList);
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
    QStandardItem* header;
    int numBits = 0;
    QMessageBox* box = new QMessageBox();
    QString currentType = ui->comboBox->currentText();
    itemModel = new QStandardItem();
    itemModel->setEditable(false);
    // Целое
    if (currentType == SigTypeAdd[0]) {
        //Валидация
        if (ui->nameInt->toPlainText() == "" || ui->idInt->text() == "" || ui->controllerInt->toPlainText() == ""
            || ui->MKOTableInt->item(0, 0)->text() == ""
            || ui->MKOTableInt->item(0, 1)->text() == "" || ui->MKOTableInt->item(0, 2)->text() == "") {
            box->setText("Поля не должны быть пустыми");
            box->show();
            return;
        } else if (idsToCheck->contains(ui->idInt->text())) {
            box->setText("id должен быть уникальным");
            box->show();
            return;
        }

        QTableWidgetItem* itemMKO1 = ui->MKOTableInt->item(0, 0);
        if (!itemMKO1 || itemMKO1->text().isEmpty()) {
            box->setText("Поля не должны быть пустыми");
            box->show();
            return;
        }
        QTableWidgetItem* itemMKO2 = ui->MKOTableInt->item(0, 1);
        if (!itemMKO2 || itemMKO2->text().isEmpty()) {
            box->setText("Поля не должны быть пустыми");
            box->show();
            return;
        }
        QTableWidgetItem* itemMKO3 = ui->MKOTableInt->item(0, 2);
        if (!itemMKO3 || itemMKO3->text().isEmpty()) {
            box->setText("Поля не должны быть пустыми");
            box->show();
            return;
        }
        bool conversionSuccess = false;
        int mko1 = ui->MKOTableInt->item(0, 0)->text().toInt(&conversionSuccess, 10);
        if (!conversionSuccess) {
            box->setText("Данные МКО имеют неверный формат");
            box->show();
            return;
        } else if (mko1 > mko1Max || mko1 < 1) {
            box->setText("Адрес абонента должен быть не больше 30");
            box->show();
            return;
        }
        int mko2 = ui->MKOTableInt->item(0, 1)->text().toInt(&conversionSuccess, 10);
        if (!conversionSuccess) {
            box->setText("Данные МКО имеют неверный формат");
            box->show();
            return;
        } else if (mko2 > mko2Max || mko2 < 1) {
            box->setText("Подадрес абонента должен быть не больше 30");
            box->show();
            return;
        }
        int mko3 = ui->MKOTableInt->item(0, 2)->text().toInt(&conversionSuccess, 10);
        if (!conversionSuccess) {
            box->setText("Данные МКО имеют неверный формат");
            box->show();
            return;
        } else if (mko3 > mko3Max || mko3 < 1) {
            box->setText("Номер слова данных абонента должен быть не больше 32");
            box->show();
            return;
        }

        //Валидация конец
        header = itemModel = new QStandardItem("Телеметрия устройства: " + ui->controllerInt->toPlainText());
        model->appendRow(itemModel);
        itemModel->setEditable(false);

        //id

        itemToAppend = new QStandardItem("id");

        itemToAppend->setEditable(true);

        itemToAppend->appendRow(new QStandardItem(ui->idInt->text()));
        itemToAppend->setEditable(false);
        itemModel->appendRow(itemToAppend);
        //имя
        itemToAppend = new QStandardItem("имя");

        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(ui->nameInt->toPlainText()));
        itemToAppend->setEditable(false);
        itemModel->appendRow(itemToAppend);
        //устройство

        itemToAppend = new QStandardItem("устройство");

        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(ui->controllerInt->toPlainText()));
        itemToAppend->setEditable(false);
        itemModel->appendRow(itemToAppend);
        // биты
        itemToAppend = new QStandardItem("биты");

        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(ui->bytesCombobox->currentText()));
        itemToAppend->setEditable(false);
        itemModel->appendRow(itemToAppend);
        // тип
        itemToAppend = new QStandardItem("тип");
        itemToAppend->setEditable(true);
        itemToAppendType = new QStandardItem(SigTypeAdd[0]);
        itemToAppendType->setEditable(false);
        itemToAppend->appendRow(itemToAppendType);
        itemToAppend->setEditable(false);
        itemModel->appendRow(itemToAppend);

        //мко
        itemToAppend = new QStandardItem("мко");

        itemToAppend->setEditable(true);
        for (int i = 0; i < ui->MKOTableInt->columnCount(); i++) {

            itemToAppend->appendRow(new QStandardItem(ui->MKOTableInt->item(0, i)->text()));
        }

        itemToAppend->setEditable(false);
        itemModel->appendRow(itemToAppend);
        idsToCheck->append(ui->idInt->text());
        this->close();
    }
    // Вещественное
    if (currentType == SigTypeAdd[1]) {
        //Валидация
        if (ui->nameReal->text() == "" || ui->idReal->text() == "" || ui->controllerReal->text() == "" || ui->MKOTableReal->rowCount() == 0) {
            box->setText("Поля не должны быть пустыми");
            box->show();
            return;
        } else if (idsToCheck->contains(ui->idReal->text())) {
            box->setText("id должен быть уникальным");
            box->show();
            return;
        }

        QVector<int> vector;

        if (ui->MKOTableReal->rowCount() < 1) {
            box->setText("Поля не должны быть пустыми");
            box->show();
            return;
        }

        for (int a = 0; a < ui->MKOTableReal->rowCount(); a++) {
            for (int b = 0; b < ui->MKOTableReal->columnCount(); b++) {
                bool convertable = true;
                QTableWidgetItem* item = ui->MKOTableReal->item(a, b);
                if (!item || item->text().isEmpty()) {
                    box->setText("Поля не должны быть пустыми");
                    box->show();
                    return;
                }
                int value = item->text().toInt(&convertable, 10);
                if (convertable == false) {
                    box->setText("Поля МКО имеют неккоректные данные для ввода");
                    box->show();
                    return;
                } else {
                    switch (b) {
                    case 0: {
                        if (value > mko1Max || value < 1) {
                            box->setText("Адрес абонента не должен быть больше 30 и не меньше 1");
                            box->show();
                            return;
                        }
                    }
                    case 1: {
                        if (value > mko2Max || value < 1) {
                            box->setText("Подадрес абонента не должен быть больше 30 и не меньше 1");
                            box->show();
                            return;
                        }
                    }
                    case 2: {
                        if (value > mko3Max || value < 1) {
                            box->setText("Номер слова данных не должен быть больше 32 и не меньше 1");
                            box->show();
                            return;
                        }
                    }
                    }
                }
            }

            if (vector.contains(ui->MKOTableReal->item(a, 0)->text().toInt())) {
                box->setText("Нельзя использовать дубликаты адресов");
                box->show();
                return;
            } else {
                int val = ui->MKOTableReal->item(a, 0)->text().toInt();
                vector.append(val);
            }
        }

        //Валидация конец
        itemModel = new QStandardItem("Телеметрия устройства: " + ui->controllerReal->text());
        itemModel->setEditable(false);
        model->appendRow(itemModel);

        //id

        itemToAppend = new QStandardItem("id");

        itemToAppend->setEditable(true);

        itemToAppend->appendRow(new QStandardItem(ui->idReal->text()));
        itemToAppend->setEditable(false);
        itemModel->appendRow(itemToAppend);
        //имя
        itemToAppend = new QStandardItem("имя");

        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(ui->nameReal->text()));
        itemToAppend->setEditable(false);
        itemModel->appendRow(itemToAppend);
        //устройство

        itemToAppend = new QStandardItem("устройство");

        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(ui->controllerReal->text()));
        itemToAppend->setEditable(false);
        itemModel->appendRow(itemToAppend);
        //мко
        itemToAppend = new QStandardItem("мко");

        itemToAppend->setEditable(true);
        for (int i = 0; i < ui->MKOTableReal->rowCount(); i++) {

            QStandardItem* currentItem = new QStandardItem(QString("Значение %1").arg(i));
            currentItem->setEditable(false);
            itemToAppend->appendRow(currentItem);
            for (int j = 0; j < ui->MKOTableReal->columnCount(); j++) {
                currentItem->appendRow(new QStandardItem(ui->MKOTableReal->item(i, j)->text()));
            }
        }
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(false);

        // тип
        itemToAppend = new QStandardItem("тип");
        itemToAppend->setEditable(true);
        itemToAppendType = new QStandardItem(SigTypeAdd[1]);
        itemToAppendType->setEditable(false);
        itemToAppend->appendRow(itemToAppendType);
        itemToAppend->setEditable(false);
        itemModel->appendRow(itemToAppend);

        idsToCheck->append(ui->idReal->text());
        this->close();
    }
    // ФОК

    if (currentType == SigTypeAdd[2]) {
        // Валидация
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
        } else if (mko1 > mko1Max || mko1 < 1) {
            box->setText("Адрес абонента должен быть не больше 30");
            box->show();
            return;
        }
        int mko2 = ui->MKOTableFlag->item(0, 1)->text().toInt(&conversionSuccess, 10);
        if (!conversionSuccess) {
            box->setText("Данные МКО имеют неверный формат");
            box->show();
            return;
        } else if (mko2 > mko2Max || mko2 < 1) {
            box->setText("Подадрес абонента должен быть не больше 30");
            box->show();
            return;
        }
        int mko3 = ui->MKOTableFlag->item(0, 2)->text().toInt(&conversionSuccess, 10);
        if (!conversionSuccess) {
            box->setText("Данные МКО имеют неверный формат");
            box->show();
            return;
        } else if (mko3 > mko3Max || mko3 < 1) {
            box->setText("Номер слова данных абонента должен быть не больше 32");
            box->show();
            return;
        }

        if (ui->nameFlag->text() == "" || ui->nameFlag->text() == "" || ui->controllerFlag->toPlainText() == "" || ui->MKOTableFlag->rowCount() == 0 || ui->abrevFlag->toPlainText() == "" || ui->valuesTableFlag->rowCount() == 0 || ui->MKOTableFlag->item(0, 0)->text() == ""
            || ui->MKOTableFlag->item(0, 1)->text() == "" || ui->MKOTableFlag->item(0, 2)->text() == "") {
            box->setText("Поля не должны быть пустыми");
            box->show();
            return;
        } else if (idsToCheck->contains(ui->idFlag->text())) {
            box->setText("id должен быть уникальным");
            box->show();
            return;
        }
        // Валидация конец
        {
            itemModel = new QStandardItem("Телеметрия устройства: " + ui->controllerFlag->toPlainText());
            itemModel->setEditable(false);
            model->appendRow(itemModel);
            //id

            itemToAppend = new QStandardItem("id");

            itemToAppend->setEditable(true);

            itemToAppend->appendRow(new QStandardItem(ui->idFlag->text()));
            itemToAppend->setEditable(false);
            idsToCheck->append(ui->idFlag->text());
            itemModel->appendRow(itemToAppend);
            //имя
            itemToAppend = new QStandardItem("имя");

            itemToAppend->setEditable(true);
            itemToAppend->appendRow(new QStandardItem(ui->nameFlag->text()));
            itemToAppend->setEditable(false);
            itemModel->appendRow(itemToAppend);
            //устройство

            itemToAppend = new QStandardItem("устройство");

            itemToAppend->setEditable(true);
            itemToAppend->appendRow(new QStandardItem(ui->controllerFlag->toPlainText()));
            itemToAppend->setEditable(false);
            itemModel->appendRow(itemToAppend);
            //мко
            itemToAppend = new QStandardItem("мко");

            itemToAppend->setEditable(true);
            for (int i = 0; i < ui->MKOTableFlag->columnCount(); i++) {
                itemToAppend->appendRow(new QStandardItem(ui->MKOTableFlag->item(0, i)->text()));
            }

            itemToAppend->setEditable(false);
            itemModel->appendRow(itemToAppend);
            // биты
            itemToAppend = new QStandardItem("биты");

            itemToAppend->setEditable(true);
            if (ui->bytesCombobox2_2->currentText() == ui->bytesCombobox2->currentText()) {
                itemToAppend->appendRow(new QStandardItem(ui->bytesCombobox2->currentText()));
            }

            else {
                itemToAppend->appendRow(new QStandardItem(ui->bytesCombobox2->currentText() + "-" + ui->bytesCombobox2_2->currentText()));
            }

            itemToAppend->setEditable(false);
            itemModel->appendRow(itemToAppend);
            //значения
            itemToAppend = new QStandardItem("значения");

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
            itemModel->appendRow(itemToAppend);
            // тип
            itemToAppend = new QStandardItem("тип");
            itemToAppend->setEditable(true);
            itemToAppendType = new QStandardItem(SigTypeAdd[2]);
            itemToAppendType->setEditable(false);
            itemToAppend->appendRow(itemToAppendType);
            itemToAppend->setEditable(false);
            itemModel->appendRow(itemToAppend);

            //сокращение
            itemToAppend = new QStandardItem("сокращение");
            itemToAppend->setEditable(true);
            itemToAppend->appendRow(new QStandardItem(ui->abrevFlag->toPlainText()));
            itemToAppend->setEditable(false);
            itemModel->appendRow(itemToAppend);
            this->close();
        }
    }
    //Метаданные
    if (currentType == SigTypeAdd[3]) {
        QVector<int> vector;
        QVector<int> vectorInt;
        //Валидация
        if (ui->idTImeMeta->text() == "" || ui->readMeta->rowCount() == 0) {
            box->setText("Поля должны быть заполнены");
            box->show();
            return;
        } else if (idsToCheck->contains(ui->idTImeMeta->text())) {
            box->setText("id должен быть уникальным");
            box->show();
            return;
        }
        bool conversionSuccess = false;
        for (int i = 0; i < ui->idPDCMMeta->columnCount(); i++) {
            QTableWidgetItem* itemID = ui->idPDCMMeta->item(0, i);
            if (!itemID || itemID->text().isEmpty()) {
                box->setText("Поля не должны быть пустыми");
                box->show();
                return;
            }
            auto num = ui->idPDCMMeta->item(0, i)->text().toInt(&conversionSuccess, 10);
            if (!conversionSuccess || num < 0) {
                box->setText("Поля имеют неправильный формат ввода");
                box->show();
                return;
            }
            if (vectorInt.contains(num)) {
                box->setText("id ПДЦМ не должен повторятся");
                box->show();
                return;
            } else {
                vectorInt.append(num);
            }
        }

        for (int a = 0; a < ui->readMeta->rowCount(); a++) {
            for (int b = 0; b < ui->readMeta->columnCount(); b++) {
                bool convertable = true;
                QTableWidgetItem* item = ui->readMeta->item(a, b);
                if (!item || item->text().isEmpty()) {
                    box->setText("Поля не должны быть пустыми");
                    box->show();
                    return;
                }
                int value = item->text().toInt(&convertable, 10);
                if (convertable == false) {
                    box->setText("Поля МКО имеют неккоректные данные для ввода");
                    box->show();
                    return;
                } else {
                    switch (b) {
                    case 0: {
                        if (value > mko1Max || value < 1) {
                            box->setText("Адрес абонента не должен быть больше 30 и не меньше 1");
                            box->show();
                            return;
                        }
                    }
                    case 1: {
                        if (value > mko2Max || value < 1) {
                            box->setText("Подадрес абонента не должен быть больше 30 и не меньше 1");
                            box->show();
                            return;
                        }
                    }
                    case 2: {
                        if (value > mko3Max || value < 1) {
                            box->setText("Номер слова данных не должен быть больше 32 и не меньше 1");
                            box->show();
                            return;
                        }
                    }
                    }
                }
            }
            if (vector.contains(ui->readMeta->item(a, 0)->text().toInt())) {
                box->setText("Нельзя использовать дубликаты адресов");
                box->show();
                return;
            } else {
                int val = ui->readMeta->item(a, 0)->text().toInt();
                vector.append(val);
            }
        }

        //Валидация конец
        itemModel = new QStandardItem("Сигнал устройства с id " + ui->idTImeMeta->text());
        itemModel->setEditable(false);
        model->appendRow(itemModel);
        //id времени

        itemToAppend = new QStandardItem("id времени");

        itemToAppend->setEditable(true);
        idsToCheck->append(ui->idTImeMeta->text());

        itemToAppend->appendRow(new QStandardItem(ui->idTImeMeta->text()));
        itemToAppend->setEditable(false);
        itemModel->appendRow(itemToAppend);
        //id ПДЦМ
        itemToAppend = new QStandardItem("id ПДЦМ");

        itemToAppend->setEditable(true);
        for (int i = 0; i < ui->idPDCMMeta->columnCount(); i++) {

            itemToAppend->appendRow(new QStandardItem(ui->idPDCMMeta->item(0, i)->text()));
        }

        itemToAppend->setEditable(false);
        itemModel->appendRow(itemToAppend);
        //читать
        itemToAppend = new QStandardItem("читать");
        ;
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
        itemModel->appendRow(itemToAppend);
        // тип
        itemToAppend = new QStandardItem("тип");
        itemToAppend->setEditable(true);
        itemToAppendType = new QStandardItem(SigTypeAdd[3]);
        itemToAppendType->setEditable(false);
        itemToAppend->appendRow(itemToAppendType);
        itemToAppend->setEditable(false);
        itemModel->appendRow(itemToAppend);
        this->close();
    }
    // Время
    if (currentType == SigTypeAdd[4]) {
        if (ui->nameTime->text() == "" || ui->idTime->text() == "" || ui->controllerTime->toPlainText() == "" || ui->MKOTableTime->rowCount() == 0) {
            box->setText("Поля не должны быть пустыми");
            box->show();
            return;
        } else if (idsToCheck->contains(ui->idTime->text())) {
            box->setText("id должен быть уникальным");
            box->show();
            return;
        }

        QVector<int> vector;

        if (ui->MKOTableTime->rowCount() < 1) {
            box->setText("Поля не должны быть пустыми");
            box->show();
            return;
        }

        for (int a = 0; a < ui->MKOTableTime->rowCount(); a++) {
            for (int b = 0; b < ui->MKOTableTime->columnCount(); b++) {
                bool convertable = true;
                QTableWidgetItem* item = ui->MKOTableTime->item(a, b);
                if (!item || item->text().isEmpty()) {
                    box->setText("Поля не должны быть пустыми");
                    box->show();
                    return;
                }
                int value = item->text().toInt(&convertable, 10);
                if (convertable == false) {
                    box->setText("Поля МКО имеют неккоректные данные для ввода");
                    box->show();
                    return;
                } else {
                    switch (b) {
                    case 0: {
                        if (value > mko1Max || value < 1) {
                            box->setText("Адрес абонента не должен быть больше 30 и не меньше 1");
                            box->show();
                            return;
                        }
                    }
                    case 1: {
                        if (value > mko2Max || value < 1) {
                            box->setText("Подадрес абонента не должен быть больше 30 и не меньше 1");
                            box->show();
                            return;
                        }
                    }
                    case 2: {
                        if (value > mko3Max || value < 1) {
                            box->setText("Номер слова данных не должен быть больше 32 и не меньше 1");
                            box->show();
                            return;
                        }
                    }
                    }
                }
            }

            if (vector.contains(ui->MKOTableTime->item(a, 0)->text().toInt())) {
                box->setText("Нельзя использовать дубликаты адресов");
                box->show();
                return;
            } else {
                int val = ui->MKOTableTime->item(a, 0)->text().toInt();
                vector.append(val);
            }
        }

        //Валидация конец
        itemModel = new QStandardItem("Телеметрия устройства: " + ui->controllerTime->toPlainText());
        itemModel->setEditable(false);
        model->appendRow(itemModel);
        //id

        itemToAppend = new QStandardItem("id");
        itemToAppend->setEditable(true);
        idsToCheck->append(ui->idTime->text());
        itemToAppend->appendRow(new QStandardItem(ui->idTime->text()));
        itemToAppend->setEditable(false);
        itemModel->appendRow(itemToAppend);
        //имя
        itemToAppend = new QStandardItem("имя");

        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(ui->nameTime->text()));
        itemToAppend->setEditable(false);
        itemModel->appendRow(itemToAppend);
        //устройство

        itemToAppend = new QStandardItem("устройство");

        itemToAppend->setEditable(true);
        itemToAppend->appendRow(new QStandardItem(ui->controllerTime->toPlainText()));
        itemToAppend->setEditable(false);
        itemModel->appendRow(itemToAppend);
        //мко
        itemToAppend = new QStandardItem("мко");

        itemToAppend->setEditable(true);
        for (int i = 0; i < ui->MKOTableTime->rowCount(); i++) {

            QStandardItem* currentItem = new QStandardItem(QString("Значение %1").arg(i));
            currentItem->setEditable(false);
            itemToAppend->appendRow(currentItem);
            for (int j = 0; j < ui->MKOTableTime->columnCount(); j++) {
                currentItem->appendRow(new QStandardItem(ui->MKOTableTime->item(i, j)->text()));
            }
        }
        itemModel->appendRow(itemToAppend);
        itemToAppend->setEditable(false);

        // тип
        itemToAppend = new QStandardItem("тип");
        itemToAppend->setEditable(true);
        itemToAppendType = new QStandardItem(SigTypeAdd[4]);
        itemToAppendType->setEditable(false);
        itemToAppend->appendRow(itemToAppendType);
        itemToAppend->setEditable(false);
        itemModel->appendRow(itemToAppend);
        this->close();
    }
}
