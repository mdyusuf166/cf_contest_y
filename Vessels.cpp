#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    // প্রতিটি পাত্র l-কে খালি ধরে লুপ চালাব
    for (int l = 0; l < n; l++) {
        vector<long long> w(n, 0); // পানির উচ্চতা সংরক্ষণের জন্য
        w[l] = 0; // l-তম পাত্রটি খালি

        // ১. ডান দিকে যাওয়া (Clockwise)
        long long current_limit = 2e18; // অসীম উচ্চতা ধরে শুরু
        int idx = l;
        for (int step = 0; step < n - 1; step++) {
            int next_idx = (idx + 1) % n;
            // idx এবং next_idx এর মাঝের দেয়াল হলো h[idx]
            current_limit = min(current_limit, h[idx]);
            
            w[next_idx] = max(w[next_idx], current_limit);
            idx = next_idx;
        }

        // ২. বাম দিকে যাওয়া (Counter-Clockwise)
        current_limit = 2e18;
        idx = l;
        for (int step = 0; step < n - 1; step++) {
            int prev_idx = (idx - 1 + n) % n;
            // idx এবং prev_idx এর মাঝের দেয়াল হলো h[prev_idx]
            current_limit = min(current_limit, h[prev_idx]);
            
            w[prev_idx] = max(w[prev_idx], current_limit);
            idx = prev_idx;
        }

        // সব পাত্রের পানির মোট যোগফল বের করা
        long long total_water = 0;
        for (int i = 0; i < n; i++) {
            total_water += w[i];
        }

        cout << total_water << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}