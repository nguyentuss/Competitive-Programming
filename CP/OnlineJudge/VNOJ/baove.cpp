#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (5005)
#define oo (int) (1e9 + 7)

int n , u , v , c , s , t;
int aug[MAX_N][MAX_N] , resi[MAX_N][MAX_N];
vector <int> adj[MAX_N];
int level[MAX_N];

void BFS() {	
	memset(level , 0 , sizeof (level));
	queue <int> q;
	level[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : adj[u]) {
			if (level[v] == 0 && (resi[u][v]||aug[u][v])) {
				level[v] = level[u] + 1;
				q.push(v); 
			}
		}
	}
	return;
}

int DFS(int u , int m) {
	if (u == t) return m;
	int res = 0;
	for (auto v : adj[u]) {
		if (level[v] == level[u] + 1) {
			if (resi[u][v]) {
				res = DFS(v , min(m , resi[u][v]));
				if (res != 0) {
					resi[u][v] -= res;
					aug[v][u] += res;
					return res;
				}
			}
			else if (aug[u][v]) {
				res = DFS(v , min(m , aug[u][v]));
				if (res != 0) {
					aug[u][v] -= res;
					resi[v][u] += res;
					return res;
				}
			}
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	cin >> n;
	s = n , t = 1;
	while (cin >> u >> v >> c) {
		if (u == t) continue;
		adj[u].push_back(v);
		adj[v].push_back(u);
		resi[u][v] += c;
	}
	int flow = 0;
	while (1) {
		BFS();
		if (level[t] == 0) break;
		while (int x = DFS(s , oo)) {
			flow += x;
		}
	}
	cout << flow;


	return 0;
}