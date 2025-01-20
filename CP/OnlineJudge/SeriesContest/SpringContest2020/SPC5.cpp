#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define ll long long

ll n;
vector<ll> adj[MAX_N];
ll a[MAX_N];
ll sz[MAX_N];
ll up[MAX_N];
ll down[MAX_N];

void init() {
	for (ll i = 1 ; i <= MAX_N ; i++) {
		up[i] = 0;
		sz[i] = 0;
		down[i] = 0 ;
		adj[i].clear();
	}
}

void DFSforsize(ll u , ll father) {
	sz[u] = 1;
	for (auto v : adj[u]) {
		if (v != father) {
			DFSforsize(v , u);
			sz[u] += sz[v];
		}
	}
}

void DFSfordown(ll u , ll father) {
	down[u] = a[u];
	for (auto v : adj[u]) {
		if (v != father) {
			DFSfordown(v , u);
			down[u] += down[v] + sz[v]*a[u];
		}
	}
}

void DFSforup(ll u , ll father) {
	for (auto v : adj[u]) {
		if (v != father) {
			up[v] = (down[u] - down[v] - sz[v]*a[u]) + up[u] + (n - sz[v])*a[v];
			DFSforup(v , u);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	ll t; cin >> t;
	while (t--) {
		cin >> n;
		init();
		for (ll i = 1 ; i <= n ;i++) cin >> a[i];
		for (ll i = 1 ; i < n ;i++) {
			ll u , v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		DFSforsize(1 , -1);
		DFSfordown(1 , -1);
		DFSforup(1 , -1);
		for (ll i = 1 ; i <= n ; i++) {
			cout << up[i] + down[i] - a[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}