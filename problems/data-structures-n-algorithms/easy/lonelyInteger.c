// Lonely Integer
// https://www.hackerrank.com/challenges/lonely-integer/problem

#include <stdio.h>
#include <stdlib.h>

int main () {
    int n, *arr, i, res = 0;

    scanf("%d", &n);

    arr = (int *) malloc(sizeof(int) * n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        res = res ^ arr[i];
    }
    
    printf("%d", res);    

}
