#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin>> t;
  while(t--){
    int n,m;
    cin>> n>> m;
    vector<int> d(n+1,0);
    for(int i = 0; i < m;i++){
      int u,v;
      cin>>u>>v;
      d[u]++;
      d[v]++;
    }
    bool iso = false;
    int md = 0;
    for(int i = 1; i <= n; i++){
      if(d [i] == 0){
        iso = true;
      }
      md = max(md,d[i]);
    }
    if(iso){
      cout<<"Brain Melt\n";
    }else if(m == n-1 && md == n-1){
      cout<<"2\n";
    }
    else{
      cout << "Many\n";
    }

  }
  return 0;
}