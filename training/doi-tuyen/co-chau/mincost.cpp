#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (207)
#define oo (int) (1e9 + 7)
#define ii pair<int , int>

int n , m , u , v , c , s , t;
int aug[MAX_N][MAX_N] , resi[MAX_N][MAX_N];
vector <int> adj[MAX_N];
int level[MAX_N];
map<int , vector<ii>> cnt;
map<int , int> pos;

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

int DFS(int u , int mini , int a1 , int a2) {
	if (u == t) {
        
        cout << a1 << " " << a2 << '\n';
        return mini;
    }
	int res = 0;
	for (auto v : adj[u]) {
		if (level[v] == level[u] + 1) {
			if (resi[u][v]) {
                int tmp1 = a1 , tmp2 = a2;
                if (mini > resi[u][v]) {
                    tmp1 = u , tmp2 = v;
                }
				res = DFS(v , min(mini , resi[u][v]) , tmp1 , tmp2);
				if (res != 0) {
					resi[u][v] -= res;
					aug[v][u] += res;
					return res;
				}
			}
			else if (aug[u][v]) {
                int tmp1 = a1 , tmp2 = a2;
                if (mini > aug[u][v]) {
                    tmp1 = u , tmp2 = v;
                }
				res = DFS(v , min(mini , aug[u][v]) , tmp1 , tmp2);
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
	cin >> n >> m >> s >> t;
    vector<ii> tmp;
	for (int i = 1 ; i <= m ; i++) {
        cin >> u >> v >> c;
        tmp.push_back(ii(u , v));
		adj[u].push_back(v);
		adj[v].push_back(u);
		resi[u][v] = resi[v][u] = c;
        cnt[c].push_back(ii(u , v));
	}
	int flow = 0;

	while (1) {
		BFS();
		if (level[t] == 0) break;
		while (int x = DFS(s , oo , oo , oo)) {
			flow += x;
		}
	}
	cout << flow << '\n';
    // for (int i = 1 ; i <= n; i++) {
    //     for (int j = 1 ; j <= n ; j ++) {
    //         cout << aug[i][j] << " ";
    //         //if (aug[i][j] > 0 && j != s && i != t) cout << i << " " << j << '\n';
    //     }
    //     cout << '\n';
    // }
    for (auto x : tmp) {
        int u = x.first, v = x.second;
        if (!resi[u][v] && v != s && u != t) {
            cout << u << " " << v << '\n';
        }
    }
	return 0;
}