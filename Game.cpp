// #include <bits/stdc++.h>
// using namespace std;

// const int INF = 1e9;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int q;
//     cin >> q;

//     int n = q + 1;
//     vector<vector<pair<int, int>>> g(n + 1);
//     vector<int> rev(2 * q), edgeTime(2 * q);

//     int id = 0;

//     for (int i = 1; i <= q; i++) {
//         int v;
//         cin >> v;

//         int u = i + 1;

//         int a = id++;
//         int b = id++;

//         rev[a] = b;
//         rev[b] = a;

//         edgeTime[a] = i;
//         edgeTime[b] = i;

//         g[v].push_back({u, b});
//         g[u].push_back({v, a});
//     }

//     vector<int> firstTime;
//     firstTime.push_back(0);
//     firstTime.push_back(1);

//     vector<int> prev(2 * q), cur(2 * q);

//     for (int i = 0; i < 2 * q; i++) {
//         prev[i] = edgeTime[i];
//     }

//     while (true) {
//         int bestAnswerTime = INF;

//         vector<array<pair<int, int>, 3>> best(n + 1);

//         for (int i = 1; i <= n; i++) {
//             best[i] = {make_pair(INF, -1), make_pair(INF, -1), make_pair(INF, -1)};
//         }

//         for (int u = 1; u <= n; u++) {
//             for (auto [v, dir] : g[u]) {
//                 int inDir = rev[dir];
//                 pair<int, int> now = {prev[inDir], inDir};

//                 if (now < best[u][0]) {
//                     best[u][2] = best[u][1];
//                     best[u][1] = best[u][0];
//                     best[u][0] = now;
//                 } else if (now < best[u][1]) {
//                     best[u][2] = best[u][1];
//                     best[u][1] = now;
//                 } else if (now < best[u][2]) {
//                     best[u][2] = now;
//                 }
//             }

//             bestAnswerTime = min(bestAnswerTime, best[u][1].first);
//         }

//         if (bestAnswerTime == INF) break;

//         firstTime.push_back(bestAnswerTime);

//         for (int u = 1; u <= n; u++) {
//             for (auto [v, dir] : g[u]) {
//                 int banned = rev[dir];

//                 int val;

//                 if (best[u][0].second == banned) {
//                     val = best[u][2].first;
//                 } else {
//                     val = best[u][1].first;
//                 }

//                 if (val == INF) {
//                     cur[dir] = INF;
//                 } else {
//                     cur[dir] = max(edgeTime[dir], val);
//                 }
//             }
//         }

//         prev.swap(cur);
//     }

//     for (int i = 1; i <= q; i++) {
//         int ans = 1;

//         for (int j = 1; j < (int)firstTime.size(); j++) {
//             if (firstTime[j] <= i) ans = j;
//         }

//         cout << ans << " ";
//     }

//     cout << '\n';

//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// const int INF = 1e9;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int q;
//     cin >> q;

//     int n = q + 1;

//     vector<vector<pair<int, int>>> g(n + 1);

//     vector<int> rev(2 * q), edgeTime(2 * q);

//     int id = 0;

//     for (int i = 1; i <= q; i++) {

//         int v;
//         cin >> v;

//         int u = i + 1;

//         int a = id++;
//         int b = id++;

//         rev[a] = b;
//         rev[b] = a;

//         edgeTime[a] = i;
//         edgeTime[b] = i;

//         g[v].push_back({u, b});
//         g[u].push_back({v, a});
//     }

//     vector<int> firstTime;

//     firstTime.push_back(0);
//     firstTime.push_back(1);

//     vector<int> prev(2 * q), cur(2 * q);

//     for (int i = 0; i < 2 * q; i++) {
//         prev[i] = edgeTime[i];
//     }

//     while (true) {

//         int bestAnswerTime = INF;

//         vector<array<pair<int, int>, 3>> best(n + 1);

//         for (int i = 1; i <= n; i++) {

//             best[i] = {
//                 make_pair(INF, -1),
//                 make_pair(INF, -1),
//                 make_pair(INF, -1)
//             };
//         }

//         for (int u = 1; u <= n; u++) {

//             for (auto it : g[u]) {

//                 int v = it.first;

//                 int dir = it.second;

//                 int inDir = rev[dir];

//                 pair<int, int> now = {prev[inDir], inDir};

//                 if (now < best[u][0]) {

//                     best[u][2] = best[u][1];

//                     best[u][1] = best[u][0];

//                     best[u][0] = now;
//                 }

//                 else if (now < best[u][1]) {

//                     best[u][2] = best[u][1];

//                     best[u][1] = now;
//                 }

//                 else if (now < best[u][2]) {

//                     best[u][2] = now;
//                 }
//             }

//             bestAnswerTime = min(bestAnswerTime, best[u][1].first);
//         }

//         if (bestAnswerTime == INF) {
//             break;
//         }

//         firstTime.push_back(bestAnswerTime);

//         for (int u = 1; u <= n; u++) {

//             for (auto it : g[u]) {

//                 int v = it.first;

//                 int dir = it.second;

//                 int banned = rev[dir];

//                 int val;

//                 if (best[u][0].second == banned) {

//                     val = best[u][2].first;
//                 }

//                 else {

//                     val = best[u][1].first;
//                 }

//                 if (val == INF) {

//                     cur[dir] = INF;
//                 }

//                 else {

//                     cur[dir] = max(edgeTime[dir], val);
//                 }
//             }
//         }

//         prev.swap(cur);
//     }

//     for (int i = 1; i <= q; i++) {

//         int ans = 1;

//         for (int j = 1; j < (int)firstTime.size(); j++) {

//             if (firstTime[j] <= i) {
//                 ans = j;
//             }
//         }

//         cout << ans << " ";
//     }

//     cout << '\n';

//     return 0;
// }









#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int mdy;
    cin >> mdy;

    int agi = mdy + 1;

    vector<vector<pair<int, int>>> qc(agi + 1);
    vector<int> rb(2 * mdy), bt(2 * mdy);

    int ai = 0;

    for (int bci = 1; bci <= mdy; bci++) {
        int cs;
        cin >> cs;

        int qct = bci + 1;

        int x = ai++;
        int y = ai++;

        rb[x] = y;
        rb[y] = x;

        bt[x] = bci;
        bt[y] = bci;

        qc[cs].push_back({qct, y});
        qc[qct].push_back({cs, x});
    }

    vector<int> vision;
    vision.push_back(0);
    vision.push_back(1);

    vector<int> qbm(2 * mdy), eth(2 * mdy);

    for (int i = 0; i < 2 * mdy; i++) {
        qbm[i] = bt[i];
    }

    while (true) {
        int best = inf;

        vector<array<pair<int, int>, 3>> cyber(agi + 1);

        for (int i = 1; i <= agi; i++) {
            cyber[i] = {
                make_pair(inf, -1),
                make_pair(inf, -1),
                make_pair(inf, -1)
            };
        }

        for (int u = 1; u <= agi; u++) {
            for (auto it : qc[u]) {
                int dir = it.second;

                int revDir = rb[dir];

                pair<int, int> now = {qbm[revDir], revDir};

                if (now < cyber[u][0]) {
                    cyber[u][2] = cyber[u][1];
                    cyber[u][1] = cyber[u][0];
                    cyber[u][0] = now;
                } 
                else if (now < cyber[u][1]) {
                    cyber[u][2] = cyber[u][1];
                    cyber[u][1] = now;
                } 
                else if (now < cyber[u][2]) {
                    cyber[u][2] = now;
                }
            }

            best = min(best, cyber[u][1].first);
        }

        if (best == inf) {
            break;
        }

        vision.push_back(best);

        for (int u = 1; u <= agi; u++) {
            for (auto it : qc[u]) {
                int dir = it.second;

                int ban = rb[dir];

                int val;

                if (cyber[u][0].second == ban) {
                    val = cyber[u][2].first;
                } 
                else {
                    val = cyber[u][1].first;
                }

                if (val == inf) {
                    eth[dir] = inf;
                } 
                else {
                    eth[dir] = max(bt[dir], val);
                }
            }
        }

        qbm.swap(eth);
    }

    for (int i = 1; i <= mdy; i++) {
        int ans = 1;

        for (int j = 1; j < (int)vision.size(); j++) {
            if (vision[j] <= i) {
                ans = j;
            }
        }

        cout << ans << " ";
    }

    cout << '\n';

    return 0;
}




