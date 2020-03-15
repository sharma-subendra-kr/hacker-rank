// Repeated String

#include <iostream>
#include <cstring>
using namespace std;

int main(){
  long long int n = 0;
  char a[2] = "a";
  char *arr;

  arr = new char [100];
  cin>>arr;
  int len = strlen(arr);

  cin>>n;

  long long int quotient = n/len;
  int remaining = n - (quotient * len);

  int countInStr = 0;
  for(int i = 0; i < len; i++){
    if(arr[i] == a[0]){
      countInStr++;
    }
  }

  int countInRem = 0;
  for(int i = 0; i < remaining; i++){
    if(arr[i] == a[0]){
      countInRem++;
    }
  }

  cout<<(countInStr * quotient) + countInRem;
  return 0;
}


// #include <bits/stdc++.h>
//
// using namespace std;
//
// // Complete the repeatedString function below.
// long repeatedString(string s, long n) {
//
//
// }
//
// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));
//
//     string s;
//     getline(cin, s);
//
//     long n;
//     cin >> n;
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//     long result = repeatedString(s, n);
//
//     fout << result << "\n";
//
//     fout.close();
//
//     return 0;
// }
