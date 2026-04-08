// https://codeforces.com/contest/447/problem/A


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, n;
    cin >> p >> n;

    vector<bool> used(p, false);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int bucket = x % p;

        if (used[bucket]) {
            cout << i << "\n";
            return 0;
        }

        used[bucket] = true;
    }

    cout << -1 << "\n";
    return 0;
}