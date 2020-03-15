// 2D Array - DS

#include <iostream>
#include <cstring>
using namespace std;

int main(){
  int n = 6, m = 6;
  int arr[6][6];
  // cin>>n;
  // cin>>m;

  // arr = new int[6][6];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin>>arr[i][j];
      // arr[i][j] = j;
    }
  }

  int count = 0;
  int sum = -9999;
  for(int i = 0; i < n - 2; i++){
    for(int j = 0; j < m - 2; j++){
      if(j < (m-2) && i < (n -2)){
        // cout<<++count<<"\n";
        int p1 = arr[i][j];
        int p2 = arr[i][j+1];
        int p3 = arr[i][j+2];
        int p4 = arr[i+1][j+1];
        int p5 = arr[i+2][j];
        int p6 = arr[i+2][j+1];
        int p7 = arr[i+2][j+2];
        // cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<" "<<p5<<" "<<p6;
        int s = p1 + p2 + p3 + p4 + p5 + p6 + p7;
        if(s > sum){
          sum = s;
        }
      }
    }
  }

  cout<<sum;
  return 0;
}
