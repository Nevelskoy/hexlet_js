#pragma once
#include "Point.h"
#define _USE_MATH_DEFINES

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

class Circle
{
	int m_radius;
	Point m_center;
public:
	Circle() : m_center(0, 0), m_radius(0) {};
	Circle(const int& x, const int& y, const int& radius);

	bool operator==(const Circle& other) const;
	bool operator!=(const Circle& others) const;

	int GetX() const;
	int GetY() const;
	int GetRadius() const;
	double GetAreaCircle() const;

	friend std::ostream& operator<<(std::ostream&, const Circle&);
};

std::ostream& operator<<(std::ostream&, const Circle&);
