#pragma once
#include "Shape.h"


class Rect :
    public Shape
{
    double m_width;
    double m_lenght;

public:
    Rect(double width = 0, double lenght = 0, Color color = GREEN, int ratio = 1);
    Rect(const Rect& other);
    virtual ~Rect();

    double GetWidth() const { return m_width; };
    double GetLenght() const  { return m_lenght; };
    double GetSquareRect() const;
    void WhereAmI() const;
    virtual void WhereAmIVirtual() const;

    virtual void Inflate(int);
};

