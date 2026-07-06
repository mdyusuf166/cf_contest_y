
#include <bits/stdc++.h>
using namespace std;

void r() {
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();
    const int NEG = -1000000000;

    vector<int> pa(n + 1, 0), pb(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        pa[i] = (pa[i - 1] + a[i - 1] - '0') % 10;
    }

    for (int i = 1; i <= m; i++) {
        pb[i] = (pb[i - 1] + b[i - 1] - '0') % 10;
    }

    vector<array<int, 10>> be(m + 1);

    for (int j = 0; j <= m; j++) {
        for (int r = 0; r < 10; r++) be[j][r] = NEG;
        be[j][0] = 0;
    }

    vector<int> dp(m + 1, NEG);

    for (int i = 1; i <= n; i++) {
        fill(dp.begin(), dp.end(), NEG);

        for (int j = 1; j <= m; j++) {
            int need = (pa[i] - pb[j] + 10) % 10;

            if (be[j - 1][need] != NEG) {
                dp[j] = be[j - 1][need] + 1;
            }
        }

        array<int, 10> c;
        for (int r = 0; r < 10; r++) c[r] = NEG;

        for (int j = 1; j <= m; j++) {
            if (dp[j] != NEG) {
                int val = (pa[i] - pb[j] + 10) % 10;
                c[val] = max(c[val], dp[j]);
            }

            for (int r = 0; r < 10; r++) {
                be[j][r] = max(be[j][r], c[r]);
            }
        }
    }

    cout << (dp[m] < 0 ? -1 : dp[m]) << '\n';
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