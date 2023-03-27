#include "dbsender.h"
#include "ui_dbsender.h"

DBSender::DBSender(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::DBSender)
{
    //Подключение драйвера
    db = QSqlDatabase::addDatabase("QSQLITE");
    //Имя базы данных
    db.setDatabaseName("TelemetryData.sqlite");
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
    //  connect(model, &QStandardItemModel::dataChanged, this, &MainWindow::itemDataValidation);
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

void DBSender::sendToDb(int id, QVariant data, QVariant dataValue)
{
    //    //Подключение драйвера
    //    db = QSqlDatabase::addDatabase("QSQLITE");
    //    //Имя базы данных
    //    db.setDatabaseName("TelemetryData.sqlite");
    //    //Открытие подключения и проверка на то,
    //    //что база данных открыта для сообщений
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
    query.bindValue(":id", id);
    query.bindValue(":data", data);
    query.bindValue(":dataValue", dataValue);
    //Выполнение запросов
    query.exec();
}

void DBSender::on_senToDbButton_clicked()
{
    QAbstractItemModel* currentModel = ui->valuesTreeView->model();
    const QStandardItemModel* standardModel = dynamic_cast<QStandardItemModel*>(currentModel);
    JSONReaderClass json;
    for (int i = 0; i < model->rowCount(); i++) {
        QStandardItem* item = model->item(i);
        QStandardItem* itemParent = standardModel->item(i);

        int numberOfChildren = itemParent->rowCount();

        QStandardItem* itemChild = itemParent->child(0);

        QJsonObject obj = json.getObject(item, json.getType(item));
        //qDebug() << obj;
        if (itemChild != nullptr) {
            sendToDb(obj.value("id").toVariant().toInt(), QVariant(obj), QVariant(itemChild->text()));
        }
    }
    db.close();
}
