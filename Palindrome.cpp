#include <bits/stdc++.h>
using namespace std;
bool ispal(long long n){
  if(n<0){
    return false;
  }
  string s = to_string(n);
  string rev = s;
  reverse(rev.begin(),rev.end());
  return s == rev;
}
void res(){
  long long n;
  cin>>n;
  for(long long b = 0; b <= 10000; b +=12){
    if(b>n)break;
    long long a = n - b;
    if(ispal(a)){
      cout<<a<<" "<<b<<"\n";
      return;
    }
  }
  cout<<"-1\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin>>t;
  while(t--){
   res();
  }
  return 0;
}

