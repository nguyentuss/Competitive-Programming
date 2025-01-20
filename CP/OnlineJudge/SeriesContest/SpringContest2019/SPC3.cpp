#include <bits/stdc++.h>

using namespace std;

#define mod (int) (1e9 + 7)

int n;
vector <int> adj[106];
vector <int> val(106);
vector <bool> visited(106) , vnum(106);
vector <long long> f(106);
vector <long long> POW(106);
bitset <100> s;

void init() {
	for (int i = 0 ; i <= 102 ; i++) {
		adj[i].clear();
		val[i] = 0;
	}
}

void DFS(int u) {
	visited[u] = true;
	f[u] = 1;
	for (auto e : adj[u]) {
		if (!visited[e] && !vnum[e]) {
			DFS(e);
			f[u] = (f[u]%mod*(f[e] + 1)%mod)%mod;
		}
	}
	return;
}

void initpro() {
	for (int i = 1 ; i <= n ; i++) {
		visited[i] = false;
		f[i] = 1;
	}
	return;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int t; cin >> t;
	POW[0] = 1;
	for (int i = 1 ; i <= 31 ; i++) POW[i] = POW[i - 1]*2;
	while (t--) {
		cin >> n;
		init();
		for (int i = 2 ; i <= n ; i++) {
			int x; cin >> x;
			adj[x].push_back(i);
			adj[i].push_back(x);		
		}
		for (int i = 1 ; i <= n ; i++) 
			cin >> val[i];
		long long total = 0 , tmp = 0;
		for (int bit = 0 ; bit <= 31 ; bit++) {
			for (int i = 1 ; i <= n ; i ++) vnum[i] = false;
			tmp = 0;
			for (int i = 1; i <= n ; i++) {
				s = val[i];
				if (s[bit]) {
					initpro();
					DFS(i);
					vnum[i] = true;
					tmp += f[i];
				}
			}
			total = (total%mod + POW[bit]%mod*tmp%mod)%mod;
		}
		cout << total << '\n';
	}
	return 0;
}