#ifndef ARR_H
#define ARR_H
#include <vector>
#include <iostream>
using namespace std;

class arr
{
public:
    vector<int> array;
    arr();
    arr(arr&);
    int len();
    void print();
    arr operator + (arr);
    bool operator == (arr);
    bool operator != (arr);
    bool operator < (arr);
    bool operator > (arr);
};

#endif // ARR_H
