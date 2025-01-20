/**
 * Author: e-maxx
 * Date: 2020-11-20
 * Description: Suffix automaton. $link$ is the suffix link, $fipos$ is the first ending position of the string at that state.
 * To get count of positions matching a state, initialize $cnt$ of all non-clone non-initial states to be 1. Then take subtree sum of the suffix link tree.
 * Time: $O(Nlog26)$
 * Status: tested on LATAM ICPC, CSES
 */

struct SufAuto {
	struct state {
		int len = 0, link = -1, fipos;
		map<char, int> next; // can use array instead
	};
	vector<state> st;
	int last = 0;

	SufAuto() {
		st.push_back(state());
	}
	void extend(char c) {
		int cur = st.size(); // new state
		st.push_back(state()); // st[cur].cnt = 1;
		
		st[cur].len = st[last].len + 1;
		st[cur].fipos = st[cur].len - 1;

		int p = last;
		while (p != -1 && !st[p].next.count(c)) {
			st[p].next[c] = cur;
			p = st[p].link;
		}
		if (p == -1) {
			st[cur].link = 0;
		} else {
			int q = st[p].next[c];
			if (st[p].len + 1 == st[q].len) {
				st[cur].link = q;
			} else {
				int cl = st.size(); // new clone state
				st.push_back(st[q]); // st[cl].cnt = 0;

				st[cl].len = st[p].len + 1;
				while (p != -1 && st[p].next[c] == q) {
					st[p].next[c] = cl;
					p = st[p].link;
				}
				st[q].link = st[cur].link = cl;
			}
		}
		last = cur;
	}
};

