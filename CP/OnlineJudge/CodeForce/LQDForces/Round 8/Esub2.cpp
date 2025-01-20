//E subtask 2

#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2*1e5 + 7)
#define int long long

int a[MAX_N];
bool vis[MAX_N];
vector<int> adj[MAX_N];
int cnt[MAX_N];
int counted = 0;
int H[MAX_N] , f[MAX_N];

void DFS(int u , int father) {
	vis[u] = true;
	counted++;
	for (auto v : adj[u]) {
		if (v != father && a[u] == a[v]) {
			DFS(v , u);

		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	int n; cin >> n;
	for (int i = 1 ; i <= n ;i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 1 ; i < n ; i++) {
		int u , v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = 0;
	vector<int> tm;
	for (int i = 1 ; i <= n ; i++) {
		if (!vis[i]) {
			counted = 0;
			DFS(i , -1);
			cnt[a[i]] += counted*(counted - 1)/2;
			tm.push_back(counted);
			ans += counted;
		}
	}
	for (auto x : tm) {
		ans -= x;
		cnt[1] += ans*x;
	}
	for (int i = 1 ; i < MAX_N ; i++) {
		if (cnt[i]) {
			cout << i << " " << cnt[i] << '\n';
		}
	}
	return 0;
}