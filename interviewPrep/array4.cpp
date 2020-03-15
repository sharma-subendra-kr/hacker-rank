// Array Manipulation

#include <iostream>
#include <omp.h>
#include <cstring>
using namespace std;

int main(){
  long long n , m;
  long long *arr, **op;

  cin>>n;
  cin>>m;
  arr = new long long [n]();
  op = new long long *[m];

  long long max = 0;
  for(long long i = 0; i < m; i++){
    op[i] = new long long [3];
    int a, b, c;
    cin>>a;
    cin>>b;
    cin>>c;
    op[i][0] = a;
    op[i][1] = b;
    op[i][2] = c;

    arr[a-1]+=c;
    arr[b]-=c;

    // #pragma omp parallel for /*num_threads(2)*/
    // for(long long j = a-1; j < b; j++){
      // arr[j]+=c;
      // if(arr[j] > max){
      //   max = arr[j];
      // }
      // arr[j]+=c;
      // if(a[b]<n){
      //
      // }
      // arr[b]-=c;
    // }

  }

  long long sum = 0;
  for(long long j = 0; j < n; j++){
    sum+=arr[j];
    if(max<sum){
      max = sum;
    }
  }

  // for(long long j = 0; j < n; j++){
  //   arr[j]+=c;
  //   if(arr[j] > max){
  //     max = arr[j];
  //   }
  // }

  cout<<max;

  return 0;
}
