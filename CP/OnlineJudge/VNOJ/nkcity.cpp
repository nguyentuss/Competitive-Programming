#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1007)

struct edge {
	int u , v , val;
};

bool cmp(edge &a , edge &b) {
	return a.val < b.val;
}

int n , m;
int root[MAX_N];
vector<edge> adj;

int findroot(int u) {
	if (u == root[u]) return u;
	else {
		root[u] = findroot(root[u]);
		return root[u];
	}
}

void unionset(int u , int v) {
	int rootu = findroot(u);
	int rootv = findroot(v);
	if (rootu != rootv) {
		root[root[u]] = rootv;
	}
}

bool check(int u , int v) {
	int rootu = findroot(u);
	int rootv = findroot(v);
	return (rootu == rootv);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1 ; i <= n  ; i++) root[i] = i;
	for (int i = 1 ; i <= m ; i++) {
		int u , v , c; cin >> u >> v >> c;
		adj.push_back({u , v , c});
	}
	sort(adj.begin() , adj.end() , cmp);
	int ans = INT_MIN;
	for (int i = 0 ; i < adj.size() ; i++) {
		if (!check(adj[i].u , adj[i].v)) {
			unionset(adj[i].u , adj[i].v);
			//cout << adj[i].u << " " << adj[i].v << " " << adj[i].val << '\n';
			ans = max(ans , adj[i].val);
		}
	}
	cout << ans;
	return 0;
}