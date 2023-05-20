#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr;
int res = 0;
int minedge = 9999;
struct edge{
    int a, b;
    edge();
    edge(int c, int d){
        a = c;
        b = d;
    }
};
vector<edge> was = vector<edge>();

bool srch(int a, int b){
    for(int i=0; i<was.size(); i++){
        if(was[i].a==a&&was[i].b==b){
            return 1;
        }
    }
    return 0;
}

bool rec(int n, int pos){
    if(pos==n-1){
        for(int i=was.size()-1; i>=0; i--){
            arr[was[i].a][was[i].b]-=minedge;
        }
        res+=minedge;
        minedge = 9999;
        was = vector<edge>();
        return 1;
    }
    for(int i=n-1; i>=0; i--){
        if(arr[pos][i]&&!srch(pos, i)){
            was.push_back(edge(pos, i));
            int tmp = minedge;
            minedge = min(minedge, arr[pos][i]);
            if(rec(n, i)){
                return 1;
            } else {
                was.pop_back();
                minedge = tmp;
                arr[pos][i] = 0;
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, c;
    cin>>n>>m;
    arr = vector<vector<int>>(n, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        arr[a-1][b-1]=c;
    }
    while(rec(n, 0)){
        continue;
    }
    cout<<res<<endl;
    return 0;
}
//10 21
//1 2 46
//1 5 72
//2 3 73
//2 7 30
//3 4 82
//4 5 28
//5 6 82
//5 8 77
//6 7 62
//7 8 16
//7 10 51
//8 5 93
//8 9 70
//8 10 62
//9 2 61
//9 7 37
//9 10 36
//10 2 17
//10 3 45
//10 8 85
//10 10 55
