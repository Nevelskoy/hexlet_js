#pragma once
#include <iostream>

class Point
{
	int m_x;
	int m_y;
public:
	Point(const int& x = 0, const int& y = 0);

	int GetX() const;
	int GetY() const;
	void SetXY(const int& x, const int& y);

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;



};

