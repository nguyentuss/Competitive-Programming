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
		for (; pos < sz(s); pos |= pos + 1) s[pos] ^= dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res ^= s[pos-1];
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

const int N = 5e5 + 7; 
vector<int> adj[N]; 
int in[N] , out[N]; 
int h[N];
int Time = 0;

void DFS(int u , int father) {
	h[u] = h[father] + 1; 
	in[u] = Time; Time++;
	for (int v : adj[u]) {
		if (v != father) {
			DFS(v , u); 
		}
	}
	out[u] = Time;
}

void solve() {
	int n; cin >> n;
	vector<tuple<int , int , int>> edge;
	for (int i = 1 ; i < n ; i++) {
		int u , v , w; cin >> u >> v >> w;
		u--; v--;
		edge.emplace_back(u , v , w&1);
		adj[u].emplace_back(v); 
		adj[v].emplace_back(u);
	}
	DFS(0 , 0);
	FT bit = FT(n + 1);
	for (auto &[u , v , w] : edge) {
		if (h[u] < h[v]) swap(u , v); 
		bit.update(in[u] , w);
		bit.update(out[u] , w);
	}
	int q; cin >> q; 
	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			//cerr << "YES";
			int u, v; cin >> u >> v; u--; v--; 
			if (bit.query(in[u] + 1) ^ bit.query(in[v] + 1)) cout << "WE NEED BLACK PANDA\n"; 
			else cout << "JAKANDA FOREVER\n";
		}
		else {
			int i , l; cin >> i >> l; 
			i--; 
			l &= 1;
			auto &[u , v , w] = edge[i];
			bit.update(in[u] , w);
			bit.update(out[u] , w);
			w = l;
			bit.update(in[u] , w);
			bit.update(out[u] , w);
		}
		//cerr << "YES";
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