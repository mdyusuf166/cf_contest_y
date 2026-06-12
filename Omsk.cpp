#include <bits/stdc++.h>
using namespace std;

void r() {
    long long a, b, x;
    cin >> a >> b >> x;

    vector<pair<long long, int>> pa, pb;

    long long ca = a;
    int sa = 0;

    pa.push_back({ca, sa});

    while (ca > 0) {
        ca /= x;
        sa++;
        pa.push_back({ca, sa});
    }

    long long cb = b;
    int sb = 0;

    pb.push_back({cb, sb});

    while (cb > 0) {
        cb /= x;
        sb++;
        pb.push_back({cb, sb});
    }

    long long ans = abs(a - b);

    for (auto &i : pa) {
        for (auto &j : pb) {
            long long va = i.first;
            long long vb = j.first;

            int oa = i.second;
            int ob = j.second;

            ans = min(ans, (long long)oa + ob + abs(va - vb));
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