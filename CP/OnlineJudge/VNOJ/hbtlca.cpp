#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
int P[MAX_N][19];
vector <int> adj[MAX_N] , H(MAX_N);
int n;

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
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	while (cin >> n && n != 0) {
		init();
		for (int i = 1 ; i < n ;i++) {
			int u , v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		H[1] = 0;
		DFS(1 , -1);	
		buildtable();
		int q;
		cin >> q;
		int u , v , root;
		char ch;
		root = 1;
		for (int i = 1 ; i <= q ; i++) {
			cin >> ch;
			if (ch == '?') {
				cin >> u >> v;
				int tmp1 = LCA(u , root) , tmp2 = LCA(v ,root) , tmp3 = LCA(u , v);
				if (tmp1 == tmp2) cout << tmp3 << '\n';
				else if (tmp1 == tmp3) cout << tmp2 << '\n';
				else if (tmp2 == tmp3) cout << tmp1 << '\n';
			}
			else {
				cin >> root;
			}
		}
		int tmp;
	}
	return 0;
}