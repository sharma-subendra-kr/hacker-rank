// AND Product
// https://www.hackerrank.com/challenges/and-product/problem
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int main () {
    unsigned int n, a, b, diff, SUM, PREV, res, prev;
    int count = 0;

    scanf("%u", &n);
    
    while (n--) {
        scanf("%u%u", &a, &b);
        count = 0;
        SUM = 0;
        diff = b - a;
        if (diff == 1) {
            printf("%u", a&b);
            continue;
        } else {
            printf("diff is not 1: %u\n", diff);
            while (diff > 1) {
                diff = diff/2;
                count++;
            }
            printf("count found: %d\n", count);
            // exit(0);
            do {
                SUM += pow(2, count); 
                count--;
                printf("SUM: %u\n", SUM);
                printf("count: %d\n", count);
                // sleep(1);
            } while (count >= 0);

            printf("SUM found: %u\n", SUM);
            PREV = a;
            while (PREV) {
                prev = PREV;
                PREV = PREV & (PREV - 1);
            }
            prev = (prev * 2) - 1;
            printf("PREV found: %u\n", PREV);
            printf("prev found: %u\n", prev);
            res = prev - SUM;
            printf("%u\n", res);
        }
    }

    return 0;
}
