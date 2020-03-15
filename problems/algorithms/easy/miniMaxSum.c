// Mini Max Sum
// https://www.hackerrank.com/challenges/mini-max-sum/problem
//
#include <stdio.h>
#include <stdlib.h>

int comp (const void *a, const void *b){
    
    long _a = *((long *) a);
    long _b = *((long *) b);

    if(_a > _b){
        return 1;
    }else if (_a < _b){
        return -1;
    }else{
        return 0;
    }
}

int main () {
    long arr[5] = {0, 0, 0, 0, 0}, i, minSum = 0, maxSum = 0;

    scanf("%ld%ld%ld%ld%ld", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
    
    // printf("\n%ld\t%ld\t%ld\t%ld\n", sizeof(arr), sizeof(arr[0]), sizeof(*arr), sizeof(arr)/sizeof(arr[0]));
    
    qsort(arr, 5, sizeof(*arr), comp);
    
    for(i = 0; i < 4; i++){
        minSum += arr[i];
    }

    for(i = 4; i >=1; i--){
        maxSum += arr[i];
    }

    printf("%ld %ld", minSum, maxSum);

    return 0;
}
