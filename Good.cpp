#include<bits/stdc++.h>

using namespace std;


bool isG(long long n) {
    int mask = 0;
    while (n > 0) {
        mask |= (1 << (n % 10));
        n /= 10;
    }
  
    return __builtin_popcount(mask) <= 2;
}

void r() {
    long long x;
    cin >> x;
    
   
    for (long long y = 2; y <= 1000000000; ++y) {
        if (isG(y) && isG(x * y)) {
            cout << y << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        r();
    }
    return 0;
}