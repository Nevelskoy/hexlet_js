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

//	Point& operator+(Point&& temp, const Point& other);  почему нельзя c двумя параметрами?
//	В методе класса можно перегрузить только унарные операторы 
//	или операторы, которые принимают один аргумент.
//	Для перегрузки бинарных операторов, таких как `+`, 
//	необходимо использовать глобальную функцию или friend - функцию.

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
// функция возвращает ссылку на объект класса `std::ostream`,
// который представляет поток вывода.
