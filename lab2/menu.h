#ifndef MENU_H
#define MENU_H
#include <vector>
#include <iostream>
#include "complexnum.h"
using namespace std;

class menu
{
private:
    complexnum* mainObj;
    int act;
public:
    menu();
    void mult();
    void sum();
    void len();
    void print();
    void init(complexnum*);
    void action();
};

#endif // MENU_H
