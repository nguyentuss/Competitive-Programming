/**
 * Author: Tomatoes + myself
 * Date: 2023-10-09
 * Source: Unknown
 * Description: Evaluate a polynomial at multiple points
 * Time: O((n + q) \log^2 (n + q) \log q)
 * Usage: vl y = polyMultiEval(p, x);
 * Status:
 *  - tested on https://judge.yosupo.jp/problem/multipoint_evaluation
 */
#pragma once

#include "NumberTheoricTransform.h"
#include "PolyDiv.h"

vector<vector<vl>> evalTree(const vl &X) { // segtree of (x-x0)(x-x1)...
	vector<vector<vl>> ps(1);
	for (ll x : X) ps[0].push_back({x > 0 ? mod - x : -x, 1});
	while (sz(ps.back()) > 1) {
		vector<vl> tmp;
		for (int i = 0; i < sz(ps.back()); i += 2)
			if (i + 1 < sz(ps.back()))
				tmp.push_back(conv(ps.back()[i], ps.back()[i^1]));
			else tmp.push_back(ps.back()[i]);
		ps.push_back(tmp); 
	}
	return ps;
}
vl polyMultiEval(const vl& a, const vl& p, vector<vector<vl>> ps = {}) {
	if (p.empty()) return {};
	if (ps.empty()) ps = evalTree(p);

	ps[sz(ps) - 1][0] = polyMod(a, ps[sz(ps) - 1][0]);
	for (int i = sz(ps) - 2; i >= 0; --i)
		for (int j = 0; j < sz(ps[i]); j += 2)
			if (j + 1 < sz(ps[i]))
				ps[i][j] = polyMod(ps[i+1][j/2], ps[i][j]),
				ps[i][j^1] = polyMod(ps[i+1][j/2], ps[i][j^1]);
			else ps[i][j] = ps[i+1][j/2];
	vl res; for (vl p: ps[0]) res.push_back(p[0]);
	return res;
}
