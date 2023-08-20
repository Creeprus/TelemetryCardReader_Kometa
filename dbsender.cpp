#include "dbsender.h"
#include "ui_dbsender.h"

DBSender::DBSender(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::DBSender)
{
    //Подключение драйвера
    db = QSqlDatabase::addDatabase("QSQLITE");
    //Имя базы данных
    QString pathToDB = QDir::homePath() + "/TelemetryData.sqlite";
    db.setDatabaseName(pathToDB);
    //Открытие подключения и проверка на то,
    //что база данных открыта для сообщений
    ui->setupUi(this);
}

DBSender::~DBSender()
{
    delete ui;
}

void DBSender::initValues()
{
    JSONReaderClass json;
    QJsonDocument doc;

    QJsonObject obj;
    QStandardItemModel* model = new QStandardItemModel(nullptr);
    QStandardItem* header = new QStandardItem(json.file.fileName());

    model->setHorizontalHeaderItem(0, header);
    QJsonArray json_aray = currentDoc.array();

    if (json_aray.isEmpty() == false) {

        for (int i = 0; i < json_aray.size(); i++) {
            obj = json_aray[i].toObject();

            auto head = obj.value("устройство").toVariant().toString();
            if (head == "") {
                auto head = obj.value("id времени").toVariant().toString();
                itemHeader = new QStandardItem("Устройство с id: " + head);

            } else {
                itemHeader = new QStandardItem("Значение для устройства: " + head);
            }
            QString type = obj.value("тип").toVariant().toString();
            itemTypes.append(type);
            itemHeader->setEditable(false);

            model->appendRow(itemHeader);

            for (int j = 0; j < obj.size(); j++) {
                if (obj.value("тип") == "МЕТАДАННЫЕ") {
                    itemHeader->setEditable(false);
                    itemHeader->setToolTip("Сигналам с типом МЕТАДАННЫЕ нельзя задать значения");

                } else {
                    itemHeader->appendRow(itemToAdd);
                    itemHeader->setToolTip(itemTypes.at(i));
                }

                break;
            }
        }

        ui->valuesTreeView->setModel(model);
    }
}

void DBSender::sendToDb(int id, QVariant data, QVariant dataValue, QVariant dataScriptValue, QVariant dataScriptColor)
{

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
               "dataValue blob NOT NULL,"
               "dataScriptValue blob NULL,"
               "dataScriptColor blob NULL"
               ");");
    //Подготовка запроса
    query.prepare("INSERT INTO telemetryValues (id,data,dataValue,dataScriptValue,dataScriptColor) VALUES (:id,:data,:dataValue,:dataScriptValue,:dataScriptColor);");
    //Переменные, используемые в запросе
    query.bindValue(":id", id);
    query.bindValue(":data", data);
    query.bindValue(":dataValue", dataValue);
    query.bindValue(":dataScriptValue", dataScriptValue);
    query.bindValue(":dataScriptColor", dataScriptColor);
    auto curData = QJsonDocument::fromBinaryData(data.toByteArray());
    qDebug() << curData;
    //Выполнение запросов
    query.exec();
    query.exec("SELECT * FROM telemetryValues;");
    while (query.next()) {
        qDebug() << query.value(0);
    }
    // Получить QJsonObject из BLOB
    query.exec("SELECT data FROM telemetryValues;");

    while (query.next()) {
        auto queryValue = query.value(0);
        qDebug() << QJsonDocument::fromBinaryData(queryValue.toByteArray());
    }
}

void DBSender::on_senToDbButton_clicked()
{
    QAbstractItemModel* currentModel = ui->valuesTreeView->model();
    const QStandardItemModel* standardModel = dynamic_cast<QStandardItemModel*>(currentModel);
    JSONReaderClass json;
    QJsonObject obj;
    QStringList validationError;
    QRegExp regex("[0-9][0-9]:[0-5][0-9]:[0-5][0-9]:[0-9][0-9][0-9]");
    int count = 0;
    for (int i = 0; i < model->rowCount(); i++) {
        QStandardItem* item = model->item(i);
        QStandardItem* itemParent = standardModel->item(i);

        int numberOfChildren = itemParent->rowCount();

        QStandardItem* itemChild = itemParent->child(0);

        obj = json.getObject(item, json.getType(item));
        if (itemChild != nullptr) {
            QString type = itemParent->toolTip();
            QString data = itemChild->text();
            bool checkDouble = false;
            data.toDouble(&checkDouble);
            QVariant value(data);

            if (type == "ЦЕЛОЕ") {

                if (value.canConvert(QMetaType::Double)) {
                    double past = value.toDouble();
                    double future = std::floor(value.toDouble());
                    if (past != future || checkDouble == false) {
                        validationError.append(itemParent->text() + ", значение не целое число");
                    }
                }
            }
            if (type == "ВЕЩЕСТВЕННОЕ") {

                if (value.canConvert(QMetaType::Double)) {
                    double past = value.toDouble();
                    double future = std::floor(value.toDouble());
                    if (past == future || checkDouble == false) {
                        validationError.append(itemParent->text() + ", значение не вещественное число");
                    }
                }
            }
            if (type == "ВРЕМЯ") {
                if (value.isNull() == true || regex.exactMatch(value.toString()) == false) {
                    validationError.append(itemParent->text() + ", время должно быть в формате 00:00:00:000");
                }
            }
            if (type == "ФОК") {
                if (value.isNull() == true || value.toString() == "") {
                    validationError.append(itemParent->text() + ", значение флага оперативного контроля не должен быть пустым");
                }
            }
            count++;
            if (validationError.count() == 0) {

                sendToDb(obj.value("id").toVariant().toInt(), QVariant(QJsonDocument(obj).toBinaryData()), QVariant(itemChild->text()), QVariant(""), QVariant(""));
                this->close();
            } else {
                QString validationString;
                validationString = validationError.join(" \n ");
                QMessageBox* box = new QMessageBox();
                box->setTextFormat(Qt::RichText);
                box->about(this, "Ошибка валидации", validationString + " . Данный сигнал не будет прогружен");
            }
        }
    }
    db.close();
}
