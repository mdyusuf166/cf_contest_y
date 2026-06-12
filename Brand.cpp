#include <bits/stdc++.h>
using namespace std;

const int N = 500005, M = 1e9 + 7;

int sp[N];

void go() {
    for (int i = 2; i < N; i++) {
        if (!sp[i]) {
            for (int j = i; j < N; j += i)
                if (!sp[j]) sp[j] = i;
        }
    }
}

int cal(int x) {
    int r = 0;
    while (x > 1) {
        int p = sp[x];
        r++;
        while (x % p == 0) x /= p;
    }
    return r;
}

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> c(N, 0);  

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        c[v]++;
    }

    long long ans = 1;

    for (int i = 1; i < N; i++) {
        if (!c[i]) continue;

        int d = cal(i);

        long long w = 1;

        while (c[i]--) {
            w = (w * (d + 1)) % M;
        }

        ans = (ans * w) % M;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    go();

    int t;
    cin >> t;
    while (t--) solve();
}