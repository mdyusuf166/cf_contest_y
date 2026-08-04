#include <bits/stdc++.h>
using namespace std;

long long gcd(long long f,long long l){
  while(l){
    f %= l;
    swap(f,l);
  }
  return f;
}
void res(){
  
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> arr(n);

        for(int i = 0; i < n; i++){
          cin >> arr[i];
        }
        long long cs= 0;
        bool res = true;
        for(int i = 0; i < n; i++){
          cs += arr[i];
          long long need = (i+1)*(i+2)/2;
          if(cs < need){
            res = false;
            break;
          }
        }

        if(res){
          cout << "YES\n";
        }
        else{
          cout << "NO\n";
        }
        

    }

    return 0;
}



