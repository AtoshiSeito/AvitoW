#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n, tmp, num;
    string out="";
    cin>>n;
    num = pow(2, n);
    for(int i=0; i<num; i++){
        tmp = (int)i^(i>>1);
        while(tmp){
            out+=(char)(tmp%2)+'0';
            tmp/=2;
        }
        for(int j=0; j<n-out.length(); j++){
            cout<<'0';
        }
        for(int j=out.length()-1; j>=0; j--){
            cout<<out[j];
        }
        out="";
        cout<<endl;
    }
    return 0;
}
