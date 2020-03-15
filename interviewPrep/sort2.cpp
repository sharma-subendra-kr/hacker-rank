// Mark and Toys

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, k;
  long long *prices;

  cin>>n;
  cin>>k;

  prices =  new long long[n];

  for(long long i = 0; i < n; i++){
    cin>>prices[i];
  }

  sort(prices, prices+n);

  long long sum = 0;
  long long i;
  for(i = 0; i < n; i++){
    if((sum+prices[i]) <= k){
      sum = sum + prices[i];
    }else{
      break;
    }
  }

  cout<<i;

  return 0;
}
