#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2*1e5 + 7)
#define ll long long
#define ii pair<ll , ll>
#define f first
#define s second


vector <int> adj[MAX_N];
ii f[MAX_N];

void DFS(ll u , ll father) {
	for (auto v : adj[u]) {
		if (v != father) {
			DFS(v , u);
			f[u].f += f[v].f + f[v].s;
			f[u].s += f[v].s;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i < n ; i++) {
		int v; cin >> v;
		adj[v].push_back(i + 1);
		f[i].f = f[i].s = 1;
	} 
	f[n].f = f[n].s = 1;
	DFS(1 , -1);
	for (int i = 1 ; i <= n ; i++) {
		cout << f[i].f << " ";
	}

	return 0;
}