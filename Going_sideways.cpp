#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long> bit;

    BIT(int n) {
        this->n = n;
        bit.assign(n + 2, 0);
    }

    void add(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    long long sum(int idx) {
        long long res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    long long rangeSum(int l, int r) {
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

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        BIT cnt(n), total(n);

        long long base = 0;

        for (int i = 0; i < n; i++) {
            int x = a[i];

            long long greaterCnt = cnt.rangeSum(x + 1, n);
            long long greaterSum = total.rangeSum(x + 1, n);

            base += greaterSum - greaterCnt * x;

            cnt.add(x, 1);
            total.add(x, x);
        }

        vector<int> leftFreq(n + 2, 0), rightFreq(n + 2, 0);

        for (int x : a) rightFreq[x]++;

        long long bestGain = 0;

        BIT leftCnt(n), rightCnt(n);

        for (int x : a) rightCnt.add(x, 1);

        for (int i = 0; i < n; i++) {
            int x = a[i];

            rightCnt.add(x, -1);

            long long leftGreaterEqual = leftCnt.rangeSum(x, n);
            long long rightLess = rightCnt.rangeSum(1, x - 1);

            long long gain = leftGreaterEqual - rightLess;

            bestGain = max(bestGain, gain);

            leftCnt.add(x, 1);
        }

        cout << base + bestGain << '\n';
    }

    return 0;
}