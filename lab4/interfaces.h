#ifndef INTERFACES_H
#define INTERFACES_H
#include <iostream>
#include <cmath>
using namespace std;

class IGeoFig {
public:
    // Площадь.
    virtual double square() = 0;
    // Периметр.
    virtual double perimeter() = 0;
};

// Вектор
class CVector2D {
    public:
    double x, y;
    CVector2D(double a, double b);
    CVector2D();
    CVector2D operator + (CVector2D a);
};

// Интерфейс "Физический объект".
class IPhysObject {
public:
    // Масса, кг.
    double mass;
    // Координаты центра масс, м.
    CVector2D position;
    // Сравнение по массе.
    virtual bool operator== ( const IPhysObject& ob ) const = 0;
    // Сравнение по массе.
    virtual bool operator< ( const IPhysObject& ob ) const = 0;
};

// Интерфейс "Отображаемый"
class IPrintable {
public:
    // Отобразить на экране
    // (выводить в текстовом виде параметры фигуры).
    virtual void draw() = 0;
};

// Интерфейс для классов, которые можно задать через диалог с пользователем.
class IDialogInitiable {
    // Задать параметры объекта с помощью диалога с пользователем.
    virtual void initFromDialog() = 0;
};

// Интерфейс "Класс"
class BaseCObject {
public:
    // Размер занимаемой памяти.
    virtual unsigned int size()=0;
};

class Round: public IGeoFig, public IPhysObject, public IPrintable, public IDialogInitiable, public BaseCObject{
public:
    double radius=0;
    Round();

    // IDialogInitiable interface
private:
    void initFromDialog() override;

    // IPrintable interface
public:
    void draw() override;

    // IPhysObject interface
public:
    bool operator ==(const IPhysObject &ob) const override;
    bool operator <(const IPhysObject &ob) const override;

    // IGeoFig interface
public:
    double square() override;
    double perimeter() override;

    // BaseCObject interface
public:
    unsigned int size() override;
};

class Triangle: public IGeoFig, public IPhysObject, public IPrintable, public IDialogInitiable, public BaseCObject{

    // IDialogInitiable interface
private:
    void initFromDialog() override;

    // IPrintable interface
public:
    void draw() override;

    // IPhysObject interface
public:
    bool operator ==(const IPhysObject &ob) const override;
    bool operator <(const IPhysObject &ob) const override;

    // IGeoFig interface
public:
    double square() override;
    double perimeter() override;

    // BaseCObject interface
public:
    unsigned int size() override;

public:
    double angle;
    double side;
    Triangle();

};

class GeomObject: public Round, public Triangle{};

#endif // INTERFACES_H
