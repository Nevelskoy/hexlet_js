#pragma once
#include <iostream>


class Date
{
	int m_day = 1;
	int m_month = 1;
	int m_year = 1970;

public:
	Date() = default;
	Date(int d, int m, int y) : m_day(d), m_month(m), m_year(y) {};
	
	int GetDay() const {
		return m_day;
	}

	int GetMonth() const {
		return m_month;
	}

	int GetYear() const {
		return m_year;
	}


};


std::ostream& operator << (std::ostream& out, const Date& d) {
	out << d.GetDay() << "." << d.GetMonth() << "." << d.GetYear();
	return out;
}
