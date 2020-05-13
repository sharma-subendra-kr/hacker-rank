// Maximizing XOR
// https://www.hackerrank.com/challenges/maximizing-xor/problem
//
#include <stdio.h>
#include <stdlib.h>

int main () { 
    int l, r, max = 0, res = 0, i, j, count;

    scanf("%d%d", &l, &r);

    for(i = l; i <= r; i++){
        for(j = i; j <= r; j++){
            res = i ^ j;
            if(res > max){
                max = res;
            }
        }
    }
        
    printf("%d", max);

    return 0;
}
