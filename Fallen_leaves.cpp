#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> g(n + 1);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int root = 1;
        for (int i = 1; i <= n; i++) {
            if ((int)g[i].size() > 1) {
                root = i;
                break;
            }
        }

        vector<int> parent(n + 1, 0), order;
        order.push_back(root);

        for (int i = 0; i < (int)order.size(); i++) {
            int u = order[i];
            for (int v : g[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                order.push_back(v);
            }
        }

        vector<int> leafCnt(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];

            if ((int)g[u].size() == 1) {
                leafCnt[u] = 1;
            }

            for (int v : g[u]) {
                if (parent[v] == u) {
                    leafCnt[u] += leafCnt[v];
                }
            }
        }

        int totalLeaves = leafCnt[root];
        int base = 0;

        for (int u = 1; u <= n; u++) {
            if (u == root) continue;
            if (leafCnt[u] % 2 == 1) base++;
        }

        int ans = base;

        if (totalLeaves % 2 == 1) {
            int bestDelta = 1e9;

            for (int leaf = 1; leaf <= n; leaf++) {
                if ((int)g[leaf].size() != 1) continue;

                int delta = 0;
                int u = leaf;

                while (u != root) {
                    if (leafCnt[u] % 2 == 1) delta--;
                    else delta++;

                    u = parent[u];
                }

                bestDelta = min(bestDelta, delta);
            }

            ans = base + bestDelta;
        }

        cout << ans << '\n';
    }

    return 0;
}