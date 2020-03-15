// Diagonal Difference
// https://www.hackerrank.com/challenges/diagonal-difference/problem
//
#include <stdio.h>
#include <stdlib.h>

int main () {
    long n, i, j, **arr, leftSum = 0, rightSum = 0, ans;

    scanf("%ld", &n);
    
    arr = (long**) malloc(sizeof(long) * n);

    for(i = 0; i < n; i++){
        arr[i] = (long *) malloc(sizeof(long) * n);
        for(j = 0; j < n; j++){
            scanf("%ld", &arr[i][j]);
            if(i == j){
                leftSum += arr[i][j];
            }
        }
        rightSum += arr[i][n-1-i];
    }

    ans = abs(leftSum - rightSum);
    printf("%ld", ans);
    free(arr);
}
