#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql>
#include <QDebug>

#include <QtXml>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setHostName("yafeilinux");
    db.setDatabaseName("data.db");
    db.setUserName("yafei");
    db.setPassword("123456");
    if (!db.open()) {
        //��ʾ����
        return false;
    }

    QSqlQuery query;

    // ���������
    query.exec("create table type(id varchar primary key, name varchar)");
    query.exec(QString("insert into type values('0', '��ѡ������')"));
    query.exec(QString("insert into type values('01', '����')"));
    query.exec(QString("insert into type values('02', '�յ�')"));

    // ����Ʒ�Ʊ�
    query.exec("create table brand(id varchar primary key, name varchar, "
               "type varchar, price int, sum int, sell int, last int)");
    query.exec(QString("insert into brand values('01', '����', '����', 3699, 50, 10, 40)"));
    query.exec(QString("insert into brand values('02', '��ά', '����', 3499, 20, 5, 15)"));
    query.exec(QString("insert into brand values('03', '����', '����', 4199, 80, 40, 40)"));
    query.exec(QString("insert into brand values('04', '����', '����', 3999, 40, 10, 30)"));
    query.exec(QString("insert into brand values('05', '����', '�յ�', 2899, 60, 10, 50)"));
    query.exec(QString("insert into brand values('06', '����', '�յ�', 2799, 70, 20, 50)"));

    return true;
}

static bool createXml()
{
    QFile file("data.xml");
    if(file.exists()) return true;
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) return false;
    QDomDocument doc;
    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);
    QDomElement root = doc.createElement(QString("�������嵥"));
    doc.appendChild(root);

    QTextStream out(&file);
    doc.save(out,4);
    file.close();
    return true;
}
#endif // CONNECTION_H
