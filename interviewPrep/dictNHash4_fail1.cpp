// Count Triplets

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

long factorial(long n){
  long prod = 1;
  for(long i = n; i > n-3; i--){
    prod = prod * i;
    // cout<<"prod "<<prod<<endl;
  }
  // cout<<"prod "<<prod<<endl;
  return prod;
}

long combination(long n){
  long f = factorial(n);
  return f/6;
}

int main(){
  long n, r;
  long *arr;
  long triplets = 0;
  map<long, long> hMap;
  cin>>n;
  cin>>r;

  arr = new long[n];

  for(long i = 0; i < n; i++){
    cin>>arr[i];
    // cout<<"processing input number "<<i<<endl;
    // cout<<"processing input "<<arr[i]<<endl;
    auto iter = hMap.find(arr[i]);
    if(iter == hMap.end()){
      hMap.insert({arr[i], 1});
    }else{
      iter->second++;
    }
  }


  // long len = hMap.size();
  for(auto i = hMap.begin(); i != hMap.end(); i++){
    // cout<<"*******"<<endl;
    long num = i->first;
    long numCount = i->second;
    long _2nd = num*r;
    long _3rd = num*r*r;

    if(_2nd == _3rd && numCount >= 3){
      // cout<<"numCount "<<numCount<<endl;
      long c = combination(numCount);
      // cout<<"combination "<<c<<endl;
      triplets+=c;
    }else{
      // cout<<"num "<<num<<"\n";
      // cout<<"2nd "<<_2nd<<endl;
      // cout<<"3rd "<<_3rd<<endl;
      auto iter1 = hMap.find(_2nd);
      auto iter2 = hMap.find(_3rd);
      if(iter1!=hMap.end() && iter2!=hMap.end()){
        long prod = iter1->second*iter2->second*numCount;
        // cout<<"prod "<<prod<<endl;
        triplets+=prod;
      }
    }

  }



  // long long num;
  // long long _2nd;
  // long long _3rd;
  // for(long long i = 0; i < n-1; i++){
  //   num = arr[i];
  //   _2nd = 0;
  //   _3rd = 0;
  //   // cout<<"******\n";
  //   // cout<<"num "<<num<<"\n";
  //   for(long long j = i; j < n; j++){
  //     if(num*r == arr[j]){
  //       _2nd++;
  //       // cout<<"2nd "<<arr[j]<<" "<<_2nd<<"\n";
  //     }
  //     if(num*r*r == arr[j]){
  //       _3rd++;
  //       // cout<<"3rd "<<arr[j]<<" "<<_3rd<<"\n";
  //     }
  //   }
  //   // if(_2nd < _3rd && _2nd > 0){
  //     triplets+=(_2nd*_3rd);
  //   // }else{
  //     // triplets+=_3rd;
  //   // }
  // }

  cout<<triplets;

  return 0;
}
