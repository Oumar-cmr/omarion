#ifndef FILESTORAGE_H
#define FILESTORAGE_H

#include <QString>
#include "phonebook.h"

class FileStorage {
public:
    bool save(const PhoneBook &pb, const QString &path);
    bool load(PhoneBook &pb, const QString &path);
};

#endif // FILESTORAGE_H
