#include <bits/stdc++.h>

using namespace std;

void r(){
  int n;
  cin>>  n;
  vector <int> a(n);

  for(int i = 0; i < n; i++){
    cin>>a[i];
  }
  long long t_s = 0;
  int c_r = a[0];
  for(int i = 0; i < n; i++){
    c_r = min(c_r,a[i]);
    t_s += c_r;
  }
  cout << t_s <<"\n";
}
int main (){
   ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
      r();
    }
    return 0;


}