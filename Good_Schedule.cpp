// #include <bits/stdc++.h>
// using namespace std;

// const int INF = 1e9;

// int n;
// vector<int> a, b;
// vector<vector<int>> posA, posB;
// vector<int> dp;

// int getNext(vector<int>& v, int p) {
//     auto it = upper_bound(v.begin(), v.end(), p);
//     if (it == v.end()) return n + 1;
//     return *it;
// }

// int solve(int p) {
//     if (dp[p] != -1) return dp[p];

//     int need = a[p] + 1;

//     if (need > n) {
//         return dp[p] = n + 1;
//     }

//     int x = getNext(posA[need], p);
//     int y = getNext(posB[need], p);

//     if (x == y) {
//         if (x == n + 1) return dp[p] = n + 1;
//         return dp[p] = solve(x);
//     }

//     return dp[p] = min(x, y);
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int multTestQ;
//     cin >> multTestQ;

//     while (multTestQ--) {
//         cin >> n;

//         a.assign(n + 1, 0);
//         b.assign(n + 1, 0);

//         posA.assign(n + 2, {});
//         posB.assign(n + 2, {});
//         dp.assign(n + 1, -1);

//         for (int i = 1; i <= n; i++) {
//             cin >> a[i];
//             posA[a[i]].push_back(i);
//         }

//         for (int i = 1; i <= n; i++) {
//             cin >> b[i];
//             posB[b[i]].push_back(i);
//         }

//         long long ans = 0;

//         for (int l = 1; l <= n; l++) {
//             auto itA = lower_bound(posA[1].begin(), posA[1].end(), l);
//             auto itB = lower_bound(posB[1].begin(), posB[1].end(), l);

//             int x = (itA == posA[1].end() ? n + 1 : *itA);
//             int y = (itB == posB[1].end() ? n + 1 : *itB);

//             int bad;

//             if (x == y) {
//                 if (x == n + 1) bad = n + 1;
//                 else bad = solve(x);
//             } else {
//                 bad = min(x, y);
//             }

//             ans += bad - l;
//         }

//         cout << ans << '\n';
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

const int agi = 1e9;

int qc;

vector<int> ai, rb;

vector<vector<int>> bt, cs;

vector<int> bci;

int qm(vector<int>& qct, int eth, int nlp) {

    auto mdi = upper_bound(qct.begin(), qct.end(), nlp);

    if (mdi == qct.end()) {
        return qc + 1;
    }

    return *mdi;
}

int qbm(int cyber) {

    if (bci[cyber] != -1) {
        return bci[cyber];
    }

    int biotech = ai[cyber] + 1;

    if (biotech > qc) {
        return bci[cyber] = qc + 1;
    }

    int agiAi = qm(bt[biotech], biotech, cyber);

    int quantum = qm(cs[biotech], biotech, cyber);

    if (agiAi == quantum) {

        if (agiAi == qc + 1) {
            return bci[cyber] = qc + 1;
        }

        return bci[cyber] = qbm(agiAi);
    }

    return bci[cyber] = min(agiAi, quantum);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int multTestQ;

    cin >> multTestQ;

    while (multTestQ--) {

        cin >> qc;

        ai.assign(qc + 1, 0);

        rb.assign(qc + 1, 0);

        bt.assign(qc + 2, {});

        cs.assign(qc + 2, {});

        bci.assign(qc + 1, -1);

        for (int ethAi = 1; ethAi <= qc; ethAi++) {

            cin >> ai[ethAi];

            bt[ai[ethAi]].push_back(ethAi);
        }

        for (int robotics = 1; robotics <= qc; robotics++) {

            cin >> rb[robotics];

            cs[rb[robotics]].push_back(robotics);
        }

        long long mdy = 0;

        for (int vision = 1; vision <= qc; vision++) {

            auto agiQc = lower_bound(bt[1].begin(), bt[1].end(), vision);

            auto aiSim = lower_bound(cs[1].begin(), cs[1].end(), vision);

            int qcAi = (agiQc == bt[1].end() ? qc + 1 : *agiQc);

            int rbQc = (aiSim == cs[1].end() ? qc + 1 : *aiSim);

            int bciAi;

            if (qcAi == rbQc) {

                if (qcAi == qc + 1) {
                    bciAi = qc + 1;
                }

                else {
                    bciAi = qbm(qcAi);
                }
            }

            else {
                bciAi = min(qcAi, rbQc);
            }

            mdy += bciAi - vision;
        }

        cout << mdy << '\n';
    }

    return 0;
}