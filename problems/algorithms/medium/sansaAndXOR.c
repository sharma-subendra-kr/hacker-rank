// Sansa and XOR
// https://www.hackerrank.com/challenges/sansa-and-xor/problem
//
#include <stdio.h>
#include <stdlib.h>

int main () {
    int t, n, temp, i, ans = 0;
    
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        ans = 0;
        
        for(i = 0; i < n; i++) {
            scanf("%d", &temp);
            if((i+1)%2 != 0) {
                ans = ans ^ temp;
            }
        }

        if(n % 2 == 0) { 
            printf("%d\n", 0);
        }else {
            printf("%d\n", ans);
        }
        
        
    }

    return 0;
}
