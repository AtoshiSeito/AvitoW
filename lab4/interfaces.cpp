#include "interfaces.h"

Round::Round()
{
    initFromDialog();
}

unsigned int Round::size()
{
    return sizeof(this);
}

void Round::initFromDialog()
{
    cout<<"Введите массу, координаты центра и радиус объекта:\n";
    cin>>mass>>position.x>>position.y>>radius;
}

void Round::draw()
{
    cout<<"Круг. Масса: "<<mass<<" Координаты центра: ["<<position.x<<" "<<position.y<<"] Радиус: "<<radius<<endl;
}

bool Round::operator ==(const IPhysObject &ob) const
{
    return mass==ob.mass;
}

bool Round::operator <(const IPhysObject &ob) const
{
    return mass<ob.mass;
}

double Round::square()
{
    return 3.14*pow(radius, 2);
}

double Round::perimeter()
{
    return 6.28*radius;
}

CVector2D::CVector2D(double a, double b)
{
    x=a; y=b;
}

CVector2D::CVector2D()
{
    x=0; y=0;
}

CVector2D CVector2D::operator +(CVector2D a){
    return CVector2D(a.x+x, a.y+y);
}

void Triangle::initFromDialog()
{
    cout<<"Введите массу, координаты центра, угол отклонения высоты от вертикали и длину стороны:\n";
    cin>>mass>>position.x>>position.y>>angle>>side;
}

void Triangle::draw()
{
    cout<<"Треугольник. Масса: "<<mass<<" Координаты центра: ["<<position.x<<" "<<position.y<<"] Угол: "<<angle<<" Сторона: "<<side<<endl;
}

bool Triangle::operator ==(const IPhysObject &ob) const
{
    return mass==ob.mass;
}

bool Triangle::operator <(const IPhysObject &ob) const
{
    return mass<ob.mass;
}

double Triangle::square()
{
    return (pow(side, 2)*sqrt(3))/4;
}

double Triangle::perimeter()
{
    return side*3;
}

Triangle::Triangle()
{
    initFromDialog();
}


unsigned int Triangle::size()
{
    return sizeof(this);
}
