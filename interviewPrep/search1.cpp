// Hash Tables: Ice Cream Parlor

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int main(){
    short t; 
    int money, n, *cost;  
    map<int, int> hMap;

    cin>>t;

    while(t > 0){
        //cout<<"******"<<endl;
        hMap.clear();
        cin>>money; 
        cin>>n;
        cost = new int[n];
        for(int i = 0; i < n; i++){
            cin>>cost[i];
        }
        
        
        for(int i = 0; i < n; i++){
            if(cost[i]>=money || cost[i] <= 0){
                continue;
            }
            auto iter = hMap.find(cost[i]);
            auto iter_ = hMap.find((money - cost[i]));
                        
            if(iter_ != hMap.end()){
                cout<<iter_->second+1<<" "<<i+1<<endl;
                break;
            }else if(iter == hMap.end()){
                hMap.insert({cost[i], i});
            }

        }
        delete[] cost;
        t--;
    } 

    return 0;
}
