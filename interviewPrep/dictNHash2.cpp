// Two Strings

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  string s1, s2;
  map<char, bool> s1Map;

  cin>>t;

  while (t != 0) {
    cin>>s1;
    cin>>s2;
    s1Map.clear();

    int sizeS1 = s1.size();
    for(int i = 0; i < sizeS1; i++){
      // auto iter = s1Map.find(s1[i]);
      // if(iter == s1Map.end()){
        s1Map.insert({s1[i], true});
      // }
    }

    int foundFlag = false;
    int sizeS2 = s2.size();
    for(int i = 0; i < sizeS2; i++){
      auto iter = s1Map.find(s2[i]);
      if(iter != s1Map.end()){
        foundFlag = true;
        break;
      }
    }

    if(foundFlag){
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }

    t--;
  }

  return 0;
}
