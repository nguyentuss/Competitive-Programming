#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n;
vector<ll> v;
ll ans = 0;

void binarysearch(ll l , ll r) {
	if (l > r) return;
	ll mid = (l + r)/2;
	ll left = mid - 1 , right = mid + 1 ;
	ll sum = 0 , sumright = 0 , sumleft = 0;
	for (int i = 0 ; i < n ;i++) {
		sum += abs(mid - v[i]);
		sumleft += abs(left - v[i]);
		sumright += abs(right - v[i]);
	}
	//cout << sum << " " << sumleft << " " << sumright << '\n';
	if ((sum <= sumright && sum <= sumleft) || (sum <= sumleft && sum <= sumright)) {
		ans = sum;
		return;
	}
	else if (sum < sumleft && sum >= sumright) return binarysearch(mid + 1 , r);
	else if (sum < sumright && sum >= sumleft) return binarysearch(l , mid - 1);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	//freopen("inp.inp","r",stdin);
	//freopen("out.out","w",stdout);
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
		ll x; cin >> x;
		v.push_back(x); 
	}
	binarysearch(0 , 1e9);
	cout << ans;
	return 0;
}