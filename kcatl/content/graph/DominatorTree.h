/**
 * Author: pwbyzg
 * Date: 2/12/2020
 * License: CC0
 * Source:
 * Description: Given a source, construct a dominator tree. 
 * Returns parent, or -1 if not in dominator tree
 * Time: O(N)
 * Usage: DTree dm(n, g); vi par = dm.build(src);
 * Status: tested on yosupo judge + cses + 102920F
 */

#pragma once

struct DTree{
	int cs = 0, n;
	vector<vi> e, re, rdom;
	vi s, rs, par, val, sdom, rp, dom;

	DTree(vector<vi> &g) : n(sz(g)), e(g), re(n), rdom(n), 
		s(n, -1), rs(n), par(n), val(n), 
		sdom(n), rp(n), dom(n) {}

	int find(int x, int c = 0) {
		if (par[x] == x) return c ? -1 : x;
		int p = find(par[x], 1);
		if (p == -1) return c ? par[x] : val[x];
		if (sdom[val[x]] > sdom[val[par[x]]]) val[x] = val[par[x]];
		par[x] = p;
		return c ? p : val[x];
	}
	void merge(int x, int y) {
		par[x] = y;
	}
	void dfs(int x) {
		rs[s[x] = cs++] = x;
		par[cs] = sdom[cs] = val[cs] = cs;
		for (int e: e[x]) {
			if (s[e] == -1) dfs(e), rp[s[e]] = s[x];
			re[s[e]].push_back(s[x]);
		}
	}
	vi build(int src) {
		dfs(src);
		for (int i = cs-1; i >= 0; i--) {
			for (int e: re[i]) sdom[i] = min(sdom[i], sdom[find(e)]);
			if (i != src) rdom[sdom[i]].push_back(i);
			for (int e: rdom[i]) {
				int p = find(e);
				if (sdom[p] == i) dom[e] = i;
				else dom[e] = p;
			}
			if (i != src) merge(i, rp[i]);
		}
		rep(i, 0, cs)
			if (sdom[i] != dom[i])
				dom[i] = dom[dom[i]];
		vi up(sz(e), -1);
		rep(i, 0, cs) up[rs[i]] = rs[dom[i]];
		return up;
	}
};
