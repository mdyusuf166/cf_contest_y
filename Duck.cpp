#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    long long total_beautiful = 0;
    
    // dp[i][j] নির্দেশ করে বর্তমান ইনডেক্স পর্যন্ত কতগুলো সাবস্ট্রিং আছে 
    // যাদের মডুলো ৩ এর সাম হচ্ছে 'i' এবং তারা শেষ হয়েছে 'j' ক্যারেক্টার দিয়ে (0 অথবা 1)
    // যেহেতু স্মৃতি বা মেমোরি বাঁচাতে হবে, আমরা শুধু আগের স্টেটের ডাটা (O(1) space) রাখবো।
    vector<vector<long long>> dp(3, vector<long long>(2, 0));

    for (int i = 0; i < n; i++) {
        int bit = s[i] - '0';
        int val = (bit == 0) ? 1 : 2; // '0' -> 1, '1' -> 2

        vector<vector<long long>> next_dp(3, vector<long long>(2, 0));

        // ১ দৈর্ঘ্যের নতুন সাবস্ট্রিং যা এই ইনডেক্স থেকে শুরু হচ্ছে
        next_dp[val][bit] = 1;

        // আগের স্টেটগুলোর সাথে বর্তমান ক্যারেক্টার যুক্ত করা
        for (int sum = 0; sum < 3; sum++) {
            for (int last_bit = 0; last_bit < 2; last_bit++) {
                if (dp[sum][last_bit] == 0) continue;

                int next_sum = (sum + val) % 3;

                // যদি আগের শেষ বিট এবং বর্তমান বিট সমান হয়, তবে তারা মার্জ হতে পারবে
                if (last_bit == bit) {
                    // মার্জ হয়ে বিপরীত বিট তৈরি করবে
                    next_dp[next_sum][1 - bit] += dp[sum][last_bit];
                } else {
                    // যদি সমান না হয়, তবে তারা মার্জ হতে পারবে না, শুধু পাশে বসে থাকবে
                    // তবে যদি যোগফল ০ না হয়, তারা ভবিষ্যতে অন্য কারো সাথে মার্জ হতে পারে
                    next_dp[next_sum][bit] += dp[sum][last_bit];
                }
            }
        }

        // বর্তমান ইনডেক্সে শেষ হওয়া বিউটিফুল সাবস্ট্রিংগুলোর যোগফল (যাদের মোট সাম % 3 != 0)
        total_beautiful += next_dp[1][0] + next_dp[1][1] + next_dp[2][0] + next_dp[2][1];

        dp = move(next_dp);
    }

    cout << total_beautiful << "\n";
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