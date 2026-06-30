#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int timer;
vector<vector<int>> adj;
vector<int> tin, tout, depth;
vector<vector<int>> level_nodes; // প্রতিটি লেভেলের নোডগুলোর tin ধরে রাখার জন্য

void dfs(int u, int d) {
    tin[u] = ++timer;
    depth[u] = d;
    
    // লেভেলের সাইজ ছোট হলে বড় করে নেওয়া
    if (level_nodes.size() <= d) {
        level_nodes.resize(d + 1);
    }
    level_nodes[d].push_back(tin[u]);

    for (int v : adj[u]) {
        dfs(v, d + 1);
    }
    tout[u] = timer;
}

void solve() {
    int n;
    cin >> n;

    adj.assign(n + 1, vector<int>());
    tin.resize(n + 1);
    tout.resize(n + 1);
    depth.resize(n + 1);
    level_nodes.clear();
    timer = 0;

    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    // রুট ১ থেকে DFS শুরু
    dfs(1, 0);

    long long total_unique_guilds = 0;
    int max_depth = level_nodes.size() - 1;

    // প্রতিটি লেভেলের জন্য আলাদাভাবে ইউনিক গিল্ড হিসাব করব
    for (int d = 0; d <= max_depth; ++d) {
        if (level_nodes[d].empty()) continue;

        vector<pair<int, int>> segments;

        // প্রতিটি নোড v এর জন্য চেক করব সে এই লেভেল d তে কী রেঞ্জ কভার করে
        // তবে শুধু সেই নোডগুলোই প্রসেস করব যাদের depth <= d
        for (int v = 1; v <= n; ++v) {
            if (depth[v] > d) continue;

            // v এর সাবট্রি রেঞ্জ হলো [tin[v], tout[v]]
            // level_nodes[d] এর মধ্যে এই রেঞ্জের নোডগুলো খুঁজে বের করব
            auto it1 = lower_bound(level_nodes[d].begin(), level_nodes[d].end(), tin[v]);
            auto it2 = upper_bound(level_nodes[d].begin(), level_nodes[d].end(), tout[v]);

            if (it1 != it2) {
                int l = distance(level_nodes[d].begin(), it1);
                int r = distance(level_nodes[d].begin(), it2) - 1;
                segments.push_back({l, r});
            }
        }

        // রেঞ্জগুলোকে Sort এবং Unique করে ইউনিক গিল্ডের সংখ্যা বের করা
        sort(segments.begin(), segments.end());
        segments.erase(unique(segments.begin(), segments.end()), segments.end());

        total_unique_guilds += segments.size();
    }

    cout << total_unique_guilds << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}