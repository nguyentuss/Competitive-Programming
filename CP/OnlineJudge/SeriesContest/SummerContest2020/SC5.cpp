#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define ii pair<ll ,ll>
#define inf (ll) (1e18)
#define s second
#define f first
#define ll long long

vector <ii> adj[MAX_N];
bool visited[MAX_N];
ll d[MAX_N];

void init() {
	for (int i = 0 ; i < MAX_N ; i++) {
		adj[i].clear();
		visited[i] = false;
	}
	return;
}

void dijkstra() {
	for (int i = 0 ; i < MAX_N ; i++) 
		d[i] = inf;
	priority_queue<ii , vector<ii> , greater<ii>> pq;
	d[0] = 0LL;
	pq.push(ii(0LL , 0));
	while (!pq.empty()) {
		int u = pq.top().s;
		ll du = pq.top().f;
		pq.pop();
		for (auto e : adj[u]) {
			int v = e.s;
			ll uv = e.f;
			if (d[v] > du + uv) {
				d[v] = du + uv;
				pq.push(ii(d[v] , v));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	//freopen("SC5.inp","r",stdin);
	//freopen("SC5.out","w",stdout);
	int t; cin >> t;
	while (t--) {
		init();
		int n , a , b; cin >> n >> a >> b;
		queue<int> q;
		visited[0] = true;
		q.push(0);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			ll v = u + 1;
			if (v <= n) {
				adj[u].push_back(ii(a , v));
				if (!visited[v]) {
					visited[v] = true;
					q.push(v);
				} 
			}
			v = 2*u;
			if (v <= n && v != u) {
				adj[u].push_back(ii(b , v));
				if (!visited[v]) {
					visited[v] = true;
					q.push(v);
				}
			}
		}
		dijkstra();
		cout << d[n] << '\n';
	}

	return 0;
}