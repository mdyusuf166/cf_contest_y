#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        const int INF = n + 1;

        vector<int> suf(n + 1, INF);

        for (int i = n - 1; i >= 0; i--) {
            suf[i] = min(suf[i + 1], a[i]);
        }

        long long base = 0;

        for (int i = 0; i < n; i++) {
            int rightMin = suf[i + 1];

            if (a[i] > rightMin) {
                base += a[i] - rightMin;
            }
        }

        vector<long long> cnt(n + 2, 0);
        long long bestGain = 0;

        for (int i = 0; i < n; i++) {
            int x = a[i];

            long long gain = cnt[x];

            if (x > suf[i + 1]) {
                gain--;
            }

            bestGain = max(bestGain, gain);

            int rightMin = suf[i + 1];

            if (rightMin <= n && a[i] >= rightMin) {
                cnt[rightMin]++;
            }
        }

        cout << base + bestGain << '\n';
    }

    return 0;
}