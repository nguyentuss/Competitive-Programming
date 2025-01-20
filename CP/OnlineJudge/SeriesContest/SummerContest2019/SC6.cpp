#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)
struct ele {
	int l , r;
};

int n , m , s , e , k;
ele a[MAX_N];
vector <int> adj[MAX_N];
bool visited[MAX_N];

void DFS(int u , int key) {
	visited[u] = true;
	for (auto v : adj[u]) {
		if (!visited[v] && a[v].l <= key && key <= a[v].r) 
			DFS(v , key);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		vector <int> save;
		cin >> n >> m >> s >> e >> k;
		for (int i = 1 ; i <= n ; i++) {
			cin >> a[i].l >> a[i].r;
			save.push_back(a[i].l - 1);
			save.push_back(a[i].r);
		}
		save.push_back(0) , save.push_back(k);
		sort(save.begin() , save.end());
		for (auto e : save) cout << e << " ";	
		for (int i = 1 ; i <= n ; i++) 
			adj[i].clear();
		for (int i = 1 ; i <= m ; i++) {
			int u , v; cin >> u >> v;
			adj[u].push_back(v);
		}
		int ans = 0;
		for (int i = 1 ; i < save.size() ; i++) {
			memset(visited , false , sizeof(visited));
			DFS(s , save[i]);
			if (visited[e]) {
				cout << save[i] << " " << save[i - 1] << '\n';
				ans += save[i] - save[i - 1];
			}
		}
		cout << ans << '\n';
	}
	return 0; 
}