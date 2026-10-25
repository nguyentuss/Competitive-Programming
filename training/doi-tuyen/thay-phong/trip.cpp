#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e2 + 7)
#define inf (int) (1e9 + 7)
#define ii pair<int , int>
#define f first
#define s second

struct edges {
	int u , v , c;
};

bool cmp(edges &a , edges &b) {
	return a.c < b.c;
}

vector<ii> adj[MAX_N];
int root[MAX_N];
vector<edges> edge;
int a[MAX_N][MAX_N];
int level[MAX_N];
vector<edges> MST;
int H[MAX_N];
int f[MAX_N];
int n , m;
int P[MAX_N][19];
vector<edges> last;

void init() {
	MST.clear();
	edge.clear();
	last.clear();
	for (int i = 1 ; i <= n ;i ++) {
		adj[i].clear();
		root[i] = i;
		level[i] = 0;
		H[i] = 0;
		f[i] = 0;
	}
	for (int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= n ; j++) {
			a[i][j] = inf;
		}
	}
}

void sparsetable() {
	for (int i = 1 ; i <= n ; i++) {
		for (int k = 1 ; k <= 8 ; k++) {
			P[i][k] = -1;
		}
	}
	for (int k = 1 ; k <= 8 ; k++) {
		for (int i = 1 ; i <= n ; i++) {
			if (P[i][k - 1] != -1) 
				P[i][k] = P[P[i][k - 1]][k - 1];
		}
	}
	return;
}

int lca(int u , int v) {
	if (H[u] < H[v]) swap(u , v);
	while (H[u] > H[v]) {
		for (int k = 8 ; k >= 0 ; k--) {
			if (P[u][k] != -1 && H[P[u][k]] >= H[v]) {
				u = P[u][k];
				break;
			}
		}
	}
	if (u == v) return v;
	while (true) {
		bool found = false;
		for (int k = 8 ; k >= 0 ; k--) {
			if (P[u][k] != -1 && P[v][k] != -1 && P[u][k] != P[v][k]) {
				u = P[u][k];
				v = P[v][k];
				found = true;
				break;
			}
		}
		if (!found) break;
	}
	return P[u][0];
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
		if (level[u] == level[v]) level[u] ++;
		if (level[u] > level[v]) root[v] = u; 
		else root[u] = v;
	}
}

bool check(int u , int v) {
	u = findroot(u);
	v = findroot(v);
	return (u == v);
}

void DFS(int u , int father) {
	P[u][0] = father;
	for (auto v : adj[u]) {
		if (v.s != father) {
			H[v.s] = H[u] + 1;
			f[v.s] = f[u] + v.f;
			DFS(v.s , u);
		}
	}
}

int dist(int u , int v) {
	return (f[u] + f[v] - 2*f[lca(u , v)]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("test.inp","r",stdin);
	while (cin >> n) {
		if (n == -1) return 0;
		cin >> m;
		init();
		for (int i = 1 ; i <= m ; i++) {
			int u , v , c; cin >> u >> v >> c;
			if (u > v) swap(u , v);
			a[u][v] = min(a[u][v] , c);
		}
		for (int i = 1 ; i < n ; i++) {
			for (int j = i + 1 ; j <= n ; j++) {
				if (a[i][j] != inf) {
					edge.push_back({i , j , a[i][j]});
				}
			}
		}
		sort(edge.begin() , edge.end() , cmp);
		for (int i = 0 ; i < edge.size() ; i++) {
			int u = edge[i].u , v = edge[i].v , c = edge[i].c;
			if (!check(u , v)) {
				unionset(u , v);
				adj[u].push_back(ii(c , v));
				adj[v].push_back(ii(c , u));
			}
			else {
				last.push_back({u , v , c});
			}
		}
		DFS(1 , -1);
		sparsetable();
		int ans = inf;
		for (int i = 0 ; i < last.size() ; i++) {
			ans = min(ans , dist(last[i].u , last[i].v) + last[i].c);
		}
		if (ans == inf) cout << -1 << '\n';
		else cout << ans << '\n';	
	}

	return 0;
}	