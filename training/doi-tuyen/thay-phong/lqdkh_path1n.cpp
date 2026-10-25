#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (5e4 + 7)
#define inf (int) (1e9 + 7)
#define ii pair<int ,int>
#define f first
#define s second
#pragma GCC optimize("Ofast")

int v[MAX_N];
int d[MAX_N];
vector<ii> adj[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1 ; i <= n ; i++) {
			adj[i].clear();
			d[i] = inf;
		}
		for (int i = 1 ; i <= n ; i++) { 
			cin >> v[i];
			if (i - 1 > 0) 
				adj[i].push_back(ii(i - 1 , 1));
			if (i + 1 <= n)
				adj[i].push_back(ii(i + 1 , 1));
			adj[i].push_back(ii(v[i] , 0));
		}
		priority_queue<ii , vector<ii> , greater<ii>> pq;
		pq.push(ii(0 , 1));
		d[1] = 0;
		while (!pq.empty()) {
			int u = pq.top().s;
			int w = pq.top().f;
			pq.pop();
			for (auto v : adj[u]) {
				if (d[v.f] > (w + v.s)) {
					d[v.f] = w + v.s;
					pq.push(ii(d[v.f] , v.f));
				}
			}
		}
		cout << d[n] << '\n';
	}
	return 0;
}