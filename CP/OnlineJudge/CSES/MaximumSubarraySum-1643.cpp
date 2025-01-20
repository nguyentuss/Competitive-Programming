#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n; 
vector<ll> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("inp.inp","r",stdin);
	//freopen("out.out","w",stdout);
	cin >> n;	
	ll num = LLONG_MIN , cnt = 0;
	for (ll i = 0 ; i < n ;i++) {
		ll x; cin >> x;
		v.push_back(x);
		if (x < 0) cnt++;
		num = max(num , x); 
	}
	if (cnt == n) {
		cout << num;
		return 0;
	}
	ll sum = 0 , maxi = LLONG_MIN;
	for (ll i = 0 ; i < n ;i++) {
		sum += v[i];
		maxi = max(maxi , sum);
		if (sum < 0) {
			maxi = max(maxi , sum - v[i]);
			sum = 0;
		}
	}
	cout << maxi;
	return 0;
}