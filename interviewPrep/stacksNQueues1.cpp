// Balanced Brackets

#include <iostream>
#include <omp.h>
#include <bits/stdc++.h>
#include <cstdlib>
#include <map>
#include <cstdlib>
#include <string>

using namespace std;

bool isFront(char a){
    if(a == '{' || a == '(' || a == '['){
        return true;
    }
    return false;
}

bool isBack(char a){
    if(a == '{' || a == '(' || a == '['){
        return true;
    }
    return false;
}

bool isPair(char a, char b){
    if(a == '(' && b == ')'){
        return true;
    }else if(a == '{' && b == '}'){
        return true;
    }else if(a == '[' && b == ']'){
        return true;
    }
    return false;
}

int main(){
    int n;
    string str;
    char *stack;
    
    cin>>n;

    while(n != 0){
        cin>>str;
        stack = new char[str.size()];
        int stackPointer = 0;
        bool isValid = true;

        for(int i = 0; i < str.size(); i++){
            if(isFront(str[i])){
                //cout<<"isFront"<<endl;
                //cout<<str[i]<<endl;
                stack[stackPointer++] = str[i];
            }else{
                //cout<<"not front"<<endl;
                //cout<<str[i]<<endl;
                if(isPair(stack[stackPointer-1], str[i])){
                    //cout<<"isPair"<<endl;
                    //cout<<stack[stackPointer]<<endl;
                    //cout<<str[i]<<endl;

                    stackPointer--;
                }else{
                    isValid = false;
                    break;
                }
            }
            if(stackPointer < 0){
                isValid = false;
                break;
            }
        }

        if(!isValid){
            cout<<"NO"<<endl;
        }else if(stackPointer == 0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

        n--;
    }

}
