#include "dbstorage.h"
#include <QtSql>
#include <QVariant>
#include <QDebug>

DBStorage::DBStorage(const QString &host, int port, const QString &dbName, const QString &user, const QString &password)
    : m_host(host), m_port(port), m_dbName(dbName), m_user(user), m_password(password) {}

DBStorage::~DBStorage() { close(); }

bool DBStorage::open() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", "PhonebookConnection");
    db.setHostName(m_host);
    db.setPort(m_port);
    db.setDatabaseName(m_dbName);
    db.setUserName(m_user);
    db.setPassword(m_password);
    if (!db.open()) {
        qWarning() << "DB open failed:" << db.lastError().text();
        return false;
    }
    // Ensure tables exist
    QSqlQuery q(db);
    q.exec(R"(
        CREATE TABLE IF NOT EXISTS contacts (
            id SERIAL PRIMARY KEY,
            first_name TEXT,
            last_name TEXT,
            middle_name TEXT,
            birth_date DATE,
            email TEXT,
            address TEXT
        );
    )");
    q.exec(R"(
        CREATE TABLE IF NOT EXISTS phones (
            id SERIAL PRIMARY KEY,
            contact_id INTEGER REFERENCES contacts(id) ON DELETE CASCADE,
            phone TEXT
        );
    )");
    return true;
}

void DBStorage::close() {
    QSqlDatabase::removeDatabase("PhonebookConnection");
}

bool DBStorage::save(const PhoneBook &pb) {
    QSqlDatabase db = QSqlDatabase::database("PhonebookConnection");
    if (!db.isOpen()) return false;
    QSqlQuery q(db);
    db.transaction();
    // Simple approach: clear and reinsert (for coursework purpose)
    if (!q.exec("DELETE FROM phones; DELETE FROM contacts;")) {
        db.rollback();
        return false;
    }
    for (const Contact &c : pb.contacts()) {
        q.prepare("INSERT INTO contacts (first_name, last_name, middle_name, birth_date, email, address) VALUES (?, ?, ?, ?, ?, ?) RETURNING id;");
        q.addBindValue(c.firstName);
        q.addBindValue(c.lastName);
        q.addBindValue(c.middleName);
        q.addBindValue(c.birthDate.isValid() ? c.birthDate : QDate());
        q.addBindValue(c.email);
        q.addBindValue(c.address.fullAddress);
        if (!q.exec()) { db.rollback(); return false; }
        int cid = q.lastInsertId().toInt();
        QSqlQuery q2(db);
        q2.prepare("INSERT INTO phones (contact_id, phone) VALUES (?, ?);");
        for (const PhoneNumber &p : c.phones) {
            q2.addBindValue(cid);
            q2.addBindValue(p.number);
            if (!q2.exec()) { db.rollback(); return false; }
        }
    }
    db.commit();
    return true;
}

bool DBStorage::load(PhoneBook &pb) {
    QSqlDatabase db = QSqlDatabase::database("PhonebookConnection");
    if (!db.isOpen()) return false;
    QSqlQuery q(db);
    if (!q.exec("SELECT id, first_name, last_name, middle_name, birth_date, email, address FROM contacts;")) return false;
    while (q.next()) {
        Contact c;
        int id = q.value(0).toInt();
        c.firstName = q.value(1).toString();
        c.lastName = q.value(2).toString();
        c.middleName = q.value(3).toString();
        c.birthDate = q.value(4).toDate();
        c.email = q.value(5).toString();
        c.address.fullAddress = q.value(6).toString();
        QSqlQuery q2(db);
        q2.prepare("SELECT phone FROM phones WHERE contact_id = ?;");
        q2.addBindValue(id);
        if (q2.exec()) {
            while (q2.next()) {
                c.phones.append(PhoneNumber(q2.value(0).toString()));
            }
        }
        pb.addContact(c);
    }
    return true;
}
