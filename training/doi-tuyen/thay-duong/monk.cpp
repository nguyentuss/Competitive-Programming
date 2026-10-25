#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e4 + 7)
#define inf (int) (1e9 + 7)
#define ii pair<int , int>
#define f first
#define s second

int n , m;
vector <ii> adj[MAX_N];
int d[MAX_N];

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
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("monk.inp","r",stdin);
	freopen("monk.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		for (int i = 1 ; i < MAX_N ; i++) 
			adj[i].clear();
		cin >> n >> m;
		for (int i = 1 ; i <= m ; i++) {
			int u , v; cin >> u >> v;
			adj[u].push_back(ii(1 , v));
			adj[v].push_back(ii(1 , u));
		}
		dijkstra();
		cout << d[n] << '\n';
	}
	return 0;
}