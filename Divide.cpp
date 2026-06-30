#include <bits/stdc++.h>
using namespace std;

void r(){
    int x, y;
    cin >> x >> y;
    if(x >= y && x % y == 0){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        r();
    }
    return 0;
}