#ifndef CONTACT_H
#define CONTACT_H

#include <QString>
#include <QDate>
#include <QVector>
#include "phonenumber.h"
#include "address.h"
#include <atomic>

// Simple profiling counters for copy/move operations (Task 4)
struct CopyMoveStats {
    static inline std::atomic<int> copies{0};
    static inline std::atomic<int> moves{0};
};

class Contact {
public:
    Contact() = default;
    Contact(QString fn, QString ln, QString mn);

    // Rule of five with profiling (counts copies/moves)
    Contact(const Contact &other);
    Contact(Contact &&other) noexcept;
    Contact& operator=(const Contact &other);
    Contact& operator=(Contact &&other) noexcept;
    ~Contact() = default;

    QString firstName;
    QString lastName;
    QString middleName;
    QDate birthDate;
    QString email;
    QVector<PhoneNumber> phones;
    Address address;

    bool validateName() const;
    bool validateEmail() const;
};

#endif // CONTACT_H
