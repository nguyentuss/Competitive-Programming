#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1007)
#define int long long

vector<int> a[MAX_N];

int find(vector <int> &a , vector <int> &b) {
	int n = a.size() , m = b.size();
	int l = 0 , r = n;
	int median = 0 , i , j;
	while (l <= r) {
		i = (l + r)/2 , j = (n + m + 1)/2 - i;
		if (i < n && j > 0 && b[j - 1] > a[i]) {
			l = i + 1;
			continue;
		}
		else if (i > 0 && j < m && a[i - 1] > b[j]) {
			r = i - 1;
			continue;
		}
		else {
			if (i == 0) 
				median = b[j - 1];
			else if (j == 0) 
				median = a[i - 1];
			else {
				median = max(a[i - 1] , b[j - 1]);
			}
			break;
		}
	}
	if ((n + m) % 2 == 1) return 2*median;
	if (i == n) return (median + b[j]);
	if (j == (m - 1)) return (median + a[i]);
	return (median + min(a[i], b[j]));
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int n , w ; cin >> n >> w;
	for (int i = 1 ; i <= n ; i++) {
		int r; cin >> r;
		for (int j = 1 ; j <= r ; j++) {
			int x; cin >> x;
			a[i].push_back(x);
		}
	}
	for (int i = 1 ; i <= w ; i++) {
		int u , v; cin >> u >> v;
		if (a[u].size() > a[v].size()) swap(u , v);
		cout << find(a[u] , a[v]) << '\n';
	}
	return 0;
}