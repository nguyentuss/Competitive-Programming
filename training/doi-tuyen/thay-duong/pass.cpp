#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define inf (int) (1e9 + 7)
#define mod (int) (1e5)
#define int long long

int f[MAX_N];
int v[MAX_N];
int n , k , m;
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("pass.inp","r",stdin);
	freopen("pass.out","w",stdout);
	cin >> n >> k >> m;
	for (int i = 1 ; i <= m ; i++) {
		cin >> v[i];
	}
	for (int i = 1 ; i < MAX_N ;i++) {
		f[i] = inf;
	}

	queue<int> q;
	q.push(n);
	f[n] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u == k) break;
		for (int i = 1 ; i <= m ;i ++) {
			int x = (u*v[i])%mod;
			if (f[x] == inf) {
				f[x] = f[u] + 1;
				q.push(x);
			}
		}
	}
	if (f[k] == inf) cout << -1;
	else cout << f[k];
	return 0;
}