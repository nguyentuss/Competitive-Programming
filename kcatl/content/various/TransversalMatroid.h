/**
 * Author: Cyanforces
 * Date: 2020-04-15
 * License: CC0
 * Source: https://codeforces.com/gym/103373/submission/141662202
 * Description: Transversal Matroid. Given a bipartite graph, activates left 
 * nodes one by one, retains perfect matching whenever possible
 * Time: $O(M)$.
 * Status: Tested on 103373I
 * Usage:
 * Details:
 */

struct TransversalMatroid {
	vector<vi> g;
	int n, m, T = 1;
	vi rmatch, lmatch, vis;
	TransversalMatroid(vector<vi> gg, int mm) : g(gg), n(sz(gg)), m(mm) {
		vis.resize(n, 0); clear();
	}
	void clear() { // resets all nodes
		rmatch.assign(m, -1);
		lmatch.assign(n, -1);
	}
	bool dfs(int l, bool commit) {
		if (vis[l] == T) return false;
		vis[l] = T;
		for (auto r: g[l]) 
			if (rmatch[r] == -1) {
				if (commit) rmatch[r] = l, lmatch[l] = r;
				return true;
			}
		for (auto r: g[l]) 
			if (dfs(rmatch[r], commit)) {
				if (commit) rmatch[r] = l, lmatch[l] = r;
				return true;
			}
		return false;
	}
	bool check(int a) { // checks if a can be activated
		++T; return dfs(a, false);
	}
	void add(int a) { // activates a if possible
		++T; dfs(a, true);
	}
};

