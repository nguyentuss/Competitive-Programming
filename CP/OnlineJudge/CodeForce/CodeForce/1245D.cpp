#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e3 + 7)
#define int long long
struct coordinates {
	int x , y;
};

struct edges {
	int u , v , c;
};

struct connect {
	int u , v;
};


coordinates pos[MAX_N];
int c[MAX_N];
int k[MAX_N];
int root[MAX_N];
vector<edges> adj;
vector<edges> trace;
int level[MAX_N];

void init() {
	for (int i = 0 ; i < MAX_N ; i++) {
		root[i] = i;
		level[i] = 0;
	}
}

int manhattan(coordinates X , coordinates Y) {
	return (abs(X.x - Y.x) + abs(X.y - Y.y));
}

bool cmp(edges &a , edges &b) {
	return (a.c < b.c);
}

int findroot(int u) {
	if (u == root[u]) return u;
	else return root[u] = findroot(root[u]);
}

void unionset(int u , int v) {
	u = findroot(u);
	v = findroot(v);
	if (u != v) {
		if (level[u] < level[v]) swap(u , v);
		root[v] = u;
		if (level[u] == level[v]) level[u] ++;
	}
}

bool check(int u , int v) {
	u = findroot(u);
	v = findroot(v);
	return (u != v);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	init();
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> pos[i].x >> pos[i].y;
	}
	for (int i = 1 ; i <= n ; i++) {
		cin >> c[i];
		adj.push_back({0 , i , c[i]});
	}
	for (int i = 1 ; i <= n; i++) 
		cin >> k[i];
	for (int i = 1 ; i < n ; i++) {
		for (int j = i + 1 ; j <= n ; j++) {
			adj.push_back({i , j , manhattan(pos[i] , pos[j])*(k[i] + k[j])});
		}
	}
	sort(adj.begin() , adj.end() , cmp);
	for (auto nodes : adj) {
		if (check(nodes.u , nodes.v)) {
			unionset(nodes.u , nodes.v);
			trace.push_back(nodes);
		} 
	}
	int ans = 0;
	vector<int> powerstation;
	vector<connect> roads;
	for (int i = 0 ; i < trace.size() ; i++) {
		int u = trace[i].u , v = trace[i].v , w = trace[i].c;
		if (u == 0 || v == 0) {
			powerstation.push_back(!u?v:u);
		}
		else {
			roads.push_back({u , v});
		}
		ans += w;
	}
	cout << ans << '\n';
	cout << powerstation.size() << '\n';
	for (auto e : powerstation) cout << e << " ";
	cout << '\n';
	cout << roads.size() << '\n';
	for (auto e : roads) cout << e.u << " " << e.v << '\n';
	return 0;
}