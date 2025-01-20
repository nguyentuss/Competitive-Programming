#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)
#define oo (int) (1e9 + 7)

map <int , bool> m;
vector <int> v;
vector <int> adj[MAX_N + 1];
int c[MAX_N + 1][MAX_N + 1] , resi[MAX_N + 1][MAX_N + 1] , aug[MAX_N + 1][MAX_N + 1];
int n , s , t;
vector <int> level(MAX_N + 1);
vector <int> counted(MAX_N + 1);

void init() {
	for (int i = 1 ; i <= MAX_N; i++) {
		adj[i].clear();
		for (int j = 1; j <= MAX_N; j++) {
			resi[i][j] = 0;
			aug[i][j] = 0;
		}
	}
	counted.assign(MAX_N , 0);
	return;
}

void BFS() {
	level.assign(MAX_N,0);
	level[s] = 1;
	queue <int> q;
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
			else if (aug[u][v]) {
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

bool check(int x) {
	init();
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1; j <= n ; j++) {
			if (c[i][j] <= x) {
				adj[i].push_back(j + n);
				adj[j + n].push_back(i);
				counted[j + n] ++;
				resi[i][j + n] = 1;
			}
		}
	}
	s = 0 , t = n + n + 1;
	for (int i = 1;  i <= n ; i++) {
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
		while (int tmp = DFS(s , oo))
			flow += tmp;
	}
	if (flow == n) return true;
	else return false;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cin >> c[i][j];
			if (m[c[i][j]] == false)
				v.push_back(c[i][j]); 
			m[c[i][j]] = true;
		}
	}
	sort(v.begin() , v.end());
//	for (auto e : v) cout << e << " ";
	int l = 0 , r = v.size() - 1;


	int ans = INT_MAX;
	while (l <= r) {
		int mid = (l + r)/2;
		if (check(v[mid])) {
			ans = min(ans , v[mid]);
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}