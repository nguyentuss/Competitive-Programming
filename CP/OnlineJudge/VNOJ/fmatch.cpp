#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)

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

	memset(counted , 0 , sizeof counted);
	cin >> n >> m;
	int u , v;
	while (cin >> u >> v) {
	//	cout << u << " " << v << '\n';
		a[u].push_back(v + n);
		a[v + n].push_back(u);	
		counted[v + n] ++;
		resi[u][v + n] = 1;
	}
	s = 0 , t = n + m + 1;
	for (int i = 1 ; i <= n ; i ++) { 
		if (a[i].size()) {
			a[s].push_back(i);
			a[i].push_back(s);
			resi[s][i] = 1;
		}
	}

	for (int i = 1 ; i <= m ; i++) {
		if (counted[i + n]) {
			a[i + n].push_back(t);
			a[t].push_back(i + n);
			resi[i + n][t] = 1;
		}
	}
	/*for (int i = s ; i <= t ; i++) {
		cout << i << ": ";
		for (auto v : a[i]) cout << v << " ";
		cout << '\n';
	}*/


	int flow = 0;
	while (1) {
		BFS();
		if (level[t] == 0) break;	
		while (int x = DFS(s , 1e9 + 7))
			flow += x;
	}
	cout << flow << '\n';
	for (int i = 0 ; i < (n + m + 2) ; i++) {
        for (int j = 0 ; j < (n + m + 2) ; j++) 
            if (aug[i][j] > 0 && j != s && i != t) cout << j << " " << i - n << '\n';
    }

	return 0;
}