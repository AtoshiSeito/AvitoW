#include "interfaces.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(Triangle a, Triangle b){
    return a<b;
}

bool comp2(Round a, Round b){
    return a<b;
}

int main()
{
    system("chcp 65001>null");
    vector<Triangle> tarr;
    vector<Round> rarr;
    int act;
    while(1){
        double s=0;
        CVector2D mr(0, 0);
        cout<<"Menu:\n"
              "1. Добавление фигуры.\n"
              "2. Отобразить все фигуры.\n"
              "3. Суммарная площадь всех фигур.\n"
              "4. Суммарный периметр всех фигур.\n"
              "5. Центр масс всей системы.\n"
              "6. Занимаемая системой память.\n"
              "7. Сортировка фигур по массе.\n";
        cin>>act;
        system("cls");
        switch (act) {
        case 1:
            cout<<"Какую фигуру вы хотите добавить? (1 - треугольник, 2 - круг)\n";
            cin>>act;
            if(act==1){
                tarr.push_back(Triangle());
            } else if(act==2){
                rarr.push_back(Round());
            }
            break;
        case 2:
            for(unsigned int i=0;i<tarr.size();i++){
                tarr[i].draw();
            }
            for(unsigned int i=0;i<rarr.size();i++){
                rarr[i].draw();
            }
            break;
        case 3:
            for(unsigned int i=0;i<tarr.size();i++){
                s+=tarr[i].square();
            }
            for(unsigned int i=0;i<rarr.size();i++){
                s+=rarr[i].square();
            }
            cout<<s<<endl;
            break;
        case 4:
            for(unsigned int i=0;i<tarr.size();i++){
                s+=tarr[i].perimeter();
            }
            for(unsigned int i=0;i<rarr.size();i++){
                s+=rarr[i].perimeter();
            }
            cout<<s<<endl;
            break;
        case 5:
            for(unsigned int i=0;i<tarr.size();i++){
                s+=tarr[i].mass;
                mr= mr + CVector2D(tarr[i].position.x*tarr[i].mass, tarr[i].position.y*tarr[i].mass);
            }
            for(unsigned int i=0;i<rarr.size();i++){
                s+=rarr[i].mass;
                mr= mr + CVector2D(rarr[i].position.x*rarr[i].mass, rarr[i].position.y*rarr[i].mass);
            }
            cout<<"["<<mr.x/s<<" "<<mr.y/s<<"]"<<endl;
            break;
        case 6:
            for(unsigned int i=0;i<tarr.size();i++){
                s+=tarr[i].size();
            }
            for(unsigned int i=0;i<rarr.size();i++){
                s+=rarr[i].size();
            }
            cout<<s<<endl;
            break;
        case 7:
            sort(tarr.begin(), tarr.end(), comp);
            sort(rarr.begin(), rarr.end(), comp2);
            break;
        default:
            cout<<"Такого пункта нет.\n";
            break;
        }
    }
    return 0;
}
