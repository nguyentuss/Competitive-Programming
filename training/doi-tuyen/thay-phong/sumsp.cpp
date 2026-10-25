#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define MAX_NUM (int) (2e6 + 7)
#define ii pair<int ,int>
#define int long long
#pragma GCC optimize("Ofast")

struct edge {
	int u , v , w;
};

int n , m , cnt[MAX_NUM] , POW[40];
int root[MAX_N] , f[MAX_N];
int len[MAX_N];
vector<ii> adj[MAX_N];
vector<edge> a;
vector<edge> last;
vector<ii> mul;

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

bool check(int u , int v) {
	u = findroot(u);
	v = findroot(v);
	return (u == v);
}

void unionset(int u , int v) {
	u = findroot(u);
	v = findroot(v);
	if (u != v) {
		if (len[u] < len[v]) swap(u , v);
		root[v] = u;
		if (len[u] == len[v]) len[u] += len[v];
	}
}

void DFS(int u , int father) {
	for (auto v : adj[u]) {
		if (v.first != father) {
			DFS(v.first , u);
			f[u] += f[v.first] + 1;
			mul.push_back(ii((f[v.first] + 1)*(n - f[v.first] - 1) , v.second));
		}
	}
}

void process(int x , int c) {
	for (int i = 39 ; i >= 0 ; i--) {
		int dem = 0;
		while (x >= POW[i]) {
			x -= POW[i];
			dem++;
		}
		cnt[i+c] += dem;
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		root[i] = i;	
		len[i] = 1;
	}
	for (int i = 1 ; i <= m ; i++) {
		int u , v , w; cin >> u >> v >> w;
		a.push_back({u , v , w});
	}
	sort(a.begin() , a.end() , cmp);
	for (auto x : a) {
		if (!check(x.u , x.v)) {
			unionset(x.u , x.v);
			adj[x.u].push_back(ii(x.v , x.w));
			adj[x.v].push_back(ii(x.u , x.w));
			last.push_back({x.u , x.v , x.w});
		}
	}
	DFS(1 , -1);
	POW[0] = 1;
	set<int , greater<int>> s;
	map<int , int> pos;
	pos[1] = 0;
	for (int i = 1 ; i <= 39 ; i++) {
		POW[i] = POW[i - 1]*2;
		s.insert(POW[i]);
		pos[POW[i]] = i;
	}
	for (auto x : mul){
		process(x.first , x.second);
	}
	for (int i = 0 ; i < MAX_NUM ; i++) {
		if (cnt[i] > 0) {
			while (1) {
				auto it = s.lower_bound(cnt[i]);
				if (it == s.end()) break;
				cnt[i] -= *it;
				cnt[i + pos[*it]] ++; 
			}
		}
	}
	int lastone = 0;
	for (int i = 0 ; i < MAX_NUM ; i++) {
		if (cnt[i]) {
			lastone = i;
		}
	}
	for (int i = lastone ; i >= 0 ; i--) {
		cout << cnt[i];
	}
	return 0;
}