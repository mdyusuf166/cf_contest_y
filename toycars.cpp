// https://codeforces.com/contest/545/problem/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> goodCars;

    for (int i = 1; i <= n; i++) {
        bool good = true;

        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;

            if (x == 1 || x == 3) {
                good = false;
            }
        }

        if (good) {
            goodCars.push_back(i);
        }
    }

    cout << goodCars.size() << endl;

    for (int car : goodCars) {
        cout << car << " ";
    }
    cout << endl;

    return 0;
}