#pragma once

#include <iostream>

static const char* arColor[] = { "RED", "GREEN", "BLACK"};
enum Color { RED, GREEN, BLACK };

class Shape
{
	Color m_color;
	int m_ratio;

public:
	Shape(Color color = BLACK, int ratio = 1);
	Shape(const Shape& other);
	virtual ~Shape();

	void GetColor_str() const;
	Color GetColor() const { return m_color; };
	int GetRatio() const { return m_ratio; };
	void SetAll(Color color, int ratio);

	void WhereAmI() const;
	virtual void WhereAmIVirtual() const;

	virtual void Inflate(int) = 0;

};

