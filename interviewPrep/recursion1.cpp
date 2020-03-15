// Recursion: Fibonacci Numbers

#include<iostream>

using namespace std;
/*
int fibonacci(int n){
    if(n == 1){
        return 1;
    }else if(n == 0){
        return 0;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}
*/
int fibonacci(int n){
    if(n == 1){
        return 1;
    }else if(n == 0){
        return 0;
    }

    int arr[2];
    arr[0] = 0;
    arr[1] = 1;
    
    int sum = 0;
    for(int i = 2; i <= n; i++){
        sum = arr[0] + arr[1]; 
        arr[0] = arr[1];
        arr[1] = sum;
    }

    return sum;
}

int main(){
    int n;
    cin>>n;
    cout<<fibonacci(n);
    return 0;
}
