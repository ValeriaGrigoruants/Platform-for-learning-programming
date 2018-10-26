#include "teacher.h"
#include "ui_teacher.h"

Teacher::Teacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Teacher)
{
    ui->setupUi(this);
    this -> setWindowTitle("Work with information");
    db = new DataBase();
   // db -> connectToDataBase();
    this->setupModel("DEVICE",
                         QStringList() << trUtf8("id")
                                             << trUtf8("Имя хоста")
                                             << trUtf8("IP адрес")
                                             << trUtf8("MAC-адрес")
                   );
}

Teacher::~Teacher()
{
    delete ui;
}


void Teacher::setupModel(const QString &tableName, const QStringList &headers)
{
    /* Производим инициализацию модели представления данных
     * */
    modelDevice = new QSqlTableModel(this);
    modelDevice->setTable(tableName);
    modelDevice->select();
    /* Устанавливаем названия колонок в таблице с сортировкой данных
     * */
    for(int i = 0, j = 0; i < modelDevice->columnCount(); i++, j++){
        modelDevice->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
}

/*void Teacher::createUI()
{
    ui->deviceTableView->setModel(modelDevice);     // Устанавливаем модель на TableView
    ui->deviceTableView->setColumnHidden(0, true);    // Скрываем колонку с id записей
    // Разрешаем выделение строк
    ui->deviceTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->deviceTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->deviceTableView->resizeColumnsToContents();
    ui->deviceTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->deviceTableView->horizontalHeader()->setStretchLastSection(true);

    connect(ui->deviceTableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotEditRecord(QModelIndex)));
}*/
