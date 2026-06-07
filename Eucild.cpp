#include <bits/stdc++.h>
using namespace std;
void r(){
  int n;
  cin>>n;
  vector<long long > arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  sort(arr.rbegin(),arr.rend());

  bool correct = true;
  for(int i = 0; i < n -2; i++){
    if(arr[i + 2] != arr[i] % arr[i + 1]){
      correct = false;
      break;
    }
  }
 if(correct){

  cout<<arr[0]<<" " <<arr[1]<<"\n";
 }else{
  cout<<"-1\n";
 }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t ;
  cin >>t;
  while(t--){
    r();
  }
  return 0;
}