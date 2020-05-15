//Hackerland Radio Transmitters
//https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem
//
#include <stdio.h>
#include <stdlib.h>

int main () {
    int n, k, max = 0, i, j, count = 0;
    int *arr, *arr2;

    scanf("%d%d", &n, &k);

    arr = (int*) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    arr2 = (int*) malloc(sizeof(int) * (max + k));
    
    for (i = 0; i < max; i++) {
        arr2[i] = 0;
    }

    for (i = 0; i < n; i++) {
        arr2[arr[i] - 1] = 1;
    }
    
    for (i = 0; i < max; i++) {
        if (arr2[i] == 1 && arr2[i + k] == 1) {
            count++;
            i+=(k*2);
        } else if (arr2[i] == 1) {
            j = i + k - 1;
            while (j > i) {
                if (arr2[j] == 1) {
                    break;
                } 
                j--;
            }
            i = j + k;
            count++;
        }
    }

    printf("%d", count);
    return 0;      
}
