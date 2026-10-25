#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)
#define inf (int) (1e9 + 7)
#define ii pair<int , int>

vector<ii> adj[MAX_N];
int d[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i < n ; i++) {
		int u , v; cin >> u >> v;
		adj[u].push_back(ii(v , 1));
		adj[v].push_back(ii(u , 1));
	}
	priority_queue<ii , vector<ii> , greater<ii>> pq;
	for (int i = 1 ; i <= n ; i++) d[i] = inf;
	pq.push(ii(0 , 1));
	d[1] = 0;
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		for (int i = 0 ; i < adj[u].size() ; i++) {
			int v = adj[u][i].first;
			int uv = adj[u][i].second;
			if (d[v] > d[u] + uv) {
				d[v] = d[u] + uv;
				pq.push(ii(d[v] , v));
			}
		}
	}
	int m; cin >> m;
	int ans = inf , pos = 0;
	for (int i = 1 ; i <= m ; i++) {
		int x; cin >> x;
		if (ans == d[x] && pos > x) pos = x;
		else if (ans > d[x]) {
			ans = d[x];
			pos = x;
		}
	}
	cout << pos;
	return 0;
}