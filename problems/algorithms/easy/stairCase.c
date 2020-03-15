// Staircase
// https://www.hackerrank.com/challenges/staircase/problem
//
#include <stdio.h>
#include <stdlib.h>

int main () {
    long n, i, j;

    scanf("%ld", &n);
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n -1 - i; j++){
            printf(" "); 
        }
        
        for(j = 0; j < i+1; j++){
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
