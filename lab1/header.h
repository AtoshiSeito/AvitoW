#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>

using namespace std;

void swap(double*, double*);
void swap(double&, double&);

void floor(double*);
void floor(double&);

class complexnum{
public:
    double a, b;
    complexnum(double*, double*);
    complexnum(double&, double&);
    void print();
};

void mult(complexnum*, double*);
void mult(complexnum&, double&);

class round{
public:
    double centerx, centery, radius;
    round(double*, double*, double*);
    round(double&, double&, double&);
    void print();
};

struct vec{
    double x, y;
};

void move(round*, vec*);
void move(round&, vec&);

#endif // HEADER_H
