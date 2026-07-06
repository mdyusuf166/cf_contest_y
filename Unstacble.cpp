



#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
  vector<int>f;
  for(int i=0;i<n;){
    int j=i;
    while(j<n && a[j]==a[i]) j++;
    f.push_back(j-i);
    i=j;
  }
  sort(f.begin(),f.end());
  int m=f.size();
  long long s= 0;
  int c=0;
  int ans=0;
  for(int i=m-1;i>=0;i--){
    s+=f[i];
    c++;
    if(i>0 && f[i]==f[i-1]) continue;
    long long need=k-s;
    if(need%c==0){
      long long x=need/c;
      if(f[i]+x>=1) ans++;
    }
  }
  cout << ans << '\n';

}
}