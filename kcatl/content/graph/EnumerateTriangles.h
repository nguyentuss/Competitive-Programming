/**
 * Author: Unknown
 * Date: 2023-11-01
 * Source: https://ngthanhtrung23.github.io/ACM_Notebook_new/Graph/find_triangles.h
 * Description: Find all triangles in simple undirected graph. If not simple, remove self-loops and parallel edges before using.
 * Usage: enumerate_triangles(n, ed, [\&](int x, int y, int z) {});
 * Time: O(N + M\sqrt M)
 * Status: tested on yosupo:enumerate_triangles
 */

template<class F>
void enumerate_triangles(int n, vector<pii>& ed, F f) {
	vi deg(n), on(n); vector<vi> g(n);
	for (auto [u, v] : ed) ++deg[u], ++deg[v];
	for (auto [u, v] : ed) {
		if (tie(deg[u], u) > tie(deg[v], v)) swap(u, v);
		g[u].pb(v);
	}
	rep(x,0,n) {
		for (int y : g[x]) on[y] = 1;
		for (int y : g[x]) for (int z : g[y]) if (on[z]) f(x,y,z);
		for (int y : g[x]) on[y] = 0;
	}
}

