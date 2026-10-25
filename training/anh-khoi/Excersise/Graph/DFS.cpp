#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

vector <int> a[100];

bool visited[100] = {false};

void DFS(int u) {
	visited[u] = true;
	for (int v = 0 ; v < (int) a[u].size() ; v++) 
		if (visited[v] == false) 
			DFS(v);
}


int main() {
	boost;

	int n , m , u , v; cin >> n >> m;
	for (int i = 1 ; i <= m ; i++){
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	DFS(5); 
	if (visited[6] == true) cout << "YES";
	else cout << "NO";

	return 0;
}