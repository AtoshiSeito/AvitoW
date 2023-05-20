#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <cmath>
#include <iostream>
using namespace std;
struct point{
    double x, y;
    point(){
        x=0;y=0;
    }
    point(double a, double b){
        x = a;
        y = b;
    }
};

struct vec{
    double x, y;
};

class triangle
{
public:
    point a, b, c;
    triangle();
    triangle(point, point, point);
    void print();
    double getS();
    double getLen(point, point);
    bool operator == (triangle);
    bool operator != (triangle);
    bool operator < (triangle);
    bool operator > (triangle);
    void operator = (triangle);
    triangle operator + (vec);
};

#endif // TRIANGLE_H
