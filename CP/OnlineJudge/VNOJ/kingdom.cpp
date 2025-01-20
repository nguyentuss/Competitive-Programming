#include <bits/stdc++.h>

using namespace std;

int n , m;
vector <int> adj[107];
int C[107] , val[107];
int F[107][2007];

void DFS(int u , int father) {
	copy(F[father], F[father] + m + 1, F[u]);
	for (int v : adj[u]) {
		if (father == v) continue;
		DFS(v , u);
	}
	for (int i = 0 ; i + C[u] <= m ; i ++) {
		if (F[u][i] != -1) {
			F[father][i + C[u]] = max(F[father][i + C[u]] , F[u][i] + val[u]);
		}
	}
}

int main(){ 
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 2 ; i <= n; i++) cin >> val[i];
	for (int i = 2 ; i <= n ; i++) cin >> C[i];
	for (int i = 1 ; i < n ; i++) {
		int u , v ; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0 ; i <= n ; i++) {
		for (int j = 0 ; j <= m ;j++) {
			F[i][j] = -1;
		}
	}
	F[0][0] = 0;
	DFS(1 , 0);
	int ans = -1;
	for (int i = 0 ; i <= m ; i++) {
		ans = max(ans , F[1][i]);
	}
	cout << ans;

	return 0;
}