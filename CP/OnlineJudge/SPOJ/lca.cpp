		#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
int P[MAX_N][19];
vector <int> adj[MAX_N] , H(MAX_N);
int n , tmp1 , tmp2;
void init() {
	for (int i = 1 ; i <= n ; i++) {
		adj[i].clear();
		H[i] = 0;
	}
}

void DFS(int u , int father) {
	P[u][0] = father;
	for (int i = 0 ; i < (int) adj[u].size() ;i++) {
		int v = adj[u][i];
		if (v == father) {
			continue;
		}
		H[v] = H[u] + 1;
		DFS(v , u);
	}
}

void buildtable() {
	for (int u = 1 ; u <= n ; u++) {
		for (int k = 1 ; k < 19 ; k ++) {
			P[u][k] = -1;
		}
	}
	for (int k = 1 ; k < 19 ;k++) {
		for (int u = 1 ; u <= n ; u++) {
			if (P[u][k - 1] != -1){
				P[u][k] = P[P[u][k - 1]][k - 1];
			}
		}
	}
}
int LCA(int u , int v) {
	if (H[u] < H[v]) {
		swap(u , v);
	}
	while (H[u] > H[v]) {
		for (int k = 18 ; k >= 0 ; k --) {
			if (P[u][k] != -1 && H[P[u][k]] >= H[v]) {
				u = P[u][k];
				break;
			}
		}
	}	
	if (u == v) return u;
	while (true) {
		bool found = false;
		for (int k = 18 ; k >= 0 ; k --) {
			if (P[u][k] != -1 && P[v][k] != -1  && P[u][k] != P[v][k]) {
				u = P[u][k];
				v = P[v][k];
				found = true;
			}
		}
		if (!found) {
			break;
		}
	}
	return P[u][0];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int test = 1 ; test <= t ; test++) {
		cin >> n;
		init();
		for (int i = 1 ; i <=n ;i++) {
			int m , u = i , v;
			cin >> m;
			for (int j = 1 ; j <= m ; j++) {
				cin >> v;
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
		DFS(1 , -1);	
		H[1] = 0;
		buildtable();
		int q;
		cout << "Case " << test << ":" << '\n';
		cin >> q;
		for (int i = 1 ; i <= q ; i++) {
			int u , v;
			cin >> u >> v;
			cout << LCA(u , v) << '\n';
		}
	}
	return 0;
}