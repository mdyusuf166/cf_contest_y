#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> bit;

    BIT(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    int sum(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    int rangeSum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<long long> pref(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1)
                pref[i] = pref[i - 1] + a[i];
            else
                pref[i] = pref[i - 1] - a[i];
        }

        vector<long long> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        auto getId = [&](long long x) {
            return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
        };

        BIT even(vals.size()), odd(vals.size());

        long long ans = 0;

        even.add(getId(pref[0]), 1);

        for (int i = 1; i <= n; i++) {
            int id = getId(pref[i]);

            if (i % 2 == 1) {
                ans += even.sum(id - 1);
            } else {
                ans += odd.rangeSum(id + 1, vals.size());
            }

            if (i % 2 == 0)
                even.add(id, 1);
            else
                odd.add(id, 1);
        }

        cout << ans << '\n';
    }

    return 0;
}