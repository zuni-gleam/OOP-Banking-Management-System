#include "dbmanager.h"
#include <QtSql/QSqlError>
#include <QCryptographicHash>

dbmanager& dbmanager::get() {
    static dbmanager inst;
    return inst;
}

bool dbmanager::open(const QString& path) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    return db.open();
}

void dbmanager::createtables() {
    exec("CREATE TABLE IF NOT EXISTS users ("
         "id INTEGER PRIMARY KEY AUTOINCREMENT,"
         "username TEXT UNIQUE NOT NULL,"
         "password TEXT NOT NULL,"
         "role TEXT DEFAULT 'customer',"
         "fullname TEXT,"
         "phone TEXT,"
         "address TEXT,"
         "securityq TEXT,"
         "securitya TEXT,"
         "totpsecret TEXT,"
         "tier TEXT DEFAULT 'gold'"
         ")");

    exec("CREATE TABLE IF NOT EXISTS accounts ("
         "id INTEGER PRIMARY KEY AUTOINCREMENT,"
         "userid INTEGER NOT NULL,"
         "acctype TEXT NOT NULL,"
         "balance REAL DEFAULT 0.0,"
         "minbalance REAL DEFAULT 10000.0,"
         "penalized INTEGER DEFAULT 0,"
         "dailyused REAL DEFAULT 0.0,"
         "dailydate TEXT DEFAULT '',"
         "interestmonth TEXT DEFAULT '',"
         "FOREIGN KEY(userid) REFERENCES users(id)"
         ")");

    exec("ALTER TABLE accounts ADD COLUMN dailydate TEXT DEFAULT ''");
    exec("ALTER TABLE accounts ADD COLUMN interestmonth TEXT DEFAULT ''");

    exec("CREATE TABLE IF NOT EXISTS transactions ("
         "id INTEGER PRIMARY KEY AUTOINCREMENT,"
         "accid INTEGER NOT NULL,"
         "txntype TEXT NOT NULL,"
         "amount REAL NOT NULL,"
         "balafter REAL NOT NULL,"
         "targetacc TEXT,"
         "createdat TEXT DEFAULT CURRENT_TIMESTAMP"
         ")");

    exec("CREATE TABLE IF NOT EXISTS deletion_requests ("
         "id INTEGER PRIMARY KEY AUTOINCREMENT,"
         "userid INTEGER NOT NULL,"
         "username TEXT NOT NULL,"
         "fullname TEXT,"
         "reason TEXT,"
         "status TEXT DEFAULT 'pending',"
         "requestedat TEXT DEFAULT CURRENT_TIMESTAMP,"
         "FOREIGN KEY(userid) REFERENCES users(id)"
         ")");
}

void dbmanager::seedadmin() {
    QSqlQuery chk = run("SELECT id FROM users WHERE username = 'admin'");
    if (chk.next())
    {
        return;
    }
    QString hashed = QString(QCryptographicHash::hash("admin", QCryptographicHash::Sha256).toHex());
    QSqlQuery q(db);
    q.prepare("INSERT INTO users (username, password, role, fullname, tier) VALUES (?, ?, 'admin', 'Administrator', 'diamond')");
    q.addBindValue("admin");
    q.addBindValue(hashed);
    q.exec();
}

QSqlQuery dbmanager::run(const QString& sql) {
    QSqlQuery q(db);
    q.exec(sql);
    return q;
}

bool dbmanager::exec(const QString& sql) {
    QSqlQuery q(db);
    return q.exec(sql);
}
