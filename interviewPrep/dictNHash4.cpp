// Count Triplets

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

long long factorial(long long n){
  long long prod = 1;
  for(long long i = n; i > n-3; i--){
    prod = prod * i;
    // cout<<"prod "<<prod<<endl;
  }
  // cout<<"prod "<<prod<<endl;
  return prod;
}

long long combination(long long n){
  long long f = factorial(n);
  return f/6;
}

int main(){
  long long n, r;
  long long *arr;
  long long triplets = 0;
  map<long long, long long> lMap, rMap;
  cin>>n;
  cin>>r;

  arr = new long long[n];

  for(long long i = 0; i < n; i++){
    cin>>arr[i];
    // cout<<"processing input number "<<i<<endl;
    // cout<<"processing input "<<arr[i]<<endl;
    auto iter = rMap.find(arr[i]);
    if(iter == rMap.end()){
      rMap.insert({arr[i], 1});
    }else{
      iter->second++;
    }
  }

  for(long long i = 0; i < n; i++){
    rMap[arr[i]]--;
    if(arr[i]%r == 0){
      triplets+=lMap[arr[i]/r]*rMap[arr[i]*r];
    }
    lMap[arr[i]]++;
  }


  // for(auto i = hMap.begin(); i != hMap.end(); i++){
  //   // cout<<"*******"<<endl;
  //   long long num = i->first;
  //   long long numCount = i->second;
  //   long long _2nd = num*r;
  //   long long _3rd = num*r*r;
  //
  //   if(_2nd == _3rd && numCount >= 3){
  //     // cout<<"numCount "<<numCount<<endl;
  //     long long c = combination(numCount);
  //     // cout<<"combination "<<c<<endl;
  //     triplets+=c;
  //   }else{
  //     // cout<<"num "<<num<<"\n";
  //     // cout<<"2nd "<<_2nd<<endl;
  //     // cout<<"3rd "<<_3rd<<endl;
  //     auto iter1 = hMap.find(_2nd);
  //     auto iter2 = hMap.find(_3rd);
  //     if(iter1!=hMap.end() && iter2!=hMap.end()){
  //       long long prod = iter1->second*iter2->second*numCount;
  //       // cout<<"prod "<<prod<<endl;
  //       triplets+=prod;
  //     }
  //   }
  //   i->second--;
  // }



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
