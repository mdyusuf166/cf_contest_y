#include <bits/stdc++.h>
using namespace std;

void res() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int g = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1])
            g++;
    }

    int mn = 0;

    for (int i = 1; i < n - 1; i++) {
        int old_t = (s[i - 1] != s[i]) + (s[i] != s[i + 1]);
        int new_t = (s[i - 1] != s[i + 1]);
        int re = new_t - old_t;

        mn = min(mn, re);
    }

    cout << g + mn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        res();
    }

    return 0;
}