#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        int mn = A[0], mx = A[0];
        for (int i = 1; i < N; i++) {
            mn = min(mn, A[i]);
            mx = max(mx, A[i]);
        }

        int count = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] > mn && A[i] < mx) {
                count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}