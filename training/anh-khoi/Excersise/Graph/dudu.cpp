#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

vector <int> graph[10007];
vector <bool> visited(10007);
vector <int> path(10007);
int n , m;
bool check;

bool DFS(int u) {
	path[u] = 1;
	for (int i = 0 ; i < (int) graph[u].size() ; i++){
		int v = graph[u][i];
		if (path[v] == 1) return true;
		else if (path[v] == 0) 
			if (DFS(v) == true) return true;
	}
	path[u] = 2;
	return false;
}

int main(){
	boost;

	int t ; cin >> t;
	while (t --) {
		check = false;
		int u , v; cin >> n >> m;
		for (int i = 1; i <= n; i++) path[i] = 0;
		for (int i = 1 ; i <= n; i++) visited[i] = false;
		for (int i = 1 ; i <= n; i++) graph[i].clear();
		for (int i = 0 ; i < m ; i++) {
			cin >> u >> v;
			graph[u].push_back(v);
		}
		for (int i = 1 ; i <= n ; i++) {
			if (path[i] == 0) {
				if (DFS(i)) {
					check = true;
					cout << "SIM" << endl;
					break;
				}
			}
		}
		if (!check) cout << "NAO" << endl;
	}


	return 0;
}