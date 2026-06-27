#include <bits/stdc++.h>
using namespace std;

void r() {
    long long n, k;
    cin >> n >> k;

    long long t_pc = 0;
    long long c_p = 1;

    while (n > 0) {

        long long m_c = k * c_p;

        if (n >= m_c) {
            t_pc += k;
            n -= m_c;
        } else {
            long long c_b = n / c_p;
            t_pc += c_b;
            break;
        }

        c_p *= 2;
    }

    cout << t_pc << "\n";
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