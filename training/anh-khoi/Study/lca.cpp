#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (3*1e5 + 7)
int P[MAX_N][20];
vector <int> adj[MAX_N] , H(MAX_N);
int n;

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
		for (int k = 1 ; k < 20 ; k ++) {
			P[u][k] = -1;
		}
	}
	for (int k = 1 ; k < 20 ;k++) {
		for (int u = 1 ; u <= n ; u++) {
			if (P[u][k - 1] != -1){
				P[u][k] = P[P[u][k - 1]][k - 1];
			}
		}
	}
}

void process(int u , int height) {
	while (H[u] > H[v]) {
		for (int i k = 19 ; k >= 0 ; k--) {
			if (P[u][k] != -1 && H[P[u][k]] >= height) {
				u = P[u][k];
				break;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("inp.inp","r",stdin);
	cin >> n;
	for (int i = 1 ; i < n ;i++) {
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	DFS(1 , -1);	
	H[1] = 0;
	buildtable();

	int q;
	cin >> q;
	int u , v;
	for (int i = 1 ; i <= q ; i++) {
		cin >> u >> v;
		cout << LCA(u , v) << '\n';
	}
	return 0;
}