#include "phonenumber.h"
#include <QRegularExpression>

bool PhoneNumber::isValid() const {
    QRegularExpression re(R"(^\s*(\+7|8)\s*(?:\(\d{3}\)|\d{3})[\s-]*\d{3}[\s-]*\d{2}[\s-]*\d{2}\s*$)");
    return re.match(number).hasMatch();
}
