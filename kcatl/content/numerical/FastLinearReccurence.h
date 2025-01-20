/**
 * Author: tomatoes
 * Date: 2023-12-03
 * Source: https://mzhang2021.github.io/cp-blog/berlekamp-massey/#kth
 * Description: Generates the $k$'th term of an $n$-order
 * linear recurrence $S[i] = \sum_j S[i-j-1]tr[j]$,
 * given $S[0 \ldots \ge n-1]$ and $tr[0 \ldots n-1]$.
 * Time: O(n \log n \log k)
 * Status: tested on 
 *   - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
 *   - https://www.codechef.com/problems/RNG
 */

#pragma once

#include "NumberTheoricTransform.h"
#include "PolyInv.h"

ll linearRec(vl S, vl tr, ll k) {
	int n = sz(tr); tr.insert(tr.begin(), 1);
	rep(i,1,sz(tr)) tr[i] = tr[i] ? mod - tr[i] : 0;
	vl p = conv(tr, S); p.resize(n);
	while (k > n) {
		vl qm = tr;
		rep(i,0,n+1) if (i % 2 && qm[i]) qm[i] = mod - qm[i];
		p = conv(p, qm), tr = conv(tr, qm);
		rep(i,0,n) p[i] = p[2 * i + (k & 1)];
		rep(i,0,n+1) tr[i] = tr[2 * i];
		k /= 2, p.resize(n), tr.resize(n + 1);
	}
	return conv(p, polyInv(tr))[k];
}
