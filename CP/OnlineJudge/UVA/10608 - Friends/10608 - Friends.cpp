#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("inp.inp","r",stdin);
#define fo freopen("out.out","w",stdout);

vector <bool> visited(30003);
vector <int> a[30003];
int ans = -1 , dem;

void DFS(int u) {
	visited[u] = true;
	for (int v = 0 ; v < (int) a[u].size() ; v++)
		if (!visited[a[u][v]]) {
			dem ++;
			DFS(a[u][v]);
		}
} 

int main(){
	boost;
	//fi;fo;
	int t; cin >> t;
	while (t --) {
		int n , m , u , v ; cin >> n >> m;
		for (int i = 1 ; i <= n ; i++) visited[i] = false; 
		for (int i = 1 ; i <= n ; i++) 
			a[i].clear();
		for (int i = 0 ; i < m ; i++){
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		ans = -1;
		for (int i = 1 ; i <= n ; i++) {
			dem = 1;
			if (!visited[i]) DFS(i);
			ans = max(ans , dem);
		}
		cout << ans << endl;
	}

	return 0;
}