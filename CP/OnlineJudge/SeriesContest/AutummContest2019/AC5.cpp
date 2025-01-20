#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)

int n , m , s , t;
vector <int> a[MAX_N];
int level[MAX_N];
int aug[MAX_N][MAX_N] , resi[MAX_N][MAX_N];
int counted[MAX_N];

void init() {
	for (int i = 0 ; i <= 241 ; i++) {
		a[i].clear();
		for (int j = 0 ; j <= 241 ; j++) {
			resi[i][j] = 0;
			aug[i][j] = 0;
		}
	}
}

void BFS() {
	memset(level , 0 , sizeof(level));
	queue<int> q;
	level[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : a[u]) {
			if ((level[v] == 0) && (resi[u][v]||aug[u][v])) {
				level[v] = level[u] + 1;
				q.push(v);
			} 
		}
	}
	return;
}

int DFS(int u , int s) {
	if (u == t) return s;
	int res =0;
	for (auto v : a[u]) {
		if (level[v] == level[u] + 1) {
			if (resi[u][v]) {
				res = DFS(v , min(s , resi[u][v]));
				if (res != 0) {
					resi[u][v] -= res;
					aug[v][u] += res;
					return res;
				}
			}
			else if (aug[u][v]) {
				res = DFS(v , min(s , aug[u][v]));
				if (res != 0) {
					resi[v][u] += res;
					aug[u][v] -= res;
					return res;
				}
			}
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	int test; cin >> test;
	while (test--) {
		init();
		memset(counted , 0 , sizeof counted);
		int n;
		cin >> n;
		for (int i = 1 ; i <= n ; i++) {
			int u , v;
			cin >> u >> v;
			a[u].push_back(v + 120);
			a[v + 120].push_back(u);	
			counted[v + 120] ++;
			resi[u][v + 120] = 1;
		}
		s = 0 , t = 240 + 1;
		for (int i = 1 ; i <= 120 ; i ++) { 
			if (a[i].size()) {
				a[s].push_back(i);
				a[i].push_back(s);
				resi[s][i] = 1;
			}
		}

		for (int i = 1 ; i <= 120 ; i++) {
			if (counted[i + 120]) {
				a[i + 120].push_back(t);
				a[t].push_back(i + 120);
				resi[i + 120][t] = 1;
			}
		}

		int flow = 0;
		while (1) {
			BFS();
			if (level[t] == 0) break;	
			while (int x = DFS(s , 1e9 + 7))
				flow += x;
		}
		cout << flow << '\n';
	}
	return 0;
}