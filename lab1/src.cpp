#include "header.h"
void swap(double* a, double* b){
    double c = *a;
    *a = *b;
    *b = c;
}
void swap(double& a, double& b){
    double c = a;
    a = b;
    b = c;
}

void floor(double* a){
    *a = (int) *a;
}
void floor(double& a){
    a = (int) a;
}

complexnum::complexnum(double* a, double* b){
    this->a = *a;
    this->b = *b;
}
complexnum::complexnum(double& a, double& b){
    this->a = a;
    this->b = b;
}
void complexnum::print(){
    cout<<a<<" + "<<b<<" * i\n";
}

void mult(complexnum* num, double* c){
    num->a *= *c;
}
void mult(complexnum& num, double& c){
    num.a *= c;
}

round::round(double* x, double* y, double* r){
    this->centerx = *x;
    this->centery = *y;
    this->radius = *r;
}
round::round(double& x, double& y, double& r){
    this->centerx = x;
    this->centery = y;
    this->radius = r;
}
void round::print(){
    cout<<"["<<centerx<<", "<<centery<<"]\n"<<"Radius: "<<radius<<endl;
}

void move(round* obj, vec* a){
    obj->centerx+=a->x;
    obj->centery+=a->y;
}
void move(round& obj, vec& a){
    obj.centerx+=a.x;
    obj.centery+=a.y;
}
