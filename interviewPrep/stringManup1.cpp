// Strings: Making Anagrams

#include <iostream>
#include <omp.h>
#include <bits/stdc++.h>
#include <cstdlib>
#include <map>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
    string s1, s2;
    map<char, int> m1, m2; 
    string alp = "abcdefghijklmnopqrstuvwxyz";

    for(int i = 0; i < 26; i++){
        m1.insert({alp[i], 0});
        m2.insert({alp[i], 0});
    }

    cin>>s1;
    cin>>s2;
    
    int len = 0;
    if(s1.length() > s2.length()){
        len = s1.length();
    }else{
        len = s2.length();
    }

    for(int i = 0; i < len; i++){
        auto iter1 = m1.find(s1[i]);
        auto iter2 = m2.find(s2[i]);
        
        if(i < s1.size()){
            if(iter1 != m1.end()){
                iter1->second++;
            }
        }
         
        if(i < s2.size()){
            if(iter2 != m2.end()){
                iter2->second++;
            }
        }
    }
    
    int ans = 0;
    map<char, int>::iterator it2 = m2.begin();
    for(map<char, int>::iterator it1 = m1.begin(); it1 != m1.end(); it1++){
        int diff = abs(it1->second - it2->second);
        cout<<"***********"<<endl;
        cout<<it1->first<<endl;
        cout<<it2->first<<endl;
        cout<<it1->second<<endl;
        cout<<it2->second<<endl;
        cout<<diff<<endl;
        ans+=diff;
        cout<<ans<<endl;
        it2++; 
    }
    
    cout<<ans; 

}
