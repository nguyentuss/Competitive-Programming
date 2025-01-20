#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (10007)

int k , n , x;
vector <int> adj[MAX_N];
int f[MAX_N];
int ans =0;
vector <bool> cnt(MAX_N , false);

void DFS(int u , int father) {
	f[u] = 1;
	for (auto v : adj[u]) {
		if (v == father) continue;
		DFS(v , u);
		f[u] += f[v];
	}
	if (f[u] >= k) {
		f[u] = 0;
		cnt[u] = true;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> k >> n ;
	for (int i = 2 ; i <= n; i++) {
		cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	//for (int i = 1 ; i <= n ; i++) 
	//	f[i] = 1;
	DFS(1 , -1);
	for (int i = 1 ; i <= n; i++) 
		if (cnt[i]) ans++;
	cout << ans;
	return 0;
}