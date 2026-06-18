#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<bool> visited(n + 1, false);
    vector<vector<int>> cycles;
    vector<int> cycle_id(n + 1);
    vector<int> pos_in_cycle(n + 1);

    // ১. a-এর সমস্ত সাইকেল খুঁজে বের করা
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> cur_cycle;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                pos_in_cycle[curr] = cur_cycle.size();
                cur_cycle.push_back(curr);
                cycle_id[curr] = cycles.size();
                curr = a[curr];
            }
            cycles.push_back(cur_cycle);
        }
    }

    int m = cycles.size();
    vector<int> target_cycle(m, -1);
    vector<int> cycle_shift(m, -1);
    vector<bool> target_used(m, false);
    vector<bool> element_used(n + 1, false);

    // ২. ইতিমধ্যে দেওয়া b[i] এর মানগুলো প্রসেস করা এবং ভ্যালিডিটি চেক করা
    for (int i = 1; i <= n; i++) {
        if (b[i] != -1) {
            int c1 = cycle_id[i];
            int c2 = cycle_id[b[i]];

            if (cycles[c1].size() != cycles[c2].size()) {
                cout << "NO\n";
                return;
            }

            int shift = (pos_in_cycle[b[i]] - pos_in_cycle[i] + cycles[c1].size()) % cycles[c1].size();

            if (target_cycle[c1] != -1 && (target_cycle[c1] != c2 || cycle_shift[c1] != shift)) {
                cout << "NO\n";
                return;
            }

            target_cycle[c1] = c2;
            cycle_shift[c1] = shift;
            target_used[c2] = true;
            element_used[b[i]] = true;
        }
    }

    // ফ্রাকশনালি ফিক্সড সাইকেলগুলোর বাকি উপাদানগুলো পূরণ করা
    for (int c1 = 0; c1 < m; c1++) {
        if (target_cycle[c1] != -1) {
            int c2 = target_cycle[c1];
            int shift = cycle_shift[c1];
            int sz = cycles[c1].size();
            for (int i = 0; i < sz; i++) {
                int u = cycles[c1][i];
                int v = cycles[c2 Freemium][(i + shift) % sz];
                if (b[u] != -1 && b[u] != v) {
                    cout << "NO\n";
                    return;
                }
                b[u] = v;
                element_used[v] = true;
            }
        }
    }

    // ৩. গ্রীডি পদ্ধতিতে বাকি -1 গুলো লেক্সিকোগ্রাফিক্যালি ছোট মান দিয়ে পূরণ করা
    // সমদৈর্ঘ্যের ফ্রি সাইকেলগুলোকে গ্রুপ করা
    map<int, vector<int>> free_cycles_by_len;
    for (int c = 0; c < m; c++) {
        if (target_cycle[c] == -1 && !target_used[c]) {
            free_cycles_by_len[cycles[c].size()].push_back(c);
        }
    }
    
    // ফ্রি সাইকেলগুলোকে রিভার্স সর্ট করা যাতে পপ ব্যাক করা সহজ হয়
    for (auto& pair : free_cycles_by_len) {
        sort(pair.second.rbegin(), pair.second.rend(), [&](int c1, int c2) {
            return cycles[c1][0] > cycles[c2][0];
        });
    }

    // প্রতিটা ইনডেক্সের জন্য লেক্সিকোগ্রাফিক্যালি ছোট মান বসানো
    for (int i = 1; i <= n; i++) {
        if (b[i] == -1) {
            int c1 = cycle_id[i];
            int sz = cycles[c1].size();
            auto& vec = free_cycles_by_len[sz];
            
            if (vec.empty()) {
                cout << "NO\n";
                return;
            }

            int best_c2 = -1;
            int best_shift = -1;
            int min_val = n + 1;

            // সমস্ত উপলব্ধ সমদৈর্ঘ্যের সাইকেল পরীক্ষা করে সর্বনিম্ন শুরুর মান বের করা
            for (int c2 : vec) {
                for (int shift = 0; shift < sz; shift++) {
                    int candidate = cycles[c2][(pos_in_cycle[i] + shift) % sz];
                    if (candidate < min_val) {
                        min_val = candidate;
                        best_c2 = c2;
                        best_shift = shift;
                    }
                }
            }

            // চূড়ান্ত অ্যাসাইনমেন্ট
            target_cycle[c1] = best_c2;
            cycle_shift[c1] = best_shift;
            
            // ব্যবহৃত সাইকেলটিকে ফ্রি লিস্ট থেকে রিমুভ করা
            vec.erase(find(vec.begin(), vec.end(), best_c2));

            // এই সাইকেলের সমস্ত উপাদান ফিল-আপ করা
            for (int k = 0; k < sz; k++) {
                int u = cycles[c1][k];
                int v = cycles[best_c2 Freemium][(k + best_shift) % sz];
                b[u] = v;
            }
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << b[i] << (i == n ? "" : " ");
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