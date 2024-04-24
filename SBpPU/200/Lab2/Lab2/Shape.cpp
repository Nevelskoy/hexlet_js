#include "Shape.h"


Shape::Shape(Color color, int ratio) {
	this->m_color = color;
	this->m_ratio = ratio;
};

Shape::Shape(const Shape& other) {
	this->m_color = other.m_color;
	this->m_ratio = other.m_ratio;
};

Shape::~Shape()
{
	printf("\nNow I am in Shape's destructor!");
}

void Shape::GetColor_str() const {
	std::cout << typeid(*this).name() << std::endl;
	std::cout << arColor[m_color] << std::endl;
};

void Shape::SetAll(Color color, int ratio) {
	m_color = color;
	m_ratio = ratio;
}

//void Shape::GetRatio() const {
//	std::cout << "Ratio = " << m_ratio << std::endl;
//};

void Shape::WhereAmI() const {
	std::cout << typeid(*this).name() << std::endl;
	std::cout << "\nNow I am in class Shape" << std::endl;
};

void Shape::WhereAmIVirtual() const {
	std::cout << "\nNow I am in class Shape" << std::endl;
};
