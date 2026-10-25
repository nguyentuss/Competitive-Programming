#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (5e3 + 7)
#define inf (int) (1e9 + 7)

int resi[MAX_N][MAX_N] , aug[MAX_N][MAX_N];
int n , m , s , t;
int level[MAX_N];
vector<int> adj[MAX_N];

void BFS() {
	memset(level , 0 , sizeof level);
	level[s] = 1;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : adj[u]) {
			if (level[v] == 0 && (resi[u][v]||aug[u][v])) {
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}
	return;
}

int DFS(int u , int mini) {
	if (u == t) return mini;
	int res = 0;
	for (auto v : adj[u]) {
		if (level[v] == level[u] + 1) {
			if (resi[u][v]) {
				res = DFS(v , min(mini , resi[u][v]));
				if (res != 0) {
					resi[u][v] -= res;
					aug[v][u] += res;
					return res;
				}
			}
			else if (aug[u][v]) {
				res = DFS(v , min(mini , aug[u][v]));
				if (res != 0) {
					aug[u][v] -= res;
					resi[v][u] += res;
					return res;
				}
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("baove.inp","r",stdin);
	freopen("baove.out","w",stdout);
	cin >> n >> m;
	s = n , t = 1;
	for (int i = 1 ; i <= m ; i++) {
		int u , v , w; cin >> u >> v >> w;
		adj[u].push_back(v);
		adj[v].push_back(u);
		resi[u][v] += w;
	}
	int flow = 0;
	while (1) {
		BFS();
		if (level[t] == 0) break;
		while (int x = DFS(s , inf)) {
			flow+= x;
		} 
	}
	cout << flow;
	return 0;
}