#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long s, k, m;
        cin >> s >> k >> m;

      
        long long last_flip = (m / k) * k;

        
        long long used_time = m - last_flip;

        long long ans = s - used_time;
        if (ans < 0) ans = 0;

        cout << ans << '\n';
    }
    return 0;
}
