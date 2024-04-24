#include "Point.h"


Point::Point(const int& x, const int& y)
{
	m_x = x;
	m_y = y;
}

int Point::GetX() const {
	return m_x;
}

int Point::GetY() const {
	return m_y;
}

void Point::SetXY(const int& x, const int& y)
{
	m_x = x;
	m_x = y;
}


bool Point::operator==(const Point& other) const
{
	return ((other.GetX() == this->GetX()) && (other.GetY() == this->GetY()));
}

bool Point::operator!=(const Point& other) const
{
	return !((other.GetX() == this->GetX()) && (other.GetY() == this->GetY()));
}