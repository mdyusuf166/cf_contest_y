


#include <bits/stdc++.h>
using namespace std;
void r(){
  string a,b;
  cin >> a >> b;
  int n = a.length();
  int m = b.length();

  vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
  dp[0][0] = 0;
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= m; ++j){
      if(dp[i][j] == -1) continue;
      int s_a = 0;
      for(int x = 1; i+x <= n; ++x){
        s_a = (s_a + (a[i+x-1]-'0'))%10;
        int s_b = 0;
        for(int y = 1; j+y <= m; ++y){
          s_b = (s_b + (b[j+y-1]-'0'))%10;
          if(s_a == s_b){
            dp[i+x][j+y] = max(dp[i+x][j+y], dp[i][j]+1);
          }
        }
      }
    }
  }
  cout << dp[n][m] << "\n";
}
int main(){
  ios:: sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--){
    r();
  }
  return 0;
}