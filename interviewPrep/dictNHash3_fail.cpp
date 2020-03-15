// Sherlock and Anagrams

#include <iostream>
#include <omp.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
  int prod = 1;
  for(int i = n; i > 0; i--){
    prod = prod * i;
  }
  return prod;
}

bool testAnagram(string s1, string s2){
  map<char, int> sMap;

  int len = s1.size();

  if(len != s2.size()){
    return false;
  }

  map<char, int>::iterator iter;
  for(int i = 0; i < len; i++){
    iter = sMap.find(s1[i]);
    if(iter == sMap.end()){
      sMap.insert({s1[i], 1});
    }else{
      iter->second++;
    }

    iter = sMap.find(s2[i]);
    if(iter == sMap.end()){
      sMap.insert({s2[i], -1});
    }else{
      iter->second--;
    }
  }

  for(map<char, int>::iterator it = sMap.begin(); it != sMap.end(); it++){
    if(it->second != 0){
      return false;
    }
  }
  return true;


  // map<char, int> s1Map;
  // map<char, int> s2Map;
  // bool anagramFlag = true;

  // map<char, int>::iterator iter1;
  // map<char, int>::iterator iter2;
  // for(int i = 0; i < len; i++){
  //     iter1 = s1Map.find(s1[i]);
  //     if(iter1 == s1Map.end()){
  //       s1Map.insert({s1[i], 1});
  //     }else{
  //       iter1->second++;
  //     }
  //
  //     iter2 = s2Map.find(s2[i]);
  //     if(iter2 == s2Map.end()){
  //       s2Map.insert({s2[i], 1});
  //     }else{
  //       iter2->second++;
  //     }
  // }

  // // len = s1.size();
  // for(int i = 0; i < len; i++){
  //   auto iter = s1Map.find(s1[i]);
  //   if(iter == s1Map.end()){
  //     s1Map.insert({s1[i], 1});
  //   }else{
  //     iter->second++;
  //   }
  // }
  //
  // // len = s2.size();
  // for(int i = 0; i < len; i++){
  //   auto iter = s2Map.find(s2[i]);
  //   if(iter == s2Map.end()){
  //     s2Map.insert({s2[i], 1});
  //   }else{
  //     iter->second++;
  //   }
  // }


  // if(s1Map.size() == s2Map.size()){
  //   map<char, int>::iterator it2;
  //   // char c;
  //   // int value;
  //   for(map<char, int>::iterator it1 = s1Map.begin(); it1 != s1Map.end(); it1++){
  //     // c = it1->first;
  //     // value = it1->second;
  //     it2 = s2Map.find(it1->first);
  //     if(it2 != s2Map.end()){
  //       if(it2->second != it1->second){
  //         anagramFlag = false;
  //         break;
  //       }
  //     }else{
  //       anagramFlag = false;
  //       break;
  //     }
  //   }
  //
  //   if(anagramFlag == true){
  //     return true;
  //   }else{
  //     return false;
  //   }
  //
  // }else{
  //   return false;
  // }

}

int main(){
  int t;
  string s;

  cin>>t;
  while(t != 0){
    cin>>s;
    int anagramCount = 0;



    // int count = 0;
    // int testLength = 0;
    // int len = s.size();
    // while(count <= (len - 2)){
    //   testLength = count+1;
    //   map <string, int> hMap;
    //   for(int i = 0; i < len; i++){
    //     if((i+(testLength - 1))<len){
    //       string sub = s.substr(i, testLength);
    //       auto iter = hMap.find(sub);
    //       if(iter == hMap.end()){
    //         // cout<<"insert"<<sub<<"\n";
    //         hMap.insert({sub, 1});
    //       }else{
    //         // cout<<"increment"<<sub<<"\n";
    //         iter->second++;
    //         // anagramCount++;
    //       }
    //     }
    //   }
    //
    //   for(auto it1 = hMap.begin(); it1 != prev(hMap.end()); it1++){
    //     // cout<<"******\n";
    //     // cout<<"it1 first "<<it1->first<<"\n";
    //     // cout<<"it1 second "<<it1->second<<"\n";
    //     for(auto it2 = next(it1); it2 != hMap.end(); it2++){
    //       // cout<<"it2 first "<<it2->first<<"\n";
    //       // cout<<"it2 second "<<it2->second<<"\n";
    //       bool res = testAnagram(it1->first, it2->first);
    //       // cout<<"res "<<res<<"\n";
    //       if(res){
    //         // cout<<"res added\n";
    //         // anagramCount++;
    //         anagramCount = anagramCount + it1->second;
    //       }
    //     }
    //     if(it1->second > 1){
    //       int an = factorial(it1->second)/(2*factorial(it1->second - 2));
    //       // cout<<"......\n";
    //       // cout<<"first "<<it1->first<<"\n";
    //       // cout<<"second "<<it1->second<<"\n";
    //       // cout<<"an "<<an<<"\n";
    //       anagramCount+=an;
    //     }
    //   }
    //
    //   auto itLast = prev(hMap.end());
    //   if(itLast->second > 1){
    //     int an = factorial(itLast->second)/(2*factorial(itLast->second - 2));
    //     // cout<<"-----\n";
    //     // cout<<"first "<<itLast->first<<"\n";
    //     // cout<<"second "<<itLast->second<<"\n";
    //     // cout<<factorial(itLast->second)<<"\n";
    //     // cout<<(2*factorial(itLast->second - 2))<<"\n";
    //     // cout<<itLast->first<<"\n";
    //     // cout<<itLast->second<<"\n";
    //     // cout<<"an "<<an<<"\n";
    //     anagramCount+=an;
    //   }
    //
    //   count++;
    // }



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
            res = testAnagram(s.substr(i, testLength), s.substr(j, testLength));
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
    cout<<anagramCount<<"\n";
    t--;
  }

  return 0;
}
