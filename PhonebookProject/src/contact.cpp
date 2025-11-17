#include "contact.h"
#include <QRegularExpression>
#include <utility>
#include <atomic>

Contact::Contact(QString fn, QString ln, QString mn)
    : firstName(fn.trimmed()), lastName(ln.trimmed()), middleName(mn.trimmed()) {}

Contact::Contact(const Contact &other)
    : firstName(other.firstName),
      lastName(other.lastName),
      middleName(other.middleName),
      birthDate(other.birthDate),
      email(other.email),
      phones(other.phones),
      address(other.address)
{
    ++CopyMoveStats::copies;
}

Contact::Contact(Contact &&other) noexcept
    : firstName(std::move(other.firstName)),
      lastName(std::move(other.lastName)),
      middleName(std::move(other.middleName)),
      birthDate(std::move(other.birthDate)),
      email(std::move(other.email)),
      phones(std::move(other.phones)),
      address(std::move(other.address))
{
    ++CopyMoveStats::moves;
}

Contact& Contact::operator=(const Contact &other) {
    if (this != &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        middleName = other.middleName;
        birthDate = other.birthDate;
        email = other.email;
        phones = other.phones;
        address = other.address;
        ++CopyMoveStats::copies;
    }
    return *this;
}

Contact& Contact::operator=(Contact &&other) noexcept {
    if (this != &other) {
        firstName = std::move(other.firstName);
        lastName = std::move(other.lastName);
        middleName = std::move(other.middleName);
        birthDate = std::move(other.birthDate);
        email = std::move(other.email);
        phones = std::move(other.phones);
        address = std::move(other.address);
        ++CopyMoveStats::moves;
    }
    return *this;
}

bool Contact::validateName() const {
    QRegularExpression re(R"(^[\p{L}][\p{L}0-9\- ]*$)");
    return re.match(firstName).hasMatch() && re.match(lastName).hasMatch();
}

bool Contact::validateEmail() const {
    QRegularExpression re(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    return re.match(email.trimmed()).hasMatch();
}
