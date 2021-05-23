#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serialization.h"
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void inputInfo(QTableWidget *tableWidget, Table &table, QString json);
    void readInfo(Table &table, QString json);
    void putInfo(QTableWidget *tableWidget, Table &table);
    void removeRow();
    void showIncomeAndCharge(Serialization serialization, QString json);
    void styling();
    ~MainWindow();

private slots:
    void on_addIncome_clicked();

    void on_addCharge_clicked();

    void on_tableWidget_cellDoubleClicked(int row);
    void on_tableWidget2_cellDoubleClicked(int row2);
    void on_delete_2_clicked();

private:
    Ui::MainWindow *ui;

    QString action;
    double money;
    Table table1;
    Table table2;
    int row_ = 0;
    int row2_ = 0;
};

#endif // MAINWINDOW_H
