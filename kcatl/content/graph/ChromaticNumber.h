/**
 * Author: nyaannyaan
 * Date: 2023-11-01
 * Source: https://nyaannyaan.github.io/library/graph/chromatic-number.hpp
 * Description: Finds the smallest number of colors needed to color the vertices so that no two adjacent vertices share the same color.
 * Time: O(N2^N)
 * Status: tested on yosupo:chromatic_number
 */

int chromatic(int n, vector<pii>& ed) {
	vector<pii> hist;
	vi g(n), dp(1 << n), memo((1 << n) + 1);
	for (auto [u, v] : ed) g[u] |= 1 << v, g[v] |= 1 << u;
	dp[0] = memo[1] = 1;
	rep(i,1,(1 << n)) { int k = i & (i - 1);
		dp[i] = dp[k] + dp[k & ~g[__builtin_ctz(i)]];
		memo[dp[i]] += __builtin_parity(i) ? -1 : 1;
	}
	rep(i,1,sz(memo)) if (memo[i]) hist.emb(i, memo[i]);
	auto calc = [n](vector<pii> hist, int mod) {
		rep(c,1,n) { ll sm = 0;
			for (auto& [i, x] : hist) sm += (x = 1LL * x * i % mod);
			if (sm % mod != 0) return c;
		}
		return n;
	};
	return min(calc(hist, 1e9 + 7), calc(hist, 1e9 + 9));
}
