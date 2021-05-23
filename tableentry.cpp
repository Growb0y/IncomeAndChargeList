#include "tableentry.h"

TableEntry::TableEntry(){}

TableEntry::TableEntry(QString act_, double mon_)
    : action(act_), money(mon_){}

TableEntry::~TableEntry(){}

void TableEntry::setAction(QString act_)
{
    action = act_;
}

void TableEntry::setMoney(double mon_){
    money = mon_;
}


QString TableEntry::getAction(){
    return action;
}

double TableEntry::getMoney(){
    return money;
}

