#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

int res = 0;
vector<int> a;
int val[MAX_N];
int f[MAX_N];
int fv[MAX_N];

int DFS(int u , int father , int ans) {
	a.push_back(val[u]);
	int i = v.size() - 1;	
	if (val[i] > val[ans]) {
		ans++;
		f[ans] = i;
	}
	int l = 1 , r = ans;
	int id = mid;
	while (l <= r) {
		int mid = (l + r)/2;
		if (val[f[mid - 1]] < val[i]) {
			l = mid + 1;
			id = mid;
		}
		else {
			r = mid - 1;
		}
	}
	res = max(res , ans);
	for (auto v : adj[u]) {
		int id = cnp(l , ans);
		if (v != father) ans = max(ans , DFS(v , u , ans));
		v.pop_back();
	}
	if (val[f[id]] >= v[i]) {
		f[id] = i;
	}
	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int n , t; cin >> n >> t;
	for (int i = 1 ; i <= n ; i++) 
		cin >> val[i];
	v.push_back(INT_MIN);
	f[0] = 0;
	DFS(1 , -1);
	cout << res;

	return 0;
}