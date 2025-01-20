#include <bits/stdc++.h>

using namespace std;

int root[2] , n , m;
vector <int> adj[2][100007];
int F[2004][2004];

void DFS1(int u) {
	for (auto v : adj[0][u]) {
		for (int i = 1 ; i <= n ; i++) {
			F[v][i] += F[u][i];
		}
		DFS1(v);
	}
	return;
}

void DFS2(int u) {
	for (auto v : adj[1][u]) {
		for (int i = 1 ; i <= n ; i++) {
			F[i][v] += F[i][u]; 
		}
		DFS2(v);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
 	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 0 ; j <= 1 ; j++) {
			int x; cin >> x;
			if (x == 0) root[j] = i;
			else adj[j][x].push_back(i);
		}
	}
	for (int i = 1 ; i <= m; i++) {
		int x , y; cin >> x >> y;
		F[x][y] ++;
	}
	DFS1(root[0]);
	DFS2(root[1]);
	for (int i = 1 ; i <= n; i++) {
		cout << F[i][i] << '\n';
	}
	return 0;
}