#include <bits/stdc++.h>
using namespace std;

void res(){
  int n, m;
  cin >> n >> m;
  

  vector<long long> arr(n + 1);
  vector<long long> bef(n + 1, 0); 
  
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
    bef[i] = bef[i-1] + arr[i];
  }

  vector<int> brr(m);
  for(int i = 0; i < m; i++){
    cin >> brr[i];
  }
  
  sort(brr.rbegin(), brr.rend());
  
  long long d0 = 0, d1 = 0;
  long long ts = bef[n] - bef[brr[0]];
  d0 = ts;
  d1 = ts;

  for(int i = 0; i < m; i++){
    int c_b = brr[i];
    int n_b = (i + 1 < m) ? brr[i + 1] : 0;

    long long c_s = bef[c_b] - bef[n_b];

    long long d0_nx = max(d0 + c_s, d1 - c_s);
    long long d1_nx = max(d0 - c_s, d1 + c_s); 

    d0 = d0_nx;
    d1 = d1_nx;
  }
  
  cout << d0 << '\n';
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