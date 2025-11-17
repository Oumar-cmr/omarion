#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QVector>
#include "contact.h"

class PhoneBook {
public:
    void addContact(const Contact &c);
    void removeContact(int index);
    QVector<Contact> find(const QString &q) const;
    QVector<Contact> contacts() const { return m_contacts; }
private:
    QVector<Contact> m_contacts;
};

#endif // PHONEBOOK_H
