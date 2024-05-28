#include "Common.h"

bool Common::setDate(std::string input_date) {
    if (Date::isValidDate(input_date)) {
        date_of_delivery = input_date;
        return true;
    }
    return false;
}

std::string Common::getDate()
{
    return date_of_delivery.formatDateAsString();
}
