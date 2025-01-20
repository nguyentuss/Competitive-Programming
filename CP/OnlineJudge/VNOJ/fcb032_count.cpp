#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (3*1e5 + 7)

struct edge {
	int val = 0;
	set <int> s;
};

edge F[MAX_N];
int id[MAX_N];
int n;
vector <int> adj[MAX_N];
int color[MAX_N];

void DFS(int u , int father) {
	for (auto v : adj[u]) {
		if (father == v) continue;
		DFS(v , u);
		int id1 = id[u] , id2 = id[v];
		if (F[id1].s.size() >= F[id2].s.size()) 
			F[id1].s.insert(F[id2].s.begin() , F[id2].s.end());
		else {
			id[u] = id[v];
			F[id2].s.insert(F[id1].s.begin() , F[id1].s.end());
		}
	}
	F[u].val = F[id[u]].s.size();	
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	cin >> n;
	for (int i = 0 ; i < n - 1; i++) {
		int u , v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1  ; i <= n ; i++) {
		id[i] = i;
		F[i].val = 1;
		cin >> color[i];
		F[i].s.insert(color[i]);
	}
	DFS(1 , -1);
	for (int i = 1 ; i <= n ; i++) {
		cout << F[i].val << " ";
	}
	return 0;
}