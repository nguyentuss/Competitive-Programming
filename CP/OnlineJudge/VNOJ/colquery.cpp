#include <bits/stdc++.h>

using namespace std;

#define MAX_N (ll) (2e5 + 7)
#define ll long long

ll root[MAX_N];
ll n , m;
map<ll ,ll> col[MAX_N];
ll ans = 0;
ll a[MAX_N];

ll findroot(ll u) {
	if (u == root[u]) return u;
	else {
		root[u] = findroot(root[u]);
		return root[u];
	}
}

void addnode(ll u , ll v) {
	u = findroot(u) , v = findroot(v);
	if (u == v) return;
	if (col[u].size() < col[v].size()) swap(u , v);
	root[v] = u;
	for (auto &i : col[v]) {
		col[u][i.first] += i.second;
	}
}	
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (ll i = 1 ; i <= n ; i++) {
		root[i] = i;
		cin >> a[i];
		col[i][a[i]] = 1;
	}
	int query;
	for (ll i = 1 ; i <= m ; i++) {
		ll u , v; cin >> query >> u >> v;
		if (query == 1) addnode(u , v);
		else cout << col[findroot(u)][v] << '\n';
	}

	return 0;
}