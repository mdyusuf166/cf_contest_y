#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long p(long long base, long long exp) {
    long long res = 1;
    base %= MOD;

    while (exp > 0) {
        if (exp & 1)
            res = (res * base) % MOD;

        base = (base * base) % MOD;
        exp >>= 1;
    }

    return res;
}

void solve() {
    long long n, m, r, c;
    cin >> n >> m >> r >> c;

    long long total_cell =
        (n % (MOD - 1)) * (m % (MOD - 1)) % (MOD - 1);

    long long num_e =
        ((n - r + 1) % (MOD - 1)) *
        ((m - c + 1) % (MOD - 1)) % (MOD - 1);

    long long ex =
        (total_cell - num_e + (MOD - 1)) % (MOD - 1);

    cout << p(2, ex) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();
}