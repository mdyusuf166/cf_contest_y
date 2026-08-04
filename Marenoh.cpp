#include <bits/stdc++.h>
using namespace std;
void res(){
  int n;
  cin>>n;
  string a,b;
  cin>>a>>b;
  vector<int>eA,eB,oA,oB;
  for(int i = 0; i < n; i++){
    if(a[i]=='1'){
      if(i%2==0)eA.push_back(i);
      else oA.push_back(i);
    }
    if(b[i]=='1'){
      if(i%2==0)eB.push_back(i);
      else oB.push_back(i);
    }
  }
  if(eA.size()!=eB.size() || oA.size()!=oB.size()){
    cout<<-1<<"\n";
    return;
  }
  long long ans=0;
  for(int i = 0; i < eA.size(); i++){
    ans+=abs(eA[i]-eB[i])/2;
  }
  for(int i = 0; i < oA.size(); i++){
    ans+=abs(oA[i]-oB[i])/2;
  }
  cout<<ans<<"\n";
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