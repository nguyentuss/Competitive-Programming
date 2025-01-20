//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

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
	static constexpr T unit = 0;
	T f(T a, T b) { return a + b; } // (any associative fn)
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
    string s; cin >> s;
    int n = sz(s);
    Tree T(n);
    for (int i = 0 ; i < n - 3 ; i++) {
        string t = s.substr(i , 4ll); 
        if (t == "1100") {  
            T.update(i , 1);
        }
    }
    int q; cin >> q;
    while (q--) {
        int x , v; cin >> x >> v; 
        x--;
        s[x] = v + '0';
        if (n < 4ll) {
            cout << "NO\n";
            continue;
        }
        bool ok = false;
        for (int i = x ; i >= max(0ll , x-3) ; i--) {
            T.update(i , 0);
            string t = s.substr(i , 4);
            if (t == "1100") {
                T.update(i , 1);
                ok = true;
            }
        }
        if (ok == true || T.query(0 , max(x-3,0ll)) || T.query(x + 1 , n)) {
            cout << "YES\n";
        } 
        else cout << "NO\n";
        // for (int i = 0 ; i < n ; i++) {
        //     cerr << T.query(i , i + 1) << " ";
        // }
        // cerr << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }

}