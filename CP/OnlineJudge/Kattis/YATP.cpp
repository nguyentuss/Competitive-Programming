//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

/**
 * Author: Simon Lindholm
 * Date: 2017-04-20
 * License: CC0
 * Source: own work
 * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
 *  Useful for dynamic programming (``convex hull trick'').
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

/**
 * Author: Tus
 * Date: 2024-08-03
 * License: CC0
 * Source: Folklore
 * Description: 
 *  * Time: O(\log N)
 * Status: Tested on https://codeforces.com/contest/321/problem/C
 */

const int N = 2e5 + 7;

vector<pii> adj[N];
int level[N] , f[N];
bool vis[N] , check[N];
int a[N];
int ans[N];
 
void DFS(int u , int father) {
    f[u] = 1;
    for (auto [v , w] : adj[u]) {
        if (v != father && !check[v]) {
            DFS(v , u);
            f[u] += f[v];
        }
    }
}
 
int find_centroid(int u , int father , int root) {
    for (auto [v , w] : adj[u]) {
        if (!check[v] && v != father && 2*f[v] >= f[root]) {
            return find_centroid(v , u , root);
        }
    }
    return u;
}

void centroid(int u , int father) {
    DFS(u , u); 
    u = find_centroid(u , u , u); 
    check[u] = 1;
    //cerr << u << '\n';
    LineContainer CHT;
    // CHT.add(0 , 0);
    CHT.add(-a[u] , 0);
    auto calc = [&](int u , int father , int stat , int d , int root , auto &&calc) -> void {
        if (!stat) {
            CHT.add(-a[u] , -d);
            //cerr << u << " " << a[u] << " " << d << " " << CHT.query(a[u]) << '\n';
            ans[root] = min(ans[root] , a[root] * a[u] + d);
            ans[u] = min({ans[u] , a[u] * a[root] + d});
        }   
        else {
            ans[u] = min(ans[u] , -CHT.query(a[u]) + d);
            //cerr << u << " " << a[u] << " " << d << " " << CHT.query(a[u]) + d << '\n';
        }
        for (auto [v , w] : adj[u]) {
            if (v != father && !check[v]) {
                calc(v , u , stat , d + w , root , calc);
            }
        }
    };

    for (auto [v , w] : adj[u]) {
        if (v != father && !check[v]) {
         //cerr << u << '\n';
            calc(v , v , 0 , w , u , calc);
        }
    }
    for (auto [v , w] : adj[u]) {
        if (v != father && !check[v]) {
         //cerr << u << '\n';
            //calc(v , v , 0 , w , u , calc);
            calc(v , v , 1 , w , u , calc);
        }
    }
    for (auto [v , w] : adj[u]) {
        if (!check[v]) centroid(v , u);
    }
}   


void solve() {
    int n; cin >> n;
    for (int i = 1 ; i <= n ;i ++) cin >> a[i];
    for (int i = 1 ; i <= n ; i++) ans[i] = a[i] * a[i];
    for (int i = 1 ; i < n ; i++) {
        int u , v , w; cin >> u >> v >> w;
        adj[u].emplace_back(v , w);
        adj[v].emplace_back(u , w);
    }
    centroid(1 , -1);
    int res = 0;
    for (int i = 1 ; i <= n ; i++) {
        //cout << ans[i] << " ";
        res += ans[i]; 
    }
    //cout << '\n';
    cout << res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}