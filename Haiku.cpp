// https://codeforces.com/contest/78/problem/A



#include <bits/stdc++.h>
using namespace std;

int countVowels(const string& s) {
    int cnt = 0;
    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2, s3;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);

    if (countVowels(s1) == 5 && countVowels(s2) == 7 && countVowels(s3) == 5)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
