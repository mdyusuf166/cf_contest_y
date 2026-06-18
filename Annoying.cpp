#include <bits/stdc++.h>
using namespace std;

void r() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> p(n);
    vector<bool> used(n, false);

    for (int j = 0; j < n; j++) {
        int cho_id = -1;

        for (int i = 0; i < n; i++) {
            if (!used[i] && a[i] <= b[j]) {
                cho_id = i;
                break;
            }
        }

        if (cho_id == -1) {
            cout << -1 << "\n";
            return;
        }

        used[cho_id] = true;
        p[j] = cho_id;
    }

    long long swaps = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i] > p[j]) {
                swaps++;
            }
        }
    }

    cout << swaps << "\n";
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