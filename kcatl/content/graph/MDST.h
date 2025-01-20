/**
 * Author: Chinese code
 * Date: 2015-02-23
 * License: CC0
 * Source: CF 222200501
 * Description: Minimum diameter spanning tree. Returns tuple of $d, u, v, x$, where $d$ is the diameter length, $(u, v)$ is the center edge of the diameter, $x$ is twice the distance from $u$ to the actual center. If $u, v$ are the same, then center is on the node.
 * To find tree, double all edge weights, then run multi-source dijkstra from $u$ and $v$, with initial distances $dist_u = x$, $dist_v = w - x$, $w$ is the (doubled) weight of edge $u, v$. Take the shortest path tree.
 * Time: O(N^3)
 * Status: Tested on CF 102391I
 */
#pragma once

const ll INF = 1e18;
tuple<ll, int, int, ll> findMDST(int n, vector<tuple<int, int, ll>> &edges) {
	vector<vector<ll>> d(n, vector<ll>(n, INF));
	rep(i,0,n) d[i][i] = 0;

	for (auto [u, v, w]: edges) 
		d[u][v] = d[v][u] = min(d[u][v], w*2);

	rep(k,0,n) rep(u,0,n) rep(v,0,n)
		d[u][v] = min(d[u][v], d[u][k] + d[k][v]);

	vector<vi> que(n);
	tuple<ll, int, int, ll> ans = {INF, INF, INF, INF};
	rep(i,0,n) {
		que[i].resize(n);
		iota(all(que[i]), 0);
		sort(all(que[i]), [&](const int &a, const int &b) {
			return d[i][a] > d[i][b];
		});
		ans = min(ans, {d[i][que[i][0]], i, i, 0});
	}
	for (auto [u, v, w]: edges) {
		int p = 0;
		rep(j,1,n) {
			int a = que[u][j], b = que[u][p];
			if (d[v][a] > d[v][b]) {
				ll x = (d[v][b] - d[u][a] + w*2)/2;
				ans = min(ans, {d[u][a] + x, u, v, x});
				p = j;
			}
		}
	}
	return ans;
}

