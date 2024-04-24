#include "Circle.h"


Circle::Circle(const int& x, const int& y, const int& radius) : m_center(x, y) {
	m_radius = radius;
	//check radius
}



bool Circle::operator==(const Circle& other) const
{
	if (m_center != other.m_center ||
		m_radius != other.m_radius) return false;
	return true;
}

bool Circle::operator!=(const Circle& other) const
{
	if (m_center == other.m_center ||
		m_radius == other.m_radius) return false;
	return true;
}

int Circle::GetX() const {
	return this->m_center.GetX();
}

int Circle::GetY() const {
	return this->m_center.GetY();
}

int Circle::GetRadius() const {
	return m_radius;
}

double Circle::GetAreaCircle() const {
	return M_PI * pow(m_radius, 2);
}


std::ostream& operator<<(std::ostream& os, const Circle& c)
{
	os << "X: " << c.GetX() << " Y: " << c.GetY() << " R: " << c.GetRadius() << std::endl;
	return os;
}