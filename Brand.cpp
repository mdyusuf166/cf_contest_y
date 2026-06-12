#include <bits/stdc++.h>
using namespace std;

void r() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int ans = 0;

    vector<vector<short>> dp(n + 1, vector<short>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {

            if (abs(a[i] - a[j]) == 1) {
                dp[i][j] = dp[i + 1][j + 1] + 1;

                int len = min((int)dp[i][j], j - i);

                ans = max(ans, len);
            }
            else if (a[i] == a[j]) {
                dp[i][j] = 0;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        r();
    }

    return 0;
}