 	#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (5e4 + 7)
#define inf (int) (1e9 + 7)

int vis[1007];
int d[MAX_N];
vector<int> adj[MAX_N];

void BFS(int x) {
	memset(vis , false , sizeof vis);
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : adj[u]) {
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int n , m; cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) d[i] = inf;
	d[1] = 0;
	for (int i = 1 ; i <= m ; i++) {
		int ask , u , v; cin >> ask;
		if (ask == 1) {
			cin >> u;
			cout << (d[u] == inf ? -1 : d[u]) << '\n';
		}
		else {
			cin >> u >> v;
			adj[u].push_back(v);
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				BFS(v);
			}
		}
	}
	return 0;
}