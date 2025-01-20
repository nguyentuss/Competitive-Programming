/**
 * Author: wleung_bvg
 * Date: 2023-11-12
 * License: CC0
 * Source: wleung_bvg
 * Description: Finds all 3-edge connected components of a graph (not triconnected!).
 * `comps` hold the components, `id` holds the component id of each node
 * Time: $O(N*\alpha(N))$
 * Status: tested on yosupo judge
 */
#pragma once

#include "../data-structures/UnionFind.h"

struct ThreeEdgeCC {
	int V, ind; 
	vi id, pre, post, low, deg, path;
	vector<vi> comps; UF uf;
	void dfs(const vector<vi> &G, int v, int prev) {
		pre[v] = ++ind; 
		for (int w : G[v]) if (w != v) {
			if (w == prev) { prev = -1; continue;}
			if (pre[w] != -1) {
				if (pre[w] < pre[v]) {deg[v]++; low[v] = min(low[v], pre[w]);}
				else {
					deg[v]--; int &u = path[v];
					for (; u != -1 && pre[u] <= pre[w] && pre[w] <= post[u];) {
						uf.join(v, u); deg[v] += deg[u]; u = path[u];
					}
				}
				continue;
			}
			dfs(G, w, v); if (path[w] == -1 && deg[w] <= 1) {
				deg[v] += deg[w]; low[v] = min(low[v], low[w]); continue;
			}
			if (deg[w] == 0) w = path[w];
			if (low[v] > low[w]) {low[v] = min(low[v], low[w]); swap(w, path[v]);}
			for (; w != -1; w = path[w]) {uf.join(v, w); deg[v] += deg[w];}
		}
		post[v] = ind;
	}
	ThreeEdgeCC(const vector<vi> &G)
			: V(G.size()), ind(-1), id(V, -1), pre(V, -1), post(V), low(V, INT_MAX),
				deg(V, 0), path(V, -1), uf(V) {
		rep(v,0,V) if (pre[v] == -1) dfs(G, v, -1);
		rep(v,0,V) if (uf.find(v) == v) {
			id[v] = comps.size(); comps.emplace_back(1, v);
		}
		rep(v,0,V) if (id[v] == -1)
			comps[id[v] = id[uf.find(v)]].push_back(v);
	}
};
