#include <bits/stdc++.h>
using namespace std;

struct Point {
    int p, c;
};

struct Node {
    int p, c;
    int mnP, mxP, mnC, mxC;
    int left, right;
};

vector<Point> points;
vector<Node> tree;

int build(int l, int r, int depth) {
    if (l >= r) return -1;

    int mid = (l + r) / 2;
    int axis = depth % 2;

    nth_element(points.begin() + l, points.begin() + mid, points.begin() + r,
        [axis](const Point& a, const Point& b) {
            if (axis == 0) return a.p < b.p;
            return a.c < b.c;
        }
    );

    int id = tree.size();

    Node node;
    node.p = points[mid].p;
    node.c = points[mid].c;
    node.mnP = node.mxP = points[mid].p;
    node.mnC = node.mxC = points[mid].c;
    node.left = node.right = -1;

    tree.push_back(node);

    int leftChild = build(l, mid, depth + 1);
    int rightChild = build(mid + 1, r, depth + 1);

    tree[id].left = leftChild;
    tree[id].right = rightChild;

    if (leftChild != -1) {
        tree[id].mnP = min(tree[id].mnP, tree[leftChild].mnP);
        tree[id].mxP = max(tree[id].mxP, tree[leftChild].mxP);
        tree[id].mnC = min(tree[id].mnC, tree[leftChild].mnC);
        tree[id].mxC = max(tree[id].mxC, tree[leftChild].mxC);
    }

    if (rightChild != -1) {
        tree[id].mnP = min(tree[id].mnP, tree[rightChild].mnP);
        tree[id].mxP = max(tree[id].mxP, tree[rightChild].mxP);
        tree[id].mnC = min(tree[id].mnC, tree[rightChild].mnC);
        tree[id].mxC = max(tree[id].mxC, tree[rightChild].mxC);
    }

    return id;
}

long long value(int x, int t, int d) {
    if (x < t) return 0;
    if (x < t + d) return x;
    return t + d;
}

long long boxValue(int l, int r, int t, int d) {
    if (l < t) return 0;
    if (l < t + d) return l;
    return t + d;
}

long long nodeLimit(int id, int tp, int tc, int d) {
    return boxValue(tree[id].mnP, tree[id].mxP, tp, d) +
           boxValue(tree[id].mnC, tree[id].mxC, tc, d);
}

void query(int id, int tp, int tc, int d, long long& ans) {
    if (id == -1) return;

    long long cur = value(tree[id].p, tp, d) + value(tree[id].c, tc, d);
    ans = min(ans, cur);

    int l = tree[id].left;
    int r = tree[id].right;

    long long leftLimit = (l == -1 ? LLONG_MAX : nodeLimit(l, tp, tc, d));
    long long rightLimit = (r == -1 ? LLONG_MAX : nodeLimit(r, tp, tc, d));

    if (leftLimit < rightLimit) {
        if (leftLimit < ans) query(l, tp, tc, d, ans);
        if (rightLimit < ans) query(r, tp, tc, d, ans);
    } else {
        if (rightLimit < ans) query(r, tp, tc, d, ans);
        if (leftLimit < ans) query(l, tp, tc, d, ans);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n), c(n);

    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    points.resize(n);

    for (int i = 0; i < n; i++) {
        points[i] = {p[i], c[i]};
    }

    tree.reserve(n);
    int root = build(0, n, 0);

    int m;
    cin >> m;

    vector<int> tp(m), tc(m), d(m);

    for (int i = 0; i < m; i++) cin >> tp[i];
    for (int i = 0; i < m; i++) cin >> tc[i];
    for (int i = 0; i < m; i++) cin >> d[i];

    for (int i = 0; i < m; i++) {
        long long ans = LLONG_MAX;
        query(root, tp[i], tc[i], d[i], ans);
        cout << ans << " ";
    }

    cout << '\n';

    return 0;
}