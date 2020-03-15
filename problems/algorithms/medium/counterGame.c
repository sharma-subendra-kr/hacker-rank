// Counter game
// https://www.hackerrank.com/challenges/counter-game/problem
//
#include <stdio.h>
#include <stdlib.h>

unsigned long long int popCount (unsigned long long int x) {
    unsigned long long int count = 0;
    while(x) {
        x &= (x-1);
        count++;
    }
    return count;
} 

int main () {
    unsigned long long int t, n, popRes;

    scanf("%llu", &t);
    
    while(t--){
        scanf("%llu", &n);
    
        popRes = popCount(n-1);
        if(popRes & 1) {
            printf("Louise\n");
        } else {
            printf("Richard\n");
        }
    }
}
