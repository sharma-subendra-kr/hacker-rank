// Flipping bits
// https://www.hackerrank.com/challenges/flipping-bits/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main () {
    unsigned int n;
    int q;

    scanf("%d", &q);

    while (q--) {
        scanf("%u", &n);

        printf("%u\n", UINT_MAX - n);
    }

    return 0;
}
