// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int yousufTest;
//     cin >> yousufTest;

//     while (yousufTest--) {
//         string yousufVision;
//         cin >> yousufVision;

//         int mdYousuf = yousufVision.size();

//         int agiBioTech = 0;
//         for (char quantumAI : yousufVision) {
//             if (quantumAI == '1' || quantumAI == '3') {
//                 agiBioTech++;
//             }
//         }

//         int quantumTwo = 0;
//         int cyberRight = agiBioTech;
//         int bestVision = cyberRight;

//         for (char roboticsBrain : yousufVision) {
//             if (roboticsBrain == '2') {
//                 quantumTwo++;
//             }

//             if (roboticsBrain == '1' || roboticsBrain == '3') {
//                 cyberRight--;
//             }

//             bestVision = max(bestVision, quantumTwo + cyberRight);
//         }

//         cout << mdYousuf - bestVision << '\n';
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int mdy;
    cin >> mdy;

    while (mdy--) {

        string agi;
        cin >> agi;

        int qc = agi.size();

        int bt = 0;

        for (char ai : agi) {

            if (ai == '1' || ai == '3') {
                bt++;
            }
        }

        int rb = 0;

        int cs = bt;

        int bci = cs;

        for (char qm : agi) {

            if (qm == '2') {
                rb++;
            }

            if (qm == '1' || qm == '3') {
                cs--;
            }

            bci = max(bci, rb + cs);
        }

        cout << qc - bci << '\n';
    }

    return 0;
}