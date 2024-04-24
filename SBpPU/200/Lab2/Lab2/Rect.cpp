#include "Shape.h"
#include "Rect.h"


Rect::Rect(double width, double lenght, Color color, int ratio) : Shape(color, ratio) {
	m_width = width;
	m_lenght = lenght;
}

Rect::Rect(const Rect& other) {
	m_width = other.m_width;
	m_lenght = other.m_lenght;
	Shape::SetAll(other.GetColor(), other.GetRatio());
}

Rect::~Rect()
{
	printf("\nNow I am in Rect's destructor!");
}

double Rect::GetSquareRect() const {
	return m_width * m_lenght;
}

void Rect::WhereAmI() const {
	std::cout << typeid(*this).name() << std::endl;
	std::cout << "\nNow I am in class Rect" << std::endl;
};

void Rect::WhereAmIVirtual() const {
	std::cout << "\nNow I am in class Rect" << std::endl;
};

void Rect::Inflate(int num) {
	m_width += num;
	m_lenght += num;
}