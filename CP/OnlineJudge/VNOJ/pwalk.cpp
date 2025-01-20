#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define ii pair<int ,int>
int P[MAX_N][19] , F[MAX_N][19];
vector <int> H(MAX_N);
vector <ii> adj[MAX_N];
int n;



void DFS(int u , int father , int weight) {
	P[u][0] = father;
	F[u][0] = weight;
	//cout << u << " " << father << " " << weight << '\n';
	for (int i = 0 ; i < (int) adj[u].size() ;i++) {
		int v = adj[u][i].second;
		if (v == father) {
			continue;
		}
		H[v] = H[u] + 1;
		DFS(v , u , adj[u][i].first);
	}
}

void buildtable() {
	for (int u = 1 ; u <= n ; u++) {
		for (int k = 1 ; k < 19 ; k ++) {
			P[u][k] = -1;
			F[u][k] = 0;
		}
	}
	for (int k = 1 ; k < 19 ;k++) {
		for (int u = 1 ; u <= n ; u++) {
			if (P[u][k - 1] != -1){
				P[u][k] = P[P[u][k - 1]][k - 1];
				F[u][k] = F[u][k - 1] + F[P[u][k - 1]][k - 1];
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
		for (int k = 18 ; k >= 0 ; k --) {
			if (P[u][k] != -1 && H[P[u][k]] >= H[v]) {
				ans += F[u][k];
				u = P[u][k];
				break;
			}
		}
	}	
	if (u == v) return ans;
	while (true) {
		bool found = false;
		for (int k = 18 ; k >= 0 ; k --) {
			if (P[u][k] != 1 && P[v][k] != -1  && P[u][k] != P[v][k]) {
				ans += F[u][k] + F[v][k];
				//cout << ans << '\n';
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
	ans += F[u][0] + F[v][0];
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int q;
	cin >> n >> q;
	for (int i = 1 ; i < n ;i++) {
		int u , v , w;
		cin >> u >> v >> w;
		adj[u].push_back(ii(w , v));
		adj[v].push_back(ii(w , u));
	}
	DFS(1 , -1 , 0);	
	buildtable();
	int u , v;
	for (int i = 1 ; i <= q ; i++) {
		cin >> u >> v;
		cout << LCA(u , v) << '\n';
	}
	return 0;
}