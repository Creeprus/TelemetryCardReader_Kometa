#include "mainwindow.h"
#include "jsonreaderclass.h"
#include "ui_mainwindow.h"
#include <QSqlRecord>
#include <QSqlResult>

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
    // connectToDb();
    //connectToDbSqlLite();
    ui->searchBox->addItems(searchList);
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
            QStringList validationError = validateObject(obj);
            if (validationError.count() > 1) {
                QMessageBox* box;
                box->about(this, "Ошибки валидации", "Нельзя сохранить телеметрическую карту, пока есть ошибки валидации");
                return;
            }
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
                    // ids->append(value.toVariant().toString());

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
                            if (key == "значения") {
                                for (int ix = ar2.size() - 1; ix >= 0; ix--) {
                                    QStandardItem* item = new QStandardItem(ar2[ix].toVariant().toString());

                                    currentItem->appendRow(item);
                                }
                            } else
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
        setNewIdList();
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
        validationString = validationError.join(" \n ");
        QMessageBox* box = new QMessageBox();
        box->setTextFormat(Qt::RichText);
        box->about(this, "Ошибка валидации", validationString);
        //  box->setText(validationString);

        //        box->show();
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
    auto currentController = obj.value("устройство");

    if (currentController != QJsonValue::Undefined) {
        validationError.append("Ошибки валидации на устройстве: " + currentController.toString());
    } else {
        validationError.append("Ошибки валидации на устройстве с id: " + obj.value("id времени").toVariant().toString());
    }
    for (int j = 0; j < obj.size(); j++) {
        auto key = obj.keys().at(j);
        auto value = obj.value(key);

        if (key == "устройство") {
            if (value.toString() == "") {
                validationError.append("Устройство не должно быть пустым");
            } else {
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
            int num = value.toVariant().toString().toInt(&isInt);
            if (value.toVariant().toInt() == 0)
                validationError.append("id устройства не должно быть пустым или нулём");
            if (isInt == false)
                validationError.append("id может быть только числом");

            //            QString idString = QString::number(num);
            //            if (ids->contains(idString) == true && isEqualList()==false) {
            //                validationError.append("id должны быть уникальные");
            //            }
            setNewIdList();
        }
        if (key == "id времени") {
            int num = value.toVariant().toString().toInt(&isInt);
            if (value.toVariant().toInt() == 0)
                validationError.append("id устройства не должно быть пустым или нулём");
            if (isInt == false)
                validationError.append("id может быть только числом");

            //            QString idString = QString::number(num);
            //            if (ids->contains(idString) == true && isEqualList()==false) {
            //                validationError.append("id должны быть уникальные");
            //            }
            setNewIdList();
            //      validationError.append("Ошибки валидации на устройстве с id: " + value.toVariant().toString());
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
        if (key == "биты") {

            auto valueByte = obj.value("биты");
            auto valueValues = obj.value("значения");
            int byte1;
            int byte2;
            bool convertable = true;
            bool convertableByte1 = false;
            bool convertableByte2 = false;
            int byte = valueByte.toVariant().toString().toInt(&convertable, 10);
            if (valueByte == "") {
                validationError.append("Биты не должны быть пустыми или не числовым диапазоном");
                break;
            }
            if (convertable == false) {

                if (valueByte.toVariant().toString().contains("-")) {
                    QStringList valueByteList = valueByte.toString().split(QLatin1Char('-'));
                    if (valueByteList.count() != 2) {
                        validationError.append("Биты обладают неправильным числовым диапазоном");
                        break;
                    } else {
                        byte1 = valueByteList[0].toInt(&convertableByte1, 10);
                        if (convertableByte1 == false) {
                            validationError.append("Биты должны быть целым числом");
                            break;
                        }
                        byte2 = valueByteList[1].toInt(&convertableByte2, 10);
                        if (convertableByte2 == false) {
                            validationError.append("Биты должны быть целым числом");
                            break;
                        }
                        if (byte1 < 0 || byte1 > 15 || byte2 < 0 || byte2 > 15) {
                            validationError.append("Биты должны быть не менее 0 и не более 15");
                            break;
                        }
                    }

                } else {
                    validationError.append("Биты обладают неправильным разделителем. Должен быть -");
                    break;
                }

            } else {
                if (byte < 0 || byte > 15) {
                    validationError.append("Биты должны быть не менее 0 и не более 15");
                    break;
                }
            }
            //Обработка ключа "значения"

            if (valueValues != QJsonValue::Undefined) {
                QVector<int> vectorInt;
                for (int i = 0; i < valueValues.toArray().count(); i++) {
                    valueValues[i][0].toVariant().toInt(&convertable);
                    if (convertable == false) {
                        validationError.append("Первая ячейка значений должна быть ячейка о значением бита");
                        break;
                    }
                    if (valueValues[i][0] == "") {
                        validationError.append("Биты значений не должны быть пустыми");
                        break;
                    }
                    if (valueValues[i][0].toVariant().toInt() < 0 || valueValues[i][0].toVariant().toInt() > valueValues.toArray().count()) {
                        validationError.append("Биты не соответствуют значениям. Значения битов имеют неправильную позицию по битам");
                        break;
                    }
                    if (valueValues[i][0].toVariant().toInt() < 0 || valueValues[i][0].toVariant().toInt() > valueValues.toArray().count()) {
                        validationError.append("Биты не соответствуют значениям. Значения битов имеют неправильную позицию по битам");
                        break;
                    }
                    if (vectorInt.contains(valueValues[i][0].toVariant().toInt())) {
                        validationError.append("Значения битов должны быть уникальными");
                        break;
                    } else {
                        vectorInt.append(valueValues[i][0].toVariant().toInt());
                    }
                }
                if (convertableByte2 == false || convertableByte1 == false) {
                    if (valueValues.toArray().count() > 2) {
                        validationError.append("Биты не соответствуют значениям");
                        break;
                    }
                } else {
                    if (byte2 > byte1)
                        std::swap(byte1, byte2);

                    int numBits = byte1 - byte2 + 1;
                    int maxPossibleValue = (1 << numBits);
                    if (valueValues.toArray().count() > maxPossibleValue) {
                        validationError.append("Количество битов не соответствуют значениям");
                        break;
                    }
                }
            }
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
///
/// \brief Метод подключения к PostGreSQL
///
void MainWindow::connectToDb()
{
    //Подключение драйвера
    db = QSqlDatabase::addDatabase("QPSQL", "PostgreSQL 13");
    //Имя базы данных
    db.setDatabaseName("telemetrydata");
    db.setUserName("postgres");
    db.setHostName("127.0.0.1");
    db.setPort(5432);
    db.setPassword("123");
    db.open();
    QString a = db.databaseName();
    QSqlQuery query(db);
    query.exec("CREATE TABLE telemetryValues "
               "("
               "id integer NOT NULL"
               ");");
}

void MainWindow::connectToDbSqlLite()
{
    //Подключение драйвера
    db = QSqlDatabase::addDatabase("QSQLITE");
    //Имя базы данных
    db.setDatabaseName("TelemetryData.sqlite");
    //Открытие подключения и проверка на то,
    //что база данных открыта для сообщений
    if (!db.open()) {
        qDebug() << "Не открылась бд";
        return;
    }
    //Использование класса для работы с запросами
    //к базе данных
    QSqlQuery query(db);
    query.exec("CREATE TABLE telemetryValues "
               "("
               "id integer NOT NULL,"
               "data blob NOT NULL,"
               "dataValue blob NOT NULL"
               ");");
    //Подготовка запроса
    query.prepare("INSERT INTO telemetryValues (id,data,dataValue) VALUES (:id,:data,:dataValue);");
    //Переменные, используемые в запросе
    query.bindValue(":id", 33);
    query.bindValue(":data", QVariant("test"));
    query.bindValue(":dataValue", QVariant("test"));
    //Выполнение запросов
    query.exec();
    query.exec("SELECT * FROM telemetryValues;");
    //Вывод результатов SELECT
    while (query.next())
        qDebug() << query.value(0);
}

void MainWindow::on_MainWindow_destroyed(QObject* arg1)
{
}

void MainWindow::on_searchLine_returnPressed()
{
    JSONReaderClass json;
    QString currentParameter = ui->searchBox->currentText();
    QString currentValue = ui->searchLine->text();
    if (currentValue == "") {
        ui->treeView->collapseAll();
        return;
    }
    QStandardItemModel* model = new QStandardItemModel(nullptr);
    auto abstract_model = ui->treeView->model();
    model = dynamic_cast<QStandardItemModel*>(abstract_model);
    int childrenCount = model->rowCount();
    ui->treeView->collapseAll();
    if (currentParameter == "id") {
        for (int i = 0; i < childrenCount; i++) {
            QStandardItem* item = model->item(i);
            QJsonObject obj = json.getObject(item, json.getType(item));
            auto value = obj.value("id");
            if (value.isUndefined()) {
                value = obj.value("id времени");
            }
            if (currentValue == value.toVariant().toString()) {
                ui->treeView->expand(item->index());
            }
        }
    }
    if (currentParameter == "Устройству") {
        for (int i = 0; i < childrenCount; i++) {
            QStandardItem* item = model->item(i);
            QJsonObject obj = json.getObject(item, json.getType(item));
            auto value = obj.value("устройство");

            if (value.toVariant().toString().contains(currentValue)) {
                ui->treeView->expand(item->index());
            }
        }
    }
    if (currentParameter == "Имени") {
        for (int i = 0; i < childrenCount; i++) {
            QStandardItem* item = model->item(i);
            QJsonObject obj = json.getObject(item, json.getType(item));
            auto value = obj.value("имя");

            if (value.toVariant().toString().contains(currentValue)) {
                ui->treeView->expand(item->index());
            }
        }
    }
    if (currentParameter == "Сокращению") {
        for (int i = 0; i < childrenCount; i++) {
            QStandardItem* item = model->item(i);
            QJsonObject obj = json.getObject(item, json.getType(item));
            auto value = obj.value("сокращение");

            if (value.toVariant().toString().contains(currentValue)) {
                ui->treeView->expand(item->index());
            }
        }
    }
}

void MainWindow::setNewIdList()
{
    JSONReaderClass json;
    QStandardItemModel* model = new QStandardItemModel(nullptr);

    auto abstract_model = ui->treeView->model();
    model = dynamic_cast<QStandardItemModel*>(abstract_model);
    oldids = *ids;
    QStringList* newIds = new QStringList;
    if (model != NULL)
        for (int i = 0; i < model->rowCount(); i++) {
            QStandardItem* item = model->item(i);
            QJsonObject obj = json.getObject(item, json.getType(item));
            auto value = obj.value("id");
            if (value.isUndefined()) {
                value = obj.value("id времени");
                if (value.isUndefined()) {
                    break;
                }
            }
            newIds->append(QString::number(value.toVariant().toInt()));
        }
    if (newIds->count() > 0) {

        ids = newIds;
    }
}

bool MainWindow::isEqualList()
{
    for (int i = 0; i < ids->length(); i++) {
        QString a1 = ids->at(i);
        QString a2;
        if (oldids.count() > 0) {
            a2 = oldids.at(i);
        } else {
            a2 = a1;
        }
        if (a1 != a2) {
            return false;
        }
    }
    return true;
}

void MainWindow::on_dbValuesWindowButton_clicked()
{
    dbssender->model = dynamic_cast<QStandardItemModel*>(ui->treeView->model());
    dbssender->currentDoc = currentDoc;

    dbssender->initValues();
    dbssender->exec();
}
