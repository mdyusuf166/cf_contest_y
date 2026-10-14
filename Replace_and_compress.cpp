#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >>t;
  while(t--){
    string s;
    cin>> s;
    int n = s.size();
    int res = 1;

    bool trip = false;
    bool iso = false;
    for(int i = 1; i< n-1; i++){
      if(s[i] == s[i-1] && s[i] == s[i+1]){
        trip = true;
      }
      if(s[i] != s[i-1] && s[i] != s[i+1]){
        iso = true;
      }
    }
    if(trip)res++;
    if(iso)res++;
    cout<< res << "\n";
  }
  return 0;
}