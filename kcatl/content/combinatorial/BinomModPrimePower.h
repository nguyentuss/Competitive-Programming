/**
 * Author: tomatoes
 * Date: 2023-08-03
 * License: CC0
 * Description: Calculate $\binom{n}{k}$ modulo prime power $p^q$.
 * Time: O(p^q) preprocessing, O(\log_p n) query
 * Status: tested on yosupo:binomial_coefficient
 * Details:
 *  This implementation is based on https://github.com/yosupo06/library-checker-problems/blob/2818383ef131842725b3f06f05a7c075795d0f49/math/binomial_coefficient/sol/correct.cpp,
 *  which implements this paper: https://web.archive.org/web/20170202003812/http://www.dms.umontreal.ca/~andrew/PDF/BinCoeff.pdf
 *
 *  However, there is an easier way to come up with this approach. We can generalize https://cp-algorithms.com/algebra/factorial-modulo.html to prime powers:
 *    - Ignore multiples of p. Let recursion handle them.
 *    - Define n!! as the product of all numbers from 1 to n not divisible by p
 *    - Instead of blocks of length p, use blocks of length p^q. The product of each group, (p^q)!!,
 *      is 1 iff p == 2 and q >= 3, otherwise it is -1, modulo p^q.
 *    - factmod(n, p, q) = factmod(n / p, p, q) * ((p^q)!!)^(n / p^q) * (n % p^q)!! mod p^q
 *  It is easy to see that this approach is equivalent to theorem 3 in the paper and the implementation below.
 */
#pragma once

#include "../number-theory/euclid.h"

struct BinomModPrimePower {
	int p, q, M; bool neg; vi pw; vl fac, ifac;
	BinomModPrimePower(int p, int q) : p(p), q(q), pw(q) {
		neg = !(p == 2 && q >= 3);
		pw[0] = 1; rep(i, 1, q) pw[i] = pw[i - 1] * p;
		M = pw[q - 1] * p;
		fac.resize(M), ifac.resize(M); fac[0] = 1;
		rep(i,1,M) fac[i] = fac[i - 1] * (i%p?i:1) % M;
		ll x, y, g = euclid(fac[M - 1], M, x, y);
		ifac[M - 1] = (x + M) % M;
		for(int i=M-1;i;--i) ifac[i - 1] = ifac[i] * (i%p?i:1) % M;
	}
	ll calc(ll n, ll k) {
		int i = 0; ll h = n - k, r = 1, e0 = 0, eq = 0, eps;
		while (n) {
			r = r * fac[n%M] % M * ifac[k%M] % M * ifac[h%M] % M;
			n /= p, k /= p, h /= p, eps = n - k - h;
			if ((e0 += eps) >= q) return 0;
			if (++i >= q) eq += eps;
		}
		if (neg && (eq & 1) && r) r = M - r;
		return r * pw[e0] % M;
	}
};
