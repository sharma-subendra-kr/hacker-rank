// Recursion: Davis' Staircase


#include <bits/stdc++.h>

using namespace std;

// Complete the stepPerms function below.
// int stepPerms(int n) {
//     if(n < 0){
//         return 0;
//     }else if(n == 0){
//         return 1;
//     }

//     return stepPerms(n-1) + stepPerms(n-2) + stepPerms(n-3);

// }

int stepPerms(int n) {
    if(n == 0){
        return 1;
    }else if(n == 1){
        return 1;
    }else if(n == 2){
        return 3;
    }else if(n == 3){
        return 4;
    }

    int arr[3];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;

    int sum = 0;
    for(int i = 3; i <= n; i++){
        sum = arr[0] + arr[1] + arr[2];
        arr[0] = arr[1];
        arr[1] = arr[2];
        arr[2] = sum;
    }
    
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
