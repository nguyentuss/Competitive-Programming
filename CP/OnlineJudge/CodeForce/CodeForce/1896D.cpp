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
 * Author: Lukas Polacek
 * Date: 2009-10-30
 * License: CC0
 * Source: folklore/TopCoder
 * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1], and updates single elements a[i],
 * taking the difference between the old and new value.
 * Time: Both operations are $O(\log N)$.
 * Status: Stress-tested
 */
#pragma once

#pragma once

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

void solve() {
	int n , q; cin >> n >> q;
	vector<int> a(n);
	set<int> s1;
	FT f(n);   
	for (int i = 0 ; i < n ;i ++) {
		cin >> a[i]; 
		if (a[i] == 1) s1.insert(i);
		f.update(i , a[i]);
	}
	while (q--) {
		int ask; cin >> ask;
		if (ask == 1) {
			int s; cin >> s;
			int sum = f.query(n);
			// for (int i = 0 ; i < n ; i++) {
			// 	cerr << f.query(i + 1) - f.query(i) << " ";
			// }
			// cerr << '\n';
			if (sum < s) {
				cout << "NO\n";
			}
			else if ((sum + s)%2 == 0) {
				cout << "YES\n"; 
			}
			else {
				if (sz(s1) == 0) {
					cout << "NO\n";
					continue;
				}
				int mn = inf;
				mn = min(mn , *s1.begin());
				mn = min(mn , n - 1 - (*s1.rbegin()));
				sum -= 2*mn; 
				// cerr << sum << '\n';
				if (sum - 1 >= s) {
					cout << "YES\n";
				}
				else cout << "NO\n";
			}
		}
		else {
			int i , v; cin >> i >> v;
			i--;
			int prev_val = f.query(i + 1) - f.query(i);
			if (prev_val == 1) s1.erase(i);
			if (v == 1) s1.insert(i); 
			f.update(i, -prev_val);
			f.update(i , v);
		}
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
