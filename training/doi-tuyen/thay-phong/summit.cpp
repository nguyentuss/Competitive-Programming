#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

int n , q;
vector<int> adj[MAX_N];
int H[MAX_N] , P[MAX_N][20];
int dist , down[MAX_N] , up[MAX_N];
int newu , newv;

void DFS(int u , int father) {
	P[u][0] = father;
	down[u] = 1;
	for (auto v : adj[u]) {
		if (v != father) {
			H[v] = H[u] + 1;
			DFS(v , u);
			down[u] += down[v];
		}
	}
}

void top(int u , int father) {
	for (auto v : adj[u]) {
		if (v != father) {
			up[v] = up[u] + down[u] - down[v];
			top(v , u);
		}
	}
}

void sparsetable() {
	for (int k = 1 ; k <= 19 ; k++) {
		for (int i = 1 ; i <= n ; i++) {
			P[i][k] = -1;
		}
	}
	for (int k = 1 ; k <= 19 ; k++) {
		for (int i = 1 ; i <= n ; i++) {
			if (P[i][k - 1] != -1) {
				P[i][k] = P[P[i][k - 1]][k - 1];
			}
		}
	}
}

int lca(int u , int v) {
	if (H[u] < H[v]) swap(u , v);
	while (H[u] > H[v]) {
		for (int k = 19 ; k >= 0 ; k--) {
			if (P[u][k] != -1 && H[P[u][k]] >= H[v]) {
				u = P[u][k];
				break;
			}
		}
	}
	if (u == v) return u;
	while (true) {
		bool found = false;
		for (int k = 19 ; k >= 0 ; k--) {
			if (P[u][k] != -1 && P[v][k] != -1 && P[u][k] != P[v][k]) {
				u = P[u][k];
				v = P[v][k];
				found = true;
			}
		}
		if (!found) break;
	}
	newu = u , newv = v;
	return P[u][0];
}

int process(int u , int height) {
	while (H[u] > height) {
		for (int k = 19 ; k >= 0 ; k--) {
			if (P[u][k] != -1 && H[P[u][k]] >= height) {
				u = P[u][k];
				break;
			}
		}
	}
	return u;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	cin >> n >> q;
	for (int i = 2 ; i <= n ;i++) {
		int x; cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	DFS(1 , -1);
	top(1 , -1);
	sparsetable();
	/*for (int i = 1 ; i <= n ; i++) {
		cout << i << " " << down[i] << " " << up[i] << '\n';;
	}*/
	for (int i = 1 ; i <= q ; i++) {	
		int u , v; cin >> u >> v;
		if (u == v) {
			cout << n << '\n';
			continue;
		}
		int tm = lca(u , v);
		dist = H[u] + H[v] - 2*H[tm];
		if (dist % 2 != 0) {
			cout << 0 << '\n';
			continue;
		}	
		else {
			if (H[u] < H[v]) swap(u , v);
			int med = process(u , H[u] - dist/2);  
			//cout << med << '\n';
			if (tm == med) {
				cout << up[med] + down[med] - down[newu] - down[newv] << '\n';
			}
			else {
				int ce = process(u , H[med] + 1);
				cout << down[med] - down[ce] << '\n';
			}
		}
	}
	return 0;
}