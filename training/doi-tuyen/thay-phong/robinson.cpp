#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

#define ii pair<int , int>
#define iii pair<int , ii>
#define f first
#define s second
#define MAX_N (int) (2007)
#define inf (int) (1e9 + 7)

struct seg {
	int u , t , h;
};

int n , m , k;
priority_queue<iii , vector<iii> , greater<iii>> pq;
vector<seg> adj[MAX_N];
int f[MAX_N][207];
int A , B;

void dijkstra(int start) {
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 0 ; j <= k ; j++) {
			f[i][j] = inf;
		}
	}
	f[start][0] = 0;
	pq.push(iii(0 , ii(0 , start)));
	while (!pq.empty()) {
		int u = pq.top().s.s;
		int value = pq.top().s.f;
		int time = pq.top().f;
		pq.pop();
		for (auto v : adj[u]) {
			if ((value + v.h) > k) continue;
			if (f[v.u][value + v.h] > (time + v.t)) {
				f[v.u][value + v.h] = time + v.t;
				pq.push(iii(f[v.u][value + v.h] , ii(value + v.h , v.u)));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	cin >> k >> n >> m;
	for (int i = 0 ; i < m ; i++) {
		int u , v , t , h; cin >> u >> v >> t >> h;
		adj[u].push_back({v , t , h});
		adj[v].push_back({u , t , h});
	}
	cin >> A >> B;
	dijkstra(A);
	int ans = INT_MAX;
	for (int i = 0 ; i < k ; i++) {
		ans = min(ans , f[B][i]);
	}
	if (ans == inf) cout << -1;
	else cout << ans;
	return 0;
}