#include "arr.h"
#include "triangle.h"

using namespace std;

int main(){
    system("chcp 65001>null");
    triangle a;
    triangle b;
    cout<<(a==b)<<endl<<(a!=b)<<endl<<(a<b)<<endl<<(a>b)<<endl;
    vec myvec;
    cin>>myvec.x>>myvec.y;
    (a+myvec).print();
    cout<<endl;

    arr myarr;
    arr myarr2;
    cout<<(myarr==myarr2)<<endl<<(myarr!=myarr2)<<endl<<(myarr<myarr2)<<endl<<(myarr>myarr2)<<endl;
    (myarr+myarr2).print();
    return 0;
}
