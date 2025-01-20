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
	cin >> n;
	for (int i = 1 ; i <= n  ; i++) {
		root[i] = i;
		int w; cin >> w;
		adj.push_back({0 , i , w});
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j ++) {
			int c ; cin >> c;
			if (i == j) continue;
			//cout << c << " ";
			adj.push_back({i , j , c});
		}
	}
	sort(adj.begin() , adj.end() , cmp);
	int ans = 0;
	for (int i = 0 ; i < adj.size() ; i++) {
		if (!check(adj[i].u , adj[i].v)) {
			unionset(adj[i].u , adj[i].v);
			ans += adj[i].val;
			cout << adj[i].u << " " << adj[i].v << " " << adj[i].val << '\n';
		}
	}
	cout << ans;
	return 0;
}