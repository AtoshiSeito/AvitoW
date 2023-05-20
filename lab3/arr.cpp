#include "arr.h"

arr::arr(){
    int n;
    cout<<"Введите количество элементов: ";
    cin>>n;
    array.resize(n);
    for(int i=0;i<n;i++){
        cout<<"i-ый элемент: ";
        cin>>array[i];
        cout<<endl;
    }
}

arr::arr(arr& a){
    array.resize(a.len());
    for(int i=0; i<a.len(); i++){
        array[i]=a.array[i];
    }
}

int arr::len(){
    return array.size();
}

void arr::print(){
    for(int i=0; i<len(); i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

arr arr::operator +(arr a){
    arr tmp(*this);
    tmp.array.resize(len()+a.len());
    for(int i=len(); i<tmp.len(); i++){
        tmp.array[i] = a.array[i-len()];
    }
    return tmp;
}

bool arr::operator ==(arr a){
    if(len()!=a.len()) return 0;
    for(int i=0; i<len(); i++){
        if(array[i]!=a.array[i]) return 0;
    }
    return 1;
}

bool arr::operator !=(arr a){
    return !(a==*this);
}

bool arr::operator <(arr a){
    return len()<a.len();
}

bool arr::operator >(arr a){
    return len()>a.len();
}
