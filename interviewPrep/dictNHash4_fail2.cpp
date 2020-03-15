// Count Triplets

#include <iostream>
#include <omp.h>
#include <cstring>
#include <string>
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

int main(int argc, char** argv){
  long long n, r;
  long long *arr;
  long long triplets = 0;
  map<long long, long long> hMap;
  // cin>>n;
  // cin>>r;

  n = stoi(argv[1]);
	r = stoi(argv[2]);

  arr = new long long[n];

  for(long long i = 0; i < argc - 3; i++){
    // cin>>arr[i];
    arr[i] = stoi(argv[i + 3]);

    // cout<<"processing input number "<<i<<endl;
    // cout<<"processing input "<<arr[i]<<endl;
    auto iter = hMap.find(arr[i]);
    if(iter == hMap.end()){
      hMap.insert({arr[i], 1});
    }else{
      iter->second++;
    }
  }

  for(long long i = 0; i < n; i++){
    auto iter = hMap.find(arr[i]);
    long long num = iter->first;
    long long numCount = iter->second;
    long long _2nd = num*r;
    long long _3rd = num*r*r;

    if(_2nd == _3rd && numCount >= 3){
      // cout<<"numCount "<<numCount<<endl;
      long long c = combination(numCount);
      // cout<<"combination "<<c<<endl;
      iter->second = 0;
      triplets+=c;
    }else if(numCount > 0){
      auto iter1 = hMap.find(_2nd);
      auto iter2 = hMap.find(_3rd);
      if(iter1!=hMap.end() && iter2!=hMap.end()){
        long long prod = iter1->second*iter2->second;
        // cout<<"prod "<<prod<<endl;
        iter->second--;
        triplets+=prod;
      }
    }
  }


  cout<<triplets;

  return 0;
}
