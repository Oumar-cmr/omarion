#include "filestorage.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

bool FileStorage::save(const PhoneBook &pb, const QString &path) {
    QJsonArray arr;
    for (const Contact &c : pb.contacts()) {
        QJsonObject obj;
        obj["firstName"] = c.firstName;
        obj["lastName"] = c.lastName;
        obj["middleName"] = c.middleName;
        obj["birthDate"] = c.birthDate.toString(Qt::ISODate);
        obj["email"] = c.email;
        obj["address"] = c.address.fullAddress;
        QJsonArray phones;
        for (const PhoneNumber &p : c.phones) phones.append(p.number);
        obj["phones"] = phones;
        arr.append(obj);
    }
    QJsonDocument doc(arr);
    QFile f(path);
    if (!f.open(QIODevice::WriteOnly)) return false;
    f.write(doc.toJson());
    f.close();
    return true;
}

bool FileStorage::load(PhoneBook &pb, const QString &path) {
    QFile f(path);
    if (!f.open(QIODevice::ReadOnly)) return false;
    QByteArray data = f.readAll();
    f.close();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray()) return false;
    QJsonArray arr = doc.array();
    for (const QJsonValue &v : arr) {
        QJsonObject obj = v.toObject();
        Contact c;
        c.firstName = obj["firstName"].toString();
        c.lastName = obj["lastName"].toString();
        c.middleName = obj["middleName"].toString();
        c.birthDate = QDate::fromString(obj["birthDate"].toString(), Qt::ISODate);
        c.email = obj["email"].toString();
        c.address.fullAddress = obj["address"].toString();
        QJsonArray phones = obj["phones"].toArray();
        for (const QJsonValue &pv : phones) c.phones.append(PhoneNumber(pv.toString()));
        pb.addContact(c);
    }
    return true;
}
