#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    bool iswf = true; // ফলাফল নির্ধারণের ভ্যারিয়েবল
    long long diff = 0;
    
    for (int i = 0; i < n; i++) {
        // b[i] এবং a[i] এর বর্তমান পার্থক্য হিসাবের সাথে পূর্ববর্তী শিফট ভ্যালু যোগ
        long long current_diff = b[i] - a[i] - diff;
        
        // পরবর্তী পজিশনের জন্য ডিফারেন্স আপডেট
        diff = current_diff;
    }
    
    // যদি সবশেষে কোনো ডিফারেন্স অবশিষ্ট না থাকে (অর্থাৎ diff == 0)
    if (diff != 0) {
        iswf = false;
    }
    
    if (iswf) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}