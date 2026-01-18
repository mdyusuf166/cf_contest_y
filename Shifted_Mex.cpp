#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin>> t;
  while(t--){
    int n;
    cin>> n;
    vector<long long > a(n);
    for(int i = 0; i < n; i++) cin>> a[i];
    sort(a.begin(), a.end());

    long long mex = 0;
    unordered_map<long long,int >freq;
    for(long long x : a)freq[x]++;

    while(true ){
      bool found = false;
      for(auto &P :freq){
        long long val = P.first;
        if(P.second > 0){
          long long x = mex - val;
          bool ok = true ;
          for(long long i = 0; i < mex ; i++){
            if(freq[i -x ]<= 0){
              ok = false;
              break;
            }
          }
          if(ok){
            found = true;
          }
        }
      }
      if (found) mex++;
            else break;
    

        
    }
    cout<< mex<< '\n';
  }
  return 0;
}