#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int infmax = 1e18;
const int infmin = -1e18;

class mintree {
public : 
    int lx, rx;
    mintree* lc = nullptr; mintree* rc = nullptr;
    int val;

    void init (int l, int r) {
        lx = l, rx = r, val = infmax; // empty element
        if(lx == rx) return;
        lc = new mintree, rc = new mintree;
        int m = (l + r) / 2;
        lc->init(l, m); rc->init(m + 1, r);
    }

    void set (int i, int v) {
        if(lx == rx) {
            val = v; return;
        } if (i > lc->rx) rc->set(i, v);
        else lc->set(i, v);
        val = min(lc->val, rc->val);
    }

    int query (int l, int r) {
        if(rx < l || lx > r) return infmax; // empty element
        if(lx >= l && rx <= r) return val;
        return min(lc->query(l, r), rc->query(l, r));
    }
};

class maxtree {
public : 
    int lx, rx;
    maxtree* lc = nullptr; maxtree* rc = nullptr;
    int val;

    void init (int l, int r) {
        lx = l, rx = r, val = infmin; // empty element
        if(lx == rx) return;
        lc = new maxtree, rc = new maxtree;
        int m = (l + r) / 2;
        lc->init(l, m); rc->init(m + 1, r);
    }

    void set (int i, int v) {
        if(lx == rx) {
            val = v; return;
        } if (i > lc->rx) rc->set(i, v);
        else lc->set(i, v);
        val = max(lc->val, rc->val);
    }

    int query (int l, int r) {
        if(rx < l || lx > r) return infmin; // empty element
        if(lx >= l && rx <= r) return val;
        return max(lc->query(l, r), rc->query(l, r));
    }
};

const int inf = 1e18;

void solve() {
    int n, s, t;
    cin >> n >> s >> t;
    vector<int> dp(n, inf);
    
    maxtree maxt; mintree mint; mintree mindp;
    maxt.init(0, n - 1); mint.init(0, n - 1); mindp.init(0, n - 1);

    function<bool(int, int)> check = [&] (int l, int r) {
        if(l > r || r < 0 || l < 0) return false;
        return (maxt.query(l, r) - mint.query(l, r)) <= s;
    };

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        int l = -1, r = i - t + 1;
        maxt.set(i, x);
        mint.set(i, x);
        
        if(check(r, i)) {
            while(r - l > 1) {
                int mid = (l + r) / 2;
                (check(mid, i) ? r : l) = mid;
            }
            if(l == -1) dp[i] = 1;
            else dp[i] = mindp.query(l, i - t) + 1;
            if(dp[i] >= inf) dp[i] = inf;
        }
        
        mindp.set(i, dp[i]);
    }
    if(dp[n - 1] == inf) dp[n - 1] = -1;
    cout << dp[n - 1] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int the_obito = 1;
    // cin >> the_obito;
    // cout << setprecision(20) << fixed;
    for(int test_case = 1; test_case <= the_obito; test_case++) solve();    
    return 0;
}