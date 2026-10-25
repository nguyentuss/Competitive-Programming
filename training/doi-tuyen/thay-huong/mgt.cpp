#include <bits/stdc++.h>

using namespace std;

struct segment {
	long long  u , v , w;
};

struct quangcute {
	long long  u , v;
};

bool cmp(segment &a , segment &b) {
	return a.w < b.w;
}

vector <segment> adj;
bool zero[2000][2000];
bool temp[2000][2000];
long long  n , m ,u , v , w;
vector <long long > root(2000);
vector <segment> go;

void init() {
	for (long long  i = 1 ; i <= n ; i++) 
		root[i] = i;
	return;
}

long long  findroot(long long  u) {
	if (root[u] == u) return u;
	else {
		root[u] = findroot(root[u]);
	}
	return root[u];
}

void unionset(long long  u , long long  v) {
	long long  rootu = findroot(u);
	long long  rootv = findroot(v);
	if (rootu != rootv) 
		root[root[u]] = rootv;
	return;
}

bool checking(long long  u , long long  v) {
	long long  rootu = findroot(u);
	long long  rootv = findroot(v);
	if (rootu == rootv) return true;
	return false;
}

int  main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("mgt.inp","r",stdin);
	freopen("mgt.out","w",stdout);
	cin >> n >> m;
	for (long long  i = 0 ; i < m ; i++) {
		cin >> u >> v;
		adj.push_back({u , v , 0});
		zero[u][v] = zero[v][u] = true;
		temp[u][v] = temp[v][u] = true;
	}
	for (long long  i = 1 ; i <= n ; i++) {
		for (long long  j = 1 ; j <= n ; j ++) {
			cin >> w;
			if (temp[i][j] == false && temp[j][i] == false){ 
				adj.push_back({i , j , w});
				temp[i][j] = true;
				temp[j][i] = true;
			}
		}
	}
	init();
	sort(adj.begin() + m , adj.end() , cmp);
	sort(adj.begin() , adj.begin() + m , cmp);
	for (long long  i = 0 ; i < (long long ) adj.size() ; i++) {
		if (!checking(adj[i].u , adj[i].v)) {
			unionset(adj[i].u , adj[i].v);
			go.push_back({adj[i].u , adj[i].v , adj[i].w});
		}
	}
	long long  ans = 0;
	vector <quangcute> res;
	for (long long  i = 0 ; i < (long long ) go.size() ; i++) {
		ans += go[i].w;
		if (!zero[go[i].u][go[i].v] && !zero[go[i].v][go[i].u]) 
			res.push_back({go[i].u , go[i].v});
	}
	cout << ans;
	cout << '\n';
	for (long long  i = 0 ; i < (long long ) res.size() ; i++) 
		cout << res[i].u << " " << res[i].v << '\n';

	return 0;
}