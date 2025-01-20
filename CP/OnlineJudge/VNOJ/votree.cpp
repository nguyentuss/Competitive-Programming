#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
int P[MAX_N][21] , F[MAX_N][21];
vector <int> adj[MAX_N] , H(MAX_N);
int n , q;

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
		for (int k = 1 ; k < 21 ; k ++) {
			P[u][k] = -1;
		}
	}
	for (int k = 1 ; k < 21 ;k++) {
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
		for (int k = 20 ; k >= 0 ; k --) {
			if (P[u][k] != -1 && H[P[u][k]] >= H[v]) {
				u = P[u][k];
				break;
			}
		}
	}	
	if (u == v) return u;
	while (true) {
		bool found = false;
		for (int k = 20 ; k >= 0 ; k --) {
			if (P[u][k] != 1 && P[v][k] != -1  && P[u][k] != P[v][k]) {
				u = P[u][k];
				v = P[v][k];
				found = true;
				break;
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
	//freopen("inp.inp","r",stdin);
	cin >> n >> q;
	for (int i = 1 ; i < n ;i++) {
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1 ; i <= n ; i++) {
		F[i][0] = i;
	}
	DFS(1 , -1);	
	H[1] = 0;
	buildtable();
	int u , v;
	for (int j = 1 ; (1 << j) <= n ; j++) {
		for (int i = 1 ; i + (1 << j) - 1 <= n ; i++) {
				F[i][j] = LCA(F[i][j - 1] , F[i + (1 << (j - 1))][j - 1]);
		}
	}
	for (int i = 1 ; i <= q ; i++) {
		cin >> u >> v;
		int k = log2(v - u + 1);
		cout << LCA(F[u][k] , F[v - (1 << k) + 1][k]) << '\n';
	}
	return 0;
}