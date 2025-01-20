/**
 * Author: tomatoes
 * Date: 2023-07-08
 * License: CC0
 * Source: https://cp-algorithms.com/algebra/primitive-root.html
 * Description: Find a primitive root modulo prime $p$. (i.e. finds $r$ such that for all $a$ such that $gcd(a, p) = 1$, there exists $k$ such that $r^k = a$).
 *  For non-prime $p$, replace \texttt{p - 1} with $\phi(p)$.
 * Time: $O(p^{1/4} + \log^8 p)$
 * Status: tested on yosupo:primitive_root
 */

#include "Factor.h"
#include "ModMulLL.h"

ull primitiveRoot(ull p) {
	ull r = 0;
	auto pf = factor(p - 1); sort(all(pf)); 
	pf.resize(unique(all(pf)) - pf.begin());
	for (int ok = 0; !ok;) {
		ok = 1; ++r;
		for (ull f: pf) if (modpow(r, (p - 1) / f, p) == 1) {
			ok = 0; break;
		}
	}
	return r;
}

