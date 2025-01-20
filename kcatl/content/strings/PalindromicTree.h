/**
 * Author: tomatoes
 * License: CC0
 * Description: Computes palindromic tree. $0$ is the $0$-len root, $1$ is the $-1$-len root
 * get\_link() returns the suffix link of node $v$, extend() returns true if new node is created.
 * Time: O(n)
 * Status: stress-tested
 */
#pragma once

struct PalindromicTree {
	const static int N = 1e5 + 5, ALPHA = 26;
	int n, last, sz, s[N], len[N], link[N], to[N][ALPHA];
	PalindromicTree() {
		s[n++] = -1;
		link[0] = 1;
		len[1] = -1;
		sz = 2;
	}
	int get_link(int v) {
		while (s[n - len[v] - 2] != s[n - 1]) v = link[v];
		return v;
	}
	void extend(int c) {
		assert(c < ALPHA);
		s[n++] = c;
		last = get_link(last);
		if (!to[last][c]) {
			len [sz] = len[last] + 2;
			link[sz] = to[get_link(link[last])][c];
			to[last][c] = sz++;
		}
		last = to[last][c];
	}
};

