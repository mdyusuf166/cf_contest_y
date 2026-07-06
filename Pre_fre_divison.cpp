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

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<int> prel(n + 1, 0), prem(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prel[i] = prel[i - 1] + (a[i] == 1 ? 1 : -1);
            prem[i] = prem[i - 1] + (a[i] == 3 ? -1 : 1);
        }

        const int NEG = -1000000000;
        vector<int> sufmax(n + 2, NEG);

        for (int i = n - 1; i >= 1; i--) {
            sufmax[i] = max(sufmax[i + 1], prem[i]);
        }

        bool ok = false;

        for (int i = 1; i <= n - 2; i++) {
            if (prel[i] >= 0 && sufmax[i + 1] >= prem[i]) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}