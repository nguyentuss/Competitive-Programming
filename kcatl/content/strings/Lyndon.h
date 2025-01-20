/**
 * Author: Unknown
 * Date: 2023-07-12
 * Source: https://cp-algorithms.com/string/lyndon_factorization.html
 * Description: Returns the Lyndon factorization of $S$.
 * Time: O(N)
 * Status: tested on yosupo:lyndon_factorization
 */

vi lyndon_factor(const string& s) {
	vi res;
	for (int i = 0, n = sz(s); i < n;) {
		int j = i + 1, k = i;
		for (; j < n && s[k] <= s[j]; ++j)
			k = s[k] < s[j] ? i : k + 1;
		while (i <= k) res.pb(i), i += j - k;
	}
	res.pb(sz(s)); return res;
}

