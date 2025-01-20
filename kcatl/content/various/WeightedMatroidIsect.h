/**
 * Author: https://codeforces.com/gym/103373/submission/141662202
 * License: CC0
 * Source: Eliden, Chilli, Benq, some papers
 * Description: Given two matroids, finds the maxweight largest common independent set.
 * For unweighted, set w = 0.
 * A matroid has 3 functions:
 *  - check(int x): can we add x without becoming dependent?
 *  - add(int x): adds x to the matroid (guaranteed to never make it dependent).
 *  - clear(): sets matroid to empty set.
 * Time: $O(r^2 (\texttt{clear} + r\cdot \texttt{add} + n\cdot \texttt{check} + n\log n))$, $r =$ answer size.
 * Status: tested on: rainbowgraph, pick your own nim, DIY Tree, 103373I
 * Details: Correctness is a bit questionable... maybe dijkstra needs to find shortest path wrt (dist, edgecount) instead of just (dist), to make sure path is chordless? I think it is fine, since a "chord" would set the dad pointer earlier
 */

template<class M1, class M2> struct WeightedMatroidIsect {
	int n;
	ll cost = 0, inf = 1e18;
	vi iset; // true if included in answer
	vector<ll> s1, s2; // split weight/potential functions
	M1 m1; M2 m2;
	WeightedMatroidIsect(M1 m1, M2 m2, vector<ll> w)
		: n(sz(w)), iset(n), s1(w), s2(n+1), m1(m1), m2(m2) {
			iset.push_back(1); // for dummy source/sink node
			s1.push_back(0);
		}
	vi nei(auto& m, int x) {
		vi res; m.clear(); 
		// possible speed-up: precompute circuits  /// exclude-line
		rep(y,0,n) if(y != x && iset[y]) m.add(y);
		rep(y,0,n) if(!iset[y] && m.check(y)) res.push_back(y);
		return res;
	}
	bool augment() {
		vector<vector<pair<int,ll>>> g(n+1);
		rep(x,0,n+1) if (iset[x]) {
			for (int y: nei(m1,x)) g[y].emplace_back(x, s1[x]-s1[y]);
			for (int y: nei(m2,x)) g[x].emplace_back(y, s2[x]-s2[y]);
		}
 
		vector<ll> dist(n+1, inf);
		vi dad(n+1, -1);
		priority_queue<pair<ll,int>> q;
		q.emplace(0,n); // when unweighted, consider replacing
		while(!q.empty()) { // dijkstra with bfs, and ignore s1/s2
			auto [d, x] = q.top();
			q.pop();
			d = -d;
			if (x == n && dad[n] != -1) continue;
			if (d > dist[x]) continue;
			for (auto [y, w]: g[x]) if (dist[y] > d + w) {
				dist[y] = d + w;
				dad[y] = x;
				q.emplace(-dist[y], y);
			}
		}
 
		if (dad[n] == -1) return false;
		cost -= dist[n];
		rep(x,0,n) if (dad[x] != -1) {
			s1[x] -= dist[x];
			s2[x] += dist[x];
		}
		for (int x = dad[n]; x != n; x = dad[x]) iset[x] ^= 1;
		return true;
	}
	pair<int, ll> solve() { // (sz, cost)
		// >= 2*speedup for unweighted:
		// rep(i,0,n) if(m1.check(i) && m2.check(i))
		//   m1.add(i), m2.add(i), iset[i] = 1;
		while (augment()); // increases intersection size by 1
		return {count(all(iset)-1,1), cost};
	}
};
