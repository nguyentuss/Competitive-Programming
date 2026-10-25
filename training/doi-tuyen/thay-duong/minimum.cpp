#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (50007)
#define ii pair<int ,int>
#define inf (int) (1e9 + 7)
#define f first
#define s second

int p[MAX_N];
int d[MAX_N];
vector <ii> adj[MAX_N];
int n;

void dijkstra() {
	priority_queue<ii , vector<ii> , greater<ii>> pq;
	for (int i = 1 ; i <= n ; i++) d[i] = inf; 
	pq.push(ii(0 , 1));
	d[1] = 0;
	while (!pq.empty()) {
		int u = pq.top().s;
		int du = pq.top().f;
		pq.pop();
		for (int i = 0 ; i < adj[u].size() ; i++) {
			int v = adj[u][i].s;
			int uv = adj[u][i].f;
			if (d[v] > du + uv) {
				d[v] = du + uv;
				pq.push(ii(d[v] , v));
			} 
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("minimum.inp","r",stdin);
	freopen("minimum.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		for (int i = 1 ; i < MAX_N ; i++) adj[i].clear();
		cin >> n;
		for (int i = 1 ; i <= n ; i++) cin >> p[i];
		for (int i = 1 ; i <= n; i++) {
			if (i - 1 > 0) adj[i].push_back(ii(1 , i - 1));
			if (i + 1 <= n) adj[i].push_back(ii(1 , i + 1));
			adj[i].push_back(ii(0 , p[i])); 
		}
		dijkstra();
		cout << d[n] << '\n';
	}
	return 0;
}