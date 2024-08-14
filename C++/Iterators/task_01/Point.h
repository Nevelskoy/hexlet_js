#pragma once
#include <iostream>

class Point
{
	int m_x;
	int m_y;

public:
	Point(int x = 0, int y = 0);
	Point(const Point& other);

	Point& operator+=(const Point& other);
	Point& operator+=(const int value);
	Point& operator+(Point& other) const;
	Point& operator+();

	friend Point& operator-=(Point& first, const Point& second);
	friend Point& operator-=(Point& pnt, const int value);
	friend Point& operator-(Point& first, const Point& second);
	friend Point& operator-(Point&& first, const Point& second);
	friend Point& operator-(Point& other);
	friend Point& operator+(Point&& first, const Point& second);

	const void PrintPoint() const;
	const int GetX() const;
	const int GetY() const;
	void SetPoint(int, int); 

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;
	bool operator<(const Point& other) const {
		return m_x < other.m_x || (m_x == other.m_x && m_y < other.m_y);
	}

	friend std::ostream& operator<<(std::ostream& os, const Point& point);
	//friend bool operator<(const Point& Pleft, const Point& Pright);

};


Point& operator-=(Point& first, const Point& second);
Point& operator-=(Point& pnt, const int value);
Point& operator-(Point& first, const Point& second);
Point& operator-(Point&& first, const Point& second);
Point& operator-(Point& other);
Point& operator+(Point&& first, const Point& second);

//The function returns a reference to an object of class `std::ostream`
std::ostream& operator<<(std::ostream& os, const Point& point);
