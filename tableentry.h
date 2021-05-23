#ifndef TABLEENTRY_H
#define TABLEENTRY_H
#include <QString>

class TableEntry{

public:
    TableEntry();
    TableEntry(QString act_, double mon_);
    ~TableEntry();

    void setAction(QString act_);
    void setMoney(double mon_);

    QString getAction();
    double getMoney();

private:
    QString action;
    double money;
};

#endif // TABLEENTRY_H
