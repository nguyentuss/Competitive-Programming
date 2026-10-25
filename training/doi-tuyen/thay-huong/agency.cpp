#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

int res = 0;
vector<int> a;
int val[MAX_N];
int f[MAX_N];
vector<int> adj[MAX_N];

int DFS(int u , int father , int value ,  int ans) {
	a.push_back(val[u]);
	int i = a.size() - 1;	
	int id = 0;
	int save; 
	if (a[i] >= value && u != father) {
		if (a[i] >= a[f[ans]]) {
			ans++;
			f[ans] = i;	
		}
		int l = 2 , r = ans;
		while (l <= r) {
			int mid = (l + r)/2;
			if (a[f[mid - 1]] <= a[i]) {
				l = mid + 1;
				id = mid;
			}
			else {
				r = mid - 1;
			}
		}
		save = f[id];
		if (a[f[id]] >= a[i] && u != father) {
			f[id] = i;
		}
	}
	for (auto v : adj[u]) {
		if (v != father) {
			res = max(res , DFS(v , u ,  val[v] , ans));
			a.pop_back();
		}
	}
	if (a[i] >= value && u != father) f[id] = save;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("agency.inp","r",stdin);
	freopen("agency.out","w",stdout);
	int n , t; cin >> n >> t;
	for (int i = 1 ; i <= n ; i++) 
		cin >> val[i];
	for (int i = 1 ; i < n ; i++) {
		int u , v ; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1 ; i <= t ; i++) {
		int c; cin >> c;
		for (int j = 1 ; j <= n ; j++) f[i] = -1;
		f[0] = 0;
		a.clear();
		a.push_back(INT_MIN);
		res = 0;
		DFS(c , -1, val[c] , 0);
		cout << res << '\n';
	}

	return 0;
}