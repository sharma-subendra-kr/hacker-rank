// A Very Big Sum
// https://www.hackerrank.com/challenges/a-very-big-sum/problem
//
#include <stdio.h>
#include <stdlib.h>

int main () {

    long n, *arr, i, sum = 0;

    scanf("%ld", &n);
    arr = (long*) malloc(sizeof(long) * n);

    for(i = 0; i < n; i++){
        scanf("%ld", &arr[i]);
        sum += arr[i];
    }

    printf("%ld", sum);
    
    free(arr);
}
