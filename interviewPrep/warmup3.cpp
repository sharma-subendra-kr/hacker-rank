// Jumping on the Clouds

#include <iostream>
using namespace std;

int main(){
  int n = 0;
  int *arr;

  cin>>n;

  arr = new int [n];

  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }

  // for(int i = 0; i < n; i++){
  //   cout<<arr[i];
  // }

  int steps = 0;
  for(int i = 0; i < n-1; i++){
    if(arr[i + 1] == 1 && (i + 1) != (n - 1)){
      steps++;
      i++;
      continue;
    }

    if(arr[i + 2] == 0){
      steps++;
      i++;
    }else{
      if(arr[i + 1] != 1){
          steps++;
      }
    }
  }
  cout<<steps;
  return steps;
}
