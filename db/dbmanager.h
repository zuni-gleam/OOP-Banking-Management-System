#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QString>

class dbmanager {
public:
    static dbmanager& get();
    bool open(const QString& path);
    void createtables();
    void seedadmin();
    QSqlQuery run(const QString& sql);
    bool exec(const QString& sql);

private:
    dbmanager() = default;
    QSqlDatabase db;
};

#endif
