#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (5e5 + 7)
#define ii pair<int ,int>
#define f first
#define s second
#define int long long

int n , k;
vector<ii> adj[MAX_N];
int v[MAX_N];
bool vis[MAX_N];
int child[MAX_N];
vector<int> res;
int ans = 0;
int sum[MAX_N];

void DFS(int u , int father) {
	for (auto v : adj[u]) {
		if (v.f != father) {
			sum[v.f] = v.s;
			child[v.f] = u;
			DFS(v.f , u);
		}
	}
}


void trace(int u) {
	int curr = u;
	while (vis[curr] == false && curr != -1) {
		vis[curr] = true;
		ans += sum[curr];
		curr = child[curr];
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	cin >> n >> k;
	memset(child , -1 , sizeof child);
	for (int i = 1 ; i < n ; i++) {
		int u , v , c; cin >> u >> v >> c;
		adj[u].push_back(ii(v , c));
		adj[v].push_back(ii(u , c));
	}
	for (int i = 1 ; i <= k ; i++) {
		cin >> v[i];
	}
	DFS(v[1] , -1);
	for (int i = 2 ; i <= k ; i++) {

		trace(v[i]);
	}
	cout << ans;
	return 0;
}