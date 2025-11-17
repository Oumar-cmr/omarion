#ifndef DBSTORAGE_H
#define DBSTORAGE_H

#include <QString>
#include "phonebook.h"

// DBStorage - uses Qt SQL (QPSQL driver) to save/load PhoneBook into PostgreSQL.
// Requires linking with QtSql and that QPSQL driver is available.
class DBStorage {
public:
    DBStorage(const QString &host, int port, const QString &dbName, const QString &user, const QString &password);
    ~DBStorage();
    bool open();
    void close();
    bool save(const PhoneBook &pb);
    bool load(PhoneBook &pb);
private:
    QString m_host;
    int m_port;
    QString m_dbName;
    QString m_user;
    QString m_password;
};

#endif // DBSTORAGE_H
