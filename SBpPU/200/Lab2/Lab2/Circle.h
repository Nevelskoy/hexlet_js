#pragma once
#include "Shape.h"
#include "Rect.h"


class Circle :
    public Shape
{
    double m_radius;
    double PI = 3.14;

public:
    Circle(double radius = 0, Color color = RED, int ratio = 1);
    Circle(const Circle& other);
    Circle(const Rect& other);

    virtual ~Circle();
    
    double GetSquareCircle() const;
    void WhereAmI() const;
    virtual void WhereAmIVirtual() const;

    virtual void Inflate(int);
};

