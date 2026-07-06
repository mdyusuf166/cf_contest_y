#include <bits/stdc++.h>
using namespace std;

int len_bin(long long x) {
    return 64 - __builtin_clzll(x);
}

int get_bit(long long x, int len, int pos) {
    int shift = len - 1 - pos;
    return (x >> shift) & 1;
}

string product_string(long long x, long long y, int n) {
    int lx = len_bin(x);
    int ly = len_bin(y);

    string s;
    for (int i = 0; i < n; i++) {
        int bx = get_bit(x, lx, i % lx);
        int by = get_bit(y, ly, i % ly);
        s.push_back(char('0' + (bx & by)));
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long l, r;
        int n;
        cin >> l >> r >> n;

        vector<long long> cand;

        for (int d = 1; d <= 30; d++) {
            long long low = 1LL << (d - 1);
            long long high = (1LL << d) - 1;

            long long L = max(l, low);
            long long R = min(r, high);

            if (L > R) continue;

            cand.push_back(L);

            for (int bit = 0; bit < d - 1; bit++) {
                if (((L >> bit) & 1) == 0) {
                    long long x = ((L >> (bit + 1)) << (bit + 1)) | (1LL << bit);
                    if (x >= L && x <= R) {
                        cand.push_back(x);
                    }
                }
            }

            for (int bit = 0; bit < d - 1; bit++) {
                if (((L >> bit) & 1) == 0) {
                    long long x = L | (1LL << bit);
                    if (x >= L && x <= R) {
                        cand.push_back(x);
                        break;
                    }
                }
            }
        }

        sort(cand.begin(), cand.end());
        cand.erase(unique(cand.begin(), cand.end()), cand.end());

        string ans(n, '1');

        int sz = cand.size();

        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                string cur = product_string(cand[i], cand[j], n);
                if (cur < ans) {
                    ans = cur;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}