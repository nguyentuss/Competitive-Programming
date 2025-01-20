#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

struct edge {
	int u , v , w;
};

int n , p;
vector<edge> adj;
int c[MAX_N];
int root[MAX_N];
bool D[MAX_N];

bool cmp(edge &a , edge &b) {
	return a.w < b.w;
}

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
	cin >> n >> p;
	for (int i = 1 ; i <= n ;i++) root[i] = i;
	int mini = INT_MAX;
	for (int i = 1 ; i <= n ;i++){ 
		cin >> c[i];
		mini = min(mini , c[i]);
	}
	for (int i = 1 ; i <= p ; i++) {
		int u , v , w; cin >> u >> v >> w;
		adj.push_back((edge) {u , v , 2*w + c[u] + c[v]});
	}
	sort(adj.begin() , adj.end() , cmp);
	for (int i = 0 ; i < p ; i ++) {
		if (!check(adj[i].u , adj[i].v)) {
			unionset(adj[i].u , adj[i].v);
			D[i] = true;
		}
	}
	int ans = 0;
	for (int i = 0 ; i < p ; i++) {
		if (D[i]) {
			ans += adj[i].w;
		}
	}
	cout << ans + mini;
	return 0;
}