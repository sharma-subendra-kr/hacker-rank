// Luck Balance

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

struct Item {
    int L;
    int T;
};

bool compareFunc(Item a, Item b){
    if(a.L > b.L){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int n, k;
    struct Item *arr;
    cin>>n;
    cin>>k;

    arr = new struct Item[n];
    
    int ans = 0;

    for(int i = 0; i < n; i++){
        struct Item item;
        cin>>item.L;
        cin>>item.T;

        if(item.T == 0){
            ans+=item.L;
        }
        arr[i] = item;
    }
    
    sort(arr, arr+n, compareFunc); 
    
    for(int i = 0; i < n; i++){
        if(k != 0 && arr[i].T == 1){
            ans+=arr[i].L;
            k--;
        }else if(arr[i].T == 1){
            ans-=arr[i].L;
        }
    }
    cout<<ans;
}
