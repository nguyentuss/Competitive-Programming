#include <bits/stdc++.h>

using namespace std;

#define MAX_N (ll) (1e5 + 7)
#define inf (ll) (1e11 + 7)
#define ll long long
#define f first
#define s second

ll n , m , a;
vector<int> adj[MAX_N];
ll f[MAX_N];

bool cmp(int u , int v) {
	return f[u] > f[v];
}

void DFS(int u , int father) {
	int cnt = 0;
	for (auto v : adj[u]) {
		if (father == v) continue;
		cnt ++;
		DFS(v , u);
	}
	if (!cnt) {
		f[u] = 0;
		return;
	}
	sort(adj[u].begin() , adj[u].end() , cmp);
	int dem = 0;
	for (auto e : adj[u]) {
		if (father == e) continue;
		dem++;
		f[u] = max(f[u] , f[e] + dem); 
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> a;
	for (ll i = 1 ; i < n ;i++) {
		ll u , v , w; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	DFS(a , -1);
	cout << f[a];
	return 0;
}