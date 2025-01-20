/**
 * Author: tomatoes
 * Date: 2023-07-07
 * License: CC0
 * Source: own work
 * Description: Calculate hash for each subtree of a rooted tree. Can be used to
 *  check if two subtrees are isomorphic. To check if two trees are isomorphic,
 *  root them at their centroids and compare their root hashes.
 * Time: $O(N)$
 * Status:
 *  - stress-tested
 *  - tested on yosupo:rooted_tree_isomorphism_classification
 *  - tested on CSES Tree Isomorphism I/II
 *  - tested on https://codeforces.com/contest/1252/problem/F
 */
#pragma once

ull splitmix64(ull x) { 
	x += 0x9e3779b97f4a7c15;
	(x ^= x >> 30) *= 0xbf58476d1ce4e5b9;
	(x ^= x >> 27) *= 0x94d049bb133111eb;
	return x ^ (x >> 31);
}
ull tree_hash(const vector<vi>&g, vector<ull>&f, int u, int p=-1){
	ull id = 0;
	for (int v : g[u]) if (v != p) id += tree_hash(g, f, v, u);
	return f[u] = splitmix64(id); // any ull->ull hash
}

