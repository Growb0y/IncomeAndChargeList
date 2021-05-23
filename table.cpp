#include "table.h"

Table::Table(){}

Table::Table(QList <TableEntry> en_)
    : entries(en_){}

Table::~Table(){}

void Table::addItem(TableEntry en_){
    entries.push_back(en_);
}

void Table::deleteItem(int i){
    entries.removeAt(i);
}

TableEntry Table::getItem(int i){
    return entries[i];
}

int Table::amountItem(){
    return entries.length();
}
