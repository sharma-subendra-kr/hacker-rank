// Sherlock and the Valid String

#include <iostream>
#include <omp.h>
#include <bits/stdc++.h>
#include <cstdlib>
#include <map>
#include <cstdlib>
#include <string>

using namespace std;

//ibfdgaeadiaefgbhbdghhhbgdfgeiccbiehhfcggchgghadhdhagfbahhddgghbdehidbibaeaagaeeigffcebfbaieggabcfbiiedcabfihchdfabifahcbhagccbdfifhghcadfiadeeaheeddddiecaicbgigccageicehfdhdgafaddhffadigfhhcaedcedecafeacbdacgfgfeeibgaiffdehigebhhehiaahfidibccdcdagifgaihacihadecgifihbebffebdfbchbgigeccahgihbcbcaggebaaafgfedbfgagfediddghdgbgehhhifhgcedechahidcbchebheihaadbbbiaiccededchdagfhccfdefigfibifabeiaccghcegfbcghaefifbachebaacbhbfgfddeceababbacgffbagidebeadfihaefefegbghgddbbgddeehgfbhafbccidebgehifafgbghafacgfdccgifdcbbbidfifhdaibgigebigaedeaaiadegfefbhacgddhchgcbgcaeaieiegiffchbgbebgbehbbfcebciiagacaiechdigbgbghefcahgbhfibhedaeeiffebdiabcifgccdefabccdghehfibfiifdaicfedagahhdcbhbicdgibgcedieihcichadgchgbdcdagaihebbabhibcihicadgadfcihdheefbhffiageddhgahaidfdhhdbgciiaciegchiiebfbcbhaeagccfhbfhaddagnfieihghfbaggiffbbfbecgaiiidccdceadbbdfgigibgcgchafccdchgifdeieicbaididhfcfdedbhaadedfageigfdehgcdaecaebebebfcieaecfagfdieaefdiedbcadchabhebgehiidfcgahcdhcdhgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd

int main(){
    string s;
    map<char, int> alpMap;
    string alp = "abcdefghijklmnopqrstuvwxyz";

    for(int i = 0; i < 26; i++){
       alpMap.insert({alp[i], 0}); 
    }
    
    cin>>s;
    //cout<<s.size()<<endl;

    for(int i = 0; i < s.size(); i++){
        auto iter = alpMap.find(s[i]);
        iter->second++;
    }
    
    map<int, int> numMap;
    
    int cnt = 0;
    for(auto iter = alpMap.begin(); iter != alpMap.end(); iter++){
        auto numIter = numMap.find(iter->second);
        if(numIter != numMap.end() && iter->second != 0){
            numIter->second++;        
        }else if(iter->second != 0){
            numMap.insert({iter->second, 1});
            cnt++;
            if(cnt > 2){
                cout<<"NO";
                exit(0);
            }
        }
    } 
    
    auto iter = numMap.begin();
    auto iter2 = iter++;
    int diff1 = abs(iter->second - iter2->second);
    int diff2 = abs(iter->first - iter2->first);
    
    //cout<<iter->first<<endl;
    //cout<<iter->second<<endl;
    //cout<<iter2->first<<endl;
    //cout<<iter2->second<<endl;

    //if(numMap.size()>2){
    //    cout<<"NO";
    //}else if(numMap.size() == 1){
    if(numMap.size() == 1){
        cout<<"YES";
    }else if(diff2 == 1){
        if(iter->second == 1 || iter2->second == 1){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
    }else if(diff2 > 1){
        if((iter->first == 1 && iter->second == 1) || (iter2->first == 1 && iter2->second == 1)){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
    }else{
        cout<<"NO";
    }
}
