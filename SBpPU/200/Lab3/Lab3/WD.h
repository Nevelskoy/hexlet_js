#pragma once


enum WD { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY };

WD operator+(WD week, int x) {
	return static_cast<WD>((static_cast<int>(week) + x) % 7);
}

WD& operator+=(WD& week, int x) {
	week = static_cast<WD>((static_cast<int>(week) + x) % 7);
	return week;
}

std::ostream& operator<<(std::ostream& os, const WD& wd) {
    switch (wd) {
    case WD::MONDAY:
        os << "Monday";
        break;
    case WD::TUESDAY:
        os << "Tuesday";
        break;
    case WD::WEDNESDAY:
        os << "Wednesday";
        break;
    case WD::THURSDAY:
        os << "Thursday";
        break;
    case WD::FRIDAY:
        os << "Friday";
        break;
    case WD::SATURDAY:
        os << "Saturday";
        break;
    case WD::SUNDAY:
        os << "Sunday";
        break;
    }
	return os;
};