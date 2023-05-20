#include <iostream>
#include <vector>

using namespace std;

int k, n;
vector<vector<int>> arr;
vector<bool> nWas;

bool rec(int st, int i, int cost=0){
    if(cost+k<0){
        for(int j=0; j<n; j++){
            if(j==st){
                return false;
            }
        }
    }
    for(int j=0; j<n; j++){
        if(arr[i][j]<1000001&&nWas[j]){
            nWas[j]=0;
            if(!rec(st, j, cost+arr[i][j])){
                return false;
            }
            nWas[j]=1;
        }
    }
    return true;
}

int main()
{
    int N, m, start, end;
    bool flag=1;
    cin>>N>>k;

    for(int i=0; i<N; i++){
        cin>>n>>m;
        arr = vector<vector<int>>(n, vector<int>(n, 1000001));
        for(int j=0; j<m; j++){
            cin>>start>>end;
            start--; end--;
            cin>>arr[start][end];
            arr[end][start]=arr[start][end];
        }
        nWas = vector<bool>(n, 1);
        for(int j=0; j<n; j++){
            nWas[j]=0;
            if(!rec(j, j)){
                cout<<"NO\n";
                flag = 0;
                break;
            }
            nWas[j]=1;
        }
        if(flag) cout<<"YES\n";
        flag = 1;
    }

    return 0;
}
