#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define ii pair<int ,int>
#define inf (int) (1e9 + 7)
int P[MAX_N][21] , Fmin[MAX_N][21] , Fmax[MAX_N][21];
vector <int> H(MAX_N);
vector <ii> adj[MAX_N];
int n;



void DFS(int u , int father , int weight) {
	P[u][0] = father;
	Fmin[u][0] = weight;
	Fmax[u][0] = weight;
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
		for (int k = 1 ; k <= 19 ; k ++) {
			P[u][k] = -1;
			Fmax[u][k] = 0;
			Fmin[u][k] = inf;
		}
	}
	for (int k = 1 ; k <= 19 ;k++) {
		for (int u = 1 ; u <= n ; u++) {
			if (P[u][k - 1] != -1){
				P[u][k] = P[P[u][k - 1]][k - 1];
				Fmin[u][k] = min(Fmin[u][k - 1] , Fmin[P[u][k - 1]][k - 1]);
				Fmax[u][k] = max(Fmax[u][k - 1] , Fmax[P[u][k - 1]][k - 1]);
			}
		}
	}
}
ii LCA(int u , int v) {
	if (H[u] < H[v]) {
		swap(u , v);
	}
	ii ans;
	ans.first = inf , ans.second = -1;
	while (H[u] > H[v]) {
		for (int k = 19 ; k >= 0 ; k --) {
			if (P[u][k] != -1 && H[P[u][k]] >= H[v]) {
				ans.first = min(ans.first , Fmin[u][k]);
				ans.second = max(ans.second , Fmax[u][k]);
				u = P[u][k];
				break;
			}
		}
	}	
	if (u == v) return ans;
	while (true) {
		bool found = false;
		for (int k = 19 ; k >= 0 ; k --) {
			if (P[u][k] != 1 && P[v][k] != -1  && P[u][k] != P[v][k]) {
				ans.first = min(ans.first , min(Fmin[u][k] , Fmin[v][k]));
				ans.second = max(ans.second , max(Fmax[u][k] , Fmax[v][k]));
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
	ans.first = min(ans.first , min(Fmin[u][0] , Fmin[v][0]));
	ans.second = max(ans.second , max(Fmax[u][0] , Fmax[v][0]));
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	cin >> n;
	for (int i = 1 ; i < n ;i++) {
		int u , v , w;
		cin >> u >> v >> w;
		adj[u].push_back(ii(w , v));
		adj[v].push_back(ii(w , u));
	}
	DFS(1 , -1 , 0);	
	buildtable();
	int u , v , q;
	cin >> q;
	for (int i = 1 ; i <= q ; i++) {
		cin >> u >> v;
		ii res = LCA(u , v);
		cout << res.first << " " << res.second << '\n';
	}
	return 0;
}