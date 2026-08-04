#include <bits/stdc++.h>
using namespace std;

void res() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int eA = 0, eB = 0;
    int oA = 0, oB = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            eA += (a[i] == '1');
            eB += (b[i] == '1');
        } else {
            oA += (a[i] == '1');
            oB += (b[i] == '1');
        }
    }

    if (eA == eB && oA == oB) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        res();
    }

    return 0;
}