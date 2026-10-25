#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

int n ,m;
vector <int> adj[MAX_N]; // tập các nút nối với cây con cũ
int f[MAX_N]; // f[i] la so nut cay con goc v
vector <int> g[MAX_N]; // tập các nút nối với cây centroid 
bool check[MAX_N]; // ktra xem có phải nút u có phải là centroid không 
int root; // gốc mẹ của cây centroid

void DFS(int u , int father) {
	f[u] = 1;
	for (auto v : adj[u]) {
		if (father != v && !check[v]) {
			DFS(v , u);
			f[u] += f[v];
		}
	}
}

int find_ct(int u , int father , int root) {
	for (auto v : adj[u]) 
		if (!check[v] && v != father && f[v]*2 >= f[root]) 
			return find_ct(v , u , root);
	return u;
}

void centroid(int u , int father) {
	DFS(u , u);
	u = find_ct(u , u , u); check[u] = 1;
	if (father != -1) {
		g[father].push_back(u);
		g[u].push_back(father);
	}
	else {
		root = u;
	}	
	for (auto v : adj[u]) {
		if (!check[v]) 
			centroid(v , u);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	// freopen("test.inp","r",stdin);
	// freopen("test.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i < n ;i++) {
		int u , v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	centroid(1 , -1);
	cerr << root;
	for (int i = 1 ; i <= n ; i++) {
		for (auto v : g[i]) {
			if (v != 0) {
				cout << i << " " << v << '\n';
			}
		}
	}
	return 0;
}