/**
 * Author: ecnerwala
 * Date: Unknown
 * Source: ecnerwala
 * Description: Min-cost max-flow.
 *  If costs can be negative, call setpi before maxflow, but note that negative cost cycles are not supported.
 *  To obtain the actual flow, look at positive values only.
 * Status: Tested on kattis mincostmaxflow, stress-tested against another implementation
 * Time: Approximately O(E^2)
 */
#pragma once

// #include <bits/extc++.h> /// include-line, keep-include

const ll INF = numeric_limits<ll>::max() / 4;
struct MCMF {
	int N;
	vector<vector<int>> adj;
	struct edge_t {
		int dest;
		ll cap, cost;
	};
	vector<edge_t> edges;
	vector<char> seen;
	vector<ll> pi;
	vector<int> prv;
	void addEdge(int from, int to, ll cap, ll cost) {
		assert(cap >= 0);
		int e = int(edges.size());
		edges.emplace_back(edge_t{to, cap, cost});
		edges.emplace_back(edge_t{from, 0, -cost});
		adj[from].push_back(e);
		adj[to].push_back(e+1);
	}
	vector<ll> dist;
	__gnu_pbds::priority_queue<pair<ll, int>> q;
	vector<typename decltype(q)::point_iterator> its;
	void path(int s) {
		dist.assign(N, INF);
		dist[s] = 0;

		its.assign(N, q.end());
		its[s] = q.push({0, s});

		while (!q.empty()) {
			int i = q.top().second; q.pop();
			ll d = dist[i];
			for (int e : adj[i]) {
				if (edges[e].cap) {
					int j = edges[e].dest;
					ll nd = d + edges[e].cost;
					if (nd < dist[j]) {
						dist[j] = nd;
						prv[j] = e;
						if (its[j] == q.end()) {
							its[j] = q.push({-(dist[j] - pi[j]), j});
						} else {
							q.modify(its[j], {-(dist[j] - pi[j]), j});
						}
					}
				}
			}
		}
		swap(pi, dist);
	}
	pair<ll, ll> maxflow(int s, int t) {
		assert(s != t);
		ll totFlow = 0; ll totCost = 0;
		while (path(s), pi[t] < INF) {
			ll curFlow = numeric_limits<ll>::max();
			for (int cur = t; cur != s; ) {
				int e = prv[cur];
				int nxt = edges[e^1].dest;
				curFlow = min(curFlow, edges[e].cap);
				cur = nxt;
			}
			totFlow += curFlow;
			totCost += pi[t] * curFlow;
			for (int cur = t; cur != s; ) {
				int e = prv[cur];
				int nxt = edges[e^1].dest;
				edges[e].cap -= curFlow;
				edges[e^1].cap += curFlow;
				cur = nxt;
			}
		}
		return {totFlow, totCost};
	}
	// If some costs can be negative, call this before maxflow:
	void setpi(int s) { // (otherwise, leave this out)
		fill(all(pi), INF); pi[s] = 0;
		int it = N, ch = 1; ll v;
		while (ch-- && it--)
			rep(i,0,N) if (pi[i] != INF)
				for (int e : adj[i]) if (edges[e].cap)
					if ((v = pi[i] + edges[e].cost) < pi[edges[e].dest])
						pi[edges[e].dest] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
	explicit MCMF(int N_) : N(N_), adj(N), pi(N, 0), prv(N) {}
};
