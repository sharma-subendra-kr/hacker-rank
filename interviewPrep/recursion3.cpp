// Recursive Digit Sum

#include<iostream>

using namespace std;

long long count = 0;

char* getString(long long num){
    char *dig = new char[1000];
    long long q, rem;

    count = 0;

    rem = num%10;
    q = num/10;
    dig[count++] = rem+'0';
    num = q;
    while(q != 0){
        rem = num%10;
        q = num/10;
        dig[count++] = rem + '0';
        num = q;
    }
    return dig;
}

int superDigit(long long num){
    long long sum = 0;
    
    char *dig = getString(num);

    for(long long i = 0; i < count; i++){
        sum = sum + (dig[i] - '0');  
    }
    if(sum > 10){
        sum = superDigit(sum); 
    }  
    return sum;
}

int superDigit(char* dig){
    long long sum = 0;

    for(long long i = 0; i < count; i++){
        sum = sum + (dig[i] - '0');  
    }
    if(sum > 10){
        sum = superDigit(sum); 
    }  
    return sum;
}


int main(){
    long long n, k, p;
    char *arr;
    
    cin>>n>>k;
    
    
    char *a = getString(n);
    arr = new char[count*k]; 
    
    int li = 0;
    for(long long i = 0; i < count*k; i++){
        arr[i] = a[li++];
        if(li == count){
            li = 0;
        } 
    }
    
    count = count*k;
    cout<<superDigit(arr);

    return 0;
}
