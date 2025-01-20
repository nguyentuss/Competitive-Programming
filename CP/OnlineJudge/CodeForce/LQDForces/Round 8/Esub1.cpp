//E subtask 1

#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2*1e5 + 7)

int a[MAX_N];
vector<int> adj[MAX_N];
int cnt[MAX_N];

void DFS(int u , int father , int gcd , int root) {
	for (auto v : adj[u]) {
		if (v != father) {
			int newgcd = __gcd(gcd, a[v]);
			if (root < v) cnt[newgcd]++;
			DFS(v , u , newgcd , root);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int n; cin >> n;
	for (int i = 1 ; i <= n ;i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 1 ; i < n ;i++) {
		int u , v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1 ; i <= n ; i++) {
		DFS(i , -1 , a[i] , i);
	}
	for (int i = 0 ; i < MAX_N ; i++) {
		if (cnt[i]) {
			cout << i << " " << cnt[i] << '\n';
		}
	}
	return 0;
}