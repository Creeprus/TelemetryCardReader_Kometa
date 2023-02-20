#include "mainwindow.h"
#include "jsonreaderclass.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    addform->resize(addform->width(), 500);
    addform->setMaximumHeight(500);
    addform->setMinimumWidth(800);
    contextMenu = new QMenu(ui->treeView);

    contextMenu->addAction("Добавить правило", this,
        SLOT(showAddForm()));

    contextMenu->addAction("Удалить правило", this,
        SLOT(deleteTelemetryRule()));

    ui->treeView->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->treeView, &QTreeView::customContextMenuRequested, this,
        &MainWindow::contextMenuExpand);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::contextMenuExpand(const QPoint& point)
{
    QModelIndex curIndex = ui->treeView->indexAt(point);
    QModelIndex index = curIndex.sibling(curIndex.row(), 0);

    if (index.isValid()) {

        auto cur = QCursor::pos();
        contextMenu->move(cur);
        contextMenu->show();
    }
}

void MainWindow::SaveJSON()
{
    QString saveFileName = QFileDialog::getSaveFileName(
        this,
        "Сохранить файл JSON",
        QDir::homePath(),
        "JSON (*.json)");
    if (saveFileName != "") {
        QJsonArray finalArray;
        JSONReaderClass json;

        // auto model=ui->treeView->model();
        QStandardItemModel* model = new QStandardItemModel(nullptr);

        QJsonDocument doc;

        auto abstract_model = ui->treeView->model();
        model = dynamic_cast<QStandardItemModel*>(abstract_model);

        for (int i = 0; i < model->rowCount(); i++) {

            auto item = model->item(i, 0);
            QJsonObject obj = json.getObject(item, json.getType(item));
            //   qDebug() << obj;
            finalArray.append(QJsonValue(obj));
        }

        doc.setArray(finalArray);

        json.saveJSON(saveFileName, doc);
    }
}

void MainWindow::addTelemetryRule()
{

    auto model = ui->treeView->model();
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
    doc = json.readJSON();
    currentDoc = doc;
    QJsonObject obj;
    QStandardItemModel* model = new QStandardItemModel(nullptr);
    QStandardItem* header = new QStandardItem(json.file.fileName());

    model->setHorizontalHeaderItem(0, header);
    connect(model, &QStandardItemModel::dataChanged, this, &MainWindow::itemDataValidation);
    QJsonArray json_aray = currentDoc.array();

    if (json_aray.isEmpty() == false) {
        ids = new QStringList();
        for (int i = 0; i < json_aray.size(); i++) {

            obj = json_aray[i].toObject();
            auto head = obj.value("устройство").toVariant().toString();
            if (head == "") {
                auto head = obj.value("id времени").toVariant().toString();
                itemHeader = new QStandardItem("Сигнал устройства с id " + head);

            } else {
                itemHeader = new QStandardItem("Телеметрия устройства: " + head);
            }
            itemHeader->setEditable(false);

            model->appendRow(itemHeader);

            for (int j = 0; j < obj.size(); j++) {
                auto key = obj.keys().at(j);
                auto value = obj.value(key);
                if (value.isString() && key != "тип") {
                    itemToAdd->setEditable(false);
                    itemToAdd = new QStandardItem(key);
                    itemToAdd->setEditable(true);
                    itemHeader->appendRow(itemToAdd);
                    itemToAdd->appendRow(new QStandardItem(value.toVariant().toString()));
                    itemToAdd->setEnabled(false);

                } else if (key == "тип") {

                    itemToAdd = new QStandardItem(key);
                    itemToAdd->setEditable(false);
                    itemHeader->appendRow(itemToAdd);
                    itemToAddType = new QStandardItem(value.toVariant().toString());
                    itemToAddType->setEditable(false);
                    itemToAdd->appendRow(itemToAddType);
                    itemToAddType->setEditable(false);
                    itemToAdd->setEditable(false);

                } else if (value.toVariant().toInt()) {
                    itemToAdd = new QStandardItem(key);
                    itemToAdd->setEditable(true);
                    itemHeader->appendRow(itemToAdd);
                    itemToAdd->appendRow(new QStandardItem(value.toVariant().toString()));
                    itemToAdd->setEditable(false);
                    //ids->insert(ids->size(),value.toVariant().toInt());
                    ids->append(value.toVariant().toString());

                } else if (value.isArray()) {

                    if (value[0].isArray()) {
                        itemToAdd = new QStandardItem(key);
                        itemToAdd->setEditable(true);
                        itemHeader->appendRow(itemToAdd);
                        QJsonArray ar = value.toArray();

                        int j = 0;

                        for (QJsonValue value : ar) {
                            QJsonArray ar2 = value.toArray();

                            quint16 currentValue = j + 1;

                            QStandardItem* currentItem = new QStandardItem(QString("Значение %1").arg(currentValue));
                            currentItem->setEditable(false);
                            itemToAdd->appendRow(currentItem);

                            for (int ix = 0; ix < ar2.size(); ix++) {
                                QStandardItem* item = new QStandardItem(ar2[ix].toVariant().toString());

                                currentItem->appendRow(item);
                            }

                            j++;
                        }
                        itemToAdd->setEditable(false);
                    } else {
                        itemToAdd = new QStandardItem(key);
                        itemHeader->appendRow(itemToAdd);
                        itemToAdd->setEditable(true);
                        QJsonArray itemArray = value.toArray();
                        for (int j = 0; j < itemArray.count(); j++) {
                            itemToAdd->appendRow(new QStandardItem(itemArray[j].toVariant().toString()));
                        }
                        itemToAdd->setEditable(false);
                    }
                }
            }
        }

        ui->treeView->setModel(model);
        currentModel = model;
    }
}

void MainWindow::itemDataValidation(const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles)
{
    QStringList validationError;
    //auto modelValidation = topLeft.model();
    QModelIndex currentIndex = topLeft;
    while (currentIndex.parent().isValid()) {
        currentIndex = currentIndex.parent();
    }

    QAbstractItemModel* abstractModel = const_cast<QAbstractItemModel*>(currentIndex.model());
    const QStandardItemModel* model = dynamic_cast<QStandardItemModel*>(abstractModel);
    auto item = model->itemFromIndex(currentIndex);

    auto obj = toJsonObject(item);
    qDebug() << obj;
    validationError = validateObject(obj);
    if (validationError.count() > 1) {
        QString validationString;
        for (QString val : validationError) {
            validationString.append(val + " ");
        }
        QMessageBox* box = new QMessageBox();
        box->setText(validationString);
        box->show();
    }
}

void MainWindow::on_telemetryReadButton_clicked()
{
    ReadTelemetry();
}

void MainWindow::showAddForm()
{
    addform->model = dynamic_cast<QStandardItemModel*>(ui->treeView->model());

    addform->idsToCheck = ids;
    addform->exec();
}

void MainWindow::deleteTelemetryRule()
{

    QAbstractItemModel* model = ui->treeView->model();
    QModelIndex curIndex = ui->treeView->currentIndex();

    while (curIndex.parent().isValid()) {
        curIndex = curIndex.parent();
    }
    int idx = curIndex.row();
    model->removeRow(idx);
    // currentModel=model;
    ids->removeAt(idx);
    addform->model = dynamic_cast<QStandardItemModel*>(model);
}
static QVector<QStandardItem*> childrenToVector(QStandardItem* item)
{
    QVector<QStandardItem*> children;
    int numberOfChildren = item->rowCount();
    for (int i = 0; i < numberOfChildren; i++) {
        children.append(item->child(i));
    }
    return children;
}

QJsonObject MainWindow::toJsonObject(QStandardItem* item)
{

    JSONReaderClass jsonReader;
    QJsonObject obj;
    QVector<QStandardItem*> c = childrenToVector(item);
    //    for (auto it = children.begin(); it != children.end(); ++it) {
    //    }
    if (
        std::find_if(c.begin(), c.end(), [](QStandardItem* item) {
            qDebug() << item->text();
            return item->text() == QString("тип");
        })
        == c.end()) {

        qDebug() << "Объект не валидный";
        return obj;
    }
    qDebug() << "ОК";
    obj = jsonReader.getObject(item, jsonReader.getType(item));
    return obj;
}
//Построчное выборочное удаление, если вдруг понадобится
//void MainWindow::deleteTelemetryRule()
//{

//    QAbstractItemModel* model=ui->treeView->model();
//    QModelIndex curIndex=ui->treeView->currentIndex();
//    int idx=curIndex.row();

//    model->removeRow(idx,curIndex.parent());
//    ui->treeView->setModel(model);

//}

//Как вариант вернуть QStringList с валидационными ошибками
QStringList MainWindow::validateObject(QJsonObject obj)
{
    QStringList validationError;

    bool isInt = true;
    for (int j = 0; j < obj.size(); j++) {
        auto key = obj.keys().at(j);
        auto value = obj.value(key);
        if (key == "устройство") {
            if (value.toString() == "") {
                validationError.append("Устройство не должно быть пустым");
            } else {
                validationError.append("Ошибки валидации на устройстве: " + value.toString());
            }
        }
        if (key == "имя") {
            if (value.toString() == "")
                validationError.append("Имя устройства не должно быть пустым");
        }
        if (key == "сокращение") {
            if (value.toString() == "")
                validationError.append("Сокращение устройства не должно быть пустым");
        }
        if (key == "id") {
            double num = value.toVariant().toString().toDouble(&isInt);
            if (value.toVariant().toString() == "")
                validationError.append("id устройства не должно быть пустым");
            if (isInt == false)
                validationError.append("id может быть только числом");
        }
        if (key == "id времени") {
            double num = value.toVariant().toString().toDouble(&isInt);
            if (value.toVariant().toString() == "")
                validationError.append("id устройства не должно быть пустым");
            if (isInt == false)
                validationError.append("id может быть только числом");

            validationError.append("Ошибки валидации на устройстве с id: " + value.toVariant().toString());
        }
        if (key == "мко") {
            if (value[0].isArray()) {
                QVector<int> vectorInt;
                QJsonArray ar = value.toArray();

                for (QJsonValue value : ar) {
                    QJsonArray ar2 = value.toArray();

                    for (int ix = 0; ix < ar2.size(); ix++) {
                        if (ar2[ix].toVariant().toString() == "") {
                            validationError.append("Значения МКО не должны быть пустыми");
                            break;
                        }
                        double num = ar2[ix].toVariant().toString().toDouble(&isInt);
                        if (isInt == false) {
                            validationError.append("Значения МКО должны быть числами");
                            break;
                        }
                    }
                    if (vectorInt.contains(ar2[0].toVariant().toString().toInt())) {
                        validationError.append("Значения адресов не должны быть дубликатами");
                        break;
                    }

                    if (ar2[0].toVariant().toString().toInt() > mko1Max || ar2[0].toVariant().toString().toInt() < 1) {
                        validationError.append("Значение адреса должно быть не больше 30 и не меньше 1");

                    } else {
                        vectorInt.append(ar2[0].toVariant().toString().toInt());
                    }
                    if (ar2[1].toVariant().toString().toInt() > mko2Max || ar2[1].toVariant().toString().toInt() < 1) {
                        validationError.append("Значение подадреса должно быть не больше 30 и не меньше 1");
                    }
                    if (ar2[2].toVariant().toString().toInt() > mko3Max || ar2[2].toVariant().toString().toInt() < 1) {
                        validationError.append("Значение номера слов данных должно быть не больше 32 и не меньше 1");
                    }
                }
            } else {
                QJsonArray itemArray = value.toArray();
                for (int j = 0; j < itemArray.count(); j++) {
                    if (itemArray[j].toVariant().toString() == "") {
                        validationError.append("Значения МКО не должны быть пустыми");
                        break;
                    }
                    double num = itemArray[j].toVariant().toString().toDouble(&isInt);
                    if (isInt == false) {
                        validationError.append("Значения МКО должны быть числами");
                        break;
                    }
                }
                if (itemArray[0].toVariant().toString().toInt() > mko1Max || itemArray[0].toVariant().toString().toInt() < 1) {
                    validationError.append("Значение адреса должно быть не больше 30 и не меньше 1");
                }
                if (itemArray[1].toVariant().toString().toInt() > mko2Max || itemArray[1].toVariant().toString().toInt() < 1) {
                    validationError.append("Значение подадреса должно быть не больше 30 и не меньше 1");
                }
                if (itemArray[2].toVariant().toString().toInt() > mko3Max || itemArray[2].toVariant().toString().toInt() < 1) {
                    validationError.append("Значение номера слов данных должно быть не больше 32 и не меньше 1");
                }
            }
        }
        if (key == "биты" || key == "значения") {
        }
        if (key == "id ПДЦМ") {
            QVector<int> vectorInt;
            QJsonArray itemArray = value.toArray();
            for (int j = 0; j < itemArray.count(); j++) {
                if (itemArray[j].toVariant().toString() == "") {
                    validationError.append("Значения id ПДЦМ не должны быть пустыми");
                    break;
                }
                int num = itemArray[j].toVariant().toString().toInt(&isInt, 10);
                if (isInt == false) {
                    validationError.append("Значения id PDCM должны быть числами");
                    break;
                }
                if (num < 1) {
                    validationError.append("Значения id PDCM должны быть больше 0");
                    break;
                }
                if (vectorInt.contains(num)) {
                    validationError.append("Значения id PDCM должны быть уникальны");
                    break;
                } else {
                    vectorInt.append(num);
                }
            }
        }
        if (key == "читать") {
            QVector<int> vectorInt;
            QJsonArray ar = value.toArray();

            for (QJsonValue value : ar) {
                QJsonArray ar2 = value.toArray();

                for (int ix = 0; ix < ar2.size(); ix++) {
                    if (ar2[ix].toVariant().toString() == "") {
                        validationError.append("Значения МКО не должны быть пустыми");
                        break;
                    }
                    int num = ar2[ix].toVariant().toString().toInt(&isInt, 10);
                    if (isInt == false) {
                        validationError.append("Значения МКО должны быть числами");
                        break;
                    }
                }
                if (vectorInt.contains(ar2[0].toVariant().toString().toInt())) {
                    validationError.append("Значения адресов не должны быть дубликатами");
                    break;
                } else {
                    vectorInt.append(ar2[0].toVariant().toString().toInt());
                }
                if (ar2[0].toVariant().toString().toInt() > mko1Max || ar2[0].toVariant().toString().toInt() < 1) {
                    validationError.append("Значение адреса должно быть не больше 30 и не меньше 1");
                }
                if (ar2[1].toVariant().toString().toInt() > mko2Max || ar2[1].toVariant().toString().toInt() < 1) {
                    validationError.append("Значение подадреса должно быть не больше 30 и не меньше 1");
                }
                if (ar2[2].toVariant().toString().toInt() > mko3Max || ar2[2].toVariant().toString().toInt() < 1) {
                    validationError.append("Значение номера слов данных должно быть не больше 32 и не меньше 1");
                }
            }
        }
    }
    return validationError;
}

void MainWindow::on_MainWindow_destroyed(QObject* arg1)
{
}
