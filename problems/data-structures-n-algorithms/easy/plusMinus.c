// Plus Minus
// https://www.hackerrank.com/challenges/plus-minus/problem
//
#include <stdio.h>
#include <stdlib.h>

int main () {
    long n, i, numPos = 0, numNeg = 0, numZero = 0;
    long *arr;
    float ratioPos, ratioNeg, ratioZero;

    scanf("%ld", &n);

    arr = (long*) malloc(sizeof(long) * n);

    for(i = 0; i < n; i++){
        scanf("%ld", &arr[i]);
        if(arr[i] > 0){
            numPos++;
        }else if(arr[i] < 0){
            numNeg++;
        }else{
            numZero++;
        }
    }
    
    ratioPos = (float) numPos / n;
    ratioNeg = (float) numNeg / n;
    ratioZero = (float) numZero / n;
    
    printf("%f\n%f\n%f", ratioPos, ratioNeg, ratioZero);
    return 0;
    
}
