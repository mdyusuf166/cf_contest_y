#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--){
    int k;
    cin >> k;
    int tw = 0;
    
      bool ok = false;
    for(int i = 0; i < k; i++){
      long long c;
      cin >> c;
      if(c >= 3) ok = true;
      if(c >= 2) tw++;
    }
    if(tw >= 2 ) ok = true;
    cout << (ok ? "YES" : "NO") << "\n";
  }
  return 0;
}