#include <bits/stdc++.h>

using namespace std;

#define MAX_N (long long) (2*1e5 + 7) 
#define ii pair<long long , long long>

struct edge {
	long long u , v , w , id;
	bool operator <(const edge &other) const {
		return w < other.w;
	}
};

vector <ii> adj[MAX_N];
vector <edge> myEdge;
vector <bool> checkEdge(MAX_N + 7);
vector <long long> root(MAX_N + 7);
long long P[MAX_N + 7][22] , F[MAX_N + 7][22] , H[MAX_N + 7];
long long n , m;

void init() {
	for (long long i = 1 ; i <= n ; i++) 
		root[i] = i;
	for (long long i = 1 ; i <= n ;i++) {
		for (long long k = 0 ; k <= 21 ; k++) {
			P[i][k] = -1;
			F[i][k] = -1;
		}
	}
}
long long findroot(long long u) {
	if (u == root[u]) return u;
	else {
		root[u] = findroot(root[u]);
		return root[u];
	}
}

void unionset(long long u , long long v) {
	long long rootu = findroot(u);
	long long rootv = findroot(v);
	if (rootu != rootv) {
		root[root[u]] = rootv;
	}
	return;
}

bool check(long long u , long long v) {
	long long rootu = findroot(u);
	long long rootv = findroot(v);
	if (rootu != rootv) return false;
	return true;
}

void kruskal() {
	for (long long i = 0 ; i < m ; i++) {
		long long u = myEdge[i].u , v = myEdge[i].v;
		if (!check(u , v)) {
			unionset(u , v);
			checkEdge[i] = true;
		}
	}
}

void DFS(long long u , long long prev , long long weight) {
	P[u][0] = prev;
	F[u][0] = weight;
	for (long long i = 0 ; i < adj[u].size() ; i++) {
		long long v = adj[u][i].second;
		if (v == prev) continue;
		H[v] = H[u] + 1;
		DFS(v , u , adj[u][i].first);
	}
	return;
}

void initlca() {
	for (long long k = 1 ; k <= 21 ; k++) {
		for (long long i = 1 ; i <= n ; i++) {
			if (P[i][k - 1] != -1){
				P[i][k] = P[P[i][k - 1]][k - 1];
				F[i][k] = max(F[i][k - 1] , F[P[i][k - 1]][k - 1]);
			}
		}
	}
}

long long lca(long long u , long long v) {
	long long maxEdge = 0;
	if (H[u] < H[v]) 
		swap(u , v);
	while (H[u] > H[v]) {
		for (long long k = 21 ; k >= 0 ; k--) {
			if (P[u][k] != -1 && H[P[u][k]] >= H[v]) {
				maxEdge = max(maxEdge , F[u][k]);
				u = P[u][k];
				break;
			}
		}
	}
	if (u == v) return maxEdge;
	while (true) {
		bool found = false;
		for (long long k = 21 ; k >= 0 ; k --) {
			if (P[u][k] != -1 && P[v][k] != -1 && P[u][k] != P[v][k]) {
				maxEdge = max(maxEdge , F[u][k]);
				maxEdge = max(maxEdge , F[v][k]);
				u = P[u][k];
				v = P[v][k];
				found = true;
			}
		}
		if (!found) break;
	}
	maxEdge = max(maxEdge , F[u][0]);
	maxEdge = max(maxEdge , F[v][0]);
	return maxEdge;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (long long i = 0 ; i < m ; i ++) {
		long long u , v , w; cin >> u >> v >> w;
		myEdge.push_back((edge) {u , v , w , i});
	}
	sort(myEdge.begin() , myEdge.end());
	init();
	
	kruskal();
	long long total = 0;
	for (long long i = 0 ; i < m ;i++) {
		if (checkEdge[i]) {
			long long u = myEdge[i].u , v = myEdge[i].v , w = myEdge[i].w;
//			cout << u << " " << v << " " << w << '\n';
			adj[u].push_back(ii(w , v));
			adj[v].push_back(ii(w , u));
			total += w;
		}
	}
	DFS(1 , -1 , 0);
	initlca();
	vector <ii> ans; 
	for (long long i = 0 ; i < m ; i ++) {
		long long u = myEdge[i].u , v = myEdge[i].v  , w = myEdge[i].w  , id = myEdge[i].id;
		ans.push_back(ii(id , total - lca(u , v) + w));
	}
	sort(ans.begin() , ans.end());
	for (ii e : ans) {
		cout << e.second << '\n';
	}

	return 0;
}