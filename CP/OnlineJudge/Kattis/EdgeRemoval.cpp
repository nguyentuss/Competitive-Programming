#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)

struct edge {
	int u , v , w , id;
};

bool cmp(edge &a , edge &b) {
	return a.w < b.w;
}

int n , m;
vector<edge> adj; 
int level[MAX_N];
int root[MAX_N]; 

void init() {
	for (int i = 1 ; i <= n ; i++) {
		root[i] = i;
	}
}

int findroot(int u) {
	if (u == root[u]) return u;
	else {
		root[u] = findroot(root[u]);
		return root[u];
	}
}

void unionset(int u , int v) {
	u = findroot(u);
	v = findroot(v);
	if (u != v) {
		root[u] = root[v];
	}
}
bool check(int u , int v) {
	u = findroot(u);
	v = findroot(v);
	return (u != v);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int t; cin >> t;
	while (t--) {
		adj.clear();
		cin >> n >> m;
		init();
		for (int i = 1 ; i <= m ; i++) {
			int u , v , w; cin >> u >> v >> w;
			unionset(u , v);
			adj.push_back({u , v , w , i});
		}
		int cnt = 0;
		for (int i = 1 ; i <= n ; i++) {
			if (root[i] == i) cnt++; 
		}
			
		if (cnt > 1) {
			cout << -1 << '\n';
			continue;
		}
		init();
		vector<int> ans;
		sort(adj.begin() , adj.end() , cmp);
		int total = 0;
		for (int i = 0 ; i < m ;) {
			int j = i;
			while (j < m && adj[i].w == adj[j].w) j++;
			vector<edge> tmp;
			for (int k = i ; k < j ; k++) {
				int u = adj[k].u;
				int v = adj[k].v;
				if (check(u , v)) {
					tmp.push_back(adj[k]);
				}
			}

			for (auto e : tmp) {
				if (!check(e.u , e.v)) {
					ans.push_back(e.id);
				}
				unionset(e.u , e.v);
			}
			i = j;
		}
		cout << ans.size() << " ";
		for (auto e : ans) cout << e << " ";
		cout << '\n';
	}
	return 0;
}