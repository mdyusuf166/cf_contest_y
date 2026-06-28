#include<bits/stdc++.h>
using namespace std;
void r(){
  long long n;
  cin>> n;
  long long tw= 0;
  for(long long b = 1; b <= n; ++b){
    long long ml = n / b;
    tw += (ml * ml);
  }
  cout<< tw <<"\n";
}
int main(){
  ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>> t;
    while(t--){
      r();
    }
    return 0;
}