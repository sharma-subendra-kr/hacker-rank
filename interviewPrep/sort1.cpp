// Sorting: Bubble Sort

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  long long *arr;

  cin>>n;

  arr = new long long[n];

  for(long long i = 0; i < n; i++){
    cin>>arr[i];
  }

  long long count = 0;
  for(long long i = 0; i < n-1; i++){
    for(long long j = 0; j < n-i-1; j++){
      if(arr[j]>arr[j+1]){
        long long temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        count++;
      }
    }
  }

  cout<<"Array is sorted in "<<count<<" swaps."<<endl;
  cout<<"First Element: "<<arr[0]<<endl;
  cout<<"Last Element: "<<arr[n-1]<<endl;
  return 0;
}
