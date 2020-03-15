// Grading Students
// https://www.hackerrank.com/challenges/grading/problem
//
#include <stdio.h>
#include <stdlib.h>

int main () {
    int n, *arr, i = 0, q, prod;
        
    scanf("%d", &n);

    arr = (int*) malloc(sizeof(int) * n);

    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        
        if(arr[i] >= 38){
            q = arr[i] / 5;
            prod = (q + 1) * 5;

            if(prod - arr[i] < 3){
                arr[i] = arr[i] + prod - arr[i];
            }
        }
    }

    for(i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}
