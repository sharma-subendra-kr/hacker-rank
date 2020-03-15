// Pairs

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, k;
    int *arr; 
    
    map<int, int> hMap;

    cin>>n>>k;

    arr = new int[n];
    
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    } 
    
    int output = 0;

    for(int i = 0; i < n; i++){
        auto iter = hMap.find(arr[i]);
        auto iter_ = hMap.find(arr[i]+k);
        auto iter__ = hMap.find(arr[i]-k);
        
        if(iter_ != hMap.end()){
            output++;   
        }
        if(iter__ != hMap.end()){
            output++;
        }
        hMap.insert({arr[i], i}); 
        
    } 
    
    cout<<output;
    return 0;
}
