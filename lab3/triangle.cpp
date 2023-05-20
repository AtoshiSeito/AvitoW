#include "triangle.h"

triangle::triangle(){
    point tmp;
    cout<<"Введите x и y первой точки:\n";
    cin>>a.x>>a.y;
    cout<<"Введите x и y второй точки:\n";
    cin>>b.x>>b.y;
    cout<<"Введите x и y третьей точки:\n";
    cin>>c.x>>c.y;
}

triangle::triangle(point d, point e, point f){
    a = d;
    b = e;
    c = f;
}

void triangle::print(){
    cout<<"["<<a.x<<", "<<a.y<<"] "<<"["<<b.x<<", "<<b.y<<"] "<<"["<<c.x<<", "<<c.y<<"] S: "<<getS();
}

double triangle::getS(){
    double tmp = (getLen(a, b)+getLen(b, c)+getLen(a, c))/2;
    return sqrt(tmp*(tmp-getLen(a, b))*(tmp-getLen(b, c))*(tmp-getLen(a, c)));
}

double triangle::getLen(point a, point b){
    return sqrt(pow(abs(a.x-b.x), 2)+ pow(abs(a.y-b.y), 2));
}

bool triangle::operator ==(triangle b){
    return this->getS()==b.getS();
}

bool triangle::operator !=(triangle b){
    return this->getS()!=b.getS();
}

bool triangle::operator <(triangle b){
    return this->getS()<b.getS();
}

bool triangle::operator >(triangle b){
    return this->getS()>b.getS();
}

void triangle::operator =(triangle obj){
    a = obj.a;
    b = obj.b;
    c = obj.c;
}

triangle triangle::operator +(vec obj){
    triangle tmp(point(a.x + obj.x, a.y + obj.y), point(b.x + obj.x, b.y + obj.y), point(c.x + obj.x, c.y + obj.y));
    return tmp;
}

