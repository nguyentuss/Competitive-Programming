/**
 * Author: FireGhost
 * License: CC0
 * Source: https://github.com/FireGhost1301/ICPC-Notebook/blob/master/content/various/1D1D.h
 * Description: Solves DP on intervals: $dp[i] = \min_{j < i}(dp[j] + cost(i+1, j))$, where $cost(i, j)$ satisfies quarangle equality.
 * Assumes array is 1-indexed, and $cost(l, r)$ is $l, r$ both inclusive.
 * Status: Tested on https://codeforces.com/gym/101981 problem B
 * Time: O(NlogN)
 */
 
 ll calc() {
	vector<ll> dp(n+1, INF); dp[0] = 0;
	vector<pair<int, int>> v(1);
	rep(x, 1, n+1) {
		int k = (--lower_bound(all(v), make_pair(x+1, 0)))->second;
		dp[x] = dp[k] + cost(k+1, x);
		for (int i = sz(v) - 1; i >= 0; i--) {
			int y = v[i].first, oldk = v[i].second;
			if (y > x && dp[x] + cost(x+1, y) < dp[oldk] + cost(oldk+1, y)) v.pop_back();
			else {
				int l = y+1, r = n+1;
				while (l < r) {
					int mid = (l+r)/2;
					if (dp[x] + cost(x+1, mid) < dp[oldk] + cost(oldk+1, mid)) r = mid;
					else l = mid+1;
				}
				if (r != n+1) v.push_back({r, x});
				break;
			}
		}
		if (v.empty()) v.push_back({0, x});
	}
	return dp[n];
}

