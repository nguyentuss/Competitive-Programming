#include <bits/stdc++.h>

using namespace std;

#define MAX_N (ll) (1e5 + 7)
#define ll long long

struct pos {
	ll x , y;
};

ll cnt1[MAX_N] , cnt2[MAX_N];
pos a[MAX_N];

int main() {	
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("rtri.inp","r",stdin);
	freopen("rtri.out","w",stdout);
	//freopen("test.inp","r",stdin);
	ll n; cin >> n;
	for (ll i = 1 ; i <= n ; i++) {
		ll x, y; cin >> a[i].x >> a[i].y;
		cnt1[a[i].x] ++ , cnt2[a[i].y]++;
	}
	ll ans = 0;
	for (ll i = 1; i <= n ; i++) {
		ans += (cnt1[a[i].x] - 1)*(cnt2[a[i].y] - 1);
	}
	cout << ans;

	return 0;
}