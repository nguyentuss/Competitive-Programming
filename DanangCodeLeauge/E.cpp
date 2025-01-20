#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = (int) 1e5 + 5;

struct Node {
    int val;
    Node *l, *r;

    Node(int v) {
        val = v;
        l = r = NULL;
    }

    void Add(int v) {
        Node *p = this;
        Node *q = NULL;
        while (p != NULL) {
            q = p;
            if (p->val < v) p = p->r;
            else p = p->l;
        }

        if (q == NULL) p = new Node(v);
        else {
            if (q->val < v) q->r = new Node(v);
            else q->l = new Node(v);
        }
    }

    ii Path(Node *q, int v) {
        Node *p = q;
        int mx = -inf;
        int mn = inf;

        while (p != NULL && p->val != v) {
            mx = max(mx, p->val);
            mn = min(mn, p->val);
            if (p->val > v) p = p->l;
            else p = p->r;
        }

        return {max(mx, v), min(mn, v)};
    }

    ii findRes(int x, int y) {
        Node *p = this;

        while (p != NULL && (x < p->val && y < p->val) || (x > p->val && y > p->val)) {
            if (x < p->val && y < p->val) p = p->l;
            else {
                if (x > p->val && y > p->val) {
                    p = p->r;
                }
            }
        }

        ii path1 = Path(p, x);
        ii path2 = Path(p, y);

        return {max(path1.fi, path2.fi), min(path1.se, path2.se)};
    }
};

void solve() {
    int n; cin >> n;
    vector<int> c(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        cin >> c[i];
    }
    Node *root = new Node(c[1]);
    for (int i = 2; i <= n; ++i) 
        root->Add(c[i]);

    int a, b;
    cin >> a >> b;
    ii res = root->findRes(a, b);
    cout << res.second << " " << res.first;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}