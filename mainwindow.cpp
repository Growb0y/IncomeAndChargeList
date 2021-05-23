#include "mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), table1(), table2()
{
    ui->setupUi(this);

    styling();
    readInfo(table2, "save2.json");
    readInfo(table1, "save1.json");
    putInfo(ui->tableWidget, table1);
    putInfo(ui->tableWidget2, table2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addIncome_clicked()
{
    inputInfo(ui->tableWidget, table1, "save1.json");
}

void MainWindow::on_addCharge_clicked()
{
    inputInfo(ui->tableWidget2, table2, "save2.json");
}

void MainWindow::on_delete_2_clicked()
{
    removeRow();

}

void MainWindow::inputInfo(QTableWidget *tableWidget, Table &table, QString json){
    action = ui->actionEdit->text();
    money = ui->moneyEdit->text().toDouble();


    tableWidget->insertRow(tableWidget->rowCount());
    TableEntry te(action, money);
    table.addItem(te);

    QTableWidgetItem *i0 = new QTableWidgetItem(action);
    QTableWidgetItem *i1 = new QTableWidgetItem(QString::number(money));

    tableWidget->setItem(tableWidget->rowCount()-1,0, i0);
    tableWidget->setItem(tableWidget->rowCount()-1,1, i1);

    Serialization serialization(table);
    serialization.startSerialization(json);

    showIncomeAndCharge(serialization, json);
}

void MainWindow::readInfo(Table &table, QString json){

    Serialization serialization(table);
    serialization.startDeserialization(json);

    showIncomeAndCharge(serialization, json);
}

void MainWindow::putInfo(QTableWidget *tableWidget, Table &table){

    for(int i = 0; i < table.amountItem(); i++)
    {
        tableWidget->insertRow(i);
        QTableWidgetItem *i0 = new QTableWidgetItem(table.getItem(i).getAction());
        QTableWidgetItem *i1 = new QTableWidgetItem(QString::number(table.getItem(i).getMoney()));

        tableWidget->setItem(i,0, i0);
        tableWidget->setItem(i,1, i1);
    }
}

void MainWindow::on_tableWidget_cellDoubleClicked(int row)
{
    row_ = row;
    row2_ = -1;
}

void MainWindow::on_tableWidget2_cellDoubleClicked(int row2)
{
    row2_ = row2;
    row_ = -1;
}

void MainWindow::removeRow(){

    ui->tableWidget->removeRow(row_);
    table1.deleteItem(row_);

    Serialization serialization(table1);
    serialization.startSerialization("save1.json");

    showIncomeAndCharge(serialization, "save1.json");

    ui->tableWidget2->removeRow(row2_);
    table2.deleteItem(row2_);

    Serialization serialization2(table2);
    serialization2.startSerialization("save2.json");

    showIncomeAndCharge(serialization2, "save2.json");
}

void MainWindow::showIncomeAndCharge(Serialization serialization, QString json){
    if (json == "save1.json")
ui->lcdNumber->display(QString::number(serialization.getIncome()));

    if (json == "save2.json")
ui->lcdNumber_2->display(QString::number(serialization.getCharge()));

ui->lcdNumber_3->display(QString::number(ui->lcdNumber->intValue()-ui->lcdNumber_2->intValue()));
}

void MainWindow::styling(){
    QPalette pal = ui->centralwidget->palette();
    pal.setColor(QPalette::Background, Qt::lightGray);
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(pal);
    ui->centralwidget->show();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget2->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    QPalette d_palette = ui->incomeLabel->palette();
    d_palette.setColor(QPalette::Foreground, Qt::darkGreen);
    ui->incomeLabel->setPalette(d_palette);

    QPalette r_palette = ui->chargeLabel->palette();
    r_palette.setColor(QPalette::Foreground, Qt::darkRed);
    ui->chargeLabel->setPalette(r_palette);

    QPalette i_palette = ui->sumLabel->palette();
    i_palette.setColor(QPalette::Foreground, Qt::darkYellow);
    ui->sumLabel->setPalette(i_palette);

    QPalette i1_palette = ui->lcdNumber->palette();
    i1_palette.setColor(QPalette::Background, Qt::darkGreen);
    ui->lcdNumber->setAutoFillBackground(true);
    ui->lcdNumber->setPalette(i1_palette);

    QPalette i2_palette = ui->lcdNumber_2->palette();
    i2_palette.setColor(QPalette::Background, Qt::darkRed);
    ui->lcdNumber_2->setAutoFillBackground(true);
    ui->lcdNumber_2->setPalette(i2_palette);

    QPalette i3_palette = ui->lcdNumber_3->palette();
    i3_palette.setColor(QPalette::Background, Qt::darkYellow);
    ui->lcdNumber_3->setAutoFillBackground(true);
    ui->lcdNumber_3->setPalette(i3_palette);
}
