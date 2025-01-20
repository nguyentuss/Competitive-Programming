#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e4 + 7)

int n , m;
int root[MAX_N];

void init() {
	for (int i = 1 ; i <= 10000 ; i++) {
		root[i] = i;
		len[i] = 1;
	}
}
 
int findroot(int x) {
	if (x == root[x]) return x;
	else {
		root[x] = findroot(root[x]);
		return root[x];
	}
}
 
void unionset(int x , int y) {
	int u = findroot(x);
	int v = findroot(y);
	if (u != v) {
		if (len[u] < len[v]) swap(u , v);
		root[v] = u;
		//if (len[u] == len[v]) len[u] += len[v];
		len[u] += len[v];
	}
}
bool checking(int u , int v) {
	int rootu = findroot(u);
	int rootv = findroot(v);
	if (rootu == rootv) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	int t; cin >> t;
	while (t--) {
		init();
		cin >> n >> m;
		for (int i = 0 ; i < m ; i++) {
			int u , v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			unionset(u , v);
		}
		for (int i = 1 ; i <= n ;i++) {
			cout << root[i] << " ";
		}
	}


	return 0;
}