//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define int long long	
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

/**
 * Author: NXT
 * Date: 2016-10-08
 * License: CC0
 * Source: NXT
 * Description: Segment tree with ability to set values of large intervals [L, R), and compute max of intervals.
 * Can be changed to other things. 
 * Time: O(\log N).
 * Status: tested
 */
#pragma once

struct STLazy {
    int n;
    vector<int> tr, lz;
    STLazy(int n) : n(n), tr(4*n + 8), lz(4*n + 8) {}

    void push(int v, int lo, int hi) {
        if (lz[v] != 0) {
            tr[v] = lz[v]*(hi - lo);
            if(lo+1 != hi) {
                lz[v*2] = lz[v];
                lz[v*2+1] = lz[v]; 
            }
            lz[v] = 0;
        }
    }
    void update(int v, int lo, int hi, int l, int r, int val) {
        push(v, lo, hi);
        if (lo >= hi || lo >= r || hi <= l) return;
        if (lo >= l && hi <= r) {
            lz[v] = val; // put lazy tag here
            push(v, lo, hi);
            return;
        }

        int mid = (lo + hi) / 2;
        update(v*2, lo, mid, l, r, val);
        update(v*2 + 1, mid, hi, l, r, val);

        tr[v] = tr[2*v] + tr[2*v+1];
    }
    int query(int v, int lo, int hi, int l, int r) {
        push(v, lo, hi);
        if (lo >= hi || lo >= r || hi <= l) return 0;
        if (lo >= l && hi <= r) return tr[v];

        int mid = (lo + hi)/2;
        int p1 = query(v*2, lo, mid, l, r);
        int p2 = query(v*2 + 1, mid, hi, l, r);
        
        return p1 + p2;
    }

    void update(int l, int r, int val) {
        update(1, 0, n, l, r, val);
    }
    int query(int l, int r) {
        return query(1, 0, n, l, r);
    }
};


int a[N];
vector<pii> ask[N];

void solve() {
    int n, q; cin >> n >> q;
    STLazy ST(n + 3);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    for (int i = 0 ; i < q ; i++) {
        int l , r; cin >> l >> r;
        ask[l].push_back({r , i});
    }
    vector<int> sum(n + 1);
    vector<int> f(n + 1);
    vector<int> ans(q);
    for (int i = 1 ; i <= n ;i ++) sum[i] = sum[i - 1] + a[i];
    stack<int> s; 
    s.push(n + 1); 
    a[n + 1] = inf;
    for (int i = n ; i >= 1 ; i--) {
        while (s.size() && a[i] >= a[s.top()]) {
            s.pop(); 
        }
        int j = s.top(); 
        ST.update(i , j , a[i]);
        for (auto [r , id] : ask[i]) {
            ans[id] = ST.query(i , r + 1) - (sum[r] - sum[i - 1]);
        }
        s.push(i);
    }
    for (int i = 0 ; i < q ; i++) {
        cout << ans[i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test = 1; 
    //cin >> test; 
    while (test--) {
       solve();
    }
}