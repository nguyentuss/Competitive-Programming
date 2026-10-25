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
	for (auto i : col[v]) {
		ll t = col[u][i.first];
		ans = ans - (t * (t - 1) / 2 + i.second * (i.second - 1) / 2) + (t + i.second) * (t + i.second - 1) / 2;
		col[u][i.first] += i.second;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("CGRAPH.inp","r",stdin);
	//freopen("CGRAPH.out","w",stdout);
	cin >> n >> m;
	for (ll i = 1 ; i <= n ; i++) {
		root[i] = i;
		cin >> a[i];
		col[i][a[i]] = 1;
	}
	for (ll i = 1 ; i <= m ; i++) {
		ll u , v; cin >> u >> v;
		addnode(u , v);
		cout << ans << '\n';
	}

	return 0;
}