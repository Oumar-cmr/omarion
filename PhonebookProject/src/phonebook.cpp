#include "phonebook.h"

void PhoneBook::addContact(const Contact &c) { m_contacts.append(c); }
void PhoneBook::removeContact(int index) { if (index >=0 && index < m_contacts.size()) m_contacts.remove(index); }

QVector<Contact> PhoneBook::find(const QString &q) const {
    QVector<Contact> res;
    for (const Contact &c : m_contacts) {
        if (c.firstName.contains(q, Qt::CaseInsensitive) || c.lastName.contains(q, Qt::CaseInsensitive) || c.email.contains(q, Qt::CaseInsensitive))
            res.append(c);
    }
    return res;
}
