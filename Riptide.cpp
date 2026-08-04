#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int ct = 0;

        while (true) {

            if (a == b || b == c || a == c)
                break;

            if (a > b && a > c) {

                if (b < c) {
                    a--;
                    b++;
                } else {
                    a--;
                    c++;
                }

            }
            else if (b > a && b > c) {

                if (a < c) {
                    b--;
                    a++;
                } else {
                    b--;
                    c++;
                }

            }
            else {

                if (a < b) {
                    c--;
                    a++;
                } else {
                    c--;
                    b++;
                }
            }

            ct++;
        }

        cout << ct << '\n';
    }

    return 0;
}