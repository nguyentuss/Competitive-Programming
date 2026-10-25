#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define f first 
#define s second

vector<int> adj[MAX_N];
queue<int> q;
int a[MAX_N];
int res[MAX_N];
bool check[MAX_N];
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("counter.inp","r",stdin);
	freopen("counter.out","w",stdout);
	int n, m; cin >> n >> m;
	for (int i = 1 ; i <= m ; i++) {
		int u , v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
		if (a[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (check[u]) continue;
		check[u] = true;
		ans.push_back(u);
		res[u]++;
		for (auto v : adj[u]) {
			res[v]++;
			if (res[v] == a[v]) {
				q.push(v);
			}
		} 
	}
	cout << ans.size() << '\n';
	for (auto x : ans) cout << x << " ";
	return 0;
}