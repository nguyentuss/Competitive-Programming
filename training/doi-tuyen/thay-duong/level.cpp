#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

vector <int> adj[MAX_N];
int level[MAX_N];

void BFS() {
	queue<int> q;
	//for (int i = 1 ; i <= n ; i++) level[i] = 0;
	q.push(1) , level[1] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : adj[u]) {
			if (!level[v]) {
				level[v] = level[u] + 1;
				q.push(v);
			}			
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("level.inp","r",stdin);
	freopen("level.out","w",stdout);
	int n; cin >> n;
	for (int i = 1 ; i < n ; i++) {
		int u , v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int x; cin >> x;
	BFS();
	int ans = 0 ;
	for (int i = 1; i <= n; i++) {
		if (level[i] == x) ans ++; 
	}
	cout << ans;
	return 0;
}