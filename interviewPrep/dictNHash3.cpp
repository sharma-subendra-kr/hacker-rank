// Sherlock and Anagrams

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

string getSignature(string s, map<char, int> alpMap){
  int *sig = new int[26]();
  string sigStr;

  int len = s.size();
  for(int i = 0; i < len; i++){
    auto itr = alpMap.find(s[i]);
    sig[itr->second]+=1;
  }

  for(int i = 0; i < 26; i++){
    char c = sig[i] + '0';
    sigStr+=c;
  }

  return sigStr;
}

int main(){
  int t;
  string s;
  char alp[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  map<char, int> alpMap;
  map<string, string> sigMap;

  for(int i = 0; i < 26; i++){
    alpMap.insert({alp[i], i});
  }

  cin>>t;
  while(t != 0){
    cin>>s;

    int anagramCount = 0;
    int count = 0;
    int testLength = 0;
    int len = s.size();
    map <string, string> hMap;
    while(count <= (len - 2)){
      testLength = count+1;
      for(int i = 0; i < len; i++){
        if((i+(testLength - 1))<len){
          string sub = s.substr(i, testLength);
          auto iter = hMap.find(sub);
          if(iter == hMap.end()){
            // cout<<"insert "<<sub<<"\n";
            string sig = getSignature(sub, alpMap);
            // cout<<sig<<"\n";
            sigMap.insert({sig, sub});
            hMap.insert({sub, sig});
          }
        }
      }
      count++;
    }


    len = s.size();
    count = 0;
    testLength = 0;
    int res;
    string s1;
    string s2;
    while(count <= (len - 2)){
      // cout<<"******\n";
      testLength = count+1;

      for(int i = 0; i < len-1; i++){
        if(i + (testLength - 1) < (len-1)){
          for(int j = i+1; j < len; j++){
            if((j + (testLength - 1))>=len){
              break;
            }
            s1 = hMap.find(s.substr(i, testLength))->second;
            s2 = hMap.find(s.substr(j, testLength))->second;
            res = s1.compare(s2);
            if(res == 0){
              anagramCount++;
            }
          }
        }else{
          break;
        }
      }
    count++;
    }

    /*
    int anagramCount = 0;

    int len = s.size();
    int count = 0;
    int testLength = 0;
    bool res;
    while(count <= (len - 2)){
      // cout<<"******\n";
      testLength = count+1;

      for(int i = 0; i < len-1; i++){
        if(i + (testLength - 1) < (len-1)){
          for(int j = i+1; j < len; j++){
            if((j + (testLength - 1))>=len){
              break;
            }
            // cout<<"******\n";
            // cout<<s.substr(i, testLength)<<"\n";
            // cout<<s.substr(j, testLength)<<"\n";
            res = testAnagram(s.substr(i, testLength), s.substr(j, testLength), alpMap, sigMap);

            // cout<<res<<"\n";
            if(res){
              anagramCount++;
            }
          }
        }else{
          break;
        }
      }
    count++;
    }
    */


    cout<<anagramCount<<"\n";
    t--;
  }

  return 0;
}
