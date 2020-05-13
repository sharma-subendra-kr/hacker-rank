// Simple Array Sum
// https://www.hackerrank.com/challenges/simple-array-sum/problem
//

#include <stdio.h>
#include <stdlib.h>

int main () {
    long sum = 0, i, n;
    long *arr;

    scanf("%ld", &n);
    arr = (long *) malloc(sizeof(long) * n);
   
    for(i = 0; i < n; i++){
        scanf("%ld", &arr[i]);
    }

    for(i = 0; i < n; i++){
        sum += arr[i];
    }
    
    printf("%ld", sum);

    free(arr);

    return 0;
}

