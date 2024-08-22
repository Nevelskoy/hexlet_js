#pragma once
#include <iostream>
#include <map>

const int DEFAULT_DAY = 1;
const int DEFAULT_MONTH = 1;
const int DEFAULT_YEAR = 1970;
const int ONE_YEAR = 365;

std::map<int, int> daysOfMonth{ {1, 31}, {2, 28}, {3, 31},
							   {4, 30}, {5, 31}, {6, 30},
							   {7, 31}, {8, 31}, {9, 30},
							   {10, 31}, {11, 30}, {12, 31} };


class Date {
private:

	int m_day = DEFAULT_DAY;
	int m_month = DEFAULT_MONTH;
	int m_year = DEFAULT_YEAR;


	int toDays() const {
		int days = 0;
		for (int i = 0; i < m_month; ++i) {
			days += daysOfMonth[i];
		}
		return (365 * m_year + days + m_day);
	}

	Date toDate(int days) {
		int restDays = days % ONE_YEAR;
		int year = (days - restDays) / ONE_YEAR;

		if (!restDays) return Date(31, 12, year);

		int month = 0;
		int day = 0;
		for (int i = 0; i < daysOfMonth.size() + 1; ++i) {
			if (restDays <= 0) {
				month = --i;
				day = daysOfMonth[i] + restDays;
				break;
			}
			restDays -= daysOfMonth[i];
		}
		return Date(day, month, year);
	}

	bool isCorrect() {
		return (GetDay() <= daysOfMonth[m_month] && GetDay() > 0)
			&& (GetMonth() < 13 && GetMonth() > 0)
			&& (GetYear() > 1969 && GetYear() < 2100);
	}

public:
	Date() = default;
	Date(int d, int m, int y) : m_day(d), m_month(m), m_year(y) 
	{
		if (!isCorrect()) {
			m_day = DEFAULT_DAY;
			m_month = DEFAULT_MONTH;
			m_year = DEFAULT_YEAR;
		};
	};
	
	int GetDay() const {
		return m_day;
	}

	int GetMonth() const {
		return m_month;
	}

	int GetYear() const {
		return m_year;
	}

	int GetDaysCount() const {
		return toDays();
	}

	Date operator+(int k) {
		 return toDate(this->toDays() + k);		
	}

	Date operator-(int k) {
		int x = this->toDays();
		int y = x - k;
		return toDate(y);
	}

};


std::ostream& operator << (std::ostream& out, const Date& d) {
	out << d.GetDay() << "." << d.GetMonth() << "." << d.GetYear();
	return out;
}
