// The Great XOR
// https://www.hackerrank.com/challenges/the-great-xor/problem?h_r=next-challenge&h_v=zen
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    long t, x, res, rem, count = 0;

    scanf("%ld", &t);

    while (t--) {
        scanf("%ld", &x);
        res = 0;
        count = 0;
        while (x) {
            rem = x%2?1:0; 
            x/=2;
            if(rem == 0){
                res = res + pow(2, count);
            }
            count++;          
        }
        printf("%ld\n", res);
    }
}
