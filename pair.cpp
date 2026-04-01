#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        map<int, long long> freq;
        long long ans = 0;

        for (int i = 1; i <= N; i++) {
            int x;
            cin >> x;
            int key = x - i;
            ans += freq[key];
            freq[key]++;
        }

        cout << ans << '\n';
    }

    return 0;
}