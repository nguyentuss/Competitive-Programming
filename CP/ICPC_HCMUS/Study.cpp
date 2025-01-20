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
const int inf = 1e15;

/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description: Zero-indexed max-tree. Bounds are inclusive to the left and exclusive to the right. Can be changed by modifying T, f and unit.
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once

//hehe

struct Tree {
	typedef int T;
	static constexpr T unit = inf;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};


void solve() {
    int n; cin >> n;
    vector<int> a(n) , b(n) , c(n);
    for (int i = 0 ; i < n ; i++) cin >> a[i]; 
    for (int i = 0 ; i < n ; i++) cin >> b[i] , b[i] = a[i] - b[i]; 
    for (int i = 0 ; i < n ; i++) cin >> c[i] , c[i] = a[i] - c[i];
    set<int> s;
    map<int , int> mp;
    for (int i = 0 ; i < n ; i++) {
        s.insert(b[i]); 
        s.insert(c[i]);
        if (i != n - 1) b[i + 1] += b[i] , c[i + 1] += c[i];
    }
    int mx = 0;
    for (int x : s) {
        mp[x] = ++mx;
    }
	vector<vector<pii>> g(mx + 3);
    for (int i = 0 ; i < n ; i++) {
        b[i] = mp[b[i]];
        c[i] = mp[c[i]];
		g[b[i]].push_back(pii(c[i] , i));
    }           
	for (int i = 1 ; i <= mx ; i++) {
		sort(g[i].begin() , g[i].end());
	}
	Tree it(mx + 3);
	int ans = 0; 
	for (int i = 1 ; i <= mx ; i++) {
		for (auto [j , r] : g[i]) {
			int l = it.query(0 , j + 1);
			if (l != inf) {
				ans = max(ans , r - l);
			}
			cerr << i << " " << j << " " << l << " " << r << " " << ans << '\n';
			it.update(j , r);
		}
	}	
	cout << ans; 
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