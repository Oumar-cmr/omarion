#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <QString>

class PhoneNumber {
public:
    PhoneNumber() = default;
    explicit PhoneNumber(const QString &s) : number(s) {}
    QString number;
    bool isValid() const;
};

#endif // PHONENUMBER_H
