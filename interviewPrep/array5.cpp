// New Year Chaos

#include <iostream>
#include <cstring>
using namespace std;

int main(){
  int t, n;
  int *arr;
  int *barr, *uarr;

  cin>>t;

  while(t != 0){
    cin>>n;
    arr = new int [n];
    barr = new int [n];
    uarr = new int [n];
    harr = new int [n];
    for(int i = 0; i < n; i++){
      cin>>arr[i];
      barr[i + 1] = 0;
      uarr[i] = i + 1;
      harr[arr[i]] = i;
    }

    int bribes = 0;
    int chaoticFlag = false;
    for(int i = 0; i < n; i++){
      if(arr[i] == (i+1)){
        continue;
      }else if(arr[i] == (i+1) + 1){
        bribes++;
        int temp = uarr[i + 1];
        uarr[i + 1] = uarr[i];
        uarr[i] = temp;
        barr[uarr[i + 1]]++;
      }else if(arr[i] == (i+1) + 2){
        bribes+=2;
        int temp1 = uarr[i + 1];
        int temp2 = uarr[i + 2];
        uarr[i + 2] = uarr[i + 1];
        uarr[i + 1] = uarr[i];
        uarr[i] = temp2;

        barr[uarr[i + 1]]++;
        barr[uarr[i + 2]]++;
      }else if(arr[i] <= i){
        int diff = i - ((arr[i] - 1) + barr[arr[i]]);
        // int diff = ((arr[i] - 1) + barr[arr[i]]) - i;

        if(diff > 0){
          cout<<"*****\n";
          cout<<"who "<<arr[i]<<"\n";
          cout<<"original index "<<(arr[i] - 1)<<"\n";
          cout<<"bribes "<<barr[arr[i]]<<"\n";
          cout<<"should be index "<<((arr[i] - 1) + barr[arr[i]])<<"\n";
          cout<<"current Index "<<i<<"\n";
          cout<<"diff "<<diff<<"\n";

          bribes+=diff;
          barr[arr[i]]+=diff;
        }
      }else{
        cout<<"Too chaotic\n";
        chaoticFlag = true;
      }
    }

    if(chaoticFlag == false){
      cout<<bribes<<"\n";
    }
    t--;
  }
  return 0;
}


// for(int i = 0; i < n - 1; i++){
//   for(int j = 0; j < n - i - 1; j++){
//     if(arr[j] > arr[j + 1]){
//       if(j < ((arr[j] - 1) - 2)){
//         cout<<"Too chaotic\n";
//         chaoticFlag = true;
//           break;
//       }
//       int temp = arr[j + 1];
//       arr[j + 1] = arr[j];
//       arr[j] = temp;
//       bribes++;
//     }
//   }
//   if(chaoticFlag == true){
//     break;
//   }
// }

// for(int i = 0; i < n; i++){
//   for(int j = 0; j < i; j++){
//     if(arr[j] > arr[i]){
//       if(j < (arr[j] - 1) - 2){
//         chaoticFlag = true;
//         cout<<"Too chaotic\n";
//         break;
//       }
//       bribes++;
//     }
//   }
//   if(chaoticFlag == true){
//     break;
//   }
// }

// if(chaoticFlag == false){
//   cout<<bribes<<"\n";
// }
// t--;
