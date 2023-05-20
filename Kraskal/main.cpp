#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct edge{
    long long a, b, weight;
    bool was=0;
};

bool comp(edge a, edge b){
    return a.weight<=b.weight;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, m, weight, count=2, compSv=1, tmpWeight=999999;
    cin>>n>>m;
    vector<edge> arr(m);
    vector<bool> nWas(n, 1);
    for(long long i=0; i<m; i++){
        cin>>arr[i].a>>arr[i].b>>arr[i].weight;
        arr[i].a--; arr[i].b--;
    }
    sort(arr.begin(), arr.end(), comp);
    vector<edge> brr(arr);
    nWas[arr[0].a]=0;
    nWas[arr[0].b]=0;
    weight=arr[0].weight;
    for(unsigned long long i=1; i<arr.size(); i++){
        if(nWas[arr[i].a]!=nWas[arr[i].b]||nWas[arr[i].a]){
            if(nWas[arr[i].a]==nWas[arr[i].b]) compSv++;
            weight+=arr[i].weight;
            nWas[arr[i].a]=0;
            nWas[arr[i].b]=0;
            arr[i].was=1;
            count++;
        } else if(compSv>1){
            compSv--;
            weight+=arr[i].weight;
        }
        if(count==n&&compSv==1) break;
    }
    cout<<weight<<" ";
    for(int k=0; k<m; k++){
        if(arr[k].was){
            count=0;
            nWas = vector<bool>(n, 1);
            brr.erase(vector<edge>::iterator(&brr[k]));
            nWas[brr[0].a]=0;
            nWas[brr[0].b]=0;
            weight=brr[0].weight;
            for(unsigned long long i=1; i<brr.size(); i++){
                if(nWas[brr[i].a]!=nWas[brr[i].b]||nWas[brr[i].a]){
                    if(nWas[brr[i].a]==nWas[brr[i].b]) compSv++;
                    weight+=brr[i].weight;
                    nWas[brr[i].a]=0;
                    nWas[brr[i].b]=0;
                    count++;
                } else if(compSv>1){
                    compSv--;
                    weight+=brr[i].weight;
                }
                if(count==n&&compSv==1) break;
            }
            tmpWeight = min(tmpWeight, weight);
            brr=arr;
        }
    }
    cout<<tmpWeight<<endl;
    return 0;
}
