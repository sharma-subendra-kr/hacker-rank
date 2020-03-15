// Alternating Characters 

#include <iostream>
#include <omp.h>
#include <bits/stdc++.h>
#include <cstdlib>
#include <map>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
    int q;
    string s;

    cin>>q;

    while(q != 0){
        cin>>s;
        string fs;
        fs+=s[0];
        int del = 0;
        for(int i = 1; i < s.length(); i++){
            if(s[i] == s[i-1]){
                del++;
            }else{
                fs+=s[i];                
            }
        }
        cout<<del<<endl;
        q--;
    }
   
}
