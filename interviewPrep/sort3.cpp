// Sorting: Comparator

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int main(){
  int n = 2;

  string *arr = new string[2];

  for(int i = 0; i < n; i++){
    cin>>arr[i];
  }

  // int l1 = strlen(arr[0]);
  // int l2 = strlen(arr[1]);
  int l1 = arr[0].size();
  int l2 = arr[1].size();

  string s1;
  string s2;

  int len;

  int retVal;

  if(l1 < l2){
    len = l2;
    s1 = arr[1];
    s2 = arr[0];

    retVal = 1;
  }else{
    len = l1;
    s1 = arr[0];
    s2 = arr[1];

    retVal = -1;
  }

  for(int i = 0; i < len; i++){
    // string a = ""+s2[i];
    // int c2 = stoi(a);
    // string b = ""+s1[i];
    // int c1 = stoi(b);
    int c2 = int(s2[i]);
    int c1 = int(s1[i]);
    cout<<c2<<endl;
    cout<<c1<<endl;
    if(c1 < c2){
      cout<<retVal<<endl;
      break;
      // return s1v;
    }else if(c2 < c1){
      cout<<retVal<<endl;
      break;
      // return s1v;
    }else{
      // return 0;
    }
  }

  if(l1 == l2){
    cout<<0<<endl;
    // return 0;
  }else if(l1 < l2){
    cout<<-1<<endl;
    // return -1;
  }else{
    cout<<1<<endl;
    // return 1;
  }

  // cout<<l1<<endl;
  // cout<<l2<<endl;

}
