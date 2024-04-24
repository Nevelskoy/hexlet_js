#pragma once
#include <iostream>

class Point
{
	int m_x;
	int m_y;

public:
	Point(int x=0, int y=0);
	Point(const Point& other);

	Point& operator+=(const Point& other);
	Point& operator+=(const int value);

	Point& operator+(Point& other) const;
	Point& operator+();

//	Point& operator+(Point&& temp, const Point& other);  ������ ������ c ����� �����������?
//	� ������ ������ ����� ����������� ������ ������� ��������� 
//	��� ���������, ������� ��������� ���� ��������.
//	��� ���������� �������� ����������, ����� ��� `+`, 
//	���������� ������������ ���������� ������� ��� friend - �������.

	friend Point& operator-=(Point& first, const Point& second);
	friend Point& operator-=(Point& pnt, const int value);
	friend Point& operator-(Point& first, const Point& second);
	friend Point& operator-(Point&& first, const Point& second);
	friend Point& operator-(Point& other);	
	friend Point& operator+(Point&& first, const Point& second);

	const void PrintPoint() const;

	friend std::ostream& operator<<(std::ostream& os, const Point& point);
};


Point& operator-=(Point& first, const Point& second);
Point& operator-=(Point& pnt, const int value);
Point& operator-(Point& first, const Point& second);
Point& operator-(Point&& first, const Point& second);
Point& operator-(Point& other);
Point& operator+(Point&& first, const Point& second);

std::ostream& operator<<(std::ostream& os, const Point& point);
// ������� ���������� ������ �� ������ ������ `std::ostream`,
// ������� ������������ ����� ������.
