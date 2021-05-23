#ifndef SERIALIZATION_H
#define SERIALIZATION_H
#include "table.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QJsonObject>
#include <QJsonDocument>

class Serialization{
public:
    explicit Serialization(Table &tb_);
    ~Serialization();

    void setTable(Table &tb_);
    void startSerialization(QString json);
    void startDeserialization(QString json);
    double getIncome();
    double getCharge();
    double zeroIncome();
    double zeroCharge();

private:
    Table& tb;
    double income = 0;
    double charge = 0;
    QJsonDocument saveDoc;
    QJsonObject jsonTable;
};

#endif // SERIALIZATION_H
