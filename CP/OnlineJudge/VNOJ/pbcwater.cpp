#include <bits/stdc++.h>

using namespace std;

#define MAX_N (ll) (1e3 + 7)
#define inf (ll) (1e18)
#define ll long long

struct ele {
	ll i , j , c;
	bool operator <(const ele &a) const {
		return c > a.c;
	}
};

ll n , m;
ll v[MAX_N][MAX_N] , f[MAX_N][MAX_N];
ll dx[] = {0 , 0 , -1 , 1};
ll dy[] = {1 , - 1 , 0 , 0};
priority_queue<ele> pq;

bool check(ll x , ll y) {
	return (x >= 1 && x <= n && y >= 1 && y <= m);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (ll i = 1 ; i <= n ; i++) {
		for (ll j = 1 ; j <= m ; j++) {
			cin >> v[i][j];
		}
	}
	for (ll i = 1 ; i <= n ; i++) 
		for (ll j = 1 ; j <= m ; j++) 
			f[i][j] = inf;
	for (ll i = 1 ; i <= m ; i++) {
		f[1][i] = v[1][i];
		pq.push({1 , i , v[1][i]});
		f[n][i] = v[n][i];
		pq.push({n , i , v[n][i]});
	}
	for (ll i = 1 ; i <= n ; i++) {
		f[i][1] = v[i][1];
		pq.push({i , 1 , v[i][1]});
		f[i][m] = v[i][m];
		pq.push({i , m , v[i][m]});
	}
	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();
		for (ll go = 0 ; go <= 3; go++) {
			ll i = t.i + dx[go];
			ll j = t.j + dy[go];
			if (!check(i , j)) continue;
			ll val = max(f[t.i][t.j] , v[i][j]);
			if (f[i][j] > val) {
				f[i][j] = val;
				pq.push({i , j , val});
			}
		}
	}
	ll ans = 0;
	for (ll i = 1 ; i <= n ; i++) {
		for (ll j = 1 ; j <= m ; j++) {
			ans += f[i][j] - v[i][j];
		}
	}
	cout << ans;
	return 0;
}