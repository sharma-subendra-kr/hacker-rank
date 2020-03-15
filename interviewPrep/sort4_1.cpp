// Fraudulent Activity Notifications

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
#include<stdlib.h>
using namespace std;

float getMedian(int* trailArr, int* freqArr, int* sortedArr, int d){
    //for(int i = 0; i <= 200; i++){
    //    freqArr[i] = 0;
    //}

    //freqArr = new int[201];

    //for(int i = 0; i < d; i++){
    //    freqArr[trailArr[i]]++;
    //}
    
    //for(int i = 1; i <= 200; i++){
    //   freqArr[i] = freqArr[i] + freqArr[i-1];
    //}

    //for(int i = 0; i < d; i++){
    //    sortedArr[freqArr[trailArr[i]]-1] = trailArr[i]; 
    //    freqArr[trailArr[i]]--;
    //}
     
    int mid = d/2;
    int mid_ = mid-1;
    
    int v = 0;
    int v_ = 0;

    int count = 0; 
    
    for(int i = 0; i <= 200; i++){
        if(freqArr[i]>1){
            for(int j = 0; j < freqArr[i]; j++){
                count++;
            }
        }else if(freqArr[i] == 1){
            count++; 
        } 

        if(count-1 == mid_){
            v_ = i; 
        }
        
        if(count-1 == mid){
            v = i; 
            break;
        }
    }

    float median;
    if(d%2 == 0){
        median = ((float)v_ + (float)v)/2;
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
    static int index = 0;
    
    int val = trailArr[index];  

    trailArr[index] = value;
    index++;    

    if(index == d){
        index = 0;
    }
    
    return val;
}

void updateFrequency(int* freqArr, int dec, int inc){
    freqArr[dec]--;
    freqArr[inc]++;  
}

int main(){
    int n, d, *exp;
    
    int *trailArr, *freqArr, *sortedArr;

    cin>>n;
    cin>>d;
    
    exp = new int[n];
    trailArr = new int[d];
    freqArr = new int[201];
    sortedArr = new int[d];
    
    int max = 0;
    for(int i = 0; i < n; i++){
        cin>>exp[i];
        if(exp[i] > max){
            max = exp[i];
        }
    }
    
    for(int i = 0; i < d; i++){
        trailArr[i] = exp[i];
        freqArr[trailArr[i]]++;
    }
    
    

    int output = 0;
    for(int i = d; i < n; i++){
        //cout<<i<<endl;
        float median = getMedian(trailArr, freqArr, sortedArr, d);
        if(exp[i] >= median*2){
            output++;
        }
        int in = exp[i];
        int val = insertIntoTrail(trailArr, in, d);
        updateFrequency(freqArr, val, exp[i]);
    }  

    cout<<output<<endl; 
    //cout<<output<<endl; 
    
    delete[] trailArr;
    delete[] freqArr;
    delete[] sortedArr;
    delete[] exp;

    return 1;
}
