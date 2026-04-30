#include <bits/stdc++.h>
using namespace std;

vector<int> manacherOdd(vector<int>& a) {
    int n = a.size();
    vector<int> d(n);
    int l = 0, r = -1;

    for (int i = 0; i < n; i++) {
        int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);

        while (i - k >= 0 && i + k < n && a[i - k] == a[i + k])
            k++;

        d[i] = k;

        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }

    return d;
}

vector<int> manacherEven(vector<int>& a) {
    int n = a.size();
    vector<int> d(n);
    int l = 0, r = -1;

    for (int i = 0; i < n; i++) {
        int k = (i > r) ? 0 : min(d[l + r - i + 1], r - i + 1);

        while (i - k - 1 >= 0 && i + k < n && a[i - k - 1] == a[i + k])
            k++;

        d[i] = k;

        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }

    return d;
}

struct Query {
    int l, r;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int m = 2 * n;
        vector<int> a(m);
        vector<vector<int>> pos(n);

        for (int i = 0; i < m; i++) {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }

        vector<int> odd = manacherOdd(a);
        vector<int> even = manacherEven(a);

        auto isPalindrome = [&](int l, int r) {
            int len = r - l + 1;

            if (len % 2 == 1) {
                int mid = (l + r) / 2;
                return odd[mid] >= len / 2 + 1;
            } else {
                int mid = (l + r + 1) / 2;
                return even[mid] >= len / 2;
            }
        };

        vector<Query> queries;

        for (int x = 0; x < n; x++) {
            int l = pos[x][0];
            int r = pos[x][1];

            if (isPalindrome(l, r)) {
                queries.push_back({l, r});
            }
        }

        int ans = 1;

        int block = 450;

        sort(queries.begin(), queries.end(), [&](Query A, Query B) {
            int ba = A.l / block;
            int bb = B.l / block;

            if (ba != bb) return ba < bb;

            if (ba & 1) return A.r > B.r;
            return A.r < B.r;
        });

        vector<int> cnt(n, 0);
        set<int> missing;

        for (int i = 0; i <= n; i++)
            missing.insert(i);

        int L = 0, R = -1;

        auto add = [&](int idx) {
            int x = a[idx];

            if (cnt[x] == 0)
                missing.erase(x);

            cnt[x]++;
        };

        auto remove = [&](int idx) {
            int x = a[idx];

            cnt[x]--;

            if (cnt[x] == 0)
                missing.insert(x);
        };

        for (auto q : queries) {
            while (L > q.l) add(--L);
            while (R < q.r) add(++R);
            while (L < q.l) remove(L++);
            while (R > q.r) remove(R--);

            ans = max(ans, *missing.begin());
        }

        cout << ans << '\n';
    }

    return 0;
}