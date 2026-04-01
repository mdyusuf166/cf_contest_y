#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int low = 0, high = 10000, ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (mid == 0) {
            ans = 0;
            low = 1;
            continue;
        }

        long long people = 0;

        for (int i = 0; i < N; i++) {
            people += A[i] / mid;
        }

        if (people >= M) {
            ans = mid;        
            low = mid + 1;   
        } else {
            high = mid - 1;   
        }
    }

    cout << ans << endl;
}