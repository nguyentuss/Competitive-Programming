/**
 * Author: NXT
 * Date: 2020-12-28
 * License: CC0
 * Source: https://cp-algorithms.com/graph/flow_with_demands.html
 * Description: Computes a minimal flow with demands. Edges of the type {u, v, cap, demand}.
 * Returns pair: First is flow, $-1$ if no solution. Second is flow through each edge in order.  
 * To find minimum flow, binary search on INF.
 * To find maximum flow, subtract found network, and run flow again
 * Status: Tested on CF 100212I and ZOJ Shoot the bullet
 */

#pragma once

#include "Dinic.h"

typedef vector<ll> vl;
pair<ll, vl> flowDemand(int n, int s, int t, vector<tuple<int, int, ll, ll>> &edges) {
	Dinic f(n+2);
	vl din(n), dout(n);
	ll sumd = 0;
	for (auto [u, v, c, d]: edges) {
		f.addEdge(u, v, c-d);
		din[v] += d; dout[u] += d; 
		sumd += d;
	}
	rep(i, 0, n) {
		f.addEdge(n, i, din[i]);
		f.addEdge(i, n+1, dout[i]);
	}
	f.addEdge(t, s, INF);

	if (f.calc(n, n+1) != sumd) {
		return {-1, vector<ll>(0)};
	} else {
		vi ptr(n);
		vl ans; ll totflow = 0;

		for (auto [u, v, c, d]: edges) {
			ll g = d + f.adj[u][ptr[u]].flow();
			ans.push_back(g);
			if (u == s) totflow += g;
			ptr[u]++;
		}

		return {totflow, ans};
	}
}
