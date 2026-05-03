#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string target = "hello";
    int j = 0;

    for (char c : s) {
        if (j < target.size() && c == target[j]) {
            j++;
        }
    }

    cout << (j == target.size() ? "YES" : "NO") << '\n';
    return 0;
}