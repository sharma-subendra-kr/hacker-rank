// Compare the Triplets
// https://www.hackerrank.com/challenges/compare-the-triplets/problem
//
#include <stdio.h>
#include <stdlib.h>

int main () {
    int a[3] = {0, 0, 0}, b[3] = {0, 0, 0};
    int alice = 0, bob = 0, i = 0;
    
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    scanf("%d%d%d", &b[0], &b[1], &b[2]);
    
    for(i = 0; i < 3; i++){
        if(a[i] > b[i]){
            alice++;
        }else if(a[i] < b[i]){
            bob++;
        }
    }    

    printf("%d %d", alice, bob);
    return 0; 
}
