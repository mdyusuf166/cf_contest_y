// #include <bits/stdc++.h>
// using namespace std;

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     map<int, int> first, last;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//         if (first.find(a[i]) == first.end()) {
//             first[a[i]] = i;
//         }
//         last[a[i]] = i;
//     }

//     auto check = [&](const vector<int>& v) {
//         map<int, int> f, l;
//         for (int i = 0; i < n; i++) {
//             if (f.find(v[i]) == f.end()) f[v[i]] = i;
//             l[v[i]] = i;
//         }
//         for (auto const& [val, first_idx] : f) {
//             int last_idx = l[val];
//             if (last_idx - first_idx + 1 != (int)count(v.begin() + first_idx, v.begin() + last_idx + 1, val)) {
//                 return false;
//             }
//         }
//         return true;
//     };

//     if (check(a)) {
//         cout << "YES\n";
//         return;
//     }

//     int left = 0;
//     while (left < n && a[left] == a[first[a[left]]] && last[a[left]] <= left) {
//         left++;
//     }
//     if (left >= n) {
//         cout << "YES\n";
//         return;
//     }

//     int type_left = a[left];
//     int r1 = last[type_left];
    
//     int right = n - 1;
//     while (right >= 0 && a[right] == a[last[a[right]]] && first[a[right]] >= right) {
//         right--;
//     }
//     int type_right = a[right];
//     int l2 = first[type_right];

//     vector<pair<int, int>> swaps = {
//         {left, r1},
//         {l2, right},
//         {left, l2},
//         {left, right},
//         {r1, l2},
//         {r1, right}
//     };

//     for (auto& p : swaps) {
//         int i = p.first;
//         int j = p.second;
//         if (i >= 0 && i < n && j >= 0 && j < n && i != j) {
//             swap(a[i], a[j]);
//             if (check(a)) {
//                 cout << "YES\n";
//                 return;
//             }
//             swap(a[i], a[j]);
//         }
//     }

//     cout << "NO\n";
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int tstCNum;
//     cin >> tstCNum;
//     while (tstCNum--) {
//         solve();
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> first, last;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (first.find(a[i]) == first.end()) {
            first[a[i]] = i;
        }
        last[a[i]] = i;
    }

    auto check = [&](const vector<int>& v) {
        map<int, int> f, l;
        for (int i = 0; i < n; i++) {
            if (f.find(v[i]) == f.end()) f[v[i]] = i;
            l[v[i]] = i;
        }
        for (auto const& pair : f) {
            int val = pair.first;
            int first_idx = pair.second;
            int last_idx = l[val];
            if (last_idx - first_idx + 1 != (int)count(v.begin() + first_idx, v.begin() + last_idx + 1, val)) {
                return false;
            }
        }
        return true;
    };

    if (check(a)) {
        cout << "YES\n";
        return;
    }

    int left = 0;
    while (left < n && a[left] == a[first[a[left]]] && last[a[left]] <= left) {
        left++;
    }
    if (left >= n) {
        cout << "YES\n";
        return;
    }

    int type_left = a[left];
    int r1 = last[type_left];
    
    int right = n - 1;
    while (right >= 0 && a[right] == a[last[a[right]]] && first[a[right]] >= right) {
        right--;
    }
    int type_right = a[right];
    int l2 = first[type_right];

    vector<pair<int, int>> swaps = {
        {left, r1},
        {l2, right},
        {left, l2},
        {left, right},
        {r1, l2},
        {r1, right}
    };

    for (auto& p : swaps) {
        int i = p.first;
        int j = p.second;
        if (i >= 0 && i < n && j >= 0 && j < n && i != j) {
            swap(a[i], a[j]);
            if (check(a)) {
                cout << "YES\n";
                return;
            }
            swap(a[i], a[j]);
        }
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tstCNum;
    cin >> tstCNum;
    while (tstCNum--) {
        solve();
    }
    return 0;
}