// Minimum Absolute Difference in an Array

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int main(){
    int n;
    int* arr;
    int min = 1e6;
    //cout<<min;
    cin>>n;

    arr = new int[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i]; 
    }
    
    sort(arr, arr+n); 
    
    for(int i = 0; i < n-1; i++){
        int diff = abs(arr[i] - arr[i+1]);
        if(diff < min){
            min = diff;
        }
    }
    cout<<min;
}
