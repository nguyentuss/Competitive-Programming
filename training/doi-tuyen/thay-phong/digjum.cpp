#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#pragma GCC optimize("Ofast")

string s;
vector<int> adj[MAX_N];
bool mark[MAX_N];
int f[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	cin >> s;
	for (int i = 0 ; i < s.size() ; i++) {
		adj[s[i] - '0'].push_back(i);
	}
	queue<int> q;
	q.push(0);
	mark[0] = 1;
	while (!q.empty()) {
		int u = q.front();
		if (u == (s.size() - 1)) break;
		q.pop();
		for (auto v : adj[s[u] - '0']) {
			if (!mark[v]) {
				mark[v] = 1;
				f[v] = f[u] + 1;
				q.push(v);
			}
		}
		adj[s[u] - '0'].clear();
		if ((u + 1) < s.size() && !mark[u + 1]){
			mark[u + 1] = true;
			f[u + 1] = f[u] + 1;
			q.push(u + 1);
		}
		if ((u - 1) >= 0 && !mark[u - 1]) {
			mark[u - 1] = true;
			f[u - 1] = f[u] + 1;
			q.push(u - 1);
		}
	}
	cout << f[s.size() - 1];

	return 0;
}