#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e4 + 7)

int n , m;
vector <int> adj[MAX_N] , a[MAX_N];
int level[MAX_N];
int aug[MAX_N][MAX_N] , resi[MAX_N][MAX_N];
int counted[MAX_N];

void BFS() {
	memset(level , 0 , sizeof(level));
	queue<int> q;
	level[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int u = q.top();
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
	if (u == (2*n)) return 2*s;
	int res =0;
	for (auto v : a[u]) {
		if (level[v] == level[u] + 1) {
			if (resi[u][v]) {
				res = DFS(v , min(s , resi[u][v]));
				if (res != 0) {
					resi[u][v] -= res;
					aug[u][v] += res;
					return res;
				}
			}
			else if (aug[u][v]) {
				res = DFS(v , min(s , aug[u][v]));
				if (res != 0) {
					resi[u][v] += res;
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

	memset(coutned , 0 , sizeof counted);
	cin >> n >> m;
	int u , v;
	while (cin >> u >> v) {
		a[u].push_back(v + n);
		counted[v + n] ++;
	}
	for (int i = 1 ; i <= n ; i ++) {
		if (a[i].size()
	}

	return 0;
}