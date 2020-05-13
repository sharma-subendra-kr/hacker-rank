// Xor-sequence
// https://www.hackerrank.com/challenges/xor-se/problem
//
#include <stdio.h>
#include <stdlib.h>

long sum (long index) {
    long rem = index % 8;

    if (rem == 0 || rem == 1)
        return index;
    else if (rem == 2 || rem == 3)
        return 2;
    else if (rem == 4 || rem == 5)
        return index+2;
    else if (rem == 6 || rem == 7)
        return 0;
    else return 0;
}

int main () {
    long t, l, r, rem, zeroValLeftIndex, lval, val, res, interval;

    scanf("%ld", &t);
    /*
    while(t--) {
        scanf("%ld%ld", &l, &r);
        
        rem = (l+1)%4;
        zeroValLeftIndex = l - rem;
        lval = 0;
        while(rem) {
            zeroValLeftIndex++;
            lval = lval ^ zeroValLeftIndex;
            rem--;
        }
        
        
        val = lval;
        res = val;
        interval = r -l;
        while(interval) {
            l++;
            val = val ^ l;
            res = res ^ val;
            interval--;
        }
    
        printf("%ld\n", res);
    }
    */ 

    // Faster solution
    while (t--) {
        scanf("%ld%ld", &l, &r);
        res = sum(r) ^ sum(l-1);
        printf("%ld\n", res);
    }

    return 0;
}
