#include <bits/stdc++.h>

using namespace std;

#define MAX_N (ll) (1e5 + 7)
#define inf (ll) (1e11 + 7)
#define ii pair<ll ,ll>
#define ll long long
#define f first
#define s second

ll d1[MAX_N] , dn[MAX_N];
ll n , m;
vector<ii> adj[MAX_N];
ll d[MAX_N];

void dijkstra(ll start , ll num) {
	priority_queue<ii , vector<ii> , greater<ii>> pq;
	for (ll i = 1 ; i <= n ; i++) {
		d[i] = LLONG_MAX;
	}
	d[start] = 0LL;
	pq.push(ii(0LL , start));
	while (!pq.empty()) {
		ll u = pq.top().s;
		ll du = pq.top().f;
		pq.pop();
		if (du != d[u]) continue;
		for (ll i = 0 ; i < adj[u].size() ; i++) {
			ll v = adj[u][i].s;
			ll uv = adj[u][i].f;
			if (d[v] > du + uv) {
				d[v] = du + uv;
				pq.push(ii(d[v] , v));
			}
		}
	}
	if (!num) {
		for (ll i = 1 ; i <= n ; i++) 
			d1[i] = d[i];
	}
	else {
		for (ll i = 1 ; i <= n ; i++) {
			dn[i] = d[i];
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	ll k;
	cin >> n >> m >> k;
	for (ll i = 1 ; i <= m ;i++) {
		ll u , v , w; cin >> u >> v >> w;
		adj[u].push_back(ii(w , v));
	}
	dijkstra(1 , 0);
	dijkstra(n , 1);
	for (ll q = 1 ; q <= k ; q++) {
		ll time1 , timen; cin >> time1 >> timen;
		ll ans = LLONG_MAX;
		for (ll i = 1 ; i <= n ; i++) {
				if (d1[i] != LLONG_MAX && dn[i] != LLONG_MAX) {
						ans = min(ans , d1[i]*time1 + dn[i]*timen);
				}
		}
		cout << ans << '\n';
	}
	return 0;
}