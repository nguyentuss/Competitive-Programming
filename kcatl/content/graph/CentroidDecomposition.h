/**
 * Author: Tus
 * Date: 2024-08-03
 * License: CC0
 * Source: Folklore
 * Description: 
 *  * Time: O(\log N)
 * Status: Tested on https://codeforces.com/contest/321/problem/C
 */

vector<int> adj[MAX_N] , g[MAX_N];
int level[MAX_N] , f[MAX_N];
bool vis[MAX_N] , check[MAX_N];
int root = 0;


void DFS(int u , int father) {
	f[u] = 1;
	for (auto v : adj[u]) {
		if (father != v && !check[v]) {
			DFS(v , u);
			f[u] += f[v];
		}
	}
}

int find_ct(int u , int father , int root) {
	for (auto v : adj[u]) 
		if (!check[v] && v != father && f[v]*2 >= f[root]) 
			return find_ct(v , u , root);
	return u;
}

void centroid(int u , int father) {
	DFS(u , u);
	u = find_ct(u , u , u); check[u] = 1;
	if (father != -1) {
		g[father].push_back(u);
		g[u].push_back(father);
	}
	else {
		root = u;
	}	
	for (auto v : adj[u]) {
		if (!check[v]) 
			centroid(v , u);
	}
}