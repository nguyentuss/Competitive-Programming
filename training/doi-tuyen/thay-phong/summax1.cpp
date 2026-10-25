#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)
#define int long long

int tr[MAX_N];
vector<int> adj[MAX_N];
int f[MAX_N];

void DFS(int u , int father) {
	for (auto v : adj[u]) {
		if (v == father) continue;
		f[v] = f[u] + tr[v];
		DFS(v , u);
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n ;i++) 
		cin >> tr[i];
	for (int i = 1 ; i <= n ; i++) {
		int x; cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	f[1] = tr[1];
	DFS(1 , -1);
	int ans = 0;
	for (int i = 1 ; i <= n ; i++) ans = max(ans , f[i]); 
	cout << ans;
	return 0;
}