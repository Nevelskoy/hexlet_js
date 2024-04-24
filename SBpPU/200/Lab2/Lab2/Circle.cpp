#include "Shape.h"
#include "Rect.h"
#include "Circle.h"


Circle::Circle(double radius, Color color, int ratio) : Shape(color, ratio) {
	m_radius = radius;
};

Circle::Circle(const Circle& other) {
	m_radius = other.m_radius;
	Shape::SetAll(other.GetColor(), other.GetRatio());
}

Circle::Circle(const Rect& other) : Shape(other) {
	double lenght = other.GetLenght();
	double width = other.GetWidth();
	m_radius = lenght + width;
//	Shape::SetAll(other.GetColor(), other.GetRatio());
}

Circle::~Circle()
{
	printf("\nNow I am in Circle's destructor!");
}

double Circle::GetSquareCircle() const {
	return m_radius * m_radius * PI;
};

void Circle::WhereAmI() const {
	std::cout << typeid(*this).name() << std::endl;
	std::cout << "\nNow I am in class Circle" << std::endl;
};

void Circle::WhereAmIVirtual() const {
	std::cout << "\nNow I am in class Circle" << std::endl;
};

void Circle::Inflate(int num) {
	m_radius += num;
}