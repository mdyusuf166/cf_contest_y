#include <bits/stdc++.h>
using namespace std;

void res() {
    int n;
    cin >> n;

    vector<long long> b(n);
    map<long long, long long> freq;

    for (long long &x : b) {
        cin >> x;
        freq[x]++;
    }

    if (freq.begin()->first != 0) {
        cout << -1 << '\n';
        return;
    }

    vector<long long> shadow;
    vector<long long> count;
for (auto it : freq) {
    long long val = it.first;
    long long cnt = it.second;

    shadow.push_back(val);
    count.push_back(cnt);
}

    int groups = shadow.size();

    map<long long, long long> assignValues;

    
    if (groups == 1) {
        assignValues[0] = 1;

        for (long long x : b) {
            cout << assignValues[x] << ' ';
        }

        cout << '\n';
        return;
    }

    long long prev = 0;

    for (int i = 0; i + 1 < groups; i++) {
        long long diff = shadow[i + 1] - shadow[i];

        if (diff % count[i] != 0) {
            cout << -1 << '\n';
            return;
        }

        long long currentVal = diff / count[i];

        if (currentVal <= prev) {
            cout << -1 << '\n';
            return;
        }

      
        assignValues[shadow[i]] = currentVal;
        prev = currentVal;
    }

    
    assignValues[shadow.back()] = prev + 1;

    for (long long x : b) {
        cout << assignValues[x] << ' ';
    }

    cout << '\n';
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