// 


#include <bits/stdc++.h>
using namespace std;

void res() {
    int n;
    cin >> n;

    vector<int> ans;

    // 1st occurrence
    for (int i = 1; i <= n; i++) {
        ans.push_back(i);
    }

    // 2nd occurrence
    for (int i = 1; i <= n; i++) {
        ans.push_back(i);
    }

    // 3rd occurrence (shifted)
    for (int i = 2; i <= n; i++) {
        ans.push_back(i);
    }
    ans.push_back(1);

    // 4th occurrence
    for (int i = 1; i <= n; i++) {
        ans.push_back(i);
    }

    for (int x : ans) {
        cout << x << " ";
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