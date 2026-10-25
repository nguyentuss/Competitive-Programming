#include <bits/stdc++.h>

using namespace std;

#define MAX_N (ll) (1e7 + 7)
#define ii pair<ll ,ll>
#define l first
#define r second
#define ll long long
ll n;
ll cnt[MAX_N];
vector<ii> v;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("test.inp","r",stdin);
	//freopen("dientich.inp","r",stdin);
	//freopen("dientich.out","w",stdout);
	cin >> n;
	for (ll i = 1 ; i <= n ;i++) {
		ll l , r; cin >> l >> r;
		if (cnt[l] < r) {
			cnt[l] = r;
		}
	}
	ll tmp = -1;	
	for (ll i = MAX_N - 7 ; i >= 2 ; i--) {
		if (cnt[i] > tmp && cnt[i] != 0) {
			tmp = cnt[i];
			v.push_back(ii(i , cnt[i]));
		}
	}
	ll ans = v[0].l * v[0].r;
	for (ll i = 1 ; i < v.size() ; i++) {
		ans += v[i].l*(v[i].r - v[i - 1].r);
	}
	cout << ans;
	return 0;
}