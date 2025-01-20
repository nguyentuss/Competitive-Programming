#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)
#define oo (int) (1e9 + 7)

int n , m , s , t;
vector <int> a[MAX_N];
int level[MAX_N];
int aug[MAX_N][MAX_N] , resi[MAX_N][MAX_N];
int counted[MAX_N];

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
	cin >> n;
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[1].push_back(i + 1);
		a[i + 1].push_back(1);
		resi[1][i + 1] = x;
	}
	for (int i = 1 ; i <= n; i++) {
		cin >> x;
		a[i + 1].push_back(n + 2);
		a[n + 2].push_back(i + 1);
		resi[i + 1][n + 2] = x;
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j ++) {
			cin >> x;
			a[i + 1].push_back(j + 1);
			a[j + 1].push_back(i + 1);
			resi[i + 1][j + 1] = x;
		}
	}
	s = 1 , t = n + 2;
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