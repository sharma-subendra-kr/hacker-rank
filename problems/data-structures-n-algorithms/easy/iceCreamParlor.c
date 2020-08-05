//Ice Cream Parlor
//https://www.hackerrank.com/challenges/icecream-parlor/problem
//
#include <stdio.h>
#include <stdlib.h>

int comp (const void *a, const void *b) {
    int _a = *(int *)a;
    int _b = *(int *)b;

    if (_a < _b) {
        return -1; 
    } else if (_a > _b) {
        return 1;
    } else {
        return 0;
    }
}

int main () {
    int t, m, n, *arr, *freq, i, j, diff;

    scanf("%d", &t);

    arr = (int*) malloc(sizeof(int) * 99999);
    freq = (int*) malloc(sizeof(int) * 99999);

    while (t--) {
        scanf("%d%d", &m, &n);


        for (i = 0; i < 99999; i++) {
            freq[i] = 0;
        }
        
        for (i = 0; i < 99999; i++) {
            arr[i] = 0;
        }

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            if (freq[arr[i]] == 0) {
                freq[arr[i]] = 1;
            } else {
                freq[arr[i]]++;
            }
        }

        for (i = 0; i < n; i++) {
            diff = m - arr[i];
            if (diff > 0 && freq[diff] != 0 && ((diff == arr[i])?(freq[diff]>1)?1:0:1)) {
                for (j = 0; j < n; j++) {
                    if (arr[j] == diff && j != i) {
                        break;
                    }
                }
            
                if (i < j) {
                    printf("%d %d\n", i+1, j+1);
                    break;
                } else {
                    printf("%d %d\n", j+1, i+1);
                    break;
                }
            }
        }
    }

    free(arr);
    free(freq);
    return 0;
}
