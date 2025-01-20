#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll mod = 1e9 + 7;
const ll MAX_N = 5e5 + 7;
ll d[MAX_N];

class SimulateBST {
public:
	int checksum(int n , vector<int> v , int a , int m) {
		ll p = v.size();
		map<ll , ll> cnt;
		cnt[-1] = -1 , cnt[1<<30] = -1;
		ll mul = 1 , ans = 0;
		for (ll i = 0 ; i < n ; i++) {
			if (i >= p) {
				v.push_back((((1LL*a*v[i - p])%m + d[i - 1])%m + 1)%m);
			}
			if (cnt.count(v[i]) == 0) {
				auto it = cnt.lower_bound(v[i]);
				ll r = it->second;
				it--;
				ll l = it->second;
				cnt[v[i]] = max(l , r) + 1;
			}
			d[i] = cnt[v[i]];
			ans = (ans + (d[i]*mul)%mod)%mod;
			mul = mul*100000%mod;
		}
		return int(ans);
	}
};
