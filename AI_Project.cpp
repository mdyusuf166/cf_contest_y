#include<bits/stdc++.h>
using namespace std;


void r(){
  long long n,x,y,z;
  cin>>n>>x>>y>>z;
  long long  time_without_ai =(n+x+y-1)/(x+y);
  long long time_with_ai= 0;

  if(z*x >=n){
    time_with_ai = (n +x-1)/x;

  }else{
    long long remaining_line=n-(z*x);
    long long speed_with_ai = x+10*y;
    long long extra_time = (remaining_line + speed_with_ai - 1) / speed_with_ai;
    time_with_ai =z + extra_time;

  }
  cout<<min(time_without_ai,time_with_ai)<<endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    r();
  }
  return 0;
}