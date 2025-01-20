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

const int N = 2e5 + 7;

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

struct Tree {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
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

int sum[N];

int cnp(int l , int r , int val) {
    int c = r; 
    int ans = 0;
    while (l <= r) {
        int mid = (l + r)/2;
        if (sum[c] - sum[mid - 1] >= val) {
            ans = mid; 
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}


void solve() {
    int n , l , r; cin >> n >> l >> r;
    vector<int> a(n + 1);
    Tree seg(n + 4); 
    vector<int> f(n + 1);
    sum[0] = 0;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1 ; i <= n ; i++) {
        int x = cnp(1 , i , l);
        int y = cnp(1 , i , r + 1);
        y++;
        cerr << x << " " << y << '\n';
        if (x > y) swap(x , y);
        if (l <= sum[i] - sum[x - 1] && sum[i] - sum[x - 1] <= r && sum[i] - sum[y - 1] >= l && sum[i] - sum[y - 1] <= r)
            f[i] = seg.query() + 1;
        f[i] = max(f[i] , f[i - 1]);
        //cerr << f[i] << " ";
        seg.update(i , f[i]);
    }
    int ans = 0; 
    for (int i = 1 ; i <= n ; i++) {
        cerr << f[i] << " ";
        ans = max(ans , f[i]);
    }
    cout << ans << '\n';
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
    return 0;
}