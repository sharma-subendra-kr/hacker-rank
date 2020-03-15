// Minimum Time Required

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
    
    int n, goal, *arr;
    
    cin>>n>>goal;
    
    arr = new int[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
   

    long long low = 0;
    long long high = 1e18;
    long long mid = 0; 
    long long done = 0;
    long long output = 0;

    while(low <= high){
        mid = (low + high)/2; 
        done = 0;

        for(int i = 0; i < n; i++){
            done+=(mid/arr[i]);
            if(done >= goal){
                break;
            }
        }

        if(done > goal){
            high = mid - 1;
            output = mid;
        }else if(done < goal){
            low = mid + 1;
        }else{
            high = mid - 1; 
            output = mid; 
        }
    }
    
    cout<<output;
     
    return 0;
}
