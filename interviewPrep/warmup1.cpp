// Sock Merchant

#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n = 0;
  int *arr;
  map<int, int> socksMap;

  // socksMap.insert({1, 2});
  // // auto iter = socksMap.find(3);
  // auto iter = socksMap.end();
  // cout<<iter->first;
  // cout<<iter->second;

  // return 0;

  while(n <= 0 || n > 100){
      cout<<"Enter N";
      cin>>n;
  }

  arr = new int [n];


  for(int i = 0; i < n; i++){
    while(arr[i] <= 0 || arr[i] > 100){
        // cout<<"Enter "<< i <<" th Sock color";
        cin>>arr[i];
    }
  }

  int pairs = 0;
  for(int i = 0; i < n; i++){
    auto iter = socksMap.find(arr[i]);
    if(iter == socksMap.end()){
      socksMap.insert({arr[i], 1});
    }else{
      iter->second++;
      if(iter->second % 2 == 0){
        pairs++;
      }
    }
  }
  // cout<<pairs;

  return pairs;
}


// #include <bits/stdc++.h>
//
// using namespace std;
//
// vector<string> split_string(string);
//
// // Complete the sockMerchant function below.
// int sockMerchant(int n, vector<int> ar) {
//
//
// }
//
// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));
//
//     int n;
//     cin >> n;
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//     string ar_temp_temp;
//     getline(cin, ar_temp_temp);
//
//     vector<string> ar_temp = split_string(ar_temp_temp);
//
//     vector<int> ar(n);
//
//     for (int i = 0; i < n; i++) {
//         int ar_item = stoi(ar_temp[i]);
//
//         ar[i] = ar_item;
//     }
//
//     int result = sockMerchant(n, ar);
//
//     fout << result << "\n";
//
//     fout.close();
//
//     return 0;
// }
//
// vector<string> split_string(string input_string) {
//     string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
//         return x == y and x == ' ';
//     });
//
//     input_string.erase(new_end, input_string.end());
//
//     while (input_string[input_string.length() - 1] == ' ') {
//         input_string.pop_back();
//     }
//
//     vector<string> splits;
//     char delimiter = ' ';
//
//     size_t i = 0;
//     size_t pos = input_string.find(delimiter);
//
//     while (pos != string::npos) {
//         splits.push_back(input_string.substr(i, pos - i));
//
//         i = pos + 1;
//         pos = input_string.find(delimiter, i);
//     }
//
//     splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
//
//     return splits;
// }
