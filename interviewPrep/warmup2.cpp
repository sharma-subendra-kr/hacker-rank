// Counting Valleys

#include <iostream>
using namespace std;

int main(){
  int n = 0;
  char D[2] = "D";
  char U[2] = "U";
  char *arr;

  while(n < 2 || n > 1000000){
      cout<<"Enter N";
      cin>>n;
  }

  arr = new char [n];

  cin>>arr;
  cout<<arr;

  // for(int i = 0; i < n; i++){
  //   while(arr[i] != D[0] && arr[i] != U[0]){
  //       cout<<"Enter "<< i <<" th Move";
  //       cin>>arr[i];
  //       // cout<<arr[i]<<"\n";
  //       // bool res = arr[i] != D[0];
  //       // cout<<D[0]<<"\n";
  //       // cout<<res<<"\n";
  //   }
  // }

  int seaLevel = 0;
  int track = 0;
  int valleys = 0;
  for(int i = 0; i < n; i++){
    cout<<"********\n";
    if(seaLevel == 0){
      cout<<"seaLevel"<<seaLevel<<"\n";
      if(track == 1){
        cout<<"track"<<track<<"\n";
        cout<<"valleys"<<valleys<<"\n";
        valleys++;
      }
      track = 1;
      cout<<"track"<<track<<"\n";
    }
    if(arr[i] == D[0]){
      seaLevel--;
      cout<<"seaLevel"<<seaLevel<<"\n";
    }
    if(arr[i] == U[0]){
      seaLevel++;
      cout<<"seaLevel"<<seaLevel<<"\n";
    }
    if(seaLevel > 0){
      track = 0;
      cout<<"track"<<track<<"\n";
    }
  }

  if(seaLevel == 0){
    cout<<"seaLevel"<<seaLevel<<"\n";
    if(track == 1){
      cout<<"track"<<track<<"\n";
      cout<<"valleys"<<valleys<<"\n";
      valleys++;
    }
    track = 1;
    cout<<"track"<<track<<"\n";
  }

  cout<<valleys<<"\n";
  return valleys;
}


// #include <iostream>
// using namespace std;
//
// int main(){
//   int n = 0;
//   char D[2] = "D";
//   char U[2] = "U";
//   char *arr;
//
//   while(n < 2 || n > 1000000){
//       cin>>n;
//   }
//
//   arr = new char [n];
//
//
//   for(int i = 0; i < n; i++){
//     while(arr[i] != D[0] && arr[i] != U[0]){
//         cin>>arr[i];
//     }
//   }
//
//   int seaLevel = 0;
//   int track = 0;
//   int valleys = 0;
//   for(int i = 0; i < n; i++){
//     if(seaLevel == 0){
//       if(track == 1){
//         valleys++;
//       }
//       track = 1;
//     }
//     if(arr[i] == D[0]){
//       seaLevel--;
//     }
//     if(arr[i] == U[0]){
//       seaLevel++;
//     }
//     if(seaLevel > 0){
//       track = 0;
//     }
//   }
//
//   if(seaLevel == 0){
//     if(track == 1){
//       valleys++;
//     }
//     track = 1;
//   }
//   return valleys;
// }
