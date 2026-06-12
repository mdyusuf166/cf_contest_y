#include <bits/stdc++.h>
using namespace std;
void r(){
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;

  vector<int> count_ones(k,0);
  for(int i = 0; i < n; i++){
    if(s[i] == '1'){
      count_ones[i % k]++;
    }
  }

  bool p = true;
  for(int i = 0; i <k; i++){
    if(count_ones[i] % 2 != 0){
      p = false;
      break;
    }
  }

  if(p){
    cout<<"Yes\n";
  } else{
    cout<<"No\n";
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  int t;
  cin>>t;
  while(t--){
      r();
  }
  return 0;
}