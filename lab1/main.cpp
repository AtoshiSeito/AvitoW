#include "header.h"

using namespace std;

int main(){
    system("chcp 65001>null");

    //swap fun
    double a, b, r;
    cout<<"Введите переменные a и b, которые поменяются значениями:\n";
    cin>>a>>b;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    swap(&a, &b);
    cout<<"Перемещение по адресам:\n";
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    swap(a, b);
    cout<<"Перемещение по ссылкам:\n";
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;

    //floor fun
    cout<<"Введите переменную a, у которой будет отброшена дробная часть: ";
    cin>>a;
    b=a;
    floor(&a);
    cout<<"Переменная без дробной части (через адрес): "<<a<<endl;
    floor(b);
    cout<<"Переменная без дробной части (через ссылку): "<<b<<endl;

    //mul fun
    cout<<"Введите переменные a и b, составные комплексного числа:\n";
    cin>>a>>b;
    complexnum num(a, b);
    num.print();
    cout<<"Введите переменную c, на которую будет умножено комплексное число:\n";
    cin>>a;
    mult(&num, &a);
    cout<<"После умножения через адрес: ";
    num.print();
    mult(num, a);
    cout<<"После умножения через ссылку: ";
    num.print();

    //move fun
    cout<<"Введите переменные x, y и radius, координаты центра окружности и ее радиус:\n";
    cin>>a>>b>>r;
    round roundObj(a, b, r);
    vec myVec;
    cout<<"Введите переменные x и y, вектор, на который смещается окружность:\n";
    cin>>myVec.x>>myVec.y;
    move(&roundObj, &myVec);
    cout<<"Окружность после перемещения через адреса:\n";
    roundObj.print();
    move(roundObj, myVec);
    cout<<"Окружность после перемещения через ссылки:\n";
    roundObj.print();

    return 0;
}
