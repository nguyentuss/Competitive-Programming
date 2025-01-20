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
const int N = 3e5 + 7;

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

struct Tree_Max {
	typedef pair<int , int> T;
	static constexpr T unit = T(-inf , -1);
	T f(T a, T b) { 
        if (a.first != b.first) return max(a , b);
        return a;
    } // (any associative fn)
	vector<T> s; int n;
	Tree_Max(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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

struct Tree_Min {
	typedef pair<int , int> T;
	static constexpr T unit = T(inf,-1);
	T f(T a, T b) { 
        if (a.first != b.first) return min(a , b);
        return a;
    } // (any associative fn)
	vector<T> s; int n;
	Tree_Min(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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
    vector<int> a(n);
    vector<vector<int>> idx(n + 1); 
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        idx[a[i]].push_back(i);
    }
    set<int> L;
    for (int i = 1 ; i <= n ; i++) {
        if (sz(idx[i])) {
            //cerr << sz(idx[i]) << '\n';
            L.insert(idx[i].back());
        }
    }
    vector<int> ans;
    Tree_Min T_min(n+3);
    Tree_Max T_max(n+3);
    for (int i = 0 ; i < n ; i++) {
        T_min.update(i , pii(a[i] , i)); 
        T_max.update(i , pii(a[i] , i));
    }
    int pos = 0;
    while (!L.empty()) {
        int r = *L.begin() + 1;
        pii t;
        //cerr << "OK";
        if (sz(ans) & 1) {  
            t = T_min.query(pos , r);
        }
        else {
            t = T_max.query(pos , r);
        }
        //cerr << t.first << " " << t.second << '\n';
        ans.push_back(t.first);
        for (int id : idx[t.first]) {
            T_min.update(id , pii(inf , id));
            T_max.update(id , pii(-inf , id));
        }
        L.erase(idx[t.first].back()); 
        pos = t.second + 1;
    }
    cout << sz(ans) << '\n';
    for (int x : ans) cout << x << " ";
    cout << '\n';
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