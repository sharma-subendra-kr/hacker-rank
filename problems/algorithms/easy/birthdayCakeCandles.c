// Birthday Cake Candles
// https://www.hackerrank.com/challenges/birthday-cake-candles/problem
//
#include <stdio.h>
#include <stdlib.h>

int main () {
    int age, *arr, i, max = -1, maxNum = 0;

    scanf("%d", &age);
    
    arr = (int*) malloc(sizeof(int) * age);

    for(i = 0; i < age; i++){
        scanf("%d", &arr[i]);

        if(arr[i] > max){
            max = arr[i];
            maxNum = 1;
        }else if(arr[i] == max){
            maxNum++;
        }
    }
    
    printf("%d", maxNum);
}
