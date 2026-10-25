#include <bits/stdc++.h>

using namespace std;

#define MAX_N (ll) (1e7 + 7)
#define ii pair<ll ,ll>
#define l first
#define r second
#define ll long long
ll n;
map<ll , ll> cnt;
vector<ii> v;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	for (ll i = 1 ; i <= n ;i++) {
		ll l , r; cin >> l >> r;
		if (cnt[l] < r) {
			cnt[l] = r;
		}
	}
	ll tmp = -1;	
	for (auto it = cnt.rbegin() ; it != cnt.rend() ; it++){
		if (it->second > tmp && it->second != 0) {
			tmp = it->second;
			v.push_back(ii(it->first , it->second));
		}
	}
	ll ans = v[0].l * v[0].r;
	for (ll i = 1 ; i < v.size() ; i++) {
		ans += v[i].l*(v[i].r - v[i - 1].r);
	}
	cout << ans;
	return 0;
}