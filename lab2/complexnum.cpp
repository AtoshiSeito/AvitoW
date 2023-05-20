#include "complexnum.h"
complexnum::complexnum(){
    a=0; b=0;
}

complexnum::complexnum(complexnum& obj){
    a = obj.geta();
    b = obj.getb();
}

complexnum::complexnum(double c, double d=0){
    a = c;
    b = d;
}

double complexnum::geta(){
    return a;
}

double complexnum::getb(){
    return b;
}

complexnum complexnum::mult(double c){
    complexnum obj(a*c, b);
    return obj;
}

complexnum complexnum::mult(complexnum obj){
    complexnum tmp(a * obj.a - b * obj.b, a * obj.b + b * obj.a);
    return tmp;
}

complexnum complexnum::sum(complexnum obj){
    complexnum tmp(a + obj.a, b + obj.b);
    return tmp;
}

int complexnum::len(){
    string tmp = to_string(a).substr(0, to_string(a).find_last_not_of("0"))+" + "+to_string(b).substr(0, to_string(b).find_last_not_of('0'))+"*i";
    return tmp.length();
}

void complexnum::print(){
    cout<<"Ваше комплексное число: ";
    cout<<a<<" + "<<b<<"*i\n";
}

void complexnum::cinnum(){
    cout<<"Введите действительную часть: ";
    cin>>a;
    cout<<"Введите мнимую часть: ";
    cin>>b;
}
