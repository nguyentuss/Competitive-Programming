#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

vector <vector <bool>> visited(5000 , vector <bool> (5000));
vector <long long> adj , h;
long long n , m , u , v;


int main(){
	//ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("chuyen03.inp","r",stdin);
	freopen("chuyen03.out","w",stdout);
	cin >> n >> m;
	for (int i = 0 ; i < m ; i++) {
		cin >> u >> v;
		visited[u][v] 	= true;
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j ++) {
			if (visited[i][j])
				adj.push_back(j);
			if (j == n) h.push_back((int) adj.size());
		}
	}
	cout << 0 << " ";
	for (int i = 0 ; i < (int) h.size() ; i++) cout << h[i] << " ";
	cout << '\n';
	for (int i = 0 ; i < (int) adj.size() ; i ++) cout << adj[i] << " ";


	return 0;
}