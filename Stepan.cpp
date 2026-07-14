#include <bits/stdc++.h>
using namespace std;
long long gcd(long long f,long long l){
  while(l){
    f %= l;
    swap(f,l);
  }
  return f;
}
  void res(){
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++){
      cin >> arr[i];
    }
    bool r = true;
    int g = gcd(x,y);
  
    for(int i = 1; i < n; i++){
      if( i % g != arr[i] % g){
        r = false;
        break;
      }
  }
  if(r){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while(t--){
    res();
  }
  return 0;
}