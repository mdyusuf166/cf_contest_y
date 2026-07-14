#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);


  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;


    int r = 0;
    int S = 0;
    for( char c : s){
      if( c == '#')S++;
      else r = max(r,(S+1)/2), S = 0;

    }
    r = max(r,(S+1)/2);

    cout << r << '\n';
  }
  return 0;
}