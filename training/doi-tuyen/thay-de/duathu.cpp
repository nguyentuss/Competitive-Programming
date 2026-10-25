#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)
#define ii pair<int ,int>
#define inf (int) (1e9 + 7)
#define f first
#define s second

vector<ii> adj[MAX_N];
int a[MAX_N];
int f[MAX_N][MAX_N];
int vf[MAX_N][MAX_N];
int dist[MAX_N];
int s , t , k , g; 

void dijkstra() {
	priority_queue<ii , vector<ii> , greater<ii>> pq;
	memset(dist , inf , sizeof dist);
	pq.push(ii(0 , s));
	while (!pq.empty()) {
		int u = pq.top().f;
		int du = pq.top().s;
		pq.pop();
		for (auto v : adj[u]) {
			if (dist[v] > (dist[u] + vf[u][v])) 
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n , m; cin >> n >> m;
	cin >> s >> t >> k >> g;
	for (int i = 1 ; i <= g ; i ++) cin >> a[i];
	for (int i = 1 ; i <= m ; i++) {
		int u , v , c; cin >> u >> v >> c;
		adj[u].push_back(v);
		adj[v].push_back(u);
		f[u][v] = f[v][u] = c;
	}
	vf[a[1]][a[2]] = vf[a[2]][a[1]] = f[a[1]][a[2]];
	for (int i = 3 ; i <= g ; i++) {
		vf[a[i]][a[i - 1]] = vf[a[i - 1]][a[i]] = vf[a[i - 1]][a[i - 2]] + f[a[i]][a[i - 1]];
	}
	dijkstra();
	return 0;
}