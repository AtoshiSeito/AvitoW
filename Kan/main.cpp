#include <iostream>
#include <vector>
using namespace std;
//для удобства использовал 1 как #, а 0 как .
bool rec(vector<vector<int>> &arr, int i, int j){
  arr[i][j]=1; //если пришли в эту точку, то отмечаем пройденной (#)
  if(j<arr[i].size()-1)if(arr[i][j+1]==0){
      arr[i][j+1]=1;
      return 1;
  }
  if(i<arr.size()-1)if(arr[i+1][j]==0){
      arr[i+1][j]=1;
      return 1;
  }
  if(j>0)if(arr[i][j-1]==0){
      arr[i][j-1]=1;
      return 1;
  }
  if(i>0)if(arr[i-1][j]==0){
      arr[i-1][j]=1;
      return 1;
  }
  arr[i][j]=0;
  return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  int n, m, q, a, b;//размеры квартиры
  int sum=0;//счетчик комнат
  cin>>n>>m>>q;
  vector<vector<int>> arr(n, vector<int>(m, 0)); //матрица, заполненная 1 (#)
  for(int i=0; i<q; i++){//заполнение точками
      cin>>a>>b;
      arr[a-1][b-1]=1;//пишем 0
  }
  for(int i=0; i<n; i++){//проходимся по каждому элементу
    for(int j=0; j<m; j++){
      if(arr[i][j]==0){//если точка
        if(rec(arr, i, j)){
            sum+=2;
        }//заполняем комнату #
      }
    }
  }
  cout<<sum<<endl;
  return 0;
}
