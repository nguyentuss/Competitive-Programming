/**
 * Author: NXT
 * Date: 2020-2-11
 * License: CC0
 * Source: CP-algorithms
 * Description: Aho-Corasick automaton, used for multiple pattern matching.
 * Time: $O(N*alpha)$
 * Status: tested
 */
#pragma once

const int alpha = 26;
const char first = 'a';

struct aho_corasick{
	struct Vertex {
		int next[alpha], go[alpha], p = -1, link = -1;
		char pch; 
		bool leaf = 0;

		Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
			fill(all(next), -1);
			fill(all(go), -1);
		}
	};
	vector<Vertex> t = vector<Vertex>(1);

	void add_string(string s) {
		int v = 0;
		for (char ch: s) {
			int c = ch - first;
			if (t[v].next[c] == -1) {
				t[v].next[c] = sz(t);
				t.emplace_back(v, ch);
			}
			v = t[v].next[c];
		}
		t[v].leaf = 1;
	}
	int get_link(int v) {
		if (t[v].link == -1) {
			if (v == 0 || t[v].p == 0)
				t[v].link = 0;
			else
				t[v].link = go(get_link(t[v].p), t[v].pch);
		}
		return t[v].link;
	}
	int go(int v, char ch) {
		int c = ch - first;
		if (t[v].go[c] == -1) {
			if (t[v].next[c] != -1)
				t[v].go[c] = t[v].next[c];
			else
				t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
		}
		return t[v].go[c];
	} 
	int is_leaf(int v) {return t[v].leaf;}
};
