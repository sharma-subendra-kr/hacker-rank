// Sorting: Comparator

#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Player {
    int score;
    string name;
};

class Checker{
public:
  	// complete this method
    
    static int compareString (string a, string b){
        // cout<<"a "<<a<<endl;
        // cout<<"b "<<b<<endl;
        int l1 = a.size();
        int l2 = b.size();

        string s1;
        string s2;

        int len;
        bool swapped;

        if(l1 <= l2){
            len = l1;
            s1 = a;
            s2 = b;
            swapped = false;
        }else{
            len = l2;
            s1 = b;
            s2 = a;
            swapped = true;
        }

        for(int i = 0; i < len; i++){
            int c1 = int(s1[i]);
            int c2 = int(s2[i]);
            // cout<<"****"<<endl;
            // cout<<s1[i]<<endl;
            // cout<<s2[i]<<endl;
            // cout<<c1<<endl;
            // cout<<c2<<endl;
            // cout<<"swapped "<<swapped<<endl;
            if(c1 < c2){
                if(swapped != true){
                    return 1;
                }else{
                    return -1;
                }
            }else if(c2 < c1){
                if(swapped != true){
                    return -1;
                }else{
                    return 1;
                }
            }
        }
        if(l1 == l2){
            return 0;
        }else if(l1 < l2){
            return 1;
        }else{
            return -1;
        }
    }

    static int comparator(Player a, Player b)  {
        if(a.score < b.score){
            return -1;
        }else if(a.score == b.score){
            int res = compareString(a.name, b.name);
            // cout<<"res "<<res<<endl;
            // return compareString(a.name, b.name);
            return res;
        }else{
            return 1;
        }
    }
};

