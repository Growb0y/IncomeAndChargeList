#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/icon/icon.jpg"));
    w.setWindowTitle("Учёт доходов и расходов");
    w.show();
    return a.exec();
}
