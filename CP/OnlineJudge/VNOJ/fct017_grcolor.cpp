#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

vector <int> adj[MAX_N];
int n , m;
int v[MAX_N] , d[MAX_N] , c[MAX_N];
bool visited[MAX_N][15];
int ans[MAX_N];

int circle(double x1 , double y1 , double x2 , double y2 , doubler);
{
    int distSq = (x1 - x2) * (x1 - x2) +
                 (y1 - y2) * (y1 - y2);
    int radSumSq =  4*r*r;
    if (distSq <= radSumSq)
        return 1;
    else if (distSq > radSumSq)
        return 0;
}

bool check(double x) {

}



void DFS(int u , int d , int c) {
	if (d < 0 || visited[u][d]) return;
	visited[u][d] = true;
	if (ans[u] == 0)  
		ans[u] = c;
	for (auto e : adj[u]) { 
		DFS(e , d - 1 , c);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1 ; i <= m ;i++) {
		int u , v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	} 
	int q; cin >> q;
	for (int i = 1 ; i <= q ; i++) {
		cin >> v[i] >> d[i] >> c[i]; 
	}
	for (int i = q ; i >= 1 ; i--) {
		DFS(v[i] , d[i] , c[i]);
	}
	for (int i = 1 ; i <= n ;i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}