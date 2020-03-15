// Arrays: Left Rotation

#include <iostream>
#include <cstring>
using namespace std;

int main(){
  int n = 0, d = 0;
  int *arr;
  int *cache;

  cin>>n;
  cin>>d;

  arr = new int [n];
  cache = new int [d];

  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }

  int iterCache = 0;

  for(int i = 0; i < n; i++){
    if(i < d){
      cache[iterCache++] = arr[i];

    }
    if(i >= d){
      int diff = i - d;
      // int temp = arr[i];

      arr[diff] = arr[i];
    }
  }

  int it = 0;
  for(int i = n - d; i < n; i++){
    arr[i] = cache[it++];
  }

  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}
