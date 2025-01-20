/**
 * Author: tomatoes
 * Date: 2023-11-30
 * License: CC0
 * Source: yosupo
 * Description: Supports range chmin chmax (i.e. a[i] = max(a[i], val)), and range add 
 * operations, in range [L, R).
 * Time: $O(\log^2 N)$ .
 * Status: tested on yosupo judge
 */
#pragma once

template <class T, T INF>
class SegTreeBeats {
	#define lid (id * 2)
	#define rid (id * 2 + 1)
	#define tm (tl + tr) / 2
	constexpr static int MAX = 0, MIN = 1;
	struct Value { T v1, v2, cnt; };
	struct Node { T sum, lazy; Value val[2]; }; // 0=max, 1=min
	int n; vector<Node> st; const T* a;
	void merge(int id) {
		st[id].sum = st[lid].sum + st[rid].sum;
		rep(k,0,2) {
			auto& [v1, v2, cnt] = st[id].val[k];
			auto [lv1, lv2, lcnt] = st[lid].val[k];
			auto [rv1, rv2, rcnt] = st[rid].val[k];
			if (lv1 == rv1)
				v1 = lv1, v2 = max(lv2, rv2), cnt = lcnt + rcnt;
			else if (lv1 > rv1)
				v1 = lv1, v2 = max(lv2, rv1), cnt = lcnt;
			else
				v1 = rv1, v2 = max(rv2, lv1), cnt = rcnt;
		}
	}
	void build(int id, int tl, int tr) {
		if (tl + 1 == tr) {
			st[id].sum = st[id].val[MAX].v1 = a[tl];
			st[id].val[MIN].v1 = -a[tl];
			st[id].val[MAX].v2 = st[id].val[MIN].v2 = -INF;
			st[id].val[MAX].cnt = st[id].val[MIN].cnt = 1;
			return;
		}
		build(lid, tl, tm); build(rid, tm, tr); merge(id);
	}
	void push_add(int id, int tl, int tr, T x) {
		if (x == 0) return;
		st[id].sum += x * (tr - tl); st[id].lazy += x;
		st[id].val[MAX].v1 += x; st[id].val[MIN].v1 -= x;
		if (st[id].val[MAX].v2 != -INF) st[id].val[MAX].v2 += x;
		if (st[id].val[MIN].v2 != -INF) st[id].val[MIN].v2 -= x;
	}
	void push_max(int id, int k, T x, bool f) {
		if (x >= st[id].val[k].v1) return;
		T tmp = (x - st[id].val[k].v1) * st[id].val[k].cnt;
		st[id].sum += k ? -tmp : tmp;
		st[id].val[k].v1 = x; x = -x; k ^= 1;
		if (f) st[id].val[k].v1 = x;
		else if (x > st[id].val[k].v1) st[id].val[k].v1 = x;
		else if (x > st[id].val[k].v2) st[id].val[k].v2 = x;
	}
	void pushdown(int id, int tl, int tr) {
		if (tl + 1 == tr) return;
		push_add(lid, tl, tm, st[id].lazy);
		push_add(rid, tm, tr, st[id].lazy);
		st[id].lazy = 0;
		rep(k,0,2) {
			push_max(lid, k, st[id].val[k].v1, tl + 1 == tm);
			push_max(rid, k, st[id].val[k].v1, tm + 1 == tr);
		}
	}
	void add(int id, int tl, int tr, int l, int r, T x) {
		if (r <= tl || tr <= l) return;
		if (l <= tl && tr <= r) return push_add(id, tl, tr, x);
		pushdown(id, tl, tr);
		add(lid, tl, tm, l, r, x); add(rid, tm, tr, l, r, x);
		merge(id);
	}
	void ch(int id, int tl, int tr, int k, int l, int r, T x) {
		if (r <= tl || tr <= l || x >= st[id].val[k].v1) return;
		if (l <= tl && tr <= r && x > st[id].val[k].v2)
			return push_max(id, k, x, tl + 1 == tr);
		pushdown(id, tl, tr);
		ch(lid, tl, tm, k, l, r, x); ch(rid, tm, tr, k, l, r, x);
		merge(id);
	}
	T sum(int id, int tl, int tr, int l, int r) {
		if (r <= tl || tr <= l) return 0;
		if (l <= tl && tr <= r) return st[id].sum;
		pushdown(id, tl, tr);
		return sum(lid, tl, tm, l, r) + sum(rid, tm, tr, l, r);
	}
	#undef tm
	#undef lid
	#undef rid
public:
	SegTreeBeats(const vector<T>& v) : n(sz(v)), st(n * 4) {
		a = v.data(); build(1, 0, n);
	}
	void chmin(int l, int r, T x) { ch(1, 0, n, MAX, l, r, x); }
	void chmax(int l, int r, T x) { ch(1, 0, n, MIN, l, r, -x); }
	void add(int l, int r, T x)   { add(1, 0, n, l, r, x); }
	T sum(int l, int r)           { return sum(1, 0, n, l, r); }
};
