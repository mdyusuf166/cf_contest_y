#include<bits/stdc++.h>
using namespace std;

void r(){
    int n, c;
    cin >> n >> c;
    vector<int> a(n), b(n);

    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    bool pwr = true;
    for(int i = 0 ; i < n; ++i){
        if(a[i] < b[i]){
            pwr = false;
            break;
        }
    }
    
    vector<int> s_a = a;
    vector<int> s_b = b;
    sort(s_a.begin(), s_a.end());
    sort(s_b.begin(), s_b.end());
    
    bool psa = true;
    long long td = 0;

    for(int i = 0; i < n; ++i){
        if(s_a[i] < s_b[i]){
            psa = false;
            break;
        }
        td += (s_a[i] - s_b[i]);
    }
    
    if(!psa){
        cout << -1 << "\n"; 
    } else {
        
        long long ans = c + td; 
        if(pwr){
            ans = min(ans, td); 
        }
        cout << ans << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        r();
    }
    return 0;
}