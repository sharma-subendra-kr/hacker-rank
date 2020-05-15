//Gridland Metro
//https://www.hackerrank.com/challenges/gridland-metro/problem
//
#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

struct range {
    long c1;
    long c2;
};

struct values {
    range *ranges;
    long len;
};

int comp (const void *a, const void *b) {
    int _a = ((range *)a) -> c1;
    int _b = ((range *)b) -> c1;
    if (_a < _b) {
        return -1;
    } else if (_a > _b) {
        return 1;
    }else {
        return 0;
    }
}

int main () {
    long n, m, k, i, j,  r, c1, c2, sum = 0;
    long **tracks;
    map<long, values> hm;

    cin>>n>>m>>k;
     
    for (i = 0; i < k; i++) {
        cin>>r>>c1>>c2;
        
        auto iter = hm.find(r);   
        if (iter == hm.end()) {
            range *ranges = new range[k];
            ranges[0].c1 = c1;
            ranges[0].c2 = c2;
            long len = 1; 
            values v;
            v.ranges = ranges;
            v.len = len;
            hm.insert({r, v});
        } else {
            iter->second.ranges[iter->second.len].c1 = c1;
            iter->second.ranges[iter->second.len].c2 = c2;
            ++iter->second.len;
        }
    }
    
    long trackLength = 0;
    range *stack = new range[k];
    int stackIter = -1;
    for (auto iter = hm.begin(); iter != hm.end(); iter++) {
        range *ranges = new range[iter->second.len];
        for (long i = 0; i < iter->second.len; i++) {
             ranges[i] = iter->second.ranges[i];
        }
        delete[] iter->second.ranges;
        iter->second.ranges = ranges;
        qsort(iter->second.ranges, iter->second.len, sizeof(iter->second.ranges[0]), comp);  


        //for (long i = 0; i < iter->second.len; i++) {
        //    cout<<iter->second.ranges[i].c1<<","<<iter->second.ranges[i].c2<<endl;
        //}
        
        stackIter = -1;
        
        stackIter = 0;
        stack[stackIter] = iter->second.ranges[stackIter];
        for (long i = 1; i < iter->second.len; i++) {
             if (stack[stackIter].c2 < iter->second.ranges[i].c1) {
                 stack[++stackIter] = iter->second.ranges[i];
             }

             if (stack[stackIter].c2 >= iter->second.ranges[i].c1 && stack[stackIter].c2 < iter->second.ranges[i].c2) {
                stack[stackIter].c2 = iter->second.ranges[i].c2;
             }
        }
        
        long _trackLength = 0;
        for (long i = 0; i < stackIter+1; i++) {
            //cout<<stack[i].c1<<","<<stack[i].c2<<endl;
            _trackLength = _trackLength + (stack[i].c2 - stack[i].c1 +1);
        }
        trackLength += _trackLength;
    }

    long totalSlots = n * m;
    long totalLampPosts = totalSlots - trackLength;

    cout<<totalLampPosts; 

    return 0;
}
