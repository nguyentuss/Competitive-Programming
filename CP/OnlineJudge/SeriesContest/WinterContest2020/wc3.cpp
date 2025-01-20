#include <bits/stdc++.h>

using namespace std;

#define MAX_N (ll) (1e5 + 7)
#define ll long long

struct edge {
	ll u , v , w;
};

bool cmp(edge &a , edge &b) {
	return a.w < b.w;
}

ll root[MAX_N] , level[MAX_N];
vector <edge> adj;
ll N , E , M , K;

void init() {
	adj.clear();
	for (ll i = 0 ; i < MAX_N ;i++) {
		root[i] = i;
		level[i] = 0;
	}
}

ll findroot(ll u) {
	if (u == root[u]) return u;
	else {
		root[u] = findroot(root[u]);
		return root[u];
	}
}

void unionset(ll u , ll v) {
	u = findroot(u);
	v = findroot(v);
	if (u != v) {
		if (level[u] < level[v]) swap(u , v);
		root[v] = u;
		if (level[u] == level[v]) level[u]++;
	}
}

bool check(ll u , ll v) {
	u = findroot(u);
	v = findroot(v);
	return (u == v);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("wc3.inp","r",stdin);
	//freopen("wc3.out","w",stdout);
	ll t; cin >> t;
	while (t--) {
		init();
		cin >> N >> E >> M >> K;
		for (ll i = 1 ; i <= K ; i++) {
			ll x; cin >> x;
			adj.push_back({0 , x , 0});
		}
		for (ll i = 1 ; i <= E ; i++) {
			ll u , v , w; cin >> u >> v >> w;
			adj.push_back({u , v , w});
		}
		sort(adj.begin() , adj.end() , cmp);
		ll total = 0 , num = 0;
		for (ll i = 0 ; i < adj.size() ; i++) {
			if (!check(adj[i].u , adj[i].v)) {
				unionset(adj[i].u , adj[i].v);
				total += adj[i].w;
				if (adj[i].w > 0) num++;
			} 
		}
		total += M*num;
		cout << total << '\n';
	}
	return 0;
}