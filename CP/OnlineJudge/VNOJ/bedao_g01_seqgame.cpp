#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define ll long long
#define ii pair <ll ,ll>
#define f first
#define s second
#define MIN_VAL (ll) (-1e18)
#define MAX_VAL (ll) (1e18)

struct ele {
	ll l , r , d;
};

ll n , m;
ll p[MAX_N] , maxi[MAX_N] , v[MAX_N] , revmaxi[MAX_N];
vector<ele> query;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0 ; i <= n + 1; i ++) {
		maxi[i] = MIN_VAL;
		revmaxi[i] = MIN_VAL;
	}
	for (int i = 1 ; i <= m ; i++) {
		ll l , r , d; cin >> l >> r >> d;
		query.push_back({l , r , d});
		p[l]+=d , p[r + 1]-=d;
	}
	for (int i = 1 ; i <= n ; i++) {
		p[i] += p[i - 1];
		v[i] += p[i];
	}
	//for (int i = 1 ; i <= n ; i++) cout << v[i] << " ";
	//cout << '\n';
	ll maxinum = MIN_VAL , pos = 0;
	for (int i = 1 ; i <= n ; i++){ 
		maxi[i] = max(maxi[i - 1] , v[i]);
		if (maxinum < v[i]) {
			maxinum = v[i];
			pos = i;
		}
	}
	for (int i = n ; i >= 1 ; i--) {
		revmaxi[i] = max(revmaxi[i + 1] , v[i]);
	}
	//cout << maxinum;
	ll ans = MAX_VAL;
	for (int i = 0 ; i < query.size() ; i++) {
		int l = query[i].l , r = query[i].r;
		ll val = query[i].d;
		if (l <= pos && pos <= r) {
			ans = min(ans , max(maxinum - val , max(maxi[l - 1] , revmaxi[r + 1])));
			//cout << ans << '\n';
		}
	}
	cout << ans;
	return 0;
}