#include <bits/stdc++.h>

using namespace std;
#define ii pair<int ,int>
#define f first
#define s second

int n;
unordered_map <int , vector<ii>> color;
vector <int> adj[300];
int level[307] , counted[307];
int resi[307][307] , aug[307][307];
int s , t;

void init() {
	for (int i = 0 ; i <= 2*n  ; i++) { 
		adj[i].clear();
		counted[i] = 0;
		level[i] = 0;
		for (int j = 0 ; j <= 2*n ; j ++) {
			resi[i][j] = resi[j][i] = 0;
			aug[i][j] = aug[j][i] = 0;
		}
	}
	return;
}

void BFS() {
	memset(level , 0 , sizeof(level));
	queue<int> q;
	level[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : adj[u]) {
			if (!level[v] && (resi[u][v]||aug[u][v])) {
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}
	return;
}

int DFS(int u , int s) {
	if (u == t) return s;
	int res = 0;
	for (auto v : adj[u]) {
		if (level[v] == level[u] + 1) {
			if (resi[u][v]) {
				res = DFS(v , min(s , resi[u][v]));
				if (res != 0) {
					resi[u][v] -= res;
					aug[v][u] += res;
					return res;
				}
			}
			else {
				res = DFS(v , min(s , aug[u][v]));
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

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);

	int test; cin >> test;
	while (test--) {
		cin >> n ;
		int ans = 0;
		color.clear();
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= n ;j++) {
				int x;
				cin >> x;
				color[x].push_back(ii(i , j));
			}
		}
		for (int cl = -n ; cl <= n ; cl++) {
			if (color[cl].size()) {
				init();
				for (auto e : color[cl]) {
					int u = e.f , v = e.s;
					adj[u].push_back(v + n);
					adj[v + n].push_back(u);
					counted[v + n] ++;
					resi[u][v + n] = 1;
				}
				s = 0 , t = 2*n + 1;
				for (int i = 1 ; i <= n ; i++) {
					if (adj[i].size()) {
						adj[s].push_back(i);
						adj[i].push_back(s);
						resi[s][i] = 1;
					}
				}
				for (int i = 1 ; i <= n ; i++) {
					if (counted[i + n]) {
						adj[i + n].push_back(t);
						adj[t].push_back(i + n);
						resi[i + n][t] = 1;
					}
				}
				int flow = 0;
				while (1) {
					BFS();
					if (level[t] == 0) break;	
					while (int x = DFS(s , 1e9 + 7))
						flow += x;
				}
				ans += flow;
			}
		}
		cout << n*n - ans << '\n';
	}

	return 0;
}