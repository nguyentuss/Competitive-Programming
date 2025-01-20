/**
 * Author: Tomatoes
 * Date: 2017-04-20
 * License: CC0
 * Source: https://ei1333.github.io/library/structure/convex-hull-trick/dynamic-li-chao-tree.hpp.html
 * Description: Convex hull trick. Adds lines of the form $ax+b$ in range $[L, R]$, queries max/min on integer $x$.
 * Note the range includes R.
 * Time: O(\log N)
 * Status: Tested on YATP, CSES Monster Game II, yosupo judge
 */
#pragma once

struct Line {
	ll a, b;
	inline ll calc(ll x) const {return a*x + b;}
};
struct DynamicLiChaoTree {
	// modify these at will
	static const bool maximum = true;
	static const ll minX = -1e9, maxX = 1e9, defVal = -1e18; 

	struct Node {
		Line line = {0, maximum ? defVal : -defVal};
		Node *lt = nullptr, *rt = nullptr;
	} *root;

	DynamicLiChaoTree() {root = new Node();}

	void update(Node* cur, ll l, ll r, ll u, ll v, Line nw) {
		#define newNode(x) if (!x) x = new Node()
		if (v < l || r < u) return;
		ll mid = (l + r) >> 1;
		if (u <= l && r <= v) {
			if (cur->line.calc(l) >= nw.calc(l)) swap(cur->line, nw);
			if (cur->line.calc(r) <= nw.calc(r)) {
				cur->line = nw; return;
			}
			if (nw.calc(mid) >= cur->line.calc(mid)) {
				newNode(cur->rt);
				update(cur->rt, mid + 1, r, u, v, cur->line);
				cur->line = nw;
			} else {
				newNode(cur->lt);
				update(cur->lt, l, mid, u, v, nw);
			}
		} else {
			newNode(cur->lt); newNode(cur->rt);
			update(cur->lt, l, mid, u, v, nw);
			update(cur->rt, mid + 1, r, u, v, nw);
		}
		#undef newNode
	}
	void add(ll a, ll b, ll l = minX, ll r = maxX) { 
		if (!maximum) a = -a, b = -b; // [L, R] not [L, R)
		update(root, minX, maxX, l, r, {a, b});
	}	
	ll query(ll x) {
		Node* cur = root;
		ll res = cur->line.calc(x), l = minX, r = maxX, mid;
		while (cur) {
			res = max(res, cur->line.calc(x));
			mid = (l + r) >> 1;
			if (x <= mid) cur = cur->lt, r = mid;
			else cur = cur->rt, l = mid + 1;
		}
		return maximum ? res : -res;
	}
};

