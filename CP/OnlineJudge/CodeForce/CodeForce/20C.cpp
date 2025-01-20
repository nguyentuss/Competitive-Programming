#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define inf (int) (1e9 +7)
#define ii pair<int ,int>
#define f first
#define s second

int n , m;
vector<ii> adj[MAX_N];
int dist[MAX_N];
int trace[MAX_N];
bool visited[MAX_N];

void dijkstra() {
	for (int i = 1 ; i < MAX_N ; i++) dist[i] = inf;
	priority_queue<ii , vector<ii> , greater<ii>> pq;
	pq.push(ii(0 , 1));
	dist[1] = 0;
	while (!pq.empty()) {
		int u = pq.top().s;
		pq.pop();
		if (visited[u]) continue;
		visited[u] = 1;
		for (int i = 0 ; i < adj[u].size() ; i++) {
			int v = adj[u][i].s;
			int uv = adj[u][i].f;
			if (dist[v] > dist[u] + uv) {
				dist[v] = dist[u] + uv;
				trace[v] = u;
				pq.push(ii(dist[v] , v));
			}
		}
	} 
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1 ; i <= m ; i++) {
		int u , v , w; cin >> u >> v >> w;
		adj[u].push_back(ii(w , v));
		adj[v].push_back(ii(w , u));
	}
	dijkstra();
	if (dist[n] == inf) {
		cout << -1;
		return 0;
	}
	trace[1] = -1;
	vector<int> v;
	v.push_back(n);
	int pos = n;
	while (trace[pos] != -1) {
		v.push_back(trace[pos]);
		pos = trace[pos];
	}
	reverse(v.begin() , v.end());
	for (auto e : v) cout << e << " "; 

	return 0;
}