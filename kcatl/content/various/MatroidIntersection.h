/**
 * Author: tfg, Aeren, pajenegod, chilli
 * Date: 2020-04-15
 * License: CC0
 * Source: https://codeforces.com/blog/entry/69287
 * Description: Given two (unweighted) matroids, finds the largest common independent set.
 * A matroid has 3 functions:
 *  - check(int x): can we add x without becoming dependent?
 *  - add(int x): adds x to the matroid (guaranteed to never make it dependent).
 *  - clear(): sets matroid to empty set.
 * Pass the matroid with more expensive add/clear operations to M1.
 * Time: $O(r^2n(\texttt{add} + \texttt{check}) + rn \texttt{clear})$, $r =$ answer size.
 * Status: Tested on SWERC 2011D, Pick Your Own Nim
 * Usage:
 * Details:
 */

template<class M1, class M2> struct MatroidIsect {
	int n;
	vector<char> iset;
	M1 m1; M2 m2;
	MatroidIsect(M1 m1, M2 m2, int n) : n(n), iset(n + 1), m1(m1), m2(m2) {}
	bool augment() {
		vector<int> frm(n, -1);
		queue<int> q({n}); // starts at dummy node
		auto fwdE = [&](int a) {
			vi ans;
			m1.clear();
			rep(v, 0, n) if (iset[v] && v != a) m1.add(v);
			rep(b, 0, n) if (!iset[b] && frm[b] == -1 && m1.check(b))
				ans.push_back(b), frm[b] = a;
			return ans;
		};
		auto backE = [&](int b) {
			m2.clear();
			rep(cas, 0, 2) rep(v, 0, n)
				if ((v == b || iset[v]) && (frm[v] == -1) == cas) {
					if (!m2.check(v))
						return cas ? q.push(v), frm[v] = b, v : -1;
					m2.add(v);
				}
			return n;
		};
		while (!q.empty()) {
			int a = q.front(), c; q.pop();
			for (int b : fwdE(a))
				while((c = backE(b)) >= 0) if (c == n) {
					while (b != n) iset[b] ^= 1, b = frm[b];
					return true;
				}
		}
		return false;
	}
	vi solve() {
		rep(i,0,n) if (m1.check(i) && m2.check(i))
			iset[i] = true, m1.add(i), m2.add(i);
		while (augment()); // increases intersection size by 1
		vi ans;
		rep(i,0,n) if (iset[i]) ans.push_back(i);
		return ans;
	}
};

