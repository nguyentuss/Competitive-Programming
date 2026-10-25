#include <bits/stdc++.h>

using namespace std;

struct edge {
	int v , w , c;
};

#define MAX_N (int) (1e5 + 7)
#define inf (int) (1e9 + 7)
#define ii pair<int , int>
#define iii pair<int , ii>
#define f first 
#define s second

int n , m; 
vector <edge> adj[MAX_N];
int d[MAX_N];

void dijkstra() {
	for (int i = 0 ; i < MAX_N ; i++) 
		d[i] = inf;
	priority_queue<iii , vector<iii> , greater<iii>> pq;
	pq.push(iii(0 , ii(-1 , 1)));
	d[1] = 0;
	while (!pq.empty()) {
		int u = pq.top().s.s;
		int color = pq.top().s.f;
		pq.pop();
		for (auto x : adj[u]) {
			int v = x.v , w = x.w , c = x.c;
			if ((d[v] > (d[u] + w)) && (((c && !color) || (!c && color)) || (color == -1))) {
				d[v] = d[u] + w;
				pq.push(iii(d[v] , ii(c , v)));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	cin >> n >> m;
	for (int i = 1 ; i <= m ; i++) {
		int u , v , w , c; cin >> u >> v >> w >> c;
		adj[u].push_back({v , w , c});
		adj[v].push_back({u , w , c});
	}
	dijkstra();
	if (d[n] == inf) cout << -1;
	else cout << d[n];
	return 0;
}