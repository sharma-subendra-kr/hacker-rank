// Triple sum

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
    
    int *a, *b, *c;
    int input [3]; 
    int alen, blen, clen; 
    set<int> aSet, bSet, cSet;
    
    cin>>input[0]>>input[1]>>input[2]; 
    
    alen = input[0];
    blen = input[1];
    clen = input[2];

    //sort(input, input+3);
   
    a = new int[alen];  
    b = new int[blen];  
    c = new int[clen];  

    int ia, ib, ic;
    int ca = 0, cb = 0, cc = 0;
   
    for(int i = 0; i < alen; i++){
        cin>>ia;
        auto iter = aSet.find(ia);
        if(iter == aSet.end()){
            a[ca++] = ia; 
            aSet.insert(ia);
        }
    }

    for(int i = 0; i < blen; i++){
        cin>>ib;
        auto iter = bSet.find(ib);
        if(iter == bSet.end()){
            b[cb++] = ib; 
            bSet.insert(ib);
        }
    }    

    for(int i = 0; i < clen; i++){
        cin>>ic;
        auto iter = cSet.find(ic);
        if(iter == cSet.end()){
            c[cc++] = ic;
            cSet.insert(ic);
        }
    }

    sort(a, a+ca);
    sort(b, b+cb);
    sort(c, c+cc);
    
    long long output = 0;
    long long indexA = 0, indexC = 0;
    for(int i = 0; i < cb; i++){
        //memory location of upperbound-starting memory location of array = index of upperbound
        indexA = (upper_bound(a, a+ca, b[i]) - a);
        indexC = (upper_bound(c, c+cc, b[i]) - c);
        if(indexA >= 0 && indexC >= 0){
            output = output + (indexA * indexC);
        }
        
    }
    
    cout<<output;

    return 0;
}
