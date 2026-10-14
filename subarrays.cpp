#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin>> t;
  while(t--){
    int n,k;
    cin>> n>> k;
    vector<int>pref(n +1,0);
    for(int i = 1; i <=n; i++){
      int a;

      cin>>a;
      pref[i] =(pref[i-1]+ a%k)%k;
    }
    vector<long long>count(k,0);
    long long res = 0;
    for(int j = 0; j<=n; j++){
      int i = j - k- 1;
      if(i >= 0){
        count[pref[i]]++;
      }
      res +=count[pref[j]];
  }
  cout <<res<<'\n';
}
return 0;
}