#ifndef TABLE1_H
#define TABLE1_H
#include "tableentry.h"
#include <QList>

class Table{

public:
    Table();
    Table(QList <TableEntry> en_);
    ~Table();

    void addItem(TableEntry en_);
    void deleteItem(int i);
    TableEntry getItem(int i);
    int amountItem();

private:
    QList <TableEntry> entries;

};

#endif // TABLE_H
