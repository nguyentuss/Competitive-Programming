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

const int N = 1e4 + 7;

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
	STLazy(int n) : n(n), tr(4*n + 8), lz(4*n + 8 , -1) {}

	void push(int v, int lo, int hi) {
		if (lz[v] != -1) {
			tr[v] = (hi - lo)*lz[v];
			if(lo+1 != hi) {
				lz[v*2] = lz[v];
				lz[v*2+1] = lz[v]; 
			}
			lz[v] = -1;
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

void solve() {
    vector<int> cnt(N); 
    vector<vi> adj(N);
    adj[1].push_back(1);
    for (int i = 2 ; i < N ; i++) {
        int tm = i;
        for (int j = 2 ; j * j <= tm ; j++) {
            if (tm % j == 0) {
                while (tm % j == 0) {
                    tm /= j;
                    cnt[i] += j;
                    adj[i].push_back(j);
                }
            }
        }
        if(tm > 1) {
            adj[i].push_back(tm);
            cnt[i] += tm;
        }
        sort(adj[i].begin() , adj[i].end() , greater<int>());
    }
    int n; cin >> n;
    vector<int> a(n);
    STLazy IT = STLazy(n+3);
    STLazy CC = STLazy(n+3);
    for (int i = 0 ; i < n; i++) {
        cin >> a[i]; 
        //cerr << cnt[a[i]] << " ";
        IT.update(i , i + 1 , cnt[a[i]]);
        CC.update(i , i + 1 , a[i]);
    }
    //cout << adj[2][0];
    //cerr << IT.query(0 , n) << '\n';
    int q; cin >> q;
    while (q--) {
        int t; cin >> t; 
        if (t == 1) {
            int i; cin >> i;
            i--;
            int x = CC.query(i , i + 1);
            //cerr << x << '\n';
            x /= adj[x][0];
            IT.update(i , i + 1 , cnt[x]);
            CC.update(i , i + 1 , x);
        }
        else if (t == 2) {
            int l , r; cin >> l >> r;
            l--; r--; 
            cout << IT.query(l , r + 1) << '\n';
        }
        else {
            int l , r , x; cin >> l >> r >> x; 
            l--; r--; 
            IT.update(l , r + 1 , cnt[x]);
            CC.update(l , r + 1 , x);
        }
    }
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