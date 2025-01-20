#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)
#define lim (int) (1e9 + 7)
#define ii pair<int , int>
#define f first
#define s second
#define int long long

struct edge {
	int u , v , w , id;
};

bool cmp(edge &a , edge &b) {
	return a.w < b.w;
}

bool cmpid(edge &a , edge &b) {
	return a.id < b.id;
}

vector<ii> adj[MAX_N];
vector<edge> a;
bool vis[MAX_N];
int P[MAX_N][20];
int f[MAX_N][20];
int root[MAX_N] , len[MAX_N] , H[MAX_N];
int n , m;

void init() {
	for (int i = 1 ; i < MAX_N ; i++) {
		root[i] = i;
		len[i] = 1;
	}
	for (int i = 1 ; i < MAX_N ; i++) {
		for (int k = 0 ; k < 20 ; k++) {
			P[i][k] = -1;
			f[i][k] = 0;
		}
	}
	return;
}

int findroot(int u) {
	if (u == root[u]) return u;
	else return root[u] = findroot(root[u]);
}

bool check(int u , int v) {
	u = findroot(u);
	v = findroot(v);
	return (u != v);
}

void unionset(int u , int v) {
	u = findroot(u);
	v = findroot(v);
	if (u != v) {
		if (len[u] < len[v]) swap(u , v);
		root[v] = u;
		len[u] += len[v];
	}
	return;
}

void DFS(int u , int father , int weight) {
	P[u][0] = father;
	f[u][0] = weight;
	for (auto v : adj[u]) {
		if (v.first != father) {
			H[v.first] = H[u] + 1;
			DFS(v.first , u , v.second);
		}
	}
}

void sparsetable() {
	for (int k = 1 ; k < 20 ; k++) {
		for (int i = 1 ; i <= n ; i++) {
			if (P[i][k - 1] != -1) {
				P[i][k] = P[P[i][k - 1]][k - 1];
				f[i][k] = max(f[i][k - 1] , f[P[i][k - 1]][k - 1]);
			} 
		}
	}
}

int lca(int u , int v) {
	if (H[u] < H[v]) swap(u , v);
	int ans = 0;
	while (H[u] > H[v]) {
		for (int k = 19 ; k >= 0 ; k--) {
			if (P[u][k] != -1 && H[P[u][k]] >= H[v]) {
				ans = max(ans , f[u][k]);
				u = P[u][k];
				break;
			}
		}
	}
	if (u == v) return ans;
	while (true) {
		bool found = false;
		for (int k = 19 ; k >= 0 ; k--) {
			if (P[u][k] != -1 && P[v][k] != -1 && P[u][k] != P[v][k]) {
				ans = max({ans , f[u][k] , f[v][k]});
				u = P[u][k];
				v = P[v][k];
				found = true;
				break;
			}
		}
		if (!found) break;
	}
	ans = max({ans , f[u][0] , f[v][0]});
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	init();
	cin >> n >> m;
	for (int i = 1 ; i <= m ; i++) {
		int u , v , w; cin >> u >> v >> w;
		a.push_back({u , v , w , i});
	}
	sort(a.begin() , a.end() , cmp);
	int wncute = 0;
	for (int i = 0 ; i < a.size() ; i++) {
		int u = a[i].u , v = a[i].v , w = a[i].w , id = a[i].id;
		if (check(u , v)) {
			unionset(u , v);
			//cout << u << " " << v << " " << w << " " << id << '\n';
			adj[u].push_back(ii(v , w));
			adj[v].push_back(ii(u , w));
			wncute += w;
			vis[id] = true;
		}
	}
	DFS(1 , -1 , 0);
	sparsetable();
	sort(a.begin() , a.end() , cmpid);
	for (int i = 0 ; i < a.size() ; i++) {
		int u = a[i].u , v = a[i].v , w = a[i].w , id = a[i].id;
		if (vis[id]) {
			cout << wncute << '\n';
			continue;
		}
		else {
			int val = lca(u , v);
			cout << wncute - val + w << '\n'; 
		}
	}
	return 0;
}