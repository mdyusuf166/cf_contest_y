#include<bits/stdc++.h>
using namespace std;
long long value_of_array(const vector<int>& a){
  long long sum = 0;
  int current_max = 0;
  for(int x : a){
    current_max = max(current_max, x);
    sum += current_max;
  }
  return sum;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin>> t;
  while(t--){
    int n;
    cin>> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>> a[i];
     long long ans = value_of_array(a);

     for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
        swap(a[i], a[j]);
        ans = max(ans, value_of_array(a));
        swap(a[i], a[j]);
      }
     }
      cout<< ans<< '\n';
  }
  return 0;
}