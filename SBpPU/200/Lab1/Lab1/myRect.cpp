#include <iostream>
#include "myRect.h"

Rect::Rect(int left, int right, int top, int bottom) {        // пользовательский конструктор класса
	if (left >= right || top <= bottom) {
		Rect::m_left = 0;
		Rect::m_right = 0;
		Rect::m_top = 0;
		Rect::m_bottom = 0;
		std::cout << "The rectangle is not normalized!" << std::endl;
	}
	else {
		Rect::m_left = left;
		Rect::m_right = right;
		Rect::m_top = top;
		Rect::m_bottom = bottom;
		std::cout << "The rectangle is create!" << std::endl;
	}
}


Rect::Rect(const Rect& rect) {								   // пользовательский конструктор копирования
	Rect::m_left = rect.m_left;
	Rect::m_right = rect.m_right;
	Rect::m_top = rect.m_top;
	Rect::m_bottom = rect.m_bottom;
	std::cout << "The rectangle is copied!" << std::endl;
}


Rect::~Rect() {
	std::cout << "The destructor was called << std::endl!" << std::endl;
}


void Rect::InflateRect(int dl, int dr, int dt, int db)
{
	if ((Rect::m_left + dl >= Rect::m_right + dr) || (Rect::m_top + dt <= Rect::m_bottom + db)) {
		std::cout << "The rectangle inflating is not applicable!" << std::endl;
	}
	else {
		Rect::m_left += dl;
		Rect::m_right += dr;
		Rect::m_top += dt;
		Rect::m_bottom += db;
		std::cout << "The rectangle is inflated!" << std::endl;
	}
}


void Rect::InflateRect(unsigned int x, unsigned int y)
{
	if ((Rect::m_left - x >= Rect::m_right + x) || (Rect::m_top + y <= Rect::m_bottom - y)) {
		std::cout << "The rectangle inflating is not applicable!" << std::endl;
	}
	else {
		Rect::m_left -= x;
		Rect::m_right += x;
		Rect::m_top += y;
		Rect::m_bottom -= y;
		std::cout << "The rectangle is inflated!" << std::endl;
	}
}

void Rect::SetAll(int left, int right, int top, int bottom)
{
	if (left >= right || top <= bottom) {
		std::cout << "The rectangle is not normalized!" << std::endl;
	}
	else {
		this->m_left = left;
		this->m_right = right;
		this->m_top = top;
		this->m_bottom = bottom;
		std::cout << "The rectangle has been changed!" << std::endl;
	}
}


void Rect::GetAll(int& m_left, int& m_right, int& m_top, int& m_bottom) const {
	m_left = this->m_left;
	m_right = this->m_right;
	m_top = this->m_top;
	m_bottom = this->m_bottom;
}


// Rect BoundingRect(Rect, Rect);
//которая принимает два объекта класса Rect по значению и
//возвращает объект класса Rect, который является прямоугольником,
//в который вписаны заданные прямоугольники. Как происходит
//передача параметров и возвращение объекта класса?

Rect BoundingRect(Rect rec1, Rect rec2) {
	Rect result;
	int x1, x2, y1, y2;
	int rec1_x1, rec1_x2, rec1_y1, rec1_y2;
	int rec2_x1, rec2_x2, rec2_y1, rec2_y2;
	rec1.GetAll(rec1_x1, rec1_x2, rec1_y1, rec1_y2);
	rec2.GetAll(rec2_x1, rec2_x2, rec2_y1, rec2_y2);
	x1 = (rec1_x1 < rec2_x1) ? rec1_x1 : rec2_x1;
	x2 = (rec1_x2 > rec2_x2) ? rec1_x2 : rec2_x2;
	y1 = (rec1_y1 > rec2_y1) ? rec1_y1 : rec2_y1;
	y2 = (rec1_y2 < rec2_y2) ? rec1_y2 : rec2_y2;
	result.SetAll(x1, x2, y1, y2);
	return result;
}


Rect BoundingRect2(Rect& rec1, Rect& rec2) {
	Rect result;
	int x1, x2, y1, y2;
	int rec1_x1, rec1_x2, rec1_y1, rec1_y2;
	int rec2_x1, rec2_x2, rec2_y1, rec2_y2;
	rec1.GetAll(rec1_x1, rec1_x2, rec1_y1, rec1_y2);
	rec2.GetAll(rec2_x1, rec2_x2, rec2_y1, rec2_y2);
	x1 = (rec1_x1 < rec2_x1) ? rec1_x1 : rec2_x1;
	x2 = (rec1_x2 > rec2_x2) ? rec1_x2 : rec2_x2;
	y1 = (rec1_y1 > rec2_y1) ? rec1_y1 : rec2_y1;
	y2 = (rec1_y2 < rec2_y2) ? rec1_y2 : rec2_y2;
	result.SetAll(x1, x2, y1, y2);
	return result;
}


void Rect::BoundingRect3(Rect& rec1, Rect& rec2) {
	Rect result;
	int rec1_x1, rec1_x2, rec1_y1, rec1_y2;
	int rec2_x1, rec2_x2, rec2_y1, rec2_y2;
	rec1.GetAll(rec1_x1, rec1_x2, rec1_y1, rec1_y2);
	rec2.GetAll(rec2_x1, rec2_x2, rec2_y1, rec2_y2);
	this->m_left = (rec1_x1 < rec2_x1) ? rec1_x1 : rec2_x1;
	this->m_right = (rec1_x2 > rec2_x2) ? rec1_x2 : rec2_x2;
	this->m_top = (rec1_y1 > rec2_y1) ? rec1_y1 : rec2_y1;
	this->m_bottom = (rec1_y2 < rec2_y2) ? rec1_y2 : rec2_y2;
}