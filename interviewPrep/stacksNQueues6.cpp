// Poisonous Plants

#include <iostream>
#include <omp.h>
#include <bits/stdc++.h>
#include <cstdlib>
#include <map>
#include <cstdlib>
#include <string>

using namespace std;

struct Item {
    int plant;
    int day;
};

int main(){
    int n;
    int *arr;
    struct Item *stack;
    int output = 0;

    cin>>n;
    arr = new int[n];
    stack = new struct Item[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    int stackPointer = 0;
    for(int i = 0; i < n; i++){
        //if(stackPointer == 0 || stack[stackPointer-1].plant == arr[i]){
        if(stackPointer == 0){
            struct Item item;
            item.plant = arr[i];
            item.day = 0;
            stack[stackPointer++] = item;
        }else if(stack[stackPointer-1].plant < arr[i]){
            struct Item item;
            item.plant = arr[i];
            item.day = 1;
            stack[stackPointer++] = item;
            output = max(output, 1);
        }else if(stack[stackPointer-1].plant >= arr[i]){
            //int d = stack[stackPointer-1].day;
            while(stackPointer >= 1 && stack[stackPointer-1].plant >= arr[i]){
                stackPointer--;
            }
            if(stackPointer == 0){
                struct Item item;
                item.plant = arr[i];
                item.day = 0;
                stack[stackPointer++] = item;
            }else{
                struct Item item;
                item.plant = arr[i];
                //item.day = d+1;
                item.day = output+1;
                stack[stackPointer++] = item;
                //output = max(output, d+1);
                output = max(output, output+1);
            }
        }
    }
    
    cout<<output<<endl;

}
