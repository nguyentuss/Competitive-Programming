#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#pragma GCC optimize("Ofast")

vector <int> adj[100007];

int dist[100007];
bool visited[100007] = {false};
int ans = 0;

int DFS(int u) {
	if (visited[u]) return dist[u];
	visited[u] = true;
	int res = 0;
	for (auto v : adj[u]) {
		res = max(res , DFS(v) + 1);
	}
	return dist[u] = res;
}

int main() {
//  boost;

  int n , m  ; cin >> n >> m;
  int u , v;
  for (int i = 1 ; i <= n ; i++) dist[i] = 1;
  for (int i = 0 ; i < m ; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
  }
  int res = 1;
  for (int i = 1 ; i <= n ; i++) {
    	res = max(res , DFS(i));
  } 
  cout << res;


  return 0;
}