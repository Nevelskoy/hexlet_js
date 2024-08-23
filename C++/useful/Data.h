#pragma once
#include <iostream>
#include <map>

const int DEFAULT_DAY = 1;
const int DEFAULT_MONTH = 1;
const int DEFAULT_YEAR = 1970;
const int YEAR_WITHOUT_FEB = 337;


class Date {
private:
	int m_day = DEFAULT_DAY, m_month = DEFAULT_MONTH, m_year = DEFAULT_YEAR;

	int GetDaysInFeb(int year) const {
		if ((!(year % 4) && !(year % 100)) || !(year % 400)) {
			return 29;
		}
		return 28;
	}

	int GetDaysInMonth(int month, int year) const {
		switch (month)
		{
		case 2:
			return GetDaysInFeb(year);
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		default:
			return 30;
		}
	}

	int GetDaysInYear(int year) const {
		return YEAR_WITHOUT_FEB + GetDaysInFeb(year);
	}

	bool isCorrect() const {
		return (GetMonth() <= 12 && GetMonth() > 0) && (GetDay() > 0 && GetDay() <= GetDaysInMonth(GetMonth(), GetYear()));
	}

	int DaysPassedToMonth(int month, int year) const {
		int days = 0;
		for (int i = 1; i < month; ++i) {
			days += GetDaysInMonth(i, year);
		}
		return days;
	}

	int GetDays() const {
		int days = 0;
		for (int i = DEFAULT_YEAR; i < GetYear(); ++i) {
			days += GetDaysInYear(i);
		}
		return days + DaysPassedToMonth(GetMonth(), GetYear()) + GetDay();
	}

	void SetFromDays(int inp_days) {
		m_month = DEFAULT_MONTH;
		m_year = DEFAULT_YEAR;

		while (inp_days > GetDaysInYear(GetYear())) {
			inp_days -= GetDaysInYear(GetYear());
			++m_year;
		}

		while (inp_days > DaysPassedToMonth(GetMonth() + 1, GetYear())) {
			++m_month;
		}

		m_day = inp_days - DaysPassedToMonth(GetMonth(), GetYear());
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
		return GetDays();
	}

	Date operator + (int k) const {
		Date result(*this);
		result.SetFromDays(result.GetDays() + k);
		return result;
	}

	Date operator - (int k) const {
		Date result(*this);
		result.SetFromDays(result.GetDays() - k);
		return result;
	}

	int operator-(Date& other) {
		int diff = this->GetDays() - other.GetDays();
		return diff;
	}

};


std::ostream& operator << (std::ostream& out, const Date& d) {
	out << d.GetDay() << "." << d.GetMonth() << "." << d.GetYear();
	return out;
}
