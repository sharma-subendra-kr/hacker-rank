// Sparse Arrays
// https://www.hackerrank.com/challenges/sparse-arrays/problem
//
#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, q; 
    map<string, int> m;
    string *arr2;
    string temp;

    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>temp;
        auto iter = m.find(temp);
        if (iter == m.end()) {
            m.insert({temp, 1});
        } else {
            iter->second++;
        }
    }
    
    cin>>q;
    arr2 = new string[q];
    for (int i = 0; i < q; i++) {
        cin>>temp;
        arr2[i] = temp;
    }
    
    int match = 0;    
    for (int j = 0; j < q; j++) {
        match = 0;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            if (iter->first.compare(arr2[j]) == 0) {
                cout<<iter->second<<endl;
                match = 1;
            }
        }
        if (match == 0) {
            cout<<0<<endl;
        }
    }

    return 0;
}
