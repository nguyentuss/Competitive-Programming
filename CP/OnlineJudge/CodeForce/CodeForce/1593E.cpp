	#include <bits/stdc++.h>

	using namespace std;

	#define MAX_N (int) (4*1e5 + 7)
	#define ii pair<int , int>
	#define f first
	#define s second
	bool visited[MAX_N];
	vector<int> adj[MAX_N];
	int counted[MAX_N];

	int main() {
		ios_base::sync_with_stdio(0); cin.tie(NULL);
		freopen("test.inp","r",stdin);
		int t; cin >> t;
		while (t--) {
			int n , k; cin >> n >> k;
			for (int i = 1 ; i <= n ; i++) {
				visited[i] = false;
				adj[i].clear();
				counted[i] = 0;
			}
			for (int i = 1 ; i < n ; i++) {
				int u , v; cin >> u >> v;
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
			vector<int> v;
			for (int i = 1 ; i <= n ; i++) {
				if (adj[i].size() == 1) {
					visited[i] = 1;
					v.push_back(i);
				}
			}
			if (n == 1 || n <= k) {
				cout << 0 << '\n';
				continue;
			}
			int remain = n;
			vector<int> tmp;
			while (k > 0 && remain > 0) {
				k--;
				remain -= v.size();
				tmp = v;
				v.clear();
				for (auto u : tmp) {
					for (auto x : adj[u]) {
						if (!visited[x]){
							counted[x]++;
							if (counted[x] == adj[x].size() -1) {
								v.push_back(x);
								visited[x] = true;
							}
						}
					}
				}
			}
			cout << remain << '\n';
		}

		return 0;
	}