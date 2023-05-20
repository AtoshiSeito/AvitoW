#ifndef COMPLEXNUM_H
#define COMPLEXNUM_H
#include <string>
#include <iostream>
using namespace std;

class complexnum
{
private:
    double a, b;
public:
    complexnum();
    complexnum(complexnum&);
    complexnum(double, double);

    double geta();
    double getb();

    complexnum mult(double);
    complexnum mult(complexnum);
    complexnum sum(complexnum);
    int len();
    void print();
    void cinnum();
};

#endif // COMPLEXNUM_H
