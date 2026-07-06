#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    bool alt = true;

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            alt = false;
            break;
        }
    }

    if (alt) {
        cout << n << '\n';
        return;
    }

    int zero = 0, one = 0;

    for (char c : s) {
        if (c == '0')
            zero++;
        else
            one++;
    }

    int minwf;

    if (zero == one)
        minwf = 2;
    else
        minwf = 1;

    cout << minwf << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}