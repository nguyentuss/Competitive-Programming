#include <bits/stdc++.h>

using namespace std;

#define inf (int) (1e9 + 7)

int C[407][407] , n , m; 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			C[i][j] = inf;
		}
	}
	for (int i = 1 ; i <= n ; i++) C[i][i] = 0;
	for (int i = 1 ; i <= m ; i++) {
		int u , v , w; cin >> u >> v >> w;
		C[u][v] = min(C[u][v] , w);
	}
	for (int k = 1 ; k <= n ; k++) {
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= n ; j++) {
				if (C[i][k] != inf && C[k][j] != inf) 
					C[i][j] = min(C[i][j] , C[i][k] + C[k][j]);
			}
		}
	}
	int q; cin >> q;
	for (int i = 1 ; i <= q ; i++) {
		int s , t; cin >> s >> t;
		cout << (C[s][t] == inf ? -1 : C[s][t]) << '\n';
	}
	return 0;
}