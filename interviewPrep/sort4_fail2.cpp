// Fraudulent Activity Notifications

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int main(){
  long long n, d, *arr, *prevArr;
  double med;
  long long medIndex, medIndex1, medIndex2;
  long long notice = 0;
  bool medIndexSingle;

  cin>>n;
  cin>>d;

  if(d%2 == 0){
    medIndexSingle = false;
    medIndex = (d-1)/2;
    // medIndex2 = (d/2) + 1;
    // cout<<"false "<<medIndex<<endl;
  }else{
    medIndexSingle = true;
    medIndex = (d-1)/2;
    // cout<<"true "<<medIndex<<endl;
  }

  arr = new long long[n];
  prevArr = new long long[d];

  for(long long i = 0; i < n; i++){
    cin>>arr[i];
  }

  long long index;
  for(long long j = 0; j < d; j++){
    prevArr[j] = arr[j];
    index = j;
  }

  // sort(arr, arr+n);
  // cout<<"after sort"<<endl;

  for(long long i = d; i < n; i++){
    // cout<<"*****"<<endl;
    // cout<<"arr[i] "<<arr[i]<<endl;
    if(i > d){
      if(index == d-1){
        index = 0;
        prevArr[0] = arr[i];
      }else{
        index++;
        prevArr[index] = arr[i];
      }
    }

    sort(prevArr, prevArr+d);

    // for(long long k = 0; k < d; k++){
    //   cout<<"sorted "<<prevArr[k]<<endl;
    // }

    if(medIndexSingle == true){
      // cout<<"single "<<medIndex<<endl;
      med = (double)prevArr[medIndex];
    }else{
      // cout<<"double "<<medIndex<<" "<<medIndex+1<<endl;
      med = (double)(prevArr[medIndex]+prevArr[medIndex+1])/2;
    }
    // cout<<"med "<<med<<endl;
    if(arr[i] >= (med*2)){
      notice++;
      // cout<<"notice "<<notice<<endl;
    }
  }

  cout<<notice;

  return 0;
}
