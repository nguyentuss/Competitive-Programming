#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2*1e5 + 7)
#define ii pair<int ,int>
#define inf (int) (1e9 + 7)
int P[MAX_N][22] , Fmin[MAX_N][22] , Fmax[MAX_N][22];
vector <int> H(MAX_N);
vector <int> adj[MAX_N] , color[MAX_N];
int n , k;

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
		for (int k = 1 ; k <= 21 ; k ++) {
			P[u][k] = -1;
		}
	}
	for (int k = 1 ; k <= 21 ;k++) {
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
	long long ans = 0;
	while (H[u] > H[v]) {
		for (int k = 21 ; k >= 0 ; k --) {
			if (P[u][k] != -1 && H[P[u][k]] >= H[v]) {
				ans += (1 << k);
				u = P[u][k];
				break;
			}
		}
	}	
	if (u == v) return ans;
	while (true) {
		bool found = false;
		for (int k = 21 ; k >= 0 ; k --) {
			if (P[u][k] != 1 && P[v][k] != -1  && P[u][k] != P[v][k]) {
				ans += 2*(1 << k);
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
	ans += (1 << 1);
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	cin >> n >> k;
	int root;
	for (int i = 1 ; i <= n ;i++) {
		int u , v;
		cin >> u >> v;
		color[u].push_back(i);
		if (v) {
			adj[i].push_back(v);
			adj[v].push_back(i);
		}
		else root = i;

	}
	DFS(root , -1);	
	buildtable();
	for (int i = 1 ; i <= k ; i ++) {
		int u = color[i][0] , res = 0 , save;
		for (auto v : color[i]) {
			long long tmp = LCA(u , v);
			//cout << u << " " << v << '\n';
			if (tmp > res) {
				res = tmp;
				save = v;
			}
		}
		for (auto v : color[i]) {
			long long tmp = LCA(save , v);
			if (tmp > res) 
				res = tmp;
		}
		cout << res << '\n';
	}
	return 0;
}