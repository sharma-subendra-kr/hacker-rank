// Fraudulent Activity Notifications

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int ind = 0;

float getMedian(int* freqArr, int d){
    int mid = d/2;
    int mid_ = mid-1;
    
    int v = 0;
    int v_ = 0;

    int count = -1; 
    
    for(int i = 0; i <= 200; i++){
        if(freqArr[i]>=1){
            for(int j = 0; j < freqArr[i]; j++){
                count++;
            }
        }

        if(count == mid_){
            v_ = i; 
        }
        
        if(count == mid){
            v = i; 
            break;
        }
    }

    float median;
    if(d%2 == 0){
        median = ((float)v_ + (float)v)/2.0;
    }else{
        median = v;     
    }
    
    //cout<<"****"<<endl; 
    //cout<<v_<<endl;    
    //cout<<v<<endl;    
    //cout<<median<<endl;    

    return median; 
}

int insertIntoTrail(int* trailArr, int value, int d){
    //static int ind = 0;
    
    int val = trailArr[ind];  

    trailArr[ind] = value;
    ind++;    

    if(ind == d){
        ind = 0;
    }
    
    return val;
}

void updateFrequency(int* freqArr, int dec, int inc){
    freqArr[dec]--;
    freqArr[inc]++;  
}

int main(){
    int n, d, *exp;
    
    int *trailArr, *freqArr;

    cin>>n;
    cin>>d;
    
    exp = new int[n];
    trailArr = new int[d];
    freqArr = new int[201];
    
    for(int i = 0; i < n; i++){
        cin>>exp[i];
    }
    
    cout<<"*****input read******"<<endl;

    for(int i = 0; i < d; i++){
        trailArr[i] = exp[i];
        freqArr[trailArr[i]]++;
    }
    
    

    int output = 0;
    int val = 0;
    for(int i = d; i < n; i++){
        //cout<<i<<endl;
        float median = getMedian(freqArr, d);
        if((float)exp[i] >= median*2.0){
            output++;
        }
        val = insertIntoTrail(trailArr, exp[i], d);
        updateFrequency(freqArr, val, exp[i]);
    }  

    cout<<output<<endl; 
    
    delete[] trailArr;
    delete[] freqArr;
    delete[] exp;

    return 1;
}
