/**
 * Author: Unknown
 * Date: 2023-10-25
 * Source: Copied from https://github.com/yosupo06/library-checker-problems/blob/master/math/kth_root_mod/sol/correct.cpp
 * Description: Returns $x$ s.t. $x^k = a \pmod p$, or $-1$ if no such $x$ exists.
 * Status: tested on yosupo:kth_root_mod
 * Time: $O(\min(p, k)^{1/4})$
 * Details: See https://nyaannyaan.github.io/library/modulo/mod-kth-root.hpp.html
 */
#pragma once

#include "ModPow.h"
#include "euclid.h"

ll peth_root(ll a, ll p, int e, ll mod) {
	map<ll, int> mp;
	int s = 0; ll q = mod-1, pe = modpow(p, e, mod), c=2, add=1;
	while (q % p == 0) q /= p, ++s;
	while (modpow(c, (mod - 1) / p, mod) == 1) ++c;
	c = modpow(c, q, mod);
	int v = (int)sqrt((double)(s - e) * p) + 1;
	ll mul = modpow(c, v * modpow(p, s-1, mod-1) % (mod-1), mod);
	rep(i,0,v+1) mp[add] = i, add = add * mul % mod;
	mul = inv(modpow(c, modpow(p, s - 1, mod - 1), mod), mod);
	ll res = modpow(a, ((pe-1)*inv(q, pe) % pe * q + 1)/pe, mod);
	rep(i,e,s) {
		ll err = inv(modpow(res, pe, mod), mod) * a % mod;
		ll tar = modpow(err, modpow(p, s - 1 - i, mod - 1), mod);
		for (int j = 0; j <= v; ++j, tar = tar * mul % mod)
			if (mp.count(tar)) {
				ll b = (j+v*mp[tar]) * modpow(p, i-e, mod-1) % (mod-1);
				res = res * modpow(c, b, mod) % mod;
				break;
			}
	}
	return res;
}

ll kth_root(ll a, ll k, ll p) {
	if (k && a % p == 0) return 0;
	k %= p - 1; ll g = __gcd(k, p - 1);
	if (modpow(a, (p - 1) / g, p) != 1) return -1;
	a = modpow(a, inv(k / g, (p - 1) / g), p);
	for (ll div = 2; div * div <= g; ++div) {
		int sz = 0; while (g % div == 0) g /= div, ++sz;
		if (sz) a = peth_root(a, div, sz, p);
	}
	if (g > 1) a = peth_root(a, g, 1, p);
	return a;
}
