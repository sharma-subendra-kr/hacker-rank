// Sum vs XOR
// https://www.hackerrank.com/challenges/sum-vs-xor/problem?h_r=next-challenge&h_v=zen
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    long n, count = 0, m, xres;
    // double xres;
        
    scanf("%ld", &n);

    while (n) {
        m = n % 2?0:1;
        n/=2;
        count+=m;        
    }

    xres = pow(2, count);
    printf("%ld", xres);
    return 0;
}
