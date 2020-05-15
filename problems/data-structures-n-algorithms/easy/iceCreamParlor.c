//Ice Cream Parlor
//https://www.hackerrank.com/challenges/icecream-parlor/problem
//
#include <stdio.h>
#include <stdlib.h>

int main () {
    int t, m, n, *arr, i;

    scanf("%d", &t);

    while (t--) {
        scanf("%d%d", &m, &n);

        arr = (int*) malloc(sizeof(int) * n);

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
    
          
    }        
}
