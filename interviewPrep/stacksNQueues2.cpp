// Largest Rectangle

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int maxh = 0;

void findTillEmptyStack(int* pStack, int* hStack, int &sTop, int currentPos){
    int tempMax = 0;
    while(sTop >= 0){
        tempMax = hStack[sTop] * (currentPos - pStack[sTop]);
        if(tempMax > maxh){
            maxh = tempMax;
        } 
        sTop--;
    } 
     
}

int main(){
    int n, *harr;
    int *pStack, *hStack;

    cin>>n;
    
    harr = new int[n];   
    pStack = new int[n];
    hStack = new int[n];

    for(int i = 0; i < n; i++){
        cin>>harr[i];
    }
    
    int sTop = -1;
    int tempMax = 0;
    for(int i = 0; i < n; i++){ 
        if(sTop < 0){
            pStack[0] = i;
            hStack[0] = harr[i]; 
            sTop++;
        }else if(harr[i] == 0){
            findTillEmptyStack(pStack, hStack, sTop, i);
        }else if(harr[i] > hStack[sTop]){
            pStack[sTop + 1] = i;
            hStack[sTop + 1] = harr[i];
            sTop++;
        }else if(harr[i] < hStack[sTop]){
            tempMax = hStack[sTop] * (i - pStack[sTop]);
            if(tempMax > maxh){
                maxh = tempMax;
                hStack[sTop] = harr[i];
            }else{
                //sTop--; 
            }
        }
    }

    findTillEmptyStack(pStack, hStack, sTop, n);
    
    cout<<maxh<<endl;

    return 1;
}
