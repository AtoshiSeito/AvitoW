#include "menu.h"

menu::menu(){
    system("chcp 65001>null");
    cout<<"Добро пожаловать в программу для работы с комплексным числом.\n";
    init(mainObj);
}

void menu::mult(){
    complexnum* tmp = new complexnum();
    cout<<"Вы хотите умножить на вещественное число(1) или на комплексное(2)? (для выхода нажмите 0)\n";
    cin>>act;
    if(act==1){
        double b;
        cout<<"Пожалуйста, введите вещественное число для умножения: ";
        cin>>b;
        tmp = new complexnum(mainObj->mult(b));
        tmp->print();
        cout<<"Результат умножения: "; tmp->print();
        act=0;
        cout<<"Вы желаете сохранить результат? (да - 1)\n";
        cin>>act;
        if(act==1) mainObj = new complexnum(*tmp);
    } else if(act==2){
        cout<<"Пожалуйста, инициализируйте комплексное число: \n";
        tmp->cinnum();
        tmp = new complexnum(mainObj->mult(*tmp));
        tmp->print();
        cout<<"Вы желаете сохранить результат? (да - 1)\n";
        cin>>act;
        if(act==1) mainObj = new complexnum(*tmp);
    } else if(act==0){
        action();
    } else {
        cout<<"Вы ввели некорректное значение.\n";
        mult();
    }
    action();
}

void menu::sum(){
    complexnum* tmp = new complexnum();
    cout<<"Пожалуйста, инициализируйте комплексное число: \n";
    tmp->cinnum();
    tmp = new complexnum(mainObj->sum(*tmp));
    tmp->print();
    char p;
    cout<<"Вы желаете сохранить результат? (да - 1)\n";
    cin>>p;
    if(p=='1') mainObj = new complexnum(*tmp);
    action();
}

void menu::len(){
    cout<<mainObj->len()<<endl;
    action();
}

void menu::print(){
    mainObj->print();
    action();
}

void menu::init(complexnum* obj){
    cout<<"Пожалуйста, инициализируйте комплексное число: \n";
    obj->cinnum();
    action();
}

void menu::action(){
    cout<<"Выберете действие:\n"
          "1. Умножить.\n"
          "2. Сложить.\n"
          "3. Вывести длину комплексного числа.\n"
          "4. Вывести комплексное число.\n"
          "5. Заново ввести комплексное число.\n";
    cin>>act;
    system("cls");
    switch(act){
    case 1:
        mult();
        break;
    case 2:
        sum();
        break;
    case 3:
        len();
        break;
    case 4:
        print();
        break;
    case 5:
        init(mainObj);
        break;
    default:
        cout<<"Вы ввели неверное значение, пожалуйста, выберете пункт из списка.\n";
        action();
    }
}
