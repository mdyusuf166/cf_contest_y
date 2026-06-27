#include <bits/stdc++.h>
using namespace std;

void r() {
    int n;
    cin >> n;

    vector<int> a(n);

    int nzc = 0;
    int xs = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] > 0)
            nzc++;

        xs ^= a[i];
    }

    if (nzc <= 1) {
        cout << 0 << '\n';
    } else if (xs == 0) { 
       
        cout << 1 << '\n';
    } else {
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if ((xs ^ a[i]) <= a[i]) {
                ans++;
            }
        }

        cout << ans << '\n';
    }
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