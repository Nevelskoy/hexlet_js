#include "Point.h"


Point::Point(int x, int y) {
	this->m_x = x;
	this->m_y = y;
}

Point::Point(const Point& other) {
	this->m_x = other.m_x;
	this->m_y = other.m_y;
}

Point& Point::operator+=(const Point& other) {
	this->m_x += other.m_x;
	this->m_y += other.m_y;
	return *this;
}

Point& Point::operator+=(const int value) {
	this->m_x += value;
	this->m_y += value;
	return *this;
}

Point& Point::operator+(Point& other) const {
	return other += *this;
}

Point& Point::operator+() {
	return *this += *this;
}

Point& operator+(Point&& first, const Point& second) {
	first += second;
	return first;
}

//Point& Point::operator+(Point&& temp, const Point& other) {
//		temp += other;
//		return temp;
//}


Point& operator-=(Point& first, const Point& second) {
	first.m_x -= second.m_x;
	first.m_y -= second.m_y;
	return first;
}

Point& operator-=(Point& pnt, const int value) {
	pnt.m_x -= value;
	pnt.m_y -= value;
	return pnt;
}

Point& operator-(Point& first, const Point& second) {
	first.m_x -= second.m_x;
	first.m_y -= second.m_y;
	return first;
}

Point& operator-(Point&& first, const Point& second) {
	first -= second;
	return first;
}

Point& operator-(Point& other) {
	return other -= other;
}

const void Point::PrintPoint() const {
	std::cout << "(" << m_x << ", " << m_y << ")" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
	os << "(" << point.m_x << ", " << point.m_y << ")";
	return os;
}

//`return os;` - returns an object of class `std::ostream`
// to support chaining of output.


bool Point::operator==(const Point& other) const
{
	if (m_x != other.m_x || m_y != other.m_y)
		return false;
	return true;
}

bool Point::operator!=(const Point& other) const
{
	if (*this == other)
		return false;
	return true;
}

//bool operator<(const Point& Pleft, const Point& Pright)
//{
//	return (Pleft.m_x < Pright.m_x) ? true : false;
//
//}

void Point::SetPoint(int x, int y) {
	m_x = x;
	m_y = y;
};

const int Point::GetX() const {
	return m_x;
}

const int Point::GetY() const {
	return m_y;
}
