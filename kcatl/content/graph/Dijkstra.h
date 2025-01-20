/**
 * Author: tomatoes
 * Date: 2023-07-04
 * License: CC0
 * Description: Calculates shortest paths from $s$ in a graph with no negative edge weights.
 * Unreachable nodes get dist = inf.
 * Assumes $V^2 \max |w_i| < \tilde{} 2^{63}$.
 * Time: O((E + V) \log V)
 * Status: tested on yosupo:shortest_path
 */

const ll inf = LLONG_MAX;
struct Ed { int v, w; };
struct Node { ll dist = inf; int prev = -1; };
void dijkstra(vector<Node>& nodes, vector<vector<Ed>>& eds, int s) {
	assert(sz(nodes) == sz(eds));
	min_heap<pair<ll, int>> q;
	q.emplace(nodes[s].dist = 0, s);
	while (!q.empty()) {
		ll d; int u; tie(d, u) = q.top(); q.pop();
		if (d > nodes[u].dist) continue;
		for (Ed e : eds[u]) {
			ll d2 = d + e.w;
			if (d2 < nodes[e.v].dist) {
				nodes[e.v].prev = u;
				nodes[e.v].dist = d2;
				q.emplace(d2, e.v);
			}
		}
	}
}
