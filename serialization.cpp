#include "serialization.h"
#include "stdlib.h"

QString path = "E:/2kurs/iAiMP/KURSOVAYA/IncomeAndChargeList/";

Serialization::Serialization(Table &tb_)

:tb(tb_){}

Serialization::~Serialization(){}

void Serialization::setTable(Table &tb_){

tb = tb_;

}

void Serialization::startSerialization(QString json){

QFile* file = new QFile(path + json);

file->open(QIODevice::WriteOnly);

for(int i = 0; i < tb.amountItem(); i++)

{

char* a = new char[5];

QJsonObject currRec;

currRec["ACTION"] = tb.getItem(i).getAction();

currRec["MONEY"] = tb.getItem(i).getMoney();

if (json == "save1.json"){
    income += tb.getItem(i).getMoney();
} else {
    charge += tb.getItem(i).getMoney();
}

jsonTable.insert((static_cast<QString>("ENTRY")) + static_cast<QString>(itoa(i,a,10)),currRec);

}

saveDoc.setObject(jsonTable);

file->write(saveDoc.toJson());

file->close();

}

void Serialization::startDeserialization(QString json){

QFile* file = new QFile(path + json);

file->open(QFile::ReadOnly | QFile::Text);

char* a = new char[5];

QByteArray saveData = file->readAll();

saveDoc = saveDoc.fromJson(saveData);

jsonTable = saveDoc.object();

for(int i = 0; i < jsonTable.size(); i++)

{

QJsonObject currEntry =jsonTable.value(static_cast<QString>("ENTRY") + static_cast<QString>(itoa(i,a,10))).toObject();

QString action = currEntry["ACTION"].toString();

double money = currEntry["MONEY"].toDouble();

if (json == "save1.json"){
    income += money;
} else {
    charge += money;
}

TableEntry en(action, money);

tb.addItem(en);

}

file->close();

}

double Serialization::getIncome(){
    return income;
}

double Serialization::getCharge(){
    return charge;
}
