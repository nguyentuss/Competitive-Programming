#include <bits/stdc++.h>

using namespace std;

int n , m , u , v , ans = 0;
int visited[101][101] = {{0}};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0 ; i < m ; i++) {
		cin >> u >> v;
		visited[u][v]++, visited[v][u]++;
	}
	int ans =0;
	for (int i = 1 ; i <= n ; i++) 
		for (int j = i + 1 ; j <= n ; j ++) {
			for (int k = j + 1 ; k <= n ; k++) 
				if (visited[i][j] == 1 && visited[j][k] == 1 && visited[k][i] == 1) 
					ans ++;
		}
	cout << ans;
	return 0;
}	