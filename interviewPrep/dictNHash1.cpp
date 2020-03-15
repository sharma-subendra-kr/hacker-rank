// Hash Tables: Ransom Note

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  string *marr, *narr;
  map<string, int> magMap;

  cin>>m>>n;

  marr = new string[m];
  narr = new string[n];

  for(int i = 0; i < m; i++){
    cin>>marr[i];
    auto iter = magMap.find(marr[i]);
    if(iter == magMap.end()){
      magMap.insert({marr[i], 1});
    }else{
      int c = iter->second;
      iter->second++;
    }
  }

  int foundFlag = true;
  for(int i = 0; i < n; i++){
    cin>>narr[i];
    auto iter = magMap.find(narr[i]);
    if(iter == magMap.end()){
      foundFlag = false;
    }else if(iter->second > 0){
      iter->second--;
    }else{
      foundFlag = false;
    }
  }

  if(foundFlag == true){
    cout<<"Yes";
  }else{
    cout<<"No";
  }
  // for(int i = 0; i < m; i++){
  //   cout<<marr[i];
  // }
  //
  // for(int i = 0; i < n; i++){
  //   cout<<narr[i];
  // }


  // cout<<a.compare(b);
  return 0;
}
