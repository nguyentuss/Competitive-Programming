#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e3 + 7)
#define ii pair<int ,int>
#define f first
#define s second

int n;
int root[MAX_N];
int level[MAX_N];
vector<ii> tr_1 , tr_2;

void init() {
	for (int i = 0 ; i < MAX_N ; i ++) {
		root[i] = i;
		level[i] = 0;
	}
}

int find_root(int u) {
	if (u == root[u]) return u;
	else 
		return (root[u] = find_root(root[u]));
}

bool check(int u , int v) {
	u = find_root(u);
	v = find_root(v);
	return (u == v);
}

void unionset(int u , int v) {
	u = find_root(u);
	v = find_root(v);
	if (u != v) {
		if (level[u] < level[v]) swap(u , v);
		root[v] = u;
		if (level[u] == level[v]) level[u] ++;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	init();
	cin >> n;
	for (int i = 1 ; i < n ; i++) {
		int u , v ; cin >> u >> v;
		if (!check(u , v)) unionset(u , v);
		else tr_1.push_back(ii(u , v));
	}
	int ans = 0;
	for (int u = 1 ; u <= n ; u++) {
		for (int v = u + 1 ; v <= n ; v++) {
			if (!check(u , v)) {
				unionset(u , v);
				ans ++;
				tr_2.push_back(ii(u , v));
			}
		}
	}
	cout << ans << '\n';
	for (int i = 0 ; i < ans ; i++) 
		cout << tr_1[i].f << " " << tr_1[i].s << " " << tr_2[i].f << " " << tr_2[i].s << '\n';
	return 0;
}