#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e4 + 7)
#define ii pair<int ,int>
#define f first
#define s second
#define inf (int) (1e9 + 7)

int n , m , a , b , s , t;
vector <ii> adj[MAX_N];
int d[MAX_N];

void dijkstra(int start) {
	priority_queue<ii , vector<ii> ,greater<ii>> pq;
	for (int i = 1 ; i <= n ; i++) d[i] = inf;
	d[start] = 0;
	pq.push(ii(0 , start));
	while (!pq.empty()) {
		int u = pq.top().s;
		int du = pq.top().f;
		pq.pop();
		for (auto v : adj[u]) {
			if (d[v.s] > du + v.f) {
				d[v.s] = du + v.f;
				pq.push(ii(d[v.s] , v.s));
			}
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("games.inp","r",stdin);
	//freopen("games.out","w",stdout);
	cin >> n >> m;
	cin >> s >> t >> a >> b;
	for (int i = 1 ; i <= m ; i++) {
		int u , v , w; cin >> u >> v >> w;
		adj[u].push_back(ii(w , v));
		adj[v].push_back(ii(w , u));
	}
	dijkstra(s);
	bool check1 = false;
	bool check2 = false;
	int ans1 = 0 , ans2 = 0;
	int res = inf;
	if (d[a] == inf) check1 = true;
	else ans1 = d[a];
	if (d[b] == inf) check2 = true;
	else ans2 = d[b];
	if (!check1) {
		dijkstra(b);
		ans1 += d[t];
		if (d[t] != inf)
			res = min(res , ans1);
	}
	if (!check2) {
		dijkstra(a);
		ans2 += d[t];
		if (d[t] != inf)
		res = min(res , ans2);
	}
	cout << (res == inf ? -1 : res);
	return 0;
}