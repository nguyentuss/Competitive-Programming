/**
 * Author: Horace He
 * Date: 2023-11-24
 * Source: https://github.com/Chillee/kactl/blob/LCT/content/graph/LCT.h#L59
 * Description: Link-cut Tree. Supports BST-like augmentations. (Can be used in place of HLD).
 * Current implementation supports vertex update, path sum, but works on any associative function.
 * If function is commutative, use f0 only.
 * Time: All operations take amortized O(\log N).
 * Status: Tested on yosupo
 *   - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
 */
#pragma once

typedef ll T;
static constexpr T unit = 0;

T f(T p, T q) {return p+q;} // any associative func

struct Node {
	bool flip = 0;
	 // pp = path parent, p = splay tree parent
	Node *pp, *p, *c[2];
	// node data
	int id = 0;
	T val, f0, f1;
	Node() { pp = p = c[0] = c[1] = 0; }
	void push() {
		if (flip) {
			for (auto &x: c) if (x) x->flip ^= 1;
			swap(c[0], c[1]); swap(f0, f1);
			flip = 0;
		}
	}
	void pull() {
		push(); T l0, l1, r0, r1;
		l0 = l1 = r0 = r1 = unit;

		if(c[0]) c[0]->push(), l0 = c[0]->f0, l1 = c[0]->f1;
		if(c[1]) c[1]->push(), r0 = c[1]->f0, r1 = c[1]->f1;

		f0 = f(l0, f(val, f(r0, unit)));
		f1 = f(r1, f(val, f(l1, unit)));
	}
	void rot(bool t) {
		Node *y = p, *z = y->p, *&w = c[t];
		if (z) z->c[z->c[1] == y] = this;
		if (w) w->p = y;
		y->c[!t] = w;
		w = y; p = z;
		y->p = this; y->pull();
	}
	void g() { if (p) p->g(), pp = p->pp; push(); }
	void splay() {
		g();
		while (p) {
			Node* y = p; Node *z = y->p;
			bool t1 = (y->c[1] != this);
			bool t2 = z && (z->c[1] != y) == t1;
			if (t2) y->rot(t1);
			rot(t1);
			if (z && !t2) rot(!t1);
		}
		pull();
	}
	Node* access() {
		for (Node *y = 0, *z = this; z; y = z, z = z->pp) {
			z->splay();
			if (z->c[1]) z->c[1]->pp = z, z->c[1]->p = 0;
			if (y) y->p = z;
			z->c[1] = y; z->pull();
		}
		splay();
		return this;
	}
	Node* makeRoot() { // makes this node root of the tree
		access(), flip ^= 1;
		return this;
	}
};
struct LinkCut {
	vector<Node> ns;
	LinkCut(int N) : ns(N) {rep(i,0,N) ns[i].id = i;}
	bool cut(int u, int v) {
		Node *y = ns[v].makeRoot();
		Node *x = ns[u].access();
		if (x->c[0] != y || y->c[1]) return false;
		x->c[0] = y->p = y->pp = 0;
		x->pull();
		return true;
	}
	bool link(int u, int v) {
		if (lca(u, v) != -1) return false;
		auto t = ns[u].makeRoot();
		t->pp = &ns[v];
		return true;
	}
	int lca(int u, int v) { // -1 if not connected
		Node *x = ns[u].access(), *y = ns[v].access();
		if (!(x == y || x->pp || x->p)) return -1;
		x->splay();
		return (x->pp ? x->pp : x)->id;
	}
	void update(int u, T val) {
		auto t = ns[u].access();
		t->val += val;
		t->pull();
	}
	T query(int u, int v) { // query u->v path
		ns[u].makeRoot();
		return ns[v].access()->f0;
	}
};
