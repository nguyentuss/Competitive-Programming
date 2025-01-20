#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)
#define inf (int) (1e9 + 7)

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
	s = 0 , t = 2*n + 1;
	int suma = 0 , sumb = 0;
	for (int i = 1 ; i <= n ; i++) {
		int x; cin >> x;
		a[s].push_back(i);
		a[i].push_back(s);
		a[i].push_back(i + n);
		a[i + n].push_back(i);
		resi[i][i + n] = inf;
		resi[s][i] = x;
		suma += x;
	}
	for (int i = 1 ; i <= n ; i++) {
		int x; cin >> x;
		a[i + n].push_back(t);
		a[t].push_back(i + n);
		resi[i + n][t] = x;
		sumb += x;
	}
	if (suma != sumb) {
		cout << "NO" ;
		return 0;
	}
	for (int i = 1 ; i <= m ; i++) {
		int u , v; cin >> u >> v;
		a[u].push_back(v + n);
		a[v + n].push_back(u);
		a[v].push_back(u + n);
		a[u + n].push_back(v);
		resi[u][v + n] = inf;
		resi[v][u + n] = inf;
	}
	int flow = 0;
	while (1) {
		BFS();
		if (level[t] == 0) break;	
		while (int x = DFS(s , 1e9 + 7))
			flow += x;
	}
	/*cout << flow << '\n';
	for (int i = 0 ; i < (n + m + 2) ; i++) {
        for (int j = 0 ; j < (n + m + 2) ; j++) 
            if (aug[i][j] > 0 && j != s && i != t) cout << j << " " << i - n << '\n';
    }*/
    if (flow != suma) cout << "NO";
    else {
    	cout << "YES" << '\n';
	    for (int i = 1 ; i <= n; i++) {
	    	for (int j = 1 ; j <= n; j++) {
	    		cout << aug[j + n][i] << " ";
	    	}
	    	cout << '\n';
	    }
	}
    //cout << aug[1][2] << " " << aug[2][1];

	return 0;
}