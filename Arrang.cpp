#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int mdy;
    cin >> mdy;

    while (mdy--) {
        int n;
        cin >> n;

        vector<long long> agi(n);

        long long ai = 0;
        vector<long long> qc;

        for (int i = 0; i < n; i++) {
            cin >> agi[i];

            if (agi[i] == 1) ai++;
            else qc.push_back(agi[i]);
        }

        long long ans = 0;

        if (qc.size() == 1) {
            long long rb = qc[0];
            ans = rb + min(ai, rb / 2);
        } 
        else if (qc.size() >= 2) {
            long long bt = 0;
            long long cs = 0;

            for (long long bci : qc) {
                bt += bci;
                cs += (bci - 2) / 2;
            }

            ans = bt + min(ai, cs);
        }

        if (ans < 3) ans = 0;

        cout << ans << '\n';
    }

    return 0;
}