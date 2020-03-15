// Time Conversion
// https://www.hackerrank.com/challenges/time-conversion/problem
//
#include <stdio.h>
#include <stdlib.h>

int main () {
    char ampm[11], shr[3], res[9]; 
    int hr, hr1, hr2, i;

    scanf("%s", ampm);

    if(ampm[8] == 'P'){
        hr1 = ampm[0] - '0';
        hr2 = ampm[1] - '0';
        hr = hr1 * 10 + hr2 + 12;
        if(hr == 24){
            hr = 12;
            res[0] = '1';
            res[1] = '2';
        }else{
            res[0] = hr/10 + '0';
            res[1] = hr%10 + '0';
        }
        
        // printf("is pm %d %d %d %s", hr1, hr2, hr, res);    
    }else{
        if(ampm[0] == '1' && ampm[1] == '2'){
            res[0] = '0';
            res[1] = '0';
        }else{
            res[0] = ampm[0];
            res[1] = ampm[1];
        }
    }  

    for(i = 2; i <= 7; i++){
        res[i] = ampm[i];
    }
    res[8] = '\0';
    printf("%s", res);
}
