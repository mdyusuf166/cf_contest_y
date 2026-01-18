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

        
        long long ans = last_flip + s - m;

        if (ans < 0) ans = 0;

        cout << ans << '\n';
    }
    return 0;
}
4
0
1
7
1
0
