#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;

        long long y = (n / 3) * min(3 * a, b);
        long long r = y + min((n % 3) * a, b);

        cout << r << '\n';
    }

    return 0;
}