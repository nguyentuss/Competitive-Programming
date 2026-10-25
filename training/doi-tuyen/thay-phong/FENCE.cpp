#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define ll long long

vector<ll> v;
ll cnt[MAX_N];
ll ans = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("FENCE.inp","r",stdin);
	freopen("FENCE.out","w",stdout);
	ll n; scanf("%lld" , &n);
	for (int i = 0 ; i < n ; i++) {
		ll x; scanf("%lld" , &x);
		v.push_back(x);
		cnt[x] ++;
	}
	for (int i = 1 ; i <= n ; i++) {
		ans += (cnt[i]*(cnt[i] - 1))/2;
	}
	for (int i = 0 ; i < n ; i++) {
		ll res = ans - ((cnt[v[i]]*(cnt[v[i]] - 1))/2) + (((cnt[v[i]] - 1)*(cnt[v[i]] - 2))/2);
		printf("%lld\n" , res);
	}
	return 0;
}