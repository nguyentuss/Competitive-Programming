#include <bits/stdc++.h>

using namespace std;

#define MAX_N (ll) (1e5 + 7)
#define ll long long

ll n; 
vector<ll> adj[MAX_N] , vec[MAX_N];
ll sz[MAX_N];
ll col[MAX_N];
ll res[MAX_N];
ll ans[MAX_N];
ll cnt[MAX_N];

void cntsize(ll u , ll father) {
	sz[u] = 1;
	for (auto v : adj[u]) {
		if (v != father) {
			cntsize(v , u);
			sz[u] += sz[v];
		}
	}
	return;
}

void update(ll u , ll &maxi , ll x) {
	ans[cnt[col[u]]] -= col[u];
	cnt[col[u]] += x;
	ans[cnt[col[u]]] += col[u];
	maxi = max(maxi , cnt[col[u]]);
}

ll dfs(ll u , ll father , ll keep) {
	ll maxi = -1 , bigchild = -1 , maximum = -1;
	for (auto v : adj[u]) {
		if (v != father && maximum < sz[v]) {
			maximum = sz[v];
			bigchild = v;
		}
	}
	for (auto v : adj[u]) {
		if (v != father && v != bigchild) {
			dfs(v , u , 0);
		}
	}
	if (bigchild != -1) {
		maxi = max(maxi , dfs(bigchild , u , 1));
		swap(vec[u] , vec[bigchild]);
	}
	vec[u].push_back(u);
	update(u , maxi , 1);
	for (auto v : adj[u]) {
		if (v != father && v != bigchild) {
			for (auto x : vec[v]){
				update(x , maxi , 1);
				vec[u].push_back(x);
			}
		}
	}
	res[u] = ans[maxi];
	if (keep == 0) {
		for (auto v : vec[u]) {
			update(v , maxi , -1);
		}
	}
return maxi;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (ll i = 1 ; i <= n ; i++) 
		cin >> col[i];
	for (ll i = 1 ; i < n ;i++) {
		ll u , v ; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cntsize(1 , -1);
	dfs(1 , -1 , 0);
	for (ll i = 1 ; i <= n ;i++) cout << res[i] << " ";
	return 0;
}